#include <Arduino.h>
#include <U8g2lib.h>
#include <SPI.h>

#define OLED_DC 1
#define OLED_CS 7
#define OLED_RST 2

U8G2_SSD1309_128X64_NONAME2_F_4W_HW_SPI u8g2(/* rotation=*/U8G2_R0, /* cs=*/ OLED_CS, /* dc=*/ OLED_DC,/* reset=*/OLED_RST);


void setup(void) {
  u8g2.begin();
  u8g2.setFontPosTop();
  pinMode(3, INPUT);
}

void loop(void) {

  u8g2.clearBuffer();          // clear the internal memory
  u8g2.setFont(u8g2_font_t0_11b_tr);  // choose a suitable font
  u8g2.drawStr(0, 5, "Hi!"); // write something to the internal memory
  String s = "s";
  s = (int)(millis() / 1000) + s;
  u8g2.drawStr(20, 5, s.c_str()); // write something to the internal memory

  String b = "pin3:";
  b += (int)analogRead(3);
  u8g2.drawStr(0, 30, b.c_str()); // write something to the internal memory

  u8g2.sendBuffer();
  delay(50);
}
