#include <board_led.h>
#include <Arduino.h>

void board_led_init()
{
    pinMode(BOARD_LED_PIN, OUTPUT);
    board_led_off();
}
void board_led_on()
{
    digitalWrite(BOARD_LED_PIN, BOARD_LED_ON_LEVEL);
}
void board_led_off()
{
    digitalWrite(BOARD_LED_PIN, BOARD_LED_OFF_LEVEL);
}
void board_led_toggle()
{
    digitalWrite(BOARD_LED_PIN, !digitalRead(BOARD_LED_PIN));
}