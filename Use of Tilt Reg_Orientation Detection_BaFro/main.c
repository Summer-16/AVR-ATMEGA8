/************************************************* Program Title ******************

Program to read the register values & display it on the LCD after manipulating it.

***************************************************Connection Details**************

SCL-PC5
SDA-PC4

***************************************************Program***********************/

#include <avr/io.h>
#include <util/delay.h>
#include "lcd118010.h"
#include "I2C.h"

void main()
{
	unsigned char tilt = 0, bafro = 0;

	lcd_init();
	lcd_gotoxy(0, 0);
	lcd_string("Orientation Det.");
	_delay_ms(1000);
	lcd_gotoxy(0, 0);
	lcd_string("                ");

	// Different register configurations for shake & tap detection

	write(0x07, 0x00); // MODE --- Stand By, to allow you to change/write/modify other registers (no o/p will be there in Xout, Yout, Zout & Tilt Reg in this mode)
	write(0x09, 0x74); // PDET ---
	write(0x08, 0x00); // SR ---
	write(0x0A, 0x08); // PD ---
	write(0x07, 0x01); // MODE --- Active, to read different register values

	while (1)
	{
		tilt = read(0x03);

		bafro = (tilt & 3); //detecting for BaFro i.e [D0:D1]
		if (bafro == 0)
		{
			lcd_gotoxy(0, 0);
			lcd_string("Unknown B/F     ");
		}

		else if (bafro == 1)
		{
			lcd_gotoxy(0, 0);
			lcd_string("Top/Front       ");
		}

		else if (bafro == 2)
		{
			lcd_gotoxy(0, 0);
			lcd_string("Bottom/Back     ");
		}
	}
}