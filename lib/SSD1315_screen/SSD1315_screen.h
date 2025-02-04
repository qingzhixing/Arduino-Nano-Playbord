#pragma once
#ifndef SSD1315_SCREEN_H
#define SSD1315_SCREEN_H

#define SDA_PIN 18
#define SCL_PIN 19

void ssd1315_init();

extern U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2_screen;

#endif // !SSD1315_SCREEN_H