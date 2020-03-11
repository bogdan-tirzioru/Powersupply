#ifndef _power_h_
#define _power_h_
#include "types.h"

#define POWER_LIMIT_EN  0x01
#define POWER_LIMIT_DIS 0x02

extern T_UWORD Divizor_U_Sense(T_UWORD luw_ADCV0);
extern T_UWORD Rawvalue_to_Current(T_UWORD luw_ADCV1);
extern T_UWORD Divizor_U_Pot(T_UWORD luw_ADCV2);
extern T_UBYTE UpotToPWM(T_UWORD luw_UPot);
extern T_UBYTE GetLimitVoltageTarget(T_UWORD uw_IPot,T_UWORD uw_Isense);
#endif
