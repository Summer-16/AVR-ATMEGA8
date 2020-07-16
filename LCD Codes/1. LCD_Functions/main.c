/************************************************** Program Title ******************

Program to display character,string and number on LCD

**************************************************Program******************************/

#include <avr/io.h>    //This is the headerfoe AVR Microcontroller
#include "lcd118010.h" //header file to program LCD

int main(void)
{
  lcd_init();             //initialization of LCD
  lcd_char('B');          //function to display a character on LCD
  lcd_gotoxy(0, 5);       //function to move the cursor position to (0th row & 5th column )
  lcd_showvalue(52);      //To print a number/variable value on LCD, it will print a 3 digit value i.e. 052
  lcd_gotoxy(1, 0);       //function to move the cursor position to (1th row & 0th column )
  lcd_string("SkillRex"); //function to display a string
  while (1)
    ;
}