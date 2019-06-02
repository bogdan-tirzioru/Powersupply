#include "micro.h"
#include "sysdef.h"

#if (USART_DRIVER_ENABLE==1)
#define UART_BAUD_RATE 9600
#define UART_SPBRG ((T_UBYTE)(((double)(XTAL))/((T_ULONG)16*(UART_BAUD_RATE)))-1)

#include <pic.h>
#include "uart.h"


T_UBYTE aub_buffer_tx[SCI_BUFFER_LENGHT];
T_UBYTE ub_tail_tx;
T_UBYTE ub_head_tx;
T_UBYTE ub_lenght_sci_tx;

T_UBYTE aub_buffer_rx[SCI_BUFFER_LENGHT];
T_UBYTE ub_tail_rx;
T_UBYTE ub_head_rx;
T_UBYTE ub_lenght_sci_rx;
volatile T_UBYTE ub_error_rx_sci;
volatile T_UBYTE ub_address_reception;
T_UBYTE ub_error_byte_reception;
volatile T_UBYTE ub_address_frame_error;
T_UBYTE ub_transmision_done;
T_UBYTE ub_reception_done;
volatile T_ULONG ul_nr_tx_interruptOK;
volatile T_ULONG ul_nr_tx_interruptNOK;

void uart_init(void)
{
 T_UBYTE ub_index;
 ub_tail_tx = 0;
 ub_head_tx = 0;
 ub_lenght_sci_rx = 0;
 ub_tail_rx = 0;
 ub_head_rx = 0;
 ub_lenght_sci_rx = 0;
 ub_error_rx_sci = 0;
 ub_address_reception = 0;
 ub_error_byte_reception = 0;
 ub_address_frame_error = 0;
 ub_transmision_done = 0;
 ub_reception_done = 0;
 ul_nr_tx_interruptOK = 0;
 ul_nr_tx_interruptNOK = 0;
 ub_reception_done = 0;
 
 for(ub_index=0;ub_index<SCI_BUFFER_LENGHT;ub_index++)
 {
  aub_buffer_tx[ub_index]=0;  
  aub_buffer_rx[ub_index]=0;  
 }
 /*init device UART*/
 /*set baundgenerator*/
 /*high speed and bound rate to 9600*/
 BRGH = 1;
 SPBRG = UART_SPBRG;
 /*enable serial pins*/
 /*serial Asynchronous mode*/
 SYNC = 0;
 /*TX out*/
 TRISC6 = 0;
 /*RX in*/
 TRISC7 = 1;
 
 /*Serial port enabled (configures RC7/RX/DT and RC6/TX/CK pins as serial port pins)*/
 SPEN = 1;
 
 #if (UART_ADRRESS_ON == 1) 
 /*enable 9 bit transmision*/
 TX9 = 1;
 /*enable 9 bit reception*/
 RX9 = 1;
 /*Set ADDEN to enable address detect*/
 ADDEN = 1;
 #endif
  
 /*enable peripherial interrupts*/
 PEIE = 1;
 TXEN = 1;
 RCIE = 1;
 
 /* disable reception */
 CREN=1;
}

/*sent a single byte service*/
T_UBYTE uart_sendbyte(T_UBYTE lub_send)
{
   T_UBYTE ub_error_code;
   /*interrupt enable*/
   if(TXIF==1)
   {
    TXREG=lub_send;
    ub_error_code=0;
   }
   else
   {
    ub_error_code=1;
   }
   TXIE=1;
 return (ub_error_code);
}

/*start to send frame*/
T_UBYTE uart_start_send(void)
{
 ub_transmision_done = 0;
 if((TXIF==1 )&&(ub_lenght_sci_tx!=0))
 {
 TXIE=1;
 return 0;
 }
 else
 {
  return 1;
 }
}

/*Transmit interrupt */
void uart_tx_ISR(void)
{
  /*TRMT: Transmit Shift Register Status bit
 1 = TSR empty
 0 = TSR full*/
 
 if (TRMT  == 0)
 {
    ub_transmision_done = 0x02;
    ul_nr_tx_interruptNOK++;
 } 
 else
 { 
     ul_nr_tx_interruptOK++;
     if(ub_lenght_sci_tx==0)
     {
      TXIE=0;
      /*transmision done succefuly*/
      ub_transmision_done = 0x01;
     }
     else
     {
      #if (UART_ADRRESS_ON == 1)
      if (ub_head_tx == 0)
      {
        TX9D = 1;
      }
      else
      {
        TX9D = 0;
      }
      #endif
      TXREG = aub_buffer_tx[ub_head_tx];
      if((ub_head_tx+1)==(SCI_BUFFER_LENGHT))
      {
       ub_head_tx=0;
       /*transmision buffer overflow*/
       ub_transmision_done = ub_transmision_done | 0x2;
      }
      else
      {
       ub_head_tx++;
      }
      ub_lenght_sci_tx--;
     }
 }
 TXIF = 0;
}

