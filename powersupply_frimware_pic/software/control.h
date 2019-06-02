#ifndef __CONTROL__
#define __CONTROL__
#include "micro.h"
#include "types.h"
#define FILT_NR_LEN   8
extern void init_botifilter(T_UWORD *Buffer,T_UWORD luwInitValue);
extern T_UWORD cycle_botifilter(T_UWORD *Buffer,T_UWORD uwNew);
extern T_UWORD lock_value(T_UWORD *Buffer,T_UWORD uwNew,T_UWORD uwOld);
#endif
