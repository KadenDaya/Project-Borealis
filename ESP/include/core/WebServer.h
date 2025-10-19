#ifndef WEBSERVER_H
#define WEBSERVER_H

#include <Arduino.h>
#include <WiFi.h>
#include <WiFiClient.h>

class WebInterface {
public:
    WebInterface();
    void init();
    void begin();
    void update();
    bool isActive();
    
private:
    WiFiServer server;
    bool active;
    
    void handleClient(WiFiClient& client);
    String generateHTML();
    String generateAPIResponse();
};

#endif

