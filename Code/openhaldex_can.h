#ifndef OPENHALDEX_CAN_H
#define OPENHALDEX_CAN_H

#if (HALDEX_GENERATION == 1)  // CAN IDs for Gen1
#define MOTOR1_ID 0x280
#define MOTOR2_ID 0x288
#define MOTOR3_ID 0x380
#define MOTOR5_ID 0x480
#define MOTOR6_ID 0x488
#define MOTOR7_ID 0x588
#define MOTORBREMS_ID 0x284
#define MOTOR_FLEX_ID 0x580
#define BRAKES1_ID 0x1A0
#define BRAKES2_ID 0x2A0
#define BRAKES3_ID 0x4A0
#define BRAKES5_ID 0x5A0
#define GRA_ID 0x38A
#define HALDEX_ID 0x2C0
#define BRAKES4_ID 0x2A0  // DLC 3 x
//#define BRAKES5_ID 0x4A8   // DLC 8 x
#define BRAKES6_ID 0x1A8   // DLC 3 x
#define BRAKES8_ID 0x1AC   // DLC 8 x
#define BRAKES9_ID 0x0AE   // DLC 8
#define BRAKES10_ID 0x3A0  // DLC 8 x
#define BRAKES11_ID 0x5B7  // DLC 8 x

#define KOMBI1_ID 0x320
#define KOMBI2_ID 0x420
#define KOMBI3_ID 0x520
#define KOMFORT_ID 0x390
#define mBSG_Last 0x570  // DLC 5
#define ZAS_ID 0x573

#define mLW_1 0x0C2         // DLC 7
#define mLenkhilfe_1 0x3D0  // DLC 6
#define mLenkhilfe_2 0x3D2  // DLC 6
#endif

#if (HALDEX_GENERATION == 2)  // CAN IDs for Gen2
#define MOTOR1_ID 0x280
#define MOTOR2_ID 0x288
#define MOTOR3_ID 0x380
#define MOTOR5_ID 0x480
#define MOTOR6_ID 0x488
#define MOTOR7_ID 0x588
#define MOTORBREMS_ID 0x284
#define MOTOR_FLEX_ID 0x580
#define BRAKES1_ID 0x1A0   // DLC 8 x
#define BRAKES2_ID 0x5A0   // DLC 8 x
#define BRAKES3_ID 0x4A0   // DLC 8 x
#define BRAKES4_ID 0x2A0   // DLC 3 x
#define BRAKES5_ID 0x4A8   // DLC 8 x
#define BRAKES6_ID 0x1A8   // DLC 3 x
#define BRAKES8_ID 0x1AC   // DLC 8 x
#define BRAKES9_ID 0x0AE   // DLC 8
#define BRAKES10_ID 0x3A0  // DLC 8 x
#define BRAKES11_ID 0x5B7  // DLC 8 x

#define GRA_ID 0x38A
#define HALDEX_ID 0x2C0
#define KOMBI1_ID 0x320
#define KOMBI2_ID 0x420
#define KOMBI3_ID 0x520
#define KOMFORT_ID 0x390
#define mBSG_Last 0x570  // DLC 5
#define ZAS_ID 0x573

#define mLW_1 0x0C2         // DLC 7
#define mLenkhilfe_1 0x3D0  // DLC 6
#define mLenkhilfe_2 0x3D2  // DLC 6
#endif

#if (HALDEX_GENERATION == 4)  // CAN IDs for Gen4
#define MOTOR1_ID 0x280
#define MOTOR2_ID 0x288
#define MOTOR3_ID 0x380
#define MOTOR5_ID 0x480
#define MOTOR6_ID 0x488
#define MOTOR7_ID 0x588
#define MOTOR8_ID 0x48A
#define MOTORBREMS_ID 0x284
#define MOTOR_FLEX_ID 0x580
#define BRAKES1_ID 0x1A0   // DLC 8 x
#define BRAKES2_ID 0x5A0   // DLC 8 x
#define BRAKES3_ID 0x4A0   // DLC 8 x
#define BRAKES4_ID 0x2A0   // DLC 3 x
#define BRAKES5_ID 0x4A8   // DLC 8 x
#define BRAKES6_ID 0x1A8   // DLC 3 x
#define BRAKES8_ID 0x1AC   // DLC 8 x
#define BRAKES9_ID 0x0AE   // DLC 8
#define BRAKES10_ID 0x3A0  // DLC 8 x
#define BRAKES11_ID 0x5B7  // DLC 8 x

#define GRA_ID 0x38A
#define HALDEX_ID 0x2C0

#define ZAS_ID 0x573
#define GATEWAY_ID 0x720
#define mGetriebe_1 0x440
#define mGetriebe_2 0x540
#define mGetriebe_4 0x548
#define mGetriebe_5 0x542
#define mGetriebe_6 0x44C
#define mGetriebe_7 0x544
#define mGetriebe_8 0x450
#define mGetriebe_9 0x454

#define mLW_1 0x0C2         // DLC 7
#define mLenkhilfe_1 0x3D0  // DLC 6
#define mLenkhilfe_2 0x3D2  // DLC 6
#define mLenkhilfe_3 0x0D0  // DLC 6

#define mGate_Komf_1 0x390           // DLC 8 100ms
#define mGate_Komf_2 0x392           // DLC 8/(4) 100ms
#define mGate_Komf_3 0x393           // DLC 8/ 200ms
#define mBSG_Last 0x570              // DLC 5 100ms
#define mDiagnose_1 0x7D0            // DLC 8 1000ms
#define mSoll_Verbauliste_neu 0x5DC  // DLC 8 100ms
#define mSysteminfo_1 0x5D0          // DLC 8(6) 100ms
#define NMH_Gateway 0x720            // DLC 7 200ms
#define mKombi_1 0x320
#define mKombi_2 0x420
#define mKombi_3 0x520
#endif

// Custom CAN IDs
#define OPENHALDEX_BROADCAST_ID 0x6B0
#define OPENHALDEX_EXTERNAL_CONTROL_ID 0x6A0

#define diagnostics_1_ID 0x764
#define diagnostics_2_ID 0x200
#define diagnostics_3_ID 0x710
#define diagnostics_4_ID 0x71D
#define diagnostics_5_ID 0x70F

// Library
#include <FlexCAN_T4.h>
FlexCAN_T4<CAN1, RX_SIZE_256, TX_SIZE_16> HaldexCAN;
FlexCAN_T4<CAN2, RX_SIZE_256, TX_SIZE_16> ChassisCAN;

// Function prototypes
float get_lock_target_adjustment();
uint8_t get_lock_target_adjusted_value(uint8_t value, bool invert);
void get_lock_data(CAN_message_t &frame);

// Functions

