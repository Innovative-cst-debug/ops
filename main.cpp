#include <PxMatrix.h>

#define P_LAT 16
#define P_A 5
#define P_B 4
#define P_C 15
#define P_D 12
#define P_E 0
#define P_OE 2

// Define the display dimensions
#define WIDTH 64
#define HEIGHT 32

PxMATRIX display(WIDTH, HEIGHT, P_LAT, P_OE, P_A, P_B, P_C, P_D);

int scrollPosition = WIDTH;

void setup() {
  display.begin(16);
  display.setBrightness(50);
  display.clearDisplay();
}

void loop() {
  display.clearDisplay();

  // Set the text color for "Oxford"
  display.setTextColor(display.color565(255, 255, 255)); // White
  display.setCursor(scrollPosition, 0);
  display.print("Oxford ");

  // Set the text color for "Green"
  display.setTextColor(display.color565(0, 255, 0)); // Green
  display.print("Green ");

  // Set the text color for "Public School"
  display.setTextColor(display.color565(255, 255, 255)); // White
  display.print("Public School");

  display.showBuffer();

  // Adjust scroll position
  scrollPosition--;
  if (scrollPosition < -200) { // Adjust to match the length of the text
    scrollPosition = WIDTH;
  }

  delay(50); // Adjust scroll speed
}
