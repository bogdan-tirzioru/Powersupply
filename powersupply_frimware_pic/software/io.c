#include "micro.h"
#include "io.h"
void io_init(void)
{
 TRISA=TRISA&0xFF;
 TRISB=TRISB&0x00;
 TRISC=TRISC&0x00;
 PORTB = 0x00;
 PORTC = 0x00;
 //while(1);
}
