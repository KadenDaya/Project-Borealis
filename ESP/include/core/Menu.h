#ifndef MENU_H
#define MENU_H

#include "Display.h"
#include "Touch.h"
#include <vector>

enum MenuItemType {
    FOLDER,
    ACTION
};

struct MenuItem {
    String name;
    MenuItemType type;
    std::vector<MenuItem*> children;
    void (*action)();  // Function pointer for actions
    
    MenuItem(String n, MenuItemType t) : name(n), type(t), action(nullptr) {}
    MenuItem(String n, void (*act)()) : name(n), type(ACTION), action(act) {}
};

class Menu {
public:
    Menu(Display* display, Touch* touch);
    ~Menu();
    
    void start();
    void update();
    
private:
    Display* display;
    Touch* touch;
    Adafruit_ILI9341* tft;
    
    // Menu structure
    MenuItem* rootMenu;
    MenuItem* currentMenu;
    std::vector<MenuItem*> navigationStack;
    
    int selectedIndex;
    int scrollOffset;
    int maxVisibleItems;
    
    // Building menu structure
    void buildMenuStructure();
    MenuItem* addFolder(const char* name);
    MenuItem* addAction(const char* name, void (*action)());
    void addSubmenu(MenuItem* parent, MenuItem* child);
    
    // Drawing
    void drawMenu();
    void drawHeader();
    void drawMenuItems();
    void drawScrollbar();
    void drawFooter();
    
    // Navigation
    void handleTouch(int x, int y);
    void selectItem(int index);
    void goBack();
    void enterFolder(MenuItem* folder);
    
    // Utility
    String getBreadcrumb();
    int getVisibleItemCount();
    
    // Action handlers (placeholders for now)
    static void actionPlaceholder();
    static void actionBack();
};

#endif
