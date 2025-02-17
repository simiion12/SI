#include "led_control.h"
#include <Arduino.h>

void initializeLed() {
    pinMode(LED_PIN, OUTPUT);
    digitalWrite(LED_PIN, LOW);
}

void turnOnLed() {
    digitalWrite(LED_PIN, HIGH);
}

void turnOffLed() {
    digitalWrite(LED_PIN, LOW);
}

bool getLedState() {
    return digitalRead(LED_PIN);
}