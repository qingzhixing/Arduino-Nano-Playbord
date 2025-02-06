#pragma once
#ifndef SPEAKER_H
#define SPEAKER_H

#include <stdint.h>

const int16_t SPEAKER_MAX_VOLUME = 255;
#define SPEAKER_FREQ_MAX 8000
#define SPEAKER_FREQ_MIN 50
#define SPEAKER_PIN 6

void speaker_init();
void speaker_on();
void speaker_off();
void speaker_toggle();
bool speaker_is_on();
void speaker_set_frequency(int32_t frequency);
int32_t speaker_get_frequency();
void speaker_set_volume(int16_t volume);
int16_t speaker_get_volume();

#endif // !SPEAKER_H