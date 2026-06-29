#!/bin/bash
# Multi-compiler build test script
# Tests code compatibility across AC6, GCC, IAR, and CLANG

set -e

SOLUTION="CNANO_MCHP_FreeRTOS_Example.csolution.yml"
COMPILERS=("AC6" "GCC" "IAR" "CLANG")
RESULTS=()

echo "=========================================="
echo "Multi-Compiler Compatibility Test"
echo "=========================================="
echo ""

# Check if cbuild is available
if ! command -v cbuild &> /dev/null; then
    echo "❌ ERROR: cbuild not found. Please install CMSIS-Toolbox."
    echo "   Download from: https://www.keil.com/download/compiler/"
    exit 1
fi

echo "Found cbuild version:"
cbuild --version
echo ""

# Test each compiler
for COMPILER in "${COMPILERS[@]}"; do
    echo "=========================================="
    echo "Building with $COMPILER..."
    echo "=========================================="

    START_TIME=$(date +%s)

    if cbuild "$SOLUTION" --compiler "$COMPILER" 2>&1 | tee "build_${COMPILER}.log"; then
        END_TIME=$(date +%s)
        DURATION=$((END_TIME - START_TIME))
        echo "✅ $COMPILER: SUCCESS (${DURATION}s)"
        RESULTS+=("✅ $COMPILER: SUCCESS")
    else
        END_TIME=$(date +%s)
        DURATION=$((END_TIME - START_TIME))
        echo "❌ $COMPILER: FAILED (${DURATION}s)"
        RESULTS+=("❌ $COMPILER: FAILED")
    fi

    echo ""
done

# Summary
echo "=========================================="
echo "Summary"
echo "=========================================="
for result in "${RESULTS[@]}"; do
    echo "$result"
done

# Check if all passed
ALL_PASSED=true
for result in "${RESULTS[@]}"; do
    if [[ $result == *"FAILED"* ]]; then
        ALL_PASSED=false
        break
    fi
done

if [ "$ALL_PASSED" = true ]; then
    echo ""
    echo "🎉 All compilers passed!"
    exit 0
else
    echo ""
    echo "⚠️  Some compilers failed. Check build_*.log files for details."
    exit 1
fi
