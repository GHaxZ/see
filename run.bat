@echo off
gcc .\src\main.c .\src\search.c .\src\util.c .\src\browser.c -o .\build\main.exe -I.\src
if %ERRORLEVEL% NEQ 0 (
    echo Compilation failed!
    exit /b %ERRORLEVEL%
)
.\build\main.exe
