/**
 * compiler_portability.h - Portable abstractions for AC6, GCC, IAR, Clang
 * Provides unified macros for all compiler-specific constructs.
 */

#ifndef COMPILER_PORTABILITY_H
#define COMPILER_PORTABILITY_H

#include <stdint.h>

/* ====================================================================
 * COMPILER DETECTION
 * ==================================================================== */

#if defined(__ARMCC_VERSION) && (__ARMCC_VERSION >= 6010050)
  #define COMPILER_AC6        1
  #define COMPILER_GCC        0
  #define COMPILER_IAR        0
  #define COMPILER_CLANG      0
#elif defined(__GNUC__) && !defined(__ICCARM__)
  #define COMPILER_AC6        0
  #define COMPILER_GCC        1
  #define COMPILER_IAR        0
  #define COMPILER_CLANG      (__clang__)
#elif defined(__ICCARM__)
  #define COMPILER_AC6        0
  #define COMPILER_GCC        0
  #define COMPILER_IAR        1
  #define COMPILER_CLANG      0
#else
  #error "Unsupported compiler. Please use AC6, GCC, IAR, or Clang."
#endif

/* ====================================================================
 * WEAK SYMBOLS & ALIASES
 * AC6/GCC/Clang: use __attribute__((weak, alias))
 * IAR: use #pragma weak
 * ==================================================================== */

#if defined(__ICCARM__)
  /* IAR: Use pragma before the symbol declaration */
  #define WEAK_FUNCTION(func_name, alias_name) \
    _Pragma(#func_name " = " #alias_name) \
    void func_name(void)

  #define WEAK_SYMBOL(symbol)  \
    _Pragma(#symbol)
#else
  /* AC6/GCC/Clang: Use __attribute__ */
  #define WEAK_FUNCTION(func_name, alias_name) \
    void func_name(void) __attribute__((weak, alias(#alias_name)))

  #define WEAK_SYMBOL(symbol) \
    __attribute__((weak)) symbol
#endif

/* ====================================================================
 * NORETURN ATTRIBUTE
 * ==================================================================== */

#if defined(__ICCARM__)
  #define NORETURN  __noreturn
#else
  /* AC6/GCC/Clang support _Noreturn (C11) or __attribute__((noreturn)) */
  #define NORETURN  __attribute__((noreturn))
#endif

/* ====================================================================
 * SECTION PLACEMENT ATTRIBUTES
 * ==================================================================== */

#if defined(__ICCARM__)
  /* IAR: use __root and @ syntax */
  #define SECTION_VECTORS     __root __attribute__((section(".intvec")))
  #define SECTION(name)       __attribute__((section(#name)))
#elif defined(__ARMCC_VERSION) && (__ARMCC_VERSION >= 6010050)
  /* AC6: use __attribute__((section)) with scatter file reference */
  #define SECTION_VECTORS     __attribute__((section("RESET")))
  #define SECTION(name)       __attribute__((section(#name)))
#else
  /* GCC/Clang: standard __attribute__((section)) */
  #define SECTION_VECTORS     __attribute__((section(".vectors")))
  #define SECTION(name)       __attribute__((section(#name)))
#endif

/* ====================================================================
 * PACKED & ALIGNED STRUCTURES
 * ==================================================================== */

#if defined(__ICCARM__)
  #define PACKED      __packed
  #define ALIGNED(n)  __attribute__((aligned(n)))
#else
  /* AC6/GCC/Clang */
  #define PACKED      __attribute__((packed))
  #define ALIGNED(n)  __attribute__((aligned(n)))
#endif

/* ====================================================================
 * INLINE & FORCE-INLINE
 * ==================================================================== */

#if defined(__ICCARM__)
  #define INLINE      inline
  #define FORCE_INLINE __inline
#elif defined(__ARMCC_VERSION) && (__ARMCC_VERSION >= 6010050)
  /* AC6 respects 'inline' as hint but doesn't guarantee */
  #define INLINE      inline
  #define FORCE_INLINE __attribute__((always_inline)) inline
#else
  /* GCC/Clang */
  #define INLINE      inline
  #define FORCE_INLINE __attribute__((always_inline)) inline
#endif

/* ====================================================================
 * LIKELY/UNLIKELY BRANCH HINTS
 * ==================================================================== */

#if defined(__ICCARM__)
  /* IAR doesn't support branch hints */
  #define LIKELY(x)   (x)
  #define UNLIKELY(x) (x)
#else
  /* AC6/GCC/Clang */
  #define LIKELY(x)   __builtin_expect(!!(x), 1)
  #define UNLIKELY(x) __builtin_expect(!!(x), 0)
#endif

/* ====================================================================
 * VOLATILE MEMORY BARRIERS
 * ==================================================================== */

#if defined(__ICCARM__)
  #define MEMORY_BARRIER()  __iar_builtin_ISB()
#else
  /* AC6/GCC/Clang: use GCC builtins */
  #define MEMORY_BARRIER()  __asm__ volatile ("" ::: "memory")
#endif

/* ====================================================================
 * PRAGMA DIAGNOSTIC CONTROL
 * Suppress/restore compiler warnings portably
 * ==================================================================== */

#if defined(__ICCARM__)
  #define PRAGMA_DIAG_PUSH()
  #define PRAGMA_DIAG_POP()
  #define PRAGMA_DIAG_IGNORE_PEDANTIC()
#elif defined(__ARMCC_VERSION) && (__ARMCC_VERSION >= 6010050)
  /* AC6 is Clang-based, use clang pragmas */
  #define PRAGMA_DIAG_PUSH()   _Pragma("clang diagnostic push")
  #define PRAGMA_DIAG_POP()    _Pragma("clang diagnostic pop")
  #define PRAGMA_DIAG_IGNORE_PEDANTIC() _Pragma("clang diagnostic ignored \"-Wpedantic\"")
#else
  /* GCC/Clang */
  #define PRAGMA_DIAG_PUSH()   _Pragma("GCC diagnostic push")
  #define PRAGMA_DIAG_POP()    _Pragma("GCC diagnostic pop")
  #define PRAGMA_DIAG_IGNORE_PEDANTIC() _Pragma("GCC diagnostic ignored \"-Wpedantic\"")
#endif

/* ====================================================================
 * BUILT-IN FUNCTIONS (Atomics, Intrinsics)
 * ==================================================================== */

#if defined(__ICCARM__)
  #include <intrinsics.h>
  #define ISB()  __iar_builtin_ISB()
  #define DSB()  __iar_builtin_DSB()
  #define DMB()  __iar_builtin_DMB()
#else
  /* AC6/GCC/Clang: ARM CMSIS-defined intrinsics */
  #define ISB()  __asm__ volatile ("isb" ::: "memory")
  #define DSB()  __asm__ volatile ("dsb" ::: "memory")
  #define DMB()  __asm__ volatile ("dmb" ::: "memory")
#endif

/* ====================================================================
 * COMPILER VERSION STRING (for diagnostics)
 * ==================================================================== */

#if defined(__ICCARM__)
  #define COMPILER_NAME "IAR Embedded Workbench"
#elif defined(__ARMCC_VERSION) && (__ARMCC_VERSION >= 6010050)
  #define COMPILER_NAME "ARM Compiler 6 (AC6/Clang)"
#elif defined(__GNUC__)
  #define COMPILER_NAME "GNU GCC"
#else
  #define COMPILER_NAME "Unknown Compiler"
#endif

#endif /* COMPILER_PORTABILITY_H */
