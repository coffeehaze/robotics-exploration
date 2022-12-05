//
// Created by xoxo on 05/12/22.
//
#include "ldr.h"
#include <Arduino.h>

#define DEFAULT_PIN A0;

const ldr_sens_val MAX_LVL = 1000;
const ldr_sens_val MIN_LVL = 1;
const ldr_sens_val MAX_PERCENTAGE = 100;
const ldr_sens_val MIN_PERCENTAGE = 0;

void LDR::pin_analog(uint8_t analog_ldr_pin_)
{
    this->analog_ldr_pin = analog_ldr_pin_;
}

LDRData LDR::read()
{
    struct LDRData s{};
    if (this->analog_ldr_pin == 0)
    {
        this->analog_ldr_pin = DEFAULT_PIN;
    }
    ldr_sens_val lvl = analogRead(this->analog_ldr_pin);
    s.percentage = map(lvl, MIN_LVL, MAX_LVL, MAX_PERCENTAGE, MIN_PERCENTAGE);
    return s;
}

void LDRData::call_at_percentage_below(ldr_sens_val t_percentage, callback_f f) const
{
    if (percentage <= t_percentage)
    {
        f();
    }
}

void LDRData::call_at_percentage_above(ldr_sens_val t_percentage, callback_f f) const
{
    if (this->percentage >= t_percentage)
    {
        f();
    }
}

void LDRData::call_at_percentage_exact(ldr_sens_val t_percentage, callback_f f) const
{
    if (this->percentage == t_percentage)
    {
        f();
    }
}
