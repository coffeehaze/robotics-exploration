#include <Arduino.h>
#include <buzzer/buzzer.h>


void setup()
{
    Serial.begin(9600);
    pinMode(A0, INPUT);
    pinMode(9, OUTPUT);
    pinMode(3, OUTPUT);
}

void loop()
{
    int ldr_v = analogRead(A0);
    Serial.println(ldr_v);

    if (ldr_v >= 800)
    {
        digitalWrite(9, LOW);
    } else
    {
        digitalWrite(9, HIGH);
    }
}