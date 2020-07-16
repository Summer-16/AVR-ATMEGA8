
/************************************************** Program Title ******************

//program to do read and write operation in AVR's internal EEPROM 

****************************************************Program***********************/

#include <avr/io.h>
#include <avr/eeprom.h> //header file for EEPROM
#include "lcd118010.h"

int main(void)
{

  unsigned char a, b, c;
  lcd_init();
  eeprom_write_byte(0, 1);  //write 1 in 0th memory location
  eeprom_write_byte(1, 2);  //write 2 in 1st memory location
  eeprom_write_byte(2, 3);  //write 3 in 2nd memory location
  eeprom_write_byte(7, 1);  //write 1 in 7th memory location
  eeprom_write_byte(10, 2); //write 2 in 10th memory location
  eeprom_write_byte(8, 3);  //write 3 in 8th memory location

  DDRC = 0x00; //initialization for switch S0
  PORTC = 0x01;
  b = 0; //incrementer
  while (1)
  {

    if ((PINC & 0x01) == 0x00) //if switch S0 is pressed
    {
      while ((PINC & 0x01) == 0x00)
        ;                      //wait until switch S0 is not released
      a = eeprom_read_byte(b); //read a  byte from bth memory location of EEPROM
      lcd_gotoxy(0, 0);
      lcd_showvalue(b);
      lcd_string("-");
      lcd_showvalue(a);
      b++; //increment variable to read the next memory location
    }
  }
}