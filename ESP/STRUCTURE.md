# Project Borealis - Code Structure

## 🎯 Philosophy
**HEAVILY MODULARIZED** - `main.cpp` is clean as fuck, just calls `menu.start()`

## 📁 File Structure

```
ESP/
├── include/core/        # Header files
│   ├── Display.h        # Display hardware abstraction
│   ├── Touch.h          # Touch controller abstraction  
│   └── Menu.h           # Menu system
│
├── src/                 # Implementation files
│   ├── main.cpp         # ⭐ MINIMAL - Just init & menu.start()
│   ├── Display.cpp      # Display implementation
│   ├── Touch.cpp        # Touch implementation
│   └── Menu.cpp         # Menu implementation
│
└── platformio.ini       # Project config & dependencies
```

## 🚀 Usage

### main.cpp (Clean as shit)
```cpp
#include "core/Display.h"
#include "core/Touch.h"
#include "core/Menu.h"

Display display;
Touch touch;
Menu menu(&display, &touch);

void setup() {
  display.init();
  touch.init();
  menu.start();
}

void loop() {
  menu.update();
}
```

## 🧩 Modules

### Display Class
- **Encapsulates**: ILI9341 TFT display
- **Methods**: `init()`, `getTFT()`
- **Hardware**: Software SPI on custom pins

### Touch Class  
- **Encapsulates**: XPT2046 touchscreen
- **Methods**: `init()`, `getTouch()`, `isTouched()`
- **Hardware**: Separate SPI bus from display
- **Returns**: TouchPoint struct with x, y, valid

### Menu Class
- **Encapsulates**: Entire menu system
- **Methods**: `start()`, `update()`
- **Features**: 6 menu items, touch navigation, modular pages

## 🔧 Adding New Features

### Add a new menu page:
1. Add method declaration in `Menu.h`
2. Implement in `Menu.cpp`  
3. Add to `openMenuItem()` switch case
4. Add menu item string to constructor

### Add a new hardware module:
1. Create `include/core/YourModule.h`
2. Create `src/YourModule.cpp`
3. Initialize in `main.cpp setup()`
4. Use anywhere via class instance

## 💡 Design Principles
- **OOP**: Everything is a class
- **Encapsulation**: Hardware details hidden in classes
- **Clean main**: main.cpp is < 30 lines
- **Modularity**: Easy to add/remove features
- **Scalability**: Ready for complex additions

## 📝 Next Steps
- Add NFC module class
- Add WiFi scanner class
- Add settings persistence
- Add state management system

