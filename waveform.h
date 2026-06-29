#ifndef WAVEFORM_H
#define WAVEFORM_H

#include <stdint.h>

typedef enum {
    WAVE_SINE = 0,
    WAVE_SQUARE,
    WAVE_TRIANGLE,
    WAVE_SAWTOOTH,
    WAVE_STEP,
    WAVE_TRAPEZOID,
    WAVE_COUNT
} waveform_t;

void waveform_init(void);
void waveform_update(void);
void waveform_set_type(waveform_t type);
waveform_t waveform_get_type(void);

#endif
