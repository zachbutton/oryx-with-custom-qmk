#include QMK_KEYBOARD_H
#include "version.h"
#define MOON_LED_LEVEL LED_LEVEL
#ifndef ZSA_SAFE_RANGE
#define ZSA_SAFE_RANGE SAFE_RANGE
#endif

enum custom_keycodes {
  RGB_SLD = ZSA_SAFE_RANGE,
  DRAG_SCROLL,
  TOGGLE_SCROLL,
  NAVIGATOR_INC_CPI,
  NAVIGATOR_DEC_CPI,
  NAVIGATOR_TURBO,
  NAVIGATOR_AIM
};

const custom_shift_key_t custom_shift_keys[] = {
  {KC_DOT , KC_EXLM}, // shift . is !
  {KC_COMM, KC_QUES}, // shift , is ?
					  
  {KC_EQL, KC_EQL }, // shift = is =
  {KC_COLN, KC_SCLN}, // shift : is ; 
  
  {KC_LABK,	KC_LBRC}, // shift < is [
  {KC_RABK,	KC_RBRC}, // shift > is ]

  {KC_LPRN, KC_LCBR}, // shift ( is {
  {KC_RPRN, KC_RCBR}, // shift ) is }

  {KC_MINS, KC_PLUS}, // shift - is +
  {KC_SLSH, KC_ASTR}, // shift / is *
  {KC_PERC, KC_CIRC}, // shift % is ^

  {KC_AMPR, KC_AMPR}, // shift & is &
  {KC_PIPE, KC_PIPE}, // shift | is |

  {KC_GRV,  KC_GRV} // shift ` is `
};



