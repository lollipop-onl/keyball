#include QMK_KEYBOARD_H

static const char PROGMEM layer_0_icon[] = {
  // '0', 16x16px
  0xfc, 0x02, 0x01, 0x01, 0x01, 0xf1, 0x09, 0x09,  0x09, 0x09, 0xf1, 0x01, 0x01, 0x01, 0x02, 0xfc, 
  0x3f, 0x40, 0x80, 0x80, 0x80, 0x8f, 0x90, 0x90,  0x90, 0x90, 0x8f, 0x80, 0x80, 0x80, 0x40, 0x3f
};

static const char PROGMEM layer_1_icon[] = {
  // '1', 16x16px
  0xfc, 0xfe, 0x07, 0x03, 0x03, 0x23, 0x33, 0xfb, 0xfb, 0x03, 0x03, 0x03, 0x03, 0x07, 0xfe, 0xfc, 
  0x3f, 0x7f, 0xe0, 0xc0, 0xc0, 0xd0, 0xd0, 0xdf, 0xdf, 0xd0, 0xd0, 0xc0, 0xc0, 0xe0, 0x7f, 0x3f, 
};

static const char PROGMEM layer_2_icon[] = {
  // '2', 16x16px
  0xfc, 0xfe, 0xff, 0xff, 0xc7, 0xc3, 0xf3, 0xf3, 0xf3, 0x73, 0x03, 0x07, 0xff, 0xff, 0xfe, 0xfc, 
  0x3f, 0x7f, 0xff, 0xff, 0xcf, 0xc7, 0xc3, 0xc1, 0xc8, 0xcc, 0xce, 0xcf, 0xff, 0xff, 0x7f, 0x3f, 
};

static const char PROGMEM layer_3_icon[] = {
  // '3', 16x16px
  0xfc, 0xfe, 0xff, 0xff, 0xcf, 0xc7, 0x63, 0x73, 0x73, 0x23, 0x07, 0x8f, 0xff, 0xff, 0xfe, 0xfc, 
  0x3f, 0x7f, 0xff, 0xff, 0xf3, 0xe3, 0xc6, 0xce, 0xce, 0xc4, 0xe0, 0xf1, 0xff, 0xff, 0x7f, 0x3f, 
};

static const char PROGMEM layer_4_icon[] = {
  // '4', 16x16px
  0xfc, 0xfe, 0xff, 0xff, 0x7f, 0x3f, 0x1f, 0x8f, 0xc7, 0x03, 0x03, 0xff, 0xff, 0xff, 0xfe, 0xfc, 
  0x3f, 0x7f, 0xff, 0xf0, 0xf0, 0xf2, 0xf3, 0xf3, 0xf3, 0xc0, 0xc0, 0xf3, 0xf3, 0xff, 0x7f, 0x3f
};

static const char PROGMEM layer_0_0_icon[] = {
  0xfc, 0x02, 0x01, 0x01, 0x01, 0xf1, 0x09, 0x09,
  0x3f, 0x40, 0x80, 0x80, 0x80, 0x8f, 0x90, 0x90,
};

static const char PROGMEM layer_0_1_icon[] = {
  0x09, 0x09, 0xf1, 0x01, 0x01, 0x01, 0x02, 0xfc, 
  0x90, 0x90, 0x8f, 0x80, 0x80, 0x80, 0x40, 0x3f,
};

void keyball_oled_render_layer_icon(void) {
  oled_set_cursor(2, 0);
  oled_write_raw_P(layer_0_0_icon, sizeof(layer_0_0_icon));

  oled_set_cursor(2, 2);
  oled_write_raw_P(layer_0_1_icon, sizeof(layer_0_1_icon));

  // switch (get_highest_layer(layer_state)) {
  //   case 1: oled_write_raw_P(layer_1_icon, sizeof(layer_1_icon)); break;
  //   case 2: oled_write_raw_P(layer_2_icon, sizeof(layer_2_icon)); break;
  //   case 3: oled_write_raw_P(layer_3_icon, sizeof(layer_3_icon)); break;
  //   case 4: oled_write_raw_P(layer_4_icon, sizeof(layer_4_icon)); break;
  //   default: oled_write_raw_P(layer_0_icon, sizeof(layer_0_icon)); break;
  // }
}