```
DMD2
DS3231 RTC Library: real-time clock
Adafruit GFX Library: Required by DMD2
```

"Oxford Green Public School":

- "Oxford" (6 characters) → ~48 pixels
- "Green" (5 characters) → ~40 pixels
- "Public School" (13 characters) → ~104 pixels
- Total: ~192 pixels (approximation).


If display is 64 pixels wide, subtract its width from the total text length:

Totl length = 192 pixels
Display width = 64 pixels
Adjustment value: 192 - 64 = 128
Add a buffer to make scrolling smooth, e.g., 128 + 50 = 178.

```
uint16_t hexToRgb565(String hex) {
  // Remove the '#' if present
  if (hex.startsWith("#")) {
    hex = hex.substring(1);
  }

  // Convert hex string to RGB components
  uint8_t r = strtol(hex.substring(0, 2).c_str(), NULL, 16);
  uint8_t g = strtol(hex.substring(2, 4).c_str(), NULL, 16);
  uint8_t b = strtol(hex.substring(4, 6).c_str(), NULL, 16);

  // Convert to RGB565
  return ((r & 0xF8) << 8) | ((g & 0xFC) << 3) | (b >> 3);
}

```