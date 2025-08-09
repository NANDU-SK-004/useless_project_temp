
#include <WiFi.h>
#include <DNSServer.h>
#include <WebServer.h>
#include <my_all_images.h>

// ===== CONFIGURATION =====
const char* apSSID = "asap_2.4G";
const char* apPassword = "asap@123";
const char* staSSID = "Aeiou";
const char* staPassword = "helloworld";
IPAddress apIP(192, 168, 4, 1);
IPAddress netMsk(255, 255, 255, 0);
const byte DNS_PORT = 53;

DNSServer dnsServer;
WebServer server(80);

// Whitelisted domains (add more if needed)
const char* whitelist[] = {
  "example.com",
  "openai.com"
};
const int whitelistSize = sizeof(whitelist) / sizeof(whitelist[0]);

bool isWhitelisted(const String& query) {
  Serial.println(query);
  for (int i = 0; i < whitelistSize; i++) {
    if (query.indexOf(whitelist[i]) >= 0) return true;
  }
  return false;
}


void sendBase64(const char *imgData){
    String out = imgData;
    server.send(200,"text/plain",out);
}


void handleRoot() {
  String mypage = R"rawliteral(
<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8" />
  <meta name="viewport" content="width=device-width, initial-scale=1.0"/>
  <title>CAPTAIN RIZZU PVT LTD</title>
  <style>
    body {
      margin: 0;
      font-family: 'Courier New', monospace;
      background-color: #0a0a0a;
      color: #00ffcc;
      overflow-x: hidden;
      display: flex;
      flex-direction: column;
      align-items: center;
      justify-content: center;
      height: 100vh;
    }


    .carousel-container {
      position: relative;
      width: 500px;
      height: 700px;
      border: 3px solid #00ffcc;
      box-shadow: 0 0 20px #00ffcc;
      overflow: hidden;
      border-radius: 10px;
      background: #111;
    }


    .carousel-images {
      display: flex;
      transition: transform 0.5s ease-in-out;
      height: 100%;
    }


    .carousel-images img {
      width: 500px;
      height: 700px;
      object-fit: cover;
      flex-shrink: 0;
    }


    .button-container {
      margin-top: 20px;
    }


    .carousel-button {
      background-color: #111;
      color: #00ffcc;
      border: 2px solid #00ffcc;
      padding: 10px 20px;
      font-size: 16px;
      cursor: pointer;
      margin: 0 10px;
      border-radius: 5px;
      transition: all 0.3s ease;
    }


    .carousel-button:hover {
      background-color: #00ffcc;
      color: #111;
    }


    /* Retro Glow */
    h1 {
      font-family: 'Courier New', monospace;
      text-shadow: 0 0 10px #00ffcc;
    }
  </style>
</head>
<body>


  <h1>M E L C O W E !!!!!</h1>


  <div class="carousel-container">
    <div class="carousel-images" id="carouselImages">
)rawliteral";

mypage += R"rawliteral(
<img src="
)rawliteral";
mypage += imageData1;
mypage += R"rawliteral(" alt="My Image0">)rawliteral";

//mypage += R"rawliteral(<img src="/img4" alt="My Image4">)rawliteral";


mypage += R"rawliteral(
<img src="
)rawliteral";
mypage += imageData4;
mypage += R"rawliteral(" alt="My Image04">)rawliteral";

mypage += R"rawliteral(
<img src="
)rawliteral";
mypage += imageData5;
mypage += R"rawliteral(" alt="My Image05">)rawliteral";

mypage += R"rawliteral(

    </div>
  </div>


  <div class="button-container">
    <button class="carousel-button" onclick="prevSlide()"> Prev</button>
    <button class="carousel-button" onclick="nextSlide()">Next </button>
  </div>


  <script>
    const carousel = document.getElementById('carouselImages');
    const totalImages = 5;
    let currentIndex = 0;


    function updateCarousel() {
      const offset = -currentIndex * 500; // width of one image
      carousel.style.transform = `translateX(${offset}px)`;
    }


    function nextSlide() {
      currentIndex = (currentIndex + 1) % totalImages;
      updateCarousel();
    }


    function prevSlide() {
      currentIndex = (currentIndex - 1 + totalImages) % totalImages;
      updateCarousel();
    }
  </script>


</body>
</html>
  )rawliteral";
  server.send(200, "text/html; charset=UTF-8", mypage);
}




void setup() {
  Serial.begin(115200);

  // Connect to upstream WiFi (STA mode)
  WiFi.mode(WIFI_AP_STA);
  WiFi.begin(staSSID, staPassword);
  Serial.print("Connecting to STA");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("Connected to STA");

  // Start AP
  WiFi.softAP(apSSID, apPassword);
  WiFi.softAPConfig(apIP, apIP, netMsk);
  Serial.println("AP Started");

  // Start DNS spoofing server
  dnsServer.start(DNS_PORT, "*", apIP);

  // DNS request handler (check whitelist)
  dnsServer.setTTL(60);
  dnsServer.setErrorReplyCode(DNSReplyCode::NoError);

  // Start captive web server
  server.onNotFound(handleRoot);
  server.on("/img4", [](){sendBase64(imageData4);}); // one-liner for image

  server.begin();
  Serial.println("Web server started");
}

void loop() {
  dnsServer.processNextRequest();
  server.handleClient();
}