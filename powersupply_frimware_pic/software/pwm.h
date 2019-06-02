#include "sysdef.h"
#if (PWM_DRIVER_ENABLE==1)
#ifndef _PWM_
#define _PWM_
#include "types.h"
#if (XTAL ==16934400)
 #define PWM_SHIFT_FACT 2
#else
 #if (XTAL ==4000000)
  #define PWM_SHIFT_FACT 4
 #endif
#endif

typedef struct T_PWM{
 T_UWORD duty_1;
 T_UWORD duty_2;
 T_UWORD period;
 T_UBYTE channel;
};

extern struct T_PWM s_pwm;

/*---------------------------*/
/*channel field*/
/*7- current channel selected*/
/*6- request period*/
/*5- request duty*/
/*-------------------------*/
extern void pwm_init(T_UBYTE loc_channel);
extern void pwm_setDuty(T_UBYTE loc_channel,T_UWORD lul_Duty);
extern T_UBYTE pwm_getDuty(T_UBYTE channel);
extern void pwm_setPeriod(T_UWORD lul_Period);
extern T_UWORD pwm_getPeriod(void);
extern void pwm_update(T_UBYTE loc_channel);
extern void pwm_disable(T_UBYTE loc_channel);
#endif
#endif
