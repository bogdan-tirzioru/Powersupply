#include "micro.h"
#include "Display_2raw.h"
#include "dwt_delay.h"

#define InitWait40ms 20
#define InitWait2ms 1
#define InitWaitRefreshms 50
#define InitWait4ms 2

#define LCD_CMD_FUNC 0x20
#define LCD_8BIT_INTERFACE 0x10
#define LCD_2LINES 0x08
#define LCD_1LINES 0x00
#define LCD_FONT_SMALL 0x00
#define LCD_FONT_LARGE 0x04
#define LCD_NOT_USED 0x03
#define LCD_CMD_DISP_ONOFF 0x08
#define LCD_CMD_CLEAR 0x01
#define LCD_CMD_ENTRY 0x04
/*I / D = 1: Increment, I / D = 0: Decrement.*/
#define LCD_ENTRY_I 0x02
#define LCD_ENTRY_S 0x01
#define LCD_CMD_DISP_ON 0x04
#define LCD_CMD_CURSOR_ON 0x02
#define LCD_CMD_POSITION_ON 0x01
#define LCD_CMD_RETURN_HOME 0x02
#define LCD_CMD_SET_DDRAM 0xC0


T_UBYTE ubFirstByte,ubSecondByte,ubThrdByte,ubFourthByte;
T_UWORD ubNumberINT,uwNumberFRC;
T_UBYTE ub_state_Display2r;
T_UBYTE ub_counter_1;
T_UWORD uw_counter;
T_UBYTE ub_busy;
T_UBYTE ub_char;
T_UBYTE ub_Datawrite;
T_UBYTE ubDispIndex;
T_UBYTE ubDisplay_buf[MaxRawDisp] ="Ch1=            ";
T_UBYTE ubDisplay_buf2[MaxRawDisp]="Ch2=            ";
T_UWORD uw_currentaddress;

void InitDisplay2raw()
{
    ubFirstByte = 0;
    ubSecondByte = 0;
    ubNumberINT = 0;
    ubThrdByte=0;
    ubFourthByte=0;
	ub_counter_1 = 0;
	ub_busy = 0;
	ub_char = 0;
	//RC0 = 0;
	DWT_Init();
	ub_state_Display2r = Display_no_init;
}

void SetDisplay_VoltageD(double dVoltage,T_UBYTE *pubDisplay_buf)
{
    T_UBYTE lubNumber=0;
    T_UBYTE lubSecondByte=0,lubFirstByte=0;
	T_UWORD luwNumberFrac=0;
	T_UBYTE lubNumberInt=0;
	T_UBYTE luwNumberSecFrac=0;

	lubNumber = (T_UBYTE)dVoltage;
    lubNumberInt = lubNumber;
    lubFirstByte = lubNumber %10;
    lubNumber = lubNumber /10;
    lubSecondByte = lubNumber %10;

	luwNumberFrac = ((dVoltage - lubNumberInt)*10);
	luwNumberSecFrac = ((dVoltage - lubNumberInt)*100) - luwNumberFrac*10;

    ubSecondByte = lubSecondByte;
	pubDisplay_buf[4] = ubSecondByte + 0x30;
    ubFirstByte = lubFirstByte;
	pubDisplay_buf[5] = ubFirstByte  + 0x30;
	pubDisplay_buf[6] = '.';
	pubDisplay_buf[7] = ((T_UBYTE)luwNumberFrac) + 0x30;
	pubDisplay_buf[8] = ((T_UBYTE)luwNumberSecFrac)+0x30;
	pubDisplay_buf[9] = 'V';

}


void SetDisplay_CurrentD(double dCurent,T_UBYTE *pubDisplay_buf)
{
    /*transform to 8 bit int part*/
    ubNumberINT = (T_UBYTE)dCurent;
    uwNumberFRC = (T_UWORD)((dCurent-ubNumberINT) * 10);
    ubFourthByte = uwNumberFRC;
    ubThrdByte = ubNumberINT;
    pubDisplay_buf[10] = 0x02F;
    pubDisplay_buf[11] = ubThrdByte + 0x30;
    pubDisplay_buf[12] =0x2E;
    pubDisplay_buf[13] = ubFourthByte + 0x30;
    pubDisplay_buf[14] = 0x41;

}

