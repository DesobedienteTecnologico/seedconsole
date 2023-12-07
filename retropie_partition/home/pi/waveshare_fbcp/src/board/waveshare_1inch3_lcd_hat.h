#pragma once

// Data specific to WaveShare 240x240, 1.3inch IPS LCD ST7789VW hat, https://www.waveshare.com/w/upload/a/ae/ST7789_Datasheet.pdf
#if defined(WAVESHARE_1INCH3_LCD_HAT)||defined(WAVESHARE_1INCH3_LCD)||defined(WAVESHARE_1INCH54_LCD)

    #ifndef __WAVESHARE_1INCH3_LCD_HAT_H

        #define __WAVESHARE_1INCH3_LCD_HAT_H

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
            #define DISPLAY_NATIVE_HEIGHT 240
        #endif

    #endif

#endif
