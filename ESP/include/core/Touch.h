#ifndef TOUCH_H
#define TOUCH_H

#include <XPT2046_Touchscreen.h>
#include <SPI.h>

// Touchscreen pin definitions
#define TOUCH_CS   33
#define TOUCH_IRQ  36
#define TOUCH_MOSI 32
#define TOUCH_MISO 39
#define TOUCH_CLK  25

// Touch calibration
#define TS_MINX 300
#define TS_MINY 400
#define TS_MAXX 3800
#define TS_MAXY 3750

struct TouchPoint {
    int x;
    int y;
    bool valid;
};

class Touch {
public:
    Touch();
    void init();
    TouchPoint getTouch();
    bool isTouched();
    
private:
    SPIClass touchSPI;
    XPT2046_Touchscreen ts;
};

#endif

