#include QMK_KEYBOARD_H

void keyball_oled_render_fuku(void) {
  static const char PROGMEM fuku_logo_1[] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x80, 0x80, 0x40, 0x40,
    0x40, 0x20, 0x20, 0x20, 0x20, 0x20, 
    0x20, 0x20, 0x40, 0x40, 0x40, 0x80, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0xe0, 0x50, 0x50, 0x20, 
    0xf0, 0xc8, 0xc6, 0x81, 0x80, 0x80, 
    0x80, 0x80, 0x00, 0x28, 0x68, 0xc8, 
    0x88, 0x48, 0x00, 0x80, 0xc0, 0xc0, 
    0x80, 0x00, 0x35, 0x66, 0x44, 0xac, 
    0xf4, 0x80, 0x80, 0x00, 0x03, 0x05, 
    0x05, 0x02, 0x07, 0x1f, 0x7f, 0xf9, 
    0xf6, 0xf6, 0xee, 0xee, 0xf5, 0xff, 
    0xfe, 0xfe, 0xfe, 0xff, 0xfc, 0xfb, 
  };

  static const char PROGMEM fuku_logo_2[] = {
    0xf7, 0xf6, 0xfb, 0xfc, 0xff, 0xff, 
    0x7f, 0x1f, 0x07, 0x04, 0x02, 0x01, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x01, 0x03, 0x03, 0x07, 
    0x07, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 
    0x0f, 0x0f, 0x07, 0x07, 0x03, 0x03, 
    0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00
  };

  oled_write_raw_P(fuku_logo_1, sizeof(fuku_logo_1));
  oled_set_cursor(0, 1);
  oled_write_raw_P(fuku_logo_2, sizeof(fuku_logo_2));
  oled_set_cursor(0, 2);
  oled_write_P(PSTR("FUKU"), false);
}
