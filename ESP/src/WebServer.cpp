#include "core/WebServer.h"

WebInterface::WebInterface() : server(80), active(false) {
}

void WebInterface::init() {
    if (active) {
        Serial.println("[*] WebUI already active");
        return;
    }
    
    Serial.println("[+] Initializing WiFi AP...");
    
    WiFi.mode(WIFI_AP);
    WiFi.softAPConfig(
        IPAddress(192, 168, 0, 1),
        IPAddress(192, 168, 0, 1),
        IPAddress(255, 255, 255, 0)
    );
    
    WiFi.softAP("Project-Borealis", "borealis123");
    
    Serial.print("[+] AP IP: ");
    Serial.println(WiFi.softAPIP());
    
    active = true;
}

void WebInterface::begin() {
    if (!active) return;
    
    server.begin();
    Serial.println("[+] Web server started on 192.168.0.1");
}

void WebInterface::update() {
    if (!active) return;
    
    WiFiClient client = server.available();
    if (client) {
        handleClient(client);
    }
}

bool WebInterface::isActive() {
    return active;
}

void WebInterface::handleClient(WiFiClient& client) {
    String currentLine = "";
    String requestPath = "";
    
    while (client.connected()) {
        if (client.available()) {
            char c = client.read();
            
            if (c == '\n') {
                if (currentLine.length() == 0) {
                    if (requestPath.indexOf("/api/status") >= 0) {
                        client.println("HTTP/1.1 200 OK");
                        client.println("Content-Type: application/json");
                        client.println("Connection: close");
                        client.println();
                        client.println(generateAPIResponse());
                    } else {
                        client.println("HTTP/1.1 200 OK");
                        client.println("Content-Type: text/html");
                        client.println("Connection: close");
                        client.println();
                        client.println(generateHTML());
                    }
                    break;
                } else {
                    currentLine = "";
                }
            } else if (c != '\r') {
                currentLine += c;
                if (currentLine.startsWith("GET ")) {
                    int spaceIndex = currentLine.indexOf(' ', 4);
                    if (spaceIndex > 0) {
                        requestPath = currentLine.substring(4, spaceIndex);
                    }
                }
            }
        }
    }
    
    client.stop();
}

String WebInterface::generateAPIResponse() {
    String json = "{";
    json += "\"device\":\"Project Borealis\",";
    json += "\"version\":\"1.0.0\",";
    json += "\"uptime\":" + String(millis() / 1000) + ",";
    json += "\"clients\":" + String(WiFi.softAPgetStationNum());
    json += "}";
    return json;
}

