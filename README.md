# CNANO MCHP FreeRTOS Example

## Overview

This example demonstrates a multi-threaded application using **FreeRTOS** on a Microchip PIC32CM JH microcontroller. It showcases LED control, button handling, and UART communication across three concurrent tasks.

## Features

- **Multi-threaded design** using CMSIS-RTOS2 wrapper API over FreeRTOS
- **Inter-thread communication** via event flags
- **GPIO control** with CMSIS-compliant drivers
- **UART output** using printf with STDOUT retargeting to USART1

## System Configuration

| Parameter | Value |
|-----------|-------|
| Core Clock | 48 MHz (OSC48M) |
| USART | SERCOM1 |

## Pin Assignments

| Pin | Function |
|-----|----------|
| PB17 | LED0 (active-low) |
| PB16 | SW0 (active-low) |
| PA16 | USART TX (SERCOM1 PAD0) |
| PA17 | USART RX (SERCOM1 PAD1) |

## Application Tasks

| Task | Function |
|------|----------|
| LED Task | Toggles LED0 every 250ms |
| Button Task | Monitors SW0 with debouncing (50ms polling) |
| Event Task | Prints UART message on button press |

## Hardware Requirements

- PIC32CM JH Curiosity Nano board
- USB cable for power and serial communication

## Building and Running

1. Open the project in your preferred IDE (Keil MDK, MPLAB X, or VS Code with CMSIS tools)
2. Build the project
3. Program the device
4. Open a serial terminal (115200 baud) to view UART messages
5. Press SW0 to trigger the "Switch Pressed: Hello Microchip FreeRTOS" message

## Configuration

FreeRTOS settings can be modified in:
- `RTE/RTOS/FreeRTOSConfig.h` - Kernel and task configuration
