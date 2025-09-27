#ifndef TYPES_H
#define TYPES_H


#include <stdbool.h>


// System mode
typedef enum {
MODE_AUTO = 0,
MODE_MANUAL
} system_mode_t;


// Pump state
typedef enum {
PUMP_OFF = 0,
PUMP_ON
} pump_state_t;


// LED states
typedef enum {
LED_NORMAL = 0,
LED_WATERING,
LED_LOW_MOISTURE_ALERT,
LED_ERROR
} led_state_t;


// Sensor data
typedef struct {
int moisture_percent; // 0-100
float temperature_c;
unsigned long last_update_ms;
} sensor_data_t;


// System settings
typedef struct {
int min_moisture;
int max_moisture;
unsigned int max_water_seconds;
unsigned int sensor_interval_seconds;
system_mode_t mode;
} system_config_t;


#endif // TYPES_H