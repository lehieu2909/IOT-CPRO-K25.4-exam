#ifndef WATERING_LOGIC_H
#define WATERING_LOGIC_H


#include "types.h"


void watering_init(system_config_t *cfg, sensor_data_t *sdata);
void watering_task_cycle(void); // run one cycle: check sensors, control pump


// functions for manual trigger
void watering_manual_trigger(unsigned int seconds);


// external for testing
extern system_config_t g_config;
extern sensor_data_t g_sensor_data;


#endif // WATERING_LOGIC_H