# NeoAnimationFX
This uses NeoPixelBrightnessBus and borrows code from awesome animations developed at WS2812FX.

## Why?
- NeoPixelBrightnessBus uses DMA, so WiFi functions are not effected while animating.
- Has support for numerous LED types
- Very easy templates to handle RGB, HSL and HTML colors
## Limitations
- Works on ESP8266 (for now)
- NO Segments support (for now)
- DMA method uses pin RX / GPIO3
- `Serial.begin();` needs to be started before `strip.Begin();` because both share the same pin.
## How to use the library
* Download this GitHub [library](https://github.com/debsahu/NeoAnimationFX/archive/master.zip).
* In Arduino, Goto Sketch -> Include Library -> Add .ZIP Library... and point to the zip file downloaded.
* Install [NeoPixelBus library](https://github.com/Makuna/NeoPixelBus) using the same procedure.
