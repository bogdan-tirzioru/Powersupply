#include "micro.h"
#include "buton.h"
#include "adc.h"
#include "signal_proc.h"
bank2 T_UBYTE ub_buton_s2;
bank2 T_UBYTE ub_buton_s3;
bank2 T_UWORD uw_adcCH3;
bank2 T_UWORD uw_ADCVS3;
bank2 T_UWORD uw_adcCH4;
bank2 T_UWORD uw_ADCVS4;
void Read_Buton_state(void)
{
   
   #if (ADC_DRIVER_ENABLE==1)
    adc_convert_one_channel(4);
    uw_adcCH4=adc_getResult(4);
    #endif

    uw_ADCVS4 = Convert_to_Voltage(uw_adcCH4);
    if (uw_ADCVS4 <Button_down_voltage)

    {
        ub_buton_s3 = 0;
    }
    else
    {
        ub_buton_s3 = 1;
    }

	if ((PORTA & 0x10) ==0x10)
	{
		 ub_buton_s2 = 1;
	}
	else
	{
		 ub_buton_s2 = 0;
	}

}
void Init_Buton(void)
{
    ub_buton_s2 = 1;
    ub_buton_s3 = 1;
}
