#include QMK_KEYBOARD_H

// LAYERS
#define QWERTY 	0      // AZERTY layer
#define _QW 	_QWERTY

#define _FUNCTION 1    // Function layer
#define _FN 	_FUNCTION

#define _CONTROL 2     // Control layer
#define _CN 	_CONTROL

#define nini 	3
#define unicode 4

#define MO_FN 	MO(_FUNCTION)
#define NINI 	MO(nini)
#define UNICODE MO(unicode)
#define _CTRL 	MO(_CONTROL)

#define SCRCLIP	C(S(KC_PAST)) 	// ShareX Screenshot to Clipboard		Ctrl+Shift+*
#define SCRUPLD	C(KC_PSCR)	 	// ShareX Screenshot and Upload			Ctrl+PrntScr
#define MP4FLDR	S(KC_PSCR)	 	// ShareX mp4 recording (Folder opens)	Shift+PrntScr
#define GIFUPLD	A(KC_PSCR)		// Sharex GIF capture and Upload		Alt+PrntScr
#define OCR		C(S(KC_PPLS))	// Sharex OCR							Ctrl+Shift++

#define RGB_MSW RGB_M_SW
#define RGB_MSN RGB_M_SN

#define LAYOUT_nini_zilents( \
    k00, k01, k02, k03, k04, k05, k06, k07, k08, k09, k0a, k0b, k0c, kins0, k0e, \
    k10,      k12, k13, k14, k15, k16, k17, k18, k19, k1a, k1b, k1c, k1d,      \
    k20,      k22, k23, k24, k25, k26, k27, k28, k29, k2a, k2b, k2c, k1e, k2d, \
    k30, k31, k32, k33, k34, k35, k36, k37, k38, k39, k3a, k3b,      k3d, kins1,\
    k40, k41,      k43,           k46,                k4a, k4b,      k4d, k4e  \
    ) { \
  { k00,  k01,   k02,   k03,  k04,   k05,   k06,  k07,   k08,   k09,   k0a,  k0b,  k0c,   kins0, k0e   }, \
  { k10,  KC_NO, k12,   k13,  k14,   k15,   k16,  k17,   k18,   k19,   k1a,  k1b,  k1c,   k1d,   k1e   }, \
  { k20,  KC_NO, k22,   k23,  k24,   k25,   k26,  k27,   k28,   k29,   k2a,  k2b,  k2c,   k2d,   KC_NO }, \
  { k30,  k31,   k32,   k33,  k34,   k35,   k36,  k37,   k38,   k39,   k3a,  k3b,  k3d, kins1,   KC_NO }, \
  { k40,  k41,   KC_NO, k43,  KC_NO, KC_NO, k46,  KC_NO, KC_NO, KC_NO, k4a,  k4b,  KC_NO, k4d,   k4e   }  \
}

enum _unicode_indexes {
  CLWN,
};

const uint32_t PROGMEM unicode_map[] = {
  [CLWN]	= 0x1F921,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [QWERTY] = LAYOUT_nini_zilents(
      //       2        3        4        5        6        7        8        9        10       11       12       13       14       15       16
      KC_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_BSPC,
      KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC,
      MO_FN,   KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_NUHS, KC_ENT,
      KC_LSFT, KC_NUBS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_DOT,  KC_SLSH, KC_RSFT,
      KC_LCTL, KC_LGUI, KC_LALT,                   KC_SPC,                             KC_RALT, NINI,    _CTRL,   KC_RCTL
      ),

  [_FUNCTION] = LAYOUT_nini_zilents(
      //       2        3        4        5        6        7        8        9        10       11       12       13       14       15       16
      KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,  KC_DEL,
      _______, KC_GRV,  KC_UP,   _______, _______, _______, _______, KC_HOME, _______, KC_END,  KC_PGUP, KC_PSCR, KC_INS,
      _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, _______, _______, _______, _______, KC_PGDN, KC_MPRV, KC_MNXT, KC_MPLY,
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_MUTE, KC_VOLD, KC_VOLU, _______,
      _______, _______, _______,                   KC_WREF,                            _______, _______, _______, _______
      ),

  [_CONTROL] = LAYOUT_nini_zilents(
      //       2        3        4        5        6        7        8        9        10       11       12       13       14       15       16
      TG(_CN), SCRCLIP, SCRUPLD, MP4FLDR, GIFUPLD, OCR,     _______, _______, _______, _______, _______, _______, _______, _______, _______,
      _______, RGB_TOG, RGB_MOD, RGB_HUD, RGB_HUI, RGB_SAD, RGB_SAI, _______, _______, _______, _______, _______, _______,
      _______, RGB_VAD, RGB_VAI, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
      _______, RGB_M_P, RGB_M_B, RGB_M_R, RGB_MSW, RGB_MSN, RGB_M_K, RGB_M_X, RGB_M_G, RGB_M_T, _______, _______, _______, _______,
      _______, _______, _______,                   XXXXXXX,                            _______, _______, _______, _______
      ),

  [nini] = LAYOUT_nini_zilents(
      //       2        3        4        5        6        7        8        9        10       11       12       13       14       15       16
      _______, KC_PPLS, KC_PMNS, KC_PAST, KC_PSLS, _______, _______, _______, _______, _______, _______, _______, _______, UNICODE, KC_NLCK,
      _______, KC_P7,   KC_P8,   KC_P9,   _______, _______, _______, _______, _______, _______, _______, _______, _______,
      _______, KC_P4,   KC_P5,   KC_P6,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
      _______, _______, KC_P1,   KC_P2,   KC_P3,   _______, _______, _______, _______, _______, _______, _______, _______, _______,
      _______, KC_PDOT, KC_P0,                   	 _______,                            _______, _______, _______, _______
      ),

  [unicode] = LAYOUT_nini_zilents(
      //       2        3        4        5        6        7        8        9        10       11       12       13       14       15       16
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
      _______, X(CLWN), _______, _______, _______, _______, _______, _______, _______, _______, UC_M_OS, UC_M_LN, UC_M_WI,
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
      _______, _______, _______,                   _______,                            _______, _______, _______, _______
      ),
};
