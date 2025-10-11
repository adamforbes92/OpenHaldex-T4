#ifndef OPENHALDEX_BLUETOOTH_H
#define OPENHALDEX_BLUETOOTH_H

// Settings
#define BT Serial2
#define BT_PACKET_END_BYTE 0xFF
#define BT_TIMEOUT_MS 3000

// Opcodes
#define APP_MSG_MODE 0
#define APP_MSG_STATUS 1
#define APP_MSG_CUSTOM_DATA 2
#define APP_MSG_CUSTOM_CTRL 3
#define APP_MSG_IS_SCREEN 4

// CUSTOM_CTRL sub-opcodes
#define DATA_CTRL_CHECK_LOCKPOINTS 0
#define DATA_CTRL_CLEAR 1
#define DATA_CTRL_CHECK_MODE 2
#define DATA_CTRL_RECONNECT_BT 3

bool reset_CAN();

// HC-05 configuration commands
const char *AT_commands[] = {
  "AT",
  "AT+UART=19200,0,0",
  "AT+NAME=OpenHaldexT4",
  "AT+ROLE=0",
  "AT+CMODE=0",
  "AT+CLASS=0",
  "AT+RMAAD",
  "AT+RESET"
};

// Variables
unsigned long last_bt_transmission_ms = 0;
bool bluetooth_connected = false;
bool connected_to_bluetooth_screen = false;
bool custom_mode_available = false;

// Functions

void config_BT() {
  DEBUG("Configuring Bluetooth");

  // Turn the LED off (the HC-05 uses a lot of current on setup).
  digitalWrite(GPIO_LED_R, LOW);
  digitalWrite(GPIO_LED_G, LOW);
  digitalWrite(GPIO_LED_B, LOW);

  // Put the HC-05 in pairing mode.
  pinMode(GPIO_BT_CONF_BUTTON, OUTPUT);
  pinMode(GPIO_BT_RESET_SIGNAL, OUTPUT);
  digitalWrite(GPIO_BT_RESET_SIGNAL, LOW);
  digitalWrite(GPIO_BT_CONF_BUTTON, HIGH);
  // Flashing the LED takes 625*2*4=5000ms. Did you mean for it to take 2500ms?
  blinkLED(625, 4, 10, 0, 0);
  pinMode(GPIO_BT_RESET_SIGNAL, INPUT);
  delay(2500);

  // Reconfigure the serial port with the baud rate necessary for HC-05 AT commands.
  BT.end();
  BT.begin(38400);

  // Send each AT command from the array.
  for (size_t i = 0; i < ARRAYSIZE(AT_commands); i++) {
    DEBUG("HC-05 AT: %s", AT_commands[i]);
    BT.println(AT_commands[i]);

    // Indicate the progress through the LED.
    blinkLED(312, 1, 10, 0, 0);
  }

  // Wait for the HC-05 to respond.
  while (!BT.available())
    ;

  // Read the response.
  static uint8_t rx_buffer[128];
  BT.readBytesUntil('\n', rx_buffer, ARRAYSIZE(rx_buffer));

  // Put the HC-05 in normal mode.
  pinMode(GPIO_BT_RESET_SIGNAL, INPUT);
  pinMode(GPIO_BT_CONF_BUTTON, OUTPUT);  // Config is left as an output?
  digitalWrite(GPIO_BT_CONF_BUTTON, LOW);
  delay(BT_TIMEOUT_MS);

  // Reconfigure the serial port with the baud rate necessary for normal Bluetooth communication.
  BT.end();
  BT.begin(19200);

  DEBUG("Bluetooth done pairing");
}

bool bt_send_status(void *params) {
  static bt_packet_t packet;

  // Update the Bluetooth screen.
  if (connected_to_bluetooth_screen) {
    // Fill the packet with data.
    packet.len = 10;
    packet.data[0] = APP_MSG_STATUS;
    packet.data[1] = 0;
    packet.data[2] = received_haldex_engagement;
    packet.data[3] = (uint8_t)lock_target;
    packet.data[4] = received_vehicle_speed;
    packet.data[5] = state.mode_override;
    packet.data[6] = (uint8_t)state.mode;
    packet.data[7] = (uint8_t)received_pedal_value;
    packet.data[8] = (SOFTWARE_VERSION & 0xFF);
    packet.data[9] = BT_PACKET_END_BYTE;

    // Send the packet.
    BT.write(packet.data, packet.len);
  } else {  // Update the Bluetooth app.
    // Fill the packet with data.
    packet.len = 6;
    packet.data[0] = APP_MSG_STATUS;
    packet.data[1] = 0;
    packet.data[2] = received_haldex_engagement;
    packet.data[3] = (uint8_t)lock_target;
    packet.data[4] = received_vehicle_speed;
    packet.data[5] = BT_PACKET_END_BYTE;

    // If any of the bytes (except for the last byte) looks like the "packet end" byte, change them.
    for (uint8_t i = 0; i < packet.len - 1; i++) {
      if (packet.data[i] == BT_PACKET_END_BYTE) {
        packet.data[i]--;
      }
    }

    // Send the packet.
    BT.write(packet.data, packet.len);
  }

  return true;
}

