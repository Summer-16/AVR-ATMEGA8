/************************************************** Program Title ******************

Taking input from switch & glowing LED

************************************************** Connection Details *************

PORTC 0   - Switch (Gives Low Input to UC)
PORTB 0-3 - LED (Active High)
***************************************************Program ***********************/

#include <avr/io.h> //This is the header for AVR Microcontroller.

int main(void)
{
	DDRC = 0x00;	// PORTC data direction configuration as input port.
	PORTC = 0x01; // PORTC lowest bit initialization as high (Pull-up mode)

	DDRB = 0x0F;	// PORTB lower nibble data direction configuration as output port.
	PORTB = 0x00; // Initial value to PORTB is 00

	while (1)
	{
		if ((PINC & 0x01) == 0x00) //checking for switch press at s0.
		{
			PORTB = 0x0F; //glow All four LED
		}
		else
		{
			PORTB = 0x00; //Turning Off All four LED
		}
	}
}
