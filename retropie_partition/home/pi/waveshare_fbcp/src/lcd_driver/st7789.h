#pragma once

#if defined(ST7789) || defined(ST7789VW) 

// On Arduino "A000096" 160x128 ST7735R LCD Screen, the following speed configurations have been tested (on a Pi 3B):
// core_freq=355: CDIV=6, results in 59.167MHz, works
// core_freq=360: CDIV=6, would result in 60.00MHz, this would work for several minutes, but then the display would turn all white at random

// On WaveShare 1.54" 240x240 Wide Angle TFT LCD Display with MicroSD ST7789 screen, the following speed configurations have been tested (on a Pi 3B):
// core_freq=340: CDIV=4, results in 85.00MHz, works
// core_freq=350: CDIV=4, would result in 87.50MHz, which would work for a while, but generate random single pixel glitches every once in a few minutes

// Data specific to the ILI9341 controller
#define DISPLAY_SET_CURSOR_X 0x2A
#define DISPLAY_SET_CURSOR_Y 0x2B
#define DISPLAY_WRITE_PIXELS 0x2C



#if defined (SET_DISPLAY_WIDTH)&&defined (SET_DISPLAY_HEIGHT)
    #if !(defined(DISPLAY_NATIVE_WIDTH)|defined(DISPLAY_NATIVE_HEIGHT))
        #define DISPLAY_NATIVE_WIDTH SET_DISPLAY_WIDTH
        #define DISPLAY_NATIVE_HEIGHT SET_DISPLAY_HEIGHT
    #endif
#elif defined(WAVESHARE_1INCH3_LCD_HAT)||defined(WAVESHARE_1INCH3_LCD)||defined(WAVESHARE_1INCH54_LCD)
    #include "waveshare_1inch3_lcd_hat.h"
#elif defined(WAVESHARE_1INCH14_LCD)
    #include "waveshare_1inch14_lcd.h"
#elif defined(WAVESHARE_2INCH_LCD)
    #include "waveshare_2inch_lcd.h"
#elif defined(ST7789) || defined(ST7789VW)
    #if !(defined(DISPLAY_NATIVE_WIDTH)|defined(DISPLAY_NATIVE_HEIGHT))
    #define DISPLAY_NATIVE_WIDTH 240
    #define DISPLAY_NATIVE_HEIGHT 240
    #endif
#else
    #error Unknown display controller!
#endif

#if defined(WAVESHARE_1INCH3_LCD_HAT)||defined(WAVESHARE_1INCH3_LCD)||defined(WAVESHARE_1INCH54_LCD)
    #include "waveshare_1inch3_lcd_hat.h"
#elif defined(WAVESHARE_1INCH14_LCD)
    #include "waveshare_1inch14_lcd.h"
#elif defined(WAVESHARE_2INCH_LCD)
    #include "waveshare_2inch_lcd.h"
#endif





#define InitSPIDisplay InitST7789

void InitST7789(void);

void TurnDisplayOn(void);
void TurnDisplayOff(void);

#if defined(ST7789) || defined(ST7789VW)
// Unlike all other displays developed so far, WaveShare 1.54" 240x240 ST7789 display
// actually needs to observe the CS line toggle during execution, it cannot just be always activated.
// (ST7735R does not care about this)
// TODO: It is actually untested if ST7789VW really needs this, but does work with it, so kept for now
#define DISPLAY_NEEDS_CHIP_SELECT_SIGNAL
#endif

#endif
