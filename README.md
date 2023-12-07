<p align="center">
    <img alt="SeedConsole" src="img/sc_logo.png" width="200"/>
</p>
<h1 align="center">SeedConsole</h1>

<p align="center">
  <a href="https://opensource.org/license/gpl-3-0/" title="License: GPLv3">
    <img src="https://img.shields.io/badge/License-GPLv3-red">
  </a>
  <a href="https://twitter.com/DesobedienteTec" title="Twitter">
  <img src="https://img.shields.io/twitter/follow/DesobedienteTecnologico?style=social">
  </a>
  <a href="lnurlp:dt@getalby.com" title="Lightning">
  <img src="https://img.shields.io/badge/%E2%9A%A1-dt%40getalby.com-orange">
  </a>
  <a href="http://btcpay.desobedientetecnologico.com/" title="Bitcoin / BIP47">
  <img src="https://img.shields.io/badge/%20%F0%9F%A5%B7-btcpay.desobedientetecnologico.com-yellow?logo=bitcoin">
  </a>
  
</p>

# ℹ️ About

SeedConsole is a repository that contains all needed to get RetroPie working out of the box with the RPi HAT 240x240 display ST7789V with buttons.

SeedConsole IS NOT A FORK of RetroPie. The .img provided ONLY have included the setup configuration.


## 🔖 Configuration
1. Flash [Retropie](https://retropie.org.uk/download/) onto the MicroSD (min 4GB).
2. Copy the contents of the **retropie_partition** directory from this repository to the **retropie** partition on the MicroSD.
3. Do the same with the contents of **boot_partition** directory from this repository to the **boot** partition on the MicroSD.
4. Download ROMs (Games) and place them in **home/pi/RetroPie/roms**. Is under **retropie** partition on the MicroSD.
5. Insert the MicroSD into the Raspberry Pi and power it on. The first boot will take ~2min. Do not be desperate, just wait 😁.
6. Enjoy! 🤗 


* You have to be root to do the first step correctly. Be smart, and launch your file browser with elevated privileges using sudo just for that. :)
#### 🗂️ Sources

- https://www.waveshare.com/wiki/1.3inch_LCD_HAT
- https://github.com/adafruit/Adafruit-Retrogame
