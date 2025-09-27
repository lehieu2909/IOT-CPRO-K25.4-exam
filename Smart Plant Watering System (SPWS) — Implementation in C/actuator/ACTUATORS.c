#include <stdio.h>
#include "actuators.h"


static pump_state_t pump_state = PUMP_OFF;
static led_state_t led_state = LED_NORMAL;


void actuators_init(void) {
pump_state = PUMP_OFF;
led_state = LED_NORMAL;
printf("[ACT] Actuators initialized (pump OFF, LED NORMAL)\n");
}


void turn_pump_on(void) {
if (pump_state == PUMP_ON) return;
pump_state = PUMP_ON;
printf("[ACT] PUMP -> ON\n");
}


void turn_pump_off(void) {
if (pump_state == PUMP_OFF) return;
pump_state = PUMP_OFF;
printf("[ACT] PUMP -> OFF\n");
}


void set_led_state(led_state_t s) {
if (led_state == s) return;
led_state = s;
const char *name = "?";
switch (s) {
case LED_NORMAL: name = "NORMAL (GREEN)"; break;
case LED_WATERING: name = "WATERING (YELLOW)"; break;
case LED_LOW_MOISTURE_ALERT: name = "LOW_MOISTURE_ALERT (ORANGE)"; break;
case LED_ERROR: name = "ERROR (RED)"; break;
}
printf("[ACT] LED -> %s\n", name);
}


pump_state_t get_pump_state(void) { return pump_state; }
led_state_t get_led_state(void) { return led_state; }