#include "kb.h"
#include "keymap_steno.h"

enum layers {
  _QWERTY,
  _DVORAK,
  _PLOVER,
  _STENO,
  _SYMBOL,
  _ARROWS,
  _MOUSE,
};

#define ST_BOLT QK_STENO_BOLT
#define ST_GEM  QK_STENO_GEMINI

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Qwerty
    * ,------------------------------------------------|                                        |------------------------------------------------, *
    * |`     |1     |2     |3     |4     |5     |SYM   |                                        |   DVO|     6|     7|     8|     9|     0|     -| *
    * |------+------+------+------+------+------+------|                                        |------+------+------+------+------+------+------| *
    * |TAB   |Q     |W     |E     |R     |T     |{     |                                        |     }|     Y|     U|     I|     O|     P|     \| *
    * |------+------+------+------+------+------+------|                                        |------+------+------+------+------+------+------| *
    * |ESC   |A     |S     |D     |F     |G     |[     |                                        |     ]|     H|     J|     K|     L|     ;|     '| *
    * |------+------+------+------+------+------+------|                                        |------+------+------+------+------+------+------| *
    * |LSH   |Z     |X     |C     |V     |B     |SYM   |                                        |   SYM|     N|     M|     ,|     .|     /|   RSH| *
    * |------+------+------+------+------+------+------|                                        |------+------+------+------+------+------+------| *
    * |SYM/= |LCTL  |LGUI  |LALT  |ARROW |                                                                    | ARROW|  RALT|  RGUI|  RTCL|   SYM| *
    * `-----------------------------------                                                                    -----------------------------------` *
    *                                                   |---------------|      |---------------|                                                   *
    *                                                   |<-     |UP     |      |    DWN|     ->|                                                   *
    *                                           ,-------+-------+-------|      |-------+-------+-------,                                           *
    *                                           |BSP    |DEL    |HOME   |      |   PGUP|  ENTER|    SPC|                                           *
    *                                           |       |       |-------|      |-------|       |       |                                           *
    *                                           |-------+-------|END    |      |   PGDN|-------+-------|                                           *
    *                                           |LSH    |SWAP   |-------|      |-------|   SWAP|    RSH|                                           *
    *                                           |-------+-------+                      +-------+-------|                                           *
    */
    [_QWERTY] = KEYMAP(
        KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, TG(_SYMBOL),
        KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_LCBR,
        KC_ESC, KC_A, KC_S, KC_D, KC_F, KC_G, KC_LBRACKET,
        KC_LSHIFT, KC_Z, KC_X, KC_C, KC_V, KC_B, TT(_SYMBOL),
        LT(_SYMBOL, KC_EQL), KC_LCTL, KC_LGUI, KC_LALT, TT(_ARROWS),
                                                                            KC_LEFT, KC_UP,
                                                                    KC_BSPC, KC_DEL, KC_HOME,
                                                                    KC_LSHIFT, SH_MON, KC_END,
    TG(_DVORAK), KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINUS,
    KC_RCBR, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSLASH,
    KC_RBRACKET, KC_H, KC_J, KC_K, KC_L, KC_SCOLON, KC_QUOT,
    TT(_SYMBOL), KC_N, KC_M, KC_COMMA, KC_DOT, KC_SLASH, KC_RSHIFT,
                       TT(_ARROWS), KC_RALT, KC_RGUI, KC_RCTL, LT(_SYMBOL, KC_EQL),
KC_DOWN, KC_RIGHT,
KC_PGUP, KC_ENTER, KC_SPC,
KC_PGDN, SH_MON, KC_RSHIFT),

    [_DVORAK] = KEYMAP(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_QUOT, KC_COMM, KC_DOT, KC_P, KC_Y, KC_TRNS,
        KC_TRNS, KC_A, KC_O, KC_E, KC_U, KC_I, KC_TRNS,
        KC_TRNS, KC_SCLN, KC_Q, KC_J, KC_K, KC_X, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                                                             KC_TRNS, KC_TRNS,
                                                                    KC_TRNS, KC_TRNS, KC_TRNS,
                                                                    KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_BSLASH,
        KC_TRNS, KC_F, KC_G, KC_C, KC_R, KC_L, KC_SLASH,
        KC_TRNS, KC_D, KC_H, KC_T, KC_N, KC_S, KC_MINUS,
        KC_TRNS, KC_B, KC_M, KC_W, KC_V, KC_Z, KC_TRNS,
                       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,

KC_TRNS, KC_TRNS,
KC_TRNS, KC_TRNS, KC_TRNS,
KC_TRNS, KC_TRNS, KC_TRNS),

/* Plover layer (http://opensteno.org)
 * ,-----------------------------------------------------------------------------------.
 * |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |  FN  |   S  |   T  |   P  |   H  |   *  |   *  |   F  |   P  |   L  |   T  |   D  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |   S  |   K  |   W  |   R  |   *  |   *  |   R  |   B  |   G  |   S  |   Z  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Exit |      |      |   A  |   O  |             |   E  |   U  |  PWR | RES1 | RES2 |
 * `-----------------------------------------------------------------------------------'
 */

    [_PLOVER] = KEYMAP(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_TRNS,
        KC_TRNS, KC_A, KC_S, KC_D, KC_F, KC_G, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                                                             KC_TRNS, KC_TRNS,
                                                                    KC_TRNS, KC_TRNS, KC_TRNS,
                                                                    KC_C, KC_V, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRACKET,
        KC_TRNS, KC_H, KC_J, KC_K, KC_L, KC_SCOLON, KC_QUOTE,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,

KC_TRNS, KC_TRNS,
KC_TRNS, KC_TRNS, KC_TRNS,
KC_TRNS, KC_N, KC_M),

    [_STENO] = KEYMAP(
        ST_BOLT, STN_N1, STN_N2, STN_N3, STN_N4, STN_N5, KC_TRNS,
        KC_TRNS, STN_S1, STN_TL, STN_PL, STN_HL, STN_ST1, KC_TRNS,
        KC_TRNS, STN_S2, STN_KL, STN_WL, STN_RL, STN_ST2, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  STN_A, STN_O, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                                                            STN_A, STN_O,
                                                                    KC_TRNS, KC_TRNS, KC_TRNS,
                                                                    STN_A, STN_O, KC_TRNS,
        KC_TRNS, STN_N6, STN_N7, STN_N8, STN_N9, KC_TRNS, QK_STENO_GEMINI,
        KC_TRNS, STN_ST3, STN_FR, STN_PR, STN_LR, STN_TR, STN_DR,
        KC_TRNS, STN_ST4, STN_RR, STN_BR, STN_GR, STN_SR, STN_ZR,
        KC_TRNS, STN_E, STN_U, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,

STN_E, STN_U,
KC_TRNS, KC_TRNS, KC_TRNS,
KC_TRNS, STN_E, STN_U),

    /* Symbol
    * ,------------------------------------------------|                                        |------------------------------------------------, *
    * |       |F1    |F2    |F3    |F4    |F5    |      |                                        |      |    F6|    F7|    F8|    F9|   F10|   F11| *
    * |------+------+------+------+------+------+------|                                        |------+------+------+------+------+------+------| *
    * |      |!     |@     |{     |}     ||     |      |                                        |      |    UP|   KP7|   KP8|   KP9|   KP*|   F12| *
    * |------+------+------+------+------+------+------|                                        |------+------+------+------+------+------+------| *
    * |      |#     |$     |(     |)     |`     |      |                                        |      |   DWN|   KP4|   KP5|   KP6|   KP+|      | *
    * |------+------+------+------+------+------+------|                                        |------+------+------+------+------+------+------| *
    * |      |%     |^     |[     |]     |~     |      |                                        |      |KPENTR|   KP1|   KP2|   KP3|   KP/|      | *
    * |------+------+------+------+------+------+------|                                        |------+------+------+------+------+------+------| *
    * |SYM/` |      |      |      |      |                                                                    |   KP0|   KP.|   KP,|   KP=|      | *
    * `-----------------------------------                                                                    -----------------------------------` *
    *                                                   |---------------|      |---------------|                                                   *
    *                                                   |       |       |      |       |       |                                                   *
    *                                           ,-------+-------+-------|      |-------+-------+-------,                                           *
    *                                           |       |       |       |      |       |       |       |                                           *
    *                                           |       |       |-------|      |-------|       |       |                                           *
    *                                           |-------+-------|       |      |       |-------+-------|                                           *
    *                                           |       |       |-------|      |-------|       |       |                                           *
    *                                           |-------+-------+                      +-------+-------|                                           */
    [_SYMBOL] = KEYMAP(
        KC_TRNS, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_TRNS,
        KC_TRNS, KC_EXLM, KC_AT, KC_LCBR, KC_RCBR, KC_PIPE, KC_TRNS,
        KC_TRNS, KC_HASH, KC_DLR, KC_LPRN, KC_RPRN, KC_GRV, KC_TRNS,
        KC_TRNS, KC_PERC, KC_CIRC, KC_LBRC, KC_RBRC, KC_TILD, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,

                                                                             KC_TRNS, KC_TRNS,
                                                                    KC_TRNS, KC_TRNS, KC_TRNS,
                                                                    KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11,
        KC_TRNS, KC_UP, KC_KP_7, KC_KP_8, KC_KP_9, KC_KP_ASTERISK, KC_F12,
        KC_TRNS, KC_DOWN, KC_KP_4, KC_KP_5, KC_KP_6, KC_KP_PLUS, KC_TRNS,
        KC_TRNS, KC_KP_ENTER, KC_KP_1, KC_KP_2, KC_KP_3, KC_KP_SLASH, KC_TRNS,
                                 KC_KP_0, KC_KP_DOT, KC_KP_COMMA, KC_KP_EQUAL, KC_TRNS,

KC_TRNS, KC_TRNS,
KC_TRNS, KC_TRNS, KC_TRNS,
KC_TRNS, KC_TRNS, KC_TRNS),

    /* Arrow
    * ,------------------------------------------------|                                        |------------------------------------------------, *
    * |      |      |      |      |      |      |      |                                        |      |      |      |      |      |      |      | *
    * |------+------+------+------+------+------+------|                                        |------+------+------+------+------+------+------| *
    * |      |      |UP    |      |      |      |      |                                        |      |      |      |      |    UP|      |      | *
    * |------+------+------+------+------+------+------|                                        |------+------+------+------+------+------+------| *
    * |      |LEFT  |DOWN  |RIGHT |      |      |      |                                        |      |      |      |  LEFT|  DOWN| RIGHT|      | *
    * |------+------+------+------+------+------+------|                                        |------+------+------+------+------+------+------| *
    * |MOUSE |      |      |      |      |      |      |                                        |      |      |      |      |      |      | MOUSE| *
    * |------+------+------+------+------+------+------|                                        |------+------+------+------+------+------+------| *
    * |STENO |      |      |      |      |                                                                    |      |      |      |      | STENO| *
    * `-----------------------------------                                                                    -----------------------------------` *
    *                                                   |---------------|      |---------------|                                                   *
    *                                                   |       |       |      |       |       |                                                   *
    *                                           ,-------+-------+-------|      |-------+-------+-------,                                           *
    *                                           |       |       |       |      |       |       |       |                                           *
    *                                           |       |       |-------|      |-------|       |       |                                           *
    *                                           |-------+-------|       |      |       |-------+-------|                                           *
    *                                           |       |       |-------|      |-------|       |       |                                           *
    *                                           |-------+-------+                      +-------+-------|                                           */
    [_ARROWS] = KEYMAP(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_UP, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_LEFT, KC_DOWN, KC_RIGHT, KC_TRNS, KC_TRNS, KC_TRNS,
        TT(_MOUSE), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        TG(_STENO), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,

                                                                             KC_TRNS, KC_TRNS,
                                                                    KC_TRNS, KC_TRNS, KC_TRNS,
                                                                    KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_UP, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_LEFT, KC_DOWN, KC_RIGHT, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, TT(_MOUSE),
                          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, TG(_STENO),

KC_TRNS, KC_TRNS,
KC_TRNS, KC_TRNS, KC_TRNS,
KC_TRNS, KC_TRNS, KC_TRNS),

    /* Mouse
    * ,------------------------------------------------|                                        |------------------------------------------------, *
    * |      |      |      |      |      |      |      |                                        |      |      |      |      |      |      |      | *
    * |------+------+------+------+------+------+------|                                        |------+------+------+------+------+------+------| *
    * |      |MS_B1 |MS_UP |ACCEL0|ACCEL1|ACCEL2|      |                                        |      |ACCEL2|ACCEL1|ACCEL0| MS_UP| MS_B1|      | *
    * |------+------+------+------+------+------+------|                                        |------+------+------+------+------+------+------| *
    * |      |MS_LFT|MS_DWN|MS_RT | MS_B2|      |      |                                        |      |      | MS_B2|MS_DWN| MS_B1| MS_RT|      | *
    * |------+------+------+------+------+------+------|                                        |------+------+------+------+------+------+------| *
    * |      |      |      |      |      |      |                                        |      |      |      |      |      |      |      | *
    * |------+------+------+------+------+------+------|                                        |------+------+------+------+------+------+------| *
    * |      |      |      |      |      |                                                                    |      |      |      |      |      | *
    * `-----------------------------------                                                                    -----------------------------------` *
    *                                                   |---------------|      |---------------|                                                   *
    *                                                   |       |       |      |       |       |                                                   *
    *                                           ,-------+-------+-------|      |-------+-------+-------,                                           *
    *                                           |       |       |       |      |       |       |       |                                           *
    *                                           |       |       |-------|      |-------|       |       |                                           *
    *                                           |-------+-------|       |      |       |-------+-------|                                           *
    *                                           |       |       |-------|      |-------|       |       |                                           *
    *                                           |-------+-------+                      +-------+-------|                                           */

    [_MOUSE] = KEYMAP(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_MS_BTN1, KC_MS_UP, KC_MS_ACCEL0, KC_MS_ACCEL1, KC_MS_ACCEL2, KC_TRNS,
        KC_TRNS, KC_MS_LEFT, KC_MS_DOWN, KC_MS_RIGHT, KC_MS_BTN2, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,

                                                                             KC_TRNS, KC_TRNS,
                                                                    KC_TRNS, KC_TRNS, KC_TRNS,
                                                                    KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_MS_ACCEL2, KC_MS_ACCEL1, KC_MS_ACCEL0, KC_MS_UP, KC_MS_BTN1, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_MS_BTN2, KC_MS_LEFT, KC_MS_DOWN, KC_MS_RIGHT, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,

KC_TRNS, KC_TRNS,
KC_TRNS, KC_TRNS, KC_TRNS,
KC_TRNS, KC_TRNS, KC_TRNS)
};