void onHaldexRX(const CAN_message_t &frame) {
  // A frame was received from the Haldex module - so let's parse it
  // Check if the ID corresponds to the "Haldex status" message.
  if (frame.id == HALDEX_ID) {
    // Extract data from the frame.
    switch (HALDEX_GENERATION) {
      case 1:
        received_haldex_state = frame.buf[0];
        received_haldex_engagement = frame.buf[1];

        // Decode the state byte.
        received_report_clutch1 = (received_haldex_state & (1 << 0));
        received_temp_protection = (received_haldex_state & (1 << 1));
        received_report_clutch2 = (received_haldex_state & (1 << 2));
        received_coupling_open = (received_haldex_state & (1 << 3));
        received_speed_limit = (received_haldex_state & (1 << 6));
#ifdef DEBUG_HALDEXCAN_TRAFFIC
        DEBUG("    BIN haldexState: " BYTE_TO_BINARY_PATTERN, BYTE_TO_BINARY(frame.buf[0]));
        DEBUG("    Raw haldexEngagement: %d", frame.buf[1]);
        DEBUG("    Mapped haldexEngagement: %d", map(frame.buf[1], 128, 198, 0, 100));
#endif
        break;

      case 2:
        received_haldex_state = frame.buf[0];
        received_haldex_engagement = frame.buf[1] + frame.buf[4];

        // Decode the state byte.
        received_report_clutch1 = (received_haldex_state & (1 << 0));
        received_temp_protection = (received_haldex_state & (1 << 1));
        received_report_clutch2 = (received_haldex_state & (1 << 2));
        received_coupling_open = (received_haldex_state & (1 << 3));
        received_speed_limit = (received_haldex_state & (1 << 6));
#ifdef DEBUG_HALDEXCAN_TRAFFIC
        DEBUG("    BIN haldexState: " BYTE_TO_BINARY_PATTERN, BYTE_TO_BINARY(frame.buf[0]));
        DEBUG("    Raw haldexEngagement: %d", frame.buf[1]);
        DEBUG("    Mapped haldexEngagement: %d", map(frame.buf[1] + frame.buf[4], 128, 255, 0, 100));
#endif
        break;

      case 4:
        received_haldex_state = frame.buf[0];
        received_haldex_engagement = map(frame.buf[1], 0, 255, 0, 100);

        // Decode the state byte.
        received_report_clutch1 = (received_haldex_state & (1 << 0));
        received_temp_protection = (received_haldex_state & (1 << 1));
        received_report_clutch2 = (received_haldex_state & (1 << 2));
        received_coupling_open = (received_haldex_state & (1 << 3));
        received_speed_limit = (received_haldex_state & (1 << 6));
#ifdef DEBUG_HALDEXCAN_TRAFFIC
        DEBUG("    BIN haldexState: " BYTE_TO_BINARY_PATTERN, BYTE_TO_BINARY(frame.buf[0]));
        DEBUG("    Raw haldexEngagement: %d", frame.buf[1]);
        DEBUG("    Mapped haldexEngagement: %d", map(frame.buf[1], 128, 255, 0, 100));
#endif
        break;

      default:
        break;
    }
  }

  // Build a frame for transmitting to Chassis CAN.
  CAN_message_t frame_out;
  frame_out.id = frame.id;
  frame_out.flags = frame.flags;
  frame_out.len = frame.len;
  memcpy(frame_out.buf, frame.buf, frame.len);

  // Forward whatever is received from Haldex to Chassis - we do no editting here
  if (!ChassisCAN.write(frame_out)) {
    DEBUG("Chassis CAN TX Fail!");
    blinkLED(50, 5, 100, 0, 0);  // blink LED fast & red IF there is a write error
    ChassisCAN.mailboxStatus();
  }
}

void onChassisRX(const CAN_message_t &frame) {
  // Ignore Chassis CAN messages in Standalone mode.
  // A frame was received from the Chassis bus.
  // Build a frame for transmitting to Haldex CAN.
  CAN_message_t frame_out;
  frame_out.id = frame.id;
  frame_out.flags = frame.flags;
  frame_out.len = frame.len;
  memcpy(frame_out.buf, frame.buf, frame.len);

  // if in standalone, check to make sure that the incoming data isn't diag
  // > if it is, allow the thread to continue (as it'll be ignored further on and then forwarded on).
  // > if it isn't and NOT diag, return / skip this module
  if (in_standalone_mode) {
    switch (frame.id) {
      case diagnostics_1_ID:
      case diagnostics_2_ID:
      case diagnostics_3_ID:
      case diagnostics_4_ID:
      case diagnostics_5_ID:
        break;  // continue
      default:
        return;  // stop
    }
  }

  // Extract data from the frame.
  switch (frame.id) {
    case MOTOR1_ID:
      received_pedal_value = frame.buf[5] * 0.4;  // wpedv_w
      break;

    case MOTOR2_ID:
      received_vehicle_speed = frame.buf[3] * 1.28;  // vfzg
      break;

    case OPENHALDEX_EXTERNAL_CONTROL_ID:
      // If the requested mode is valid, apply it.
      if (frame.buf[0] < (uint8_t)openhaldex_mode_t_MAX && frame.buf[0] != (uint8_t)MODE_CUSTOM)  // Is it really a problem to accept MODE_CUSTOM from CAN?
      {
        state.mode = (openhaldex_mode_t)frame.buf[0];
      }
      break;
  }

  // Edit the CAN frame, if not in STOCK mode (otherwise, the original frame is already copied in the new buffer).
  if (state.mode != MODE_STOCK) {
    // Edit the frame (only Gen1 and Gen4 supported).
    if (HALDEX_GENERATION == 1 || HALDEX_GENERATION == 2 || HALDEX_GENERATION == 4) {
      get_lock_data(frame_out);
    }
    // For other generations, frames are not edited yet.
    else if (state.mode != MODE_FWD) {
      switch (frame.id) {
        case MOTOR1_ID:
        case MOTOR2_ID:
        case MOTOR3_ID:
        case MOTOR6_ID:
        case BRAKES1_ID:
        case BRAKES2_ID:
        case BRAKES3_ID:
          break;
      }
    }
  }

  // Send the (edited) frame from Chassis to Haldex.
  if (!HaldexCAN.write(frame_out)) {
    DEBUG("Haldex CAN TX Fail!");
    blinkLED(50, 5, 100, 0, 0);
    HaldexCAN.mailboxStatus();
  }
}

void init_CAN() {
  // Initialize the Haldex CAN bus.
  HaldexCAN.begin();
  //HaldexCAN.setClock(CLK_60MHz);
  HaldexCAN.setBaudRate(500000);
  HaldexCAN.setMaxMB(64);
  HaldexCAN.onReceive(onHaldexRX);
  HaldexCAN.enableFIFO();
  HaldexCAN.enableFIFOInterrupt();
#ifdef ENABLE_DEBUG
  HaldexCAN.mailboxStatus();
#endif

  // Initialize the Chassis CAN bus.
  ChassisCAN.begin();
  //ChassisCAN.setClock(CLK_60MHz);
  ChassisCAN.setBaudRate(500000);
  ChassisCAN.setMaxMB(64);
  ChassisCAN.onReceive(onChassisRX);
  ChassisCAN.enableFIFO();
  ChassisCAN.enableFIFOInterrupt();
#ifdef ENABLE_DEBUG
  ChassisCAN.mailboxStatus();
#endif
}

