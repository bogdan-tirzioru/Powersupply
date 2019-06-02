#ifndef PROCESSING_H
#define PROCESSING_H
#include "micro.h"
extern double Convert_to_Voltage(uint16_t ADC_LiniarVoltage);
extern double ADC_to_Physical_VoltageDivider(uint16_t d_VoltageADC,uint32_t ui32RezistorUper,uint32_t ui32RezistorLower);
extern double ADC_to_PhysicalINA169(uint16_t d_VoltageADC,double dRezitorSarcina,uint32_t ui32RezitorLeader);
#endif
