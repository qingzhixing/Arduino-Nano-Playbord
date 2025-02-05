#include <Arduino.h>
#include "buzzer.h"

static bool buzzer_state = false;
static int32_t buzzer_value = BUZZER_PWM_RANGE - 1;

void buzzer_init()
{
    pinMode(BUZZER_PIN, OUTPUT);
    // analogWriteResolution(BUZZER_PWM_RESOLUTION);
    buzzer_off();
}
void buzzer_on()
{
    buzzer_state = true;
}
void buzzer_off()
{
    buzzer_state = false;
}
void buzzer_toggle()
{
    buzzer_state = !buzzer_state;
}
void buzzer_loop()
{
    if (buzzer_state)
    {
        analogWrite(BUZZER_PIN, buzzer_value);
    }
    else
    {
        digitalWrite(BUZZER_PIN, BUZZER_OFF_LEVEL);
    }
}
void buzzer_set_value(int32_t value)
{
    buzzer_value = max(0, min(BUZZER_PWM_RANGE - 1, value));
}

int32_t buzzer_get_value()
{
    return buzzer_value;
}

void buzzer_value_add(int32_t value)
{
    buzzer_set_value(buzzer_value + value);
}