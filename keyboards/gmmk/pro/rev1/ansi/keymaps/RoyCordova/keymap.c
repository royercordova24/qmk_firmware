
#include QMK_KEYBOARD_H
#include "rgb_matrix_map.h"

enum LAYERS{
    _BL,
    _FN,
    _NUM,
    _GAMING
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

//      ESC      F1       F2       F3       F4       F5       F6       F7       F8       F9       F10      F11      F12	     Prt           Rotary(Mute)
//      ~        1        2        3        4        5        6        7        8        9        0         -       (=)	     BackSpc           Del
//      Tab      Q        W        E        R        T        Y        U        I        O        P        [        ]        \                 PgUp
//      Caps     A        S        D        F        G        H        J        K        L        ;        "                 Enter             PgDn
//      Sh_L              Z        X        C        V        B        N        M        ,        .        ?                 Sh_R     Up       End
//      Ct_L     Win_L    Alt_L                               SPACE                               Alt_R    FN       Ct_R     Left     Down     Right


    // The FN key by default maps to a momentary toggle to layer 1 to provide access to the QK_BOOT key (to put the board into bootloader mode). Without
    // this mapping, you have to open the case to hit the button on the bottom of the PCB (near the USB cable attachment) while plugging in the USB
    // cable to get the board into bootloader mode - definitely not fun when you're working on your QMK builds. Remove this and put it back to KC_RGUI
    // if that's your preference.
    //
    // To put the keyboard in bootloader mode, use FN+backslash. If you accidentally put it into bootloader, you can just unplug the USB cable and
    // it'll be back to normal when you plug it back in.

    [_BL] = LAYOUT(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_PSCR,          KC_MUTE,
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,          KC_DEL,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,          KC_PGUP,
        KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,           KC_PGDN,
        KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT, KC_UP,   KC_END,
        KC_LCTL, KC_LGUI, KC_LALT,                            KC_SPC,                             KC_RALT, MO(_FN), KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
    ),

    [_FN] = LAYOUT(
        KC_SLEP, _______, _______, _______, _______, _______, _______, RGB_VAD, RGB_VAI, _______, KC_MPRV, KC_MPLY, KC_MNXT, QK_BOOT,           _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,           TO(_GAMING),
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_UP,   _______, _______,           TO(_NUM),
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN,          KC_RGHT,           _______,
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______,  _______,
        KC_HOME, XXXXXXX, KC_END,                             _______,                            _______, _______, _______, _______, _______,  _______
    ),

    [_NUM] = LAYOUT(
        KC_ESC,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, QK_BOOT,           _______,
        _______, _______, _______, _______, _______, _______, XXXXXXX, KC_7,    KC_8,    KC_9,    XXXXXXX, _______, _______, _______,           _______,
        _______, _______, _______, _______, _______, _______, KC_PAST, KC_4,    KC_5,    KC_6,    KC_PSLS, _______, _______, _______,           TO(_BL),
        _______, _______, _______, _______, _______, _______, KC_0,    KC_1,    KC_2,    KC_3,    XXXXXXX, _______,          _______,           _______,
        _______,          _______, _______, _______, _______, XXXXXXX, KC_PPLS, KC_PMNS, XXXXXXX, KC_PDOT, _______,          _______, _______,  _______,
        _______, _______, _______,                            _______,                            _______, MO(_FN), _______, _______, _______,  _______
    ),

    [_GAMING] = LAYOUT(
        KC_ESC,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_PSCR,           _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,           TO(_BL),
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,           _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,           _______,
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______,  _______,
        _______, XXXXXXX, _______,                            _______,                            _______, MO(_FN), _______, _______, _______,  _______
    ),
};
//rgb functions
static void setRgbForArray(const uint8_t ledList[], size_t size, uint8_t r, uint8_t g, uint8_t b){
    for (size_t i = 0; i < size; i++) {
        rgb_matrix_set_color(ledList[i], r, g, b);
    }
}

static void setRgbForLayer(uint8_t layer){

    switch(layer){

        case _GAMING:
            setRgbForArray(LED_LIST_WASD, sizeof(LED_LIST_WASD) / sizeof(LED_LIST_WASD[0]), 255, 255, 0);  
            rgb_matrix_set_color(LED_HOME, RGB_WHITE);
            break;
        case _NUM:
            rgb_matrix_set_color(LED_PGUP, RGB_WHITE);
            break;
        case _FN:
            break;
        case _BL:
            break;
    }
}

