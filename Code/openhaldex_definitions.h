#ifndef OPENHALDEX_DEFINITIONS_H
#define OPENHALDEX_DEFINITIONS_H

// Helper to calculate how many items an array can hold
#define ARRAYSIZE(a) ((sizeof(a) / sizeof(*(a))) / static_cast<size_t>(!(sizeof(a) % sizeof(*(a)))))

// Helpers to format a number as a binary string for printf
#define BYTE_TO_BINARY_PATTERN "%c%c%c%c%c%c%c%c"
#define BYTE_TO_BINARY(byte) \
  ((byte)&0x80 ? '1' : '0'), \
    ((byte)&0x40 ? '1' : '0'), \
    ((byte)&0x20 ? '1' : '0'), \
    ((byte)&0x10 ? '1' : '0'), \
    ((byte)&0x08 ? '1' : '0'), \
    ((byte)&0x04 ? '1' : '0'), \
    ((byte)&0x02 ? '1' : '0'), \
    ((byte)&0x01 ? '1' : '0')

// Debugging macros
#ifdef ENABLE_DEBUG
#define DEBUG(x, ...) Serial.printf(x "\n", ##__VA_ARGS__)
#define DEBUG_(x, ...) Serial.printf(x, ##__VA_ARGS__)
#else
#define DEBUG(x, ...)
#define DEBUG_(x, ...)
#endif

// Custom data types

enum openhaldex_mode_t {
  MODE_STOCK,
  MODE_FWD,
  MODE_5050,
  MODE_7525,
  MODE_CUSTOM,
  openhaldex_mode_t_MAX
};

// Convert a value of type openhaldex_mode_t to a string.
const char *get_openhaldex_mode_string(openhaldex_mode_t mode) {
  switch (mode) {
    case MODE_STOCK:
      return "STOCK";
    case MODE_FWD:
      return "FWD";
    case MODE_5050:
      return "5050";
    case MODE_7525:
      return "7525";
    case MODE_CUSTOM:
      return "CUSTOM";
    default:
      break;
  }
  return "?";
}

struct lockpoint_t {
  uint8_t speed;
  uint8_t lock;
  uint8_t intensity;
};

#define CUSTOM_LOCK_POINTS_MAX_COUNT 10
struct openhaldex_custom_mode_t {
  lockpoint_t lockpoints[CUSTOM_LOCK_POINTS_MAX_COUNT];
  uint8_t lockpoint_bitfield_high_byte;
  uint8_t lockpoint_bitfield_low_byte;
  uint8_t lockpoint_count;
};

struct openhaldex_state_t {
  openhaldex_mode_t mode;
  openhaldex_custom_mode_t custom_mode;
  uint8_t pedal_threshold;
  bool mode_override;
};

struct bt_packet_t {
  uint8_t len;
  uint8_t data[12];
};

/* steering wheel angle data for Gen4
Byte 5 = counter
Byte 6 = multiplex value?
Byte 7 = 0x77 - all

*/
const uint8_t lws_2[16][8] = {
  { 0x22, 0x00, 0x00, 0x00, 0x80, 0x00, 0xA0, 0xDD },
  { 0x22, 0x00, 0x00, 0x00, 0x80, 0x10, 0x85, 0xCD },
  { 0x22, 0x00, 0x00, 0x00, 0x80, 0x20, 0xEA, 0xBD },
  { 0x22, 0x00, 0x00, 0x00, 0x80, 0x30, 0xCF, 0xAD },
  { 0x22, 0x00, 0x00, 0x00, 0x80, 0x40, 0x34, 0x9D },
  { 0x22, 0x00, 0x00, 0x00, 0x80, 0x50, 0x11, 0x8D },
  { 0x22, 0x00, 0x00, 0x00, 0x80, 0x60, 0x7E, 0x7D },
  { 0x22, 0x00, 0x00, 0x00, 0x80, 0x70, 0x5B, 0x6D },
  { 0x22, 0x00, 0x00, 0x00, 0x80, 0x80, 0xA7, 0x5D },
  { 0x22, 0x00, 0x00, 0x00, 0x80, 0x90, 0x82, 0x4D },
  { 0x22, 0x00, 0x00, 0x00, 0x80, 0xA0, 0xED, 0x3D },
  { 0x22, 0x00, 0x00, 0x00, 0x80, 0xB0, 0xC8, 0x2D },
  { 0x22, 0x00, 0x00, 0x00, 0x80, 0xC0, 0x33, 0x1D },
  { 0x22, 0x00, 0x00, 0x00, 0x80, 0xD0, 0x16, 0x0D },
  { 0x22, 0x00, 0x00, 0x00, 0x80, 0xE0, 0x79, 0xFD },
  { 0x22, 0x00, 0x00, 0x00, 0x80, 0xF0, 0x5C, 0xED }
};

#endif
