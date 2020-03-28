#include <msp430.h>
#include "switches.h"

#include "led.h"
#include "buzzer.h"
#include "stateMachine.h"
void turnOff();
void button_state(); // added these two for the methods in assembly
int state;
char switch_state_down, switch_state_changed, s1, s2, s3, s4; /* effectively boolean */
int beat = 600;// used to cahnge the beat of the tune

// used some of the methods provided by the demo labs to complete this lab
static char

switch_update_interrupt_sense()

{

  char p1val = P2IN;

  /* update switch interrupt to detect changes from current buttons */

  P2IES |= (p1val & SWITCHES);/* if switch up, sense down */

  P2IES &= (p1val | ~SWITCHES);/* if switch down, sense up */

  return p1val;

}



void

switch_init()/* setup switch */

{

  P2REN |= SWITCHES;/* enables resistors for switches */

  P2IE |= SWITCHES;/* enable interrupts from switches */

  P2OUT |= SWITCHES;/* pull-ups for switches */

  P2DIR &= ~SWITCHES;/* set switches' bits for input */

  switch_update_interrupt_sense();

  led_update();

}



void

switch_interrupt_handler()

{

  char p1val = switch_update_interrupt_sense();
  // sets up values for the switches to check if pressed then te if statements check and carry out      an action depending the button pressed more in README.md
  s1 = (p1val & SW1) ? 0 : 1;
  s2 = (p1val & SW2) ? 0 : 1;
  s3 = (p1val & SW3) ? 0 : 1;
  s4 = (p1val & SW4) ? 0 : 1;
  button_state();
   /* Used for switch cases
  if(s1) {
    state = 1;
  }
  else if(s2) {

    state = 2;
  }
  else if(s3) {
    state = 3;
  }
  else if(s4) {
    state = 4;

  }
   */
   
   /* I made the fallowing into switch cases (below) then to a function in assembly called button_s      tate();
  if (s1) {
    switch_state_down = s1;
    switch_state_changed = 1;
    buzzer_set_period(1000);
    dim1 = 1;
  }

  else if(s2) {
      switch_state_down = s2;
      switch_state_changed = 1;
      buzzer_set_period(beat);
      beat = beat + 50;// used to change the beat every time its pressed.
      if (beat >2000) {
	beat = 600;
      }
      led_init();
      toggle_red();
      
      dim1 = 0;
      green_on =1;
      led_update();
  }
  else if(s3) {
    switch_state_down = s3;
    switch_state_changed = 1;
    turnOff();
    dim1 =0;
  }

  else if(s4) { 
    switch_state_down = s4;
    switch_state_changed = 1;
    playSong();
    dim1 =0;
  }
   */
   /*
     switch(state) {   // This is the switch version of the previos if statements for the state of 
                         bottons wich i then changed to assembly
 case 1:
     switch_state_down = s1;
     switch_state_changed = 1;
     buzzer_set_period(1000);
     dim1 = 1;
     state =0;
     break;
 case 2:
     switch_state_down = s2;
     switch_state_changed = 1;
     buzzer_set_period(beat);
     beat = beat + 50;// used to change the beat every time its pressed.
     if (beat >2000){
       beat = 600;
     }
     led_init();
     toggle_red();
     dim1 = 0;
     green_on =1;
     led_update();
     state =0;
     break;

   case 3:
     switch_state_down = s3;
     switch_state_changed = 1;
     turnOff();
     dim1 =0;
     state= 0;
     break;
   case 4:
     switch_state_down = s4;
     switch_state_changed = 1;
     playSong();
     dim1 =0;
     state=0;
     break;
   default:
     break;
   }
   */
}
