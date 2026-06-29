# Compiler Compatibility Checklist

Use this checklist to verify your code works across all four compilers.

## Code Analysis Phase

Before building, review the following areas of your codebase:

### ✅ Headers and Includes
- [ ] All includes are in `<angle brackets>` for system/CMSIS headers
- [ ] Local includes use `"quotes"`
- [ ] No compiler-specific `#include` paths
- [ ] `RTE_Components.h` and `CMSIS_device_header` used consistently

### ✅ Data Types
- [ ] Using `stdint.h` types: `uint8_t`, `uint16_t`, `uint32_t`, `int32_t`
- [ ] No `int` or `long` without explicit width (`int32_t` preferred)
- [ ] Avoiding compiler-specific types like `__int64` (use `int64_t`)
- [ ] Using `size_t` for sizes/indices
- [ ] Using `bool` from `<stdbool.h>` for booleans

### ✅ Function Attributes
- [ ] `__attribute__((weak))` only used with `#ifdef __GNUC__` guards or CMSIS macros
- [ ] IAR equivalents for weak functions: `#pragma weak`
- [ ] CMSIS standard attributes: `__NO_RETURN`, `__NO_INIT`, etc.
- [ ] Using provided CMSIS attribute macros instead of compiler-specific ones

### ✅ Inline Assembly
- [ ] No inline assembly (portable code preferred)
- [ ] If assembly needed, use CMSIS intrinsics (e.g., `__WFI()`, `__NOP()`)
- [ ] Intrinsics wrapped in appropriate `#ifdef` or CMSIS headers

### ✅ Pragmas
- [ ] All `#pragma` directives are compiler-specific and guarded:
  ```c
  #ifdef __GNUC__
      #pragma GCC diagnostic push
      ...
  #endif
  
  #ifdef __ICCARM__
      #pragma ...
  #endif
  ```
- [ ] No bare pragmas that will fail on other compilers

### ✅ Preprocessor Defines
- [ ] Compiler detection using standard macros:
  - `__ARMCC_VERSION` for AC6/Keil
  - `__GNUC__` for GCC
  - `__ICCARM__` for IAR
  - `__clang__` for CLANG
- [ ] Not relying on compiler-specific predefined macros outside guards

## Build Phase

### ✅ AC6 (Arm Compiler 6)
- [ ] Run: `cbuild CNANO_MCHP_FreeRTOS_Example.csolution.yml --compiler AC6`
- [ ] Build completes without errors
- [ ] Check build_AC6.log for warnings
- [ ] No compiler-specific warnings that block other compilers

### ✅ GCC (arm-none-eabi-gcc)
- [ ] Run: `cbuild CNANO_MCHP_FreeRTOS_Example.csolution.yml --compiler GCC`
- [ ] Build completes without errors
- [ ] Check build_GCC.log for warnings
- [ ] Math library linked (if using `-lm` functions)
- [ ] No "undefined reference" errors for standard functions

### ✅ IAR (IAR Embedded Workbench)
- [ ] Run: `cbuild CNANO_MCHP_FreeRTOS_Example.csolution.yml --compiler IAR`
- [ ] Build completes without errors
- [ ] Check build_IAR.log for warnings
- [ ] No pragmas causing "unknown pragma" warnings
- [ ] Weak function definitions work correctly

### ✅ CLANG (LLVM Clang)
- [ ] Run: `cbuild CNANO_MCHP_FreeRTOS_Example.csolution.yml --compiler CLANG`
- [ ] Build completes without errors
- [ ] Check build_CLANG.log for warnings
- [ ] GCC compatibility pragmas don't cause issues
- [ ] LLVM-specific optimizations don't break code

## Binary Comparison Phase

### ✅ Size Consistency
- [ ] All binaries are similar size (±10% variation is normal)
  ```bash
  ls -lh out/*/PIC32CM5164JH01048/Debug/*.elf
  ```
- [ ] If one compiler significantly larger/smaller, investigate

### ✅ Symbol Tables
- [ ] All expected symbols present in each binary
- [ ] Global functions not optimized away
- [ ] No missing weak symbol definitions

