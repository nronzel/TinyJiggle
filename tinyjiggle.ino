/*
    TinyJiggle
    Mouse jiggle to keep your computer from going idle.

    Works with any ATmega32U4 or SAMD device.

    Author: nronzel
    Date: 06/2024
    https://github.com/nronzel/TinyJiggle
*/

#include <Mouse.h>

const unsigned long MAX_IDLE_TIME = 300000; // 5 minutes in milliseconds

unsigned long lastMoveTime = 0;

void setup() {
    Mouse.begin();
    pinMode(LED_BUILTIN, OUTPUT);
    randomSeed(analogRead(0));
}

void loop() {
    unsigned long currentTime = millis();

    if (currentTime - lastMoveTime > MAX_IDLE_TIME || random(0, 101) < 2) {
        mouseJiggle();
        lastMoveTime = currentTime;
    }
    delay(1000);
}

// Jiggles the mouse and flashes the built-in LED to let you know it was
// triggered.
void mouseJiggle() {
    digitalWrite(LED_BUILTIN, HIGH);
    Mouse.move(2, 0);
    Mouse.move(-2, 0);
    delay(20); // give the LED time to light up
    digitalWrite(LED_BUILTIN, LOW);
}
