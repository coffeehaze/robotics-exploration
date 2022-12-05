//
// Created by xoxo on 05/12/22.
//

#include <Arduino.h>

#ifndef LDR_H
#define LDR_H

typedef unsigned int ldr_sens_val;

typedef void (*callback_f)();

struct LDRData
{
    ldr_sens_val percentage;
    void call_at_percentage_below(ldr_sens_val t_percentage, callback_f f) const;
    void call_at_percentage_above(ldr_sens_val t_percentage, callback_f f) const;
    void call_at_percentage_exact(ldr_sens_val t_percentage, callback_f f) const;
};

class LDR
{
private:
    uint8_t analog_ldr_pin;
public:
    void pin_analog(uint8_t analog_ldr_pin);

    LDRData read();
};

#endif //LDR_H