bool broadcast_openhaldex(void *params) {
  // Construct the frame for OpenHaldex (for FIS, etc).
  // todo: combine small bools together into one byte to save on space ('in_standalone', 'mode_override', 'state.mode' (0-15?))
  CAN_message_t broadcast_frame;
  broadcast_frame.id = OPENHALDEX_BROADCAST_ID;
  broadcast_frame.len = 8;
  broadcast_frame.buf[0] = APP_MSG_STATUS;
  broadcast_frame.buf[1] = in_standalone_mode;
  broadcast_frame.buf[2] = (uint8_t)received_haldex_engagement;
  broadcast_frame.buf[3] = (uint8_t)lock_target;
  broadcast_frame.buf[4] = received_vehicle_speed;
  broadcast_frame.buf[5] = state.mode_override;
  broadcast_frame.buf[6] = (uint8_t)state.mode;
  broadcast_frame.buf[7] = (uint8_t)received_pedal_value;

  // Send the frame on Chassis CAN.
  if (!ChassisCAN.write(broadcast_frame)) {
    DEBUG("Chassis CAN TX Fail! (broadcast)");
    blinkLED(50, 5, 100, 0, 0);
    ChassisCAN.mailboxStatus();
  }
  return true;
}

void send_standalone_frame_Gen1() {
// Get initial lock target.
#if (HALDEX_GENERATION == 1)

  lock_target = get_lock_target_adjustment();
  if (state.mode == MODE_7525) {
    lock_target = 30;
  }

  CAN_message_t frame;
  frame.id = MOTOR1_ID;
  frame.len = 8;
  frame.buf[0] = 0x00;
  frame.buf[1] = get_lock_target_adjusted_value(0xFE, false);
  frame.buf[2] = 0x21;
  frame.buf[3] = get_lock_target_adjusted_value(0x4E, false);  // set RPM to a value so the pre-charge pump runs
  frame.buf[4] = 0x00;
  frame.buf[5] = 0x00;
  frame.buf[6] = get_lock_target_adjusted_value(0x16, false);  // set to a low value to control the req. transfer torque.  Main control value for Gen1
  frame.buf[7] = 0x00;
  HaldexCAN.write(frame);

  frame.id = MOTOR3_ID;
  frame.len = 8;
  frame.buf[0] = 0x00;
  frame.buf[1] = 0x50;
  frame.buf[2] = 0x00;
  frame.buf[3] = 0x00;
  frame.buf[4] = 0x00;
  frame.buf[5] = 0x00;
  frame.buf[6] = 0x00;
  frame.buf[7] = 0xFE;
  HaldexCAN.write(frame);

  static uint8_t BRAKES1_counter = 0;
  frame.id = BRAKES1_ID;
  frame.len = 8;
  frame.buf[0] = 0x80;  // ASR
  frame.buf[1] = get_lock_target_adjusted_value(0x00, false);
  frame.buf[2] = 0x00;
  frame.buf[3] = 0x0A;
  frame.buf[4] = 0xFE;
  frame.buf[5] = 0xFE;
  frame.buf[6] = 0x00;
  frame.buf[7] = BRAKES1_counter;
  HaldexCAN.write(frame);

  if (++BRAKES1_counter > 0xF) {
    BRAKES1_counter = 0;
  }

  frame.id = BRAKES3_ID;
  frame.len = 8;
  frame.buf[0] = get_lock_target_adjusted_value(0xFE, false);  // set a different 'front' wheel speed to 'rear'
  frame.buf[1] = 0x0A;
  frame.buf[2] = get_lock_target_adjusted_value(0xFE, false);  // set a different 'front' wheel speed to 'rear'
  frame.buf[3] = 0x0A;
  frame.buf[4] = 0x00;
  frame.buf[5] = 0x0A;
  frame.buf[6] = 0x00;
  frame.buf[7] = 0x0A;
  HaldexCAN.write(frame);
#endif
}

