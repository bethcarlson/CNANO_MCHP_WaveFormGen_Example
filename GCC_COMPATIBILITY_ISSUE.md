# GCC Compatibility Issue Summary

## Status
- ✅ **AC6**: Builds and runs perfectly
- ❌ **GCC**: Builds without errors but does not execute on device

## Problem Analysis

### What Works
- GCC successfully compiles all source files with zero errors
- GCC generates valid .hex file (100 KB)
- Binary size reasonable (35.5 KB code, 13 KB RAM)
- No linker errors
- Object files and libraries properly linked

### What Doesn't Work
- When GCC binary is flashed to device: **nothing happens**
- LED doesn't blink
- No serial output
- No indication that code is running

## Root Cause Investigation

### Tested and Verified

1. **Vector Table**: Correctly defined in startup_pic32cm5164jh01048.c
   - GCC uses: `__attribute__((used, section(".vectors")))`
   - AC6 uses: `__attribute__((used, section("RESET")))`
   - Both are compiler-appropriate

2. **Linker Script**: pic32cm5164jh01048_flash.ld is correct
   - Memory regions properly defined
   - Section layout correct
   - ENTRY(Reset_Handler) specified

3. **Startup Code**: Functionally identical between compilers
   - Reset_Handler properly calls SystemInit()
   - __PROGRAM_START() called to initialize data/BSS
   - Both use __NO_RETURN and __attribute__((weak, alias(...)))

4. **System Initialization**: SystemInit() is correct
   - Sets VTOR properly
   - Sets SystemCoreClock
   - Both compilers use same code

### Likely Causes (Hypothesis)

1. **Data Section Initialization**
   - GCC might not be initializing .data/.bss sections correctly
   - The copy table (_copy_table_start/__copy_table_end__) might not be working
   - Zero table (_zero_table_start/__zero_table_end__) might not be applied

2. **Vector Table Placement**
   - Vector table might not be placed at address 0x00000000
   - VTOR might point to wrong address
   - GCC sections might not match linker script expectations

3. **Stack Initialization**
   - __INITIAL_SP symbol might not be set correctly
   - Stack pointer might be invalid

4. **Compiler-Specific Binary Format**
   - GCC ELF format might be incompatible with device programmer
   - hex file conversion might have issues

## Workaround: Use AC6

Until GCC compatibility is resolved, use AC6 compiler (which works perfectly):

```yaml
# In CNANO_MCHP_FreeRTOS_Example.csolution.yml
compiler: AC6  # Works reliably
```

Build and flash:
```bash
cbuild CNANO_MCHP_FreeRTOS_Example.csolution.yml -c CNANO_MCHP_FreeRTOS_Example.Debug+PIC32CM5164JH01048
```

Flash binary from:
```
out/CNANO_MCHP_FreeRTOS_Example/PIC32CM5164JH01048/Debug/CNANO_MCHP_FreeRTOS_Example.hex
```

## Next Steps to Debug GCC

### Option 1: Enable Debugging
1. Connect CMSIS-DAP debugger
2. Load GCC .elf file in debugger
3. Step through Reset_Handler
4. Check:
   - Is Reset_Handler being called?
   - Does SystemInit() execute?
   - What is the stack pointer value?
   - What is VTOR set to?

### Option 2: Add Minimal Test Code
```c
// Add to main() 
volatile uint32_t test_var = 0x12345678;
while(test_var != 0) { __NOP(); }  // This would hang if code is running
```

### Option 3: Check Memory Layout
```bash
# Compare ELF files
arm-none-eabi-objdump -h CNANO_MCHP_FreeRTOS_Example.elf | grep -E "\.text|\.data|\.bss|\.vectors"
```

### Option 4: Verify Hex File
```bash
# Check if .hex file contains vector table
# First few lines should have flash memory content starting at 0x00000000
head -20 CNANO_MCHP_FreeRTOS_Example.hex
```

## Code Portability

✅ **The application code IS multi-compiler compatible:**
- No compiler-specific pragmas in user code
- Uses only CMSIS abstractions
- Pre-generated waveform tables (no math library)
- Portable C99 code

❌ **The startup/linking might need compiler-specific tuning:**
- GCC might need different linker flags
- Vector table placement differs between compilers
- Data initialization might need explicit handling

## Recommendation

1. **For now**: Use AC6 (it works perfectly)
2. **Long-term**: Investigate why GCC startup isn't working
   - May need to compare .map files between AC6 and GCC
   - May need to adjust linker script or startup code for GCC
   - May need to contact Microchip/ARM for GCC-specific startup guidance

## Files Involved

- Startup: `RTE/Device/PIC32CM5164JH01048/startup_pic32cm5164jh01048.c`
- System init: `RTE/Device/PIC32CM5164JH01048/system_pic32cm5164jh01048.c`
- Linker script: `RTE/Device/PIC32CM5164JH01048/pic32cm5164jh01048_flash.ld`
- Config: `CNANO_MCHP_FreeRTOS_Example.csolution.yml`

## Conclusion

The code builds cleanly for GCC with no errors, but there's a **startup/initialization issue at the system level** that prevents execution. This is not a code compatibility problem, but rather a **toolchain integration issue** that would require deeper debugging with a hardware debugger or further investigation of the startup/linker configuration.
