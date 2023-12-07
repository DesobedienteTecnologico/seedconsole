#pragma once

#if defined(ST7735R) || defined(ST7735S)

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
#elif defined(WAVESHARE_0INCH96_LCD)
    #include "waveshare_0inch96_lcd.h"
#elif defined(WAVESHARE_1INCH8_LCD)
    #include "waveshare_1inch8_lcd.h"
#elif defined(WAVESHARE_1INCH44_LCD_HAT)
    #include "waveshare_1inch44_lcd_hat.h"
#elif defined(ST7735R)
    #define DISPLAY_NATIVE_WIDTH 240
    #define DISPLAY_NATIVE_HEIGHT 320
#elif defined(ST7735S)
// ST7735S displays are 128x128 pixels, but they have a somewhat odd offset that X,Y=(0,0) is not top-left corner pixel, but X,Y=(2,1) is.
// Therefore consider the display two pixels wider and one pixel higher, and add a constant offset of X=+2, Y=+1 via the DISPLAY_COVERED_* mechanism.
    #define DISPLAY_NATIVE_WIDTH 130
    #define DISPLAY_NATIVE_HEIGHT 129
    #define DISPLAY_NATIVE_COVERED_LEFT_SIDE 2
    #define DISPLAY_NATIVE_COVERED_TOP_SIDE 1
#else
#error Unknown display controller!
#endif

#if defined(WAVESHARE_1INCH44_LCD_HAT)
    #include "waveshare_1inch44_lcd_hat.h"
#elif defined(WAVESHARE_0INCH96_LCD)
    #include "waveshare_0inch96_lcd.h"
#elif defined(WAVESHARE_1INCH8_LCD)
    #include "waveshare_1inch8_lcd.h"
#endif


#define InitSPIDisplay InitST7735R

void InitST7735R(void);

void TurnDisplayOn(void);
void TurnDisplayOff(void);

#endif
