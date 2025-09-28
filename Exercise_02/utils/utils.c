#include "utils.h"
#include <time.h>
#include <unistd.h>

unsigned long millis(void) {
struct timespec ts;
clock_gettime(CLOCK_MONOTONIC, &ts);
return (unsigned long)(ts.tv_sec * 1000UL + ts.tv_nsec / 1000000UL);
}

void delay_ms(unsigned int ms) {
usleep(ms * 1000u);
}