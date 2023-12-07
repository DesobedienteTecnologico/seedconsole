#pragma once

// Data specific to WaveShare 240x320, 2inch IPS LCD ST7789VW , https://www.waveshare.com/w/upload/a/ae/ST7789_Datasheet.pdf
#ifdef WAVESHARE_2INCH4_LCD

    #ifndef __WAVESHARE_2INCH4_LCD_H

        #define __WAVESHARE_2INCH4_LCD_H

        #if !defined(GPIO_TFT_DATA_CONTROL)
            #define GPIO_TFT_DATA_CONTROL 25
        #endif

        #if !defined(GPIO_TFT_BACKLIGHT)
            #define GPIO_TFT_BACKLIGHT 24
        #endif

        #if !defined(GPIO_TFT_RESET_PIN)
            #define GPIO_TFT_RESET_PIN 27
        #endif
        
        #if !defined (SET_DISPLAY_WIDTH)
            #define DISPLAY_NATIVE_WIDTH 240
        #endif

        #if !defined (SET_DISPLAY_HEIGHT)
            #define DISPLAY_NATIVE_HEIGHT 320
        #endif

    #endif

#endif
