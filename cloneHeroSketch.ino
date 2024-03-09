#include "Keyboard.h"

#define BUTTON_PIN_1 A3
#define BUTTON_PIN_2 A0

bool buttonPressed1 = false;
bool buttonPressed2 = false;

void setup() {
  pinMode(LED_BUILTIN_TX, INPUT);
  pinMode(LED_BUILTIN_RX, INPUT);

  pinMode(BUTTON_PIN_1, INPUT_PULLUP);
  pinMode(BUTTON_PIN_2, INPUT_PULLUP);

  Keyboard.begin();

  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);
}

void loop() {
  int buttonState1 = digitalRead(BUTTON_PIN_1);
  int buttonState2 = digitalRead(BUTTON_PIN_2);

  if (buttonState1 == LOW && !buttonPressed1) {
    Keyboard.write('h');
    buttonPressed1 = true;
  } else if (buttonState1 == HIGH) {
    buttonPressed1 = false;
  }

  if (buttonState2 == LOW && !buttonPressed2) {
    Keyboard.write('h');
    buttonPressed2 = true;
  } else if (buttonState2 == HIGH) {
    buttonPressed2 = false;
  }

  delay(50);
}