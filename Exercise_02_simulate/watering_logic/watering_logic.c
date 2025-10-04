#include "watering_logic.h"
#include "sensors.h"
#include "actuators.h"
#include "config.h"
#include <stdio.h>
#include <string.h>

// trạng thái nội bộ
static unsigned long last_sensor_check_ms = 0;
static unsigned long pump_start_ms = 0;
static unsigned int watering_remaining_seconds = 0; // cho manual mode

extern Config g_config;
extern SensorData g_sensor_data;

void watering_logic_init(void) {
    last_sensor_check_ms = 0;
    pump_start_ms = 0;
    watering_remaining_seconds = 0;
    stop_watering();
    set_led_state(LED_OFF);
}

void start_watering_manual(unsigned int seconds) {
    watering_remaining_seconds = seconds;
    pump_start_ms = millis();
    set_pump_state(PUMP_ON);
    printf("[WL] Manual watering start for %u seconds\n", seconds);
}

void start_watering_auto(void) {
    watering_remaining_seconds = 0; // no fixed duration
    pump_start_ms = millis();
    set_pump_state(PUMP_ON);
    printf("[WL] Auto watering start\n");
}

void stop_watering(void) {
    set_pump_state(PUMP_OFF);
    watering_remaining_seconds = 0;
    printf("[WL] Watering stopped\n");
}

void watering_task_cycle(void) {
    unsigned long now = millis();

    // 1) Đọc sensor theo chu kỳ
    if (now - last_sensor_check_ms >= (unsigned long)g_config.sensor_interval_seconds * 1000UL) {
        sensors_read(&g_sensor_data);
        last_sensor_check_ms = now;
    }

    // 2) Nếu ở AUTO mode thì quyết định
    if (g_config.mode == MODE_AUTO) {
        if (get_pump_state() == PUMP_OFF) {
            if (g_sensor_data.moisture_percent < g_config.min_moisture) {
                printf("[WL] Auto: moisture %d < min %d -> schedule watering\n",
                       g_sensor_data.moisture_percent, g_config.min_moisture);
                start_watering_auto();
            }
        } else {
            // pump đang bật: dừng khi đạt max_moisture hoặc hết thời gian
            if (g_sensor_data.moisture_percent >= g_config.max_moisture) {
                printf("[WL] Auto: moisture %d >= max %d -> stop watering\n",
                       g_sensor_data.moisture_percent, g_config.max_moisture);
                stop_watering();
            } else {
                if (now - pump_start_ms >= (unsigned long)g_config.max_water_seconds * 1000UL) {
                    printf("[WL] Auto: reached max watering time %u sec -> stop\n",
                           g_config.max_water_seconds);
                    stop_watering();
                }
            }
        }
    }

    // 3) Nếu manual thì đếm ngược thời gian
    if (get_pump_state() == PUMP_ON && watering_remaining_seconds > 0) {
        unsigned long elapsed = (now - pump_start_ms) / 1000UL;
        if (elapsed >= watering_remaining_seconds) {
            stop_watering();
        }
    }

    // 4) Quyết định LED báo trạng thái
    if (get_pump_state() == PUMP_ON) {
        set_led_state(LED_WATERING);
    } else {
        if (g_sensor_data.moisture_percent < g_config.min_moisture)
            set_led_state(LED_LOW_MOISTURE_ALERT);
        else
            set_led_state(LED_NORMAL);
    }

    // 5) Báo cáo trạng thái định kỳ
    static unsigned long last_report_ms = 0;
    if (now - last_report_ms >= 10000UL) { // mỗi 10 giây
        printf("[REPORT] Mode=%s | Moisture=%d%% | Temp=%.1fC | Pump=%s\n",
               g_config.mode == MODE_AUTO ? "AUTO" : "MANUAL",
               g_sensor_data.moisture_percent,
               g_sensor_data.temperature_c,
               get_pump_state() == PUMP_ON ? "ON" : "OFF");
        last_report_ms = now;
    }
}
