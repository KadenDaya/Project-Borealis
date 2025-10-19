#include <Arduino.h>
#include "core/Display.h"
#include "core/Touch.h"
#include "core/Menu.h"
#include "core/WebServer.h"

Display display;
Touch touch;
WebInterface webInterface;
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
  
  // Show boot screen
  display.showBootScreen();
  
  // Initialize menu
  menu.init();
  menu.setWebInterface(&webInterface);
  
  // Show main menu
  menu.showMainMenu();
  
  Serial.println("[+] System ready!");
  Serial.println("[*] Touch menu items to navigate!");
}

void loop() {
  // Handle web server
  webInterface.update();
  
  // Handle menu & touch
  menu.update();
  
  delay(10);
}
