#include <Arduino.h>

uint8_t esp32RGBLed = RGB_BUILTIN;

void setup()
{
    Serial.begin(115200);
    Serial.println("Start setup");
    pinMode(esp32RGBLed, OUTPUT);

    Serial.print("CPU freq : ");
    Serial.println(String(ESP.getCpuFreqMHz()) + " MHz");
    Serial.print("CPU cores : ");
    esp_chip_info_t out_info;
    esp_chip_info(&out_info);
    Serial.println(String(out_info.cores));
    Serial.print("Flash size : ");
    Serial.println(String(ESP.getFlashChipSize() / 1000000) + " MB");
    Serial.print("Free RAM : ");
    Serial.println(String((long)ESP.getFreeHeap()) + " bytes");
    Serial.printf("PSRAM : %d MB\n", ESP.getPsramSize() / (1024 * 1024));
    Serial.println("Setup done");
}

void loop()
{
    Serial.println("Start blink");
    // Hello world!, non blink!
    neopixelWrite(esp32RGBLed, RGB_BRIGHTNESS, 0, 0);
    delay(1000);
    neopixelWrite(esp32RGBLed, 0, RGB_BRIGHTNESS, 0);
    delay(1000);
    neopixelWrite(esp32RGBLed, 0, 0, RGB_BRIGHTNESS);
    delay(1000);
    neopixelWrite(esp32RGBLed, 0, 0, 0);
    delay(2000);
}