String WebInterface::generateHTML() {
    // WiFi Pineapple Enterprise style - sleek and professional
    String html = R"(<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<meta name="viewport" content="width=device-width,initial-scale=1.0">
<title>Project Borealis</title>
<style>
*{margin:0;padding:0;box-sizing:border-box}
body{font-family:-apple-system,BlinkMacSystemFont,'Segoe UI',Roboto,sans-serif;background:#0a0e27;color:#e4e4e7;overflow-x:hidden}
.sidebar{position:fixed;left:0;top:0;width:260px;height:100vh;background:#151934;border-right:1px solid #1e2842;z-index:1000}
.logo{padding:24px 20px;border-bottom:1px solid #1e2842}
.logo h1{font-size:20px;color:#00d4ff;font-weight:700;letter-spacing:0.5px}
.logo p{color:#6b7280;font-size:11px;margin-top:4px}
.nav{padding:12px 0}
.nav-item{padding:14px 20px;color:#9ca3af;cursor:pointer;display:flex;align-items:center;transition:all .15s;font-size:14px}
.nav-item:hover{background:#1a2038;color:#fff}
.nav-item.active{background:#1e2440;color:#00d4ff;border-left:4px solid #00d4ff;padding-left:16px}
.nav-icon{width:20px;margin-right:14px;font-size:16px}
.main{margin-left:260px;padding:24px;min-height:100vh}
.top-bar{background:#151934;border:1px solid #1e2842;border-radius:12px;padding:24px;margin-bottom:24px;display:flex;justify-content:space-between;align-items:center}
.top-bar h2{font-size:28px;font-weight:700}
.top-bar .status{display:flex;gap:16px}
.status-badge{padding:8px 16px;background:#00d4ff15;border:1px solid #00d4ff30;border-radius:8px;color:#00d4ff;font-size:13px;font-weight:600}
.stats{display:grid;grid-template-columns:repeat(auto-fit,minmax(220px,1fr));gap:16px;margin-bottom:24px}
.stat-card{background:#151934;border:1px solid #1e2842;border-radius:12px;padding:20px}
.stat-label{color:#9ca3af;font-size:13px;text-transform:uppercase;letter-spacing:0.5px;margin-bottom:8px;font-weight:500}
.stat-value{font-size:28px;font-weight:700;color:#00d4ff}
.modules{display:grid;grid-template-columns:repeat(auto-fit,minmax(340px,1fr));gap:20px}
.module{background:#151934;border:1px solid #1e2842;border-radius:12px;padding:24px;transition:all .2s}
.module:hover{border-color:#00d4ff50;transform:translateY(-2px);box-shadow:0 8px 24px rgba(0,212,255,0.1)}
.module h3{font-size:18px;font-weight:600;margin-bottom:16px;display:flex;align-items:center;gap:10px}
.module-icon{font-size:22px}
.module ul{list-style:none;color:#9ca3af;font-size:14px;line-height:1.8}
.module li{padding:6px 0;padding-left:20px;position:relative}
.module li:before{content:'▸';position:absolute;left:0;color:#00d4ff}
.btn{background:linear-gradient(135deg,#00d4ff,#0088ff);border:none;padding:10px 20px;border-radius:8px;color:#fff;font-size:14px;font-weight:600;cursor:pointer;transition:all .2s}
.btn:hover{transform:scale(1.02);box-shadow:0 4px 16px rgba(0,212,255,0.3)}
.footer{margin-top:48px;text-align:center;color:#6b7280;font-size:12px;padding:20px;border-top:1px solid #1e2842}
.pulse{width:8px;height:8px;background:#22c55e;border-radius:50%;display:inline-block;margin-right:8px;animation:pulse 2s infinite}
@keyframes pulse{0%,100%{opacity:1;transform:scale(1)}50%{opacity:0.6;transform:scale(0.95)}}
</style>
</head>
<body>
<div class="sidebar">
  <div class="logo">
    <h1>PROJECT BOREALIS</h1>
    <p>Wireless Pentesting Platform</p>
  </div>
  <div class="nav">
    <div class="nav-item active"><span class="nav-icon">⌂</span>Dashboard</div>
    <div class="nav-item"><span class="nav-icon">📡</span>WiFi Tools</div>
    <div class="nav-item"><span class="nav-icon">🔵</span>Bluetooth</div>
    <div class="nav-item"><span class="nav-icon">💳</span>NFC/RFID</div>
    <div class="nav-item"><span class="nav-icon">⚙</span>Settings</div>
  </div>
</div>
<div class="main">
  <div class="top-bar">
    <h2>Dashboard</h2>
    <div class="status">
      <div class="status-badge"><span class="pulse"></span>Online</div>
    </div>
  </div>
  <div class="stats">
    <div class="stat-card">
      <div class="stat-label">Device IP</div>
      <div class="stat-value" style="font-size:20px">192.168.0.1</div>
    </div>
    <div class="stat-card">
      <div class="stat-label">Uptime</div>
      <div class="stat-value" id="uptime" style="font-size:20px">0s</div>
    </div>
    <div class="stat-card">
      <div class="stat-label">Connected Clients</div>
      <div class="stat-value" id="clients">0</div>
    </div>
  </div>
  <div class="modules">
    <div class="module">
      <h3><span class="module-icon">📡</span>WiFi Operations</h3>
      <ul>
        <li>Reconnaissance & Scanning</li>
        <li>Attack Modules</li>
        <li>Packet Capture</li>
        <li>Network Analysis</li>
      </ul>
      <button class="btn" style="margin-top:16px">Configure WiFi</button>
    </div>
    <div class="module">
      <h3><span class="module-icon">🔵</span>Bluetooth</h3>
      <ul>
        <li>BLE Scanner & Tracker</li>
        <li>Device Enumeration</li>
        <li>Attack Tools</li>
        <li>Packet Sniffing</li>
      </ul>
      <button class="btn" style="margin-top:16px">Configure BLE</button>
    </div>
    <div class="module">
      <h3><span class="module-icon">💳</span>RFID/NFC Tools</h3>
      <ul>
        <li>13.56 MHz NFC (PN532)</li>
        <li>125 kHz RFID (RDM6300)</li>
        <li>Read, Write, Emulate</li>
        <li>Card Database</li>
      </ul>
      <button class="btn" style="margin-top:16px">Manage Cards</button>
    </div>
    <div class="module">
      <h3><span class="module-icon">📊</span>System Info</h3>
      <ul>
        <li>ESP32 Classic</li>
        <li>ILI9341 Display</li>
        <li>Alpha AWUS036ACM</li>
        <li>Raspberry Pi Zero 2</li>
      </ul>
      <button class="btn" style="margin-top:16px">View Details</button>
    </div>
  </div>
  <div class="footer">
    Made with ❤️ by Kaden Daya | Project Borealis v1.0.0 | For Security Research Only
  </div>
</div>
<script>
function updateStats(){
  fetch('/api/status')
    .then(r=>r.json())
    .then(d=>{
      document.getElementById('uptime').textContent=d.uptime+'s';
      document.getElementById('clients').textContent=d.clients;
    })
    .catch(e=>console.error(e));
}
setInterval(updateStats,2000);
updateStats();
</script>
</body>
</html>)";
    
    return html;
}
