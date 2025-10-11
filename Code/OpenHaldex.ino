/* OpenHaldex by Forbes-Automotive - re-documented/re-built by Vlad! 

Basic principles are to take the OEM CAN data from ECU (Motor)/ABS (Bremse)/Cluster (Kombi) etc and adjust before sending to the Haldex unit to force locking as requested.  
CAN Library for Teensy is interrupt driven so no work being done in the 'loop'.

Supports:
  Generation 1 as OEM & Standalone
  Generation 2 is OEM & Standalone
  Generation 4 as OEM & Standalone
  Generation 5 is currently unsupported(!)

Version History:
  Documented in '_vers.h'
*/

// Settings
#define HALDEX_GENERATION 1      // define number variable for generation.  Either 1, 2, 4.  3 (Volvo) and 5 (VW) unsupported AT THE MOMENT
#define SOFTWARE_VERSION 0x006C  // 0.108
#define BROADCAST_OPENHALDEX     // For FIS/aftermarket ECU/etc support.  Broadcasts OpenHaldex (& Haldex) data via. 0x6B0.  Comment out to disable - may conflict with other modules, confirm first(!)

// Debug (comment out to disable)
#define ENABLE_DEBUG  // Enable Serial debug.  Comment out to disable
//#define DEBUG_HALDEXCAN_TRAFFIC   // Enable printing of Haldex CAN Traffic.  Comment out to disable
//#define DEBUG_CHASSISCAN_TRAFFIC  // Enable printing of Chassis CAN Traffic.  Comment out to disable

// Files
#include "openhaldex_definitions.h"
#include "openhaldex.h"
#include "openhaldex_gpio.h"
#include "openhaldex_bluetooth.h"
#include "openhaldex_can.h"
#include "openhaldex_calculations.h"
#include "openhaldex_eeprom.h"
#include "openhaldex_button.h"

// Timer used for repeating tasks
#include <arduino-timer.h>
auto timer = timer_create_default();

bool print_current_mode(void *params) { // print the current mode & Haldex data in Serial
  DEBUG("Mode: %s", get_openhaldex_mode_string(state.mode));
  DEBUG("    Raw haldexEngagement: %d", received_haldex_state);

  // different Generations have different feedback.  Gen1 is JUST Byte 1, Gen2 is SUM of Byte 1 & Byte 4
  switch (HALDEX_GENERATION) {
    case 1:
      DEBUG("    Mapped haldexEngagement: %d", map(received_haldex_engagement, 128, 198, 0, 100));  // Byte 1, range is 128 to 198
      break;
    case 2:
      DEBUG("    Mapped haldexEngagement: %d", map(received_haldex_engagement, 128, 255, 0, 100));  // Byte 1 + Byte 4, range is 128 to 255
      break;
    case 4:
      DEBUG("    Mapped haldexEngagement: %d", map(received_haldex_engagement, 128, 255, 0, 100));
      break;
    default:
      DEBUG("    Mapped haldexEngagement: %d", map(received_haldex_engagement, 128, 198, 0, 100));
      break;
  }

  DEBUG("    reportClutch1: %d", received_report_clutch1);        // this means it has a clutch issue
  DEBUG("    haldexEngagement: %d", received_haldex_engagement);  // this is the lock %
  DEBUG("    reportClutch2: %d", received_report_clutch2);        // this means it also has a clutch issue
  DEBUG("    couplingOpen: %d", received_coupling_open);          // clutch fully disengaged
  DEBUG("    speedLimit: %d", received_speed_limit);              // hit a speed limit...
  DEBUG("    tempCounter2: %d", tempCounter2);                    // incrememting value for checking the response to vars...

  return true;
}

void setup() {
#ifdef ENABLE_DEBUG
  Serial.begin(115200);
  DEBUG("OpenHaldex - Teensy 4.0 @ %dMHz", F_CPU_ACTUAL / (1000 * 1000));
#endif

  DEBUG("Initialise CAN...");
  init_CAN();  // initialise CAN-BUS on Teensy

  DEBUG("Initialise EEPROM...");
  init_EEPROM();  // initialise EEPROM on Teensy (for reading last saved settings)

  timer.every(2500, bt_send_status);     // Update the Bluetooth connection every 2.5 seconds
  timer.every(2500, update_EEPROM);      // Update the values stored in EEPROM every 2.5 seconds
  timer.every(20, send_standalone_CAN);  // Emulate CAN frames for Standalone mode (if enabled).  May require multiple variants if Haldex expects frames in xx times(!)

  DEBUG("Initialise GPIO...");
  init_GPIO(); // initialise buttons, LED etc

  DEBUG("Initialise Bluetooth...");
  BT.begin(19200); // speed to match LCD screen.  Phone app doesn't care.

#ifdef ENABLE_DEBUG
  timer.every(1000, print_current_mode);  // display the current mode every second.
#endif

#ifdef BROADCAST_OPENHALDEX
  timer.every(50, broadcast_openhaldex);  // broadcast OpenHaldex data every 50ms to CAN.
#endif
}

void loop() {
  timer.tick();  // update the timer

  // if too much time passed since the last Bluetooth message, a device is not connected
  if (millis() - last_bt_transmission_ms >= BT_TIMEOUT_MS) {
    bluetooth_connected = false;
  } else {  // a device is connected...
    bluetooth_connected = true;
  }

  // if there is Bluetooth data available, read and parse it
  if (BT.available()) {
    static bt_packet_t rx_packet;
    rx_packet.len = BT.readBytesUntil(BT_PACKET_END_BYTE, rx_packet.data, ARRAYSIZE(rx_packet.data));
    parse_bt_packet(rx_packet);
  }

  // if the Bluetooth Configuration button is pressed, start Bluetooth pairing
  if (digitalRead(GPIO_BT_CONF_BUTTON)) {
    DEBUG("BT button pressed in loop...");
    config_BT();
  }

  // light the LED according to the current mode
  show_current_mode_LED();
}
