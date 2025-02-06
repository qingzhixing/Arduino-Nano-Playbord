#include "speaker.h"
#include <Arduino.h>

static int32_t current_frequency = SPEAKER_FREQ_MIN;
static int16_t current_volume = SPEAKER_MAX_VOLUME;
static bool is_on = false;

void speaker_init()
{
    pinMode(SPEAKER_PIN, OUTPUT);
    analogWrite(SPEAKER_PIN, current_volume);
    speaker_off();
}

void speaker_on()
{
    analogWrite(SPEAKER_PIN, current_volume);
    tone(SPEAKER_PIN, current_frequency);
    is_on = true;
}

void speaker_off()
{
    analogWrite(SPEAKER_PIN, 0);
    noTone(SPEAKER_PIN);
    is_on = false;
}

void speaker_toggle()
{
    if (is_on)
    {
        speaker_off();
    }
    else
    {
        speaker_on();
    }
}

bool speaker_is_on()
{
    return is_on;
}

void speaker_set_frequency(int32_t frequency)
{
    current_frequency = max(SPEAKER_FREQ_MIN, min(frequency, SPEAKER_FREQ_MAX));
    if (is_on)
    {
        tone(SPEAKER_PIN, current_frequency);
    }
}

int32_t speaker_get_frequency()
{
    return current_frequency;
}

void speaker_set_volume(int16_t volume)
{
    current_volume = max(0, min(volume, SPEAKER_MAX_VOLUME));
    analogWrite(SPEAKER_PIN, current_volume);
}

int16_t speaker_get_volume()
{
    return current_volume;
}