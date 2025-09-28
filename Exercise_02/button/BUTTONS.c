#include <stdio.h>
#include "buttons.h"


static int toggle_auto_pending = 0;
static int manual_water_pending = 0;


void buttons_init(void) {
toggle_auto_pending = 0;
manual_water_pending = 0;
printf("[BTN] Buttons initialized (simulation)\n");
}


bool buttons_poll_toggle_auto(void) {
if (toggle_auto_pending) { toggle_auto_pending = 0; printf("[BTN] Toggle-AUTO pressed\n"); return true; }
return false;
}


bool buttons_poll_manual_water(void) {
if (manual_water_pending) { manual_water_pending = 0; printf("[BTN] Manual-WATER pressed\n"); return true; }
return false;
}


void buttons_simulate_toggle_auto_press(void) { toggle_auto_pending = 1; }
void buttons_simulate_manual_press(void) { manual_water_pending = 1; }