/************************************************** Program Title ******************

Taking input from switch & Control a robot

************************************************** Connection Details *************

M0-PORTD4-motor1 Brown(+) 
M1-PORTD5-motor1 Black(-)
M2-PORTD6-motor2 Brown(+)
M3-PORTD7-motor2 Black(-) 

**************************************************Program **********************/

#include <avr/io.h> //This is the header for AVR Microcontroller.

int main(void)
{
	DDRC = 0x00;	// PORTC data direction configuration as input port.
	PORTC = 0x01; // PORTC lowest bit initialization as high (Pull-up mode)

	DDRB = 0x0F;	// PORTB lower nibble data direction configuration as output port.
	PORTB = 0x00; // Initial value to PORTB is 00

	DDRD = 0xF0;	// PORTD Higher nibble data direction configuration as output port.
	PORTD = 0x00; // Initial value to PORTD is 00

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
			PORTD = 0x00; //Robot Stop
			break;
		case 1:
			PORTB = 0x01; //glow LED0
			PORTD = 0x60; //moving ROBOT forward
			break;
		case 2:
			PORTB = 0x02; //glow LED1
			PORTD = 0x90; //moving ROBOT backward
			break;
		case 3:
			PORTB = 0x04; //glow LED2
			PORTD = 0x40; //moving ROBOT Left
			break;
		case 4:
			PORTB = 0x08; //glow LED3
			PORTD = 0x20; //moving ROBOT Right
			break;
		}
	}
}
