/*
 * LEDSegment.c
 *
 * Created: 13.07.2018 18:07:15
 * Author : Norbert Orlikowski
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "includes/d_led.h"

int main(void)
{
	d_init();
	uint8_t i;
	
	cy1 = 9;
	cy2 = 5;
	cy3 = 2;
	cy4 = 9;
	sei();
    /* Replace with your application code */
    while (1) 
    {
		for (i = 9; i--; i>0)
		{
			_delay_ms(50);
			cy4--;
			if (cy4 == 0)
			{
				cy3--;
				cy4 = 9;
			}
			if (cy3 == 0)
			{
				cy2--;
				cy4 = 9;
				cy3 = 9;
			}
			if (cy2 == 0)
			{
				cy1--;
				cy4 = 9;
				cy3 = 9;
				cy2 = 9;
			}
		}
    }
}

