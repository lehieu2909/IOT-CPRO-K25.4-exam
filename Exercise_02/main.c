#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "config.h"
#include "sensors.h"
#include "actuators.h"
#include "watering_logic.h"
#include "utils.h"

Config g_config;
SensorData g_sensor_data;

int main(void) {
    srand((unsigned int)time(NULL));

    g_config.mode = MODE_AUTO;
    g_config.min_moisture = 30;
    g_config.max_moisture = 70;
    g_config.max_water_seconds = 15;
    g_config.sensor_interval_seconds = 5;

    utils_init();
    actuators_init();
    sensors_init();
    watering_logic_init();

    printf("[MAIN] Smart Plant Watering System started.\n");

    while (1) {
        watering_task_cycle();
        utils_delay_ms(100); 
    }

    return 0;
}
