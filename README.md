# Project Borealis

The ultimate all-in-one wireless exploitation & pentesting device.

## Features
* Touchscreen + D-pad + keypad  
* Swappable antennas (sub-GHz, Wi-Fi, cellular, SDR-grade)  
* Dual microSD slots (payload + logging)  
* USB-C OTG host + device mode  
* GPIO / UART / JTAG header  
* Secure enclave chip  
* Wi-Fi monitor mode  
* Wi-Fi deauth floods  
* Evil twin AP cloning  
* Karma-style rogue AP (captive portal)  
* Handshake capture + on-device cracking  
* WPA3-Enterprise credential harvesting (evil twin downgrade)  
* Auto captive portal phishing (Google / School / Workplace login spoofing)  
* MITM proxy with SSL stripping + live injection  
* Multi-AP mesh cloning (spam dozens of fake SSIDs at once)  
* Beacon flood / SSID spam (hundreds of ghost networks)  
* Deauth cannon (saturate multiple APs simultaneously)  
* Wi-Fi client hunting (force victims onto rogue APs)  
* Automatic credential replay (inject stolen creds back into real network)  
* Bluetooth sniffing + packet injection  
* Bluetooth jamming / spam pairing flood  
* Fake AirPods / BT keyboard / BT mouse emulation  
* Bluetooth HID injection (drive laptops/phones remotely)  
* BLE beacon spam (flood nearby devices with phantom BT devices)  
* Bluetooth MITM (live proxy between phones/wearables)  
* Sub-GHz wideband SDR capture (300 MHz – 6 GHz)  
* Rolling code capture / replay bypass  
* Car fob panic button replay (mass alarm chaos in parking lots)  
* RF fuzzing / brute force for IoT (garage doors, wireless bells, toys)  
* Smart meter + pager decoding  
* Wireless thermostat / alarm / sensor spoofing  
* Drone hijack (DJI + other 2.4 GHz control channels)  
* TPMS spoofing (fake low tire pressure alerts)  
* Cellular 2G/3G fake base station (IMSI catcher)  
* 4G/5G passive sniffing (with SDR)  
* SMS interception + spoofing  
* Silent SMS tracking (ping phones without alerting)  
* LTE data injection (inject ads / malware into HTTP streams)  
* NFC read/write/emulate/fuzz/relay  
* RFID LF/HF read/write/emulate  
* EMV chip read/write/emulate  
* Magstripe read/write/emulate  
* IR record/replay/fuzz (TVs, ACs, projectors)  
* iButton read/write/emulate  
* USB Rubber Ducky++ (scriptable payloads, branching logic)  
* USB MITM / proxy (sniff & alter USB traffic)  
* BadUSB over Bluetooth / Wi-Fi  
* Keyboard / mouse hijack (e.g., Logitech Unifying exploit)  
* Drive-by HID payloads (plug in → instant backdoor/exfil)  
* Mass BadUSB infection (deploys to every port sequentially)  
* Multi-band RF jamming (2.4 GHz, 5 GHz, BT, sub-GHz, LoRa)  
* Directional jamming (high-gain antenna add-on)  
* Adaptive smart jammer (protocol-aware, selective jamming)  
* GPS jamming / spoofing (make phones think they’re in random locations)  
* Wireless wardriving (GPS + Wi-Fi + BT logging)  
* On-device Nmap / port scanner  
* Vulnerability scanner (CVE database integration)  
* Payload launcher (Metasploit-style modules)  
* MITM on printers/projectors (inject print jobs or slides)  
* Scriptable automation (Python / Lua)  
* Spectrum analyzer  
* MAC / IMEI randomization  
* Payload encryption (AES, ChaCha20)  
* Self-destruct / wipe mode (zeroize storage instantly)  
* Stealth OS mode (disguised as music player / calculator)  
* Remote kill-switch (SMS, NFC, or timed trigger)  
* Fire-and-forget mode (drop it → runs attacks automatically)  
* Scheduled chaos mode (e.g. “8AM flood Wi-Fi & trigger alarms”)  
* Mesh coordination (multiple Borealis units sync for bigger attacks)  
* Car CAN bus injection (via OBD-II)  
* Smart home hacking (Zigbee, Z-Wave)  
* Voice assistant spoofing (fake Alexa/Google commands via RF/BT/Wi-Fi)  
* Drone/UAV control via RF  
* Satellite pager decoding (Iridium, Inmarsat)  
* LoRaWAN exploitation (IoT takeover)  
* Badge cloning (RFID/NFC work ID badges at scale)  
* NFC relay attacks (extend range of keycards via proxy)  
* Mass badge wipe / corruption mode  
* IoT camera hijack (RTSP sniff/inject)  
* Auto-phish hotspot (captures logins, injects malware links)  
* Credential exfil to cloud (LTE backhaul)  
* Mass network lockdown (force every nearby device offline)  
* Printer takeover (spam jobs, alter docs)  
* Projector takeover (inject images/memes mid-presentation)  
* OMG Cable style attacks (keylogging, payload delivery)  
* Covert exfil (hides logs inside RF noise, images, or audio streams)  
* Silent stalker mode (logs all signals without transmitting)  
* Chaos flood mode (jam Wi-Fi, BT, NFC, Zigbee simultaneously)  

