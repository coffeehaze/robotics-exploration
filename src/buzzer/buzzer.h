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
    uint16_t frequency;

public:
    void setup();

    void pin(uint8_t buzzer_pin);

    void freq(uint16_t freq);

    void buzz() const;

    void buzz_and_blink() const;
};

#endif //BUZZER_H
