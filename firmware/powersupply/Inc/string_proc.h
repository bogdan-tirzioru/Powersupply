#ifndef _string_proc_
#define _string_proc_
#include "types.h"
//void ConvertZecimalToAsci(T_SWORD sw_ADCT0,T_UBYTE ub_lenght);
void ConvertZecimalToAsci(T_SWORD sw_ADCT0,T_UBYTE ub_lenght,T_UBYTE *s_Response);
void ConvertHexToAsci32(T_ULONG lul_data_read,T_UBYTE *s_Response);
extern T_ULONG ExtractAdrressReq(T_UBYTE s_Request[10]);
#endif
