#ifndef _TASKS_H
#define _TASKS_H

#include "types.h"
#include "control.h"
extern bank2 T_UBYTE ub_sensor_data_req;
extern bank2 T_UWORD uw_adcCH0;
extern bank2 T_UWORD uw_adcCH1;
extern bank2 T_UBYTE ub_islimit_power;
extern T_UWORD auwPWMOut[FILT_NR_LEN];
extern T_UWORD auwUPOT[5];
extern bank2 T_UWORD uw_ADCV0,uw_ADCV1;
extern void task_fast(void);
extern void task_slow(void);
extern void ConvertZecimalToAsci(T_SWORD sw_ADCT0,T_UBYTE ub_lenght);
extern T_ULONG ExtractAdrressReq(void);
extern void ConvertHexToAsci32(T_ULONG lul_data_read);
extern T_UBYTE Read_data_from_address8(T_ULONG ul_address_request);
extern T_UBYTE GetButtonRequest(void);
#endif
