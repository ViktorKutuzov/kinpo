@echo off
setlocal enabledelayedexpansion

set appPath=D:\_Projects\cpp\kinpo\x64\Debug\RomanFactionReducer.exe
set basePath=D:\_Projects\cpp\kinpo\tests

for /L %%i in (1, 1, 10) do (
    set "inputPath=%basePath%\input%%i.txt"
    set "outputPath=%basePath%\output%%i.txt"

    echo Running test case %%i

    "%appPath%" "!inputPath!" "!outputPath!"

    echo Test case %%i completed.
    echo.
)

echo All test cases completed.
pause
