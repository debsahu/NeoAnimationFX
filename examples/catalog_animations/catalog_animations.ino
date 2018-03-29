#include <NeoAnimationFX.h>

#define NEOMETHOD NeoPBBGRB800
#define numPixels 16

NEOMETHOD strip(numPixels);
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