void SetDisplay_Current_target(T_UWORD uwCurent)
{
 	T_UWORD luwTemp;
    /*transform to 8 bit int part*/
	luwTemp = (T_UWORD)uwCurent >> Curent_Resol_Sh;
    ubNumberINT = luwTemp;
    
	uwNumberFRC = uwCurent & (0x0FFF);
    uwNumberFRC = uwNumberFRC * 10;
    /*copy to buffer numbers */
    uwNumberFRC = uwNumberFRC >> Curent_Resol_Sh;
	
    ubFourthByte = uwNumberFRC;
    ubThrdByte = ubNumberINT;
	ubDisplay_buf[12] = ubThrdByte + 0x30;
	ubDisplay_buf[13] =0x2e;
	ubDisplay_buf[14] = ubFourthByte + 0x30;
	ubDisplay_buf[15] =0x41;
}
T_UBYTE Dispaly2raw_task(void)
{
	T_UBYTE ub_UpdateOk =0;
	switch (ub_state_Display2r)
	{
		case Display_no_init:
			/*wait 40ms to init*/
			if (ub_counter_1 > InitWait40ms)
			{
				/*setup interface , nr of lines and font size first */
				SetCommand(LCD_CMD_FUNC | LCD_8BIT_INTERFACE );
				ub_state_Display2r = Display_init_step_1;
				ub_counter_1 = 0;
				//RC0 = ~RC0;
			}
			else
			{
				ub_counter_1++;
			}
		break;
		case Display_init_step_1:
			/*wait >4.1ms*/
			if (ub_counter_1 > InitWait4ms)
			{
				/*setup interface , nr of lines and font size*/
				SetCommand(LCD_CMD_FUNC | LCD_8BIT_INTERFACE );
				ub_state_Display2r = Display_init_step_2;
			}
			else
			{
				ub_counter_1++;
			}
		break;
		case Display_init_step_2:
			/*wait >100us*/
			/*setup interface , nr of lines and font size*/
			SetCommand(LCD_CMD_FUNC | LCD_8BIT_INTERFACE);
			ub_state_Display2r = Display_init_step_3;
		break;
		case Display_init_step_3:
			/*wait >100us*/
			/*setup interface , nr of lines and font size*/
			SetCommand(LCD_CMD_FUNC | LCD_8BIT_INTERFACE|LCD_2LINES );
			ub_state_Display2r = Display_init_DisplayOff;
		break;
		case Display_init_DisplayOff:
			/*wait >100us*/
			/*display off*/
			ub_busy = IsBusy();
			if (ub_busy ==0)
			{
				SetCommand(LCD_CMD_DISP_ONOFF);
				ub_state_Display2r = Display_init_ClearDisplay;		
			}
			else
			{
			
			}	
			//RC0 = ~RC0 ;
		break;
		case Display_init_ClearDisplay:
			/*wait >37us*/
			/*clear display*/
			ub_busy = IsBusy();
			if (ub_busy ==0)
			{
			
				SetCommand(LCD_CMD_CLEAR);
				ub_state_Display2r = Display_init_EntryMode;

				ub_counter_1 = 0;
				}
			else
			{
			
			}
			//RC0 = ~RC0 ;
		break;
		case Display_init_EntryMode:
			/*Wait time >1.52mS to clear*/
			if (ub_counter_1 > InitWait2ms)
			{
				ub_busy = IsBusy();
				if (ub_busy ==0)
				{
					/*setup interface , nr of lines and font size*/
					SetCommand(LCD_CMD_ENTRY | LCD_ENTRY_I);
					ub_state_Display2r = Display_init_DisplayOn;
					ub_counter_1 = 0;
					
				}
			}
			else
			{
				ub_counter_1++;
			}
		break;
		case Display_init_DisplayOn:
			/*setup interface , nr of lines and font size*/
			//SetCommand(LCD_CMD_DISP_ONOFF | LCD_CMD_DISP_ON | LCD_CMD_CURSOR_ON | LCD_CMD_POSITION_ON);
			SetCommand(LCD_CMD_DISP_ONOFF | LCD_CMD_DISP_ON);
			ub_busy = IsBusy();
			if (ub_busy ==0)
			{
				ub_state_Display2r = Display_idle;
				uw_counter =0;
			}
			
			//RC0 = ~RC0 ;
		break;
		case Display_idle:
			ub_busy = IsBusy();
			if (ub_busy ==0)
			{
				if (uw_counter > InitWaitRefreshms)
				{
					ub_state_Display2r = Display_clear_screen;
					ubDispIndex = 0;
					uw_counter = 0;
				}
				else
				{
					uw_counter++;
				}
			}
			ub_UpdateOk =1;
		break;
		case Display_clear_screen:
			ub_busy = IsBusy();
			if (ub_busy ==0)
			{
 				SetCommand(LCD_CMD_RETURN_HOME);
				ub_state_Display2r = Display_write_string;
			}
		break;
		case Display_write_string:
			ub_busy = IsBusy();
			if (ub_busy ==0)
			{
				ub_Datawrite = ubDisplay_buf[ubDispIndex];
				WriteData(ub_Datawrite);
				ubDispIndex++;
				if(ubDispIndex > MaxRawDisp)
				{
					ub_state_Display2r = Display_MoveSecond;
					ubDispIndex = 0;
					uw_counter =0;
				}
			}
		break;
		case Display_MoveSecond:
			ub_busy = IsBusy();
			if (ub_busy ==0)
			{
 				SetCommand(LCD_CMD_SET_DDRAM);
				ub_state_Display2r = Display_write_string_l2;
			}
			break;
		case Display_write_string_l2:
			ub_busy = IsBusy();
			if (ub_busy ==0)
			{
				ub_Datawrite = ubDisplay_buf2[ubDispIndex];
				WriteData(ub_Datawrite);
				ubDispIndex++;
				if(ubDispIndex > MaxRawDisp)
				{
					ub_state_Display2r = Display_idle;
					ubDispIndex = 0;
					uw_counter =0;
				}
			}
		break;
		default :
			ub_state_Display2r = Display_no_init;
		break;
	}
	return ub_UpdateOk;
}
T_UBYTE ub_log[512];
T_UBYTE ub_index=0;
void SetCommand(T_UBYTE ub_Command)
{
	ub_log[ub_index]=ub_Command;
	ub_index++;
	GPIOC->MODER=GPIOC->MODER | (0x00055555);
	//LCD_delay_us(10);
	HAL_GPIO_WritePin(GPIOC,LCD_RS_Pin|LCD_RW_Pin,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOC,LCD_EN_Pin,GPIO_PIN_SET);
	GPIOC->ODR &= 0XFE00;
	GPIOC->ODR |= ((ub_Command & 0x1f) | (((T_UWORD)ub_Command & 0xE0)<<1));
	LCD_delay_us(1);
	HAL_GPIO_WritePin(GPIOC,LCD_EN_Pin,GPIO_PIN_RESET);
}

