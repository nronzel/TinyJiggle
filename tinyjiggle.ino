/*
  TinyJiggle is a mouse jiggler that should work with any ATmega32U4 device.

  This will move the mouse randomly, or if there hasn't been a movement within
  5 minutes it will move the mouse.

  The random chance is around 2% per second, which gives about a 69%-70% chance
  of moving the mouse within a minute.

  The mouse movement is very small. It will move 2 pixels left and then 2
  pixels back and is not noticeable or disruptive.

  Author: nronzel
  Date: 06/2024
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
