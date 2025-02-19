#include <Arduino.h>
#include <U8g2lib.h>
#include "board_led.h"
#include "SSD1315_screen.h"
#include "encoder.h"
#include "buzzer.h"
#include "speaker.h"

bool need_update_screen = false;

void setup()
{
	board_led_init();
	ssd1315_init();
	Serial.begin(9600);
	encoder_init();

	Serial.println("Hello World!");
	need_update_screen = true;
	buzzer_init();
	speaker_init();

	on_encoder_key_pressed([]()
						   { 
								Serial.println("Key pressed!"); 
								speaker_toggle(); 
								Serial.printf("Speaker on state: %s\n", speaker_is_on() ? "ON" : "OFF"); });
	on_encoder_turned([](bool direction)
					  {
							if (direction)
							{
								Serial.println("Clockwise!");
								speaker_set_frequency(speaker_get_frequency() + 50);
							}
							else
							{
								Serial.println("Counterclockwise!");
								speaker_set_frequency(speaker_get_frequency() - 50);
							} });
	on_encoder_key_released([]()
							{ Serial.println("Key released!"); });
}

void loop()
{
	board_led_off();
	encoder_update();

	if (need_update_screen)
	{
		need_update_screen = false;
		u8g2_screen.clearBuffer();
		u8g2_screen.drawStr(0, 10, "Hello World!");
		u8g2_screen.sendBuffer();
	}

	board_led_on();
}