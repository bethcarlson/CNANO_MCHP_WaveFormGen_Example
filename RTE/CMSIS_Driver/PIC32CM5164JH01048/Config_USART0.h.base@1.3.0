#ifndef CONFIG_USART0_H_
#define CONFIG_USART0_H_

#include "Config_USART_Pins.h"

#ifdef __cplusplus
extern "C" {
#endif

/*============================================================================
 * Configuration Wizard
 *==========================================================================*/

// <<< Use Configuration Wizard in Context Menu >>>

// <h> USART0 Configuration

//   <o USART0_DEFAULT_BAUD_RATE> USART0 Default Baud Rate
//     <1200=>    1200
//     <2400=>    2400
//     <4800=>    4800
//     <9600=>    9600
//     <14400=>   14400
//     <19200=>   19200
//     <28800=>   28800
//     <38400=>   38400
//     <57600=>   57600
//     <115200=>  115200
//     <230400=>  230400
//     <460800=>  460800
//   <i> Default: 115200
#define USART0_DEFAULT_BAUD_RATE        115200

//   <o USART0_OPERATING_MODE_SEL> USART0 Operating Mode [FIXED]
//     <1=> Internal Clock (only supported option)
//   <i> FIXED - External Clock mode is not supported by this driver.
#define USART0_OPERATING_MODE_SEL       1

//   <o USART0_COMMUNICATION_MODE_SEL> USART0 Communication Mode [FIXED]
//     <1=> Asynchronous (only supported option)
//   <i> FIXED - Synchronous mode is not supported by this driver.
#define USART0_COMMUNICATION_MODE_SEL   1

//   <o USART0_DATA_SIZE_SEL> USART0 Data Size
//     <1=> 5 Bits
//     <2=> 6 Bits
//     <3=> 7 Bits
//     <4=> 8 Bits
//     <5=> 9 Bits
//   <i> Default: 8 Bits
#define USART0_DATA_SIZE_SEL            4

//   <o USART0_DATA_ORDER_SEL> USART0 Data Order
//     <1=> LSB First
//     <2=> MSB First
//   <i> Default: LSB First
#define USART0_DATA_ORDER_SEL           1

//   <o USART0_STOP_BITS_SEL> USART0 Stop Bits
//     <1=> 1 Stop Bit
//     <2=> 2 Stop Bits
//   <i> Default: 1 Stop Bit
#define USART0_STOP_BITS_SEL            1

//   <o USART0_FRAME_FORMAT_SEL> USART0 Frame Format [FIXED]
//     <1=> Standard Frame (only supported option)
//   <i> FIXED - Custom Frame format is not supported by this driver.
#define USART0_FRAME_FORMAT_SEL         1

// </h>

// <<< end of configuration section >>>

/*============================================================================
 * Derived driver-facing macros
 *
 * The Configuration Wizard above can only edit numeric literals, but
 * Driver_USART0.c passes these macros directly into the SERCOM0_USART_*
 * PLIB calls and therefore needs the real symbolic driver constants.
 * The *_SEL wizard indices are mapped to those constants below.
 *==========================================================================*/

/* USART0 operating mode.
 * Driver options: USART_INT (internal clock), USART_EXT (external clock).
 * NOTE: Only USART_INT is supported by this driver; USART_EXT is not. */
#if (USART0_OPERATING_MODE_SEL == 1)
    #define USART0_OPERATING_MODE       USART_INT
#else
    #error "USART0_OPERATING_MODE_SEL: only Internal Clock (1) is supported."
#endif

/* USART0 communication mode.
 * Driver options: USART_ASYNC_MODE (asynchronous), USART_SYNC_MODE (synchronous).
 * NOTE: Only USART_ASYNC_MODE is supported by this driver; USART_SYNC_MODE is not. */
#if (USART0_COMMUNICATION_MODE_SEL == 1)
    #define USART0_COMMUNICATION_MODE   USART_ASYNC_MODE
#else
    #error "USART0_COMMUNICATION_MODE_SEL: only Asynchronous (1) is supported."
#endif

/* USART0 data size.
 * Driver options: USART_DATA_5_BIT, USART_DATA_6_BIT, USART_DATA_7_BIT,
 *                 USART_DATA_8_BIT, USART_DATA_9_BIT. */
#if   (USART0_DATA_SIZE_SEL == 1)
    #define USART0_DATA_SIZE            USART_DATA_5_BIT
#elif (USART0_DATA_SIZE_SEL == 2)
    #define USART0_DATA_SIZE            USART_DATA_6_BIT
#elif (USART0_DATA_SIZE_SEL == 3)
    #define USART0_DATA_SIZE            USART_DATA_7_BIT
#elif (USART0_DATA_SIZE_SEL == 4)
    #define USART0_DATA_SIZE            USART_DATA_8_BIT
#elif (USART0_DATA_SIZE_SEL == 5)
    #define USART0_DATA_SIZE            USART_DATA_9_BIT
#else
    #error "USART0_DATA_SIZE_SEL: invalid selection (expected 1..5)."
#endif

/* USART0 data order.
 * Driver options: USART_LSB_FIRST, USART_MSB_FIRST. */
#if   (USART0_DATA_ORDER_SEL == 1)
    #define USART0_DATA_ORDER           USART_LSB_FIRST
#elif (USART0_DATA_ORDER_SEL == 2)
    #define USART0_DATA_ORDER           USART_MSB_FIRST
#else
    #error "USART0_DATA_ORDER_SEL: invalid selection (expected 1 or 2)."
#endif

/* USART0 stop bits.
 * Driver options: USART_STOP_1_BIT, USART_STOP_2_BIT. */
#if   (USART0_STOP_BITS_SEL == 1)
    #define USART0_STOP_BITS            USART_STOP_1_BIT
#elif (USART0_STOP_BITS_SEL == 2)
    #define USART0_STOP_BITS            USART_STOP_2_BIT
#else
    #error "USART0_STOP_BITS_SEL: invalid selection (expected 1 or 2)."
#endif

/* USART0 frame format.
 * Driver options: USART_FRAME (standard), USART_FRAME_CUSTOM (custom).
 * NOTE: Only USART_FRAME is supported by this driver; USART_FRAME_CUSTOM is not. */
#if (USART0_FRAME_FORMAT_SEL == 1)
    #define USART0_FRAME_FORMAT         USART_FRAME
#else
    #error "USART0_FRAME_FORMAT_SEL: only Standard Frame (1) is supported."
#endif

#ifdef __cplusplus
}
#endif

#endif /* CONFIG_USART0_H_ */
