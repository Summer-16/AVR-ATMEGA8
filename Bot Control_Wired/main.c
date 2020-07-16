/***********************************************************************

Program to read X & Y register & control a robotic vehicle movement.

************************************************** Connection Details *************

SCL-PC5
SDA-PC4

Motor

PORTD4(M4)-Right Motor+
PORTD5(M5)-Right Motor-
PORTD6(M6)-Left Motor-
PORTD7(M7)-Left Motor+
***************************************************Program ***********************/

#include <avr/io.h>
#include <util/delay.h>
#include "lcd118010.h"
#include "I2C.h"

void main()
{
	unsigned char x = 0, y = 0;

	DDRD = 0xF0;
	PORTD = 0x00;

	lcd_init();
	lcd_gotoxy(0, 0);
	lcd_string("Robot Control");
	_delay_ms(1000);
	lcd_gotoxy(0, 0);
	lcd_string("                ");

	write(0x07, 0x01); //Active mode

	while (1)
	{

		/******************************** X - Data ***************************/

		x = read(0x00);

		lcd_gotoxy(0, 0);
		lcd_string("X=");
		lcd_showvalue(x);

		/******************************** Y - Data ***************************/

		y = read(0x01);

		lcd_gotoxy(0, 9);
		lcd_string("Y=");
		lcd_showvalue(y);

		/******************************** Computation ***************************/

		if ((x > 12) & (x < 25))
		{
			PORTD = 0x10;
			lcd_gotoxy(1, 0);
			lcd_string("Right           ");
		}

		else if ((x < 55) & (x > 45))
		{
			PORTD = 0x80;
			lcd_gotoxy(1, 0);
			lcd_string("Left            ");
		}

		else if ((y > 5) & (y < 25))
		{
			PORTD = 0x90;
			lcd_gotoxy(1, 0);
			lcd_string("Forward         ");
		}

		else if ((y < 55) & (y > 45))
		{
			PORTD = 0x60;
			lcd_gotoxy(1, 0);
			lcd_string("Backward        ");
		}

		else
		{
			PORTD = 0x00;
			lcd_gotoxy(1, 0);
			lcd_string("Stop            ");
		}
	}
}