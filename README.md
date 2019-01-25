# NeoAnimationFX
This uses NeoPixelBrightnessBus and borrows code from awesome animations developed at [WS2812FX](https://github.com/kitesurfer1404/WS2812FX).

----------------------------------------
Check [WS28FX example](https://github.com/kitesurfer1404/WS2812FX/blob/master/examples/ws2812fx_dma/ws2812fx_dma.ino), easier way to achieve this. Still want to use this, follow instructions below.  
----------------------------------------
## Why?
- NeoPixelBrightnessBus uses DMA, so WiFi functions are not effected while animating.
- Has support for numerous LED types
- Very easy templates to handle RGB, HSL and HTML colors
- Supports segments just like [WS2812FX](https://github.com/kitesurfer1404/WS2812FX)
## Limitations
- RBGW leds not yet implemented! (not high priority)
- Works on ESP8266 (for now), ESP32?
- DMA method uses pin RX / GPIO3
- UART method uses pin D4 / GPIO2
- `Serial.begin();` needs to be started before `strip.Begin();` because both share the same pin.
## How to use the library
* Download this GitHub [library](https://github.com/debsahu/NeoAnimationFX/archive/master.zip).
* In Arduino, Goto Sketch -> Include Library -> Add .ZIP Library... and point to the zip file downloaded.
* Install [NeoPixelBus library](https://github.com/Makuna/NeoPixelBus) using the same procedure.
