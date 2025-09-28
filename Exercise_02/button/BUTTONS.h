#ifndef BUTTONS_H
#define BUTTONS_H

#include <stdbool.h>

void buttons_init(void);

bool buttons_poll_toggle_auto(void);
bool buttons_poll_manual_water(void);

void buttons_simulate_toggle_auto_press(void);
void buttons_simulate_manual_press(void);

#endif 