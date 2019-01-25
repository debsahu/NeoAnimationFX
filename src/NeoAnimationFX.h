#ifndef NeoAnimationFX_h
#define NeoAnimationFX_h

#include <NeoPixelBrightnessBus.h>

#define DEFAULT_BRIGHTNESS 50
#define DEFAULT_MODE 0
#define DEFAULT_SPEED 1000
#define DEFAULT_COLOR 0xFF0000

#define SPEED_MIN 10
#define SPEED_MAX 65535

#define BRIGHTNESS_MIN 0
#define BRIGHTNESS_MAX 255

/* each segment uses 34 bytes of SRAM memory, so if you're application fails because of
  insufficient memory, decreasing MAX_NUM_SEGMENTS may help */
#define MAX_NUM_SEGMENTS 10
#define NUM_COLORS 3     /* number of colors per segment */
#define SEGMENT          _segments[_segment_index]
#define SEGMENT_RUNTIME  _segment_runtimes[_segment_index]
#define SEGMENT_LENGTH   (SEGMENT.stop - SEGMENT.start + 1)
#define RESET_RUNTIME    memset(_segment_runtimes, 0, sizeof(_segment_runtimes))

// some common colors
#define RED        0xFF0000
#define GREEN      0x00FF00
#define BLUE       0x0000FF
#define WHITE      0xFFFFFF
#define BLACK      0x000000
#define YELLOW     0xFFFF00
#define CYAN       0x00FFFF
#define MAGENTA    0xFF00FF
#define PURPLE     0x400080
#define ORANGE     0xFF3000
#define ULTRAWHITE 0xFFFFFFFF

#define MODE_COUNT 58

#define FX_MODE_STATIC                   0
#define FX_MODE_BLINK                    1
#define FX_MODE_BREATH                   2
#define FX_MODE_COLOR_WIPE               3
#define FX_MODE_COLOR_WIPE_INV           4 
#define FX_MODE_COLOR_WIPE_REV           5
#define FX_MODE_COLOR_WIPE_REV_INV       6
#define FX_MODE_COLOR_WIPE_RANDOM        7
#define FX_MODE_RANDOM_COLOR             8
#define FX_MODE_SINGLE_DYNAMIC           9
#define FX_MODE_MULTI_DYNAMIC           10
#define FX_MODE_RAINBOW                 11
#define FX_MODE_RAINBOW_CYCLE           12
#define FX_MODE_SCAN                    13
#define FX_MODE_DUAL_SCAN               14
#define FX_MODE_FADE                    15
#define FX_MODE_THEATER_CHASE           16
#define FX_MODE_THEATER_CHASE_RAINBOW   17
#define FX_MODE_RUNNING_LIGHTS          18
#define FX_MODE_TWINKLE                 19
#define FX_MODE_TWINKLE_RANDOM          20
#define FX_MODE_TWINKLE_FADE            21
#define FX_MODE_TWINKLE_FADE_RANDOM     22
#define FX_MODE_SPARKLE                 23
#define FX_MODE_FLASH_SPARKLE           24
#define FX_MODE_HYPER_SPARKLE           25
#define FX_MODE_STROBE                  26
#define FX_MODE_STROBE_RAINBOW          27
#define FX_MODE_MULTI_STROBE            28
#define FX_MODE_BLINK_RAINBOW           29
#define FX_MODE_CHASE_WHITE             30
#define FX_MODE_CHASE_COLOR             31
#define FX_MODE_CHASE_RANDOM            32
#define FX_MODE_CHASE_RAINBOW           33
#define FX_MODE_CHASE_FLASH             34
#define FX_MODE_CHASE_FLASH_RANDOM      35
#define FX_MODE_CHASE_RAINBOW_WHITE     36
#define FX_MODE_CHASE_BLACKOUT          37
#define FX_MODE_CHASE_BLACKOUT_RAINBOW  38
#define FX_MODE_COLOR_SWEEP_RANDOM      39
#define FX_MODE_RUNNING_COLOR           40
#define FX_MODE_RUNNING_RED_BLUE        41
#define FX_MODE_RUNNING_RANDOM          42
#define FX_MODE_LARSON_SCANNER          43
#define FX_MODE_COMET                   44
#define FX_MODE_FIREWORKS               45
#define FX_MODE_FIREWORKS_RANDOM        46
#define FX_MODE_MERRY_CHRISTMAS         47
#define FX_MODE_FIRE_FLICKER            48
#define FX_MODE_FIRE_FLICKER_SOFT       49
#define FX_MODE_FIRE_FLICKER_INTENSE    50
#define FX_MODE_CIRCUS_COMBUSTUS        51
#define FX_MODE_HALLOWEEN               52
#define FX_MODE_BICOLOR_CHASE           53
#define FX_MODE_TRICOLOR_CHASE          54
#define FX_MODE_ICU                     55
#define FX_MODE_CUSTOM                  56
#define FX_MODE_METEOR_RAIN             57

#define MAX_PIXEL_CT 3000

typedef  NeoPixelBrightnessBus<NeoGrbFeature, Neo800KbpsMethod>                 NeoPBBGRB800;   // Use this for WS2812
typedef  NeoPixelBrightnessBus<NeoGrbFeature, Neo400KbpsMethod>                 NeoPBBGRB400;
typedef  NeoPixelBrightnessBus<NeoGrbFeature, NeoEsp8266Uart1800KbpsMethod>     NeoPBBGRBU800;
typedef  NeoPixelBrightnessBus<NeoGrbFeature, NeoEsp8266Uart0400KbpsMethod>     NeoPBBGRBU400;
typedef  NeoPixelBrightnessBus<NeoGrbFeature, NeoEsp8266Dma800KbpsMethod>       NeoPBBGRBD800;
typedef  NeoPixelBrightnessBus<NeoGrbFeature, NeoEsp8266Dma400KbpsMethod>       NeoPBBGRBD400;
typedef  NeoPixelBrightnessBus<NeoGrbFeature, NeoEsp8266BitBang800KbpsMethod>   NeoPBBGRBBB800;
typedef  NeoPixelBrightnessBus<NeoGrbFeature, NeoEsp8266BitBang400KbpsMethod>   NeoPBBGRBBB400;
typedef  NeoPixelBrightnessBus<NeoGrbFeature, NeoWs2813Method>                  NeoPBBGRBws2813;

typedef  NeoPixelBrightnessBus<NeoRgbFeature, Neo800KbpsMethod>                 NeoPBBRGB800;
typedef  NeoPixelBrightnessBus<NeoRgbFeature, Neo400KbpsMethod>                 NeoPBBRGB400;
typedef  NeoPixelBrightnessBus<NeoRgbFeature, NeoEsp8266Uart1800KbpsMethod>     NeoPBBRGBU800;
typedef  NeoPixelBrightnessBus<NeoRgbFeature, NeoEsp8266Uart0400KbpsMethod>     NeoPBBRGBU400;
typedef  NeoPixelBrightnessBus<NeoRgbFeature, NeoEsp8266Dma800KbpsMethod>       NeoPBBRGBD800;
typedef  NeoPixelBrightnessBus<NeoRgbFeature, NeoEsp8266Dma400KbpsMethod>       NeoPBBRGBD400;
typedef  NeoPixelBrightnessBus<NeoRgbFeature, NeoEsp8266BitBang800KbpsMethod>   NeoPBBRGBBB800;
typedef  NeoPixelBrightnessBus<NeoRgbFeature, NeoEsp8266BitBang400KbpsMethod>   NeoPBBRGBBB400;
typedef  NeoPixelBrightnessBus<NeoRgbFeature, NeoWs2813Method>                  NeoPBBRGBws2813;

typedef  NeoPixelBrightnessBus<NeoBrgFeature, Neo800KbpsMethod>                 NeoPBBBRG800;
typedef  NeoPixelBrightnessBus<NeoBrgFeature, Neo400KbpsMethod>                 NeoPBBBRG400;
typedef  NeoPixelBrightnessBus<NeoBrgFeature, NeoEsp8266Uart1800KbpsMethod>     NeoPBBBRGU800;
typedef  NeoPixelBrightnessBus<NeoBrgFeature, NeoEsp8266Uart0400KbpsMethod>     NeoPBBBRGU400;
typedef  NeoPixelBrightnessBus<NeoBrgFeature, NeoEsp8266Dma800KbpsMethod>       NeoPBBBRGD800;
typedef  NeoPixelBrightnessBus<NeoBrgFeature, NeoEsp8266Dma400KbpsMethod>       NeoPBBBRGD400;
typedef  NeoPixelBrightnessBus<NeoBrgFeature, NeoEsp8266BitBang800KbpsMethod>   NeoPBBBRGBB800;
typedef  NeoPixelBrightnessBus<NeoBrgFeature, NeoEsp8266BitBang400KbpsMethod>   NeoPBBBRGBB400;
typedef  NeoPixelBrightnessBus<NeoBrgFeature, NeoWs2813Method>                  NeoPBBBRGws2813;

typedef  NeoPixelBrightnessBus<NeoRbgFeature, Neo800KbpsMethod>                 NeoPBBRBG800;
typedef  NeoPixelBrightnessBus<NeoRbgFeature, Neo400KbpsMethod>                 NeoPBBRBG400;
typedef  NeoPixelBrightnessBus<NeoRbgFeature, NeoEsp8266Uart1800KbpsMethod>     NeoPBBRBGU800;
typedef  NeoPixelBrightnessBus<NeoRbgFeature, NeoEsp8266Uart0400KbpsMethod>     NeoPBBRBGU400;
typedef  NeoPixelBrightnessBus<NeoRbgFeature, NeoEsp8266Dma800KbpsMethod>       NeoPBBRBGD800;
typedef  NeoPixelBrightnessBus<NeoRbgFeature, NeoEsp8266Dma400KbpsMethod>       NeoPBBRBGD400;
typedef  NeoPixelBrightnessBus<NeoRbgFeature, NeoEsp8266BitBang800KbpsMethod>   NeoPBBRBGBB800;
typedef  NeoPixelBrightnessBus<NeoRbgFeature, NeoEsp8266BitBang400KbpsMethod>   NeoPBBRBGBB400;
typedef  NeoPixelBrightnessBus<NeoRbgFeature, NeoWs2813Method>                  NeoPBBRBGws2813;

