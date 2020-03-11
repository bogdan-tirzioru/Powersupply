#include "micro.h"
#include "Display_7D.h"
#include "buton.h"
T_UBYTE ubFirstByte,ubSecondByte,ubThrdByte,ubFourthByte;
T_UWORD ubNumberINT,uwNumberFRC;
T_UBYTE ubDisplayState;

void InitDisplay7D()
{
    ubFirstByte = 0;
    ubSecondByte = 0;
    ubNumberINT = 0;
    ubDisplayState = 0;
    ubThrdByte=0;
    ubFourthByte=0;
	PINENABLE_7S4 = Disable_tz;
    PINENABLE_7S3 = Disable_tz;
    PINENABLE_7S2 = Disable_tz;
    PINENABLE_7S1 = Disable_tz;
}


void SetDisplay_Voltage(T_UWORD uwVoltage)
{
    T_UBYTE lubNumber=0;
    T_UBYTE lubSecondByte,lubFirstByte;
    
	//uwVoltage = 0x8FA5;
    /*transform to 8 bit int part*/
    ubNumberINT = uwVoltage >> Voltage_Resol_Sh;
    lubNumber = ubNumberINT;
    lubFirstByte = lubNumber %10;
    lubNumber = lubNumber /10;
    lubSecondByte = lubNumber %10;
	
    ubSecondByte = lubSecondByte;
    ubFirstByte = lubFirstByte;
}

void SetDisplay_Current(T_UWORD uwCurent)
{
    T_UBYTE lubNumber=0;
    T_UBYTE lubSecondByte,lubFirstByte;
	T_UWORD luwTemp;    
    /*transform to 8 bit int part*/
	luwTemp = (T_UWORD)uwCurent >> Curent_Resol_Sh;
    ubNumberINT = luwTemp;
    lubNumber = ubNumberINT;
    
	uwNumberFRC = uwCurent & (0x0FFF);
    uwNumberFRC = uwNumberFRC * 10;
    /*copy to buffer numbers */
    uwNumberFRC = uwNumberFRC >> Curent_Resol_Sh;
	
    ubFourthByte = uwNumberFRC;
    ubThrdByte = ubNumberINT;
}

void  DisplayByte(T_UBYTE lubNumber)
{
    switch (lubNumber)
    {
        case 0:
            PIN_A = On_Led;
            PIN_B = On_Led;
            PIN_C = On_Led;
            PIN_D = On_Led;
            PIN_E = On_Led;
            PIN_F = On_Led;
            PIN_G = Off_Led;
        break;
        case 1:
            PIN_A = Off_Led;
            PIN_B = On_Led;
            PIN_C = On_Led;
            PIN_D = Off_Led;
            PIN_E = Off_Led;
            PIN_F = Off_Led;
            PIN_G = Off_Led;
        break;
        case 2:
            PIN_A = On_Led;
            PIN_B = On_Led;
            PIN_C = Off_Led;
            PIN_D = On_Led;
            PIN_E = On_Led;
            PIN_F = Off_Led;
            PIN_G = On_Led;
        break;
        case 3:
            PIN_A = On_Led;
            PIN_B = On_Led;
            PIN_C = On_Led;
            PIN_D = On_Led;
            PIN_E = Off_Led;
            PIN_F = Off_Led;
            PIN_G = On_Led;
        break;
        case 4:
            PIN_A = Off_Led;
            PIN_B = On_Led;
            PIN_C = On_Led;
            PIN_D = Off_Led;
            PIN_E = Off_Led;
            PIN_F = On_Led;
            PIN_G = On_Led;
        break;
        case 5:
            PIN_A = On_Led;
            PIN_B = Off_Led;
            PIN_C = On_Led;
            PIN_D = On_Led;
            PIN_E = Off_Led;
            PIN_F = On_Led;
            PIN_G = On_Led;
        break;
        case 6:
            PIN_A = On_Led;
            PIN_B = Off_Led;
            PIN_C = On_Led;
            PIN_D = On_Led;
            PIN_E = On_Led;
            PIN_F = On_Led;
            PIN_G = On_Led;
        break;
        case 7:
            PIN_A = On_Led;
            PIN_B = On_Led;
            PIN_C = On_Led;
            PIN_D = Off_Led;
            PIN_E = Off_Led;
            PIN_F = Off_Led;
            PIN_G = Off_Led;
        break;
        case 8:
            PIN_A = On_Led;
            PIN_B = On_Led;
            PIN_C = On_Led;
            PIN_D = On_Led;
            PIN_E = On_Led;
            PIN_F = On_Led;
            PIN_G = On_Led;
        break;
        case 9:
            PIN_A = On_Led;
            PIN_B = On_Led;
            PIN_C = On_Led;
            PIN_D = On_Led;
            PIN_E = Off_Led;
            PIN_F = On_Led;
            PIN_G = On_Led;
        break;
        case '-':
            /*minus sign*/
            PIN_A = Off_Led;
            PIN_B = Off_Led;
            PIN_C = Off_Led;
            PIN_D = Off_Led;
            PIN_E = Off_Led;
            PIN_F = On_Led;
            PIN_G = Off_Led;
        break;
        default:
            PIN_A = Off_Led;
            PIN_B = Off_Led;
            PIN_C = Off_Led;
            PIN_D = Off_Led;
            PIN_E = Off_Led;
            PIN_F = Off_Led;
            PIN_G = Off_Led;
        break;
    }
}

