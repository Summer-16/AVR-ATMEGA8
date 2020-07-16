/************************************************* Program Title ******************

Program to read the register values & display it on the LCD after manipulating it.

************************************************** Connection Details *************

SCL-PC5
SDA-PC4

***************************************************Program Starting **********************/

#include <avr/io.h>
#include <util/delay.h>
#include "lcd118010.h"
#include "I2C.h"

void main()
{
	unsigned char tilt = 0, pola = 0;

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

		pola = (tilt & 28); //detecting for PoLa i.e [D2:D4]

		if (pola == 0)
		{
			lcd_gotoxy(1, 0);
			lcd_string("Unknown LR/UN/DI");
		}

		else if (pola == 4)
		{
			lcd_gotoxy(1, 0);
			lcd_string("L to Left       ");
		}

		else if (pola == 8)
		{
			lcd_gotoxy(1, 0);
			lcd_string("L to Right      ");
		}

		else if (pola == 20)
		{
			lcd_gotoxy(1, 0);
			lcd_string("Vert Down Inv   ");
		}

		else if (pola == 24)
		{
			lcd_gotoxy(1, 0);
			lcd_string("Vert Up Normal  ");
		}
	}
}
