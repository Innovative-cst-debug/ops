#include <DMD2.h>
#include <SPI.h>

// width and height of panels
#define DISPLAYS_WIDE 3
#define DISPLAYS_HIGH 1

// Init library
SPIDMD dmd(DISPLAYS_WIDE,DISPLAYS_HIGH);
SoftDMD canvas(dmd);

void setup() {
  dmd.begin();                  // Initi display
  dmd.setBrightness(255);
  canvas.selectFont(SystemFont5x7);
}

void loop() {
  static int offsetX = dmd.width();
  const char* text = "Oxford green public school";

  canvas.clear();
  canvas.drawString(offsetX, 0, text);

  offsetX--;                    
  if (offsetX < -canvas.stringWidth(text)) {
    offsetX = dmd.width();
  }

  delay(50);
}
