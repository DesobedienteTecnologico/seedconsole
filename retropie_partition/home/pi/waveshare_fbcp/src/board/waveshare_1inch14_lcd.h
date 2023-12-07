#pragma once

// Data specific to WaveShare 240x240, 1.3inch IPS LCD ST7789VW hat, https://www.waveshare.com/w/upload/a/ae/ST7789_Datasheet.pdf
#if defined(WAVESHARE_1INCH14_LCD)

    #ifndef __WAVESHARE_1INCH14_LCD_H

        #define __WAVESHARE_1INCH14_LCD_H

        #if !defined(GPIO_TFT_DATA_CONTROL)
            #define GPIO_TFT_DATA_CONTROL 25
        #endif

        #if !defined(GPIO_TFT_BACKLIGHT)
            #define GPIO_TFT_BACKLIGHT 24
        #endif

        #if !defined(GPIO_TFT_RESET_PIN)
            #define GPIO_TFT_RESET_PIN 27
        #endif
        
        #define DISPLAY_NATIVE_COVERED_LEFT_SIDE 40
        #define DISPLAY_NATIVE_COVERED_TOP_SIDE 53
        
        #if !defined (SET_DISPLAY_WIDTH)
            #define DISPLAY_NATIVE_WIDTH (240+DISPLAY_NATIVE_COVERED_LEFT_SIDE)
        #endif

        #if !defined (SET_DISPLAY_HEIGHT)
            #define DISPLAY_NATIVE_HEIGHT (135+DISPLAY_NATIVE_COVERED_TOP_SIDE)
            
        #endif

    #endif

#endif
