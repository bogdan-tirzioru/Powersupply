#ifndef _DISPLAY_2RAW_
#define _DISPLAY_2RAW_

#include "types.h"
#include "micro.h"


#define Voltage_Resol_Sh 11
#define Curent_Resol_Sh 12

#define DataClearDisplay 0x01
#define DataHomeDisplay  0x02
#define Direction_OUPUT 0x00
#define Direction_INPUT 0xFF

enum Display2raw_State{
Display_no_init = 0,
Display_init_step_1 = 1,
Display_init_step_2 = 9,
Display_init_step_3 =10,
Display_init_DisplayOff = 2,
Display_init_ClearDisplay =3,
Display_init_EntryMode = 4,
Display_init_DisplayOn =5,
Display_idle = 6,
Display_clear_screen = 7,
Display_write_string = 8,
Display_MoveSecond =11,
Display_write_string_l2=12

};
#define MaxRawDisp 16
extern T_UBYTE ubDisplay_buf[MaxRawDisp];
extern T_UBYTE ubDisplay_buf2[MaxRawDisp];

#define SetLimitWarnning() {ubDisplay_buf[11] =0xC6;}
#define ResetLimitWarning() {ubDisplay_buf[11] =0x11;}
 
extern void InitDisplay2raw(void);
extern void SetDisplay_Voltage(T_UWORD uwVoltage);
extern void SetDisplay_VoltageD(double dVoltage,T_UBYTE *pubDisplay_buf);
extern void SetDisplay_Current(T_UWORD uwCurent);
extern void SetDisplay_CurrentD(double dCurent,T_UBYTE *pubDisplay_buf);
extern T_UBYTE Dispaly2raw_task(void);
extern void SetCommand(T_UBYTE ub_Command);
extern void WriteData(T_UBYTE ub_Data);
extern T_UBYTE ReadData(void);
extern T_UBYTE IsBusy(void);
extern void LCD_delay_us(T_UBYTE delay);
extern void SetDisplay_Current_target(T_UWORD uwCurent);
#endif
