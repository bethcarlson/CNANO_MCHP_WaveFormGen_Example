#include <stdio.h>
#include "compiler_portability.h"
#include "RTE_Components.h"
#include CMSIS_device_header
#include "cmsis_os2.h"
#include "Driver_GPIO.h"
#include "Driver_USART.h"

extern void app_tasks(void);

extern ARM_DRIVER_GPIO Driver_GPIO;
extern ARM_DRIVER_USART Driver_USART1;

ARM_DRIVER_GPIO *GPIOdrv = &Driver_GPIO;
ARM_DRIVER_USART *USARTdrv = &Driver_USART1;

static void configure_GPIO(void)
{
    GPIOdrv->Setup(19, NULL);    // LED0 = PA19
    GPIOdrv->SetDirection(19, ARM_GPIO_OUTPUT);

    /* PA00 (TX) and PA01 (RX) for SERCOM1, mux D */
    PORT_REGS->GROUP[0].PORT_PINCFG[0] = PORT_PINCFG_PMUXEN_Msk;
    PORT_REGS->GROUP[0].PORT_PINCFG[1] = PORT_PINCFG_PMUXEN_Msk;
    PORT_REGS->GROUP[0].PORT_PMUX[0] =
        (PORT_PMUX_PMUXE_D_Val << PORT_PMUX_PMUXE_Pos) |
        (PORT_PMUX_PMUXO_D_Val << PORT_PMUX_PMUXO_Pos);
}


int main(void)
{
    /* Simple test to verify code is running */
    volatile uint32_t startup_test = 0xDEADBEEF;
    volatile uint32_t i;

    /* Blink LED immediately to prove startup code runs */
    PORT_REGS->GROUP[0].PORT_OUTSET = (1UL << 19);  /* LED on */
    for (i = 0; i < 100000; i++) {}
    PORT_REGS->GROUP[0].PORT_OUTCLR = (1UL << 19);  /* LED off */

    SystemInit();
    SystemCoreClockUpdate();

    /* Enable APB clock for SERCOM1 */
    MCLK_REGS->MCLK_APBCMASK |= MCLK_APBCMASK_SERCOM1_Msk;

    /* Enable GCLK for SERCOM1 core */
    GCLK_REGS->GCLK_PCHCTRL[SERCOM1_GCLK_ID_CORE] =
        GCLK_PCHCTRL_GEN_GCLK0 | GCLK_PCHCTRL_CHEN_Msk;

    configure_GPIO();

    /* Initialize CMSIS-Driver USART1 */
    USARTdrv->Initialize(NULL);
    USARTdrv->PowerControl(ARM_POWER_FULL);
    USARTdrv->Control(
        ARM_USART_MODE_ASYNCHRONOUS |
        ARM_USART_PARITY_NONE       |
        ARM_USART_STOP_BITS_1       |
        ARM_USART_DATA_BITS_8,
        115200
    );
    USARTdrv->Control(ARM_USART_CONTROL_TX, 1);
    USARTdrv->Control(ARM_USART_CONTROL_RX, 1);

    osKernelInitialize();

    /* Create the app thread */
    extern void app_thread(void *arg);
    osThreadNew(app_thread, NULL, NULL);

    osKernelStart();

    for (;;) {
        __WFI();
    }
}
