/*
Copyright 2021 @Yowkees
Copyright 2021 MURAOKA Taro (aka KoRoN, @kaoriya)

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "quantum.h"

#if defined(OLED_ENABLE) && !defined(OLEDKIT_DISABLE)

// __attribute__((weak)) void oledkit_render_logo_user(void) {
//     // Require `OLED_FONT_H "keyboards/keyball/lib/logofont/logofont.c"`
//     char ch = 0x80;
//     for (int y = 0; y < 3; y++) {
//         oled_write_P(PSTR("  "), false);
//         for (int x = 0; x < 16; x++) {
//             oled_write_char(ch++, false);
//         }
//         oled_advance_page(false);
//     }
// }

static const char PROGRAM logo_1[] = {
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xf8, 0x0f, 0xff,
    0xff, 0xc0, 0x01, 0xff, 0xff, 0x00,
    0x00, 0xff, 0xfe, 0x00, 0x00, 0x7f,
    0xfc, 0x00, 0x00, 0x0f, 0xfc, 0x00,
    0x00, 0xf7, 0xf8, 0x07, 0xc0, 0x0f, 
    0x90, 0x00, 0x00, 0x8f, 0x60, 0x06, 
    0x00, 0xd7, 0x16, 0x03, 0x4c, 0x67, 
    0x77, 0xf1, 0x9e, 0x11, 0x17, 0x0c, 
    0x5a, 0xf6, 0x66, 0xf7, 0xde, 0xf5, 
    0x96, 0xff, 0xed, 0xf3, 0xfb, 0x37, 
    0xf3, 0xef, 0xfb, 0xcf, 0xff, 0xef
}
static const char PROGRAM logo_2[] = {
    0xfd, 0xff, 0xff, 0xdf, 0xfd, 0xff,
    0xff, 0xdf, 0xfe, 0xff, 0xff, 0xbf, 
    0xff, 0x7f, 0xff, 0x7f, 0xff, 0x9f, 
    0xfc, 0xff, 0xff, 0xe7, 0xf3, 0xff, 
    0xff, 0xf8, 0x0f, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff
}

void oledkit_render_logo_user(void) {
    oled_write_raw_P(logo_1, sizeof(logo_1));
    oled_set_cursor(0, 1);
    oled_write_raw_P(logo_2, sizeof(logo_2));
    oled_set_cursor(0, 2);
}

__attribute__((weak)) void oledkit_render_info_user(void) {
    oledkit_render_logo_user();
}

__attribute__((weak)) bool oled_task_user(void) {
    if (is_keyboard_master()) {
        oledkit_render_info_user();
    } else {
        oledkit_render_logo_user();
    }
    return true;
}

__attribute__((weak)) oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    // Logo needs to be rotated 180 degrees.
    //
    // A typical OLED has a narrow margin on the left side near the origin, and
    // a wide margin on the right side. The Keyball logo consists of three
    // lines. If the logo is displayed on an OLED consisting of four lines, the
    // margin on the right side will be too large and the balance is not good.
    //
    // Additionally, by rotating it, the left side of the logo will be above
    // the OLED screen, giving it a natural look.
    return !is_keyboard_master() ? OLED_ROTATION_180 : rotation;
}

#endif // OLED_ENABLE
