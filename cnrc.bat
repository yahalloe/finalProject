@echo off

set SOURCE_FILE=main.c library

set EXECUTABLE=main

gcc %SOURCE_FILE%.c -o %EXECUTABLE%

if %errorlevel% neq 0 (
    echo Compilation failed!
    exit /b 1
)

.\%EXECUTABLE%

pause