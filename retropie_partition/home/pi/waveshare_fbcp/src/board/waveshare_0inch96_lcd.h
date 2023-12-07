#pragma once

// Data specific to WaveShare 240x320, 2inch IPS LCD ST7789VW , https://www.waveshare.com/w/upload/a/ae/ST7789_Datasheet.pdf
#ifdef WAVESHARE_0INCH96_LCD

    #ifndef __WAVESHARE_0INCH96_LCD_H

        #define __WAVESHARE_0INCH96_LCD_H

        #if !defined(GPIO_TFT_DATA_CONTROL)
            #define GPIO_TFT_DATA_CONTROL 25
        #endif

        #if !defined(GPIO_TFT_BACKLIGHT)
            #define GPIO_TFT_BACKLIGHT 24
        #endif

        #if !defined(GPIO_TFT_RESET_PIN)
            #define GPIO_TFT_RESET_PIN 27
        #endif
        
        #define DISPLAY_NATIVE_COVERED_LEFT_SIDE 26
        #define DISPLAY_NATIVE_COVERED_TOP_SIDE 1

        #if !defined (SET_DISPLAY_WIDTH)
            #define DISPLAY_NATIVE_WIDTH (80+DISPLAY_NATIVE_COVERED_LEFT_SIDE)
        #endif

        #if !defined (SET_DISPLAY_HEIGHT)
            #define DISPLAY_NATIVE_HEIGHT (160+DISPLAY_NATIVE_COVERED_TOP_SIDE)
        #endif

    #endif

#endif
