#ifndef SENSORS_H
#define SENSORS_H

#include "types.h"

void sensors_init(void);
void sensors_read(sensor_data_t *data);

void sensors_set_simulated_moisture(int m);

#endif 