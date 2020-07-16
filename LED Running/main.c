
/************************************************* Program Title ******************

/*Program to run all the LEDs connected in PORT B.

************************************************** Connection Details *************

LED-PORTB

***************************************************Program ***********************/

#include <avr/io.h>			//This is the header for AVR Microcontroller.
#include <util/delay.h> //header file to generate time delay.

int main(void)
{
	PORTB = 0X00; // PortB initiallization as all bits low.
	DDRB = 0X0F;	// PortB data direction declaration as out put.
	unsigned char x;

	while (1)
	{
		for (x = 0x01; x != 0x10; x <<= 1) //initialize x with (00000001), while x not equals to (00010000) left shift the content of x
		{
			PORTB = x;			//assign the value of x to PORTB
			_delay_ms(300); // wait for 300 miliseconds
		}
	}
}