static void setRgbForFnLayer(bool isFnLayerActive){
    if(!isFnLayerActive) return;

    setRgbForArray(LED_LIST_ALT_ARROWS, sizeof(LED_LIST_ALT_ARROWS) / sizeof(LED_LIST_ALT_ARROWS[0]), 255, 255, 255);
    setRgbForArray(LED_FN_NAV_INDICATORS, sizeof(LED_FN_NAV_INDICATORS) / sizeof(LED_FN_NAV_INDICATORS[0]), 255, 255, 255); 
    setRgbForArray(LED_LAYER_INDICATORS, sizeof(LED_LAYER_INDICATORS) / sizeof(LED_LAYER_INDICATORS[0]), 255, 255, 255); 
    setRgbForArray(LED_MEDIA_INDICATORS, sizeof(LED_MEDIA_INDICATORS) / sizeof(LED_MEDIA_INDICATORS[0]), 255, 255, 0); 
    setRgbForArray(LED_BRIGHTNESS_INDICATORS, sizeof(LED_BRIGHTNESS_INDICATORS) / sizeof(LED_BRIGHTNESS_INDICATORS[0]), 255, 255, 0); 

    rgb_matrix_set_color(LED_ESC, RGB_RED);
    rgb_matrix_set_color(LED_INS, RGB_RED);
}

static void setKeyCapsRgb(bool isKeyCapsOn, uint8_t layer){
    if(!isKeyCapsOn) return;

    uint8_t r = 255;
    uint8_t g = 255;
    uint8_t b = 255;

    if(layer != _GAMING){
        setRgbForArray(LED_CAPS_ROW, sizeof(LED_CAPS_ROW) / sizeof(LED_CAPS_ROW[0]), r, g, b);
        return;  
    }

    setRgbForArray(LED_CAPS_WHEN_GAMING, sizeof(LED_CAPS_WHEN_GAMING) / sizeof(LED_CAPS_WHEN_GAMING[0]), r, g, b);      
}

static void setWindowsKeyRgb(bool isWindowsKeyActive){
    if(isWindowsKeyActive) return;
    rgb_matrix_set_color(LED_LWIN, RGB_RED);
}

static void setNumpadRgb(bool isNumpadActive){
    if(!isNumpadActive) return;
    setRgbForArray(LED_LIST_NUMPAD, sizeof(LED_LIST_NUMPAD) / sizeof(LED_LIST_NUMPAD[0]), 255, 255, 255);
}
//should add mouse wheel movement for encoder
//adds mouse wheel with or without modifiers active
static bool ProcessEncoderForBaseLayer(bool clockwise, uint8_t modState){
    
    if (modState & MOD_MASK_SHIFT){
        tap_code(clockwise ? KC_VOLU : KC_VOLD);
        return false;
    }

    tap_code(clockwise ? KC_WH_D : KC_WH_U);
    return false;
}
//steps rgb matrix animation with encoder
static bool ProcessEncoderForFunctionLayer(bool clockwise, uint8_t modState){

    if(clockwise){
        rgb_matrix_step_noeeprom();
        return false;
    }

    rgb_matrix_step_reverse_noeeprom();
    return false;
}
//changes rgb matrix hue with encoder
static bool ProcessEncoderForNumpadLayer(bool clockwise){

    if(clockwise){
        rgb_matrix_increase_hue_noeeprom();
        return false;
    }

    rgb_matrix_decrease_hue_noeeprom();
    return false;
}
//only allows for volume change when in gaming layer
static bool ProcessEncoderForGamingLayer(bool clockwise){
    tap_code(clockwise ? KC_VOLU : KC_VOLD);
    return false;
}

#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {

    switch(get_highest_layer(layer_state|default_layer_state)){
        case _BL:
            return ProcessEncoderForBaseLayer(clockwise, get_mods());
        case _FN:
            return ProcessEncoderForFunctionLayer(clockwise, get_mods());
        case _NUM:
            return ProcessEncoderForNumpadLayer(clockwise);
        case _GAMING:
            return ProcessEncoderForGamingLayer(clockwise);
        default:
            return false;
    }
}
#endif

//qmk callbacks
bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max){
    
    uint8_t layer = get_highest_layer(layer_state|default_layer_state);
    bool isWindowsKeyActive = layer != _GAMING;
    bool isNumpadActive = layer == _NUM;
    bool isFnLayerActive = layer_state_is(_FN);

    setRgbForFnLayer(isFnLayerActive);
    setRgbForLayer(layer);
    setKeyCapsRgb(host_keyboard_led_state().caps_lock, layer);
    setWindowsKeyRgb(isWindowsKeyActive);
    setNumpadRgb(isNumpadActive);

    return false;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record){
    switch (keycode){
        default:
            return true;
    }
}