void send_standalone_frame_Gen2() {
#if (HALDEX_GENERATION == 2)
  // Get initial lock target.
  lock_target = get_lock_target_adjustment();
  if (state.mode == MODE_7525) {
    lock_target = 30;
  }
  tempCounter++;
  if (tempCounter > 3) {
    tempCounter1++;
    tempCounter = 0;
  }
  if (tempCounter1 > 5) {
    tempCounter1 = 0;
    tempCounter2++;
  }
  if (tempCounter2 > 254) {
    tempCounter2 = 0;
  }
  CAN_message_t frame;
  frame.id = MOTOR1_ID;  // needs this
  frame.len = 8;
  frame.buf[0] = 0x08;                                         // various bits no effect
  frame.buf[1] = 0xFA;                                         // MDNORM no effect x
  frame.buf[2] = 0x20;                                         // RPM low byte no effect was 0x20
  frame.buf[3] = get_lock_target_adjusted_value(0x4E, false);  // RPM high byte.  Will disable pre-charge pump if 0x00.  Sets raw = 8, coupling open
  frame.buf[4] = 0xFA;                                         // MDNORM no effect
  frame.buf[5] = 0xFA;                                         // Pedal no effect
  frame.buf[6] = get_lock_target_adjusted_value(0x20, false);  // idle adaptation?  Was slippage? no effect?
  frame.buf[7] = 0xFA;                                         // Fahrerwunschmoment req. torque? no effect
  HaldexCAN.write(frame);

  frame.id = MOTOR2_ID;  // needs this - just fill with default data
  frame.len = 8;
  frame.buf[0] = 0x00;  // no effect mux code
  frame.buf[1] = 0x30;  // no effect motor temperature
  frame.buf[2] = 0x00;  // bremse - does affect (coupling open etc)
  frame.buf[3] = 0xA;   // no effect speed (act)
  frame.buf[4] = 0xA;   // no effect speed (cruise?)
  frame.buf[5] = 0x10;  // no effect idle rpm
  frame.buf[6] = 0xFE;  // no effect torque
  frame.buf[7] = 0xFE;  //no effect torque
  HaldexCAN.write(frame);

  /*frame.id = MOTOR3_ID;  // doesn't throw code with this out
  frame.len = 8;
  frame.buf[0] = 0x00;                                         // various bits
  frame.buf[1] = 0x50;                                         // outside temp
  frame.buf[2] = 0xFA;                                         //Pedal
  frame.buf[3] = tempCounter2; //get_lock_target_adjusted_value(0xFE, false);  //Pedal
  frame.buf[4] = get_lock_target_adjusted_value(0xFE, false);  //Pedal
  frame.buf[5] = get_lock_target_adjusted_value(0xFE, false);  //Pedal
  frame.buf[6] = 0x64;                                         // 100 in dec, *25 = 2500rpm
  frame.buf[7] = get_lock_target_adjusted_value(0x01, false);  // gen1 is FE, Gen4 is 01
  HaldexCAN.write(frame);
  */

  frame.id = MOTOR5_ID;  // needs this
  frame.len = 8;
  frame.buf[0] = 0xFE;            // no effect max torque
  frame.buf[1] = 0x00;            // no effect epc, eml,
  frame.buf[2] = 0x00;            // no effect
  frame.buf[3] = 0x00;            // no effect
  frame.buf[4] = 0x00;            // no effect tvluesic PWM interface?
  frame.buf[5] = 0x00;            // no effect
  frame.buf[6] = 0x00;            // no effect
  frame.buf[7] = MOTOR5_counter;  // no effect checksum
  HaldexCAN.write(frame);
  if (++MOTOR5_counter > 255) {
    MOTOR5_counter = 0;
  }

  frame.id = KOMBI1_ID;  // 0x320 needs this
  frame.len = 8;
  frame.buf[0] = 0x00;  // no effect
  frame.buf[1] = 0x02;  //0x00;          //  bremsinfo, glow plug etc
  //bitSet(frame.buf[1], 7);  //set bremes info
  //bitSet(frame.buf[1], 6);  //set handbrake
  //todo: add handbrake override
  frame.buf[2] = 0x00;  // no effect
  frame.buf[3] = 0x00;  // no effect
  frame.buf[4] = 0x36;  // no effect
  frame.buf[5] = 0x00;  // no effect
  frame.buf[6] = 0x00;  // no effect
  frame.buf[7] = 0x00;  // no effect
  HaldexCAN.write(frame);

  frame.id = BRAKES1_ID;  // 0x1A0
  frame.len = 8;          // DLC 8
  frame.buf[0] = 0x00;    // ASR 0x04 sets bit 4.  0x08 removes set.  Coupling open?  Run through no change?
  frame.buf[1] = 0x41;    //can use to disable (>130 dec).  Gen1 is 41
  frame.buf[2] = 0x00;    //;    // no effect
  frame.buf[3] = 0xFE;    // was 0xFE no effect
  frame.buf[4] = 0xFE;    // was 0xFE miasrl no effect
  frame.buf[5] = 0xFE;    // was 0xFE miasrs no effect
  frame.buf[6] = 0x00;    // no effect
  frame.buf[7] = BRAKES1_counter;
  HaldexCAN.write(frame);
  if (++BRAKES1_counter > 0xF) {
    BRAKES1_counter = 0;
  }

  frame.id = BRAKES2_ID;                                       // 0x5A0
  frame.len = 8;                                               // DLC 8
  frame.buf[0] = 0x7F;                                         // various bits // was 7E
  frame.buf[1] = 0xAE;                                         // outside temp no effect
  frame.buf[2] = 0x3D;                                         // Pedal no effect
  frame.buf[3] = BRAKES2_counter;                              // checksum
  frame.buf[4] = get_lock_target_adjusted_value(0x7F, false);  // big affect(!) 0x7F is max
  frame.buf[5] = get_lock_target_adjusted_value(0xFE, false);  // no effect.  Was 0x6E
  frame.buf[6] = 0x5E;                                         // no effect.  Was 0x70
  frame.buf[7] = 0x2B;                                         // no effect.  gen1 is FE, Gen4 is 01 was AB
  HaldexCAN.write(frame);
  BRAKES2_counter = BRAKES2_counter + 10;
  if (BRAKES2_counter > 0xF7) {
    BRAKES2_counter = 7;
  }

  frame.id = BRAKES3_ID;                                       // 0x4A0
  frame.len = 8;                                               // DLC 8
  frame.buf[0] = get_lock_target_adjusted_value(0xFE, false);  // change in wheel speeds doesn't actually affect
  frame.buf[1] = 0x0A;
  frame.buf[2] = get_lock_target_adjusted_value(0xFE, false);  // change in wheel speeds doesn't actually affect
  frame.buf[3] = 0x0A;
  frame.buf[4] = 0x00;
  frame.buf[5] = 0x0A;
  frame.buf[6] = 0x00;
  frame.buf[7] = 0x0A;
  HaldexCAN.write(frame);

  frame.id = BRAKES4_ID;           // 0x2A0 includes coupling moment?
  frame.len = 8;                   // DLC 8 (/4)
  frame.buf[0] = 0x00;             // no effect
  frame.buf[1] = 0x00;             // no effect
  frame.buf[2] = 0x00;             // no effect
  frame.buf[3] = 0x00;             // no effect
  frame.buf[4] = 0x00;             // no effect
  frame.buf[5] = 0x00;             // no effect
  frame.buf[6] = BRAKES4_counter;  // checksum
  frame.buf[7] = BRAKES4_counter;  // checksum
  HaldexCAN.write(frame);
  BRAKES4_counter = BRAKES4_counter + 10;
  if (BRAKES4_counter > 0xF0) {
    BRAKES4_counter = 0;
  }

  frame.id = BRAKES5_ID;  // 0x4A8 EPB, ESP? wants to see this
  frame.len = 8;
  frame.buf[0] = 0xFE;              // no effect
  frame.buf[1] = 0x7F;              // no effect
  frame.buf[2] = 0x03;              // no effect
  frame.buf[3] = 0x00;              // no effect
  frame.buf[4] = 0x00;              // no effect
  frame.buf[5] = 0x00;              // no effect
  frame.buf[6] = BRAKES5_counter;   // checksum
  frame.buf[7] = BRAKES5_counter2;  // checksum
  HaldexCAN.write(frame);
  BRAKES5_counter = BRAKES5_counter + 10;
  if (BRAKES5_counter > 0xF0) {
    BRAKES5_counter = 0;
  }
  BRAKES5_counter2 = BRAKES5_counter2 + 10;
  if (BRAKES5_counter2 > 0xF3) {
    BRAKES5_counter2 = 3;
  }

  frame.id = BRAKES9_ID;            // 0x0AE
  frame.len = 8;                    // DLC 8
  frame.buf[0] = BRAKES9_counter;   // checksum
  frame.buf[1] = BRAKES9_counter2;  // checksum
  frame.buf[2] = 0x00;              // no effect
  frame.buf[3] = 0x00;              // no effect
  frame.buf[4] = 0x00;              // no effect
  frame.buf[5] = 0x00;              // no effect
  frame.buf[6] = 0x02;              // no effect
  frame.buf[7] = 0x00;              // no effect
  HaldexCAN.write(frame);
  BRAKES9_counter = BRAKES9_counter + 10;
  if (BRAKES9_counter > 0xF1) {
    BRAKES9_counter = 11;
  }
  BRAKES9_counter2 = BRAKES9_counter2 + 10;
  if (BRAKES9_counter2 > 0xF0) {
    BRAKES9_counter2 = 0;
  }

  frame.id = BRAKES10_ID;           // 0x3A0
  frame.len = 8;                    // DLC 8
  frame.buf[0] = 0xA6;              // no effect
  frame.buf[1] = BRAKES10_counter;  // checksum
  frame.buf[2] = 0x75;              // no effect
  frame.buf[3] = 0xD4;              // no effect
  frame.buf[4] = 0x51;              // no effect
  frame.buf[5] = 0x47;              // no effect
  frame.buf[6] = 0x1D;              // no effect
  frame.buf[7] = 0x0F;              // no effect
  HaldexCAN.write(frame);
  BRAKES10_counter = BRAKES10_counter + 1;
  if (BRAKES10_counter > 0xF) {
    BRAKES10_counter = 0;
  }

  frame.id = mLW_1;              // electronic power steering 0x0C2
  frame.len = 8;                 // DLC 8
  frame.buf[0] = 0x20;           // always 0x20 angle of turn?
  frame.buf[1] = 0x00;           // no effect B
  frame.buf[2] = 0x00;           // no effect C
  frame.buf[3] = 0x00;           // no effect D
  frame.buf[4] = 0x80;           // no effect E
  frame.buf[5] = mLW_1_counter;  // no effect F
  frame.buf[6] = 0x00;           // no effect G

  // now calculate checksum (0xFF - bytes 0, 1, 2, 3 + 5)
  mLW_1_crc = 255 - (frame.buf[0] + frame.buf[1] + frame.buf[2] + frame.buf[3] + frame.buf[5]);
  frame.buf[7] = mLW_1_crc;  //0x8F;          // no effect H
  mLW_1_counter = mLW_1_counter + 16;
  if (mLW_1_counter >= 0xF0) {
    mLW_1_counter = 0;
  }
  HaldexCAN.write(frame);

  /*
  frame.id = mLenkhilfe_1; // doesn't need this
  frame.len = 6;
  frame.buf[0] = 0x00;  // no effect
  frame.buf[1] = 0x07;  // no effect
  frame.buf[2] = 0x00;  // no effect
  frame.buf[3] = 0x00;  // no effect
  frame.buf[4] = 0xC8;  // no effect
  frame.buf[5] = 0x00;  // no effect
  HaldexCAN.write(frame);
  */

#endif
}

