#include "micro.h"
#include "sysdef.h"
#if (ADC_DRIVER_ENABLE==1)
#include "adc.h"
#include "types.h"
#include <pic.h>
//#define GO_DONE ADGO

T_UWORD adc_buffer[ADC_CANNALS];

void adc_init(void)
{
 /*select clock to convert*/
 /*clock ADC from internal RC*/
 ADCS2=0;
 ADCS1=1;
 ADCS0=1;
 /*Select format right justified*/
 ADFM=1;
/*select channels*/
 PCFG3=0;
 PCFG2=0;
 PCFG1=1;
 PCFG0=0;

/*select pins for AD*/
 TRISA0=1;
 TRISA1=1;
 TRISA2=1;
 TRISA3=1;

 /*enable conversion*/
 ADON=1;
}
void adc_convert_all(void)
{
 T_UBYTE current_ch = 0;
 T_UBYTE ub_Index1 =0;
 T_UBYTE ub_Index2 =0;
 T_UBYTE ub_Index3 =0;
   
 for (current_ch=0;current_ch<ADC_CANNALS;current_ch++)
 {
  CHANNEL_SELECT_ADC(current_ch);
  for (ub_Index1=0;ub_Index1<AdcDelay;ub_Index1++);
  /*start conversion*/
  ADIF = 0;
  GO_DONE=1;
  while((ADIF == 0) ||(GO_DONE==1));
  for (ub_Index3=0;ub_Index3<AdcDelay;ub_Index3++);
  adc_buffer[current_ch]=(ADRESL)|((T_UWORD)(ADRESH<<8));
 }
}

void adc_convert_one_channel(T_UBYTE ub_channel)
{
 T_UBYTE ub_Index1;
 CHANNEL_SELECT_ADC(ub_channel);
 for (ub_Index1=0;ub_Index1<AdcDelay;ub_Index1++);
 /*start conversion*/
 ADIF = 0;
 GO_DONE=1;
 while((ADIF == 0) ||(GO_DONE==1));
 for (ub_Index1=0;ub_Index1<AdcDelay;ub_Index1++);
 adc_buffer[ub_channel]=(ADRESL)|((T_UWORD)(ADRESH<<8));
}
#endif
