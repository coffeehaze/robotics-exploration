//
// Created by xoxo on 03/12/22.
//

#include <Arduino.h>

#ifndef BUZZER_H
#define BUZZER_H

class Buzzer
{
private:
    uint8_t buzzer_pin;

public:
    void setup() const;

    void buzz() const;

    void buzz_and_blink() const;

    explicit Buzzer(uint8_t buzzer_pin_);
};

#endif //BUZZER_H