## Hardware
* ESP32-S3 (UI + control)  
* Pi Zero W (advanced pentest payloads + Linux tools)
### Features + Hardware

* Touchscreen + D-pad + keypad (ESP32-S3 + TFT touchscreen + JR-KP-02 keypad)  
* Swappable antennas (SMA connectors + switchable RF front-ends)  
* Dual microSD slots (ESP32-S3 + Pi Zero W with SD)  
* USB-C OTG host + device mode (ESP32-S3 native USB + Pi Zero W)  
* GPIO / UART / JTAG header (ESP32-S3 pins, breakout header)  
* Secure enclave chip (ATECC608A crypto co-processor)  

* Wi-Fi monitor mode (USB Wi-Fi dongle — Atheros AR9271 / MT76xx)  
* Wi-Fi deauth floods (same as above)  
* Evil twin AP cloning (Pi Zero W + hostapd-wpe)  
* Karma-style rogue AP (Pi Zero W + hostapd-karma)  
* Handshake capture + on-device cracking (AR9271 dongle + hcxdumptool + Pi Zero W)  
* WPA3-Enterprise credential harvesting (evil twin downgrade via Pi + hostapd-wpe)  
* Auto captive portal phishing (Pi Zero W webserver + hostapd)  
* MITM proxy with SSL stripping + live injection (Pi Zero W + Bettercap/sslstrip)  
* Multi-AP mesh cloning (Pi Zero W + multiple AR9271 dongles)  
* Beacon flood / SSID spam (ESP32-S3 or AR9271 dongle)  
* Deauth cannon (AR9271 dongle + Pi)  
* Wi-Fi client hunting (Pi + Wireshark/hcxdumptool)  
* Automatic credential replay (Pi + bettercap modules)  

* Bluetooth sniffing + packet injection (nRF52840 dongle + Pi)  
* Bluetooth jamming / spam pairing flood (nRF52840 dongle)  
* Fake AirPods / BT keyboard / BT mouse emulation (ESP32-S3 + BT HID firmware)  
* Bluetooth HID injection (nRF52840 dongle in HID mode)  
* BLE beacon spam (ESP32-S3 BLE stack)  
* Bluetooth MITM (nRF52840 dongle + Pi + btlejack)  

* Sub-GHz wideband SDR capture (HackRF One / LimeSDR Mini)  
* Rolling code capture / replay bypass (HackRF One + Pi + RF cracking software)  
* Car fob panic button replay (CC1101 module / HackRF)  
* RF fuzzing / brute force for IoT (CC1101 + ESP32-S3, or HackRF)  
* Smart meter + pager decoding (HackRF / RTL-SDR dongle)  
* Wireless thermostat / alarm / sensor spoofing (CC1101 / SX1262 LoRa)  
* Drone hijack (HackRF + DJI protocol tools)  
* TPMS spoofing (HackRF / CC1101)  

* Cellular 2G/3G fake base station (HackRF + OpenBTS/YateBTS)  
* 4G/5G passive sniffing (LimeSDR Mini + srsLTE)  
* SMS interception + spoofing (SIM7600 LTE modem + AT commands)  
* Silent SMS tracking (SIM7600 LTE modem)  
* LTE data injection (SIM7600 + MITM proxies)  

