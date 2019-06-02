#ifndef _BUTONS_
#include "types.h"
#include <pic.h>
#define IsPushed(var) (((var)==0)? 1 :0)
//#define RBUTTON_SENSOR RA3
#define LBUTTON_SENSOR RA4
#define Button_down_voltage 3000
extern bank2 T_UBYTE ub_buton_s2;
extern bank2 T_UBYTE ub_buton_s3;
extern bank2 T_UWORD uw_adcCH3;
extern void Read_Buton_state(void);
#endif
