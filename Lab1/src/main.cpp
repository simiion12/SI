#include <Arduino.h>
#include "led_control.h"
#include <stdio.h>

#define BAUD_RATE 9600
#define MAX_COMMAND_LENGTH 20

char command[MAX_COMMAND_LENGTH];
int commandIndex = 0;

static FILE uartout = {0};

static int uart_putchar(char c, FILE* stream) {
    Serial.write(c);
    return 0;
}

static int uart_getchar(FILE* stream) {
    while (!Serial.available());
    return Serial.read();
}

void setup() {
    Serial.begin(BAUD_RATE);
    
    fdev_setup_stream(&uartout, uart_putchar, uart_getchar, _FDEV_SETUP_RW);
    stdout = &uartout;
    stdin = &uartout;
    
    initializeLed();
    printf("System ready. Available commands: 'led on', 'led off'\n");
}

void processCommand() {
    if (strcmp(command, "led on") == 0) {
        turnOnLed();
        printf("LED turned ON\n");
    }
    else if (strcmp(command, "led off") == 0) {
        turnOffLed();
        printf("LED turned OFF\n");
    }
    else {
        printf("Unknown command\n");
    }
}

void loop() {
    char c;
    if (scanf("%c", &c) == 1) {
        if (c == '\n' || c == '\r') {
            if (commandIndex > 0) {
                command[commandIndex] = '\0';
                processCommand();
                commandIndex = 0;
            }
        }
        else if (commandIndex < MAX_COMMAND_LENGTH - 1) {
            command[commandIndex++] = c;
        }
    }
}