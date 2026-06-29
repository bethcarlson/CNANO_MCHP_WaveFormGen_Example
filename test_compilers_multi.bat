@echo off
REM Multi-compiler build test script for Windows
REM Tests code compatibility across AC6 and GCC

setlocal enabledelayedexpansion

set SOLUTION=CNANO_MCHP_FreeRTOS_Example.csolution.yml
set COMPILERS=AC6 GCC
set FAILED_COUNT=0
set PASSED_COUNT=0

echo ==========================================
echo Multi-Compiler Compatibility Test
echo ==========================================
echo.

REM Test each compiler
for %%C in (%COMPILERS%) do (
    echo ==========================================
    echo Building with %%C...
    echo ==========================================

    REM Update csolution to use this compiler
    powershell -Command "(gc '%SOLUTION%') -replace 'compiler: AC6|compiler: GCC|compiler: IAR|compiler: CLANG', 'compiler: %%C' | Out-File '%SOLUTION%'"

    REM Clean build
    cbuild "%SOLUTION%" -c CNANO_MCHP_FreeRTOS_Example.Debug+PIC32CM5164JH01048 --clean > NUL 2>&1

    REM Build
    cbuild "%SOLUTION%" -c CNANO_MCHP_FreeRTOS_Example.Debug+PIC32CM5164JH01048 > build_%%C.log 2>&1

    if !errorlevel! equ 0 (
        echo.
        echo [OK] %%C: SUCCESS
        set /a PASSED_COUNT+=1
    ) else (
        echo.
        echo [FAIL] %%C: FAILED
        set /a FAILED_COUNT+=1
        echo.
        echo Error details:
        type build_%%C.log | findstr /I "error undefined"
    )

    echo.
)

REM Reset to AC6
powershell -Command "(gc '%SOLUTION%') -replace 'compiler: AC6|compiler: GCC|compiler: IAR|compiler: CLANG', 'compiler: AC6' | Out-File '%SOLUTION%'"

REM Summary
echo ==========================================
echo Summary
echo ==========================================
echo Passed: %PASSED_COUNT%
echo Failed: %FAILED_COUNT%
echo.

if %FAILED_COUNT% equ 0 (
    echo All compilers passed!
    exit /b 0
) else (
    echo Some compilers failed. Check build_*.log files for details.
    dir /b build_*.log 2>nul
    exit /b 1
)
