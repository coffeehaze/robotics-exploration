#include <Arduino.h>
#include <buzzer/buzzer.h>

#define BUZZER_PIN 6
Buzzer bz = Buzzer(BUZZER_PIN);

void setup()
{
    bz.setup();
}

void loop()
{
    bz.buzz_and_blink();
    delay(500);
}