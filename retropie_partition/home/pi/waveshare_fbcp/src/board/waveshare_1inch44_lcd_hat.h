#pragma once

// Data specific to WaveShare 128x128, 1.44inch LCD ST7735S hat, https://www.waveshare.com/1.44inch-lcd-hat.htm
#ifdef WAVESHARE_1INCH44_LCD_HAT

    #ifndef __WAVESHARE_1INCH44_LCD_HAT_H

        #define __WAVESHARE_1INCH44_LCD_HAT_H

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
            #define DISPLAY_NATIVE_WIDTH 130
        #endif

        #if !defined (SET_DISPLAY_HEIGHT)
            #define DISPLAY_NATIVE_HEIGHT 129
        #endif
        #define DISPLAY_NATIVE_COVERED_LEFT_SIDE 2
        #define DISPLAY_NATIVE_COVERED_TOP_SIDE 1
        #define DISPLAY_SHOULD_FLIP_ORIENTATION

    #endif
#endif
