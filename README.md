# CNANO MCHP WaveForm Generator Example

## Overview

A **multi-waveform signal generator** implemented on the Microchip PIC32CM5164JH01048 microcontroller using FreeRTOS. This project demonstrates real-time DAC output, USART communication, GPIO control, and waveform management through button input and serial commands.

The generator produces six different waveforms (sine, square, triangle, sawtooth, step, and trapezoid) at approximately 2 Hz output frequency, selectable via push button or serial commands.

## Features

- **6 Waveform Types**: Sine, Square, Triangle, Sawtooth, Step, and Trapezoid
- **Multi-threaded Design**: FreeRTOS + CMSIS-RTOS2 for concurrent waveform updates and user I/O
- **DAC Output**: 10-bit Digital-to-Analog Converter on PA02
- **Serial Interface**: USART1 at 115200 baud for real-time waveform selection and status display
- **Button Control**: GPIO-based push button (SW0) for waveform cycling
- **LED Feedback**: Visual heartbeat indicator blinking every 250ms
- **AC6/GCC/IAR Support**: Builds with Arm Compiler 6, GCC, and IAR toolchains

## Hardware Requirements

- **Microchip PIC32CM5164JH01048** microcontroller (Curiosity Nano or equivalent)
- USB cable for power and serial communication
- **Logic analyzer or oscilloscope** for viewing DAC output waveforms

## Pin Assignments

| Pin | Function | Mode |
|-----|----------|------|
| PA02 | DAC Output (Waveforms) | Analog |
| PA19 | LED0 (Heartbeat) | GPIO Output |
| PA27 | SW0 (Button) | GPIO Input |
| PA00 | USART1 TX | SERCOM1 Pad 0 |
| PA01 | USART1 RX | SERCOM1 Pad 1 |

## System Configuration

| Parameter | Value |
|-----------|-------|
| Core Clock | 4 MHz (Default) |
| DAC Reference | AVDD (Vcc) |
| DAC Output Range | 0V to Vcc (10-bit resolution) |
| USART Baud Rate | 115200 baud |
| RTOS | FreeRTOS with CMSIS-RTOS2 wrapper |

## Building and Running

### Prerequisites
- CMSIS-Toolbox (cbuild)
- Arm Compiler 6 (AC6), ARM GCC, or IAR Embedded Workbench
- Git

### Build Steps

```bash
# Clone the repository
git clone https://github.com/bethcarlson/CNANO_MCHP_WaveFormGen_Example.git
cd CNANO_MCHP_WaveFormGen_Example

# Build with default compiler (AC6)
cbuild CNANO_MCHP_WaveFormGen_Example.csolution.yml

# Or specify a different compiler
cbuild CNANO_MCHP_WaveFormGen_Example.csolution.yml -c Release

# Program the device
# (Use your IDE or programmer command)
```

### Serial Interface

Connect to the device's serial port at **115200 baud** to:
- View waveform status messages
- Send commands to switch waveforms

#### Serial Commands

| Command | Action |
|---------|--------|
| `1` | Switch to Sine wave |
| `2` | Switch to Square wave |
| `3` | Switch to Triangle wave |
| `4` | Switch to Sawtooth wave |
| `5` | Switch to Step wave |
| `6` | Switch to Trapezoid wave |

### User Interface

- **Push Button (SW0)**: Cycles through waveforms in order
- **LED (PA19)**: Blinks every 250ms (heartbeat indicator)
- **Serial Terminal**: Displays selected waveform and ready status

## Waveform Details

All waveforms are stored as 10-bit lookup tables (0–1023 DAC values) optimized for the device's memory:

| Waveform | Type | Samples | Frequency | Notes |
|----------|------|---------|-----------|-------|
| Sine | Smooth oscillation | 256 | ~2 Hz | Clean sinusoidal output |
| Square | Digital pulse | 512 | Variable | 50% duty cycle |
| Triangle | Linear ramp | 512 | Variable | Up/down symmetry |
| Sawtooth | Continuous ramp | 512 | Variable | Fast rise, instant fall |
| Step | 4-level staircase | 512 | Variable | Discrete amplitude levels |
| Trapezoid | Sloped plateau | 512 | Variable | Rise-hold-fall profile |

