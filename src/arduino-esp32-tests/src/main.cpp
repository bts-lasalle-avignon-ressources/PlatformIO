#ifdef esp32_test
#include <Arduino.h>
#endif
#include "led.h"

// uint8_t esp32Led = 1; // LED_BUILTIN
uint8_t esp32Led = 16;

Led led(esp32Led);

void setup()
{
    Serial.begin(115200);
#ifdef DEBUG
    Serial.println("Setup start");
#endif
    led.begin();
    led.readState();
#ifdef DEBUG
    Serial.print("Led pin : ");
    Serial.println(led.getPin());
    Serial.print("Led state : ");
    Serial.println(led.getState());
#endif
#ifdef DEBUG
    Serial.println("Setup done");
#endif
}

void loop()
{
    int ledState = 0;

    led.on();
    led.readState();
#ifdef DEBUG
    Serial.print("Led state : ");
    Serial.println(led.getState());
#endif
    delay(1000);

    led.off();
    led.readState();
#ifdef DEBUG
    Serial.print("Led state : ");
    Serial.println(led.getState());
#endif
    delay(1000);
}
