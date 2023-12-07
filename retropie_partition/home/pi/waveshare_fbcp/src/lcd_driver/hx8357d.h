#pragma once

#ifdef HX8357D

// Data specific to the HX8357D controller
#define DISPLAY_SET_CURSOR_X 0x2A
#define DISPLAY_SET_CURSOR_Y 0x2B
#define DISPLAY_WRITE_PIXELS 0x2C

void InitHX8357D(void);

void TurnDisplayOn(void);
void TurnDisplayOff(void);

#if defined (DISPLAY_WIDTH)&&defined (DISPLAY_HEIGHT)
    #define DISPLAY_NATIVE_WIDTH DISPLAY_WIDTH
    #define DISPLAY_NATIVE_HEIGHT DISPLAY_HEIGHT
#else 
    #define DISPLAY_NATIVE_WIDTH 320
    #define DISPLAY_NATIVE_HEIGHT 480
#endif




#define MUST_SEND_FULL_CURSOR_WINDOW

#define InitSPIDisplay InitHX8357D

#endif
