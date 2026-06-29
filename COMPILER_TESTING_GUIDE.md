# Multi-Compiler Testing Guide

This guide explains how to test your FreeRTOS application with all four supported compilers.

## Supported Compilers

1. **AC6** - Arm Compiler 6 (Keil uVision / ARM Development Studio)
2. **GCC** - GNU Compiler Collection (arm-none-eabi-gcc)
3. **IAR** - IAR Embedded Workbench
4. **CLANG** - LLVM Clang for ARM

## Prerequisites

### Install CMSIS-Toolbox

CMSIS-Toolbox provides the `cbuild` command used to build with different compilers.

**Windows:**
```
Download and install from: https://www.keil.com/download/compiler/
```

**macOS/Linux:**
```bash
# Via package manager or direct download
```

### Install Individual Compilers

Each compiler must be installed separately:

#### AC6 (Arm Compiler 6)
- Comes with Keil uVision (Windows)
- Or download ARM Development Studio
- Ensure `armclang` is in your PATH

#### GCC (arm-none-eabi-gcc)
```bash
# Windows (using choco/winget)
choco install gcc-arm-embedded

# macOS
brew install arm-none-eabi-gcc

# Linux
sudo apt install gcc-arm-none-eabi
```

#### IAR Embedded Workbench
- Download from: https://www.iar.com/
- Ensure `iccarm` is in your PATH
- May require license for compilation

#### CLANG (LLVM)
```bash
# Windows
choco install llvm

# macOS
brew install llvm

# Linux
sudo apt install clang
```

## Quick Start: Automated Testing

### Windows
```cmd
cd path\to\CNANO_MCHP_FreeRTOS_Example2
test_all_compilers.bat
```

### macOS/Linux
```bash
cd path/to/CNANO_MCHP_FreeRTOS_Example2
chmod +x test_all_compilers.sh
./test_all_compilers.sh
```

## Manual Testing: Build One Compiler at a Time

### Build with AC6
```bash
cbuild CNANO_MCHP_FreeRTOS_Example.csolution.yml --compiler AC6
```

### Build with GCC
```bash
cbuild CNANO_MCHP_FreeRTOS_Example.csolution.yml --compiler GCC
```

### Build with IAR
```bash
cbuild CNANO_MCHP_FreeRTOS_Example.csolution.yml --compiler IAR
```

### Build with CLANG
```bash
cbuild CNANO_MCHP_FreeRTOS_Example.csolution.yml --compiler CLANG
```

## Output Files

Each build generates:
- `out/CNANO_MCHP_FreeRTOS_Example/PIC32CM5164JH01048/Debug/` - Debug build
- `out/CNANO_MCHP_FreeRTOS_Example/PIC32CM5164JH01048/Release/` - Release build

Build artifacts include:
- `.elf` - Executable ELF file
- `.hex` - Hex file for flashing
- `.map` - Memory map showing symbol sizes and addresses
- `compile_macros.h` - Compiler-generated macro definitions

## Interpreting Results

### Success Output
```
========================================
Building with GCC...
========================================

[cbuild output indicating successful compilation]

[OK] GCC: SUCCESS
```

### Failed Output
If a compiler fails, check:
1. **build_COMPILER.log** - Detailed error messages
2. **Common issues:**
   - Missing compiler installation
   - Missing required packs (check `.cprj` generation)
   - Compiler-specific syntax errors (rare if code is portable)

## Debugging Build Failures

### Step 1: Check compiler is installed
```bash
# AC6
armclang --version

# GCC
arm-none-eabi-gcc --version

# IAR
iccarm --version

# CLANG
clang --version
```

### Step 2: Check CMSIS-Toolbox
```bash
cbuild --version
```

### Step 3: Check required packs
The solution requires these packs to be installed:
- `Microchip::PIC32CM-JH_DFP`
- `ARM::CMSIS`
- `ARM::CMSIS-Compiler`
- `Microchip::CMSIS-Driver_PIC32CM-JH`
- `Microchip::PIC32CM-JH_Examples`
- `ARM::CMSIS-FreeRTOS`

Install missing packs via:
```bash
cbuild --version  # This should download required packs
```

Or via Keil's pack installer if using uVision.

### Step 4: Review build log
```bash
# Windows
type build_GCC.log

# macOS/Linux
cat build_GCC.log
```

## Common Compiler-Specific Issues

### Issue: "undefined reference to `_xxx_'"
**Cause:** Missing library or CMSIS pack
**Solution:** Verify pack is installed and component is configured

### Issue: "redefinition of `_xxx_'"
**Cause:** Duplicate includes or compiler-specific definitions
**Solution:** Check for missing `#ifndef` guards in headers

### Issue: "incompatible types"
**Cause:** Compiler interpretation of implicit conversions differs
**Solution:** Use explicit casts or compiler-specific pragmas

### Issue: Math functions not found (sin, cos, etc.)
**Cause:** Math library not linked
**Solution:** Add `-lm` to linker flags (usually automatic in CMSIS-Toolbox)

## Verifying Compiler Compatibility

After successful builds with all compilers, verify:

### 1. Binary Size
```bash
# Compare ELF file sizes (should be similar)
ls -lh out/*/PIC32CM5164JH01048/Debug/*.elf
```

### 2. Memory Usage
```bash
# Check .map files for symbol sizes
grep -E "RAM|ROM|Total" out/*/PIC32CM5164JH01048/Debug/*.map
```

### 3. Functional Testing
If device programming is available:
1. Flash with each compiler's binary
2. Verify all features work (LED blink, UART output, etc.)
3. Check for runtime errors or crashes

## Continuous Integration (CI)

To automate this in CI/CD:

### GitHub Actions Example
```yaml
name: Multi-Compiler Test

on: [push, pull_request]

jobs:
  build:
    runs-on: ubuntu-latest
    strategy:
      matrix:
        compiler: [AC6, GCC, IAR, CLANG]
    steps:
      - uses: actions/checkout@v3
      - name: Install CMSIS-Toolbox
        run: |
          # Installation steps for ubuntu
      - name: Build
        run: cbuild CNANO_MCHP_FreeRTOS_Example.csolution.yml --compiler ${{ matrix.compiler }}
```

## References

- [CMSIS-Toolbox Documentation](https://github.com/Open-CMSIS-Pack/devtools/blob/main/docs/)
- [Arm Compiler 6 Documentation](https://developer.arm.com/documentation/100066/0620/)
- [GCC ARM Embedded Documentation](https://developer.arm.com/tools-and-software/open-source-software/gnu-toolchain/gnu-rm/)
- [IAR Embedded Workbench](https://www.iar.com/ewarm/)

## Support

If you encounter build failures specific to a compiler:

1. Check the detailed error in `build_COMPILER.log`
2. Verify compiler installation and PATH configuration
3. Consult compiler-specific documentation
4. Check CMSIS packs are up-to-date
