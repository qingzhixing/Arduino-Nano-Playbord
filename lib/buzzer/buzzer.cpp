#include <Arduino.h>
#include "buzzer.h"

void buzzer_init()
{
    pinMode(BUZZER_PIN, OUTPUT);
    buzzer_off();
}
void buzzer_on()
{
    digitalWrite(BUZZER_PIN, BUZZER_ON_LEVEL);
}
void buzzer_off()
{
    digitalWrite(BUZZER_PIN, !BUZZER_ON_LEVEL);
}
void buzzer_toggle()
{
    digitalWrite(BUZZER_PIN, !digitalRead(BUZZER_PIN));
}
