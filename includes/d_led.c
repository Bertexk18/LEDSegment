/*
 * LEDSegment.c
 *
 * Created: 13.07.2018 18:07:15
 * Author : Norbert Orlikowski
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/pgmspace.h>
#include "d_led.h"

const uint8_t cyfry[15] PROGMEM = {
	~(SEG_A|SEG_B|SEG_E|SEG_D|SEG_C|SEG_F),			// 0
	~(SEG_B|SEG_C),									// 1
	~(SEG_A|SEG_B|SEG_D|SEG_E|SEG_G),				// 2
	~(SEG_A|SEG_B|SEG_C|SEG_D|SEG_G),				// 3
	~(SEG_B|SEG_C|SEG_F|SEG_G),						// 4
	~(SEG_A|SEG_C|SEG_D|SEG_F|SEG_G),				// 5
	~(SEG_A|SEG_C|SEG_D|SEG_E|SEG_F|SEG_G),			// 6
	~(SEG_A|SEG_B|SEG_C|SEG_F),						// 7
	~(SEG_A|SEG_B|SEG_C|SEG_D|SEG_E|SEG_F|SEG_G),	// 8
	~(SEG_A|SEG_B|SEG_C|SEG_D|SEG_F|SEG_G),			// 9
	//0xFF											// NIC (puste miejsce)
};

volatile uint8_t cy1;
volatile uint8_t cy2;
volatile uint8_t cy3;
volatile uint8_t cy4;

void d_init(void) {
	LED_DATA_DIR = 0xFF;
	LED_DATA = 0xFF;
	
	ANODY_PORT_DIR |= CA1 | CA2 | CA3 | CA4;
	ANODY_PORT |= (CA1 | CA2 | CA3 | CA4);
	
	TCCR0 |= (1<<WGM01);
	TCCR0 |= (1<<CS02)|(1<<CS00);
	OCR0 = 38;
	TIMSK |= (1<<OCIE0);
}

ISR(TIMER0_COMP_vect) {
	static uint8_t licznik = 1;
	
	if (licznik == 1)
	{
		LED_DATA = pgm_read_byte( &cyfry[cy1] );
	}
	else if(licznik == 2)
	{
		LED_DATA = pgm_read_byte( &cyfry[cy2] );
	}
	else if(licznik == 4)
	{
		LED_DATA = pgm_read_byte( &cyfry[cy3] );
	}
	else if(licznik == 8)
	{
		LED_DATA = pgm_read_byte( &cyfry[cy4] );
	}
	ANODY_PORT = (ANODY_PORT & 0xF0) | (~licznik & 0x0F);
	licznik <<= 1;
	if (licznik > 8)
	{
		licznik = 1;
	}
}