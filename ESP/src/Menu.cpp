#include "core/Menu.h"
#include "core/WebServer.h"

Menu::Menu(Display* disp, Touch* touch) {
    display = disp;
    tft = display->getTFT();
    touchScreen = touch;
    webUI = nullptr;
    selectedIndex = 0;
    currentState = MAIN_MENU;
}

void Menu::init() {
    Serial.println("[+] Menu initialized");
}

void Menu::setWebInterface(WebInterface* web) {
    webUI = web;
}

void Menu::showMainMenu() {
    currentState = MAIN_MENU;
    selectedIndex = 0;
    
    tft->fillScreen(BLACK);
    
    // Nicer header with colored bar
    tft->fillRect(0, 0, 320, 25, CYAN);
    tft->setTextColor(BLACK);
    tft->setTextSize(2);
    tft->setCursor(10, 6);
    tft->print("PROJECT BOREALIS");
    
    // Draw all menu items with better spacing
    drawMenuItem(0, "WiFi", selectedIndex == 0);
    drawMenuItem(1, "Bluetooth", selectedIndex == 1);
    drawMenuItem(2, "13.56 MHz NFC", selectedIndex == 2);
    drawMenuItem(3, "125 kHz RFID", selectedIndex == 3);
    drawMenuItem(4, "WebUI", selectedIndex == 4);
    
    // Footer with version
    tft->fillRect(0, 220, 320, 20, DARKGREY);
    tft->setTextColor(BLACK);
    tft->setTextSize(1);
    tft->setCursor(10, 227);
    tft->print("v1.0.0 | Made with ");
    tft->setTextColor(RED);
    tft->print("<3");
    tft->setTextColor(BLACK);
    tft->print(" by Kaden");
}

void Menu::drawHeader(String title) {
    tft->setTextSize(1);
    tft->setTextColor(CYAN);
    tft->setCursor(5, 5);
    tft->print(title);
    tft->drawFastHLine(0, 18, 320, DARKGREY);
}

void Menu::drawMenuItem(int index, String text, bool selected) {
    int startY = 35;
    int itemHeight = 36;
    int y = startY + (index * itemHeight);
    int leftMargin = 15;
    
    // Draw item background for selected
    if (selected) {
        tft->fillRoundRect(5, y, 310, itemHeight - 4, 8, CYAN);
        tft->setTextColor(BLACK);
    } else {
        // Draw subtle border for unselected
        tft->drawRoundRect(5, y, 310, itemHeight - 4, 8, DARKGREY);
        tft->setTextColor(WHITE);
    }
    
    tft->setTextSize(2);
    tft->setCursor(leftMargin, y + 10);
    tft->print(text);
}

void Menu::update() {
    TouchPoint p = touchScreen->getTouch();
    if (p.valid) {
        handleTouch(p.x, p.y);
        delay(300);
    }
}

void Menu::handleTouch(int x, int y) {
    Serial.print("[TOUCH] State=");
    Serial.print(currentState);
    Serial.print(" X=");
    Serial.print(x);
    Serial.print(" Y=");
    Serial.print(y);
    
    // Check for back button - MUCH LARGER AREA (bottom 50px)
    if (y >= 190) {
        Serial.println(" -> BACK AREA!");
        if (currentState != MAIN_MENU) {
            Serial.println("[MENU] Going back to main menu!");
            goBack();
            return;
        }
    }
    Serial.println();
    
    // Main menu touch
    if (currentState == MAIN_MENU) {
        int startY = 35;
        int itemHeight = 36;
        
        if (y < 18) return;
        
        int touchedItem = (y - startY) / itemHeight;
        
        Serial.print("[MENU] Item #");
        Serial.println(touchedItem);
        
        if (touchedItem >= 0 && touchedItem <= 4) {
            selectedIndex = touchedItem;
            
            switch(touchedItem) {
                case 0: // WiFi
                    {
                        String items[] = {"Reconnaissance", "Attacks"};
                        showSubmenu("< WiFi", items, 2);
                        currentState = WIFI_SUBMENU;
                    }
                    break;
                    
                case 1: // Bluetooth
                    {
                        String items[] = {"Coming Soon..."};
                        showSubmenu("< Bluetooth", items, 1);
                        currentState = BT_SUBMENU;
                    }
                    break;
                    
                case 2: // 13.56 MHz NFC
                    {
                        String items[] = {"Read", "Write", "Emulate", "Saves"};
                        showSubmenu("< 13.56 MHz NFC", items, 4);
                        currentState = NFC_SUBMENU;
                    }
                    break;
                    
                case 3: // 125 kHz RFID
                    {
                        String items[] = {"Read", "Write", "Emulate", "Saves"};
                        showSubmenu("< 125 kHz RFID", items, 4);
                        currentState = RFID_SUBMENU;
                    }
                    break;
                    
                case 4: // WebUI
                    if (webUI) {
                        Serial.println("[+] Starting WebUI...");
                        webUI->init();
                        webUI->begin();
                        showWebUIScreen();
                        currentState = WEBUI_SCREEN;
                    }
                    break;
            }
        }
    }
    // Handle submenu touches
    else if (currentState != WEBUI_SCREEN) {
        int startY = 35;
        int itemHeight = 36;
        
        if (y >= startY && y < 200) {
            int touchedItem = (y - startY) / itemHeight;
            Serial.print("[SUBMENU] Item #");
            Serial.println(touchedItem);
            
            // Placeholder - would execute submenu actions here
            tft->fillRect(0, 220, 320, 20, BLACK);
            tft->setTextColor(GREEN);
            tft->setTextSize(1);
            tft->setCursor(10, 225);
            tft->print("Selected item ");
            tft->print(touchedItem);
            delay(500);
        }
    }
}

