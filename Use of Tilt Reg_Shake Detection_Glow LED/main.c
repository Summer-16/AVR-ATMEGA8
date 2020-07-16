/***********************************************************************

Program to read the tilt register for shake detection & glow LED using same.

***********************************************************************
COPYRIGHT(C)SkillRex Technology
Date:...............19th SEPT 2015
Author:.............SkillRex Technology R&D Team
Organization:.......SkillRex Technology
Target System:......AVR Devlopment Board S/N-118010
Manufacturer:.......SkillRex Technology
Microcontroller:....ATmega-8
Clock:..............12mhz
Compiler Used:...........WinAVR-20100110
***********************************************************************
SCL-PC5
SDA-PC4
***********************************************************************/


#include<avr/io.h>                   
#include<util/delay.h>
#include"lcd118010.h"
#include"I2C.h"

void main()
{
	unsigned char t=0;
	DDRB=0X0F;
	//Different register configurations for shake detection
	
	write(0x07,0x00);		// MODE --- Stand By, to allow you to change/write/modify other registers (no o/p will be there in Xout, Yout, Zout & Tilt Reg in this mode)
	write(0x09,0x74);		// PDET ---
	write(0x08,0x00);		// SR ---
	write(0x0A,0x08);		// PD ---
	write(0x07,0x01);		// MODE --- Active, to read different register values 
	

	while(1)
	{
		t=read(0x03);      	//reading tilt status register
		
		if((t & 128)==128)  //detecting shake i.e D7
		{
			PORTB=0X0F;
			_delay_ms(1000);
		}
		else	
			PORTB=0X00;
	}	
}
	
