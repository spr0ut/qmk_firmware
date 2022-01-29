#pragma once
#include "quantum.h"
#include "version.h"
#include "process_records.h"

#ifdef ENCODER_ENABLE
bool left_encoder_rotated;
bool right_encoder_rotated;
uint16_t encoder_rotated_timer;
#endif

#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _ADJUST 3
// #define _RAISE 4
// #define _ADJUST 5
// #define _NUMPAD 6
