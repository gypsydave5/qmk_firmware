#include "action_layer.h"
#include "eeconfig.h"
#include "preonic.h"
#ifdef AUDIO_ENABLE
#include "audio.h"
#endif

// Each layer gets a name for readability, which is then used in the keymap
// matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or
// any other name.
// Layer names don't all need to be of the same length, obviously, and you can
// also skip them
// entirely and just use numbers.
#define _COLEMAK 0
#define _APL 2
#define _APL_SFT 3
#define _LOWER 4
#define _RAISE 6
#define _KEYPAD 8
#define _ADJUST 16

// APL Keycodes - starting with Monadic Functions
#define APL_ROLL UC(0x003F)  // ?
#define APL_CEIL UC(0x2308)  // ⌈
#define APL_FLR UC(0x230A)   // ⌊
#define APL_SHP UC(0x2374)   // ⍴
#define APL_NOT UC(0x223C)   // ∼
#define APL_ABS UC(0x2223)   // ∣
#define APL_IDXG UC(0x2373)  // ⍳
#define APL_EXP UC(0x22C6)   // ⋆
#define APL_NEG UC(0x2212)   // −
#define APL_ID UC(0x002B)    // +
#define APL_SGNM UC(0x00D7)  // ×
#define APL_RCPR UC(0x00F7)  // ÷
#define APL_RCL UC(0x002C)   // ,
#define APL_MXINV UC(0x2339) // ⌹
#define APL_PITMS UC(0x25CB) // ○
#define APL_LOG UC(0x235F)   // ⍟
#define APL_REVL UC(0x233D)  // ⌽
#define APL_REVF UC(0x2296)  // ⊖
#define APL_GDUP UC(0x234B)  // ⍋
#define APL_GDDN UC(0x2352)  // ⍒
#define APL_EXE UC(0x234E)   // ⍎
#define APL_MFMT UC(0x2355)  // ⍕
#define APL_MTSP UC(0x2349)  // ⍉
#define APL_FAC UC(0x0021)   // !

// Dyadic
#define APL_EPS UC(0x2208)  // ∈
#define APL_TAKE UC(0x2191) // ↑
#define APL_DROP UC(0x2193) // ↓

enum preonic_keycodes {
  COLEMAK = SAFE_RANGE,
  APL,
  APL_SFT,
  LOWER,
  RAISE,
  KEYPAD
};

enum { TD_SPC_ENT = 0 };

qk_tap_dance_action_t tap_dance_actions[] = {
        [TD_SPC_ENT] = ACTION_TAP_DANCE_DOUBLE(KC_SPC, KC_ENT),
};

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

        [_COLEMAK] = {{KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8,
                       KC_9, KC_0, KC_BSPC},
                      {GUI_T(KC_TAB), KC_Q, KC_W, KC_F, KC_P, KC_G, KC_J, KC_L,
                       KC_U, KC_Y, KC_SCLN, GUI_T(KC_BSLS)},
                      {CTL_T(KC_ESC), KC_A, KC_R, KC_S, KC_T, KC_D, KC_H, KC_N,
                       KC_E, KC_I, KC_O, CTL_T(KC_QUOT)},
                      {KC_LSPO, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_K, KC_M,
                       KC_COMM, KC_DOT, KC_SLSH, KC_RSPC},
                      {KEYPAD, KC_NO, KC_NO, LOWER, ALT_T(KC_LBRC),
                       TD(TD_SPC_ENT), TD(TD_SPC_ENT), ALT_T(KC_RBRC), RAISE,
                       KC_NO, KC_NO, KC_NO}},

        [_APL] = {{_______, _______, _______, _______, _______, _______,
                   _______, _______, _______, _______, _______, _______},
                  {_______, _______, _______, _______, _______, _______,
                   _______, _______, _______, _______, _______, _______},
                  {_______, _______, _______, _______, _______, _______,
                   _______, _______, _______, _______, _______, _______},
                  {APL_SFT, _______, _______, _______, _______, _______,
                   _______, _______, _______, _______, _______, APL_SFT},
                  {_______, _______, _______, _______, _______, _______,
                   _______, _______, _______, _______, _______, _______}},

        [_APL_SFT] = {{_______, _______, _______, _______, _______, _______,
                       _______, _______, _______, _______, _______, _______},
                      {_______, _______, _______, _______, _______, _______,
                       _______, _______, _______, _______, _______, _______},
                      {_______, _______, _______, _______, _______, _______,
                       _______, _______, _______, _______, _______, _______},
                      {_______, _______, _______, _______, _______, _______,
                       _______, _______, _______, _______, _______, _______},
                      {_______, _______, _______, _______, _______, _______,
                       _______, _______, _______, _______, _______, _______}},

        [_LOWER] = {{KC_F13, KC_F14, KC_F15, KC_F16, KC_F17, KC_F18, KC_F19,
                     KC_F20, KC_F21, KC_F22, KC_F23, KC_F24},
                    {KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8,
                     KC_F9, KC_F10, KC_F11, KC_F12},
                    {_______, _______, _______, _______, _______, _______,
                     _______, KC_MINUS, KC_EQL, _______, _______, _______},
                    {_______, _______, _______, _______, _______, _______,
                     _______, KC_UNDS, KC_PLUS, KC_PGDN, KC_UP, KC_PGUP},
                    {RESET, _______, _______, _______, _______, _______,
                     _______, _______, _______, KC_LEFT, KC_DOWN, KC_UP}},

        [_RAISE] = {{_______, _______, _______, _______, _______, _______,
                     _______, _______, _______, _______, _______, _______},
                    {_______, _______, _______, _______, _______, _______,
                     _______, _______, _______, _______, _______, _______},
                    {_______, KC_1, KC_2, KC_3, KC_4, KC_5, _______, _______,
                     _______, _______, _______, _______},
                    {_______, KC_6, KC_7, KC_8, KC_9, KC_0, _______, _______,
                     _______, _______, _______, _______},
                    {RESET, _______, _______, _______, _______, _______,
                     _______, _______, _______, _______, _______, _______}},

        [_KEYPAD] = {{_______, _______, _______, _______, _______, _______,
                      _______, KC_PEQL, KC_PSLS, KC_PAST, _______, _______},
                     {_______, _______, _______, _______, _______, _______,
                      KC_P7, KC_P8, KC_P9, KC_PMNS, _______, _______},
                     {_______, _______, _______, _______, _______, _______,
                      KC_P4, KC_P5, KC_P6, KC_PPLS, _______, _______},
                     {_______, _______, _______, _______, _______, _______,
                      KC_P1, KC_P2, KC_P3, KC_PENT, _______, _______},
                     {_______, _______, _______, _______, _______, _______,
                      KC_P0, KC_P0, KC_PDOT, KC_PENT, _______, _______}},

        [_ADJUST] = {{_______, _______, _______, _______, _______, _______,
                      _______, _______, KC_MUTE, KC_VOLD, KC_VOLU, KC_PWR},
                     {_______, RESET, _______, _______, _______, _______,
                      _______, _______, _______, _______, _______, KC_DEL},
                     {_______, _______, _______, AU_ON, AU_OFF, AG_NORM,
                      AG_SWAP, _______, _______, _______, _______, _______},
                     {_______, MUV_DE, MUV_IN, MU_ON, MU_OFF, MI_ON, MI_OFF,
                      _______, _______, _______, _______, _______},
                     {_______, _______, _______, _______, _______, _______,
                      _______, _______, _______, _______, _______, _______}}};

