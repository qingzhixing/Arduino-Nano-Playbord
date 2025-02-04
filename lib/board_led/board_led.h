#pragma once
#ifndef BOARD_LED_H
#define BOARD_LED_H

#define BOARD_LED_PIN 13
#define BOARD_LED_ON_LEVEL HIGH
#define BOARD_LED_OFF_LEVEL LOW

void board_led_init();
void board_led_on();
void board_led_off();
void board_led_toggle();

#endif // !BOARD_LED_H