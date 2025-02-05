#pragma once
#ifndef BUZZER_H
#define BUZZER_H

#include <math.h>
#include <stdint.h>

static const uint8_t BUZZER_PWM_RESOLUTION = 8;                         // bits
static const uint16_t BUZZER_PWM_RANGE = pow(2, BUZZER_PWM_RESOLUTION); // [0, 2^PWM_RESOLUTION-1]
static const uint8_t BUZZER_PIN = 6;
#define BUZZER_OFF_LEVEL HIGH

void buzzer_init();
void buzzer_on();
void buzzer_off();
void buzzer_toggle();
void buzzer_loop();
void buzzer_set_value(int32_t value);
int32_t buzzer_get_value();
void buzzer_value_add(int32_t value);
#endif // !BUZZER_H
