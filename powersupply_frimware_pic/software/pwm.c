#include "micro.h"
#include "sysdef.h"
#if (PWM_DRIVER_ENABLE==1)
#include "pwm.h"
#include <pic.h>
struct T_PWM s_pwm;

#if (0)
T_UBYTE divide_100(T_UWORD uw_number_r1);
#endif

void pwm_init(T_UBYTE loc_channel)
{
 /*set output pwm pin*/
 TRISC2=0;
 TRISC1=0;
 /*low frequency need for pwm*/
 /*set prescaler of timer 2 to 16*/
 T2CKPS1=0;
 T2CKPS0=0;
 /*enable timer 2*/
 TMR2ON=1;
 /*set pwm mode*/
if ((loc_channel & 0x80)==0x80)
 {  
  CCP1M3=1;
  CCP1M2=1;
 }
 else 
 {
  CCP2M3=1;
  CCP2M2=1;
 }
}

void pwm_setDuty(T_UBYTE loc_channel,T_UWORD lul_Duty)
{
 if (lul_Duty<=1024)
 {
  s_pwm.channel=s_pwm.channel|0x20;
  if ((loc_channel & 0x80)==0x80) 
  {
   s_pwm.duty_1=lul_Duty;
  }
  else
  {
   s_pwm.duty_2=lul_Duty;
  }
 }
}

T_UBYTE pwm_getDuty(T_UBYTE channel)
{
 if ((channel & 0x80)==0x80)
  return s_pwm.duty_1;
 else
  return s_pwm.duty_2;
}

void pwm_setPeriod(T_UWORD luw_Period)
{
 
 if(luw_Period>1023)
  {
   luw_Period=1023; /*maxim 1023 microsec period*/
  }
 s_pwm.period=luw_Period;
 s_pwm.channel=s_pwm.channel|0x40;
}

T_UWORD pwm_getPeriod(void)
{
 return s_pwm.period; 
}

void pwm_update(T_UBYTE loc_channel)
{
 T_UWORD luw_duty;
 /*period request*/
 if ((s_pwm.channel & 0x40)==0x40)

   PR2=(s_pwm.period>>PWM_SHIFT_FACT)-1;
 /*duty request*/
 if ((s_pwm.channel & 0x20)==0x20)
  {
   /*channel 1*/
   if ((loc_channel & 0x80)==0x80)
   {
     luw_duty=s_pwm.period;
     luw_duty=(((T_ULONG)luw_duty*s_pwm.duty_1))/1024;
	 if(luw_duty&0x02 == 0x02) CCP1X =1;
	 else CCP1X =0;
	 if(luw_duty&0x01 == 0x01) CCP1Y =1;
	 else CCP1Y =0;
     CCPR1L=luw_duty>>2;
   }
   else
   {
     luw_duty=s_pwm.period;
     luw_duty=(((T_ULONG)luw_duty*s_pwm.duty_2))/1024;
	 if(luw_duty&0x02 == 0x02) CCP2X =1;
	 else CCP2X =0;
	 if(luw_duty&0x01 == 0x01) CCP2Y =1;
	 else CCP2Y =0;
     CCPR2L=luw_duty>>2;
   }
  }
}
void pwm_disable(T_UBYTE loc_channel)
{

 if ((loc_channel & 0x80)==0x80)
 {
 /*channel 1*/
  CCP1M3=0;
  CCP1M2=0;
  CCP1M1=0;
  CCP1M0=0;
 }
 else
 {
  CCP2M3=0;
  CCP2M2=0;
  CCP2M1=0;
  CCP2M0=0;
 }
}
#if (0)
T_UBYTE divide_100(T_UWORD uw_number_r1)
{
 T_UBYTE uw_number_r2=uw_number_r1;
 uw_number_r2=uw_number_r2>>5;
 uw_number_r2=uw_number_r2+uw_number_r1;
 uw_number_r2=uw_number_r2<<2;
 uw_number_r1=uw_number_r2+uw_number_r1;
 return (T_UBYTE)(uw_number_r1>>9); 
}
#endif
#endif
