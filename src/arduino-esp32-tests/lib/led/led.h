#ifndef LED_h
#define LED_h

#ifdef esp32_test
#include <Arduino.h>
#else
typedef unsigned char uint8_t;
#endif

#ifndef LED_BUILTIN
#define LED_BUILTIN 1
#endif

#define LED_OFF 0
#define LED_ON  1

class Led
{
  public:
    explicit Led(uint8_t pin = LED_BUILTIN);

    void    begin();
    void    on();
    void    off();
    void    readState();
    uint8_t getPin() const;
    int     getState() const;

  private:
    uint8_t pin;
    int     state;
};

#endif // LED_h