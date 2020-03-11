#include "micro.h"
#include "sysdef.h"
#include "init.h"
#include "tasks.h"
#include "types.h"
#include "pwm.h"
#include "signal_proc.h"
#include "lcd.h"

#define PRELOAD_TIMER0 250
#define TASK_1 4
#define TASK_2 200
#define enable_INT() {GIE=1;}
#define disable_INT() {GIE=0;}

//__CONFIG(FOSC_HS & WDTE_OFF & CP_OFF & BOREN_OFF & LVP_OFF & CPD_OFF & DEBUG_ON);

T_UBYTE ub_task=0;
T_ULONG ul_task1=0;

T_ULONG ul_mseconds;
T_ULONG ul_task2;

void init_timer0(void)
{
 /*internal clock*/
 T0CS=0;
 /*enable prescaler*/
 PSA=0;
 /*prescaler 256*/
 PS2=0;
 PS1=0;
 PS0=0;
 
 /*enable timer0 interrupt*/
 TMR0IE=1;
 /*enable peripherial interrupts*/
 PEIE=1;
 enable_INT();
}

/*8ms isr periodic*/
void timer0_isr(void)
{
  ul_mseconds++;
  ul_task1++;
  ul_task2++;
  TMR0 += -PRELOAD_TIMER0;    // re-load timer
  if ((ul_task1&TASK_1)==TASK_1)
  {
   ub_task=ub_task|0x01;
   ul_task1=0;
  }
  if ((ul_task2&TASK_2)==TASK_2)
  {
   ub_task=ub_task|0x02;
   ul_task2=0;   
  }
  TMR0IF=0;
}
void interrupt external_isr(void) @ 0x10
{
 if (TMR0IF==1)
  timer0_isr();
 #if (USART_DRIVER_ENABLE==1)
 if(RCIF==1)
    {
       uart_rx_ISR();  
    }
 if((TXIF==1)&&( TXIE==1))
    {
       uart_tx_ISR();  
    }
 #endif 
}
void main(void)
{
 init();
 init_timer0();

 while(1)
 {
    
   if ((ub_task&0x02)==0x2)
     {
       task_slow();
       ub_task=ub_task&(~0x02);
       ul_task1++;
     }    
   if ((ub_task&0x01)==0x1)
     {
       task_fast();
       ub_task=ub_task&(~0x01);
     }
       
    if (ul_mseconds>0Xffffff00)
     {
        ul_mseconds=0;
        ul_task1=0;
        ul_task2=0;
        enable_INT();
     }
 }
}
