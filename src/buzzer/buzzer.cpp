//
// Created by xoxo on 03/12/22.
//

#include "buzzer.h"
#include <Arduino.h>

#define DEFAULT_PIN 3
#define DELAY 50
#define FREQUENCY 2000

void Buzzer::buzz() const
{
    // Buzzing
    tone(this->buzzer_pin, this->frequency);

    // take a moment for LED and Buzzer to HIGH
    delay(0);

    // De-Buzzing
    noTone(this->buzzer_pin);
}

void Buzzer::buzz_and_blink() const
{
    // Buzzing and Beeping
    tone(this->buzzer_pin, this->frequency);
    digitalWrite(LED_BUILTIN, HIGH);

    // take a moment for LED and Buzzer to HIGH
    delay(DELAY);

    // De-Buzzing and De-Beeping
    noTone(this->buzzer_pin);
    digitalWrite(LED_BUILTIN, LOW);
}

void Buzzer::setup()
{
    // set default pin
    if (this->buzzer_pin == 0)
    {
        this->buzzer_pin = DEFAULT_PIN;
    }

    // set LED pin mode to OUTPUT
    pinMode(LED_BUILTIN, OUTPUT);

    // set buzz pin mode to OUTPUT
    pinMode(this->buzzer_pin, OUTPUT);

    // LOW volt LED and Buzzer
    digitalWrite(LED_BUILTIN, LOW);
    digitalWrite(this->buzzer_pin, LOW);
}

void Buzzer::pin(uint8_t buzzer_pin_)
{
    this->buzzer_pin = buzzer_pin_;
    this->frequency = FREQUENCY;
}

void Buzzer::freq(uint16_t freq)
{
    this->frequency = freq;
}
