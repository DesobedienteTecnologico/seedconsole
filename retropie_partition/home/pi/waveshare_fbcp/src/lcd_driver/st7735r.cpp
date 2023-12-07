#include "config.h"

#if defined(ST7735R) || defined(ST7735S) 

#include "spi.h"

#include <memory.h>
#include <stdio.h>

void InitST7735R()
{
  // If a Reset pin is defined, toggle it briefly high->low->high to enable the device. Some devices do not have a reset pin, in which case compile with GPIO_TFT_RESET_PIN left undefined.
#if defined(GPIO_TFT_RESET_PIN) && GPIO_TFT_RESET_PIN >= 0
  printf("Resetting display at reset GPIO pin %d\n", GPIO_TFT_RESET_PIN);
  SET_GPIO_MODE(GPIO_TFT_RESET_PIN, 1);
  SET_GPIO(GPIO_TFT_RESET_PIN);
  usleep(120 * 1000);
  CLEAR_GPIO(GPIO_TFT_RESET_PIN);
  usleep(120 * 1000);
  SET_GPIO(GPIO_TFT_RESET_PIN);
  usleep(120 * 1000);
#endif

  // Do the initialization with a very low SPI bus speed, so that it will succeed even if the bus speed chosen by the user is too high.
  spi->clk = 34;
  __sync_synchronize();

  BEGIN_SPI_COMMUNICATION();
  {

    usleep(120*1000);
    SPI_TRANSFER(0x11/*Sleep Out*/);
    usleep(120 * 1000);

    SPI_TRANSFER(0x3A/*COLMOD: Pixel Format Set*/, 0x05/*16bpp*/);
    usleep(20 * 1000);

#define MADCTL_BGR_PIXEL_ORDER (1<<3)
#define MADCTL_ROW_COLUMN_EXCHANGE (1<<5)
#define MADCTL_COLUMN_ADDRESS_ORDER_SWAP (1<<6)
#define MADCTL_ROW_ADDRESS_ORDER_SWAP (1<<7)
#define MADCTL_ROTATE_180_DEGREES (MADCTL_COLUMN_ADDRESS_ORDER_SWAP | MADCTL_ROW_ADDRESS_ORDER_SWAP)
#define MADCTL_ROTATE_90_DEGREES ()
    uint8_t madctl = 0;
#if defined(ST7735R) || defined(ST7735S)
    madctl |= MADCTL_BGR_PIXEL_ORDER;
#endif
#ifdef DISPLAY_SWAP_BGR
    madctl ^= MADCTL_BGR_PIXEL_ORDER;
#endif

#if defined(WAVESHARE_1INCH8_LCD)
    madctl ^= MADCTL_BGR_PIXEL_ORDER;
#endif

#if defined(DISPLAY_FLIP_ORIENTATION_IN_HARDWARE)
    madctl |= MADCTL_ROW_COLUMN_EXCHANGE;
#endif

    madctl |= MADCTL_ROW_ADDRESS_ORDER_SWAP;

#if defined(WAVESHARE_1INCH44_LCD_HAT)
    madctl ^= MADCTL_ROTATE_180_DEGREES;
#endif

#ifdef DISPLAY_ROTATE_180_DEGREES
    madctl ^= MADCTL_ROTATE_180_DEGREES;
#endif

    SPI_TRANSFER(0x36/*MADCTL: Memory Access Control*/, madctl);
    usleep(10*1000);

    bool invertColors = false;

#ifdef DISPLAY_INVERT_COLORS
    invertColors = !invertColors;
#endif
#if defined(WAVESHARE_0INCH96_LCD)
    invertColors = !invertColors;
#endif

    if (invertColors)
      SPI_TRANSFER(0x21/*Display Inversion On*/);
    else
      SPI_TRANSFER(0x20/*Display Inversion Off*/);

    SPI_TRANSFER(0x13/*NORON: Partial off (normal)*/);
    usleep(10*1000);

    SPI_TRANSFER(/*Display ON*/0x29);
    usleep(100 * 1000);


#if defined(GPIO_TFT_BACKLIGHT) && defined(BACKLIGHT_CONTROL)
    printf("Setting TFT backlight on at pin %d\n", GPIO_TFT_BACKLIGHT);
    SET_GPIO_MODE(GPIO_TFT_BACKLIGHT, 0x01); // Set backlight pin to digital 0/1 output mode (0x01) in case it had been PWM controlled
    SET_GPIO(GPIO_TFT_BACKLIGHT); // And turn the backlight on.
#endif

    ClearScreen();
  }
#ifndef USE_DMA_TRANSFERS // For DMA transfers, keep SPI CS & TA active.
  END_SPI_COMMUNICATION();
#endif

  // And speed up to the desired operation speed finally after init is done.
  usleep(10 * 1000); // Delay a bit before restoring CLK, or otherwise this has been observed to cause the display not init if done back to back after the clear operation above.
  spi->clk = SPI_BUS_CLOCK_DIVISOR;
}

void TurnDisplayOff()
{
#if defined(GPIO_TFT_BACKLIGHT) && defined(BACKLIGHT_CONTROL)
  SET_GPIO_MODE(GPIO_TFT_BACKLIGHT, 0x01); // Set backlight pin to digital 0/1 output mode (0x01) in case it had been PWM controlled
  CLEAR_GPIO(GPIO_TFT_BACKLIGHT); // And turn the backlight off.
#endif
#if 0
  QUEUE_SPI_TRANSFER(0x28/*Display OFF*/);
  QUEUE_SPI_TRANSFER(0x10/*Enter Sleep Mode*/);
  usleep(120*1000); // Sleep off can be sent 120msecs after entering sleep mode the earliest, so synchronously sleep here for that duration to be safe.
#endif
//  printf("Turned display OFF\n");
}

void TurnDisplayOn()
{
#if 0
  QUEUE_SPI_TRANSFER(0x11/*Sleep Out*/);
  usleep(120 * 1000);
  QUEUE_SPI_TRANSFER(0x29/*Display ON*/);
#endif
#if defined(GPIO_TFT_BACKLIGHT) && defined(BACKLIGHT_CONTROL)
  SET_GPIO_MODE(GPIO_TFT_BACKLIGHT, 0x01); // Set backlight pin to digital 0/1 output mode (0x01) in case it had been PWM controlled
  SET_GPIO(GPIO_TFT_BACKLIGHT); // And turn the backlight on.
#endif
//  printf("Turned display ON\n");
}

void DeinitSPIDisplay()
{
  ClearScreen();
}

#endif
