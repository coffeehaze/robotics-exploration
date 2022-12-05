//
// Created by xoxo on 05/12/22.
//

#include <Arduino.h>

#ifndef LED_H
#define LED_H

class LED
{
private:
    uint8_t led_pin;

public:
    void setup();

    void pin(uint8_t led_pin);

    void blink() const;
};

#endif //LED_H
