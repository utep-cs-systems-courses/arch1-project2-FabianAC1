#include <msp430.h>

#include "switches.h"

// used the file provided by the demo labs changed the 1 to a 2 so that it would work with the 4 required bottons

/* Switch on P1 (S2) */

void

__interrupt_vec(PORT2_VECTOR) Port_2(){

  if (P2IFG & SWITCHES) {      /* did a button cause this interrupt? */

    P2IFG &= ~SWITCHES;      /* clear pending sw interrupts */

    switch_interrupt_handler();/* single handler for all switches */

  }

}
