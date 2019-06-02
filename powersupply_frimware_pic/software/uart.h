#include "sysdef.h"
#if (USART_DRIVER_ENABLE==1)
#ifndef _UART_
#define _UART_
#include "types.h"
#define UART_ADRRESS_ON  0
#define SCI_BUFFER_LENGHT 16
extern T_UBYTE ub_reception_done;
#define uart_Rx_succeded() (ub_reception_done)

extern void uart_init(void);
extern T_UBYTE uart_sendbyte(T_UBYTE lub_send);
extern void uart_tx_ISR(void);
extern T_UBYTE uart_recevebyte(void);
extern T_UBYTE uart_tx_pop_byte(T_UBYTE lub_tx_byte);
extern T_UBYTE uart_start_send(void);
extern void uart_rx_ISR(void);
extern void uart_FlashTx(void);
extern T_UBYTE uart_Rx_IsEmpty(void);
extern void uart_FlashRx(void);

#endif
#endif