* NFC read/write/emulate/fuzz/relay (PN532 NFC module)  
* RFID LF/HF read/write/emulate (PN532 + RDM6300 LF module)  
* EMV chip read/write/emulate (ACS ACR1281 smartcard reader)  
* Magstripe read/write/emulate (MSR605 clone board)  
* IR record/replay/fuzz (ESP32-S3 GPIO + IR LED + IR photodiode)  
* iButton read/write/emulate (DS1990 1-Wire module)  

* USB Rubber Ducky++ (ESP32-S3 USB HID stack)  
* USB MITM / proxy (Pi Zero W + USB OTG hub)  
* BadUSB over Bluetooth / Wi-Fi (ESP32-S3 HID over BT/Wi-Fi)  
* Keyboard / mouse hijack (Logitech Unifying dongle exploit + Pi)  
* Drive-by HID payloads (ESP32-S3 BadUSB scripts)  
* Mass BadUSB infection (Pi Zero W running USB attack scripts)  

* Multi-band RF jamming (HackRF + Wi-Fi dongle + nRF52840)  
* Directional jamming (HackRF with directional antenna)  
* Adaptive smart jammer (Pi Zero coordinating multiple radios)  
* GPS jamming / spoofing (HackRF + active GPS antenna amp)  

* Wireless wardriving (Pi Zero W + GPS module u-blox NEO-6M + AR9271 dongle)  
* On-device Nmap / port scanner (Pi Zero W + nmap)  
* Vulnerability scanner (Pi Zero W + OpenVAS or custom CVE scripts)  
* Payload launcher (Pi Zero W + Metasploit)  
* MITM on printers/projectors (Pi Zero W + bettercap)  
* Scriptable automation (ESP32-S3 for macros, Pi Zero for scripts)  
* Spectrum analyzer (HackRF / LimeSDR + Pi software)  

* MAC / IMEI randomization (Pi Zero W + network tools, SIM7600 AT commands)  
* Payload encryption (ATECC608A secure element)  
* Self-destruct / wipe mode (ESP32-S3 GPIO controlling SD erase circuit)  
* Stealth OS mode (ESP32-S3 fake calculator/music player UI)  
* Remote kill-switch (ESP32-S3 + SIM7600 SMS listener or NFC trigger)  
* Fire-and-forget mode (ESP32-S3 autonomous script runner)  
* Scheduled chaos mode (ESP32-S3 RTC alarm launching attacks)  
* Mesh coordination (multiple ESP32-S3 units with LoRa SX1262)  

* Car CAN bus injection (MCP2515 CAN bus module via OBD-II adapter)  
* Smart home hacking (CC2531 Zigbee USB stick, Z-Wave ZM5202 module)  
* Voice assistant spoofing (HackRF / ESP32 Wi-Fi/Bluetooth emulation)  
* Drone/UAV control via RF (HackRF + SDR-based hijack scripts)  
* Satellite pager decoding (HackRF / LimeSDR + GNURadio)  
* LoRaWAN exploitation (SX1276/SX1262 LoRa module + Pi)  
* Badge cloning (PN532 + RDM6300)  
* NFC relay attacks (ESP32-S3 + PN532 with dual readers)  
* Mass badge wipe / corruption mode (PN532 firmware abuse)  
* IoT camera hijack (Pi Zero + bettercap/rtsp tools)  
* Auto-phish hotspot (Pi Zero + hostapd + phishing webserver)  
* Credential exfil to cloud (SIM7600 LTE modem + Pi scripts)  
* Mass network lockdown (Pi Zero + AR9271 Wi-Fi dongle + deauth flood)  
* Printer takeover (Pi Zero + printer exploit scripts)  
* Projector takeover (IR LED or network-based injection from Pi)  
* OMG Cable style attacks (Pi Zero emulating HID over USB cable)  
* Covert exfil (Pi Zero + SDR steganography or audio/image hiding)  
* Silent stalker mode (HackRF in RX-only, ESP logs locally)  
* Chaos flood mode (ESP32 + Pi coordinating all radios simultaneously)  

