#include "control.h"
#define PWM_TRASHOLD 5
void init_botifilter(T_UWORD *Buffer,T_UWORD luwInitValue)
{
	T_UBYTE lubindex = 0;
	for (lubindex =0;lubindex<(FILT_NR_LEN+1);lubindex++)
	{
		Buffer[lubindex] = luwInitValue;
	}
}
T_UWORD cycle_botifilter(T_UWORD *Buffer,T_UWORD uwNew)
{
	T_UBYTE lubindex = 0;
	T_ULONG lulRetValue = 0;
	for (lubindex = FILT_NR_LEN;lubindex>0;lubindex--)
	{
		Buffer[lubindex] = Buffer[lubindex-1];
	}
    Buffer[0] = uwNew;

	for (lubindex = 0;lubindex<FILT_NR_LEN;lubindex++)
	{
		lulRetValue = lulRetValue + Buffer[lubindex];	
	}
	lulRetValue =lulRetValue/FILT_NR_LEN;
	return (T_UWORD)lulRetValue;
}

T_UWORD lock_value(T_UWORD *Buffer,T_UWORD uwNew,T_UWORD uwOld)
{
	T_ULONG lulRetValue = 0;
    T_UBYTE lub_NotChange =0;
    T_UBYTE lubindex = 0;
    T_SLONG lusDer = 0;
    for (lubindex = 0;lubindex<FILT_NR_LEN;lubindex++)
	{
		lusDer = (T_SLONG)Buffer[lubindex]- (T_SLONG)uwNew;
	    if (lusDer<0) lusDer = -lusDer;
		if (lusDer> PWM_TRASHOLD)
		{
			lub_NotChange ++;
		}
	}
    if (lub_NotChange >1)
    {
		lulRetValue = uwOld;
	}
	else
    {
		lulRetValue = uwNew;
	}
    return (T_UWORD)lulRetValue;
}