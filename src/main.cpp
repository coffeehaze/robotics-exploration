#include <Arduino.h>
#include <buzzer/buzzer.h>
#include "Servo.h"

Buzzer bz;
Servo main_servo;

int angle = 0;

void setup()
{
    bz.setup();
    bz.pin(6);
    bz.freq(1000);

    main_servo.attach(9);
    main_servo.write(0);
}

void loop()
{
//    // Sweep from 0 to 180 degrees:
//    for (angle = 0; angle <= 180; angle += 1)
//    {
//        main_servo.write(angle);
//    }
//
//    // And back from 180 to 0 degrees:
//    for (angle = 180; angle >= 0; angle -= 1)
//    {
//        main_servo.write(angle);
//    }
//    delay(1000);
    bz.buzz_and_blink();
    delay(300000);
}