T_UBYTE uart_recevebyte(void)
{
 T_UBYTE lub_return_rx_byte=0;
 if(ub_lenght_sci_rx==0)
 {
  
 }
 else
 {
  lub_return_rx_byte=aub_buffer_rx[ub_head_rx];
  if((ub_head_rx+1)==(SCI_BUFFER_LENGHT))
  {
   ub_head_rx = 0;
   ub_tail_rx = 0;
   ub_reception_done = 0;
  }
  else
  {
   ub_head_rx++;
  }
  ub_lenght_sci_rx--;
 }
 return lub_return_rx_byte;
}

void uart_rx_ISR(void)
{
 T_UBYTE ub_index=0;
 /*Read the RCSTA register to get the ninth bit and determine if any error occurred during reception.*/
 /*address bits */
 #if (UART_ADRRESS_ON == 1)
 ub_address_reception = RCSTA & 0x09;
 #endif
 ub_error_byte_reception = RCSTA & 0x06;
 ub_reception_done = ub_reception_done | ub_error_byte_reception; 
 /*Read the 8-bit received data by reading the RCREG register to determine if the device is being addressed.*/
 if ((ub_tail_rx==ub_head_rx)&&(ub_lenght_sci_rx==SCI_BUFFER_LENGHT))
 {
  ub_error_rx_sci=RCREG; /*quelle full-> bytes no more accepted*/
  /*reception buffer overflow*/
  ub_reception_done = ub_reception_done | 0x08;
 }
 else
 {
  if((ub_head_rx==0)&&(ub_lenght_sci_rx==0))
  {
   aub_buffer_rx[ub_head_rx]=RCREG;
   ub_lenght_sci_rx++;
  }
  else
  {
   if ((ub_tail_rx+1)>(SCI_BUFFER_LENGHT-1))
   {
    ub_index= ub_tail_rx+1-SCI_BUFFER_LENGHT;
   }
   else
   {
     ub_index= (ub_tail_rx+1);
   }
   
   aub_buffer_rx[ub_index]=RCREG;
   ub_tail_rx=ub_index;
   ub_lenght_sci_rx++;
   /*reception buffer full , frame it was recieved*/
   if (ub_tail_rx == (SCI_BUFFER_LENGHT-1))
   {
     ub_reception_done = ub_reception_done | 0x01;
   }
  }
 }
 if((aub_buffer_rx[ub_index] =='-') ||(aub_buffer_rx[ub_index] ==0x0d))
 {
    ub_reception_done = ub_reception_done | 0x01;
 }
 /*If any error occurred, clear the error by clearing enable bit CREN. */
 if (ub_error_byte_reception != 0)
 {
    CREN = 1;
 }
 #if (UART_ADRRESS_ON == 1)
 /* If the device has been addressed, clear the ADDEN bit to allow data bytes and address bytes
 to be read into the receive buffer and interrupt the CPU*/
 if ((ub_tail_rx != 0)&&(ub_address_reception == 0x9))
 {
    /*Error reading address , it is not on first position*/
    ub_address_frame_error = 1;
 }
 else
 {
    
 }
 if (ub_address_reception == 0x9)
 {
    ADDEN = 0;
 }
 #endif
 RCIF = 0;
}

T_UBYTE uart_tx_pop_byte(T_UBYTE lub_tx_byte)
{
 T_UBYTE ub_index=0;
 if ((ub_tail_tx==ub_head_tx)&&(ub_lenght_sci_tx==SCI_BUFFER_LENGHT))
 {
  return 1; /*quelle full-> byte not trasmited*/
 }
 else
 {
  if((ub_head_tx==0)&&(ub_lenght_sci_tx==0))
  {
   aub_buffer_tx[ub_head_tx]=lub_tx_byte;
   ub_lenght_sci_tx++;
  }
  else
  {
   if ((ub_tail_tx+1)>(SCI_BUFFER_LENGHT-1))
   {
    ub_index= ub_tail_tx+1-SCI_BUFFER_LENGHT;
   }
   else
   {
     ub_index= (ub_tail_tx+1);
   }
   aub_buffer_tx[ub_index]=lub_tx_byte;
   ub_tail_tx=ub_index;
   ub_lenght_sci_tx++;
  }
 }
 return 0;
}

T_UBYTE uart_Tx_succeded(void)
{
 return (ub_transmision_done);
}

void uart_FlashTx(void)
{
 ub_tail_tx = 0;
 ub_head_tx = 0;
}
void uart_FlashRx(void)
{
 ub_lenght_sci_rx = 0;
 ub_tail_rx = 0;
 ub_head_rx = 0;
 ub_lenght_sci_rx = 0;
 ub_error_rx_sci = 0;
 ub_address_reception = 0;
 ub_error_byte_reception = 0;
 ub_address_frame_error = 0;
 ub_reception_done = 0;
}

T_UBYTE uart_Rx_IsEmpty(void)
{
    T_UBYTE lub_result = 0;
    if (ub_tail_rx == ub_head_rx)
    {
        lub_result = 1;
    }
    else
    {
        lub_result = 0;
    }
return lub_result;
}
#endif
