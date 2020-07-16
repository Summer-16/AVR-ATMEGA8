/************************************************** Program Title ******************

/*Program to use command and scroll entire display


****************************************************Program***********************/

#include <avr/io.h>
#include <util/delay.h>
#include "lcd118010.h"

int main(void)
{
	unsigned char x; //variable declaration
	char str1[] = "SkillRex";
	char str2[] = "Technology";
	lcd_init();
	lcd_string(str1);
	lcd_cmd(0xc0); //Command to move cursor to second line
	lcd_string(str2);
	while (1)
	{
		lcd_cmd(0x18); //scroll entire display towards lef
		_delay_ms(400);
	}
}