#ifdef AUDIO_ENABLE
float tone_startup[][2] = {
    {NOTE_B5, 20}, {NOTE_B6, 8}, {NOTE_DS6, 20}, {NOTE_B6, 8}};

float tone_qwerty[][2] = SONG(QWERTY_SOUND);
float tone_dvorak[][2] = SONG(DVORAK_SOUND);
float tone_colemak[][2] = SONG(COLEMAK_SOUND);
float tone_goodbye[][2] = SONG(GOODBYE_SOUND);
float music_scale[][2] = SONG(MUSIC_SCALE_SOUND);
#endif

void persistant_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
  case COLEMAK:
    if (record->event.pressed) {
#ifdef AUDIO_ENABLE
      PLAY_NOTE_ARRAY(tone_colemak, false, 0);
#endif
      persistant_default_layer_set(1UL << _COLEMAK);
    }
    return false;
    break;
  case LOWER:
    if (record->event.pressed) {
      layer_on(_LOWER);
      update_tri_layer(_LOWER, _RAISE, _ADJUST);
    } else {
      layer_off(_LOWER);
      update_tri_layer(_LOWER, _RAISE, _ADJUST);
    }
    return false;
    break;
  case RAISE:
    if (record->event.pressed) {
      layer_on(_RAISE);
      update_tri_layer(_LOWER, _RAISE, _ADJUST);
    } else {
      layer_off(_RAISE);
      update_tri_layer(_LOWER, _RAISE, _ADJUST);
    }
    return false;
    break;
  case APL:
    if (record->event.pressed) {
      layer_on(_APL);
    } else {
      layer_off(_APL);
    }
    return false;
    break;
  case APL_SFT:
    if (record->event.pressed) {
      layer_on(_APL_SFT);
    } else {
      layer_off(_APL_SFT);
    }
    return false;
    break;
  case KEYPAD:
    if (record->event.pressed) {
      layer_on(_KEYPAD);
    } else {
      layer_off(_KEYPAD);
    }
    return false;
    break;
  }
  return true;
};

void matrix_init_user(void) {
#ifdef AUDIO_ENABLE
  startup_user();
#endif
}

#ifdef AUDIO_ENABLE

void startup_user() {
  _delay_ms(20); // gets rid of tick
  PLAY_NOTE_ARRAY(tone_startup, false, 0);
}

void shutdown_user() {
  PLAY_NOTE_ARRAY(tone_goodbye, false, 0);
  _delay_ms(150);
  stop_all_notes();
}

void music_on_user(void) { music_scale_user(); }

void music_scale_user(void) { PLAY_NOTE_ARRAY(music_scale, false, 0); }

#endif
