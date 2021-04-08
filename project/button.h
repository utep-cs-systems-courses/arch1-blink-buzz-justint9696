#ifndef _BUTTON_
#define _BUTTON

#define BUTTON BIT3 // P1.3 on board

void init_button();

static char button_handler();

void monitor_button();

#endif
