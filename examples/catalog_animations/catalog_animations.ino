#include <NeoAnimationFX.h>

#define numPixels 16
#define PIN 2 //GPIO3

#ifdef ESP8266
typedef  NeoPixelBrightnessBus<NeoGrbFeature, Neo800KbpsMethod> NEOMETHOD; //uses GPIO3/RX
//typedef  NeoPixelBrightnessBus<NeoGrbFeature, NeoEsp8266Uart1800KbpsMethod> NEOMETHOD; //uses GPIO2/D4
#endif
#ifdef ESP32
typedef  NeoPixelBrightnessBus<NeoGrbFeature, NeoEsp32I2s1800KbpsMethod> NEOMETHOD;
#endif

NEOMETHOD strip(numPixels, PIN); // PIN is ignored for ESP8266
NeoAnimationFX<NEOMETHOD> myPixelRef(strip);

int i=-1;
long lastModeT = 0;
bool MASTERMODE = false;
int modetotry = FX_MODE_CUSTOM;

void setup() {
  Serial.begin(115200);
  Serial.println();
  myPixelRef.init();
  myPixelRef.setColor(random(255),random(255),random(255));
//  myPixelRef.setSpeed(65535);
//  myPixelRef.setBrightness(100);
  myPixelRef.start();
}

void loop() {
  myPixelRef.service();
  if (millis() - lastModeT > 5000) {
    lastModeT = millis();
    myPixelRef.clear();
    (MASTERMODE) ? i = modetotry : i++;
    if(i >= myPixelRef.getModeCount() ) i=0;
    myPixelRef.setMode(i);
    Serial.print("Mode: ");
    Serial.println(myPixelRef.getModeName(i));
  }
}