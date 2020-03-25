


#include<msp430.h>
#define LED_RED BIT0               // P1.0

#define LED_GREEN BIT6             // P1.6

#define LEDS (BIT0 | BIT6)


unsigned char red_on = 0, green_on = 0;

unsigned char led_changed = 0;



static char redVal[] = {0, LED_RED}, greenVal[] = {0, LED_GREEN};


void main(){
P1DIR |= LEDS;// bits attached to leds are output

led_changed = 1;

led_update();
}
