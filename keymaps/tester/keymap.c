#include QMK_KEYBOARD_H

static matrix_row_t last_matrix[MATRIX_ROWS];

void send_num(uint8_t num) {
    if (num == 0) tap_code(KC_0);
    else tap_code(KC_1 + (num - 1));
}

void send_coord(uint8_t r, uint8_t c) {
    int old_mod = get_mods();
    clear_mods(); // Make sure no shift/ctrl is held that might mess up output
    tap_code(KC_R);
    if (r >= 10) { send_num(r / 10); }
    send_num(r % 10);
    tap_code(KC_C);
    if (c >= 10) { send_num(c / 10); }
    send_num(c % 10);
    tap_code(KC_SPACE);
    set_mods(old_mod);
}

void matrix_init_user(void) {
    // Note: matrix_init_user is normally standard, but keyboard post-init might be safer if matrix is not yet initialized.
    // However, usually it's fine. We'll init the arrays here to 0 for safety.
    for (uint8_t r = 0; r < MATRIX_ROWS; r++) {
        last_matrix[r] = matrix_get_row(r);
    }
}

void matrix_scan_user(void) {
    for (uint8_t r = 0; r < MATRIX_ROWS; r++) {
        matrix_row_t current_row = matrix_get_row(r);
        matrix_row_t row_changes = current_row ^ last_matrix[r];
        
        if (row_changes) {
            for (uint8_t c = 0; c < MATRIX_COLS; c++) {
                if (row_changes & (1 << c)) {
                    if (current_row & (1 << c)) { 
                        // Key down event
                        send_coord(r, c);
                    }
                }
            }
            last_matrix[r] = current_row;
        }
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    return false; // Prevent traditional layout events from double-typing
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO
    )
};
