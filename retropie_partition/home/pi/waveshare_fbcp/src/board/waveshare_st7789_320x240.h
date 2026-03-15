#pragma once

// Data specific to a 320x240 landscape ST7789/ST7789VW display.
// The ST7789 controller has 240 columns x 320 rows of graphics RAM.
// This board config represents the display in its portrait form (240x320)
// so that the landscape orientation flip mechanism produces 320x240 output.
#ifdef WAVESHARE_ST7789_320X240

    #ifndef __WAVESHARE_ST7789_320X240_H

        #define __WAVESHARE_ST7789_320X240_H

        #if !defined(GPIO_TFT_DATA_CONTROL)
            #define GPIO_TFT_DATA_CONTROL 25
        #endif

        #if !defined(GPIO_TFT_BACKLIGHT)
            #define GPIO_TFT_BACKLIGHT 24
        #endif

        #if !defined(GPIO_TFT_RESET_PIN)
            #define GPIO_TFT_RESET_PIN 27
        #endif

        // Define native dimensions in portrait form; the landscape flip in
        // display.h will swap them to produce DISPLAY_WIDTH=320, DISPLAY_HEIGHT=240.
        #if !defined(SET_DISPLAY_WIDTH)
            #define DISPLAY_NATIVE_WIDTH 240
        #endif

        #if !defined(SET_DISPLAY_HEIGHT)
            #define DISPLAY_NATIVE_HEIGHT 320
        #endif

    #endif

#endif
