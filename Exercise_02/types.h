#ifndef TYPES_H
#define TYPES_H

#include <stdbool.h>

typedef enum {
MODE_AUTO = 0,
MODE_MANUAL
} system_mode_t;

typedef enum {
PUMP_OFF = 0,
PUMP_ON
} pump_state_t;

typedef enum {
LED_NORMAL = 0,
LED_WATERING,
LED_LOW_MOISTURE_ALERT,
LED_ERROR
} led_state_t;

typedef struct {
int moisture_percent;
float temperature_c;
unsigned long last_update_ms;
} sensor_data_t;

typedef struct {
int min_moisture;
int max_moisture;
unsigned int max_water_seconds;
unsigned int sensor_interval_seconds;
system_mode_t mode;
} system_config_t;

#endif 