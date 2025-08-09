<img width="3188" height="1202" alt="frame (3)" src="https://github.com/user-attachments/assets/517ad8e9-ad22-457d-9538-a9e62d137cd7" />


# [Sagar Alias Jacker] 🎯


## Basic Details
### Team Name: [Perilla]


### Team Members
- Team Lead: [Nandu S Kumar] - [College of Engineering Perumon,Kollam]
- Member 2: [Sundara Siva Sreerag] - [College of Engineering Perumon,Kollam]

### Project Description
This project combines an ESP8266-based Wi-Fi jammer with an ESP32-powered local web server to mimic a target Wi-Fi network and deliver a humorous, meme-based HTML page. When users connect, they are redirected to a fun, themed page filled with memes and dialogues for entertainment.

### The Problem (that doesn't exist)
People connect to Wi-Fi networks without getting enough daily memes, leading to severe meme deficiency and boredom.

### The Solution (that nobody asked for)
We created a Wi-Fi imposter that hijacks your browsing journey and force-feeds you a glorious page of spicy memes and iconic Malayalam–Manglish dialogues, ensuring your laughter bandwidth is always full.

## Technical Details
### Technologies/Components Used
For Software:
- Languages used
      C (for ESP32 firmware)
      HTML, CSS, JavaScript (for meme page
- Frameworks used
      Arduino Core for ESP32
      NodeMCU firmware environment     
- Libraries used
      WiFi.h (ESP32 Wi-Fi control)
      DNSServer.h (to redirect to meme page)
      ESPAsyncWebServer.h (host the memes)
      ESP32 Deauther(SpacehuhnTech/esp8266_deauther)
- Tools used
      Arduino IDE
      GitHub


For Hardware:
- List main components
    ESP32-WROOM-32 module
    NodeMCU board (ESP8266 variant)
- List specifications
    ESP32 Dual-core 240MHz ,Wi-Fi + Bluetooth, 4MB Flash
    NodeMCU with ESP8266, 80/160 MHz, 4MB Flash
- List tools required
    Micro-USB cable
    Laptop for flashing firmware
    jumper wires 



### Implementation
For Software:
The ESP8266 is programmed to scan and jam Wi-Fi networks in range (educational/demo purposes only, of course). When a device tries to connect, a captive portal triggers and redirects the user to our custom meme webpage hosted on the ESP32. The meme page is pure HTML/JS, designed to make people laugh at their lack of internet instead of crying.
# Installation
Clone the repository
git clone https://github.com/NANDU-SK-004/useless_project_temp.git
cd useless_project_temp

 Install required libraries in Arduino IDE
 - ESPAsyncWebServer
 - ESPAsyncTCP (for ESP8266) / AsyncTCP (for ESP32)
 - WiFi library (comes built-in)

Open the .ino file in Arduino IDE
Select the correct Board and Port in Tools menu


# Run
Connect your ESP32/ESP8266 via USB
Click 'Upload' in Arduino IDE to flash the code
Open Serial Monitor to check logs

 Once running:
 - Access the Web Host via the IP shown in Serial Monitor
 - User's will redirect to the page 
 - Use Wi-Fi scan page to detect and deauth networks (if enabled)




# Screenshots (Add at least 3)
![Arduino IDE – Running Web Host Code](https://github.com/NANDU-SK-004/useless_project_temp/blob/main/arduino_ide.png)
This image shows the Arduino IDE with the ESP8266/ESP32 web server code uploaded. The code configures the microcontroller to act as a local web host, serving the project’s interface to connected devices.

![Meme Page](https://github.com/NANDU-SK-004/useless_project_temp/blob/main/meme.png)
This image displays the meme page hosted by the ESP device. Users connected to the device’s network can view and interact with this page through their browser.

![Wi-Fi Scanning & Deauthentication Page](https://github.com/NANDU-SK-004/useless_project_temp/blob/main/scan.png)
This image shows the Wi-Fi scanning and deauthentication interface. It lists available Wi-Fi networks and provides controls for initiating deauthentication packets for testing and network analysis.

# Diagrams
![Workflow](Add your workflow/architecture diagram here)
*Add caption explaining your workflow*

For Hardware:

# Schematic & Circuit
![Circuit](Add your circuit diagram here)
*Add caption explaining connections*

![Schematic](Add your schematic diagram here)
*Add caption explaining the schematic*

# Build Photos
![Components](https://github.com/NANDU-SK-004/useless_project_temp/blob/main/1.jpeg)
![Components](https://github.com/NANDU-SK-004/useless_project_temp/blob/main/2.jpeg)
ESP8266 and ESP32

![Build](https://github.com/NANDU-SK-004/useless_project_temp/blob/main/3.jpeg)
The ESP32 and ESP8266 boards are now running the code. We are in the process of testing, troubleshooting, and resolving any detected errors to ensure smooth operation.

![Final](https://github.com/NANDU-SK-004/useless_project_temp/blob/main/4.jpeg)
At last, the final build is complete — proudly named Sagar Alias Jacker.


### Project Demo
# Video
[Add your demo video link here]
*Explain what the video demonstrates*

# Additional Demos
[Add any extra demo materials/links]

## Team Contributions
- [Name 1]: [Specific contributions]
- [Name 2]: [Specific contributions]
- [Name 3]: [Specific contributions]

---
Made with ❤️ at TinkerHub Useless Projects 

![Static Badge](https://img.shields.io/badge/TinkerHub-24?color=%23000000&link=https%3A%2F%2Fwww.tinkerhub.org%2F)
![Static Badge](https://img.shields.io/badge/UselessProjects--25-25?link=https%3A%2F%2Fwww.tinkerhub.org%2Fevents%2FQ2Q1TQKX6Q%2FUseless%2520Projects)



