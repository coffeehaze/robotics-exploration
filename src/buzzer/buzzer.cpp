//
// Created by xoxo on 03/12/22.
//

#include "buzzer.h"
#include <Arduino.h>

#define DELAY 50

Buzzer::Buzzer(uint8_t buzzer_pin_)
{
    buzzer_pin = buzzer_pin_;
}

void Buzzer::buzz() const
{
    tone(buzzer_pin, 100);
    delay(DELAY);
    noTone(buzzer_pin);
}

void Buzzer::buzz_and_blink() const
{
    tone(buzzer_pin, 100);
    digitalWrite(LED_BUILTIN, HIGH);
    delay(DELAY);
    noTone(buzzer_pin);
    digitalWrite(LED_BUILTIN, LOW);
}

void Buzzer::setup() const
{
    pinMode(LED_BUILTIN, OUTPUT);
    pinMode(buzzer_pin, OUTPUT);
    digitalWrite(LED_BUILTIN, LOW);
    digitalWrite(buzzer_pin, LOW);
}

