#ifndef OPENHALDEX_CALCULATIONS_H
#define OPENHALDEX_CALCULATIONS_H

// Only executed when in MODE_FWD/MODE_5050/MODE_CUSTOM
float get_lock_target_adjustment() {
  // Handle FWD and 5050 modes.
  switch (state.mode) {
    case MODE_FWD:
      return 0;

    case MODE_5050:
      if (received_pedal_value >= state.pedal_threshold || state.pedal_threshold == 0 || state.mode_override) {
        return 100;
      }
      return 0;

    default:
      return 0;
      break;
  }

  // Getting here means it's in not FWD or 5050.

  // Check if locking is necessary.
  if (!(received_pedal_value >= state.pedal_threshold || state.pedal_threshold == 0 || state.mode_override)) {
    return 0;
  }

  // Find the pair of lockpoints between which the vehicle speed falls.
  lockpoint_t lp_lower = state.custom_mode.lockpoints[0];
  lockpoint_t lp_upper = state.custom_mode.lockpoints[state.custom_mode.lockpoint_count - 1];

  // Look for the lockpoint above the current vehicle speed.
  for (uint8_t i = 0; i < state.custom_mode.lockpoint_count; i++) {
    if (received_vehicle_speed <= state.custom_mode.lockpoints[i].speed) {
      lp_upper = state.custom_mode.lockpoints[i];
      lp_lower = state.custom_mode.lockpoints[(i == 0) ? 0 : (i - 1)];
      break;
    }
  }

  // Handle the case where the vehicle speed is lower than the lowest lockpoint.
  if (received_vehicle_speed <= lp_lower.speed) {
    return lp_lower.lock;
  }

  // Handle the case where the vehicle speed is higher than the highest lockpoint.
  if (received_vehicle_speed >= lp_upper.speed) {
    return lp_upper.lock;
  }

  // In all other cases, interpolation is necessary.
  float inter = (float)(lp_upper.speed - lp_lower.speed) / (float)(received_vehicle_speed - lp_lower.speed);

  // Calculate the target.
  float target = lp_lower.lock + ((float)(lp_upper.lock - lp_lower.lock) / inter);
  DEBUG("lp_upper:%d@%d lp_lower:%d@%d speed:%d target:%0.2f", lp_upper.lock, lp_upper.speed, lp_lower.lock, lp_lower.speed, received_vehicle_speed, target);
  return target;
}

// Only executed when in MODE_FWD/MODE_5050/MODE_CUSTOM
uint8_t get_lock_target_adjusted_value(uint8_t value, bool invert) {
  // Handle 5050 mode.
  if (state.mode == MODE_5050) {
    if (received_pedal_value >= state.pedal_threshold || state.pedal_threshold == 0) {
      return (invert ? (0xFE - value) : value);
    }
    return (invert ? 0xFE : 0x00);
  }

  // Handle FWD and CUSTOM modes.

  // No correction is necessary if the target is already 0.
  if (lock_target == 0) {
    return (invert ? 0xFE : 0x00);
  }

  // Apply a linear correction (hacky).
  float correction_factor = ((float)lock_target / 2) + 20;
  uint8_t corrected_value = value * (correction_factor / 100);
  return (invert ? (0xFE - corrected_value) : corrected_value);
}