void WriteData(T_UBYTE ub_Data)
{
	ub_log[ub_index]=ub_Data;
	ub_index++;
	GPIOC->MODER=GPIOC->MODER | (0x00055555);
	//LCD_delay_us(10);

	HAL_GPIO_WritePin(GPIOC,LCD_RS_Pin,GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOC,LCD_RW_Pin,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOC,LCD_EN_Pin,GPIO_PIN_SET);
	GPIOC->ODR &= 0XFE00;
	GPIOC->ODR |= ((ub_Data & 0x1f) | (((T_UWORD)ub_Data & 0xE0)<<1));
	LCD_delay_us(1);
	HAL_GPIO_WritePin(GPIOC,LCD_EN_Pin,GPIO_PIN_RESET);
}

T_UBYTE ReadData(void)
{
	T_UBYTE ub_Data;
	GPIOC->MODER=GPIOC->MODER & 0xFFF00000;
	//LCD_delay_us(10);
	GPIOC->ODR &= 0XFE00;
	HAL_GPIO_WritePin(GPIOC,LCD_RS_Pin|LCD_RW_Pin|LCD_EN_Pin,GPIO_PIN_SET);
	ub_Data = ((GPIOC->IDR) & 0x1f) | (((GPIOC->IDR) &0x1c0)>>1);
	LCD_delay_us(10);
	HAL_GPIO_WritePin(GPIOC,LCD_EN_Pin,GPIO_PIN_RESET);

	return ub_Data;
}

T_UBYTE IsBusy(void)
{
	T_UBYTE ub_Bussy = 1;
	T_UWORD uw_data = 0;
#if 1
	GPIOC->MODER=GPIOC->MODER & 0xFFFC0000;
	//LCD_delay_us(10);
	HAL_GPIO_WritePin(GPIOC,LCD_RS_Pin,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOC,LCD_RW_Pin|LCD_EN_Pin,GPIO_PIN_SET);
	LCD_delay_us(1);
	uw_data = ((GPIOC->IDR) & 0x1f) | (((GPIOC->IDR) &0x1c0)>>1);
	HAL_GPIO_WritePin(GPIOC,LCD_EN_Pin,GPIO_PIN_RESET);
	LCD_delay_us(1);
	uw_currentaddress = uw_data & 0x7f;
	ub_Bussy = ((uw_data) & 0x100 )>> 0x8;
#else
	ub_Bussy = 0;
#endif
	return ub_Bussy;
}

void LCD_delay_us(T_UBYTE delay)
{
	DWT_Delay(delay);
}



