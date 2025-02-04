#include <Arduino.h>
#include <board_led.h>

void setup()
{
	board_led_init();
}

void loop()
{
	board_led_on();
	delay(3000);
	board_led_off();
	delay(3000);
}