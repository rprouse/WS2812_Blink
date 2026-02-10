# ESP32-S3 Test Program

I purchased several ESP32-S3 N16R8 MCU 44Pin 8M PSRAM dev boards. They are not
directly supported by [PlatformIO](https://platformio.org/), so this project adds
[ESP32-S3-DevKitC-1-N16R8.json](https://github.com/shpegun60/ESP32-S3-N16R8) to
the boards folder and configures it in `platformio.ini`.

The code in `main.cpp` is simple code to flash the on-board WS2812 RGB LED on
pin 48 to prove that the compile, upload and monitoring are working.
