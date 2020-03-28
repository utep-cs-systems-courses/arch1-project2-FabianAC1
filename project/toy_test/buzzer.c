#include <msp430.h>

#include "libTimer.h"

#include "buzzer.h"
#include "stateMachine.h"


void buzzer_init()

{


  timerAUpmode();

  P2SEL2 &= ~(BIT6 | BIT7);

  P2SEL &= ~BIT7;

  P2SEL |= BIT6;

  P2DIR = BIT6;

}



void buzzer_set_period(short cycles) /* buzzer clock = 2MHz.  (period of 1k results in 2kHz tone) */

{

  CCR0 = cycles;

  CCR1 = cycles >> 1;/* one half cycle */

}


void playSong(){
  // Songs include mario theme song, never gonna give you up and the office theme song wich i used.
  // int song[] =  {837,887,1054,887,837,837,837,837,887,1054,887,837,837,837,0};
  // int song2[] = {1055,0,996,0,558,0,996,0,558,0,704,0,627,0,790,0,790,0,790,0,837,0,939,0,837,0,                    1055,0,996,0,558,0,996,0,887,0,558,0,627,0,704,0,627,0,704,0,837,0,790,0,790,0,                    790,0,837,0,939,0,837,0,1055,0,996,0,558,0,996,0,558,0,704,0,627,0};
  // int song1[] = {837,837,837,1054,837,704,704,837,627,558,592,627,704,837,704,627,790,704,837,10                   54,939,558,0};
  // int song3[] = {587,392,587,0,587,392,587,349,587,0};
  int song4[] =   {1703,2551,1703,0,0,1703,2551,1703,2863,1703,0,1703,2863,1517,2551,1517,0,1517,
		   2551,1910,0,1910,0,1910,2025,2273,2025,2551,0,2551,0,0,0,
		   1432,1276,1432,1703,1517,0,0,0,1910,0,1910,0,1910,2025,2273,
		   2025,2551,0};
   // int song5[]  {1910,0,1910,1703,1432,0,1432,0,1432,0,1276,0,1910,1276,0,1136,0,955,1136,0,113                     6,1432,0,1276,0,1910,0,0,0,1910,0,1910,1703,1432,0,1432,1703,1517,1432,0,1432,                     1276,1517,1703,1910,0,0,1703,0,1703,1517,1432,1703,1910,955,0,955,0,1276,0,0,1                     703,0,1703,1517,1432,1703,1432,1276,1517,1703,1910,0,0,0,1703,0,1703,1517,1432                     ,0};
  buzzer_init();
  for(int i=0; i <51;i++) {
    buzzer_set_period(song4[i]);
    state_advance();// makes the lights move with the song
    for(int o=0; o<11;o++) {
      for(int j=0; j<30000;j++) {     // this double foor loop used to simulate time between notes
      }

    }

  } 
    
}










