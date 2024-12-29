#include <DMD2.h>
#include <SPI.h>

// width and height of  display i panels
#define DISPLAYS_WIDE 3
#define DISPLAYS_HIGH 1

// Ini library
SPIDMD dmd(DISPLAYS_WIDE, DISPLAYS_HIGH);
SoftDMD canvas(dmd);

void setup() {
  dmd.begin(); // Init display
  dmd.setBrightness(255);
  
  canvas.selectFont(SystemFont5x7);
  dmd.setColor(COLOR_RGB(255, 255, 255));
}

void loop() {
  static int offsetX = 0; // X offset for scrolling
  const char* text1 = "Oxford ";
  const char* text2 = "green ";
  const char* text3 = "public school";

  canvas.clear();
  
  dmd.setColor(COLOR_RGB(255, 255, 255));
  canvas.drawString(offsetX, 0, text1);
  
  int width1 = canvas.stringWidth(text1);
  
  dmd.setColor(COLOR_RGB(0, 0, 255));
  canvas.drawString(offsetX + width1, 0, text2);
  
  int width2 = canvas.stringWidth(text2);

  dmd.setColor(COLOR_RGB(255, 255, 255));
  canvas.drawString(offsetX + width1 + width2, 0, text3);


  offsetX--;
  if (offsetX < -canvas.stringWidth(text1) - width1 - width2) {
    offsetX = dmd.width(); // Reset offset when text scrolls out
  }
  
  delay(50);
}