void Menu::showSubmenu(String title, String items[], int itemCount) {
    tft->fillScreen(BLACK);
    
    // Header with back arrow
    tft->fillRect(0, 0, 320, 25, CYAN);
    tft->setTextColor(BLACK);
    tft->setTextSize(2);
    tft->setCursor(10, 6);
    tft->print(title);
    
    selectedIndex = 0;
    
    // Draw submenu items
    for (int i = 0; i < itemCount && i < 5; i++) {
        drawMenuItem(i, items[i], i == 0);
    }
    
    // Draw back button
    tft->fillRect(0, 220, 320, 20, DARKGREY);
    tft->setTextColor(BLACK);
    tft->setTextSize(1);
    tft->setCursor(10, 227);
    tft->print("< BACK TO MENU");
}

void Menu::showWebUIScreen() {
    tft->fillScreen(BLACK);
    
    // Console/CLI style
    tft->setTextSize(1);
    tft->setTextColor(GREEN);
    tft->setCursor(5, 5);
    tft->println("root@borealis:~#");
    
    tft->setTextColor(WHITE);
    tft->setCursor(5, 20);
    tft->println("> Initializing WebUI...");
    delay(300);
    
    tft->setCursor(5, 35);
    tft->setTextColor(GREEN);
    tft->println("[OK] WiFi AP Started");
    delay(200);
    
    tft->setCursor(5, 50);
    tft->setTextColor(GREEN);
    tft->println("[OK] Web Server Running");
    delay(200);
    
    // Connection details box
    tft->drawRect(5, 70, 310, 90, CYAN);
    
    tft->setTextColor(CYAN);
    tft->setCursor(15, 80);
    tft->println("NETWORK INFORMATION");
    
    tft->setTextColor(WHITE);
    tft->setCursor(15, 95);
    tft->print("SSID: ");
    tft->setTextColor(CYAN);
    tft->println("Project-Borealis");
    
    tft->setTextColor(WHITE);
    tft->setCursor(15, 108);
    tft->print("Password: ");
    tft->setTextColor(CYAN);
    tft->println("borealis123");
    
    tft->setTextColor(WHITE);
    tft->setCursor(15, 121);
    tft->print("WebUI: ");
    tft->setTextColor(GREEN);
    tft->println("http://192.168.0.1");
    
    tft->setTextColor(YELLOW);
    tft->setCursor(15, 140);
    tft->println("Awaiting connection...");
    
    // Status indicator
    tft->fillCircle(20, 175, 5, GREEN);
    tft->setTextColor(GREEN);
    tft->setCursor(35, 170);
    tft->println("ONLINE");
    
    // Back button
    tft->fillRect(0, 220, 320, 20, DARKGREY);
    tft->setTextColor(BLACK);
    tft->setTextSize(1);
    tft->setCursor(10, 227);
    tft->print("< BACK");
}

void Menu::goBack() {
    Serial.println("[MENU] Going back...");
    showMainMenu();
}
