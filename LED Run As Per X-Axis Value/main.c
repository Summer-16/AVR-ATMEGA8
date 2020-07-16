/************************************************* Program Title ******************

Program to run LEDs Left to Right or Right to Left according to x-Axis value of Acceleration Sensor 

************************************************** Connection Details *************

SCL-PC5
SDA-PC4

***************************************************Program ***********************/
#include <avr/io.h>
#include <util/delay.h>
#include "I2C.h"

void main()
{
	unsigned char x = 0;
	DDRB = 0x0f;

	write(0x07, 0x01);

	while (1)
	{
		x = read(0x00);

		if (x <= 25)
		{
			PORTB = 0x00;
			_delay_ms(300);
			PORTB = 0x08;
			_delay_ms(300);
			PORTB = 0x0c;
			_delay_ms(300);
			PORTB = 0x0e;
			_delay_ms(300);
			PORTB = 0x0f;
			_delay_ms(300);
		}

		else if (x >= 40)
		{
			PORTB = 0x01;
			_delay_ms(300);
			PORTB = 0x03;
			_delay_ms(300);
			PORTB = 0x07;
			_delay_ms(300);
			PORTB = 0x0f;
			_delay_ms(300);
			PORTB = 0x00;
			_delay_ms(300);
		}

		else
			PORTB = 0x00;
	}
}