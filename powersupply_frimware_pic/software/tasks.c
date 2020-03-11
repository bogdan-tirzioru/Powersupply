#include "micro.h"
#include "tasks.h"
#include "types.h"
#include <pic.h>
#include "adc.h"
#include "init.h"
#include "sysdef.h"
#include "signal_proc.h"
#include "Display_2raw.h"
#include "buton.h"
#include "string_proc.h"
#include "power.h"
#include "control.h"
extern T_UBYTE uw_mseconds;
#if (ADC_DRIVER_ENABLE==1)
bank2 T_UWORD uw_adcCH0=0;
bank2 T_UWORD uw_adcCH1=0;
bank2 T_UWORD uw_adcCH2=0;
#endif

bank2 T_UWORD uw_ADCV0,uw_ADCV1;
bank2 T_UWORD uw_ADCV2,uw_ADCV3;
bank2 T_UWORD uw_Usense;
bank2 T_UWORD uw_Isense;
bank2 T_UWORD uw_UPot;
bank2 T_UWORD uw_IPot;
bank2 T_UBYTE ub_islimit_power;
bank2 T_UWORD temp_duty_pwm2;

#if (USART_DRIVER_ENABLE == 1)
bank2 T_UBYTE s_Response[SCI_BUFFER_LENGHT];
bank2 T_UBYTE s_Request[SCI_BUFFER_LENGHT];
#endif

T_UWORD auwPWMOut[FILT_NR_LEN];
T_UWORD auwUPOT[5];
void task_fast(void)
{
 CLRWDT();
 //Display_7D_Temp();
 Dispaly2raw_task();
}

void task_slow(void)
{
	//adc_convert_all();
	/*read state of butons*/
    Read_Buton_state();  
	
	/*get actual voltage U_SENSE*/
	#if (ADC_DRIVER_ENABLE==1)
	adc_convert_one_channel(0);
	uw_adcCH0=adc_getResult(0);
	#endif
	uw_ADCV0 = Convert_to_Voltage(uw_adcCH0);
	uw_Usense = Divizor_U_Sense(uw_ADCV0);
	SetDisplay_Voltage(uw_Usense);
	
	/*get actual current I_SENSE*/
	#if (ADC_DRIVER_ENABLE==1)
	adc_convert_one_channel(1);
	uw_adcCH1=adc_getResult(1);
	#endif
	uw_ADCV1 = Convert_to_Voltage(uw_adcCH1);
	uw_Isense = Rawvalue_to_Current(uw_ADCV1);
	SetDisplay_Current(uw_Isense);

	/*get Ipot raw voltage I_POT*/	
	adc_convert_one_channel(3);
	uw_adcCH3=adc_getResult(3);
	/*convert raw voltage numbers to voltage*/
	uw_ADCV3 = Convert_to_Voltage(uw_adcCH3);
	/*calculate voltage before voltage diveder*/
	uw_IPot = Divizor_U_Pot(uw_ADCV3);
	/*display target current*/
	SetDisplay_Current_target(uw_IPot);
	
	/*from voltge to pwm and compesation*/
	duty_pwm1 = UpotToPWM(uw_IPot*2);
	pwm_setDuty(0x80,duty_pwm1);
	pwm_update(0x80);
	
	/*get Upot raw voltage U_POT*/	
	adc_convert_one_channel(2);
	uw_adcCH2=adc_getResult(2);
	/*convert raw voltage numbers to voltage*/
	uw_ADCV2 = Convert_to_Voltage(uw_adcCH2);
	/*calculate voltage before voltage diveder*/
	uw_UPot = Divizor_U_Pot(uw_ADCV2);
	//uw_UPot = cycle_botifilter(auwUPOT,uw_UPot);
	/*from voltge to pwm and compesation*/
	//duty_pwm2 = uw_adcCH2;
//temp_duty_pwm2 = cycle_botifilter(auwPWMOut,(T_UWORD)uw_adcCH2);
//duty_pwm2 = cycle_botifilter(auwPWMOut,(T_UWORD)uw_adcCH2);
	if (ub_buton_s2==0)
	{
		duty_pwm2++;
		if(duty_pwm2>1023)
		{
			duty_pwm2=1023;
		}
	}
	if (ub_buton_s3==0)
	{
		if(duty_pwm2>1) 
		{
			duty_pwm2--;
		}
	}
    //duty_pwm2 =  lock_value(auwPWMOut,temp_duty_pwm2,duty_pwm2);

	ub_islimit_power = GetLimitVoltageTarget(uw_IPot,uw_Isense);
	if (ub_islimit_power == POWER_LIMIT_EN)
	{
		duty_pwm2 = 0;
		SetLimitWarnning();
	}
	else
	{
		ResetLimitWarning();
	}

	pwm_setDuty(0x00,duty_pwm2);
 	pwm_update(0x00);
}	


 


