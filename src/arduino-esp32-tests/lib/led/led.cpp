#include "led.h"

Led::Led(uint8_t pin /* = LED_BUILTIN*/) : pin(pin), state(LED_OFF)
{
}

void Led::begin()
{
#ifdef esp32_test
    pinMode(pin, OUTPUT);
#endif
    off();
}

void Led::on()
{
#ifdef esp32_test
    digitalWrite(pin, LED_ON);
#endif
    state = LED_ON;
}

void Led::off()
{
#ifdef esp32_test
    digitalWrite(pin, LED_OFF);
#endif
    state = LED_OFF;
}

void Led::readState()
{
#ifdef esp32_test
    state = digitalRead(pin);
#endif
}

uint8_t Led::getPin() const
{
    return pin;
}

int Led::getState() const
{
    return state;
}
