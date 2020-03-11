#include "processing.h"
#define ADCVoltageReferince ((double)3.3)
#define ADCNrBitRezolution 12
double Convert_to_Voltage(uint16_t ui16ADCRawNumber)
{
	double ret_Value=0; /*Voltage*/
	/*x--->RawVoltage*/
	/*3V--->2^12*/
	if(ADCVoltageReferince!=0)
		ret_Value = ui16ADCRawNumber * ADCVoltageReferince/(((uint32_t)1)<<ADCNrBitRezolution);
	return ret_Value;
}
double ADC_to_Physical_VoltageDivider(double d_VoltageADC,uint32_t ui32RezistorUper,uint32_t ui32RezistorLower)
{
	double ret_Value=0; /*Voltage*/
	if (((double)ui32RezistorUper+ui32RezistorLower)!=0)
		ret_Value = ((double)(ui32RezistorUper+ui32RezistorLower)*d_VoltageADC)/ui32RezistorLower;
	return ret_Value;
}

double ADC_to_PhysicalINA169(double d_VoltageADC,double dRezitorSarcina,uint32_t ui32RezitorLeader)
{
	/*Vout = IsRs(1000uA/V)(Rl)*/
	/*Is=Vout/(Rs(1000uA/V)(Rl))*/
	double ret_ValueI=0; /*Voltage*/
	if ((dRezitorSarcina !=0)&&(ui32RezitorLeader!=0))
			ret_ValueI = (double)d_VoltageADC /(dRezitorSarcina*0.001*ui32RezitorLeader);
	return ret_ValueI;
}

double ADC_to_PhysicalIntrumentationAmplifier(double d_VoltageADC,double dRezitorSarcina,double dfactorInstrumentation)
{
	double ret_ValueI=0; /*Current returned in phisical*/
	if ((dRezitorSarcina !=0)&&(dfactorInstrumentation!=0))
		ret_ValueI = (double)d_VoltageADC /(dfactorInstrumentation*dRezitorSarcina);
	return ret_ValueI;
}
