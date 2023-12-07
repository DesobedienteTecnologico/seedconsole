# Introduction
This repository forked from  [juj/fbcp-ili9341](https://github.com/juj/fbcp-ili9341)

This repository implements a driver for certain SPI-based LCD displays for Raspberry Pi A, B, 2, 3, 4 and Zero.

## What I do
1. sorted out the folders (At least it looks better)
2. add the ability to change screen size to fit more screens(Each controller may have different displays)
3. added most of the WaveShare LCD Hat support
## Tested Devices
The driver has been checked to work (at least some point in the past) on the following systems:
* Raspberry Pi 4 Model B with Raspbian Stretch (GCC 8.3.0)
* Raspberry Pi 3 Model B+ with Raspbian Stretch (GCC 6.3.0)
* Raspberry Pi 3 Model B Rev 1.2 with Raspbian Jessie (GCC 4.9.2) and Raspbian Stretch (GCC 6.3.0)
* Raspberry Pi Zero W with Raspbian Jessie (GCC 4.9.2) and Raspbian Stretch (GCC 6.3.0)
* Raspberry Pi 2 Model B
* Raspberry Pi B Rev. 2.0 (old board from Q4 2012, board revision ID 000e)

although not all boards are actively tested on, so ymmv especially on older boards. (Bug fixes welcome, use [https://elinux.org/RPi_HardwareHistory](https://elinux.org/RPi_HardwareHistory) to identify which board you are running on)

## Tested Displays
* [WAVESHARE_0INCH96_LCD](https://www.waveshare.net/shop/0.96inch-LCD-Module.htm)with ST7735 controller
* [WAVESHARE_1INCH44_LCD_HAT](https://www.waveshare.net/shop/1.44inch-LCD-HAT.htm)with ST7735 controller
* [WAVESHARE_1INCH8_LCD](https://www.waveshare.net/shop/1.8inch-LCD-Module.htm)with ST7735 controller
* [WAVESHARE_1INCH14_LCD](https://www.waveshare.net/shop/1.14inch-LCD-Module.htm)with ST7789VM controller
* [WAVESHARE_1INCH3_LCD](https://www.waveshare.net/shop/1.3inch-LCD-Module.htm)with ST7789VM controller
* [WAVESHARE_1INCH3_LCD_HAT](https://www.waveshare.net/shop/1.3inch-LCD-HAT.htm)with ST7789VM controller
* [WAVESHARE_1INCH54_LCD](https://www.waveshare.net/shop/1.54inch-LCD-Module.htm)with ST7789VM controller
* [WAVESHARE_2INCH_LCD](https://www.waveshare.net/shop/2inch-LCD-Module.htm)with ST7789VM controller
* [WAVESHARE_2INCH4_LCD](https://www.waveshare.net/shop/2.4inch-LCD-Module.htm)with IL9341 controller

## How to use
### Installation
Check the following sections to set up the driver.
#### Boot configuratio
This driver does not utilize the [notro/fbtft](https://github.com/notro/fbtft) framebuffer driver, so that needs to be disabled if active. That is, if your `/boot/config.txt` file has lines that look something like `dtoverlay=pitft28r, ...`, `dtoverlay=waveshare32b, ...` or `dtoverlay=flexfb, ...`, those should be removed.

This program neither utilizes the default SPI driver, so a line such as `dtparam=spi=on` in `/boot/config.txt` should also be removed so that it will not cause conflicts.

Likewise, if you have any touch controller related dtoverlays active, such as `dtoverlay=ads7846,...` or anything that has a `penirq=` directive, those should be removed as well to avoid conflicts. It would be possible to add touch support to fbcp-ili9341 if someone wants to take a stab at it.


#### Building and running
Run in the console of your Raspberry Pi:
```
cd ~
sudo apt-get install cmake -y
git clone https://github.com/EngineerWill/waveshare_fbcp.git
cd waveshare_fbcp
mkdir build
cd build 
cmake [options] ..
make -j
sudo ./fbcp
```
If you are in China, you can use the following command
```
cd ~
sudo apt-get install cmake -y
sudo apt-get install p7zip-full -y
wget https://www.waveshare.net/w/upload/f/f9/Waveshare_fbcp.7z
7z x Waveshare_fbcp.7z
cd waveshare_fbcp
mkdir build
cd build
cmake [options] ..
make -j
sudo ./fbcp
```
Note especially the two dots `..` on the CMake line, which denote "up one directory" in this case (instead of referring to "more items go here").

See the next section to see what to input under **[options]**.

If you have been running existing `fbcp` driver, make sure to remove that e.g. via a `sudo pkill fbcp` first (while running in SSH prompt or connected to a HDMI display), these two cannot run at the same time. If `/etc/rc.local` or `/etc/init.d` contains an entry to start up `fbcp` at boot, that directive should be deleted.

##### Configuring build options
If you are using the LCD module of WaveShare, you can use the following commands(I have adapted it for you)
```
#ST7735
cmake -DSPI_BUS_CLOCK_DIVISOR=20 -DWAVESHARE_0INCH96_LCD=ON -DBACKLIGHT_CONTROL=ON -DSTATISTICS=0 ..
cmake -DSPI_BUS_CLOCK_DIVISOR=20 -DWAVESHARE_1INCH44_LCD_HAT=ON -DBACKLIGHT_CONTROL=ON -DSTATISTICS=0 ..
cmake -DSPI_BUS_CLOCK_DIVISOR=20 -DWAVESHARE_1INCH8_LCD=ON -DBACKLIGHT_CONTROL=ON -DSTATISTICS=0 ..
#ST7789
cmake -DSPI_BUS_CLOCK_DIVISOR=20 -DWAVESHARE_1INCH14_LCD=ON -DBACKLIGHT_CONTROL=ON -DSTATISTICS=0 ..
cmake -DSPI_BUS_CLOCK_DIVISOR=20 -DWAVESHARE_1INCH3_LCD=ON -DBACKLIGHT_CONTROL=ON -DSTATISTICS=0 ..
cmake -DSPI_BUS_CLOCK_DIVISOR=20 -DWAVESHARE_1INCH3_LCD_HAT=ON -DBACKLIGHT_CONTROL=ON -DSTATISTICS=0 ..
cmake -DSPI_BUS_CLOCK_DIVISOR=20 -DWAVESHARE_1INCH54_LCD=ON -DBACKLIGHT_CONTROL=ON -DSTATISTICS=0 ..
cmake -DSPI_BUS_CLOCK_DIVISOR=20 -DWAVESHARE_2INCH_LCD=ON -DBACKLIGHT_CONTROL=ON -DSTATISTICS=0 ..
#IL9341
cmake -DSPI_BUS_CLOCK_DIVISOR=20 -DWAVESHARE_2INCH4_LCD=ON -DBACKLIGHT_CONTROL=ON -DSTATISTICS=0 ..
```
Other**[options]** You can check out [juj/fbcp-ili9341](https://github.com/juj/fbcp-ili9341) for help.
### License

This driver is licensed under the MIT License. See LICENSE.txt. In nonlegal terms, it's yours for both free and commercial projects, DIY packages, kickstarters, Etsys and Ebays, and you don't owe back a dime. Feel free to apply and derive as you wish.

If you found waveshare-fbcp useful, it makes me happy to hear back about the projects it found a home in. If you did a build or a project where waveshare-fbcp worked out, it'd be great to see a video or some photos or read about your experiences.

I hope you build something you enjoy!

