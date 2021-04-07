#include <msp430.h>

#include "led.h"
#include "button.h"

int main(void) {
  init_led();
  init_button();
  return 1;
}
