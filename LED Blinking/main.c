/************************************************* Program Title ******************

/*program to blink all the LEDS connected in PORTB


************************************************** Connection Details *************

LED-PORTB

***************************************************Program ***********************/

#include <avr/io.h>			//This is the header for AVR Microcontroller.
#include <util/delay.h> //header file to generate time delay.

int main(void)
{
	DDRB = 0x0F; //Port B data direction declaration as output.

	while (1) //This is for the the infinity loop.
	{
		PORTB = 0X0F;		 //Switch on all 4 LEDs
		_delay_ms(1000); //Delay of 1sec=1000msec
		PORTB = 0X00;		 //Switch off all 4 LEDs
		_delay_ms(1000); //Delay of 1sec=1000msec
	}
}
