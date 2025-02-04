#include <U8g2lib.h>
#include "SSD1315_screen.h"

extern U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2_screen(U8G2_R0, /* reset=*/U8X8_PIN_NONE, /* clock=*/SCL, /* data=*/SDA);

void ssd1315_init()
{
    u8g2_screen.begin();
    u8g2_screen.clearBuffer();
    u8g2_screen.setFont(u8g2_font_6x10_tf);
}