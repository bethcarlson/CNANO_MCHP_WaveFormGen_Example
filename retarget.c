#include "Driver_USART.h"
#include <string.h>
#include <stdio.h>

extern ARM_DRIVER_USART Driver_USART1;
static ARM_DRIVER_USART *USARTdrv = &Driver_USART1;



int stdout_init(void) {
  return 0;
}

int stdin_init(void) {
  return 0;
}

int stdout_putchar(int ch) {
  uint8_t byte = (uint8_t)ch;
  ARM_USART_STATUS status;

  if (USARTdrv->Send(&byte, 1) == ARM_DRIVER_OK) {
    do {
      status = USARTdrv->GetStatus();
    } while (status.tx_busy);
    return ch;
  }
  return -1;
}

int stdin_getchar(void) {
  uint8_t buf[1];

  if (USARTdrv->Receive(buf, 1) == ARM_DRIVER_OK) {
    while (USARTdrv->GetRxCount() != 1);
    return (int)buf[0];
  }
  return -1;
}

int stdin_getchar_nonblocking(void) {
  static uint8_t ch;
  static int pending = 0;

  if (!pending) {
    if (USARTdrv->Receive(&ch, 1) == ARM_DRIVER_OK) {
      pending = 1;
    } else {
      return -1;
    }
  }

  if (!USARTdrv->GetStatus().rx_busy) {
    pending = 0;
    return (int)ch;
  }

  return -1;
}

int fputc(int ch, FILE *f) {
  return stdout_putchar(ch);
}
