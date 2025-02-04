#include <Arduino.h>
#include <U8g2lib.h>
#include "board_led.h"
#include "SSD1315_screen.h"
#include "encoder.h"

static U8G2 u8g2;

void setup()
{
	board_led_init();
	ssd1315_init();
	encoder_init();
	u8g2 = get_u8g2();
	// Serial.begin(9600);
}

void loop()
{
	encoder_update();

	u8g2.clearBuffer();
	u8g2.drawStr(0, 10, "Hello World!");
	u8g2.sendBuffer();

	board_led_on();
	delay(200);
	board_led_off();
	delay(200);
}