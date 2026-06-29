# GCC Build Debugging Guide

## Problem
GCC binary builds successfully but produces no output when flashed to the device (no LED blink, no serial output).

## Solution Steps

### Step 1: Verify You're Flashing the Right Binary
- **AC6 Debug**: `out/CNANO_MCHP_FreeRTOS_Example/PIC32CM5164JH01048/Debug/CNANO_MCHP_FreeRTOS_Example.hex` (Works ✓)
- **GCC Debug**: `out/CNANO_MCHP_FreeRTOS_Example/PIC32CM5164JH01048/Debug/CNANO_MCHP_FreeRTOS_Example.hex` (Being tested)

### Step 2: Compare Binary Sizes
```
AC6:  30,980 bytes code + 7,804 bytes data = ~38.8 KB
GCC: ~31,500 bytes code + ~7,800 bytes data = ~39.3 KB
```
✓ Similar sizes - both should fit in flash

### Step 3: Check Device Connection
1. Device powered on (LED should be visible)
2. USB cable connected (if programming via CMSIS-DAP)
3. Try AC6 binary first to confirm device works
4. Then try GCC binary

### Step 4: Serial Monitor Settings
- **Port**: COM3 or COM4 (check Device Manager)
- **Baud Rate**: 115200
- **Data Bits**: 8
- **Stop Bits**: 1
- **Parity**: None
- **Flow Control**: None

### Step 5: What to Expect
When working correctly, you should see immediately:
```
=====================================
   WAVEFORM GENERATOR
   Press SW0 to cycle waveforms
=====================================

[OK] LED initialized
[OK] Button initialized
[WAIT] Initializing waveform generator...
[OK] All 6 waveforms ready

Serial commands:
 1=sine   2=square   3=triangle  4=sawtooth
 5=step   6=trapezoid

Current: SINE
```

Plus:
- LED0 blinking every 250ms
- DAC waveform output on PA02

### Step 6: If GCC Doesn't Work

**Possible Causes:**
1. **Memory alignment** - GCC may place code/data differently
2. **Startup code** - Compiler-specific initialization
3. **Vector table** - Different linker script handling
4. **Stack/Heap** - Different memory layout

**Debug Strategy:**
1. Flash GCC binary
2. Does LED blink at all? 
   - YES → System running, likely UART issue
   - NO  → System not initializing

### Step 7: Fallback to AC6
If GCC doesn't work:
```yaml
# In CNANO_MCHP_FreeRTOS_Example.csolution.yml
compiler: AC6  # Use AC6 for now
```

Then rebuild and flash:
```bash
cbuild CNANO_MCHP_FreeRTOS_Example.csolution.yml -c CNANO_MCHP_FreeRTOS_Example.Debug+PIC32CM5164JH01048
```

## Technical Notes

### Why GCC Might Have Issues
1. **Debug symbols** - GCC Debug binary is much larger (1.5MB vs AC6's smaller ELF)
2. **Linker script** - Different handling of memory sections
3. **Startup sequence** - Compiler-specific initialization order
4. **Stack placement** - Different default stack configuration

### Binary File Locations After Build
```
Debug/
├── CNANO_MCHP_FreeRTOS_Example.elf    (Executable)
├── CNANO_MCHP_FreeRTOS_Example.hex    (For flashing) ← USE THIS
├── CNANO_MCHP_FreeRTOS_Example.elf.map (Memory map)
└── compile_commands.json
```

### Compiler Selection
```yaml
# Switch between compilers by changing this line:
compiler: AC6      # Use Arm Compiler 6
compiler: GCC      # Use GNU Compiler Collection
compiler: IAR      # Use IAR (when installed)
compiler: CLANG    # Use LLVM Clang (when configured)
```

## Next Steps if GCC Issues Persist

1. **Enable Debug Symbols in GCC**
   - Create `.gdbinit` in project root
   - Connect via debugger interface
   - Step through startup code

2. **Compare Assembly Output**
   ```bash
   arm-none-eabi-objdump -d out/.../Debug/CNANO_MCHP_FreeRTOS_Example.elf > gcc_disasm.asm
   ```

3. **Check Map Files**
   - AC6: `CNANO_MCHP_FreeRTOS_Example.elf.map`
   - GCC: `CNANO_MCHP_FreeRTOS_Example.elf.map`
   - Compare memory layout

4. **Enable Verbose Build**
   ```bash
   cbuild ... -v  # Verbose output
   ```

## References

- CMSIS-Toolbox: https://github.com/Open-CMSIS-Pack/devtools
- ARM Toolchain: https://developer.arm.com/tools-and-software/open-source-software/gnu-toolchain
- GCC for ARM: https://gcc.gnu.org/

## Quick Checklist

- [ ] Flashed correct binary (CNANO_MCHP_FreeRTOS_Example.hex)
- [ ] Device powered on
- [ ] USB connection stable
- [ ] Serial monitor configured (115200 baud)
- [ ] AC6 binary works (baseline)
- [ ] GCC binary tested on device
- [ ] Checked Device Manager for COM port
- [ ] Verified LED circuit (if using external LED)
