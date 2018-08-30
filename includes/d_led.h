/*
 * LEDSegment.c
 *
 * Created: 13.07.2018 18:07:15
 * Author : Norbert Orlikowski
 */ 

#ifndef _d_led_h
#define _d_led_h

#define LED_DATA PORTA
#define LED_DATA_DIR DDRA
#define ANODY_PORT PORTC
#define ANODY_PORT_DIR DDRC

#define CA1 (1<<PC0)
#define CA2 (1<<PC1)
#define CA3 (1<<PC2)
#define CA4 (1<<PC3)

extern volatile uint8_t cy1;
extern volatile uint8_t cy2;
extern volatile uint8_t cy3;
extern volatile uint8_t cy4;
extern uint8_t start_count;

#define SEG_A (1<<0)
#define SEG_B (1<<1)
#define SEG_C (1<<2)
#define SEG_D (1<<3)
#define SEG_E (1<<4)
#define SEG_F (1<<5)
#define SEG_G (1<<6)
#define SEG_DP (1<<7)

#endif