
/************************************************** Program Title ******************

/*Program to display number of times switch S0 is pressed

S0-PORTC0

****************************************************Program***************************/

#include <avr/io.h>
#include "lcd118010.h"

int main(void)
{
	unsigned char x; //variable declaration
	lcd_init();
	DDRC = 0x00;
	PORTC = 0x01;
	while (1)
	{
		if ((PINC & 0x01) == 0x00) //check for switch press i.e S0
		{
			while ((PINC & 0x01) == 0x00)
				; //switch debouncing i.e. wait for release of the switch
			x++;
			lcd_gotoxy(1, 1); //to move the cursor of lcd
			lcd_showvalue(x); //print the contents of x
		}
	}
}