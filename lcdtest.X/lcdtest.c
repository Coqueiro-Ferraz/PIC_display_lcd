/*
 * File:   lcdtest.c
 * Author: Henrique
 *
 * Created on 21 de Abril de 2023, 10:43
 */

#pragma config FOSC = INTRC_NOCLKOUT// Oscillator Selection bits (INTOSCIO oscillator: I/O function on RA6/OSC2/CLKOUT pin, I/O function on RA7/OSC1/CLKIN)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled and can be enabled by SWDTEN bit of the WDTCON register)

#include <xc.h>
#include "string.h"
#include "biblioteca_lcd.h"

#define _XTAL_FREQ 4000000
/*
#define lcd_rs RC0
#define lcd_en RC1
#define lcd_d4 RC2
#define lcd_d5 RC3
#define lcd_d6 RC4
#define lcd_d7 RC5*/

char robo[8] = {0x0E, 0x11, 0x0E, 0x04,
                0x1F, 0x04, 0x0A, 0X10};

lcd_pin_t lcd_pins = {
    &PORTC, 0,
    &PORTD, 0,
    &PORTC, 2, 3, 4, 5
};


void main() 
{
    TRISC = 0x00;
    PORTC = 0x00;
    TRISD = 0x00;
    PORTD = 0x00;
    
    lcd_init(&lcd_pins);
    escreve(2,3,"Henrique");
    grava_caractere(0, &robo[0]);
          
    
    
    usa_caractere(1,2,0);
    usa_caractere(1,4,'5');
    while(1)
    {
  //byte(1,0x00);
    }
}