## Output Characteristics

- **Update Rate**: 1 kHz (1 sample per millisecond)
- **Output Frequency**: ~2 Hz (varies by waveform size)
- **Resolution**: 10-bit DAC → ~9.8 mV per step (at 10V reference)
- **Ripple**: Minimal due to high sample rate and smooth LUTs

## Project Structure

```
CNANO_MCHP_WaveFormGen_Example/
├── main.c                           # Entry point, FreeRTOS setup
├── app.c                            # Main application thread
├── waveform.c / waveform.h          # Waveform generation engine
├── retarget.c                       # STDOUT/STDIN redirection to USART
├── CNANO_MCHP_WaveFormGen_Example.csolution.yml  # Project configuration
├── CNANO_MCHP_WaveFormGen_Example.cproject.yml   # Build targets
├── RTE/                             # Runtime environment (drivers, configs)
│   ├── Device/                      # Device startup and system files
│   ├── CMSIS_Driver/                # GPIO, USART drivers
│   └── RTOS/                        # FreeRTOS configuration
└── README.md                        # This file
```

## Key Implementation Details

### Waveform Generation

The `waveform_update()` function is called 1000 times per second from the main FreeRTOS thread:

```c
void waveform_update(void) {
    uint16_t len = waveform_lengths[active_wave];
    DAC_WriteData(waveforms[active_wave][wave_idx]);
    wave_idx++;
    if (wave_idx >= len) wave_idx = 0;
}
```

Each waveform's lookup table length is tracked separately to ensure proper cycling without distortion.

### Thread Management

- **Main Thread**: Handles waveform updates, button polling, and serial I/O
- **FreeRTOS Scheduler**: Manages timing with 1ms tick rate
- **CMSIS-RTOS2 Wrapper**: Provides standard OS API

### Startup Flow

1. SystemInit() configures core clock and peripherals
2. GPIO and USART are initialized
3. DAC is configured for external reference mode
4. FreeRTOS kernel starts
5. App thread begins waveform generation

## Troubleshooting

### No waveform output on PA02
- Check DAC is enabled: `DAC_Enable()`
- Verify GCLK routing to DAC
- Confirm PA02 is configured as analog output

### Serial output not appearing
- Verify USART1 is initialized: `USARTdrv->Initialize(NULL)`
- Check baud rate matches terminal (115200)
- Confirm TX/RX pins are correct (PA00/PA01)

### Waveform looks distorted
- Each waveform type now uses its correct lookup table length
- Verify `waveform_lengths[]` array matches your LUT sizes
- Check DAC update frequency is consistent

## Compiler Support

| Compiler | Status | Command |
|----------|--------|---------|
| Arm Compiler 6 (AC6) | ✅ Working | `cbuild ... -c AC6` |
| GCC (arm-none-eabi) | ✅ Supported | `cbuild ... -c GCC` |
| IAR Embedded Workbench | ✅ Supported | `cbuild ... -c IAR` |

## Configuration Files

### FreeRTOS Configuration
Edit `RTE/RTOS/FreeRTOSConfig.h` to adjust:
- Tick rate (default: 1 kHz)
- Heap size
- Task stack sizes

### DAC Configuration
Edit `waveform_init()` in `waveform.c` to adjust:
- Reference voltage
- Output mode (internal/external)

## License

This example is provided as-is for educational and development purposes on Microchip PIC32CM devices.

## Support

For issues or questions:
1. Check the Microchip PIC32CM datasheet
2. Review FreeRTOS documentation
3. Verify hardware connections
4. Check serial terminal output for error messages

---

**Project Repository**: https://github.com/bethcarlson/CNANO_MCHP_WaveFormGen_Example

**Last Updated**: 2026  
**Target Device**: PIC32CM5164JH01048
