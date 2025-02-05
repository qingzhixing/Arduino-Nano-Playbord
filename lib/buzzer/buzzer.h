#pragma once
#ifndef BUZZER_H
#define BUZZER_H

#include <math.h>
#include <stdint.h>

static const uint8_t BUZZER_PIN = 14;
#define BUZZER_ON_LEVEL HIGH

void buzzer_init();
void buzzer_on();
void buzzer_off();
void buzzer_toggle();
#endif // !BUZZER_H