//typedef  NeoPixelBrightnessBus <NeoRgbwFeature, Neo800KbpsMethod>               NeoPBBRGBW800; // Not supported yet
  
template<typename T_PIXEL_METHOD> class NeoAnimationFX {
  typedef uint16_t (NeoAnimationFX::*mode_ptr)(void);
  
  public:
  
  // segment parameters
  
  /* set default values c way 
  struct segment_struct {
    uint8_t  mode;
    RgbColor color;
    uint16_t speed;
    uint16_t start;
    uint16_t stop;
    bool     reverse;
  } segment_default = { FX_MODE_STATIC, (RgbColor) HtmlColor(DEFAULT_COLOR), DEFAULT_SPEED, 0, 7, false};
  
  typedef struct segment_struct segment; */

  typedef struct Segment {
    uint8_t  mode;
    RgbColor colors[NUM_COLORS];
    uint16_t speed;
    uint16_t start;
    uint16_t stop;
    bool     reverse;
	// set default values c++ way
	Segment(): 
	  mode(FX_MODE_STATIC), 
	  colors({(RgbColor) HtmlColor(DEFAULT_COLOR), (RgbColor) HtmlColor(BLACK), (RgbColor) HtmlColor(GREEN)}), 
	  speed(DEFAULT_SPEED), 
	  start(0), 
	  stop(7), 
	  reverse(false) {}
  } segment;
    
  // segment runtime parameters
  typedef struct Segment_runtime {
    uint32_t counter_mode_step;
    uint32_t counter_mode_call;
    unsigned long next_time;
    uint16_t aux_param;
  } segment_runtime;
  
  NeoAnimationFX(T_PIXEL_METHOD& pixelStrip) :
    _strip(pixelStrip) {
      _mode[FX_MODE_STATIC]                  = &NeoAnimationFX::mode_static;
	  _mode[FX_MODE_BLINK]                   = &NeoAnimationFX::mode_blink;
      _mode[FX_MODE_COLOR_WIPE]              = &NeoAnimationFX::mode_color_wipe;
      _mode[FX_MODE_COLOR_WIPE_INV]          = &NeoAnimationFX::mode_color_wipe_inv;
      _mode[FX_MODE_COLOR_WIPE_REV]          = &NeoAnimationFX::mode_color_wipe_rev;
      _mode[FX_MODE_COLOR_WIPE_REV_INV]      = &NeoAnimationFX::mode_color_wipe_rev_inv;
      _mode[FX_MODE_COLOR_WIPE_RANDOM]       = &NeoAnimationFX::mode_color_wipe_random;
      _mode[FX_MODE_RANDOM_COLOR]            = &NeoAnimationFX::mode_random_color;
      _mode[FX_MODE_SINGLE_DYNAMIC]          = &NeoAnimationFX::mode_single_dynamic;
      _mode[FX_MODE_MULTI_DYNAMIC]           = &NeoAnimationFX::mode_multi_dynamic;
      _mode[FX_MODE_RAINBOW]                 = &NeoAnimationFX::mode_rainbow;
      _mode[FX_MODE_RAINBOW_CYCLE]           = &NeoAnimationFX::mode_rainbow_cycle;
      _mode[FX_MODE_SCAN]                    = &NeoAnimationFX::mode_scan;
      _mode[FX_MODE_DUAL_SCAN]               = &NeoAnimationFX::mode_dual_scan;
      _mode[FX_MODE_FADE]                    = &NeoAnimationFX::mode_fade;
      _mode[FX_MODE_THEATER_CHASE]           = &NeoAnimationFX::mode_theater_chase;
      _mode[FX_MODE_THEATER_CHASE_RAINBOW]   = &NeoAnimationFX::mode_theater_chase_rainbow;
      _mode[FX_MODE_TWINKLE]                 = &NeoAnimationFX::mode_twinkle;
      _mode[FX_MODE_TWINKLE_RANDOM]          = &NeoAnimationFX::mode_twinkle_random;
      _mode[FX_MODE_TWINKLE_FADE]            = &NeoAnimationFX::mode_twinkle_fade;
      _mode[FX_MODE_TWINKLE_FADE_RANDOM]     = &NeoAnimationFX::mode_twinkle_fade_random;
      _mode[FX_MODE_SPARKLE]                 = &NeoAnimationFX::mode_sparkle;
      _mode[FX_MODE_FLASH_SPARKLE]           = &NeoAnimationFX::mode_flash_sparkle;
      _mode[FX_MODE_HYPER_SPARKLE]           = &NeoAnimationFX::mode_hyper_sparkle;
      _mode[FX_MODE_STROBE]                  = &NeoAnimationFX::mode_strobe;
      _mode[FX_MODE_STROBE_RAINBOW]          = &NeoAnimationFX::mode_strobe_rainbow;
      _mode[FX_MODE_MULTI_STROBE]            = &NeoAnimationFX::mode_multi_strobe;
      _mode[FX_MODE_BLINK_RAINBOW]           = &NeoAnimationFX::mode_blink_rainbow;
      _mode[FX_MODE_CHASE_WHITE]             = &NeoAnimationFX::mode_chase_white;
      _mode[FX_MODE_CHASE_COLOR]             = &NeoAnimationFX::mode_chase_color;
      _mode[FX_MODE_CHASE_RANDOM]            = &NeoAnimationFX::mode_chase_random;
      _mode[FX_MODE_CHASE_RAINBOW]           = &NeoAnimationFX::mode_chase_rainbow;
      _mode[FX_MODE_CHASE_FLASH]             = &NeoAnimationFX::mode_chase_flash;
      _mode[FX_MODE_CHASE_FLASH_RANDOM]      = &NeoAnimationFX::mode_chase_flash_random;
      _mode[FX_MODE_CHASE_RAINBOW_WHITE]     = &NeoAnimationFX::mode_chase_rainbow_white;
      _mode[FX_MODE_CHASE_BLACKOUT]          = &NeoAnimationFX::mode_chase_blackout;
      _mode[FX_MODE_CHASE_BLACKOUT_RAINBOW]  = &NeoAnimationFX::mode_chase_blackout_rainbow;
      _mode[FX_MODE_COLOR_SWEEP_RANDOM]      = &NeoAnimationFX::mode_color_sweep_random;
      _mode[FX_MODE_RUNNING_COLOR]           = &NeoAnimationFX::mode_running_color;
      _mode[FX_MODE_RUNNING_RED_BLUE]        = &NeoAnimationFX::mode_running_red_blue;
      _mode[FX_MODE_RUNNING_RANDOM]          = &NeoAnimationFX::mode_running_random;
      _mode[FX_MODE_LARSON_SCANNER]          = &NeoAnimationFX::mode_larson_scanner;
      _mode[FX_MODE_COMET]                   = &NeoAnimationFX::mode_comet;
      _mode[FX_MODE_FIREWORKS]               = &NeoAnimationFX::mode_fireworks;
      _mode[FX_MODE_FIREWORKS_RANDOM]        = &NeoAnimationFX::mode_fireworks_random;
      _mode[FX_MODE_MERRY_CHRISTMAS]         = &NeoAnimationFX::mode_merry_christmas;
      _mode[FX_MODE_HALLOWEEN]               = &NeoAnimationFX::mode_halloween;
      _mode[FX_MODE_FIRE_FLICKER]            = &NeoAnimationFX::mode_fire_flicker;
      _mode[FX_MODE_FIRE_FLICKER_SOFT]       = &NeoAnimationFX::mode_fire_flicker_soft;
      _mode[FX_MODE_FIRE_FLICKER_INTENSE]    = &NeoAnimationFX::mode_fire_flicker_intense;
      _mode[FX_MODE_CIRCUS_COMBUSTUS]        = &NeoAnimationFX::mode_circus_combustus;
      _mode[FX_MODE_BICOLOR_CHASE]           = &NeoAnimationFX::mode_bicolor_chase;
      _mode[FX_MODE_TRICOLOR_CHASE]          = &NeoAnimationFX::mode_tricolor_chase;
// if flash memory is constrained (I'm looking at you Arduino Nano), replace modes
// that use a lot of flash with mode_static (reduces flash footprint by about 3600 bytes)
#ifdef REDUCED_MODES
      _mode[FX_MODE_BREATH]                  = &NeoAnimationFX::mode_static;
      _mode[FX_MODE_RUNNING_LIGHTS]          = &NeoAnimationFX::mode_static;
      _mode[FX_MODE_ICU]                     = &NeoAnimationFX::mode_static;
#else
      _mode[FX_MODE_BREATH]                  = &NeoAnimationFX::mode_breath;
      _mode[FX_MODE_RUNNING_LIGHTS]          = &NeoAnimationFX::mode_running_lights;
      _mode[FX_MODE_ICU]                     = &NeoAnimationFX::mode_icu;
#endif
      _mode[FX_MODE_CUSTOM]                  = &NeoAnimationFX::mode_custom;
      _mode[FX_MODE_METEOR_RAIN]             = &NeoAnimationFX::mode_meteor_rain;

      _name[FX_MODE_STATIC]                    = F("Static");
      _name[FX_MODE_BLINK]                     = F("Blink");
      _name[FX_MODE_BREATH]                    = F("Breath");
      _name[FX_MODE_COLOR_WIPE]                = F("Color Wipe");
      _name[FX_MODE_COLOR_WIPE_INV ]           = F("Color Wipe Inverse");
      _name[FX_MODE_COLOR_WIPE_REV]            = F("Color Wipe Reverse");
      _name[FX_MODE_COLOR_WIPE_REV_INV]        = F("Color Wipe Reverse Inverse");
      _name[FX_MODE_COLOR_WIPE_RANDOM]         = F("Color Wipe Random");
      _name[FX_MODE_RANDOM_COLOR]              = F("Random Color");
      _name[FX_MODE_SINGLE_DYNAMIC]            = F("Single Dynamic");
      _name[FX_MODE_MULTI_DYNAMIC]             = F("Multi Dynamic");
      _name[FX_MODE_RAINBOW]                   = F("Rainbow");
      _name[FX_MODE_RAINBOW_CYCLE]             = F("Rainbow Cycle");
      _name[FX_MODE_SCAN]                      = F("Scan");
      _name[FX_MODE_DUAL_SCAN]                 = F("Dual Scan");
      _name[FX_MODE_FADE]                      = F("Fade");
      _name[FX_MODE_THEATER_CHASE]             = F("Theater Chase");
      _name[FX_MODE_THEATER_CHASE_RAINBOW]     = F("Theater Chase Rainbow");
      _name[FX_MODE_RUNNING_LIGHTS]            = F("Running Lights");
      _name[FX_MODE_TWINKLE]                   = F("Twinkle");
      _name[FX_MODE_TWINKLE_RANDOM]            = F("Twinkle Random");
      _name[FX_MODE_TWINKLE_FADE]              = F("Twinkle Fade");
      _name[FX_MODE_TWINKLE_FADE_RANDOM]       = F("Twinkle Fade Random");
      _name[FX_MODE_SPARKLE]                   = F("Sparkle");
      _name[FX_MODE_FLASH_SPARKLE]             = F("Flash Sparkle");
      _name[FX_MODE_HYPER_SPARKLE]             = F("Hyper Sparkle");
      _name[FX_MODE_STROBE]                    = F("Strobe");
      _name[FX_MODE_STROBE_RAINBOW]            = F("Strobe Rainbow");
      _name[FX_MODE_MULTI_STROBE]              = F("Multi Strobe");
      _name[FX_MODE_BLINK_RAINBOW]             = F("Blink Rainbow");
      _name[FX_MODE_CHASE_WHITE]               = F("Chase White");
      _name[FX_MODE_CHASE_COLOR]               = F("Chase Color");
      _name[FX_MODE_CHASE_RANDOM]              = F("Chase Random");
      _name[FX_MODE_CHASE_RAINBOW]             = F("Chase Rainbow");
      _name[FX_MODE_CHASE_FLASH]               = F("Chase Flash");
      _name[FX_MODE_CHASE_FLASH_RANDOM]        = F("Chase Flash Random");
      _name[FX_MODE_CHASE_RAINBOW_WHITE]       = F("Chase Rainbow White");
      _name[FX_MODE_CHASE_BLACKOUT]            = F("Chase Blackout");
      _name[FX_MODE_CHASE_BLACKOUT_RAINBOW]    = F("Chase Blackout Rainbow");
      _name[FX_MODE_COLOR_SWEEP_RANDOM]        = F("Color Sweep Random");
      _name[FX_MODE_RUNNING_COLOR]             = F("Running Color");
      _name[FX_MODE_RUNNING_RED_BLUE]          = F("Running Red Blue");
      _name[FX_MODE_RUNNING_RANDOM]            = F("Running Random");
      _name[FX_MODE_LARSON_SCANNER]            = F("Larson Scanner");
      _name[FX_MODE_COMET]                     = F("Comet");
      _name[FX_MODE_FIREWORKS]                 = F("Fireworks");
      _name[FX_MODE_FIREWORKS_RANDOM]          = F("Fireworks Random");
      _name[FX_MODE_MERRY_CHRISTMAS]           = F("Merry Christmas");
      _name[FX_MODE_HALLOWEEN]                 = F("Halloween");
      _name[FX_MODE_FIRE_FLICKER]              = F("Fire Flicker");
      _name[FX_MODE_FIRE_FLICKER_SOFT]         = F("Fire Flicker (soft)");
      _name[FX_MODE_FIRE_FLICKER_INTENSE]      = F("Fire Flicker (intense)");
      _name[FX_MODE_CIRCUS_COMBUSTUS]          = F("Circus Combustus");
      _name[FX_MODE_BICOLOR_CHASE]             = F("Bicolor Chase");
      _name[FX_MODE_TRICOLOR_CHASE]            = F("Tricolor Chase");
      _name[FX_MODE_ICU]                       = F("ICU");
      _name[FX_MODE_CUSTOM]                    = F("Custom");
	  _name[FX_MODE_METEOR_RAIN]               = F("Meteor Rain");

      _brightness = DEFAULT_BRIGHTNESS;
	  _running = false;
	  _num_segments = 1;
      _segments[0].mode = DEFAULT_MODE;
      _segments[0].colors[0] = (RgbColor) HtmlColor(DEFAULT_COLOR);
      _segments[0].start = 0;
	  (_strip.PixelCount() >= MAX_PIXEL_CT) ? _segments[0].stop = MAX_PIXEL_CT : _segments[0].stop = _strip.PixelCount() ;
      _segments[0].speed = DEFAULT_SPEED;
      RESET_RUNTIME;
    }
  
  void init() {
    _strip.Begin(); 	
    setBrightness(_brightness);
    _strip.Show();
  }
  
  void service() {
    if(_running || _triggered) {
      unsigned long now = millis(); // Be aware, millis() rolls over every 49 days
      bool doShow = false;
      for(uint8_t i=0; i < _num_segments; i++) {
        _segment_index = i;
        if(now > SEGMENT_RUNTIME.next_time || _triggered) {
          doShow = true;
          uint16_t delay = (this->*_mode[SEGMENT.mode])();
          SEGMENT_RUNTIME.next_time = now + max((int)delay, SPEED_MIN);
          SEGMENT_RUNTIME.counter_mode_call++;
        }
      }
      if(doShow) {
        //delay(1); // for ESP32 (see https://forums.adafruit.com/viewtopic.php?f=47&t=117327)
        _strip.Show();
      }
      _triggered = false;
    }
  }
  
  void start() {
	RESET_RUNTIME;
    _running = true;
  }

  void stop() {
    _running = false;
    strip_off();
  }
  
  void clear(){
    strip_off();
  }
    
  void show(){
    _strip.Show();
  }

  void trigger() {
    _triggered = true;
  }

  void setMode(uint8_t m) {
	RESET_RUNTIME;
	_segments[0].mode = constrain(m, 0, MODE_COUNT - 1);
    setBrightness(_brightness);
  }

  void setSpeed(uint16_t s) {
	RESET_RUNTIME;
    _segments[0].speed = constrain(s, SPEED_MIN, SPEED_MAX);
  }

  void increaseSpeed(uint8_t s) {
	uint16_t newSpeed = constrain(SEGMENT.speed + s, SPEED_MIN, SPEED_MAX);
    setSpeed(newSpeed);
  }

  void decreaseSpeed(uint8_t s) {
	uint16_t newSpeed = constrain(SEGMENT.speed - s, SPEED_MIN, SPEED_MAX);
    setSpeed(newSpeed);
  }

  void setBrightness(uint8_t b) {
    _brightness = constrain(b, BRIGHTNESS_MIN, BRIGHTNESS_MAX);
    _strip.SetBrightness(_brightness);
    _strip.Show();
  }
  
  void increaseBrightness(uint8_t s) {
    s = constrain(_brightness + s, BRIGHTNESS_MIN, BRIGHTNESS_MAX);
    setBrightness(s);
  }

  void decreaseBrightness(uint8_t s) {
    s = constrain(_brightness - s, BRIGHTNESS_MIN, BRIGHTNESS_MAX);
    setBrightness(s);
  }
  
  void setLength(uint16_t b) {
    RESET_RUNTIME;
    if (b < 1) b = 1;
    _segments[0].start = 0;
    _segments[0].stop = b;
  }

  void increaseLength(uint16_t s) {
    s = _segments[0].stop - _segments[0].start + 1 + s;
    setLength(s);
  }

  void decreaseLength(uint16_t s) {
    if (s > _segments[0].stop - _segments[0].start + 1) s = 1;
    s = _segments[0].stop - _segments[0].start + 1 - s;

    for(uint16_t i=_segments[0].start + s; i <= (_segments[0].stop - _segments[0].start + 1); i++) {
      this->setPixelColor(i, (RgbColor) HtmlColor(BLACK));
    }
    _strip.Show();

    setLength(s);
  }
  
  uint16_t getLength(void) {
    return _segments[0].stop - _segments[0].start + 1;
  }

  void setColor(RgbColor c) {
    RESET_RUNTIME;
    _segments[0].colors[0] = c;
  }
  
  void setColor(uint32_t c) {
    RESET_RUNTIME;
    _segments[0].colors[0] = (RgbColor) HtmlColor((uint32_t) c);
  }
  
  void setColor(uint8_t r, uint8_t g, uint8_t b) {
	setColor(((uint32_t)r << 16) | ((uint32_t)g <<  8) | b);
  }
  
  void setPixelColor(uint16_t pixel, uint8_t r, uint8_t g, uint8_t b) {
    RgbColor color_tmp(r, g, b);
	_strip.SetPixelColor(pixel, color_tmp);
  }
  
  void setPixelColor(uint16_t pixel, RgbColor pixel_rgb_color) {
	_strip.SetPixelColor(pixel, pixel_rgb_color);
  }
  
  uint8_t getMode(void) {
	return _segments[0].mode;
  }

  uint16_t getSpeed(void) {
	return _segments[0].speed;
  }

  uint8_t getBrightness(void) {
    return _brightness;
  }
  
  uint8_t getModeCount(void) {
    return MODE_COUNT;
  }
  
  uint32_t getColor(void) {
	return _segments[0].colors[0];
  }
  
  uint16_t numPixels(void){
	return _segments[0].stop - _segments[0].start + 1;
  }

  boolean isRunning() {
    return _running;
  }
  
  const __FlashStringHelper* getModeName(uint8_t m) {
    if(m < MODE_COUNT) {
      return _name[m];
    } else {
      return F("");
    }
  }

  uint8_t getNumSegments() {
    return _num_segments;
  }

  void setNumSegments(uint8_t n) {
    _num_segments = n;
  }
  
  Segment getSegment() {
    return SEGMENT;
  }

  Segment_runtime getSegmentRuntime() {
    return SEGMENT_RUNTIME;
  }

  Segment* getSegments() {
    return _segments;
  }

  void setSegment(uint8_t n, uint16_t start, uint16_t stop, uint8_t mode, uint32_t color, uint16_t speed, bool reverse) {
    if(n < (sizeof(_segments) / sizeof(_segments[0]))) {
      if(n + 1 > _num_segments) _num_segments = n + 1;
      _segments[n].start = start;
      _segments[n].stop = stop;
      _segments[n].mode = mode;
      _segments[n].speed = speed;
      _segments[n].reverse = reverse;
	  _segments[n].colors[0] = (RgbColor) HtmlColor(color);
    }
  }

  void setSegment(uint8_t n, uint16_t start, uint16_t stop, uint8_t mode, const uint32_t colors[], uint16_t speed, bool reverse) {
    if(n < (sizeof(_segments) / sizeof(_segments[0]))) {
      if(n + 1 > _num_segments) _num_segments = n + 1;
      _segments[n].start = start;
      _segments[n].stop = stop;
      _segments[n].mode = mode;
      _segments[n].speed = speed;
      _segments[n].reverse = reverse;

      for(uint8_t i=0; i<NUM_COLORS; i++) {
		_segments[n].colors[i] = (RgbColor) HtmlColor(colors[i]);
      }
    }
  }

  void resetSegments() {
    memset(_segments, 0, sizeof(_segments));
    memset(_segment_runtimes, 0, sizeof(_segment_runtimes));
    _segment_index = 0;
    _num_segments = 1;
    setSegment(0, 0, 7, FX_MODE_STATIC, DEFAULT_COLOR, DEFAULT_SPEED, false);
  }
  
  /*
  * Custom mode helper
  */
  void setCustomMode(uint16_t (*p)()) {
    setMode(FX_MODE_CUSTOM);
    customMode = p;
  }
  
  /*
  * Put a value 0 to 255 in to get a color value.
  * The colours are a transition r -> g -> b -> back to r
  * Inspired by the Adafruit examples.
  */
  RgbColor color_wheel(uint8_t pos) {
    pos = 255 - pos;
	uint32_t ret_hex;
    if(pos < 85) {
      ret_hex = ((uint32_t)(255 - pos * 3) << 16) | ((uint32_t)(0) << 8) | (pos * 3);
    } else if(pos < 170) {
      pos -= 85;
      ret_hex = ((uint32_t)(0) << 16) | ((uint32_t)(pos * 3) << 8) | (255 - pos * 3);
    } else {
      pos -= 170;
      ret_hex = ((uint32_t)(pos * 3) << 16) | ((uint32_t)(255 - pos * 3) << 8) | (0);
    }
	return (RgbColor) HtmlColor((uint32_t) ret_hex);
  }


  /*
  * Returns a new, random wheel index with a minimum distance of 42 from pos.
  */
  uint8_t get_random_wheel_index(uint8_t pos) {
    uint8_t r = 0;
    uint8_t x = 0;
    uint8_t y = 0;
    uint8_t d = 0;

    while(d < 42) {
      r = random(256);
      x = abs(pos - r);
      y = 255 - x;
      d = min(x, y);
    }

    return r;
  }

  private:
  T_PIXEL_METHOD& _strip;
	
  uint8_t 
      _brightness;
	  
  boolean
      _running,
      _triggered;
	  
  unsigned long next_time;

  RgbColor colorConverted(uint32_t color) {
    RgbColor color_tmp(HtmlColor( _color ));
	return color_tmp;
  } 
  
  void strip_off() {
	_strip.ClearTo(rgbcolor_black);
    _strip.Show();
  }

  //////////// Start of Effects ////////////
  
  /*
  * Fades all pixel to Black (percentage rgb)
  */
  void fadeToBlack(uint16_t ledNo, byte fadeValue) {
    RgbColor oldColor = _strip.GetPixelColor(ledNo);
    uint8_t r = (oldColor.R <= 10)? 0 : (uint8_t) oldColor.R - (oldColor.R * fadeValue / 256);
    uint8_t g = (oldColor.G <= 10)? 0 : (uint8_t) oldColor.G - (oldColor.G * fadeValue / 256);
    uint8_t b = (oldColor.B <= 10)? 0 : (uint8_t) oldColor.B - (oldColor.B * fadeValue / 256);
	RgbColor newColor(r, g, b);    
    _strip.SetPixelColor(ledNo, newColor);
  }

  /*
  * Fades all pixel to Black (use absolute value)
  */
  void fadeToWhiteVal(uint16_t ledNo, uint8_t fadeValue) {
    RgbColor color_tmp = _strip.GetPixelColor(ledNo);
	if(fadeValue < 10) fadeValue = 0; 
	color_tmp.Lighten(fadeValue);
    _strip.SetPixelColor(ledNo, color_tmp);
  }

  /*
  * Fades all pixel to Black (percentage rgb)
  */
  void fadeToWhite(uint16_t ledNo, byte fadeValue) {
    RgbColor oldColor = _strip.GetPixelColor(ledNo);
    uint8_t r = (oldColor.R <= 10)? 0 : (uint8_t) oldColor.R + (oldColor.R * fadeValue / 256);
    uint8_t g = (oldColor.G <= 10)? 0 : (uint8_t) oldColor.G + (oldColor.G * fadeValue / 256);
    uint8_t b = (oldColor.B <= 10)? 0 : (uint8_t) oldColor.B + (oldColor.B * fadeValue / 256);
	RgbColor newColor(r, g, b);    
    _strip.SetPixelColor(ledNo, newColor);
  }

  /*
  * Fades all pixel to Black (use absolute value)
  */
  void fadeToBlackVal(uint16_t ledNo, uint8_t fadeValue) {
    RgbColor color_tmp = _strip.GetPixelColor(ledNo);
	if(fadeValue < 10) fadeValue = 0; 
	color_tmp.Darken(fadeValue);
    _strip.SetPixelColor(ledNo, color_tmp);
  }
  
  /*
  * No blinking. Just plain old static light.
  */
  uint16_t mode_static(void) {	
	for(uint16_t i=SEGMENT.start; i <= SEGMENT.stop; i++) {
      this->setPixelColor(i, SEGMENT.colors[0]);
    }
    return 500;
  }
  
  /*
  * Blink/strobe function
  * Alternate between color1 and color2
  * if(strobe == true) then create a strobe effect
  */
  uint16_t blink(RgbColor color1, RgbColor color2, bool strobe) {
    RgbColor color = ((SEGMENT_RUNTIME.counter_mode_call & 1) == 0) ? color1 : color2;
    if(SEGMENT.reverse) color = (color == color1) ? color2 : color1;

    for(uint16_t i=SEGMENT.start; i <= SEGMENT.stop; i++) {
      this->setPixelColor(i, color);
    }

    if((SEGMENT_RUNTIME.counter_mode_call & 1) == 0) {
      return strobe ? 20 : (SEGMENT.speed / 2);
    } else {
      return strobe ? SEGMENT.speed - 20 : (SEGMENT.speed / 2);
    }
  }

  /*
  * Normal blinking. 50% on/off time.
  */
  uint16_t mode_blink(void) {
    return blink(SEGMENT.colors[0], SEGMENT.colors[1], false);
  }

  /*
  * Does the "standby-breathing" of well known i-Devices. Fixed Speed.
  * Use mode "fade" if you like to have something similar with a different speed.
  */
  uint16_t mode_breath(void) {
    //                                      0    1    2   3   4   5   6    7   8   9  10  11   12   13   14   15   16    // step
    uint16_t breath_delay_steps[] =     {   7,   9,  13, 15, 16, 17, 18, 930, 19, 18, 15, 13,   9,   7,   4,   5,  10 }; // magic numbers for breathing LED
    uint8_t breath_brightness_steps[] = { 150, 125, 100, 75, 50, 25, 16,  15, 16, 25, 50, 75, 100, 125, 150, 220, 255 }; // even more magic numbers!

    if(SEGMENT_RUNTIME.counter_mode_call == 0) {
      SEGMENT_RUNTIME.aux_param = breath_brightness_steps[0] + 1; // we use aux_param to store the brightness
    }

    uint8_t breath_brightness = SEGMENT_RUNTIME.aux_param;

    if(SEGMENT_RUNTIME.counter_mode_step < 8) {
      breath_brightness--;
    } else {
      breath_brightness++;
    }

    // update index of current delay when target brightness is reached, start over after the last step
    if(breath_brightness == breath_brightness_steps[SEGMENT_RUNTIME.counter_mode_step]) {
      SEGMENT_RUNTIME.counter_mode_step = (SEGMENT_RUNTIME.counter_mode_step + 1) % (sizeof(breath_brightness_steps)/sizeof(uint8_t));
    }

    int lum = map(breath_brightness, 0, 255, 0, _brightness);  // keep luminosity below brightness set by user
    //uint8_t w = (SEGMENT.colors[0].W) * lum / _brightness; // modify RGBW colors with brightness info
    uint8_t r = (SEGMENT.colors[0].R) * lum / _brightness;
    uint8_t g = (SEGMENT.colors[0].G) * lum / _brightness;
    uint8_t b = (SEGMENT.colors[0].B) * lum / _brightness;
    for(uint16_t i=SEGMENT.start; i <= SEGMENT.stop; i++) {
      this->setPixelColor(i, r, g, b);
    }

    SEGMENT_RUNTIME.aux_param = breath_brightness;
    return breath_delay_steps[SEGMENT_RUNTIME.counter_mode_step];
  }
  
  uint16_t color_wipe(RgbColor color1, RgbColor color2, bool rev) {
    if(SEGMENT_RUNTIME.counter_mode_step < SEGMENT_LENGTH) {
      uint32_t led_offset = SEGMENT_RUNTIME.counter_mode_step;
      if(SEGMENT.reverse) {
        this->setPixelColor(SEGMENT.stop - led_offset, color1);
      } else {
        this->setPixelColor(SEGMENT.start + led_offset, color1);
      }
    } else {
      uint32_t led_offset = SEGMENT_RUNTIME.counter_mode_step - SEGMENT_LENGTH;
      if((SEGMENT.reverse && !rev) || (!SEGMENT.reverse && rev)) {
        this->setPixelColor(SEGMENT.stop - led_offset, color2);
      } else {
        this->setPixelColor(SEGMENT.start + led_offset, color2);
      }
    }

    SEGMENT_RUNTIME.counter_mode_step = (SEGMENT_RUNTIME.counter_mode_step + 1) % (SEGMENT_LENGTH * 2);
    return (SEGMENT.speed / (SEGMENT_LENGTH * 2));
  }
  
  /*
  * Lights all LEDs one after another.
  */
  uint16_t mode_color_wipe(void) {
    return color_wipe(SEGMENT.colors[0], SEGMENT.colors[1], false);
  }

  uint16_t mode_color_wipe_inv(void) {
    return color_wipe(SEGMENT.colors[1], SEGMENT.colors[0], false);
  }

  uint16_t mode_color_wipe_rev(void) {
    return color_wipe(SEGMENT.colors[0], SEGMENT.colors[1], true);
  }

  uint16_t mode_color_wipe_rev_inv(void) {
    return color_wipe(SEGMENT.colors[1], SEGMENT.colors[0], true);
  }
  
  /*
  * Turns all LEDs after each other to a random color.
  * Then starts over with another color.
  */
  uint16_t mode_color_wipe_random(void) {
    if(SEGMENT_RUNTIME.counter_mode_step % SEGMENT_LENGTH == 0) { // aux_param will store our random color wheel index
      SEGMENT_RUNTIME.aux_param = get_random_wheel_index(SEGMENT_RUNTIME.aux_param);
    }
    RgbColor color = color_wheel(SEGMENT_RUNTIME.aux_param);
    return color_wipe(color, color, false) * 2;
  }

  /*
  * Lights all LEDs in one random color up. Then switches them
  * to the next random color.
  */
  uint16_t mode_random_color(void) {
    SEGMENT_RUNTIME.aux_param = get_random_wheel_index(SEGMENT_RUNTIME.aux_param); // aux_param will store our random color wheel index
    RgbColor color = color_wheel(SEGMENT_RUNTIME.aux_param);

    for(uint16_t i=SEGMENT.start; i <= SEGMENT.stop; i++) {
      this->setPixelColor(i, color);
    }
    return (SEGMENT.speed);
  }

  /*
  * Lights every LED in a random color. Changes one random LED after the other
  * to another random color.
  */
  uint16_t mode_single_dynamic(void) {
    if(SEGMENT_RUNTIME.counter_mode_call == 0) {
      for(uint16_t i=SEGMENT.start; i <= SEGMENT.stop; i++) {
        this->setPixelColor(i, color_wheel(random(256)));
      }
    }

    this->setPixelColor(SEGMENT.start + random(SEGMENT_LENGTH), color_wheel(random(256)));
    return (SEGMENT.speed);
  }

  /*
  * Lights every LED in a random color. Changes all LED at the same time
  * to new random colors.
   */
  uint16_t mode_multi_dynamic(void) {
    for(uint16_t i=SEGMENT.start; i <= SEGMENT.stop; i++) {
      this->setPixelColor(i, color_wheel(random(256)));
    }
    return (SEGMENT.speed);
  }
  
  /*
  * Cycles all LEDs at once through a rainbow.
  */
  uint16_t mode_rainbow(void) {
    RgbColor color = color_wheel(SEGMENT_RUNTIME.counter_mode_step);
    for(uint16_t i=SEGMENT.start; i <= SEGMENT.stop; i++) {
      this->setPixelColor(i, color);
    }

    SEGMENT_RUNTIME.counter_mode_step = (SEGMENT_RUNTIME.counter_mode_step + 1) & 0xFF;
    return (SEGMENT.speed / 256);
  }

  /*
  * Cycles a rainbow over the entire string of LEDs.
  */
  uint16_t mode_rainbow_cycle(void) {
    for(uint16_t i=0; i < SEGMENT_LENGTH; i++) {
	    RgbColor color = color_wheel(((i * 256 / SEGMENT_LENGTH) + SEGMENT_RUNTIME.counter_mode_step) & 0xFF);
      this->setPixelColor(SEGMENT.start + i, color);
    }

    SEGMENT_RUNTIME.counter_mode_step = (SEGMENT_RUNTIME.counter_mode_step + 1) & 0xFF;
    return (SEGMENT.speed / 256);
  }
  
  /*
  * Runs a single pixel back and forth.
  */
  uint16_t mode_scan(void) {
    if(SEGMENT_RUNTIME.counter_mode_step > (SEGMENT_LENGTH * 2) - 3) {
      SEGMENT_RUNTIME.counter_mode_step = 0;
    }
	
	for(uint16_t i=SEGMENT.start; i <= SEGMENT.stop; i++) {
      this->setPixelColor(i, rgbcolor_black);
    }

    int led_offset = SEGMENT_RUNTIME.counter_mode_step - (SEGMENT_LENGTH - 1);
    led_offset = abs(led_offset); 

    if(SEGMENT.reverse) {
      this->setPixelColor(SEGMENT.stop - led_offset, SEGMENT.colors[0]);
    } else {
      this->setPixelColor(SEGMENT.start + led_offset, SEGMENT.colors[0]);
    }

    SEGMENT_RUNTIME.counter_mode_step++;
    return (SEGMENT.speed / (SEGMENT_LENGTH * 2));
  }

  /*
  * Runs two pixel back and forth in opposite directions.
  */
  uint16_t mode_dual_scan(void) {
    if(SEGMENT_RUNTIME.counter_mode_step > (SEGMENT_LENGTH * 2) - 3) {
      SEGMENT_RUNTIME.counter_mode_step = 0;
    }

    for(uint16_t i=SEGMENT.start; i <= SEGMENT.stop; i++) {
      this->setPixelColor(i, BLACK);
    }

    int led_offset = SEGMENT_RUNTIME.counter_mode_step - (SEGMENT_LENGTH - 1);
    led_offset = abs(led_offset);

    this->setPixelColor(SEGMENT.start + led_offset, SEGMENT.colors[0]);
    this->setPixelColor(SEGMENT.start + SEGMENT_LENGTH - led_offset - 1, SEGMENT.colors[0]);

    SEGMENT_RUNTIME.counter_mode_step++;
    return (SEGMENT.speed / (SEGMENT_LENGTH * 2));
  }
  
  /*
  * Fades the LEDs on and (almost) off again.
  */
  uint16_t mode_fade(void) {
    int lum = SEGMENT_RUNTIME.counter_mode_step - 31;
    lum = 63 - (abs(lum) * 2);
    lum = map(lum, 0, 64, min(25, (int)_brightness), _brightness);

    //uint8_t w = (SEGMENT.colors[0] >> 24 & 0xFF) * lum / _brightness; // modify RGBW colors with brightness info
    uint8_t r = (SEGMENT.colors[0].R) * lum / _brightness;
    uint8_t g = (SEGMENT.colors[0].G) * lum / _brightness;
    uint8_t b = (SEGMENT.colors[0].B) * lum / _brightness;
    for(uint16_t i=SEGMENT.start; i <= SEGMENT.stop; i++) {
      this->setPixelColor(i, r, g, b);
    }

    SEGMENT_RUNTIME.counter_mode_step = (SEGMENT_RUNTIME.counter_mode_step + 1) % 64;
    return (SEGMENT.speed / 64);
  }
  
  /*
  * theater chase function
  */
  uint16_t theater_chase(RgbColor color1, RgbColor color2) {
    SEGMENT_RUNTIME.counter_mode_call = SEGMENT_RUNTIME.counter_mode_call % 3;
    for(uint16_t i=0; i < SEGMENT_LENGTH; i++) {
      if((i % 3) == SEGMENT_RUNTIME.counter_mode_call) {
        if(SEGMENT.reverse) {
          this->setPixelColor(SEGMENT.stop - i, color1);
        } else {
          this->setPixelColor(SEGMENT.start + i, color1);
        }
      } else {
        if(SEGMENT.reverse) {
          this->setPixelColor(SEGMENT.stop - i, color2);
        } else {
          this->setPixelColor(SEGMENT.start + i, color2);
        }
      }
    }

    return (SEGMENT.speed / SEGMENT_LENGTH);
  }

  /*
  * Theatre-style crawling lights.
  * Inspired by the Adafruit examples.
  */
  uint16_t mode_theater_chase(void) {
    return theater_chase(SEGMENT.colors[0], rgbcolor_black);
  }

  /*
  * Theatre-style crawling lights with rainbow effect.
  * Inspired by the Adafruit examples.
  */
  uint16_t mode_theater_chase_rainbow(void) {
    SEGMENT_RUNTIME.counter_mode_step = (SEGMENT_RUNTIME.counter_mode_step + 1) & 0xFF;
    return theater_chase(color_wheel(SEGMENT_RUNTIME.counter_mode_step), BLACK);
  }
  
  /*
  * Running lights effect with smooth sine transition.
  */
  uint16_t mode_running_lights(void) {
    float radPerLed = (2.0 * 3.14159) / SEGMENT_LENGTH;
    for(uint16_t i=0; i < SEGMENT_LENGTH; i++) {
      int lum = map((int)(sin((i + SEGMENT_RUNTIME.counter_mode_step) * radPerLed) * 128), -128, 128, 0, 255);
      if(SEGMENT.reverse) {
        this->setPixelColor(SEGMENT.start + i, (SEGMENT.colors[0].R * lum) / 256, (SEGMENT.colors[0].G * lum) / 256, (SEGMENT.colors[0].B * lum) / 256);
      } else {
        this->setPixelColor(SEGMENT.stop - i, (SEGMENT.colors[0].R * lum) / 256, (SEGMENT.colors[0].G * lum) / 256, (SEGMENT.colors[0].B * lum) / 256);
      }
    }
    SEGMENT_RUNTIME.counter_mode_step = (SEGMENT_RUNTIME.counter_mode_step + 1) % SEGMENT_LENGTH;
    return (SEGMENT.speed / SEGMENT_LENGTH);
  }

  /*
   * twinkle function
   */
  uint16_t twinkle(RgbColor color) {
    if(SEGMENT_RUNTIME.counter_mode_step == 0) {
      for(uint16_t i=SEGMENT.start; i <= SEGMENT.stop; i++) {
        this->setPixelColor(i, BLACK);
      }
      uint16_t min_leds = max(1, SEGMENT_LENGTH / 5); // make sure, at least one LED is on
      uint16_t max_leds = max(1, SEGMENT_LENGTH / 2); // make sure, at least one LED is on
      SEGMENT_RUNTIME.counter_mode_step = random(min_leds, max_leds);
    }

    this->setPixelColor(SEGMENT.start + random(SEGMENT_LENGTH), color);

    SEGMENT_RUNTIME.counter_mode_step--;
    return (SEGMENT.speed / SEGMENT_LENGTH);
  }

  /*
  * Blink several LEDs on, reset, repeat.
  * Inspired by www.tweaking4all.com/hardware/arduino/adruino-led-strip-effects/
  */
  uint16_t mode_twinkle(void) {
    return twinkle(SEGMENT.colors[0]);
  }

  /*
  * Blink several LEDs in random colors on, reset, repeat.
  * Inspired by www.tweaking4all.com/hardware/arduino/adruino-led-strip-effects/
  */
  uint16_t mode_twinkle_random(void) {
    return twinkle(color_wheel(random(256)));
  }
  
  /*
  * fade out function
  * fades out the current segment by dividing each pixel's intensity by 2
  */
  void fade_out() {
	for(uint16_t i=SEGMENT.start; i <= SEGMENT.stop; i++) {
      RgbColor rgbcolortmp = _strip.GetPixelColor(i);
	  RgbColor color_tmp((uint8_t)(rgbcolortmp.R/2), (uint8_t)(rgbcolortmp.G/2), (uint8_t)(rgbcolortmp.B/2) );
      _strip.SetPixelColor(i, color_tmp);
    }
  }

  /*
  * twinkle_fade function
  */
  uint16_t twinkle_fade(RgbColor color) {
    fade_out();

    if(random(3) == 0) {
      this->setPixelColor(SEGMENT.start + random(SEGMENT_LENGTH), color);
    }
    return (SEGMENT.speed / 8);
  }


  /*
  * Blink several LEDs on, fading out.
  */
  uint16_t mode_twinkle_fade(void) {
    return twinkle_fade(SEGMENT.colors[0]);
  }

  /*
  * Blink several LEDs in random colors on, fading out.
  */
  uint16_t mode_twinkle_fade_random(void) {
    return twinkle_fade(color_wheel(random(256)));
  }

  /*
  * Blinks one LED at a time.
  * Inspired by www.tweaking4all.com/hardware/arduino/adruino-led-strip-effects/
  */
  uint16_t mode_sparkle(void) {
    this->setPixelColor(SEGMENT.start + SEGMENT_RUNTIME.aux_param, rgbcolor_black);
    SEGMENT_RUNTIME.aux_param = random(SEGMENT_LENGTH); // aux_param stores the random led index
    this->setPixelColor(SEGMENT.start + SEGMENT_RUNTIME.aux_param, SEGMENT.colors[0]);
    return (SEGMENT.speed / SEGMENT_LENGTH);
  }

  /*
  * Lights all LEDs in the color. Flashes single white pixels randomly.
  * Inspired by www.tweaking4all.com/hardware/arduino/adruino-led-strip-effects/
  */
  uint16_t mode_flash_sparkle(void) {
    if(SEGMENT_RUNTIME.counter_mode_call == 0) {
      for(uint16_t i=SEGMENT.start; i <= SEGMENT.stop; i++) {
        this->setPixelColor(i, SEGMENT.colors[0]);
      }
    }

    this->setPixelColor(SEGMENT.start + SEGMENT_RUNTIME.aux_param, SEGMENT.colors[0]);

    if(random(5) == 0) {
      SEGMENT_RUNTIME.aux_param = random(SEGMENT_LENGTH); // aux_param stores the random led index
      this->setPixelColor(SEGMENT.start + SEGMENT_RUNTIME.aux_param, rgbcolor_white);
      return 20;
    } 
    return SEGMENT.speed;
  }

  /*
  * Like flash sparkle. With more flash.
  * Inspired by www.tweaking4all.com/hardware/arduino/adruino-led-strip-effects/
  */
  uint16_t mode_hyper_sparkle(void) {
    for(uint16_t i=SEGMENT.start; i <= SEGMENT.stop; i++) {
      this->setPixelColor(i, SEGMENT.colors[0]);
    }

    if(random(5) < 2) {
      for(uint16_t i=0; i < max(1, SEGMENT_LENGTH/3); i++) {
        this->setPixelColor(SEGMENT.start + random(SEGMENT_LENGTH), rgbcolor_white);
      }
      return 20;
    }
    return SEGMENT.speed;
  }
  
  /*
  * Classic Strobe effect.
  */
  uint16_t mode_strobe(void) {
    return blink(SEGMENT.colors[0], SEGMENT.colors[1], true);
  }

  /*
  * Classic Strobe effect. Cycling through the rainbow.
  */
  uint16_t mode_strobe_rainbow(void) {
    return blink(color_wheel(SEGMENT_RUNTIME.counter_mode_call & 0xFF), SEGMENT.colors[1], true);
  }
    
  /*
  * Strobe effect with different strobe count and pause, controlled by speed.
  */
  uint16_t mode_multi_strobe(void) {
    for(uint16_t i=SEGMENT.start; i <= SEGMENT.stop; i++) {
      this->setPixelColor(i, rgbcolor_black);
    }

    uint16_t delay = SEGMENT.speed / (2 * ((SEGMENT.speed / 10) + 1));
    if(SEGMENT_RUNTIME.counter_mode_step < (2 * ((SEGMENT.speed / 10) + 1))) {
      if((SEGMENT_RUNTIME.counter_mode_step & 1) == 0) {
        for(uint16_t i=SEGMENT.start; i <= SEGMENT.stop; i++) {
          this->setPixelColor(i, SEGMENT.colors[0]);
        }
        delay = 20;
      } else {
        delay = 50;
      }
    }
    SEGMENT_RUNTIME.counter_mode_step = (SEGMENT_RUNTIME.counter_mode_step + 1) % ((2 * ((SEGMENT.speed / 10) + 1)) + 1);
    return delay;
  }
  
  /*
  * Classic Blink effect. Cycling through the rainbow.
  */
  uint16_t mode_blink_rainbow(void) {
    return blink(color_wheel(SEGMENT_RUNTIME.counter_mode_call & 0xFF), SEGMENT.colors[1], false);
  }
  
  /*
  * color chase function.
  * color1 = background color
  * color2 and color3 = colors of two adjacent leds
  */
  uint16_t chase(RgbColor color1, RgbColor color2, RgbColor color3) {
    uint16_t a = SEGMENT_RUNTIME.counter_mode_step;
    uint16_t b = (a + 1) % SEGMENT_LENGTH;
    uint16_t c = (b + 1) % SEGMENT_LENGTH;
    if(SEGMENT.reverse) {
      this->setPixelColor(SEGMENT.stop - a, color1);
      this->setPixelColor(SEGMENT.stop - b, color2);
      this->setPixelColor(SEGMENT.stop - c, color3);
    } else {
      this->setPixelColor(SEGMENT.start + a, color1);
      this->setPixelColor(SEGMENT.start + b, color2);
      this->setPixelColor(SEGMENT.start + c, color3);
    }

    SEGMENT_RUNTIME.counter_mode_step = (SEGMENT_RUNTIME.counter_mode_step + 1) % SEGMENT_LENGTH;
    return (SEGMENT.speed / SEGMENT_LENGTH);
  }

  /*
  * Bicolor chase mode
  */
  uint16_t mode_bicolor_chase(void) {
    return chase(SEGMENT.colors[0], SEGMENT.colors[1], SEGMENT.colors[2]);
  }
  
  /*
  * White running on _color.
  */
  uint16_t mode_chase_color(void) {
    return chase(SEGMENT.colors[0], rgbcolor_white, rgbcolor_white);
  }

  /*
  * Black running on _color.
  */
  uint16_t mode_chase_blackout(void) {
    return chase(SEGMENT.colors[0], rgbcolor_black, rgbcolor_black);
  }

  /*
  * _color running on white.
  */
  uint16_t mode_chase_white(void) {
    return chase(rgbcolor_white, SEGMENT.colors[0], SEGMENT.colors[0]);
  }

  /*
  * White running followed by random color.
  */
  uint16_t mode_chase_random(void) {
    if(SEGMENT_RUNTIME.counter_mode_step == 0) {
      SEGMENT_RUNTIME.aux_param = get_random_wheel_index(SEGMENT_RUNTIME.aux_param);
    }
    return chase(color_wheel(SEGMENT_RUNTIME.aux_param), rgbcolor_white, rgbcolor_white);
  }

  /*
  * Rainbow running on white.
  */
  uint16_t mode_chase_rainbow_white(void) {
    uint16_t n = SEGMENT_RUNTIME.counter_mode_step;
    uint16_t m = (SEGMENT_RUNTIME.counter_mode_step + 1) % SEGMENT_LENGTH;
    RgbColor color2 = color_wheel(((n * 256 / SEGMENT_LENGTH) + (SEGMENT_RUNTIME.counter_mode_call & 0xFF)) & 0xFF);
    RgbColor color3 = color_wheel(((m * 256 / SEGMENT_LENGTH) + (SEGMENT_RUNTIME.counter_mode_call & 0xFF)) & 0xFF);

    return chase(rgbcolor_white, color2, color3);
  }

  /*
  * White running on rainbow.
  */
  uint16_t mode_chase_rainbow(void) {
    uint8_t color_sep = 256 / SEGMENT_LENGTH;
    uint8_t color_index = SEGMENT_RUNTIME.counter_mode_call & 0xFF;
    RgbColor color = color_wheel(((SEGMENT_RUNTIME.counter_mode_step * color_sep) + color_index) & 0xFF);

    return chase(color, rgbcolor_white, rgbcolor_white);
  }

  /*
  * Black running on rainbow.
  */
  uint16_t mode_chase_blackout_rainbow(void) {
    uint8_t color_sep = 256 / SEGMENT_LENGTH;
    uint8_t color_index = SEGMENT_RUNTIME.counter_mode_call & 0xFF;
    RgbColor color = color_wheel(((SEGMENT_RUNTIME.counter_mode_step * color_sep) + color_index) & 0xFF);

    return chase(color, rgbcolor_black, rgbcolor_black);
  }

  /*
  * White flashes running on _color.
  */
  uint16_t mode_chase_flash(void) {
    const static uint8_t flash_count = 4;
    uint8_t flash_step = SEGMENT_RUNTIME.counter_mode_call % ((flash_count * 2) + 1);

    for(uint16_t i=SEGMENT.start; i <= SEGMENT.stop; i++) {
      this->setPixelColor(i, SEGMENT.colors[0]);
    }

    uint16_t delay = (SEGMENT.speed / SEGMENT_LENGTH);
    if(flash_step < (flash_count * 2)) {
      if(flash_step % 2 == 0) {
        uint16_t n = SEGMENT_RUNTIME.counter_mode_step;
        uint16_t m = (SEGMENT_RUNTIME.counter_mode_step + 1) % SEGMENT_LENGTH;
        if(SEGMENT.reverse) {
          this->setPixelColor(SEGMENT.stop - n, rgbcolor_white);
          this->setPixelColor(SEGMENT.stop - m, rgbcolor_white);
        } else {
          this->setPixelColor(SEGMENT.start + n, rgbcolor_white);
          this->setPixelColor(SEGMENT.start + m, rgbcolor_white);
        }
        delay = 20;
      } else {
        delay = 30;
      }
    } else {
      SEGMENT_RUNTIME.counter_mode_step = (SEGMENT_RUNTIME.counter_mode_step + 1) % SEGMENT_LENGTH;
    }
    return delay;
  }

  /*
  * White flashes running, followed by random color.
  */
  uint16_t mode_chase_flash_random(void) {
    const static uint8_t flash_count = 4;
      uint8_t flash_step = SEGMENT_RUNTIME.counter_mode_call % ((flash_count * 2) + 1);

    for(uint16_t i=0; i < SEGMENT_RUNTIME.counter_mode_step; i++) {
      this->setPixelColor(SEGMENT.start + i, color_wheel(SEGMENT_RUNTIME.aux_param));
    }

    uint16_t delay = (SEGMENT.speed / SEGMENT_LENGTH);
    if(flash_step < (flash_count * 2)) {
      uint16_t n = SEGMENT_RUNTIME.counter_mode_step;
      uint16_t m = (SEGMENT_RUNTIME.counter_mode_step + 1) % SEGMENT_LENGTH;
      if(flash_step % 2 == 0) {
        this->setPixelColor(SEGMENT.start + n, rgbcolor_white);
        this->setPixelColor(SEGMENT.start + m, rgbcolor_white);
        delay = 20;
      } else {
        this->setPixelColor(SEGMENT.start + n, color_wheel(SEGMENT_RUNTIME.aux_param));
        this->setPixelColor(SEGMENT.start + m, rgbcolor_black);
        delay = 30;
      }
    } else {
      SEGMENT_RUNTIME.counter_mode_step = (SEGMENT_RUNTIME.counter_mode_step + 1) % SEGMENT_LENGTH;

      if(SEGMENT_RUNTIME.counter_mode_step == 0) {
        SEGMENT_RUNTIME.aux_param = get_random_wheel_index(SEGMENT_RUNTIME.aux_param);
      }
    }
    return delay;
  }
    
  /*
  * Random color intruduced alternating from start and end of strip.
  */
  uint16_t mode_color_sweep_random(void) {
    if(SEGMENT_RUNTIME.counter_mode_step % SEGMENT_LENGTH == 0) { // aux_param will store our random color wheel index
      SEGMENT_RUNTIME.aux_param = get_random_wheel_index(SEGMENT_RUNTIME.aux_param);
    }
    RgbColor color = color_wheel(SEGMENT_RUNTIME.aux_param);
    return color_wipe(color, color, true) * 2;
  }
  
  /*
  * Alternating pixels running function.
  */
  uint16_t running(RgbColor color1, RgbColor color2) {
    for(uint16_t i=0; i < SEGMENT_LENGTH; i++) {
      if((i + SEGMENT_RUNTIME.counter_mode_step) % 4 < 2) {
        if(SEGMENT.reverse) {
          this->setPixelColor(SEGMENT.start + i, color1);
        } else {
          this->setPixelColor(SEGMENT.stop - i, color1);
        }
      } else {
        if(SEGMENT.reverse) {
          this->setPixelColor(SEGMENT.start + i, color2);
        } else {
          this->setPixelColor(SEGMENT.stop - i, color2);
        }
      }
    }

    SEGMENT_RUNTIME.counter_mode_step = (SEGMENT_RUNTIME.counter_mode_step + 1) & 0x3;
    return (SEGMENT.speed / SEGMENT_LENGTH);
  }

 /*
  * Alternating color/white pixels running.
  */
  uint16_t mode_running_color(void) {
    return running(SEGMENT.colors[0], rgbcolor_white);
  }

  /*
  * Alternating red/blue pixels running.
  */
  uint16_t mode_running_red_blue(void) {
    return running((RgbColor) HtmlColor(RED), (RgbColor) HtmlColor(BLUE));
  }

  /*
   * Alternating red/green pixels running.
   */
  uint16_t mode_merry_christmas(void) {
    return running((RgbColor) HtmlColor(RED), (RgbColor) HtmlColor(GREEN));
  }

  /*
  * Alternating orange/purple pixels running.
  */
  uint16_t mode_halloween(void) {
    return running((RgbColor) HtmlColor(PURPLE), (RgbColor) HtmlColor(ORANGE));
  }

  /*
   * Random colored pixels running.
   */
  uint16_t mode_running_random(void) {
    for(uint16_t i=SEGMENT_LENGTH-1; i > 0; i--) {
      if(SEGMENT.reverse) {
        this->setPixelColor(SEGMENT.stop - i, _strip.GetPixelColor(SEGMENT.stop - i + 1));
      } else {
        this->setPixelColor(SEGMENT.start + i, _strip.GetPixelColor(SEGMENT.start + i - 1));
      }
    }

    if(SEGMENT_RUNTIME.counter_mode_step == 0) {
      SEGMENT_RUNTIME.aux_param = get_random_wheel_index(SEGMENT_RUNTIME.aux_param);
      if(SEGMENT.reverse) {
        this->setPixelColor(SEGMENT.stop, color_wheel(SEGMENT_RUNTIME.aux_param));
      } else {
        this->setPixelColor(SEGMENT.start, color_wheel(SEGMENT_RUNTIME.aux_param));
      }
    }

    SEGMENT_RUNTIME.counter_mode_step = (SEGMENT_RUNTIME.counter_mode_step == 0) ? 1 : 0;
    return (SEGMENT.speed / SEGMENT_LENGTH);
  }

  /*
  * K.I.T.T.
  */
  uint16_t mode_larson_scanner(void) {
    fade_out();

    if(SEGMENT_RUNTIME.counter_mode_step < SEGMENT_LENGTH) {
      if(SEGMENT.reverse) {
        this->setPixelColor(SEGMENT.stop - SEGMENT_RUNTIME.counter_mode_step, SEGMENT.colors[0]);
      } else {
        this->setPixelColor(SEGMENT.start + SEGMENT_RUNTIME.counter_mode_step, SEGMENT.colors[0]);
      }
    } else {
      if(SEGMENT.reverse) {
        this->setPixelColor(SEGMENT.stop - ((SEGMENT_LENGTH * 2) - SEGMENT_RUNTIME.counter_mode_step) + 2, SEGMENT.colors[0]);
      } else {
        this->setPixelColor(SEGMENT.start + ((SEGMENT_LENGTH * 2) - SEGMENT_RUNTIME.counter_mode_step) - 2, SEGMENT.colors[0]);
      }
    }

    SEGMENT_RUNTIME.counter_mode_step = (SEGMENT_RUNTIME.counter_mode_step + 1) % ((SEGMENT_LENGTH * 2) - 2);
    return (SEGMENT.speed / (SEGMENT_LENGTH * 2));
  }

  /*
  * Firing comets from one end.
  */
  uint16_t mode_comet(void) {
    fade_out();

    if(SEGMENT.reverse) {
      this->setPixelColor(SEGMENT.stop - SEGMENT_RUNTIME.counter_mode_step, SEGMENT.colors[0]);
    } else {
      this->setPixelColor(SEGMENT.start + SEGMENT_RUNTIME.counter_mode_step, SEGMENT.colors[0]);
    }

    SEGMENT_RUNTIME.counter_mode_step = (SEGMENT_RUNTIME.counter_mode_step + 1) % SEGMENT_LENGTH;
    return (SEGMENT.speed / SEGMENT_LENGTH);
  }

  /*
  * Fireworks function.
  */
  uint16_t fireworks(RgbColor color) {
    fade_out();

    uint32_t prevLed, thisLed, nextLed;

    for(uint16_t i=SEGMENT.start + 1; i <SEGMENT.stop; i++) {
      RgbColor rgbPrevLed = _strip.GetPixelColor(i-1);
	  RgbColor rgbThisLed = _strip.GetPixelColor(i);
	  RgbColor rgbNextLed = _strip.GetPixelColor(i+1);
	  
	  byte R = (byte)rgbPrevLed.R; byte G = (byte)rgbPrevLed.G; byte B = (byte)rgbPrevLed.B;
      unsigned long prevLedhex = ((long)R << 16L) | ((long)G << 8L) | (long)B;
	  R = (byte)rgbThisLed.R; G = (byte)rgbThisLed.G; B = (byte)rgbThisLed.B;
      unsigned long thisLedhex = ((long)R << 16L) | ((long)G << 8L) | (long)B;
	  R = (byte)rgbNextLed.R; G = (byte)rgbNextLed.G; B = (byte)rgbNextLed.B;
      unsigned long nextLedhex = ((long)R << 16L) | ((long)G << 8L) | (long)B;
	  
      prevLed = (prevLedhex >> 2) & 0x3F3F3F;
      thisLed = thisLedhex;
      nextLed = (nextLedhex >> 2) & 0x3F3F3F;
      this->setPixelColor(i, (RgbColor) HtmlColor((uint32_t) (prevLed + thisLed + nextLed)));
    }

    if(!_triggered) {
      for(uint16_t i=0; i<max(1, SEGMENT_LENGTH/20); i++) {
        if(random(10) == 0) {
		  this->setPixelColor(SEGMENT.start + random(SEGMENT_LENGTH), color);
        }
      }
    } else {
      for(uint16_t i=0; i<max(1, SEGMENT_LENGTH/10); i++) {
		this->setPixelColor(SEGMENT.start + random(SEGMENT_LENGTH), color);
      }
    }
    return (SEGMENT.speed / SEGMENT_LENGTH);
  }

  /*
  * Firework sparks.
  */
  uint16_t mode_fireworks(void) {
    RgbColor color = SEGMENT.colors[0];
    return fireworks(color);
  }

  /*
  * Random colored firework sparks.
  */
  uint16_t mode_fireworks_random(void) {
    RgbColor color = color_wheel(random(256));
    return fireworks(color);
  }

  /*
  * Fire flicker function
  */
  uint16_t fire_flicker(int rev_intensity) {
    byte lum = max(SEGMENT.colors[0].R, max(SEGMENT.colors[0].G, SEGMENT.colors[0].B)) / rev_intensity;
    for(uint16_t i=SEGMENT.start; i <= SEGMENT.stop; i++) {
      int flicker = random(0, lum);
      this->setPixelColor(i, max(SEGMENT.colors[0].R - flicker, 0), max(SEGMENT.colors[0].G - flicker, 0), max(SEGMENT.colors[0].B - flicker, 0));
    }
    return (SEGMENT.speed / SEGMENT_LENGTH);
  }

  /*
  * Random flickering.
  */
  uint16_t mode_fire_flicker(void) {
    return fire_flicker(3);
  }

  /*
  * Random flickering, less intesity.
  */
  uint16_t mode_fire_flicker_soft(void) {
    return fire_flicker(6);
  }

  /*
  * Random flickering, more intesity.
  */
  uint16_t mode_fire_flicker_intense(void) {
    return fire_flicker(1.7);
  }

  /*
  * Tricolor chase function
  */
  uint16_t tricolor_chase(RgbColor color1, RgbColor color2, RgbColor color3) {
    for(uint16_t i=0; i < SEGMENT_LENGTH; i++) {
      if((i + SEGMENT_RUNTIME.counter_mode_step) % 6 < 2) {
        if(SEGMENT.reverse) {
          this->setPixelColor(SEGMENT.start + i, color1);
        } else {
          this->setPixelColor(SEGMENT.stop - i, color1);
        }
      } else if((i + SEGMENT_RUNTIME.counter_mode_step) % 6 < 4) {
        if(SEGMENT.reverse) {
          this->setPixelColor(SEGMENT.start + i, color2);
        } else {
          this->setPixelColor(SEGMENT.stop - i, color2);
        }
      } else {
        if(SEGMENT.reverse) {
          this->setPixelColor(SEGMENT.start + i, color3);
        } else {
          this->setPixelColor(SEGMENT.stop - i, color3);
        }
      }
    }

    SEGMENT_RUNTIME.counter_mode_step = (SEGMENT_RUNTIME.counter_mode_step + 1) % 6;
    return (SEGMENT.speed / SEGMENT_LENGTH);
  }

  /*
  * Tricolor chase mode
  */
  uint16_t mode_tricolor_chase(void) {
    return tricolor_chase(SEGMENT.colors[0], SEGMENT.colors[1], SEGMENT.colors[2]);
  }

  /*
  * Alternating white/red/black pixels running.
  */
  uint16_t mode_circus_combustus(void) {
    return tricolor_chase((RgbColor) HtmlColor(RED), (RgbColor) HtmlColor(WHITE), (RgbColor) HtmlColor(BLACK));
  }

  /*
  * ICU mode
  */
  uint16_t mode_icu(void) {
    uint16_t dest = SEGMENT_RUNTIME.counter_mode_step & 0xFFFF;
 
    this->setPixelColor(SEGMENT.start + dest, SEGMENT.colors[0]);
    this->setPixelColor(SEGMENT.start + dest + SEGMENT_LENGTH/2, SEGMENT.colors[0]);

    if(SEGMENT_RUNTIME.aux_param == dest) { // pause between eye movements
      if(random(6) == 0) { // blink once in a while
        this->setPixelColor(SEGMENT.start + dest, rgbcolor_black);
        this->setPixelColor(SEGMENT.start + dest + SEGMENT_LENGTH/2, rgbcolor_black);
        return 200;
      }
      SEGMENT_RUNTIME.aux_param = random(SEGMENT_LENGTH/2);
      return 1000 + random(2000);
    }

    this->setPixelColor(SEGMENT.start + dest, rgbcolor_black);
    this->setPixelColor(SEGMENT.start + dest + SEGMENT_LENGTH/2, rgbcolor_black);

    if(SEGMENT_RUNTIME.aux_param > SEGMENT_RUNTIME.counter_mode_step) {
      SEGMENT_RUNTIME.counter_mode_step++;
      dest++;
    } else if (SEGMENT_RUNTIME.aux_param < SEGMENT_RUNTIME.counter_mode_step) {
      SEGMENT_RUNTIME.counter_mode_step--;
      dest--;
    }

    this->setPixelColor(SEGMENT.start + dest, SEGMENT.colors[0]);
    this->setPixelColor(SEGMENT.start + dest + SEGMENT_LENGTH/2, SEGMENT.colors[0]);

    return (SEGMENT.speed / SEGMENT_LENGTH);
  }
  
  /*
  * Custom mode
  */
  uint16_t (*customMode)(void) = NULL;
  uint16_t mode_custom() {
    if(customMode == NULL) {
      return 1000; // if custom mode not set, do nothing
    } else {
      return customMode();
    }
  }
  
  /*
  * Meteor Rain
  * https://www.tweaking4all.com/hardware/arduino/adruino-led-strip-effects/#LEDStripEffectMeteorRain
  */
  
  uint16_t meteorRain(uint8_t meteorTrailDecay, boolean meteorRandomDecay) {  
    uint16_t meteorSize = SEGMENT_LENGTH * 0.15;
	
	if(SEGMENT_RUNTIME.counter_mode_step == 0){
      _strip.ClearTo(rgbcolor_black);
	}
  
    if( SEGMENT_RUNTIME.counter_mode_step <= SEGMENT_LENGTH*2 ) {
      // fade brightness all LEDs one step
      for(uint16_t i=0; i <= SEGMENT_LENGTH; i++) {
        if( (!meteorRandomDecay) || (random(10)>5) ) {
          fadeToBlackVal(i, meteorTrailDecay );        
        }
      }
      // draw meteor
      for(uint16_t i = 0; i <= meteorSize; i++) {
        if( ( (SEGMENT_RUNTIME.counter_mode_step)-i <= SEGMENT_LENGTH) && ((SEGMENT_RUNTIME.counter_mode_step)-i >= 0) ) {
          if(!SEGMENT.reverse){
            this->setPixelColor(SEGMENT_RUNTIME.counter_mode_step - i, SEGMENT.colors[0]);
		  } else {
		    this->setPixelColor(SEGMENT_LENGTH - SEGMENT_RUNTIME.counter_mode_step + i, SEGMENT.colors[0]);
          }
        } 
      }
    } 

	SEGMENT_RUNTIME.counter_mode_step = (SEGMENT_RUNTIME.counter_mode_step + 1) % SEGMENT_LENGTH;
    return (SEGMENT.speed / SEGMENT_LENGTH);
  }
  
  uint16_t mode_meteor_rain(void) {
    return meteorRain(64, true);
  }
  
  //////////// End of Effects ////////////
  
  const __FlashStringHelper*
      _name[MODE_COUNT]; // SRAM footprint: 2 bytes per element

  mode_ptr
      _mode[MODE_COUNT]; // SRAM footprint: 4 bytes per element
	  
  uint8_t _segment_index = 0;
  uint8_t _num_segments = 1;
  segment _segments[MAX_NUM_SEGMENTS];
  segment_runtime _segment_runtimes[MAX_NUM_SEGMENTS];
  RgbColor rgbcolor_black =   (RgbColor) (HtmlColor(BLACK));
  RgbColor rgbcolor_white =   (RgbColor) (HtmlColor(WHITE));
  RgbColor rgbcolor_default = (RgbColor) (HtmlColor(DEFAULT_COLOR));
};
#endif