
#ifndef switches_included

#define switches_included


// added more bits for the other 3 bottons
#define SW1 BIT0
#define SW2 BIT1
#define SW3 BIT2
#define SW4 BIT3

#define SWITCHES (SW1|SW2|SW3|SW4)

void switch_init();

void switch_interrupt_handler();



extern char switch_state_down, switch_state_changed, s1,s2,s3,s4; 
extern int beat; // used for the changing beat in button 2


#endif // included
