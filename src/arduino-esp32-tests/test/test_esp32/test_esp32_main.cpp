#include <Arduino.h>
#include <unity.h>

#include "led.h" // La classe Led

void setUp(void)
{
    // set stuff up here
}

void tearDown(void)
{
    // clean stuff up here
}

// Constructeur par défaut
void test_unitaire_constructeur_defaut_led()
{
    Led led;

    led.begin();
    TEST_ASSERT_EQUAL_INT8(led.getPin(), LED_BUILTIN);
    TEST_ASSERT_EQUAL_INT(led.getState(), LED_OFF);
}

// Constructeur d'initialisation
void test_unitaire_constructeur_led()
{
    Led led(16);

    led.begin();
    TEST_ASSERT_EQUAL_INT8(led.getPin(), 16);
    TEST_ASSERT_EQUAL_INT(led.getState(), LED_OFF);
}

void test_unitaire_led_on()
{
    Led led(16);

    led.on();
    led.readState();
    TEST_ASSERT_EQUAL_INT(led.getState(), LED_ON);
}

void test_unitaire_led_off()
{
    Led led(16);

    led.off();
    led.readState();
    TEST_ASSERT_EQUAL_INT(led.getState(), LED_OFF);
}

void setup()
{
    UNITY_BEGIN(); // IMPORTANT LINE!
    RUN_TEST(test_unitaire_constructeur_defaut_led);
    RUN_TEST(test_unitaire_constructeur_led);
    RUN_TEST(test_unitaire_led_on);
    RUN_TEST(test_unitaire_led_off);
    UNITY_END(); // stop unit testing
}

void loop()
{
}
