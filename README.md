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