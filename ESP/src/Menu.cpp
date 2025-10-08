#include "core/Menu.h"

// Flipper Zero style colors
#define BG_COLOR      BLACK
#define HEADER_COLOR  ORANGE
#define SELECT_COLOR  ORANGE
#define TEXT_COLOR    WHITE
#define BORDER_COLOR  0x7BEF  // Grey
#define SCROLL_COLOR  ORANGE

Menu::Menu(Display* disp, Touch* tch) {
    display = disp;
    touch = tch;
    tft = display->getTFT();
    
    selectedIndex = 0;
    scrollOffset = 0;
    maxVisibleItems = 9;  // More items fit with compact design
    
    rootMenu = nullptr;
    currentMenu = nullptr;
}

Menu::~Menu() {
    // Clean up menu structure (simplified - could be more thorough)
    if (rootMenu) delete rootMenu;
}

void Menu::start() {
    Serial.println("[+] Flipper-style menu started");
    buildMenuStructure();
    currentMenu = rootMenu;
    drawMenu();
}

void Menu::buildMenuStructure() {
    rootMenu = new MenuItem("Main Menu", FOLDER);
    
    // ========== WiFi Menu (ESP32 Marauder Clone) ==========
    MenuItem* wifi = addFolder("WiFi");
    
    // Scan
    MenuItem* scan = addFolder("Scan");
    addSubmenu(scan, addAction("Scan APs", actionPlaceholder));
    addSubmenu(scan, addAction("Scan Stations", actionPlaceholder));
    addSubmenu(scan, addAction("Select AP", actionPlaceholder));
    addSubmenu(scan, addAction("Select Station", actionPlaceholder));
    addSubmenu(wifi, scan);
    
    // Attack
    MenuItem* attack = addFolder("Attack");
    addSubmenu(attack, addAction("Deauth", actionPlaceholder));
    addSubmenu(attack, addAction("Beacon", actionPlaceholder));
    addSubmenu(attack, addAction("Probe", actionPlaceholder));
    addSubmenu(attack, addAction("Rick Roll", actionPlaceholder));
    addSubmenu(wifi, attack);
    
    // Sniff
    MenuItem* sniff = addFolder("Sniff");
    addSubmenu(sniff, addAction("Beacon", actionPlaceholder));
    addSubmenu(sniff, addAction("Deauth", actionPlaceholder));
    addSubmenu(sniff, addAction("Probe", actionPlaceholder));
    addSubmenu(sniff, addAction("EAPOL/PMKID", actionPlaceholder));
    addSubmenu(sniff, addAction("Raw", actionPlaceholder));
    addSubmenu(wifi, sniff);
    
    // List
    MenuItem* list = addFolder("List");
    addSubmenu(list, addAction("APs", actionPlaceholder));
    addSubmenu(list, addAction("Stations", actionPlaceholder));
    addSubmenu(list, addAction("SSIDs", actionPlaceholder));
    addSubmenu(wifi, list);
    
    // Settings
    MenuItem* wifiSettings = addFolder("Settings");
    addSubmenu(wifiSettings, addAction("Channel", actionPlaceholder));
    addSubmenu(wifiSettings, addAction("Force PMKID", actionPlaceholder));
    addSubmenu(wifiSettings, addAction("Save PCAP", actionPlaceholder));
    addSubmenu(wifiSettings, addAction("Clear", actionPlaceholder));
    addSubmenu(wifi, wifiSettings);
    
    addSubmenu(rootMenu, wifi);
    
    // ========== 125 kHz RFID Menu ==========
    MenuItem* rfid125 = addFolder("125 kHz RFID");
    addSubmenu(rfid125, addAction("Read", actionPlaceholder));
    addSubmenu(rfid125, addAction("Write", actionPlaceholder));
    addSubmenu(rfid125, addAction("Emulate", actionPlaceholder));
    addSubmenu(rfid125, addAction("Saved", actionPlaceholder));
    addSubmenu(rootMenu, rfid125);
    
    // ========== 13.56 MHz NFC Menu ==========
    MenuItem* nfc = addFolder("13.56 MHz NFC");
    addSubmenu(nfc, addAction("Read", actionPlaceholder));
    addSubmenu(nfc, addAction("Write", actionPlaceholder));
    addSubmenu(nfc, addAction("Emulate", actionPlaceholder));
    addSubmenu(nfc, addAction("Saved", actionPlaceholder));
    addSubmenu(rootMenu, nfc);
    
    // ========== Other Menus ==========
    MenuItem* ir = addFolder("Infrared");
    addSubmenu(ir, addAction("Learn Remote", actionPlaceholder));
    addSubmenu(ir, addAction("Saved Remotes", actionPlaceholder));
    addSubmenu(ir, addAction("Universal Remote", actionPlaceholder));
    addSubmenu(rootMenu, ir);
    
    MenuItem* badusb = addFolder("Bad USB");
    addSubmenu(badusb, addAction("Scripts", actionPlaceholder));
    addSubmenu(badusb, addAction("New Script", actionPlaceholder));
    addSubmenu(badusb, addAction("Run Script", actionPlaceholder));
    addSubmenu(rootMenu, badusb);
    
    MenuItem* settings = addFolder("Settings");
    addSubmenu(settings, addAction("Display", actionPlaceholder));
    addSubmenu(settings, addAction("Sound", actionPlaceholder));
    addSubmenu(settings, addAction("System Info", actionPlaceholder));
    addSubmenu(settings, addAction("About", actionPlaceholder));
    addSubmenu(rootMenu, settings);
}