void parse_bt_packet(const bt_packet_t &rx_packet) {
  // Store the current time, to be able to gauge whether the Bluetooth connection is active.
  last_bt_transmission_ms = millis();

  // Parse the packet depending on the message type (first byte).
  switch (rx_packet.data[0]) {
    // Got a request to change the current mode
    case APP_MSG_MODE:
      {
        // If the requested mode is valid, apply it.
        if (rx_packet.data[1] < (uint8_t)openhaldex_mode_t_MAX) {
          state.mode = (openhaldex_mode_t)rx_packet.data[1];
        }
        // For invalid values, fall back to STOCK mode.
        else {
          state.mode = MODE_STOCK;
        }

        // Apply the requested pedal threshold.
        state.pedal_threshold = rx_packet.data[2];

        // In FWD mode, reset the lock target.
        if (state.mode == MODE_FWD) {
          lock_target = 0;
        }

        // If the phone app requested CUSTOM mode, lockpoints will be sent, so the mode is available.
        if (state.mode == MODE_CUSTOM) {
          custom_mode_available = true;
        } else {
          custom_mode_available = false;
        }
        reset_CAN();

        DEBUG("[APP_MSG_MODE] Mode:%s, PedalThreshold:%d",
              get_openhaldex_mode_string(state.mode),
              state.pedal_threshold);
      }
      break;

    // Got a custom lockpoint definition
    case APP_MSG_CUSTOM_DATA:
      {
        // Ensure the specified array index is valid.
        uint8_t custom_lockpoint_index = rx_packet.data[1];
        if (custom_lockpoint_index < CUSTOM_LOCK_POINTS_MAX_COUNT) {
          // Store the received data.
          state.custom_mode.lockpoints[custom_lockpoint_index].speed = rx_packet.data[2];
          state.custom_mode.lockpoints[custom_lockpoint_index].lock = rx_packet.data[3];
          state.custom_mode.lockpoints[custom_lockpoint_index].intensity = rx_packet.data[4];

          // Set the bit corresponding to the lockpoint in the bitfield.
          if (custom_lockpoint_index > 6)  // why is the MSB unused in the low byte?
          {
            state.custom_mode.lockpoint_bitfield_high_byte |= (1 << (custom_lockpoint_index - 7));
          } else {
            state.custom_mode.lockpoint_bitfield_low_byte |= (1 << custom_lockpoint_index);
          }

          // Increment the counter.
          state.custom_mode.lockpoint_count++;

          DEBUG("[LOCKPOINT %d] Bitfield:%02X%02X, Total:%d",
                custom_lockpoint_index,
                state.custom_mode.lockpoint_bitfield_high_byte,
                state.custom_mode.lockpoint_bitfield_low_byte,
                state.custom_mode.lockpoint_count);
        }
      }
      break;

    // Got a request to perform a special action
    case APP_MSG_CUSTOM_CTRL:
      {
        static bt_packet_t tx_packet;
        switch (rx_packet.data[1]) {
          // Got a request to check the defined lockpoints
          case DATA_CTRL_CHECK_LOCKPOINTS:
            tx_packet.len = 5;
            tx_packet.data[0] = APP_MSG_CUSTOM_CTRL;
            tx_packet.data[1] = DATA_CTRL_CHECK_LOCKPOINTS;
            tx_packet.data[2] = state.custom_mode.lockpoint_bitfield_low_byte;
            tx_packet.data[3] = state.custom_mode.lockpoint_bitfield_high_byte;
            tx_packet.data[4] = BT_PACKET_END_BYTE;
            BT.write(tx_packet.data, tx_packet.len);
            break;

          // Got a request to clear the custom mode (lockpoints)
          case DATA_CTRL_CLEAR:
            memset(&state.custom_mode, 0, sizeof(state.custom_mode));
            break;

          // Got a request to check the current mode
          case DATA_CTRL_CHECK_MODE:
            tx_packet.len = 5;
            tx_packet.data[0] = APP_MSG_CUSTOM_CTRL;
            tx_packet.data[1] = DATA_CTRL_CHECK_MODE;
            tx_packet.data[2] = (uint8_t)state.mode;
            tx_packet.data[3] = state.pedal_threshold;
            tx_packet.data[4] = BT_PACKET_END_BYTE;
            BT.write(tx_packet.data, tx_packet.len);
            break;

          // Got a request to reconnect Bluetooth?
          case DATA_CTRL_RECONNECT_BT:
            state.mode_override = false;
            DEBUG("App assumed control of override");
            break;
        }
      }
      break;

    // Got a request to change to "Bluetooth screen" mode
    case APP_MSG_IS_SCREEN:
      connected_to_bluetooth_screen = true;
      state.mode_override = false;
      break;
  }
}

#endif