void Display_7D_Temp(void)
{
    T_UBYTE lubNumber= 0;
    switch (ubDisplayState)
    {
        case (DisplayState_7S4):
        {
            /*Display less significant byte*/
            /*enable display 0*/
            PINENABLE_7S3 = Disable_tz;
            PINENABLE_7S2 = Disable_tz;
            PINENABLE_7S1 = Disable_tz;
            
            /* set sign led*/
            //PIN_SIGN = ubSign;
            DisplayByte(ubFirstByte);
            PIN_DIG = 1;
            PINENABLE_7S4 = Enable_tz;
            ubDisplayState = DisplayState_7S3;
        }
        break;
        case (DisplayState_7S3):
        {
            /*Display less significant byte*/
            /*enable display 0*/
            PINENABLE_7S4 = Disable_tz;
            PINENABLE_7S2 = Disable_tz;
            PINENABLE_7S1 = Disable_tz;
            
            /* set sign led*/
            //PIN_SIGN = ubSign;
            DisplayByte(ubSecondByte);
            PIN_DIG = 1;
            PINENABLE_7S3 = Enable_tz;
            ubDisplayState = DisplayState_7S2;
        }
        break;
        case (DisplayState_7S2):
        {
            /*Display less significant byte*/
            /*enable display 0*/
            PINENABLE_7S4 = Disable_tz;
            PINENABLE_7S3 = Disable_tz;
            PINENABLE_7S1 = Disable_tz;
            
            /* set sign led*/
            //PIN_SIGN = ubSign;
            DisplayByte(ubThrdByte);
            PIN_DIG = 0;
            PINENABLE_7S2 = Enable_tz;
            ubDisplayState = DisplayState_7S1;
        }
        break;
        case (DisplayState_7S1):
        {
            /*Display less significant byte*/
            /*enable display 0*/
            PINENABLE_7S4 = Disable_tz;
            PINENABLE_7S3 = Disable_tz;
            PINENABLE_7S2 = Disable_tz;
            
            /* set sign led*/
            //PIN_SIGN = ubSign;
            
            DisplayByte(ubFourthByte);
            PIN_DIG = 1;
            PINENABLE_7S1 = Enable_tz;
            ubDisplayState = DisplayState_7S4;
        }
        break;
        default:
        ubDisplayState = DisplayState_7S4;
        break;
    }
}
