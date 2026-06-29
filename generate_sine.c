/* Generate sine lookup table - run this once to generate values */
#include <stdio.h>
#include <math.h>

#define SINE_SIZE 512
#define AMPLITUDE 0.48f
#define DAC_MAX 1023

int main(void) {
    printf("static const uint16_t sine_lut[] = {\n\t");

    for (int i = 0; i < SINE_SIZE; i++) {
        float angle = (6.283185307f * i) / SINE_SIZE;
        float norm = 0.5f + AMPLITUDE * sinf(angle);
        uint16_t val = (uint16_t)(norm * DAC_MAX);

        printf("%d", val);
        if (i < SINE_SIZE - 1) printf(", ");
        if ((i + 1) % 16 == 0) printf("\n\t");
    }

    printf("\n};\n");
    return 0;
}
