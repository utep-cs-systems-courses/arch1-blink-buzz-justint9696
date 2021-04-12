#include <msp430.h>

#include "led.h"
#include "button.h"
#include "buzzer.h"
#include "timerLib/libTimer.h"

int main(void) {
  configureClocks();
  
  init_led();
  init_button();
  init_buzzer();

  enableWDTInterrupts();
  
  or_sr(0x18);
  
  return 1;
}
