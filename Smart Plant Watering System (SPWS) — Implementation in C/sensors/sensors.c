#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sensors.h"


static int simulated_moisture = -1; // if -1 then random walk
static int seeded = 0;


void sensors_init(void) {
if (!seeded) { srand((unsigned)time(NULL)); seeded = 1; }
printf("[SENSORS] Initialized. (simulated)\n");
}


// Simple simulated reading: random walk or forced value
void sensors_read(sensor_data_t *data) {
if (!data) return;
if (simulated_moisture >= 0) {
data->moisture_percent = simulated_moisture;
} else {
static int cur = 50; // start 50%
int step = (rand() % 7) - 3; // -3..+3
cur += step;
if (cur < 0) cur = 0;
if (cur > 100) cur = 100;
data->moisture_percent = cur;
}
// temperature simulated
data->temperature_c = 20.0f + (rand() % 150) / 10.0f; // 20.0 .. 35.0
data->last_update_ms = 0;
printf("[SENSORS] Read: moisture=%d%%, temp=%.1f C\n", data->moisture_percent, data->temperature_c);
}


void sensors_set_simulated_moisture(int m) {
if (m < 0) simulated_moisture = -1;
else if (m > 100) simulated_moisture = 100;
else simulated_moisture = m;
}