// Only executed when in MODE_FWD/MODE_5050/MODE_CUSTOM
void get_lock_data(CAN_message_t &frame) {
  // Get the initial lock target.
  lock_target = get_lock_target_adjustment();
  if (state.mode == MODE_7525) {
    lock_target = 30;
  }

// Edit the frames if configured as Gen1...
#if (HALDEX_GENERATION == 1)
  switch (frame.id) {
    case MOTOR1_ID:
      //frame.buf[1] = get_lock_target_adjusted_value(0xFE, false);
      //frame.buf[2] = 0x21;
      //frame.buf[3] = get_lock_target_adjusted_value(0x4E, false);
      //frame.buf[6] = get_lock_target_adjusted_value(0x16, true);

      frame.buf[0] = 0x00;                                         // these must play a factor - achieves ~169 without
      frame.buf[1] = get_lock_target_adjusted_value(0xFE, false);  // rpm low byte
      frame.buf[2] = 0x21;                                         // rpm high byte
      frame.buf[3] = get_lock_target_adjusted_value(0x4E, false);  // set RPM to a value so the pre-charge pump runs
      frame.buf[4] = 0x00;                                         // these must play a factor - achieves ~169 without
      frame.buf[5] = 0x00;                                         // these must play a factor - achieves ~169 without
      frame.buf[6] = get_lock_target_adjusted_value(0x16, false);  // set to a low value to control the req. transfer torque.  Main control value for Gen1
      frame.buf[7] = 0x00;                                         // these must play a factor - achieves ~169 without
      break;
    case MOTOR3_ID:
      frame.buf[2] = get_lock_target_adjusted_value(0xFE, false);
      frame.buf[7] = get_lock_target_adjusted_value(0xFE, false);
      break;
    case BRAKES1_ID:
      frame.buf[1] = get_lock_target_adjusted_value(0x00, false);
      frame.buf[2] = 0x00;
      frame.buf[3] = get_lock_target_adjusted_value(0x0A, false);
      break;
    case BRAKES3_ID:
      frame.buf[0] = get_lock_target_adjusted_value(0xFE, false);
      frame.buf[1] = 0x0A;
      frame.buf[2] = get_lock_target_adjusted_value(0xFE, false);
      frame.buf[3] = 0x0A;
      frame.buf[4] = 0x00;
      frame.buf[5] = 0x0A;
      frame.buf[6] = 0x00;
      frame.buf[7] = 0x0A;
      break;
  }
#endif

// Edit the frames if configured as Gen2...
#if (HALDEX_GENERATION == 2)
  // Edit the frames if configured as Gen2.  Currently copied from Gen4...
  switch (frame.id) {
    case MOTOR1_ID:
      frame.buf[1] = get_lock_target_adjusted_value(0xFE, false);
      frame.buf[2] = 0x21;
      frame.buf[3] = get_lock_target_adjusted_value(0x4E, false);
      frame.buf[6] = get_lock_target_adjusted_value(0xFE, false);
      break;
    case MOTOR3_ID:
      frame.buf[2] = get_lock_target_adjusted_value(0xFE, false);
      frame.buf[7] = get_lock_target_adjusted_value(0x01, false);  // gen1 is 0xFE, gen4 is 0x01
      break;
    case MOTOR6_ID:
      break;
    case BRAKES1_ID:
      frame.buf[0] = get_lock_target_adjusted_value(0x80, false);
      frame.buf[1] = get_lock_target_adjusted_value(0x41, false);
      frame.buf[2] = get_lock_target_adjusted_value(0xFE, false);  // gen1 is 0x00, gen4 is 0xFE
      frame.buf[3] = 0x0A;
      break;
    case BRAKES2_ID:
      frame.buf[4] = get_lock_target_adjusted_value(0x7F, false);  // big affect(!) 0x7F is max
      frame.buf[5] = get_lock_target_adjusted_value(0xFE, false);  // no effect.  Was 0x6E
      break;
    case BRAKES3_ID:
      frame.buf[0] = get_lock_target_adjusted_value(0xFE, false);
      frame.buf[1] = 0x0A;
      frame.buf[2] = get_lock_target_adjusted_value(0xFE, false);
      frame.buf[3] = 0x0A;
      frame.buf[4] = 0x00;
      frame.buf[5] = 0x0A;
      frame.buf[6] = 0x00;
      frame.buf[7] = 0x0A;
      break;
  }
#endif
// Edit the frames if configured as Gen4...
#if (HALDEX_GENERATION == 4)
  switch (frame.id) {
    case mLW_1:
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
      break;
    case MOTOR1_ID:
      frame.buf[1] = get_lock_target_adjusted_value(0xFE, false);  // has effect
      frame.buf[2] = get_lock_target_adjusted_value(0x20, false);  // RPM low byte no effect was 0x20
      frame.buf[3] = get_lock_target_adjusted_value(0x4E, false);  // RPM high byte.  Will disable pre-charge pump if 0x00.  Sets raw = 8, coupling open
      frame.buf[4] = get_lock_target_adjusted_value(0xFE, false);  // MDNORM no effect
      frame.buf[5] = get_lock_target_adjusted_value(0xFE, false);  // Pedal no effect
      frame.buf[6] = get_lock_target_adjusted_value(0x16, false);  // idle adaptation?  Was slippage?
      frame.buf[7] = get_lock_target_adjusted_value(0xFE, false);  // Fahrerwunschmoment req. torque?
      break;
    case MOTOR3_ID:
      //frame.buf[2] = get_lock_target_adjusted_value(0xFE, false);
      //frame.buf[7] = get_lock_target_adjusted_value(0x01, false);
      break;
    case MOTOR6_ID:
      break;
    case BRAKES1_ID:
      frame.buf[0] = 0x20;                                         // ASR 0x04 sets bit 4.  0x08 removes set.  Coupling open/closed
      frame.buf[1] = 0x40;                                         // can use to disable (>130 dec).  Was 0x00; 0x41?  0x43?
      frame.buf[4] = get_lock_target_adjusted_value(0xFE, false);  // was 0xFE miasrl no effect
      frame.buf[5] = get_lock_target_adjusted_value(0xFE, false);  // was 0xFE miasrs no effect
      break;
    case BRAKES2_ID:
      frame.buf[4] = get_lock_target_adjusted_value(0x7F, false);  // big affect(!) 0x7F is max
      break;
    case BRAKES3_ID:
      frame.buf[0] = get_lock_target_adjusted_value(0xB6, false);  // front left low
      frame.buf[1] = 0x07;                                         // front left high
      frame.buf[2] = get_lock_target_adjusted_value(0xCC, false);  // front right low
      frame.buf[3] = 0x07;                                         // front right high
      frame.buf[4] = get_lock_target_adjusted_value(0xD2, false);  // rear left low
      frame.buf[5] = 0x07;                                         // rear left high
      frame.buf[6] = get_lock_target_adjusted_value(0xD2, false);  // rear right low
      frame.buf[7] = 0x07;                                         // rear right high
      break;

    case BRAKES4_ID:
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
      break;
  }
#endif
}
#endif
