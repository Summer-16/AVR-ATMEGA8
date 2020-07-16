
/************************************************** Program Title ******************

/*Program to control  DC motor 

************************************************** Connection Details *************
M0-PORTD4-motor1 Brown(+) 
M1-PORTD5-motor1 Black(-)
M2-PORTD6-motor2 Brown(+)
M3-PORTD7-motor2 Black(-) 
***************************************************Program****************************/

#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
  DDRD = 0xF0; //Setting the data direction of PORTD where motors are connected
  while (1)
  {
    PORTD = 0x60; //moving ROBOT forward
    _delay_ms(1000);
    PORTD = 0x90; //moving ROBOT backward
    _delay_ms(1000);
  }
}