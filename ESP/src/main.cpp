#include <Arduino.h>
#include "core/Display.h"
#include "core/Touch.h"
#include "core/Menu.h"

// Initialize modules
Display display;
Touch touch;
Menu menu(&display, &touch);

void setup() {
  Serial.begin(115200);
  delay(1000);
  
  Serial.println("\n=================================");
  Serial.println("  PROJECT BOREALIS - ESP32");
  Serial.println("=================================\n");
  
  // Initialize hardware
  display.init();
  touch.init();
  
  // Start the menu system
  menu.start();
  
  Serial.println("\n[+] System ready!");
}

void loop() {
  menu.update();
}