#define DUAL_FUNC_0 LT(4, KC_Z)
#define DUAL_FUNC_1 LT(14, KC_F11)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_voyager(
    KC_AT,          KC_QUOTE,       KC_COMMA,       KC_DOT,         KC_P,           KC_Y,                                           KC_F,           KC_G,           KC_C,           KC_R,           KC_L,           KC_SLASH,       
    KC_GRAVE,       KC_A,           MT(MOD_LALT, KC_O),MT(MOD_LGUI, KC_E),MT(MOD_LCTL, KC_U),KC_I,                                           KC_D,           MT(MOD_RCTL, KC_H),MT(MOD_RGUI, KC_T),MT(MOD_RALT, KC_N),KC_S,           KC_MINUS,       
    KC_TRANSPARENT, KC_SCLN,        KC_Q,           KC_J,           KC_K,           KC_X,                                           KC_B,           KC_M,           KC_W,           KC_V,           KC_Z,           KC_PERC,        
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TILD,        KC_TRANSPARENT, KC_TRANSPARENT, LALT(LCTL(KC_LEFT_GUI)),                                RALT(RCTL(KC_RIGHT_GUI)),KC_TRANSPARENT, KC_TRANSPARENT, KC_UNDS,        KC_TRANSPARENT, OSL(3),         
                                                    MT(MOD_LSFT, KC_ENTER),LT(1, KC_TAB),                                  LT(2, KC_BSPC), MT(MOD_RSFT, KC_SPACE)
  ),
  [1] = LAYOUT_voyager(
    KC_AT,          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_QUES,        KC_DLR,                                         KC_HASH,        KC_7,           KC_8,           KC_9,           KC_ASTR,        KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_BSLS,        KC_LABK,        KC_RABK,        KC_EQUAL,       KC_PIPE,                                        KC_LPRN,        KC_4,           KC_5,           KC_6,           KC_PLUS,        KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_EXLM,        KC_LBRC,        KC_RBRC,        KC_AMPR,                                        KC_RPRN,        KC_1,           KC_2,           KC_3,           KC_CIRC,        KC_TRANSPARENT, 
    TO(0),          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_DOT,         KC_0,           KC_EQUAL,       KC_TRANSPARENT, TO(0),          
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [2] = LAYOUT_voyager(
    KC_NO,          KC_NO,          KC_MS_BTN4,     KC_MS_BTN3,     KC_MS_BTN5,     NAVIGATOR_INC_CPI,                                KC_PAGE_UP,     KC_HOME,        KC_UP,          KC_END,         KC_NO,          QK_BOOT,        
    KC_NO,          KC_NO,          KC_MS_BTN2,     DRAG_SCROLL,    KC_MS_BTN1,     NAVIGATOR_TURBO,                                KC_PGDN,        KC_LEFT,        KC_DOWN,        KC_RIGHT,       KC_NO,          KC_NO,          
    KC_NO,          KC_NO,          KC_NO,          TOGGLE_SCROLL,  KC_NO,          NAVIGATOR_DEC_CPI,                                KC_TRANSPARENT, KC_MEDIA_PREV_TRACK,KC_MEDIA_PLAY_PAUSE,KC_MEDIA_NEXT_TRACK,KC_NO,          KC_TRANSPARENT, 
    KC_TRANSPARENT, TOGGLE_LAYER_COLOR,RGB_MODE_FORWARD,RGB_SLD,        RGB_VAD,        RGB_VAI,                                        KC_TRANSPARENT, KC_AUDIO_MUTE,  KC_AUDIO_VOL_DOWN,KC_AUDIO_VOL_UP,KC_TRANSPARENT, KC_MS_JIGGLER_TOGGLE,
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [3] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_F11,         
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_F4,          KC_F5,          KC_F6,          KC_TRANSPARENT, KC_F12,         
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_F1,          KC_F2,          KC_F3,          KC_TRANSPARENT, KC_ENTER,       
    DUAL_FUNC_0,    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, TO(0),          KC_TRANSPARENT, KC_TRANSPARENT, DUAL_FUNC_1,    
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
};

const char chordal_hold_layout[MATRIX_ROWS][MATRIX_COLS] PROGMEM = LAYOUT(
  'L', 'L', 'L', 'L', 'L', 'L', 'R', 'R', 'R', 'R', 'R', 'R', 
  'L', 'L', 'L', 'L', 'L', 'L', 'R', 'R', 'R', 'R', 'R', 'R', 
  'L', 'L', 'L', 'L', 'L', 'L', 'R', 'R', 'R', 'R', 'R', 'R', 
  'L', 'L', 'L', 'L', 'L', 'L', 'R', 'R', 'R', 'R', 'R', 'R', 
  '*', '*', '*', '*'
);

const uint16_t PROGMEM combo0[] = { LT(1, KC_TAB), LT(2, KC_BSPC), COMBO_END};
const uint16_t PROGMEM combo1[] = { MT(MOD_LSFT, KC_ENTER), MT(MOD_RSFT, KC_SPACE), COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    COMBO(combo0, KC_ESCAPE),
    COMBO(combo1, KC_COLN),
};



extern rgb_config_t rgb_matrix_config;

RGB hsv_to_rgb_with_value(HSV hsv) {
  RGB rgb = hsv_to_rgb( hsv );
  float f = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
  return (RGB){ f * rgb.r, f * rgb.g, f * rgb.b };
}

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}

const uint8_t PROGMEM ledmap[][RGB_MATRIX_LED_COUNT][3] = {
    [0] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,218,204}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    [1] = { {163,218,204}, {200,218,204}, {163,218,204}, {163,218,204}, {86,218,204}, {163,218,204}, {200,218,204}, {163,218,204}, {86,218,204}, {86,218,204}, {86,218,204}, {43,218,204}, {86,218,204}, {200,218,204}, {86,218,204}, {0,218,204}, {0,218,204}, {43,218,204}, {0,0,0}, {0,218,204}, {163,218,204}, {163,218,204}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {163,218,204}, {0,0,255}, {0,0,255}, {0,0,255}, {200,218,204}, {200,218,204}, {0,218,204}, {0,0,255}, {0,0,255}, {0,0,255}, {200,218,204}, {200,218,204}, {0,218,204}, {0,0,255}, {0,0,255}, {0,0,255}, {200,218,204}, {200,218,204}, {0,0,0}, {163,218,204}, {0,0,255}, {86,218,204}, {28,218,204}, {0,0,0}, {0,0,0}, {0,0,0} },

    [2] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,0}, {0,0,0}, {190,218,204}, {190,218,204}, {140,218,204}, {190,218,204}, {0,0,0}, {0,0,0}, {190,218,204}, {140,218,204}, {140,218,204}, {140,218,204}, {0,0,0}, {0,0,0}, {0,0,0}, {43,218,204}, {43,218,204}, {43,218,204}, {0,0,0}, {0,0,0}, {0,0,0}, {88,218,204}, {88,218,204}, {88,218,204}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    [3] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,0}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,0}, {0,0,255}, {0,0,0}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

};

