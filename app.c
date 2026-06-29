#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "RTE_Components.h"
#include CMSIS_device_header
#include "cmsis_os2.h"
#include "Driver_GPIO.h"
#include "plib_gclk.h"
#include "waveform.h"

extern ARM_DRIVER_GPIO *GPIOdrv;
extern int stdin_getchar_nonblocking(void);

#define LED0_PIN 19
#define SW0_PIN  27

static const char *waveform_names[] = {
	"SINE", "SQUARE", "TRIANGLE", "SAWTOOTH",
	"STEP", "TRAPEZOID"
};


void app_thread(void *arg)
{
	uint32_t led_state = 0;
	uint32_t led_tick = 0;
	uint32_t button_last = 1;
	uint32_t button_now;
	waveform_t current_wave = WAVE_SINE;

	(void)arg;

	osDelay(100);
	printf("\r\n=====================================\r\n");
	printf("   WAVEFORM GENERATOR\r\n");
	printf("   Press SW0 to cycle waveforms\r\n");
	printf("=====================================\r\n\r\n");

	/* Setup LED */
	GPIOdrv->Setup(LED0_PIN, NULL);
	GPIOdrv->SetDirection(LED0_PIN, ARM_GPIO_OUTPUT);
	printf("[OK] LED initialized\r\n");

	/* Setup button */
	GPIOdrv->Setup(SW0_PIN, NULL);
	GPIOdrv->SetDirection(SW0_PIN, ARM_GPIO_INPUT);
	printf("[OK] Button initialized\r\n");

	/* Initialize waveform generator */
	printf("[WAIT] Initializing waveform generator...\r\n");
	waveform_init();
	printf("[OK] All 6 waveforms ready\r\n\r\n");

	printf("Serial commands:\r\n");
	printf(" 1=sine   2=square   3=triangle  4=sawtooth\r\n");
	printf(" 5=step   6=trapezoid\r\n\r\n");
	printf("Current: %s\r\n", waveform_names[current_wave]);

	for (;;) {
		/* Update DAC with current waveform */
		waveform_update();

		/* LED blink every 250ms */
		led_tick++;
		if (led_tick >= 250) {
			led_tick = 0;
			led_state ^= 1;
			//GPIOdrv->SetOutput(LED0_PIN, led_state);
		}

		/* Button read - cycle through waveforms */
		button_now = (PORT_REGS->GROUP[0].PORT_IN >> 27) & 1;

		if (button_now == 0 && button_last == 1) {
			current_wave = (current_wave + 1) % WAVE_COUNT;
			waveform_set_type(current_wave);
			printf("\r\n>>> Switched to: %s <<<\r\n", waveform_names[current_wave]);
		}

		button_last = button_now;

		/* Check for serial input (1-6 for waveforms) */
		int ch = stdin_getchar_nonblocking();
		if (ch > 0) {
			int wave_num = ch - '0';
			if (wave_num >= 1 && wave_num <= 6) {
				current_wave = (waveform_t)(wave_num - 1);
				waveform_set_type(current_wave);
				printf("\r\n>>> Switched to: %s <<<\r\n", waveform_names[current_wave]);
			}
		}

		osDelay(1);
	}
}

void app_tasks(void)
{
}
