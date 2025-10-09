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

  // Edit the frames if configured as Gen1.
  if (HALDEX_GENERATION == 1) {
    switch (frame.id) {
      case MOTOR1_ID:
        frame.buf[1] = get_lock_target_adjusted_value(0xFE, false);
        frame.buf[2] = 0x21;
        frame.buf[3] = get_lock_target_adjusted_value(0x4E, false);
        frame.buf[6] = get_lock_target_adjusted_value(0x16, true);
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
  } else if (HALDEX_GENERATION == 2) {
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
  }
  // Edit the frames if configured as Gen4.
  else if (HALDEX_GENERATION == 4) {
    switch (frame.id) {
      case MOTOR1_ID:
        frame.buf[1] = get_lock_target_adjusted_value(0xFE, false);
        frame.buf[2] = 0x20;
        frame.buf[3] = get_lock_target_adjusted_value(0x4E, false);
        frame.buf[6] = get_lock_target_adjusted_value(0x16, true);
        break;
      case MOTOR3_ID:
        frame.buf[2] = get_lock_target_adjusted_value(0xFE, false);
        frame.buf[7] = get_lock_target_adjusted_value(0x01, false);
        break;
      case MOTOR6_ID:
        break;
      case BRAKES1_ID:
        frame.buf[1] = get_lock_target_adjusted_value(0x00, false);
        frame.buf[2] = get_lock_target_adjusted_value(0xFE, false);
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
  }
}

#endif