void set_layer_color(int layer) {
  for (int i = 0; i < RGB_MATRIX_LED_COUNT; i++) {
    HSV hsv = {
      .h = pgm_read_byte(&ledmap[layer][i][0]),
      .s = pgm_read_byte(&ledmap[layer][i][1]),
      .v = pgm_read_byte(&ledmap[layer][i][2]),
    };
    if (!hsv.h && !hsv.s && !hsv.v) {
        rgb_matrix_set_color( i, 0, 0, 0 );
    } else {
        RGB rgb = hsv_to_rgb_with_value(hsv);
        rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
    }
  }
}

bool rgb_matrix_indicators_user(void) {
  if (rawhid_state.rgb_control) {
      return false;
  }
  if (!keyboard_config.disable_layer_led) { 
    switch (biton32(layer_state)) {
      case 0:
        set_layer_color(0);
        break;
      case 1:
        set_layer_color(1);
        break;
      case 2:
        set_layer_color(2);
        break;
      case 3:
        set_layer_color(3);
        break;
     default:
        if (rgb_matrix_get_flags() == LED_FLAG_NONE) {
          rgb_matrix_set_color_all(0, 0, 0);
        }
    }
  } else {
    if (rgb_matrix_get_flags() == LED_FLAG_NONE) {
      rgb_matrix_set_color_all(0, 0, 0);
    }
  }

  return true;
}

extern bool set_scrolling;
extern bool navigator_turbo;
extern bool navigator_aim;




bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
  case QK_MODS ... QK_MODS_MAX:
    // Mouse and consumer keys (volume, media) with modifiers work inconsistently across operating systems,
    // this makes sure that modifiers are always applied to the key that was pressed.
    if (IS_MOUSE_KEYCODE(QK_MODS_GET_BASIC_KEYCODE(keycode)) || IS_CONSUMER_KEYCODE(QK_MODS_GET_BASIC_KEYCODE(keycode))) {
      if (record->event.pressed) {
        add_mods(QK_MODS_GET_MODS(keycode));
        send_keyboard_report();
        wait_ms(2);
        register_code(QK_MODS_GET_BASIC_KEYCODE(keycode));
        return false;
      } else {
        wait_ms(2);
        del_mods(QK_MODS_GET_MODS(keycode));
      }
    }
    break;

    case DUAL_FUNC_0:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          layer_move(0);
        } else {
          layer_move(0);
        }
      } else {
        if (record->event.pressed) {
          register_code16(KC_LEFT_SHIFT);
        } else {
          unregister_code16(KC_LEFT_SHIFT);
        }  
      }  
      return false;
    case DUAL_FUNC_1:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          layer_move(0);
        } else {
          layer_move(0);
        }
      } else {
        if (record->event.pressed) {
          register_code16(KC_RIGHT_SHIFT);
        } else {
          unregister_code16(KC_RIGHT_SHIFT);
        }  
      }  
      return false;
    case DRAG_SCROLL:
      if (record->event.pressed) {
        set_scrolling = true;
      } else {
        set_scrolling = false;
      }
      return false;
    case TOGGLE_SCROLL:
      if (record->event.pressed) {
        set_scrolling = !set_scrolling;
      }
      return false;
    break;
  case NAVIGATOR_TURBO:
    if (record->event.pressed) {
      navigator_turbo = true;
    } else {
      navigator_turbo = false;
    }
    return false;
  case NAVIGATOR_AIM:
    if (record->event.pressed) {
      navigator_aim = true;
    } else {
      navigator_aim = false;
    }
    return false;
  case NAVIGATOR_INC_CPI:
    if (record->event.pressed) {
        pointing_device_set_cpi(1);
    }
    return false;
  case NAVIGATOR_DEC_CPI:
    if (record->event.pressed) {
        pointing_device_set_cpi(0);
    }
    return false;
    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
  }
  return true;
}