void send_standalone_frame_Gen4() {
  //send_standalone_frame_Gen2();
  //20ms frames

#if (HALDEX_GENERATION == 4)
  lock_target = get_lock_target_adjustment();
  if (state.mode == MODE_7525) {
    lock_target = 30;
  }

  CAN_message_t frame;
  frame.id = mLW_1;                        // electronic power steering 0x0C2
  frame.len = 8;                           // DLC 8
  frame.buf[0] = lws_2[mLW_1_counter][0];  // angle of turn (block 011) low byte
  frame.buf[1] = lws_2[mLW_1_counter][1];  // no effect B high byte
  frame.buf[2] = lws_2[mLW_1_counter][2];  // no effect C
  frame.buf[3] = lws_2[mLW_1_counter][3];  // no effect D
  frame.buf[4] = lws_2[mLW_1_counter][4];  // rate of change (block 010) was 0x00
  frame.buf[5] = lws_2[mLW_1_counter][5];  // no effect F
  frame.buf[6] = lws_2[mLW_1_counter][6];  // no effect F
  frame.buf[7] = lws_2[mLW_1_counter][7];  // no effect F
  mLW_1_counter++;
  if (mLW_1_counter > 15) {
    mLW_1_counter = 0;
  }
  HaldexCAN.write(frame);

  frame.id = BRAKES1_ID;           // 0x1A0
  frame.len = 8;                   // DLC 8
  frame.buf[0] = 0x20;             // ASR 0x04 sets bit 4.  0x08 removes set.  Coupling open/closed
  frame.buf[1] = 0x40;             // can use to disable (>130 dec).  Was 0x00; 0x41?  0x43?
  frame.buf[2] = 0xF0;             // was 0x00 no effect
  frame.buf[3] = 0x07;             // was 0xFE no effect
  frame.buf[4] = 0xFE;             // was 0xFE miasrl no effect
  frame.buf[5] = 0xFE;             // was 0xFE miasrs no effect
  frame.buf[6] = 0x00;             // was 0x00
  frame.buf[7] = BRAKES1_counter;  // checksum
  if (++BRAKES1_counter > 0x1F) {  // 0xF
    BRAKES1_counter = 10;          // 0
  }
  HaldexCAN.write(frame);

  /*
  Bremse 3 has massive effect - deviation between front/rear = block 011 'rpm changing'
  too high a speed causes 'pulsing'
  slip control changes from 0 to 1 IF rear > front
  */
  frame.id = BRAKES3_ID;                                       // 0x4A0 - deviation between front/rear = block 011 'rpm'
  frame.len = 8;                                               // DLC 8
  frame.buf[0] = 0xB6;                                         // front left low
  frame.buf[1] = 0x07;                                         // front left high
  frame.buf[2] = 0xCC;                                         // front right low
  frame.buf[3] = 0x07;                                         // front right high
  frame.buf[4] = get_lock_target_adjusted_value(0xD2, false);  // rear left low
  frame.buf[5] = 0x07;                                         // rear left high
  frame.buf[6] = get_lock_target_adjusted_value(0xD2, false);  // rear right low
  frame.buf[7] = 0x07;                                         // rear right high
  HaldexCAN.write(frame);

  frame.id = BRAKES4_ID;                                       // 0x2A0 includes coupling moment? Affects vehicle mode(!) do not have!
  frame.len = 8;                                               // DLC 8 (/4)
  frame.buf[0] = get_lock_target_adjusted_value(0xFE, false);  // affects estimated torque AND vehicle mode(!)
  frame.buf[1] = 0x00;                                         //
  frame.buf[2] = 0x00;                                         //
  frame.buf[3] = 0x64;                                         // 32605
  frame.buf[4] = 0x00;                                         //
  frame.buf[5] = 0x00;                                         //
  frame.buf[6] = BRAKES4_counter;                              // checksum
  BRAKES4_crc = 0;
  for (uint8_t i = 0; i < 7; i++) {
    BRAKES4_crc ^= frame.buf[i];
  }
  frame.buf[7] = BRAKES4_crc;

  BRAKES4_counter = BRAKES4_counter + 16;
  if (BRAKES4_counter > 0xF0) {
    BRAKES4_counter = 0x00;
  }
  HaldexCAN.write(frame);

  frame.id = BRAKES9_ID;            // 0x0AE do not have!
  frame.len = 8;                    // DLC 8
  frame.buf[0] = BRAKES9_counter;   // checksum
  frame.buf[1] = BRAKES9_counter2;  // checksum
  frame.buf[2] = 0x00;              // no effect
  frame.buf[3] = 0x00;              // no effect
  frame.buf[4] = 0x00;              // no effect
  frame.buf[5] = 0x00;              // no effect
  frame.buf[6] = 0x03;              // 0x01
  frame.buf[7] = 0x00;              // no effect
  HaldexCAN.write(frame);
  BRAKES9_counter = BRAKES9_counter + 16;
  if (BRAKES9_counter > 0xF3) {
    BRAKES9_counter = 0x03;
  }
  BRAKES9_counter2 = BRAKES9_counter2 + 16;
  if (BRAKES9_counter2 > 0xF0) {
    BRAKES9_counter2 = 0x00;
  }

  frame.id = MOTOR1_ID;  // 0x280 - needs this
  frame.len = 8;
  frame.buf[0] = 0x01;                                         // various bits no effect 0x08
  frame.buf[1] = 0xFE;                                         // MDNORM no effect x
  frame.buf[2] = 0x20;                                         // RPM low byte no effect was 0x20
  frame.buf[3] = get_lock_target_adjusted_value(0x4E, false);  // RPM high byte.  Will disable pre-charge pump if 0x00.  Sets raw = 8, coupling open
  frame.buf[4] = 0xFE;                                         // MDNORM no effect
  frame.buf[5] = 0xFE;                                         // Pedal no effect
  frame.buf[6] = get_lock_target_adjusted_value(0x20, false);  // idle adaptation?  Was slippage?
  frame.buf[7] = get_lock_target_adjusted_value(0xFE, false);  // Fahrerwunschmoment req. torque?
  HaldexCAN.write(frame);

  /*
  frame.id = MOTOR3_ID;  // doesn't throw code with this out - no effect on any block
  frame.len = 8;
  frame.buf[0] = 0x20;  // various bits
  frame.buf[1] = 0x84;  // outside temp
  frame.buf[2] = 0xFE;  //Pedal
  frame.buf[3] = 0xFE;  //get_lock_target_adjusted_value(0xFE, false);  //Pedal
  frame.buf[4] = 0xFE;  //Pedal
  frame.buf[5] = 0xFE;  //Pedal
  frame.buf[6] = 0x00;  // 100 in dec, *25 = 2500rpm was 0x64
  frame.buf[7] = 0x00;  // gen1 is FE, Gen4 WAS 01
  HaldexCAN.write(frame);

  frame.id = MOTOR6_ID;  // doesn't throw code with this out - no effect on any block
  frame.len = 8;
  frame.buf[0] = 0x6A;             // various bits
  frame.buf[1] = 0x11;             // outside temp
  frame.buf[2] = 0x0F;             //Pedal
  frame.buf[3] = 0x7A;             //get_lock_target_adjusted_value(0xFE, false);  //Pedal
  frame.buf[4] = 0xFE;             //Pedal
  frame.buf[5] = 0xFF;             //Pedal
  frame.buf[6] = 0xFF;             // 100 in dec, *25 = 2500rpm was 0x64
  frame.buf[7] = MOTOR6_counter2;  // gen1 is FE, Gen4 WAS 01
  HaldexCAN.write(frame);
  MOTOR6_counter = MOTOR6_counter - 16;
  if (MOTOR6_counter < 0x0E) {
    MOTOR6_counter = 254;  // there is a sum here!
  }
  MOTOR6_counter2 = MOTOR6_counter2 + 16;
  if (MOTOR6_counter2 > 0xF0) {
    MOTOR6_counter2 = 0;
  }

  // added in:
  frame.id = 0x1AC;  // doesn't throw code with this out - no effect on any block
  frame.len = 8;
  frame.buf[0] = 0x1C;  // various bits
  frame.buf[1] = 0x03;  // outside temp
  frame.buf[2] = 0x00;  //Pedal
  frame.buf[3] = 0x00;  //get_lock_target_adjusted_value(0xFE, false);  //Pedal
  frame.buf[4] = 0x0C;  //Pedal
  frame.buf[5] = 0x01;  //Pedal
  frame.buf[6] = 0x00;  // 100 in dec, *25 = 2500rpm was 0x64
  frame.buf[7] = 0x12;  // gen1 is FE, Gen4 WAS 01
  HaldexCAN.write(frame);
  */

  /*
  frame.id = BRAKES10_ID;           // 0x3A0
  frame.len = 8;                    // DLC 8
  frame.buf[0] = tempCounter2;      // no effect
  frame.buf[1] = BRAKES10_counter;  // checksum
  frame.buf[2] = tempCounter2;      // no effect
  frame.buf[3] = tempCounter2;      // no effect
  frame.buf[4] = tempCounter2;      // no effect
  frame.buf[5] = tempCounter2;      // no effect
  frame.buf[6] = tempCounter2;      // no effect
  frame.buf[7] = tempCounter2;      // no effect
  HaldexCAN.write(frame);
  BRAKES10_counter = BRAKES10_counter + 1;
  if (BRAKES10_counter > 0xF) {
    BRAKES10_counter = 0;
  }
  */

  frame.id = BRAKES2_ID;                                       // 0x5A0
  frame.len = 8;                                               // DLC 8
  frame.buf[0] = 0x80;                                         // various bits // was 7E
  frame.buf[1] = 0x7A;                                         // outside temp no effect
  frame.buf[2] = 0x05;                                         // Pedal no effect
  frame.buf[3] = BRAKES2_counter;                              // checksum changing
  frame.buf[4] = get_lock_target_adjusted_value(0x7F, false);  // big affect(!) 0x7F is max
  frame.buf[5] = 0xCA;                                         // no effect.  Was 0x6E
  frame.buf[6] = 0x1B;                                         // no effect.  Was 0x70 - can cause 'Operating Mode Malfunction'(!) Includes Emergency Mode and Control Module Error
  frame.buf[7] = 0xAB;                                         // no effect.  gen1 is FE, Gen4 is 01 was AB - can cause 'Operating Mode Malfunction'(!)
  HaldexCAN.write(frame);
  BRAKES2_counter = BRAKES2_counter + 16;
  if (BRAKES2_counter > 0xF0) {
    BRAKES2_counter = 0;
  }

  /*
  frame.id = BRAKES5_ID;  // 0x4A8 EPB, ESP? wants to see this
  frame.len = 8;
  frame.buf[0] = 0x48;              // no effect
  frame.buf[1] = 0x00;              // no effect
  frame.buf[2] = 0x07;              // no effect
  frame.buf[3] = 0x80;              // no effect
  frame.buf[4] = 0x00;              // no effect
  frame.buf[5] = 0x00;              // no effect
  frame.buf[6] = BRAKES5_counter;   // checksum
  frame.buf[7] = BRAKES5_counter2;  // no checksum?
  HaldexCAN.write(frame);
  BRAKES5_counter = BRAKES5_counter + 16;
  if (BRAKES5_counter > 0xF4) {
    BRAKES5_counter = 0x04;
  }
  BRAKES5_counter2 = BRAKES5_counter2 + 10;
  if (BRAKES5_counter2 > 0xF3) {
    BRAKES5_counter2 = 3;
  }

  frame.id = BRAKES8_ID;           // 0x4A0 - deviation between front/rear = block 011 'rpm'
  frame.len = 8;                   // DLC 8
  frame.buf[0] = 0x1C;             // front left low
  frame.buf[1] = BRAKES8_counter;  // front left high
  frame.buf[2] = 0x00;             // front right low
  frame.buf[3] = 0x00;             // front right high
  frame.buf[4] = 0x0C;             // rear left low
  frame.buf[5] = 0x01;             // rear left high
  frame.buf[6] = 0x00;             // rear right low
  frame.buf[7] = 0x12;             // rear right high
  HaldexCAN.write(frame);
  BRAKES8_counter = BRAKES8_counter + 16;
  if (BRAKES8_counter > 0xF0) {
    BRAKES8_counter = 0x00;
  }

  frame.id = MOTOR2_ID;  // needs this - just fill with default data
  frame.len = 8;
  frame.buf[0] = 0x00;  // no effect mux code
  frame.buf[1] = 0x30;  // no effect motor temperature
  frame.buf[2] = 0x20;  // bremse - does affect (coupling open etc)
  frame.buf[3] = 0x00;  // no effect speed (act)
  frame.buf[4] = 0x00;  // no effect speed (cruise?)
  frame.buf[5] = 0x00;  // no effect idle rpm
  frame.buf[6] = 0xFA;  // no effect torque
  frame.buf[7] = 0xFA;  //no effect torque
  HaldexCAN.write(frame);

  frame.id = MOTOR5_ID;  // 0x480 needs this - no effect on any block
  frame.len = 8;
  frame.buf[0] = 0x84;  // no effect max torque
  frame.buf[1] = 0x20;  // no effect epc, eml,
  frame.buf[2] = 0xDF;  // no effect
  frame.buf[3] = 0x62;  // no effect
  frame.buf[4] = 0x55;  // no effect tvluesic PWM interface?
  frame.buf[5] = 0x00;  // no effect
  frame.buf[6] = 0x02;  // no effect
  frame.buf[7] = 0x4E;  // no effect checksum
  HaldexCAN.write(frame);
  if (++MOTOR5_counter > 255) {
    MOTOR5_counter = 0;
  }

  frame.id = MOTOR7_ID;  // doesn't throw code with this out - no effect on any block
  frame.len = 8;
  frame.buf[0] = 0xE8;  // various bits
  frame.buf[1] = 0x6C;  // outside temp
  frame.buf[2] = 0x7A;  //Pedal
  frame.buf[3] = 0x89;  //get_lock_target_adjusted_value(0xFE, false);  //Pedal
  frame.buf[4] = 0x00;  //Pedal
  frame.buf[5] = 0x01;  //Pedal
  frame.buf[6] = 0x04;  // 100 in dec, *25 = 2500rpm was 0x64
  frame.buf[7] = 0x8C;  // gen1 is FE, Gen4 WAS 01
  HaldexCAN.write(frame);

  frame.id = mLenkhilfe_1;  // doesn't throw code with this out - no effect on any block
  frame.len = 6;
  frame.buf[0] = 0x00;  // various bits
  frame.buf[1] = 0x00;  // outside temp
  frame.buf[2] = 0x08;  //Pedal
  frame.buf[3] = 0x00;  //get_lock_target_adjusted_value(0xFE, false);  //Pedal
  frame.buf[4] = 0xC8;  //Pedal
  frame.buf[5] = 0x69;  //Pedal
  HaldexCAN.write(frame);

  frame.id = 0x0D0;  // doesn't throw code with this out - no effect on any block
  frame.len = 6;
  frame.buf[0] = 0x03;  // various bits
  frame.buf[1] = 0xF5;  // outside temp
  frame.buf[2] = 0x08;  //Pedal
  frame.buf[3] = 0x38;  //get_lock_target_adjusted_value(0xFE, false);  //Pedal
  frame.buf[4] = 0x26;  //Pedal
  frame.buf[5] = 0xE0;  //Pedal
  HaldexCAN.write(frame);

  frame.id = 0x448;  // doesn't throw code with this out - no effect on any block
  frame.len = 5;
  frame.buf[0] = 0x52;  // various bits
  frame.buf[1] = 0x00;  // outside temp
  frame.buf[2] = 0x00;  //Pedal
  frame.buf[3] = 0x00;  //get_lock_target_adjusted_value(0xFE, false);  //Pedal
  frame.buf[4] = 0xA0;  //Pedal
  HaldexCAN.write(frame);

  frame.id = 0x440;  // doesn't throw code with this out - no effect on any block
  frame.len = 8;
  frame.buf[0] = 0x00;  // various bits
  frame.buf[1] = 0x52;  // outside temp
  frame.buf[2] = 0x5D;  //Pedal
  frame.buf[3] = 0xFE;  //get_lock_target_adjusted_value(0xFE, false);  //Pedal
  frame.buf[4] = 0x7F;  //Pedal
  frame.buf[5] = 0x00;  //Pedal
  frame.buf[6] = 0x80;  // 100 in dec, *25 = 2500rpm was 0x64
  frame.buf[7] = 0x03;  // gen1 is FE, Gen4 WAS 01
  HaldexCAN.write(frame);

  frame.id = 0x540;  // doesn't throw code with this out - no effect on any block
  frame.len = 8;
  frame.buf[0] = 0x05;  // various bits
  frame.buf[1] = 0x00;  // outside temp
  frame.buf[2] = 0xFF;  //Pedal
  frame.buf[3] = 0x00;  //get_lock_target_adjusted_value(0xFE, false);  //Pedal
  frame.buf[4] = 0xFF;  //Pedal
  frame.buf[5] = 0x00;  //Pedal
  frame.buf[6] = 0x02;  // 100 in dec, *25 = 2500rpm was 0x64
  frame.buf[7] = 0x56;  // gen1 is FE, Gen4 WAS 01
  HaldexCAN.write(frame);

  frame.id = 0x594;  // doesn't throw code with this out - no effect on any block
  frame.len = 8;
  frame.buf[0] = 0x4D;  // various bits
  frame.buf[1] = 0x19;  // outside temp
  frame.buf[2] = 0x5A;  //Pedal
  frame.buf[3] = 0xA8;  //get_lock_target_adjusted_value(0xFE, false);  //Pedal
  frame.buf[4] = 0x59;  //Pedal
  frame.buf[5] = 0xFE;  //Pedal
  frame.buf[6] = 0x7A;  // 100 in dec, *25 = 2500rpm was 0x64
  frame.buf[7] = 0x7B;  // gen1 is FE, Gen4 WAS 01
  HaldexCAN.write(frame);
  */

  // 25ms frames
  frame.id = mKombi_1;  // kombi 1
  frame.len = 8;        // DLC 8
  frame.buf[0] = 0x24;  // angle of turn (block 011) low byte
  frame.buf[1] = 0x00;  // no effect B high byte
  frame.buf[2] = 0x1D;  // no effect C
  frame.buf[3] = 0xB9;  // no effect D
  frame.buf[4] = 0x07;  // rate of change (block 010)
  frame.buf[5] = 0x42;  // rate of change (block 010) checksum?
  frame.buf[6] = 0x09;  // rate of change (block 010)
  frame.buf[7] = 0x81;  // rate of change (block 010)
  HaldexCAN.write(frame);

  frame.id = mKombi_3;  // 0x520 - kombi 3
  frame.len = 8;        // DLC 8
  frame.buf[0] = 0x60;  // angle of turn (block 011) low byte
  frame.buf[1] = 0x43;  // no effect B high byte
  frame.buf[2] = 0x01;  // no effect C
  frame.buf[3] = 0x10;  // no effect D
  frame.buf[4] = 0x66;  // rate of change (block 010)
  frame.buf[5] = 0xF1;  // rate of change (block 010) checksum?
  frame.buf[6] = 0x03;  // rate of change (block 010)
  frame.buf[7] = 0x02;  // rate of change (block 010)
  HaldexCAN.write(frame);

  /*
  frame.id = 0x394;     // electronic power steering 0x0C2
  frame.len = 8;        // DLC 8
  frame.buf[0] = 0x0F;  // angle of turn (block 011) low byte
  frame.buf[1] = 0x14;  // no effect B high byte
  frame.buf[2] = 0x7F;  // no effect C
  frame.buf[3] = 0xE0;  // no effect D
  frame.buf[4] = 0x7D;  // rate of change (block 010)
  frame.buf[5] = 0xD0;  // rate of change (block 010) checksum?
  frame.buf[6] = 0x00;  // rate of change (block 010)
  frame.buf[7] = 0x90;  // rate of change (block 010)
  HaldexCAN.write(frame);
  */

  // 100ms frames
  frame.id = mGate_Komf_1;  // electronic power steering 0x0C2
  frame.len = 8;            // DLC 8
  frame.buf[0] = 0x03;      // angle of turn (block 011) low byte
  frame.buf[1] = 0x11;      // no effect B high byte
  frame.buf[2] = 0x58;      // no effect C
  frame.buf[3] = 0x00;      // no effect D
  frame.buf[4] = 0x40;      // rate of change (block 010)
  frame.buf[5] = 0x00;      // rate of change (block 010)
  frame.buf[6] = 0x01;      // rate of change (block 010)
  frame.buf[7] = 0x08;      // rate of change (block 010)
  HaldexCAN.write(frame);

  frame.id = mGate_Komf_2;  // electronic power steering 0x0C2
  frame.len = 8;            // DLC 8
  frame.buf[0] = 0x09;      // angle of turn (block 011) low byte
  frame.buf[1] = 0x01;      // no effect B high byte
  frame.buf[2] = 0x00;      // no effect C
  frame.buf[3] = 0xA1;      // no effect D
  frame.buf[4] = 0x00;      // rate of change (block 010)
  frame.buf[5] = 0x00;      // rate of change (block 010)
  frame.buf[6] = 0x00;      // rate of change (block 010)
  frame.buf[7] = 0x00;      // rate of change (block 010)
  HaldexCAN.write(frame);

  frame.id = mSysteminfo_1;  // electronic power steering 0x0C2
  frame.len = 6;             // DLC 8
  frame.buf[0] = 0xC0;       // angle of turn (block 011) low byte
  frame.buf[1] = 0x03;       // no effect B high byte
  frame.buf[2] = 0x50;       // no effect C
  frame.buf[3] = 0xBF;       // no effect D
  frame.buf[4] = 0x37;       // rate of change (block 010)
  frame.buf[5] = 0x56;       // rate of change (block 010)
  frame.buf[6] = 0xC0;       // rate of change (block 010)
  frame.buf[7] = 0x00;       // rate of change (block 010)
  HaldexCAN.write(frame);

  frame.id = mSoll_Verbauliste_neu;  // electronic power steering 0x0C2
  frame.len = 8;                     // DLC 8
  frame.buf[0] = 0xF7;               // angle of turn (block 011) low byte
  frame.buf[1] = 0x42;               // no effect B high byte
  frame.buf[2] = 0x70;               // no effect C
  frame.buf[3] = 0x3F;               // no effect D
  frame.buf[4] = 0x1C;               // rate of change (block 010)
  frame.buf[5] = 0x08;               // rate of change (block 010)
  frame.buf[6] = 0x00;               // rate of change (block 010)
  frame.buf[7] = 0xC8;               // rate of change (block 010)
  HaldexCAN.write(frame);

  frame.id = BRAKES11_ID;  // 0x3A0
  frame.len = 8;           // DLC 8
  frame.buf[0] = 0x00;     // no effect
  frame.buf[1] = 0XC0;     // checksum
  frame.buf[2] = 0x00;     // no effect
  frame.buf[3] = 0x00;     // no effect
  frame.buf[4] = 0x00;     // no effect
  frame.buf[5] = 0x00;     // no effect
  frame.buf[6] = 0x00;     // no effect
  frame.buf[7] = 0x00;     // no effect
  HaldexCAN.write(frame);

  // 200ms frames
  frame.id = mKombi_2;  // electronic power steering 0x0C2
  frame.len = 8;        // DLC 8
  frame.buf[0] = 0x4C;  // angle of turn (block 011) low byte
  frame.buf[1] = 0x86;  // no effect B high byte
  frame.buf[2] = 0x85;  // no effect C
  frame.buf[3] = 0x00;  // no effect D
  frame.buf[4] = 0x00;  // rate of change (block 010)
  frame.buf[5] = 0x30;  // rate of change (block 010)
  frame.buf[6] = 0xFF;  // rate of change (block 010)
  frame.buf[7] = 0x04;  // rate of change (block 010)
  HaldexCAN.write(frame);

  frame.id = mKombi_3;  // electronic power steering 0x0C2
  frame.len = 8;        // DLC 8
  frame.buf[0] = 0xA6;  // angle of turn (block 011) low byte checksum?
  frame.buf[1] = 0x87;  // no effect B high bytechecksum?
  frame.buf[2] = 0x01;  // no effect C
  frame.buf[3] = 0x10;  // no effect D
  frame.buf[4] = 0x66;  // rate of change (block 010)
  frame.buf[5] = 0xF2;  // rate of change (block 010)
  frame.buf[6] = 0x03;  // rate of change (block 010)
  frame.buf[7] = 0x02;  // rate of change (block 010)
  HaldexCAN.write(frame);

  frame.id = NMH_Gateway;  // electronic power steering 0x0C2
  frame.len = 7;           // DLC 8
  frame.buf[0] = 0x04;     // angle of turn (block 011) low byte
  frame.buf[1] = 0x03;     // no effect B high byte
  frame.buf[2] = 0x01;     // no effect C
  frame.buf[3] = 0x00;     // no effect D
  frame.buf[4] = 0x02;     // rate of change (block 010)
  frame.buf[5] = 0x00;     // rate of change (block 010)
  frame.buf[6] = 0x00;     // rate of change (block 010)
  HaldexCAN.write(frame);

  // 1000ms frames
  frame.id = mDiagnose_1;              // electronic power steering 0x0C2
  frame.len = 8;                       // DLC 8
  frame.buf[0] = 0x26;                 // angle of turn (block 011) low byte
  frame.buf[1] = 0xF2;                 // no effect B high byte
  frame.buf[2] = 0x03;                 // no effect C
  frame.buf[3] = 0x12;                 // no effect D
  frame.buf[4] = 0x70;                 // rate of change (block 010)
  frame.buf[5] = 0x19;                 // rate of change (block 010)
  frame.buf[6] = 0x25;                 // rate of change (block 010)
  frame.buf[7] = mDiagnose_1_counter;  // rate of change (block 010) checksum?
  HaldexCAN.write(frame);
  mDiagnose_1_counter++;
  if (mDiagnose_1_counter > 0x1F) {
    mDiagnose_1_counter = 0;
  }
#endif
}

bool send_standalone_CAN(void *params) {
  // Don't send Standalone messages if not in Standalone mode.  Remember there is a 20ms timer always active regardless (since standalone can be switched at runtime)
  if (!in_standalone_mode) {
    return true;
  }

  if (state.mode == MODE_FWD || state.mode == MODE_5050 || state.mode == MODE_7525) {
    switch (HALDEX_GENERATION) {
      case 1:
        send_standalone_frame_Gen1();
        break;
      case 2:
        send_standalone_frame_Gen2();
        break;
      case 4:
        send_standalone_frame_Gen4();
        break;
      default:
        break;
    }
  }
  return false;
}

bool reset_CAN() {
  // Gen2 doesn't like a missing CAN message, so disable, allow bus to rest for 500ms and restart.
  // todo: look into understanding WHAT the issue is here...
  if (HALDEX_GENERATION == 2) {
    HaldexCAN.reset();
    ChassisCAN.reset();
    delay(500);
    init_CAN();
  }
  return true;
}

#endif
