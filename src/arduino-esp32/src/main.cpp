#include <Arduino.h>

int esp32Led = 1; // LED_BUILTIN

void setup()
{
    Serial.begin(115200);
    pinMode(esp32Led, OUTPUT);
#ifdef DEBUG
    Serial.println("Setup done");
#endif
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
}

void loop()
{
#ifdef DEBUG
    Serial.println("Start blink");
#endif
    // Hello world!, non blink!
    digitalWrite(esp32Led, HIGH);
    delay(1000);
    digitalWrite(esp32Led, LOW);
    delay(1000);
}
