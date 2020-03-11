#include "micro.h"
#include "init.h"
#include "io.h"
#include "pwm.h"
#include "uart.h"
#include "adc.h"
#include "sysdef.h"
#include "tasks.h"
#include "signal_proc.h"
#include "Display_2raw.h"
#include "adc.h"
#include "power.h"
#include "control.h"
#if (PWM_DRIVER_ENABLE==1)
T_UWORD duty_pwm1;
T_UWORD duty_pwm2;
#endif

void init(void)
{
 io_init();
  #if (PWM_DRIVER_ENABLE==1)
 /*set pwm channel 1*/
 duty_pwm1=0;
 duty_pwm2=0;
 pwm_setPeriod(4000);
 pwm_setDuty(0x80,duty_pwm1);
 pwm_update(0x80);
 pwm_init(0x80);

 /*set pwm channel 2*/
 pwm_setDuty(0x00,duty_pwm2);
 pwm_update(0x00);
 pwm_init(0x00);
 #endif
 
 /*set uart*/
 #if (USART_DRIVER_ENABLE==1)
 uart_init();
 #endif
 
 #if (ADC_DRIVER_ENABLE==1)
 /*initialization of ADC device*/
 adc_init();
 #endif
 init_signal_procesing();
 //InitDisplay7D();
 InitDisplay2raw();
 init_botifilter(auwUPOT,0);
 init_botifilter(auwPWMOut,0);
}
