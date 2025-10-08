#include "core/Touch.h"

Touch::Touch() : touchSPI(HSPI), ts(TOUCH_CS, TOUCH_IRQ) {
}

void Touch::init() {
    touchSPI.begin(TOUCH_CLK, TOUCH_MISO, TOUCH_MOSI, TOUCH_CS);
    ts.begin(touchSPI);
    ts.setRotation(1);
    
    Serial.println("[+] Touch initialized");
}

bool Touch::isTouched() {
    return ts.tirqTouched() && ts.touched();
}

TouchPoint Touch::getTouch() {
    TouchPoint point = {0, 0, false};
    
    if (!isTouched()) {
        return point;
    }
    
    TS_Point p = ts.getPoint();
    
    // Map to screen coordinates
    point.x = map(p.x, TS_MINX, TS_MAXX, 0, 320);
    point.y = map(p.y, TS_MINY, TS_MAXY, 0, 240);
    
    // Constrain to screen bounds
    point.x = constrain(point.x, 0, 319);
    point.y = constrain(point.y, 0, 239);
    point.valid = true;
    
    return point;
}

