@echo off
setlocal enabledelayedexpansion
echo Collecting source files...

set "SOURCES="
for /r src %%f in (*.c) do set "SOURCES=!SOURCES! %%f"

set "INCLUDES=-I include"

set "CFLAGS=-std=c99 -Wall -O2"

gcc %SOURCES% %INCLUDES% %CFLAGS% -lssl -lcrypto -o paranoid.exe

if errorlevel 1 (
    echo Build failed!
    exit /b 1
)

echo Build successful
