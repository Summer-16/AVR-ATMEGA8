/************************************************** Program Title ******************

Taking input from switch & glowing LED using Switch Case 

************************************************** Connection Details *************

PORTC 0   - Switch (Gives Low Input to UC)
PORTB 0-3 - LED (Active High)

**************************************************Program ***********************/

#include <avr/io.h> //This is the header for AVR Microcontroller.

int main(void)
{
	DDRC = 0x00;	// PORTC data direction configuration as input port.
	PORTC = 0x01; // PORTC lowest bit initialization as high (Pull-up mode)

	DDRB = 0x0F;	// PORTB lower nibble data direction configuration as output port.
	PORTB = 0x00; // Initial value to PORTB is 00

	unsigned char i = 0;

	while (1)
	{

		if ((PINC & 0x01) == 0x00) //checking for switch press at s0.
		{
			i++;
			if (i > 4)
			{
				i = 0;
			}
			while ((PINC & 0x01) == 0x00)
				;
		}
		switch (i)
		{
		case 0:
			PORTB = 0x00; //Turning Off All four LED
			break;
		case 1:
			PORTB = 0x01; //glow LED0
			break;
		case 2:
			PORTB = 0x02; //glow LED1
			break;
		case 3:
			PORTB = 0x04; //glow LED2
			break;
		case 4:
			PORTB = 0x08; //glow LED3
			break;
		}
	}
}
