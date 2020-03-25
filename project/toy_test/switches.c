#include <msp430.h>
#include "switches.h"

#include "led.h"
#include "buzzer.h"
#include "stateMachine.h"

char switch_state_down, switch_state_changed, s1, s2, s3, s4; /* effectively boolean */
//global char dim = 0;

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

  P2IE = SWITCHES;/* enable interrupts from switches */

  P2OUT |= SWITCHES;/* pull-ups for switches */

  P2DIR &= ~SWITCHES;/* set switches' bits for input */

  switch_update_interrupt_sense();

  led_update();

}



void

switch_interrupt_handler()

{

  char p1val = switch_update_interrupt_sense();
  // sets up values for the switches to check if pressed then te if statements check and carry out an action depending the button pressed more in README.md
  s1 = (p1val & SW1) ? 0 : 1;
  s2 = (p1val & SW2) ? 0 : 1;
  s3 = (p1val & SW3) ? 0 : 1;
  s4 = (p1val & SW4) ? 0 : 1;
  if (s1){
    switch_state_down = s1;
    switch_state_changed = 1;
    buzzer_set_period(1000);
    dim1 = 1;
  }

  else if(s2){
      switch_state_down = s2;
      switch_state_changed = 1;
      buzzer_set_period(1200);
      led_init();
      toggle_red();
      led_update();
      dim1 = 0;
      green_on =1;

  }
  else if(s3){
    switch_state_down = s3;
    switch_state_changed = 1;
    turnOff();
    dim1 =0;
  }

  else if(s4){
    switch_state_down = s4;
    switch_state_changed = 1;
    playSong();
    dim1 =0;
  }

}