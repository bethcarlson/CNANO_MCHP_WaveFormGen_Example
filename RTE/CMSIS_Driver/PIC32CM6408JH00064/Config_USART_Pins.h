#ifndef CONFIG_USART_PINS_H_
#define CONFIG_USART_PINS_H_

#ifdef  __cplusplus
extern "C" {
#endif

// <<< Use Configuration Wizard in Context Menu >>>

// <e> USART0 Port Configuration
// <i> Enable SERCOM0 USART pin configuration.
#ifndef USART0_PIN_CONFIG_ENABLE
#define USART0_PIN_CONFIG_ENABLE 1
#endif

#ifndef USART0_TX_PAD
//   <o USART0_TX_PAD> USART0 TX PAD Configuration
//     <1=> PAD[0]=TxD, PAD[1]=XCK
//     <2=> PAD[2]=TxD, PAD[3]=XCK
//     <3=> PAD[0]=TxD, PAD[2]=RTS/TE, PAD[3]=CTS
//     <4=> PAD[0]=TxD, PAD[1]=XCK, PAD[2]=RTS/TE
//     <i> Defines the SERCOM PAD used for USART TX.
//     <i> Default: PAD[0]=TxD, PAD[1]=XCK
#define USART0_TX_PAD 1
#endif

#ifndef USART0_RX_PAD
//   <o USART0_RX_PAD> USART0 RX PAD Configuration
//     <1=> SERCOM PAD[0] is used for data reception
//     <2=> SERCOM PAD[1] is used for data reception
//     <3=> SERCOM PAD[2] is used for data reception
//     <4=> SERCOM PAD[3] is used for data reception
//     <i> Defines the SERCOM PAD used for USART RX.
//     <i> Default: SERCOM PAD[1] is used for data reception
#define USART0_RX_PAD 2
#endif
// </e>

// <e> USART1 Port Configuration
// <i> Enable SERCOM1 USART pin configuration.
#ifndef USART1_PIN_CONFIG_ENABLE
#define USART1_PIN_CONFIG_ENABLE 1
#endif

#ifndef USART1_TX_PAD
//   <o USART1_TX_PAD> USART1 TX PAD Configuration
//     <1=> PAD[0]=TxD, PAD[1]=XCK
//     <2=> PAD[2]=TxD, PAD[3]=XCK
//     <3=> PAD[0]=TxD, PAD[2]=RTS/TE, PAD[3]=CTS
//     <4=> PAD[0]=TxD, PAD[1]=XCK, PAD[2]=RTS/TE
//     <i> Defines the SERCOM PAD used for USART TX.
//     <i> Default: PAD[0]=TxD, PAD[1]=XCK
#define USART1_TX_PAD 1
#endif

#ifndef USART1_RX_PAD
//   <o USART1_RX_PAD> USART1 RX PAD Configuration
//     <1=> SERCOM PAD[0] is used for data reception
//     <2=> SERCOM PAD[1] is used for data reception
//     <3=> SERCOM PAD[2] is used for data reception
//     <4=> SERCOM PAD[3] is used for data reception
//     <i> Defines the SERCOM PAD used for USART RX.
//     <i> Default: SERCOM PAD[1] is used for data reception
#define USART1_RX_PAD 2
#endif
// </e>

// <e> USART2 Port Configuration
// <i> Enable SERCOM2 USART pin configuration.
#ifndef USART2_PIN_CONFIG_ENABLE
#define USART2_PIN_CONFIG_ENABLE 1
#endif

#ifndef USART2_TX_PAD
//   <o USART2_TX_PAD> USART2 TX PAD Configuration
//     <1=> PAD[0]=TxD, PAD[1]=XCK
//     <2=> PAD[2]=TxD, PAD[3]=XCK
//     <3=> PAD[0]=TxD, PAD[2]=RTS/TE, PAD[3]=CTS
//     <4=> PAD[0]=TxD, PAD[1]=XCK, PAD[2]=RTS/TE
//     <i> Defines the SERCOM PAD used for USART TX.
//     <i> Default: PAD[0]=TxD, PAD[1]=XCK
#define USART2_TX_PAD 1
#endif

#ifndef USART2_RX_PAD
//   <o USART2_RX_PAD> USART2 RX PAD Configuration
//     <1=> SERCOM PAD[0] is used for data reception
//     <2=> SERCOM PAD[1] is used for data reception
//     <3=> SERCOM PAD[2] is used for data reception
//     <4=> SERCOM PAD[3] is used for data reception
//     <i> Defines the SERCOM PAD used for USART RX.
//     <i> Default: SERCOM PAD[1] is used for data reception
#define USART2_RX_PAD 2
#endif
// </e>

// <e> USART3 Port Configuration
// <i> Enable SERCOM3 USART pin configuration.
#ifndef USART3_PIN_CONFIG_ENABLE
#define USART3_PIN_CONFIG_ENABLE 1
#endif

#ifndef USART3_TX_PAD
//   <o USART3_TX_PAD> USART3 TX PAD Configuration
//     <1=> PAD[0]=TxD, PAD[1]=XCK
//     <2=> PAD[2]=TxD, PAD[3]=XCK
//     <3=> PAD[0]=TxD, PAD[2]=RTS/TE, PAD[3]=CTS
//     <4=> PAD[0]=TxD, PAD[1]=XCK, PAD[2]=RTS/TE
//     <i> Defines the SERCOM PAD used for USART TX.
//     <i> Default: PAD[0]=TxD, PAD[1]=XCK
#define USART3_TX_PAD 1
#endif

#ifndef USART3_RX_PAD
//   <o USART3_RX_PAD> USART3 RX PAD Configuration
//     <1=> SERCOM PAD[0] is used for data reception
//     <2=> SERCOM PAD[1] is used for data reception
//     <3=> SERCOM PAD[2] is used for data reception
//     <4=> SERCOM PAD[3] is used for data reception
//     <i> Defines the SERCOM PAD used for USART RX.
//     <i> Default: SERCOM PAD[1] is used for data reception
#define USART3_RX_PAD 2
#endif
// </e>

// <e> USART4 Port Configuration
// <i> Enable SERCOM4 USART pin configuration.
#ifndef USART4_PIN_CONFIG_ENABLE
#define USART4_PIN_CONFIG_ENABLE 1
#endif

#ifndef USART4_TX_PAD
//   <o USART4_TX_PAD> USART4 TX PAD Configuration
//     <1=> PAD[0]=TxD, PAD[1]=XCK
//     <2=> PAD[2]=TxD, PAD[3]=XCK
//     <3=> PAD[0]=TxD, PAD[2]=RTS/TE, PAD[3]=CTS
//     <4=> PAD[0]=TxD, PAD[1]=XCK, PAD[2]=RTS/TE
//     <i> Defines the SERCOM PAD used for USART TX.
//     <i> Default: PAD[0]=TxD, PAD[1]=XCK
#define USART4_TX_PAD 1
#endif

#ifndef USART4_RX_PAD
//   <o USART4_RX_PAD> USART4 RX PAD Configuration
//     <1=> SERCOM PAD[0] is used for data reception
//     <2=> SERCOM PAD[1] is used for data reception
//     <3=> SERCOM PAD[2] is used for data reception
//     <4=> SERCOM PAD[3] is used for data reception
//     <i> Defines the SERCOM PAD used for USART RX.
//     <i> Default: SERCOM PAD[1] is used for data reception
#define USART4_RX_PAD 2
#endif
// </e>

// <e> USART5 Port Configuration
// <i> Enable SERCOM5 USART pin configuration.
#ifndef USART5_PIN_CONFIG_ENABLE
#define USART5_PIN_CONFIG_ENABLE 1
#endif

#ifndef USART5_TX_PAD
//   <o USART5_TX_PAD> USART5 TX PAD Configuration
//     <1=> PAD[0]=TxD, PAD[1]=XCK
//     <2=> PAD[2]=TxD, PAD[3]=XCK
//     <3=> PAD[0]=TxD, PAD[2]=RTS/TE, PAD[3]=CTS
//     <4=> PAD[0]=TxD, PAD[1]=XCK, PAD[2]=RTS/TE
//     <i> Defines the SERCOM PAD used for USART TX.
//     <i> Default: PAD[0]=TxD, PAD[1]=XCK
#define USART5_TX_PAD 1
#endif

#ifndef USART5_RX_PAD
//   <o USART5_RX_PAD> USART5 RX PAD Configuration
//     <1=> SERCOM PAD[0] is used for data reception
//     <2=> SERCOM PAD[1] is used for data reception
//     <3=> SERCOM PAD[2] is used for data reception
//     <4=> SERCOM PAD[3] is used for data reception
//     <i> Defines the SERCOM PAD used for USART RX.
//     <i> Default: SERCOM PAD[1] is used for data reception
#define USART5_RX_PAD 2
#endif
// </e>

// <e> USART6 Port Configuration
// <i> Enable SERCOM6 USART pin configuration.
#ifndef USART6_PIN_CONFIG_ENABLE
#define USART6_PIN_CONFIG_ENABLE 1
#endif

#ifndef USART6_TX_PAD
//   <o USART6_TX_PAD> USART6 TX PAD Configuration
//     <1=> PAD[0]=TxD, PAD[1]=XCK
//     <2=> PAD[2]=TxD, PAD[3]=XCK
//     <3=> PAD[0]=TxD, PAD[2]=RTS/TE, PAD[3]=CTS
//     <4=> PAD[0]=TxD, PAD[1]=XCK, PAD[2]=RTS/TE
//     <i> Defines the SERCOM PAD used for USART TX.
//     <i> Default: PAD[0]=TxD, PAD[1]=XCK
#define USART6_TX_PAD 1
#endif

#ifndef USART6_RX_PAD
//   <o USART6_RX_PAD> USART6 RX PAD Configuration
//     <1=> SERCOM PAD[0] is used for data reception
//     <2=> SERCOM PAD[1] is used for data reception
//     <3=> SERCOM PAD[2] is used for data reception
//     <4=> SERCOM PAD[3] is used for data reception
//     <i> Defines the SERCOM PAD used for USART RX.
//     <i> Default: SERCOM PAD[1] is used for data reception
#define USART6_RX_PAD 2
#endif
// </e>

// <e> USART7 Port Configuration
// <i> Enable SERCOM7 USART pin configuration.
#ifndef USART7_PIN_CONFIG_ENABLE
#define USART7_PIN_CONFIG_ENABLE 1
#endif

#ifndef USART7_TX_PAD
//   <o USART7_TX_PAD> USART7 TX PAD Configuration
//     <1=> PAD[0]=TxD, PAD[1]=XCK
//     <2=> PAD[2]=TxD, PAD[3]=XCK
//     <3=> PAD[0]=TxD, PAD[2]=RTS/TE, PAD[3]=CTS
//     <4=> PAD[0]=TxD, PAD[1]=XCK, PAD[2]=RTS/TE
//     <i> Defines the SERCOM PAD used for USART TX.
//     <i> Default: PAD[0]=TxD, PAD[1]=XCK
#define USART7_TX_PAD 1
#endif

#ifndef USART7_RX_PAD
//   <o USART7_RX_PAD> USART7 RX PAD Configuration
//     <1=> SERCOM PAD[0] is used for data reception
//     <2=> SERCOM PAD[1] is used for data reception
//     <3=> SERCOM PAD[2] is used for data reception
//     <4=> SERCOM PAD[3] is used for data reception
//     <i> Defines the SERCOM PAD used for USART RX.
//     <i> Default: SERCOM PAD[1] is used for data reception
#define USART7_RX_PAD 2
#endif
// </e>

// <<< end of configuration section >>>

/*----------------------------------------------------------------------------
 * Direct mapping from wizard values to driver config macros
 *----------------------------------------------------------------------------*/

/*
 * The *_PAD_CONFIG macros below are only emitted when the corresponding
 * USARTx_PIN_CONFIG_ENABLE toggle is set. Driver_USARTx.c is linked into
 * the build only for enabled instances, so undefined *_PAD_CONFIG macros
 * for disabled instances never reach the compiler.
 */

#if (USART0_PIN_CONFIG_ENABLE == 1)

/**
 * @def USART0_RX_PAD_CONFIG
 * @brief Macro definition for USART0 RX PAD configuration.
 */
#if (USART0_RX_PAD == 1)
#define USART0_RX_PAD_CONFIG    USART_RX_PAD0
#elif (USART0_RX_PAD == 2)
#define USART0_RX_PAD_CONFIG    USART_RX_PAD1
#elif (USART0_RX_PAD == 3)
#define USART0_RX_PAD_CONFIG    USART_RX_PAD2
#elif (USART0_RX_PAD == 4)
#define USART0_RX_PAD_CONFIG    USART_RX_PAD3
#else
#define USART0_RX_PAD_CONFIG    USART_RX_PAD1
#endif

/**
 * @def USART0_TX_PAD_CONFIG
 * @brief Macro definition for USART0 TX PAD configuration.
 */
#if (USART0_TX_PAD == 1)
#define USART0_TX_PAD_CONFIG    USART_TX_PAD0
#elif (USART0_TX_PAD == 2)
#define USART0_TX_PAD_CONFIG    USART_TX_PAD2
#elif (USART0_TX_PAD == 3)
#define USART0_TX_PAD_CONFIG    USART_TX_PAD0_WITH_RTS_CTS
#elif (USART0_TX_PAD == 4)
#define USART0_TX_PAD_CONFIG    USART_TX_PAD0_WITH_TE
#else
#define USART0_TX_PAD_CONFIG    USART_TX_PAD0
#endif

#endif /* USART0_PIN_CONFIG_ENABLE */

#if (USART1_PIN_CONFIG_ENABLE == 1)

/**
 * @def USART1_RX_PAD_CONFIG
 * @brief Macro definition for USART1 RX PAD configuration.
 */
#if (USART1_RX_PAD == 1)
#define USART1_RX_PAD_CONFIG    USART_RX_PAD0
#elif (USART1_RX_PAD == 2)
#define USART1_RX_PAD_CONFIG    USART_RX_PAD1
#elif (USART1_RX_PAD == 3)
#define USART1_RX_PAD_CONFIG    USART_RX_PAD2
#elif (USART1_RX_PAD == 4)
#define USART1_RX_PAD_CONFIG    USART_RX_PAD3
#else
#define USART1_RX_PAD_CONFIG    USART_RX_PAD1
#endif

/**
 * @def USART1_TX_PAD_CONFIG
 * @brief Macro definition for USART1 TX PAD configuration.
 */
#if (USART1_TX_PAD == 1)
#define USART1_TX_PAD_CONFIG    USART_TX_PAD0
#elif (USART1_TX_PAD == 2)
#define USART1_TX_PAD_CONFIG    USART_TX_PAD2
#elif (USART1_TX_PAD == 3)
#define USART1_TX_PAD_CONFIG    USART_TX_PAD0_WITH_RTS_CTS
#elif (USART1_TX_PAD == 4)
#define USART1_TX_PAD_CONFIG    USART_TX_PAD0_WITH_TE
#else
#define USART1_TX_PAD_CONFIG    USART_TX_PAD0
#endif

#endif /* USART1_PIN_CONFIG_ENABLE */

#if (USART2_PIN_CONFIG_ENABLE == 1)

/**
 * @def USART2_RX_PAD_CONFIG
 * @brief Macro definition for USART2 RX PAD configuration.
 */
#if (USART2_RX_PAD == 1)
#define USART2_RX_PAD_CONFIG    USART_RX_PAD0
#elif (USART2_RX_PAD == 2)
#define USART2_RX_PAD_CONFIG    USART_RX_PAD1
#elif (USART2_RX_PAD == 3)
#define USART2_RX_PAD_CONFIG    USART_RX_PAD2
#elif (USART2_RX_PAD == 4)
#define USART2_RX_PAD_CONFIG    USART_RX_PAD3
#else
#define USART2_RX_PAD_CONFIG    USART_RX_PAD1
#endif

/**
 * @def USART2_TX_PAD_CONFIG
 * @brief Macro definition for USART2 TX PAD configuration.
 */
#if (USART2_TX_PAD == 1)
#define USART2_TX_PAD_CONFIG    USART_TX_PAD0
#elif (USART2_TX_PAD == 2)
#define USART2_TX_PAD_CONFIG    USART_TX_PAD2
#elif (USART2_TX_PAD == 3)
#define USART2_TX_PAD_CONFIG    USART_TX_PAD0_WITH_RTS_CTS
#elif (USART2_TX_PAD == 4)
#define USART2_TX_PAD_CONFIG    USART_TX_PAD0_WITH_TE
#else
#define USART2_TX_PAD_CONFIG    USART_TX_PAD0
#endif

#endif /* USART2_PIN_CONFIG_ENABLE */

#if (USART3_PIN_CONFIG_ENABLE == 1)

/**
 * @def USART3_RX_PAD_CONFIG
 * @brief Macro definition for USART3 RX PAD configuration.
 */
#if (USART3_RX_PAD == 1)
#define USART3_RX_PAD_CONFIG    USART_RX_PAD0
#elif (USART3_RX_PAD == 2)
#define USART3_RX_PAD_CONFIG    USART_RX_PAD1
#elif (USART3_RX_PAD == 3)
#define USART3_RX_PAD_CONFIG    USART_RX_PAD2
#elif (USART3_RX_PAD == 4)
#define USART3_RX_PAD_CONFIG    USART_RX_PAD3
#else
#define USART3_RX_PAD_CONFIG    USART_RX_PAD1
#endif

/**
 * @def USART3_TX_PAD_CONFIG
 * @brief Macro definition for USART3 TX PAD configuration.
 */
#if (USART3_TX_PAD == 1)
#define USART3_TX_PAD_CONFIG    USART_TX_PAD0
#elif (USART3_TX_PAD == 2)
#define USART3_TX_PAD_CONFIG    USART_TX_PAD2
#elif (USART3_TX_PAD == 3)
#define USART3_TX_PAD_CONFIG    USART_TX_PAD0_WITH_RTS_CTS
#elif (USART3_TX_PAD == 4)
#define USART3_TX_PAD_CONFIG    USART_TX_PAD0_WITH_TE
#else
#define USART3_TX_PAD_CONFIG    USART_TX_PAD0
#endif

#endif /* USART3_PIN_CONFIG_ENABLE */

#if (USART4_PIN_CONFIG_ENABLE == 1)

/**
 * @def USART4_RX_PAD_CONFIG
 * @brief Macro definition for USART4 RX PAD configuration.
 */
#if (USART4_RX_PAD == 1)
#define USART4_RX_PAD_CONFIG    USART_RX_PAD0
#elif (USART4_RX_PAD == 2)
#define USART4_RX_PAD_CONFIG    USART_RX_PAD1
#elif (USART4_RX_PAD == 3)
#define USART4_RX_PAD_CONFIG    USART_RX_PAD2
#elif (USART4_RX_PAD == 4)
#define USART4_RX_PAD_CONFIG    USART_RX_PAD3
#else
#define USART4_RX_PAD_CONFIG    USART_RX_PAD1
#endif

/**
 * @def USART4_TX_PAD_CONFIG
 * @brief Macro definition for USART4 TX PAD configuration.
 */
#if (USART4_TX_PAD == 1)
#define USART4_TX_PAD_CONFIG    USART_TX_PAD0
#elif (USART4_TX_PAD == 2)
#define USART4_TX_PAD_CONFIG    USART_TX_PAD2
#elif (USART4_TX_PAD == 3)
#define USART4_TX_PAD_CONFIG    USART_TX_PAD0_WITH_RTS_CTS
#elif (USART4_TX_PAD == 4)
#define USART4_TX_PAD_CONFIG    USART_TX_PAD0_WITH_TE
#else
#define USART4_TX_PAD_CONFIG    USART_TX_PAD0
#endif

#endif /* USART4_PIN_CONFIG_ENABLE */

#if (USART5_PIN_CONFIG_ENABLE == 1)

/**
 * @def USART5_RX_PAD_CONFIG
 * @brief Macro definition for USART5 RX PAD configuration.
 */
#if (USART5_RX_PAD == 1)
#define USART5_RX_PAD_CONFIG    USART_RX_PAD0
#elif (USART5_RX_PAD == 2)
#define USART5_RX_PAD_CONFIG    USART_RX_PAD1
#elif (USART5_RX_PAD == 3)
#define USART5_RX_PAD_CONFIG    USART_RX_PAD2
#elif (USART5_RX_PAD == 4)
#define USART5_RX_PAD_CONFIG    USART_RX_PAD3
#else
#define USART5_RX_PAD_CONFIG    USART_RX_PAD1
#endif

/**
 * @def USART5_TX_PAD_CONFIG
 * @brief Macro definition for USART5 TX PAD configuration.
 */
#if (USART5_TX_PAD == 1)
#define USART5_TX_PAD_CONFIG    USART_TX_PAD0
#elif (USART5_TX_PAD == 2)
#define USART5_TX_PAD_CONFIG    USART_TX_PAD2
#elif (USART5_TX_PAD == 3)
#define USART5_TX_PAD_CONFIG    USART_TX_PAD0_WITH_RTS_CTS
#elif (USART5_TX_PAD == 4)
#define USART5_TX_PAD_CONFIG    USART_TX_PAD0_WITH_TE
#else
#define USART5_TX_PAD_CONFIG    USART_TX_PAD0
#endif

#endif /* USART5_PIN_CONFIG_ENABLE */

#if (USART6_PIN_CONFIG_ENABLE == 1)

/**
 * @def USART6_RX_PAD_CONFIG
 * @brief Macro definition for USART6 RX PAD configuration.
 */
#if (USART6_RX_PAD == 1)
#define USART6_RX_PAD_CONFIG    USART_RX_PAD0
#elif (USART6_RX_PAD == 2)
#define USART6_RX_PAD_CONFIG    USART_RX_PAD1
#elif (USART6_RX_PAD == 3)
#define USART6_RX_PAD_CONFIG    USART_RX_PAD2
#elif (USART6_RX_PAD == 4)
#define USART6_RX_PAD_CONFIG    USART_RX_PAD3
#else
#define USART6_RX_PAD_CONFIG    USART_RX_PAD1
#endif

/**
 * @def USART6_TX_PAD_CONFIG
 * @brief Macro definition for USART6 TX PAD configuration.
 */
#if (USART6_TX_PAD == 1)
#define USART6_TX_PAD_CONFIG    USART_TX_PAD0
#elif (USART6_TX_PAD == 2)
#define USART6_TX_PAD_CONFIG    USART_TX_PAD2
#elif (USART6_TX_PAD == 3)
#define USART6_TX_PAD_CONFIG    USART_TX_PAD0_WITH_RTS_CTS
#elif (USART6_TX_PAD == 4)
#define USART6_TX_PAD_CONFIG    USART_TX_PAD0_WITH_TE
#else
#define USART6_TX_PAD_CONFIG    USART_TX_PAD0
#endif

#endif /* USART6_PIN_CONFIG_ENABLE */

#if (USART7_PIN_CONFIG_ENABLE == 1)

/**
 * @def USART7_RX_PAD_CONFIG
 * @brief Macro definition for USART7 RX PAD configuration.
 */
#if (USART7_RX_PAD == 1)
#define USART7_RX_PAD_CONFIG    USART_RX_PAD0
#elif (USART7_RX_PAD == 2)
#define USART7_RX_PAD_CONFIG    USART_RX_PAD1
#elif (USART7_RX_PAD == 3)
#define USART7_RX_PAD_CONFIG    USART_RX_PAD2
#elif (USART7_RX_PAD == 4)
#define USART7_RX_PAD_CONFIG    USART_RX_PAD3
#else
#define USART7_RX_PAD_CONFIG    USART_RX_PAD1
#endif

/**
 * @def USART7_TX_PAD_CONFIG
 * @brief Macro definition for USART7 TX PAD configuration.
 */
#if (USART7_TX_PAD == 1)
#define USART7_TX_PAD_CONFIG    USART_TX_PAD0
#elif (USART7_TX_PAD == 2)
#define USART7_TX_PAD_CONFIG    USART_TX_PAD2
#elif (USART7_TX_PAD == 3)
#define USART7_TX_PAD_CONFIG    USART_TX_PAD0_WITH_RTS_CTS
#elif (USART7_TX_PAD == 4)
#define USART7_TX_PAD_CONFIG    USART_TX_PAD0_WITH_TE
#else
#define USART7_TX_PAD_CONFIG    USART_TX_PAD0
#endif

#endif /* USART7_PIN_CONFIG_ENABLE */

#ifdef  __cplusplus
}
#endif

#endif /* CONFIG_USART_PINS_H_ */
