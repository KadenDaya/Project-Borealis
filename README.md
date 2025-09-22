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
ESP32-S3 dev board (UI control, menus, touchscreen driver, NFC/IR/iButton handling, GPIO interface)

Raspberry Pi Zero W / 2 W (Linux payload engine, runs Kali/PwnPi, handles Wi-Fi injection, Metasploit, bettercap, etc.)

HackRF One (wideband SDR 1–6 GHz for replay, GPS spoofing, IMSI catcher, rolling code bypass, advanced RF chaos)

SIM7600 LTE module (SMS spoof, silent SMS tracking, LTE backhaul for exfiltration, remote control)

PN532 NFC module (NFC read/write/emulate/relay, transit cards, access badges, fuzzing)

RDM6300 LF RFID module (125 kHz low-frequency RFID for HID/EM4100 badges)

MSR605 clone magstripe reader/writer (magstripe card reading/writing/emulation)

ACS ACR1281 smartcard module (ISO7816) (EMV chip read/write/emulation)

DS1990 iButton reader/emulator module (iButton/Dallas keys read/write/emulation)

IR LED + IR photodiode pair (IR signal capture + replay for TVs, ACs, projectors, office equipment)

CC1101 sub-GHz RF module (basic sub-GHz replay/fuzzing for garage doors, alarms, IoT devices)

SX1262 LoRa module (LoRa/LoRaWAN exploitation, extended sub-GHz communication, mesh networking)

Atheros AR9271 or MT76xx Wi-Fi dongle (Wi-Fi monitor mode, injection, AP cloning, deauth floods)

nRF52840 Bluetooth dongle (Bluetooth sniffing, MITM, HID injection, beacon spam, fuzzing)

u-blox NEO-6M GPS module (GPS logging for wardriving, location tagging of captures)

MCP2515 CAN bus module with OBD-II adapter (vehicle CAN bus injection, diagnostics spoofing)

CC2531 Zigbee USB stick (smart home Zigbee exploitation)

Z-Wave module (ZM5202) (smart home Z-Wave exploitation)

ATECC608A secure element (payload encryption, secure key storage, tamper resistance)

2.4–3.5″ TFT touchscreen (UI display for ESP32-S3)

JR-KP-02 keypad + D-pad (physical control input)

Dual microSD card slots (payload storage + logging, one for ESP, one for Pi)

USB-C OTG hub (connects Pi Zero W to Wi-Fi dongles, SDR, LTE modem, magstripe reader, etc.)

Li-ion battery 5000–8000 mAh + BMS (portable power supply, USB-C PD charging, power rails 5V + 3.3V)

Case + SMA connectors + antenna kit (swappable antennas for sub-GHz, Wi-Fi, LTE, SDR)
