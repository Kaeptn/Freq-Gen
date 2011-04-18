#include <stdlib.h>
#include <avr/io.h>
#include <util/delay.h>

#include "ltc1257.h"

/* define CPU frequency in Mhz here if not defined in Makefile */
#ifndef F_CPU
#define F_CPU 12000000UL
#endif

int main(void);
inline void ioinit(void);

int main(void) {

  unsigned int steps = 0;
  unsigned int loop = 0;

  ioinit();

  while(1) {

 /*   ltc1257_ll_write(steps);
    
    steps += 50;
    
    if(steps>= 4000)
      steps=0;
 
    _delay_ms(10); 
   */ 
    PORTC=0xff;
    _delay_ms(500);
    PORTC=0;
    _delay_ms(500); 

  }    

}

inline void ioinit(void)
{
	/* IO setup: */
	DDRA = (1 << PA3) | (1 << PA4) | (1 << PA5);	/* LTC1257 pins (output) */
	DDRC=0x11111111b;
  	
	/* Low-level init of DAC: */
	ltc1257_ll_init();
}
