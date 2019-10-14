#include QMK_KEYBOARD_H

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
 *  You can use _______ in place for KC_TRNS (transparent)   *
 *  Or you can use XXXXXXX for KC_NO (NOOP)                  *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

// Each layer gets a name for readability.
#define LAYER_QWERTY 0
#define LAYER_NAV 1
#define LAYER_MOUSEMEDIA 2
#define LAYER_QMK 3

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [LAYER_QWERTY] = LAYOUT_60_ansi(
    /* Row 0 */
    KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSPC, 
    /* Row 1 */
    KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSLS, 
    /* Row 2 */
    TT(1), KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT,  
    /* Row 3 */
    KC_LSPO, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSPC, 
    /* Row 4 */
    KC_LCTL, KC_LGUI, KC_LALT, KC_SPC, TT(1), TT(2), KC_APP, KC_RCTL), 
	
  [LAYER_NAV] = LAYOUT_60_ansi(
    /* Row 0 */
    KC_ESC, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_DEL,  
    /* Row 1 */
    _______, XXXXXXX, KC_UP, XXXXXXX, XXXXXXX, XXXXXXX, KC_INS, KC_DEL, XXXXXXX, KC_PGUP, KC_PGDN, XXXXXXX, XXXXXXX, XXXXXXX, 
    /* Row 2 */
    _______, KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX, XXXXXXX, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, XXXXXXX, XXXXXXX, _______, 
    /* Row 3 */
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_HOME, KC_END, XXXXXXX, KC_RALT, KC_RGUI, _______,  
    /* Row 4 */
    _______, _______, _______, _______, TG(1), _______, _______, _______),

  [LAYER_MOUSEMEDIA] = LAYOUT_60_ansi(
    /* Row 0 */
    TG(2), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, 
    /* Row 1 */
    KC_BTN3, KC_BTN1, KC_MS_U, KC_BTN2, KC_WH_U, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, TG(3), 
    /* Row 2 */
    _______, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D, XXXXXXX, XXXXXXX, XXXXXXX, KC_MPRV, KC_MPLY, KC_MSTP, KC_MNXT, _______, 
    /* Row 3 */
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_MUTE, KC__VOLDOWN, KC_VOLU, XXXXXXX, _______,
    /* Row 4 */
    _______, _______, _______, XXXXXXX, _______, _______, _______, _______),
  
  [LAYER_QMK] = LAYOUT_60_ansi(
    /* Row 0 */
    TG(3), RGB_M_P, RGB_M_B, RGB_M_R, RGB_M_SW, RGB_M_SN, RGB_M_K, RGB_M_X, RGB_M_G, XXXXXXX, XXXXXXX, RGB_VAD, RGB_VAI, RESET, 
    /* Row 1 */
    XXXXXXX, RGB_RMOD, RGB_MOD, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RGB_SAD, RGB_SAI, XXXXXXX, _______, 
    /* Row 2 */
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RGB_SPD, RGB_SPI, XXXXXXX, XXXXXXX,
    /* Row 3 */
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, BL_TOGG, BL_DEC, BL_INC, BL_STEP, BL_BRTG, 
    /* Row 4 */
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX)
};

const uint8_t HSV_PerLayer[][3] = {
  {HSV_CHARTREUSE},		/* QWERTY */
  {HSV_TEAL},			/* NAV */
  {HSV_GOLD},			/* MOUSEMEDIA */
  {HSV_RED}			/* QMK */
};

void matrix_init_user(void) {
    rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
    rgblight_sethsv_noeeprom(HSV_PerLayer[0][0], 
			     HSV_PerLayer[0][1], 
			     HSV_PerLayer[0][2]);
}

void matrix_scan_user(void) {

#ifdef RGBLIGHT_ENABLE
  
  static int old_layer = -1;
  uint8_t new_layer = biton32(layer_state);

  if (old_layer != new_layer) {
    rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
    rgblight_sethsv_noeeprom(HSV_PerLayer[new_layer][0], 
			     HSV_PerLayer[new_layer][1], 
			     rgblight_get_val());

    old_layer = new_layer;
  }

#endif //RGBLIGHT_ENABLE

}
