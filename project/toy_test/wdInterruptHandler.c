#include <msp430.h>
#include "stateMachine.h"
// used the wdInterupt from the demo labs and modefied it
void
__interrupt_vec(WDT_VECTOR) WDT(){
  static char blink_count = 0;
  if (++blink_count == 1  && dim1) {  // changed to 1 to simulate a dim and boolean dim1 to only be done when switch one is turned on
    state_advance1();
    blink_count = 0;
  }
}
