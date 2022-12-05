#include <Arduino.h>
#include <buzzer/buzzer.h>
#include <led/led.h>
#include <ldr/ldr.h>

#define LDR_PIN A0
#define LED_PIN 13
#define BUZZER_PIN 6
#define BUZZER_FREQ 100

Buzzer bz;
LED led;
LDR ldr;

void setup()
{
    // initialize serial monitor with baud rate 9600
    Serial.begin(9600);
    Serial.flush();

    // initializing buzzer
    bz.setup();
    bz.pin(BUZZER_PIN);
    bz.freq(BUZZER_FREQ);

    // initializing LED
    led.setup();
    led.pin(LED_PIN);

    // initialize LDR
    ldr.pin_analog(A0);
}

void callback_below()
{
    Serial.println("BELOW 10%");
}

void callback_above()
{
    Serial.println("ABOVE 10%");
}

void loop()
{
    LDRData ldr_d = ldr.read();

    callback_f dfa = &callback_above;
    callback_f dfb = &callback_below;

    ldr_d.call_at_percentage_above(10, dfa);
    ldr_d.call_at_percentage_below(10, dfb);

    delay(1000);
}