/*******************************************************************************
 * Code
 ******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h> /* For sleep() on POSIX. Replace for embedded RTOS if needed. */

#include "config.h"
#include "spws_controller.h"

/*******************************************************************************
 * Prototypes
 ******************************************************************************/

/* Helper: simulate 1-second tick */
static void s_DelayOneSecond(void);

/*******************************************************************************
 * Variables
 ******************************************************************************/

/* Global system state declared in spws_controller.c (definition) is used.
 * We reference it here as extern to avoid multiple definitions.
 */
extern SystemState_t g_SystemState;

/*******************************************************************************
 * Code
 ******************************************************************************/

int main(void)
{
    /* Initialize system state */
    System_Init(&g_SystemState);

    /* Main loop: 1-second tick */
    while (1) {
        /* Simulate passing of one second */
        s_DelayOneSecond();

        /* Update elapsed counters used by controller */
        g_SystemState.sensorElapsed_s += 1U;
        if (g_SystemState.pumpState == PUMP_ON) {
            g_SystemState.wateringTimeElapsed_s += 1U;
        }

        /* Run controller logic once per second */
        SPWS_Run(&g_SystemState);

        /* In embedded code, any housekeeping or low-power could be done here */
    }

    return 0;
}

/* Simple 1-second wait - for simulation on POSIX systems */
static void s_DelayOneSecond(void)
{
    sleep(1);
}
