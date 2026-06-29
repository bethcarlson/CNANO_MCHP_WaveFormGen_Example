/*
 * ARMCC startup file for PIC32CM6408JH00064
 *
 * Copyright (c) 2026 Microchip Technology Inc. and its subsidiaries.
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *   https://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */

#include <stdint.h>
#include <stdbool.h>

#include "pic32cm6408jh00064.h"

// Check if DeviceVectors is defined and create a typedef to VECTOR_TABLE_Type
#ifndef DEVICE_VECTORS_DEFINE
    typedef DeviceVectors VECTOR_TABLE_Type; // Defines the toolchain agnostic type of the vector table type defined in the 'pic32cm6408jh00064.h'

    #define DEVICE_VECTORS_DEFINE
#endif


/*---------------------------------------------------------------------------
  External References
 *---------------------------------------------------------------------------*/
extern uint32_t __INITIAL_SP;
extern uint32_t __STACK_LIMIT;
#if defined (__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE == 3U)
extern uint32_t __STACK_SEAL;
#endif

extern __NO_RETURN void __PROGRAM_START(void);

/*---------------------------------------------------------------------------
  Internal References
 *---------------------------------------------------------------------------*/
__NO_RETURN void Reset_Handler  (void);
__NO_RETURN void Default_Handler(void);

/*---------------------------------------------------------------------------
  Exception / Interrupt Handler
 *---------------------------------------------------------------------------*/

/* Cortex-M0PLUS core handlers */
void NonMaskableInt_Handler         (void) __attribute__ ((weak, alias("Default_Handler"))); /* Legacy handler name */
void NMI_Handler                    (void);
void SVCall_Handler                 (void) __attribute__ ((weak, alias("Default_Handler"))); /* Legacy handler name */
void SVC_Handler                    (void);

/* Trampoline functions for backward compatibility */
void __attribute__ ((weak)) NMI_Handler(void) {
    NonMaskableInt_Handler();
}
void __attribute__ ((weak)) SVC_Handler(void) {
    SVCall_Handler();
}

void HardFault_Handler              (void) __attribute__ ((weak, alias("Default_Handler")));
void PendSV_Handler                 (void) __attribute__ ((weak, alias("Default_Handler")));
void SysTick_Handler                (void) __attribute__ ((weak, alias("Default_Handler")));

/* Peripherals handlers */
void SYSTEM_Handler                 ( void ) __attribute__ ((weak, alias("Default_Handler")));
void WDT_Handler                    ( void ) __attribute__ ((weak, alias("Default_Handler")));
void RTC_Handler                    ( void ) __attribute__ ((weak, alias("Default_Handler")));
void EIC_Handler                    ( void ) __attribute__ ((weak, alias("Default_Handler")));
void FREQM_Handler                  ( void ) __attribute__ ((weak, alias("Default_Handler")));
void NVMCTRL_Handler                ( void ) __attribute__ ((weak, alias("Default_Handler")));
void DMAC_Handler                   ( void ) __attribute__ ((weak, alias("Default_Handler")));
void EVSYS_Handler                  ( void ) __attribute__ ((weak, alias("Default_Handler")));
void SERCOM0_Handler                ( void ) __attribute__ ((weak, alias("Default_Handler")));
void SERCOM1_Handler                ( void ) __attribute__ ((weak, alias("Default_Handler")));
void SERCOM2_Handler                ( void ) __attribute__ ((weak, alias("Default_Handler")));
void SERCOM3_Handler                ( void ) __attribute__ ((weak, alias("Default_Handler")));
void TCC0_Handler                   ( void ) __attribute__ ((weak, alias("Default_Handler")));
void TCC1_Handler                   ( void ) __attribute__ ((weak, alias("Default_Handler")));
void TCC2_Handler                   ( void ) __attribute__ ((weak, alias("Default_Handler")));
void TC0_Handler                    ( void ) __attribute__ ((weak, alias("Default_Handler")));
void TC1_Handler                    ( void ) __attribute__ ((weak, alias("Default_Handler")));
void TC2_Handler                    ( void ) __attribute__ ((weak, alias("Default_Handler")));
void TC3_Handler                    ( void ) __attribute__ ((weak, alias("Default_Handler")));
void TC4_Handler                    ( void ) __attribute__ ((weak, alias("Default_Handler")));
void ADC0_Handler                   ( void ) __attribute__ ((weak, alias("Default_Handler")));
void AC_Handler                     ( void ) __attribute__ ((weak, alias("Default_Handler")));
void PTC_Handler                    ( void ) __attribute__ ((weak, alias("Default_Handler")));

/*----------------------------------------------------------------------------
  Exception / Interrupt Vector table
 *----------------------------------------------------------------------------*/

#if defined ( __GNUC__ )
    #pragma GCC diagnostic push
    #pragma GCC diagnostic ignored "-Wpedantic"
#endif

