#ifndef LED_CONTROL_H
#define LED_CONTROL_H

// Definirea pinului LED
#define LED_PIN 13

// Funcții pentru controlul LED-ului
void initializeLed();
void turnOnLed();
void turnOffLed();
bool getLedState();

#endif