MenuItem* Menu::addFolder(const char* name) {
    return new MenuItem(String(name), FOLDER);
}

MenuItem* Menu::addAction(const char* name, void (*action)()) {
    return new MenuItem(String(name), action);
}

void Menu::addSubmenu(MenuItem* parent, MenuItem* child) {
    parent->children.push_back(child);
}

void Menu::update() {
    TouchPoint p = touch->getTouch();
    if (p.valid) {
        handleTouch(p.x, p.y);
        delay(200);  // Debounce
    }
}

void Menu::drawMenu() {
    tft->fillScreen(BG_COLOR);
    drawHeader();
    drawMenuItems();
    drawScrollbar();
    drawFooter();
}

void Menu::drawHeader() {
    // Compact header with breadcrumb
    tft->fillRect(0, 0, 320, 20, HEADER_COLOR);
    tft->setTextColor(BLACK);
    tft->setTextSize(1);
    
    // Draw breadcrumb showing full path
    String breadcrumb = getBreadcrumb();
    tft->setCursor(3, 6);
    tft->print(breadcrumb);
    
    // Draw small arrow on right to indicate more items
    if (currentMenu && currentMenu->children.size() > 0) {
        tft->setCursor(305, 6);
        tft->print("v");
    }
}

void Menu::drawMenuItems() {
    int itemHeight = 22;  // More compact
    int startY = 22;
    int visibleCount = getVisibleItemCount();
    
    for (int i = 0; i < visibleCount; i++) {
        int itemIndex = scrollOffset + i;
        if (itemIndex >= currentMenu->children.size()) break;
        
        MenuItem* item = currentMenu->children[itemIndex];
        int y = startY + (i * itemHeight);
        
        // Draw selection
        if (itemIndex == selectedIndex) {
            tft->fillRect(0, y, 308, itemHeight - 1, SELECT_COLOR);
            tft->setTextColor(BLACK);
        } else {
            tft->setTextColor(TEXT_COLOR);
        }
        
        // Draw item text - smaller, more compact
        tft->setTextSize(1);
        tft->setCursor(5, y + 7);
        
        // Add folder icon
        if (item->type == FOLDER) {
            tft->print("> ");
        } else {
            tft->print("  ");
        }
        
        tft->print(item->name);
        
        // Draw subtle separator line
        if (itemIndex != selectedIndex) {
            tft->drawFastHLine(0, y + itemHeight - 1, 308, BORDER_COLOR);
        }
    }
}

