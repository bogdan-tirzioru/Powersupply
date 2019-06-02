#ifndef _INIT_
#define _INIT_
#include "pwm.h"
#include "uart.h"
#include "adc.h"
#include "sysdef.h"

#if (PWM_DRIVER_ENABLE==1)
extern T_UWORD duty_pwm1;
extern T_UWORD duty_pwm2;
#endif

extern void init(void);
#endif
