#include <DMD2.h>
#include <fonts/SystemFont5x7.h>
#include <Wire.h>
#include <RTClib.h>

int WIDTH 32
int PANELS 3
SoftDMD dmd(WIDTH * PANELS, 16, 1);

RTC_DS3231 rtc;

void setup() {
  Serial.begin(9600);

  dmd.setBrightness(255);
  dmd.begin();

  if (!rtc.begin()) {
    Serial.println("Couldn't find RTC");
    while (1);
  }
  if (rtc.lostPower()) {
    Serial.println("RTC lost power, setting the time.");
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  }
}

void loop() {
  dmd.clearScreen();

  dmd.selectFont(SystemFont5x7);
  dmd.drawMarquee("Oxford Dreen Public School", 27, 0, 0);

  DateTime now = rtc.now();
  char timeStr[9];
  sprintf(timeStr, "%02d:%02d", now.hour(), now.second());
  dmd.drawString(0, 9, timeStr, GRAPHICS_NORMAL);

  dmd.refresh();

  delay(1);
}
