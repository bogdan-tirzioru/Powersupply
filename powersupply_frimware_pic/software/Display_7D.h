#ifndef _DISPLAY_7D_
#define _DISPLAY_7D_

#include "sysdef.h"
#include "types.h"
#include <pic.h>

#define PINENABLE_7S1 RC0
#define PINENABLE_7S2 RC3
#define PINENABLE_7S3 RC4
#define PINENABLE_7S4 RC5

#define PIN_A RB2
#define PIN_B RB3
#define PIN_C RB6
#define PIN_D RB5
#define PIN_E RB4
#define PIN_F RB1
#define PIN_G RB0
#define PIN_DIG RB7
#define PIN_SIGN RC1
#define Disable_tz 0
#define Enable_tz 1
#define On_Led 0
#define Off_Led 1
#define Voltage_Resol_Sh 11
#define Curent_Resol_Sh 12

enum {
DisplayState_7S4,
DisplayState_7S3,
DisplayState_7S2,
DisplayState_7S1
};
extern void InitDisplay7D();
extern void Display_7D_Temp(void);
extern void SetDisplay_Voltage(T_UWORD uwVoltage);
extern void SetDisplay_Current(T_UWORD uwCurent);
#endif