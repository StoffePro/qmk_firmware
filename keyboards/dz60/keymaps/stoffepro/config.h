#pragma once

#undef TAPPING_TOGGLE
#define TAPPING_TOGGLE 2

// Turn off RGB when computer goes to sleep
#ifdef RGBLIGHT_ENABLE
#define RGBLIGHT_SLEEP
#endif // RGBLIGHT_ENABLE
