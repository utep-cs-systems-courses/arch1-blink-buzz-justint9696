#include <msp430.h>

#include "buzzer.h"
#include "timerLib/libTimer.h"

void init_buzzer() {
  timerAUpmode();
  P2SEL2 &= ~(BIT6 | BIT7);
  P2SEL &= ~BIT7;
  P2SEL |= BIT6;
  P2DIR = BIT6;
}

void set_buzzer(short cycles) {
  CCR0 = cycles;
  CCR1 = cycles >> 1;
}
