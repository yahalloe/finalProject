set SOURCE_FILE=main.c library.c

set EXECUTABLE=main

gcc -Wall -Wimplicit -Werror %SOURCE_FILE% -o  %EXECUTABLE%

if %errorlevel% neq 0 (
    echo Compilation failed!
    exit /b 1
)
%EXECUTABLE%