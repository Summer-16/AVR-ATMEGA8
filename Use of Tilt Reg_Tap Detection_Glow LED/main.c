/*********************************************************Program Title**************

Program to read the tilt register for tap detection & to glow LED if tap is there

************************************************** Company/HW/SW etc Details*********
COPYRIGHT(C)SkillRex Technology
Date:...............19th SEPT 2015
Author:.............SkillRex Technology R&D Team
Organization:.......SkillRex Technology
Target System:......AVR Devlopment Board S/N-118010
Manufacturer:.......SkillRex Technology
Microcontroller:....ATmega-8
Clock:..............12mhz
Compiler Used:...........WinAVR-20100110

***************************************************Connection Details***************

SCL-PC5
SDA-PC4

***************************************************Program**************************/


#include<avr/io.h>                   
#include<util/delay.h>
#include"I2C.h"

void main()
{
	unsigned char t=0;
	DDRB=0x0f;
	
	write(0x07,0x00);		 // MODE --- Stand By
	write(0x09,0x74);		 // PDET ---
	write(0x08,0x00);		 // SR ---
	write(0x0A,0x08);		 // PD ---
	write(0x07,0x01);		 // MODE --- Active, INT push-pull
	

	while(1)
	{
		t=read(0x03);      	 //reading tilt status register
		
		if((t & 32)==32)    //detecting tap i.e D5
		{
			PORTB=0x0f;
			_delay_ms(100);
		}
		else
		{
			PORTB=0x00;
			_delay_ms(100);
		}		
	}
}