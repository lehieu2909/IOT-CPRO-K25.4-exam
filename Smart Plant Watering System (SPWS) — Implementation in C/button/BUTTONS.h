#ifndef BUTTONS_H
#define BUTTONS_H


#include <stdbool.h>


void buttons_init(void);


// poll buttons (simulation)
// returns true if toggle auto button pressed
// returns true in second arg if manual water button pressed
bool buttons_poll_toggle_auto(void);
bool buttons_poll_manual_water(void);


// helper to simulate button press in tests
void buttons_simulate_toggle_auto_press(void);
void buttons_simulate_manual_press(void);


#endif // BUTTONS_H