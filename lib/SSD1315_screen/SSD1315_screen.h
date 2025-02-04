#pragma once
#ifndef SSD1315_SCREEN_H
#define SSD1315_SCREEN_H

#define SDA_PIN 18
#define SCL_PIN 19

void ssd1315_init();

U8G2 get_u8g2();

#endif // !SSD1315_SCREEN_H