//     [_XYZ] = KEYMAP(
//         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
//         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
//         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
//         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
//         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,

//                                                                              KC_TRNS, KC_TRNS,
//                                                                     KC_TRNS, KC_TRNS, KC_TRNS,
//                                                                     KC_TRNS, KC_TRNS, KC_TRNS,
//         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
//         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
//         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
//         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
//                                  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,

// KC_TRNS, KC_TRNS,
// KC_TRNS, KC_TRNS, KC_TRNS,
// KC_TRNS, KC_TRNS, KC_TRNS)

    /* Arrow
    * ,------------------------------------------------|                                        |------------------------------------------------, *
    * |      |      |      |      |      |      |      |                                        |      |      |      |      |      |      |      | *
    * |------+------+------+------+------+------+------|                                        |------+------+------+------+------+------+------| *
    * |      |      |      |      |      |      |      |                                        |      |      |      |      |      |      |      | *
    * |------+------+------+------+------+------+------|                                        |------+------+------+------+------+------+------| *
    * |      |      |      |      |      |      |      |                                        |      |      |      |      |      |      |      | *
    * |------+------+------+------+------+------+------|                                        |------+------+------+------+------+------+------| *
    * |      |      |      |      |      |      |      |                                        |      |      |      |      |      |      |      | *
    * |------+------+------+------+------+------+------|                                        |------+------+------+------+------+------+------| *
    * |      |      |      |      |      |                                                                    |      |      |      |      |      | *
    * `-----------------------------------                                                                    -----------------------------------` *
    *                                                   |---------------|      |---------------|                                                   *
    *                                                   |       |       |      |       |       |                                                   *
    *                                           ,-------+-------+-------|      |-------+-------+-------,                                           *
    *                                           |       |       |       |      |       |       |       |                                           *
    *                                           |       |       |-------|      |-------|       |       |                                           *
    *                                           |-------+-------|       |      |       |-------+-------|                                           *
    *                                           |       |       |-------|      |-------|       |       |                                           *
    *                                           |-------+-------+                      +-------+-------|                                           */
