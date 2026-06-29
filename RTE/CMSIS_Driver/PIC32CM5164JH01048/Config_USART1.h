#ifndef CONFIG_USART1_H_
#define CONFIG_USART1_H_

#include "Config_USART_Pins.h"

#ifdef __cplusplus
extern "C" {
#endif

/*============================================================================
 * Configuration Wizard
 *==========================================================================*/

// <<< Use Configuration Wizard in Context Menu >>>

// <h> USART1 Configuration

//   <o USART1_DEFAULT_BAUD_RATE> USART1 Default Baud Rate
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
#define USART1_DEFAULT_BAUD_RATE        115200

//   <o USART1_OPERATING_MODE_SEL> USART1 Operating Mode [FIXED]
//     <1=> Internal Clock (only supported option)
//   <i> FIXED - External Clock mode is not supported by this driver.
#define USART1_OPERATING_MODE_SEL       1

//   <o USART1_COMMUNICATION_MODE_SEL> USART1 Communication Mode [FIXED]
//     <1=> Asynchronous (only supported option)
//   <i> FIXED - Synchronous mode is not supported by this driver.
#define USART1_COMMUNICATION_MODE_SEL   1

//   <o USART1_DATA_SIZE_SEL> USART1 Data Size
//     <1=> 5 Bits
//     <2=> 6 Bits
//     <3=> 7 Bits
//     <4=> 8 Bits
//     <5=> 9 Bits
//   <i> Default: 8 Bits
#define USART1_DATA_SIZE_SEL            4

//   <o USART1_DATA_ORDER_SEL> USART1 Data Order
//     <1=> LSB First
//     <2=> MSB First
//   <i> Default: LSB First
#define USART1_DATA_ORDER_SEL           1

//   <o USART1_STOP_BITS_SEL> USART1 Stop Bits
//     <1=> 1 Stop Bit
//     <2=> 2 Stop Bits
//   <i> Default: 1 Stop Bit
#define USART1_STOP_BITS_SEL            1

//   <o USART1_FRAME_FORMAT_SEL> USART1 Frame Format [FIXED]
//     <1=> Standard Frame (only supported option)
//   <i> FIXED - Custom Frame format is not supported by this driver.
#define USART1_FRAME_FORMAT_SEL         1

// </h>

// <<< end of configuration section >>>

/*============================================================================
 * Derived driver-facing macros
 *
 * The Configuration Wizard above can only edit numeric literals, but
 * Driver_USART1.c passes these macros directly into the SERCOM1_USART_*
 * PLIB calls and therefore needs the real symbolic driver constants.
 * The *_SEL wizard indices are mapped to those constants below.
 *==========================================================================*/

/* USART1 operating mode.
 * Driver options: USART_INT (internal clock), USART_EXT (external clock).
 * NOTE: Only USART_INT is supported by this driver; USART_EXT is not. */
#if (USART1_OPERATING_MODE_SEL == 1)
    #define USART1_OPERATING_MODE       USART_INT
#else
    #error "USART1_OPERATING_MODE_SEL: only Internal Clock (1) is supported."
#endif

/* USART1 communication mode.
 * Driver options: USART_ASYNC_MODE (asynchronous), USART_SYNC_MODE (synchronous).
 * NOTE: Only USART_ASYNC_MODE is supported by this driver; USART_SYNC_MODE is not. */
#if (USART1_COMMUNICATION_MODE_SEL == 1)
    #define USART1_COMMUNICATION_MODE   USART_ASYNC_MODE
#else
    #error "USART1_COMMUNICATION_MODE_SEL: only Asynchronous (1) is supported."
#endif

/* USART1 data size.
 * Driver options: USART_DATA_5_BIT, USART_DATA_6_BIT, USART_DATA_7_BIT,
 *                 USART_DATA_8_BIT, USART_DATA_9_BIT. */
#if   (USART1_DATA_SIZE_SEL == 1)
    #define USART1_DATA_SIZE            USART_DATA_5_BIT
#elif (USART1_DATA_SIZE_SEL == 2)
    #define USART1_DATA_SIZE            USART_DATA_6_BIT
#elif (USART1_DATA_SIZE_SEL == 3)
    #define USART1_DATA_SIZE            USART_DATA_7_BIT
#elif (USART1_DATA_SIZE_SEL == 4)
    #define USART1_DATA_SIZE            USART_DATA_8_BIT
#elif (USART1_DATA_SIZE_SEL == 5)
    #define USART1_DATA_SIZE            USART_DATA_9_BIT
#else
    #error "USART1_DATA_SIZE_SEL: invalid selection (expected 1..5)."
#endif

/* USART1 data order.
 * Driver options: USART_LSB_FIRST, USART_MSB_FIRST. */
#if   (USART1_DATA_ORDER_SEL == 1)
    #define USART1_DATA_ORDER           USART_LSB_FIRST
#elif (USART1_DATA_ORDER_SEL == 2)
    #define USART1_DATA_ORDER           USART_MSB_FIRST
#else
    #error "USART1_DATA_ORDER_SEL: invalid selection (expected 1 or 2)."
#endif

/* USART1 stop bits.
 * Driver options: USART_STOP_1_BIT, USART_STOP_2_BIT. */
#if   (USART1_STOP_BITS_SEL == 1)
    #define USART1_STOP_BITS            USART_STOP_1_BIT
#elif (USART1_STOP_BITS_SEL == 2)
    #define USART1_STOP_BITS            USART_STOP_2_BIT
#else
    #error "USART1_STOP_BITS_SEL: invalid selection (expected 1 or 2)."
#endif

/* USART1 frame format.
 * Driver options: USART_FRAME (standard), USART_FRAME_CUSTOM (custom).
 * NOTE: Only USART_FRAME is supported by this driver; USART_FRAME_CUSTOM is not. */
#if (USART1_FRAME_FORMAT_SEL == 1)
    #define USART1_FRAME_FORMAT         USART_FRAME
#else
    #error "USART1_FRAME_FORMAT_SEL: only Standard Frame (1) is supported."
#endif

#ifdef __cplusplus
}
#endif

#endif /* CONFIG_USART1_H_ */