### ✅ Memory Layout
- [ ] Check .map files (in Release build) for reasonable memory usage
- [ ] RAM and ROM sections present and reasonable
- [ ] No overlapping sections

## Runtime Testing Phase (if device available)

### ✅ Functional Verification
- [ ] Flash each compiler's binary to device
- [ ] LED blinks correctly (timing verified)
- [ ] UART output working (115200 baud, correct messages)
- [ ] Button input responsive
- [ ] Waveform output (DAC) producing correct signals
- [ ] FreeRTOS scheduler running (no crashes or hangs)

### ✅ Performance Verification
- [ ] No noticeable timing differences between compilers
- [ ] Waveform frequency consistent across compilers
- [ ] UART baud rate accurate
- [ ] No buffer overruns or dropped characters

## Documentation Phase

### ✅ Update Project Docs
- [ ] Document any compiler-specific workarounds
- [ ] List tested compiler versions
- [ ] Note any performance differences
- [ ] Include compiler selection in build instructions

## Troubleshooting Guide

If build fails for a specific compiler, follow this checklist:

### GCC Failures
- [ ] Verify `arm-none-eabi-gcc --version` shows recent version (9.x or later)
- [ ] Check `-lm` is in linker flags (for math functions)
- [ ] Review warning pragmas - GCC uses `-Wxxxx` format
- [ ] Check for underscores in attribute names (`__attribute__`, not `__attr__`)

### IAR Failures  
- [ ] Verify IAR license is valid (evaluation or commercial)
- [ ] Check `iccarm --version` returns version number
- [ ] Review pragma syntax - IAR uses `#pragma module` format
- [ ] Check weak function declarations use IAR-compatible syntax

### AC6 Failures
- [ ] Verify `armclang --version` works
- [ ] Check Keil uVision or ARM Development Studio installed
- [ ] Ensure Microchip packs installed via uVision
- [ ] Review diagnostics like `-gdwarf-5` flags work in your build

### CLANG Failures
- [ ] Verify `clang --version` shows ARM support
- [ ] Check LLVM version compatibility with ARM targets
- [ ] May need additional flags for ARM Cortex-M target specification
- [ ] Review GCC compatibility - CLANG aims to be GCC-compatible

## Quick Commands Reference

```bash
# Run all tests
./test_all_compilers.sh  # or .bat on Windows

# Build individual compiler
cbuild CNANO_MCHP_FreeRTOS_Example.csolution.yml --compiler AC6
cbuild CNANO_MCHP_FreeRTOS_Example.csolution.yml --compiler GCC
cbuild CNANO_MCHP_FreeRTOS_Example.csolution.yml --compiler IAR
cbuild CNANO_MCHP_FreeRTOS_Example.csolution.yml --compiler CLANG

# Check compiler versions
armclang --version
arm-none-eabi-gcc --version
iccarm --version
clang --version

# Compare binary sizes
ls -lh out/*/PIC32CM5164JH01048/Debug/*.elf

# View build logs
cat build_GCC.log
cat build_IAR.log
# etc.
```

## Notes

- **Optimization levels**: Ensure all compilers use same optimization level for comparison
  - Current setting: `none` (Debug), `balanced` (Release)
  - Adjust if specific optimizations fail on a compiler

- **CMSIS version**: Ensure CMSIS packs are up-to-date
  - Older CMSIS may have incomplete compiler support

- **Architecture**: PIC32CM5164JH01048 is ARMv8-M Cortex-M4
  - All four compilers support this architecture
  - No ARMv7 vs ARMv8 compatibility issues expected

## Success Criteria

✅ **Fully Compatible** when:
- [ ] All four compilers build without errors
- [ ] All binaries have reasonable sizes (within 10% variation)
- [ ] All binaries run correctly on device (if available)
- [ ] No compiler-specific workarounds needed in main code
- [ ] Documentation updated with tested compiler versions

🟡 **Partially Compatible** when:
- [ ] 3 of 4 compilers work fully
- [ ] 1 compiler needs minor workarounds
- [ ] Performance varies but all functional

❌ **Not Compatible** when:
- [ ] 2 or more compilers fail to build
- [ ] Runtime behavior differs significantly
- [ ] Significant code changes needed for each compiler
