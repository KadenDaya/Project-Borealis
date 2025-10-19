#ifndef MENU_H
#define MENU_H

#include <Arduino.h>
#include "Display.h"
#include "Touch.h"

// Forward declaration
class WebInterface;

enum MenuState {
    MAIN_MENU,
    WIFI_SUBMENU,
    BT_SUBMENU,
    NFC_SUBMENU,
    RFID_SUBMENU,
    ONNET_SUBMENU,
    WEBUI_SCREEN
};

class Menu {
public:
    Menu(Display* display, Touch* touch);
    void init();
    void setWebInterface(WebInterface* web);
    void showMainMenu();
    void update();
    
private:
    Display* display;
    Adafruit_ILI9341* tft;
    Touch* touchScreen;
    WebInterface* webUI;
    int selectedIndex;
    MenuState currentState;
    
    void drawMenuItem(int index, String text, bool selected);
    void drawHeader(String title);
    void handleTouch(int x, int y);
    void showSubmenu(String title, String items[], int itemCount);
    void showWebUIScreen();
    void goBack();
};

#endif