void Menu::drawScrollbar() {
    if (currentMenu->children.size() <= maxVisibleItems) return;
    
    int scrollbarHeight = 198;  // Adjusted for new layout
    int scrollbarY = 22;
    int scrollbarX = 312;
    int scrollbarWidth = 3;
    
    // Background
    tft->fillRect(scrollbarX, scrollbarY, scrollbarWidth, scrollbarHeight, BORDER_COLOR);
    
    // Calculate thumb position and size
    float ratio = (float)maxVisibleItems / currentMenu->children.size();
    int thumbHeight = max(8, (int)(scrollbarHeight * ratio));
    float scrollRatio = (float)scrollOffset / (currentMenu->children.size() - maxVisibleItems);
    int thumbY = scrollbarY + (int)((scrollbarHeight - thumbHeight) * scrollRatio);
    
    // Draw thumb
    tft->fillRect(scrollbarX, thumbY, scrollbarWidth, thumbHeight, SCROLL_COLOR);
}

void Menu::drawFooter() {
    // Split footer into two rows for more space
    tft->fillRect(0, 220, 320, 20, HEADER_COLOR);
    tft->setTextColor(BLACK);
    tft->setTextSize(1);
    
    // Top line - Controls and Project name
    tft->setCursor(3, 224);
    if (navigationStack.size() > 0) {
        tft->print("BACK");
    }
}

String Menu::getBreadcrumb() {
    String breadcrumb = "Main";
    
    // Add navigation path
    for (int i = 0; i < navigationStack.size(); i++) {
        breadcrumb += " > ";
        breadcrumb += navigationStack[i]->name;
    }
    
    // Add current menu if we're not at root
    if (currentMenu != rootMenu) {
        breadcrumb += " > ";
        breadcrumb += currentMenu->name;
    }
    
    // Truncate if too long (max ~50 chars for display)
    if (breadcrumb.length() > 50) {
        breadcrumb = "..." + breadcrumb.substring(breadcrumb.length() - 47);
    }
    
    return breadcrumb;
}

int Menu::getVisibleItemCount() {
    return min((int)currentMenu->children.size() - scrollOffset, maxVisibleItems);
}

void Menu::handleTouch(int x, int y) {
    // Check for back button (footer left)
    if (y > 220 && x < 80 && navigationStack.size() > 0) {
        goBack();
        return;
    }
    
    // Check for menu items
    if (y >= 22 && y < 220) {
        int itemIndex = (y - 22) / 22 + scrollOffset;
        if (itemIndex < currentMenu->children.size()) {
            selectItem(itemIndex);
        }
    }
    
    // TODO: Add scroll gesture detection
}

void Menu::selectItem(int index) {
    selectedIndex = index;
    MenuItem* item = currentMenu->children[index];
    
    Serial.print("Selected: ");
    Serial.println(item->name);
    
    if (item->type == FOLDER) {
        enterFolder(item);
    } else if (item->action) {
        // Execute action
        item->action();
        // Redraw menu after action
        delay(100);
        drawMenu();
    }
}

void Menu::enterFolder(MenuItem* folder) {
    navigationStack.push_back(currentMenu);
    currentMenu = folder;
    selectedIndex = 0;
    scrollOffset = 0;
    drawMenu();
}

void Menu::goBack() {
    if (navigationStack.size() > 0) {
        currentMenu = navigationStack.back();
        navigationStack.pop_back();
        selectedIndex = 0;
        scrollOffset = 0;
        drawMenu();
    }
}

// Placeholder action
void Menu::actionPlaceholder() {
    Serial.println("[!] Action not implemented yet");
}
