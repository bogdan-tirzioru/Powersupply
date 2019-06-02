#include "sysdef.h"
#if (ADC_DRIVER_ENABLE==1)
#ifndef ADC_H
#define ADC_H

#include "types.h"
#include <pic.h>

#define ADC_CANNALS 5
#define CHANNEL_SELECT_ADC(CH){CHS0=(CH)&0x1; CHS1=((CH)&0x2)>>1;CHS2=((CH)&0x4)>>2;}
#define AdcDelay 5

#define adc_getResult(channel) (adc_buffer[channel])
extern T_UWORD adc_buffer[ADC_CANNALS];
extern void adc_init(void);
extern void adc_convert_all(void);
extern void adc_convert_one_channel(T_UBYTE ub_channel);
#endif
#endif
