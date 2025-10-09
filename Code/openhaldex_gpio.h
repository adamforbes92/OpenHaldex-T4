#ifndef OPENHALDEX_GPIO_H
#define OPENHALDEX_GPIO_H

// Pin assignments
#define GPIO_BT_CONF_BUTTON 4
#define GPIO_BT_RESET_SIGNAL 5
#define GPIO_MODE_BUTTON 17
#define GPIO_MODE_PCB 13
#define GPIO_LED_R 12
#define GPIO_LED_G 10
#define GPIO_LED_B 11

// Function prototype
void mode_button_ISR();

// Functions

void blinkLED(int duration, int flashes, uint8_t R, uint8_t G, uint8_t B) {
  for (int i = 0; i < flashes; i++) {
    analogWrite(GPIO_LED_R, R);
    analogWrite(GPIO_LED_G, G);
    analogWrite(GPIO_LED_B, B);
    delay(duration);
    analogWrite(GPIO_LED_R, 0);
    analogWrite(GPIO_LED_G, 0);
    analogWrite(GPIO_LED_B, 0);
    delay(duration);
  }
}

void init_GPIO() {
  // Disable unwanted Teensy optionals.
  CCM_ANALOG_PLL_AUDIO |= CCM_ANALOG_PLL_AUDIO_POWERDOWN;
  CCM_ANALOG_PLL_VIDEO |= CCM_ANALOG_PLL_VIDEO_POWERDOWN;
  CCM_ANALOG_PLL_ENET |= CCM_ANALOG_PLL_ENET_POWERDOWN;

  // Turn off the power LED.
  pinMode(LED_BUILTIN, OUTPUT);

  // Configure the RGB LED pins as outputs.
  pinMode(GPIO_LED_R, OUTPUT);
  pinMode(GPIO_LED_G, OUTPUT);
  pinMode(GPIO_LED_B, OUTPUT);

  pinMode(GPIO_BT_CONF_BUTTON, INPUT);
  pinMode(GPIO_MODE_PCB, INPUT);

  // If the Bluetooth Configuration button is held at startup, flash the Haldex Generation number.
  if (digitalRead(GPIO_BT_CONF_BUTTON)) {
    DEBUG("Show Haldex Ver.");
    blinkLED(2000, HALDEX_GENERATION, 255, 0, 0);

    // Holding the Bluetooth Configuration button causes the HC-05 to go into AT mode.
    // Reset the HC-05 to the normal mode.
    pinMode(GPIO_BT_CONF_BUTTON, OUTPUT);
    pinMode(GPIO_BT_RESET_SIGNAL, OUTPUT);
    digitalWrite(GPIO_BT_RESET_SIGNAL, LOW);
    digitalWrite(GPIO_BT_CONF_BUTTON, LOW);
    delay(2500);
    pinMode(GPIO_BT_RESET_SIGNAL, INPUT);
    pinMode(GPIO_BT_CONF_BUTTON, INPUT);
  }

  // Attach an interrupt to the Mode button.
  attachInterrupt(GPIO_MODE_BUTTON, mode_button_ISR, HIGH);
}

void show_current_mode_LED() {
  switch (state.mode) {
    case MODE_STOCK:
      analogWrite(GPIO_LED_R, 10);
      analogWrite(GPIO_LED_G, 0);
      analogWrite(GPIO_LED_B, 0);
      break;
    case MODE_FWD:
      analogWrite(GPIO_LED_R, 0);
      analogWrite(GPIO_LED_G, 10);
      analogWrite(GPIO_LED_B, 0);
      break;
    case MODE_5050:
      analogWrite(GPIO_LED_R, 0);
      analogWrite(GPIO_LED_G, 0);
      analogWrite(GPIO_LED_B, 10);
      break;
    case MODE_7525:
      analogWrite(GPIO_LED_R, 0);
      analogWrite(GPIO_LED_G, 5);
      analogWrite(GPIO_LED_B, 5);
      break;
    case MODE_CUSTOM:
      analogWrite(GPIO_LED_R, 5);
      analogWrite(GPIO_LED_G, 0);
      analogWrite(GPIO_LED_B, 5);
      break;
    default:
      break;
  }
}

#endif
