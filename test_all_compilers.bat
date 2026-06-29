@echo off
REM Multi-compiler build test script for Windows
REM Tests code compatibility across AC6, GCC, IAR, and CLANG

setlocal enabledelayedexpansion

set SOLUTION=CNANO_MCHP_FreeRTOS_Example.csolution.yml
set COMPILERS=AC6 GCC IAR CLANG

echo ==========================================
echo Multi-Compiler Compatibility Test
echo ==========================================
echo.

REM Check if cbuild is available
where cbuild >nul 2>&1
if %errorlevel% neq 0 (
    echo ERROR: cbuild not found. Please install CMSIS-Toolbox.
    echo Download from: https://www.keil.com/download/compiler/
    exit /b 1
)

echo Found cbuild version:
cbuild --version
echo.

REM Test each compiler
for %%C in (%COMPILERS%) do (
    echo ==========================================
    echo Building with %%C...
    echo ==========================================

    set START_TIME=!time!

    cbuild "%SOLUTION%" --compiler %%C > build_%%C.log 2>&1

    if !errorlevel! equ 0 (
        echo.
        echo [OK] %%C: SUCCESS
        set RESULT_%%C=OK
    ) else (
        echo.
        echo [FAIL] %%C: FAILED
        set RESULT_%%C=FAIL
    )

    echo.
)

REM Summary
echo ==========================================
echo Summary
echo ==========================================

set FAILED=0
for %%C in (%COMPILERS%) do (
    if "!RESULT_%%C!"=="OK" (
        echo [OK] %%C
    ) else (
        echo [FAIL] %%C
        set FAILED=1
    )
)

echo.

if %FAILED% equ 0 (
    echo All compilers passed!
    exit /b 0
) else (
    echo Some compilers failed. Check build_*.log files for details.
    echo.
    echo Error log files generated:
    dir /b build_*.log 2>nul
    exit /b 1
)