extern const VECTOR_TABLE_Type __VECTOR_TABLE;
const VECTOR_TABLE_Type __VECTOR_TABLE __VECTOR_TABLE_ATTRIBUTE = {
        .pvStack = (void*) (&__INITIAL_SP),       /*     Initial Stack Pointer */



        .pfnReset_Handler              = (void*) Reset_Handler,
        .pfnNMI_Handler                = (void*) NMI_Handler,
        .pfnHardFault_Handler          = (void*) HardFault_Handler,
        .pvReservedC12                 = (void*) (0UL), /* Reserved */
        .pvReservedC11                 = (void*) (0UL), /* Reserved */
        .pvReservedC10                 = (void*) (0UL), /* Reserved */
        .pvReservedC9                  = (void*) (0UL), /* Reserved */
        .pvReservedC8                  = (void*) (0UL), /* Reserved */
        .pvReservedC7                  = (void*) (0UL), /* Reserved */
        .pvReservedC6                  = (void*) (0UL), /* Reserved */
        .pfnSVC_Handler                = (void*) SVC_Handler,
        .pvReservedC4                  = (void*) (0UL), /* Reserved */
        .pvReservedC3                  = (void*) (0UL), /* Reserved */
        .pfnPendSV_Handler             = (void*) PendSV_Handler,
        .pfnSysTick_Handler            = (void*) SysTick_Handler,

        /* Configurable interrupts */
        .pfnSYSTEM_Handler             = (void*) SYSTEM_Handler, /* 0  Main Clock */
        .pfnWDT_Handler                = (void*) WDT_Handler,    /* 1  Watchdog Timer */
        .pfnRTC_Handler                = (void*) RTC_Handler,    /* 2  Real-Time Counter */
        .pfnEIC_Handler                = (void*) EIC_Handler,    /* 3  External Interrupt Controller */
        .pfnFREQM_Handler              = (void*) FREQM_Handler,  /* 4  Frequency Meter */
        .pvReserved5                   = (void*) (0UL),          /* 5  Reserved */
        .pfnNVMCTRL_Handler            = (void*) NVMCTRL_Handler, /* 6  Non-Volatile Memory Controller */
        .pfnDMAC_Handler               = (void*) DMAC_Handler,   /* 7  Direct Memory Access Controller */
        .pfnEVSYS_Handler              = (void*) EVSYS_Handler,  /* 8  Event System Interface */
        .pfnSERCOM0_Handler            = (void*) SERCOM0_Handler, /* 9  Serial Communication Interface */
        .pfnSERCOM1_Handler            = (void*) SERCOM1_Handler, /* 10 Serial Communication Interface */
        .pfnSERCOM2_Handler            = (void*) SERCOM2_Handler, /* 11 Serial Communication Interface */
        .pfnSERCOM3_Handler            = (void*) SERCOM3_Handler, /* 12 Serial Communication Interface */
        .pvReserved13                  = (void*) (0UL),          /* 13 Reserved */
        .pvReserved14                  = (void*) (0UL),          /* 14 Reserved */
        .pvReserved15                  = (void*) (0UL),          /* 15 Reserved */
        .pvReserved16                  = (void*) (0UL),          /* 16 Reserved */
        .pfnTCC0_Handler               = (void*) TCC0_Handler,   /* 17 Timer Counter Control */
        .pfnTCC1_Handler               = (void*) TCC1_Handler,   /* 18 Timer Counter Control */
        .pfnTCC2_Handler               = (void*) TCC2_Handler,   /* 19 Timer Counter Control */
        .pfnTC0_Handler                = (void*) TC0_Handler,    /* 20 Basic Timer Counter */
        .pfnTC1_Handler                = (void*) TC1_Handler,    /* 21 Basic Timer Counter */
        .pfnTC2_Handler                = (void*) TC2_Handler,    /* 22 Basic Timer Counter */
        .pfnTC3_Handler                = (void*) TC3_Handler,    /* 23 Basic Timer Counter */
        .pfnTC4_Handler                = (void*) TC4_Handler,    /* 24 Basic Timer Counter */
        .pfnADC0_Handler               = (void*) ADC0_Handler,   /* 25 Analog Digital Converter */
        .pvReserved26                  = (void*) (0UL),          /* 26 Reserved */
        .pfnAC_Handler                 = (void*) AC_Handler,     /* 27 Analog Comparators */
        .pvReserved28                  = (void*) (0UL),          /* 28 Reserved */
        .pvReserved29                  = (void*) (0UL),          /* 29 Reserved */
        .pfnPTC_Handler                = (void*) PTC_Handler     /* 30 Peripheral Touch Controller */
};

#if defined ( __GNUC__ )
    #pragma GCC diagnostic pop
#endif

/*----------------------------------------------------------------------------
  Reset Handler called on controller reset
 *----------------------------------------------------------------------------*/
__NO_RETURN void Reset_Handler(void)
{
    #if !defined(DISABLE_CMSIS_INIT)
    SystemInit();           /* CMSIS System Initialization */
    #endif /* DISABLE_CMSIS_INIT */

    /* Branch to main function */
    __PROGRAM_START();      /* Enter PreMain (C library entry point) */
}

#if defined(__ARMCC_VERSION) && (__ARMCC_VERSION >= 6010050)
    #pragma clang diagnostic push
    #pragma clang diagnostic ignored "-Wmissing-noreturn"
#endif

/*----------------------------------------------------------------------------
  Default Handler for Exceptions / Interrupts
 *----------------------------------------------------------------------------*/
__NO_RETURN void Default_Handler(void)
{
    while (true) {}
}

#if defined(__ARMCC_VERSION) && (__ARMCC_VERSION >= 6010050)
    #pragma clang diagnostic pop
#endif
