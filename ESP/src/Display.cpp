#include "core/Display.h"

Display::Display() : tft(TFT_CS, TFT_DC, TFT_MOSI, TFT_SCLK, TFT_RST, TFT_MISO) {
}

void Display::init() {
    // Turn on backlight
    pinMode(TFT_LED, OUTPUT);
    digitalWrite(TFT_LED, HIGH);
    
    // Initialize display
    tft.begin();
    tft.setRotation(3); // Landscape mode
    tft.fillScreen(BLACK);
    
    Serial.println("[+] Display initialized");
}

Adafruit_ILI9341* Display::getTFT() {
    return &tft;
}

