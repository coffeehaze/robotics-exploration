//
// Created by xoxo on 05/12/22.
//

#include "led.h"
#include <Arduino.h>

#define DEFAULT_PIN 13
#define DELAY 50

void LED::setup()
{
    // set default pin
    if (this->led_pin == 0)
    {
        this->led_pin = DEFAULT_PIN;
    }

    // set buzz pin mode to OUTPUT
    pinMode(this->led_pin, OUTPUT);

    // LOW volt LED and Buzzer
    digitalWrite(this->led_pin, LOW);
}

void LED::pin(uint8_t led_pin_)
{
    this->led_pin = led_pin_;
}

void LED::blink() const
{
    // Blinking
    digitalWrite(this->led_pin, HIGH);

    // take a moment for LED HIGH
    delay(DELAY);

    // De-Blinking
    digitalWrite(this->led_pin, LOW);
}
