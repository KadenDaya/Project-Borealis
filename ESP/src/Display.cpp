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

void Display::showBootScreen() {
    tft.fillScreen(BLACK);
    
    int leftMargin = 10;
    
    // Title
    tft.setTextSize(3);
    tft.setTextColor(CYAN);
    tft.setCursor(leftMargin, 25);
    tft.println("PROJECT");
    
    tft.setCursor(leftMargin, 55);
    tft.println("BOREALIS");
    
    // Subtitle
    tft.setTextSize(1);
    tft.setTextColor(LIGHTGREY);
    tft.setCursor(leftMargin, 90);
    tft.println("All in one wireless pentester");
    
    // Version
    tft.setTextSize(1);
    tft.setTextColor(DARKGREY);
    tft.setCursor(leftMargin, 105);
    tft.println("v1.0.0");
    
    // Made by
    tft.setTextSize(1);
    tft.setTextColor(PINK);
    tft.setCursor(leftMargin, 120);
    tft.print("Made with ");
    tft.setTextColor(RED);
    tft.print("<3");
    tft.setTextColor(PINK);
    tft.println(" By Kaden Daya");
    
    // Loading bar
    int barX = leftMargin;
    int barY = 155;
    int barWidth = 200;
    int barHeight = 20;
    
    tft.drawRect(barX - 2, barY - 2, barWidth + 4, barHeight + 4, CYAN);
    
    // Animate loading bar
    for (int i = 0; i <= 100; i += 2) {
        drawLoadingBar(barX, barY, barWidth, barHeight, i);
        
        tft.fillRect(leftMargin, 190, 240, 20, BLACK);
        tft.setTextSize(1);
        tft.setTextColor(WHITE);
        tft.setCursor(leftMargin, 195);
        
        if (i < 30) {
            tft.println("Initializing hardware...");
        } else if (i < 60) {
            tft.println("Loading modules...");
        } else if (i < 90) {
            tft.println("Starting system...");
        } else {
            tft.println("Ready!");
        }
        
        delay(20);
    }
    
    delay(500);
    tft.fillScreen(BLACK);
}

void Display::drawLoadingBar(int x, int y, int width, int height, int progress) {
    tft.fillRect(x, y, width, height, BLACK);
    
    int filledWidth = (width * progress) / 100;
    
    for (int i = 0; i < filledWidth; i++) {
        uint16_t color = tft.color565(0, 150 + (i % 105), 255);
        tft.fillRect(x + i, y, 1, height, color);
    }
    
    tft.fillRect(x + width + 8, y, 45, height, BLACK);
    
    tft.setTextSize(2);
    tft.setTextColor(WHITE, BLACK);
    tft.setCursor(x + width + 10, y + 2);
    tft.print(progress);
    tft.print("%");
}

Adafruit_ILI9341* Display::getTFT() {
    return &tft;
}

