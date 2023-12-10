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

SeedConsole IS NOT A FORK of RetroPie. The .img provided ONLY contains the setup configuration available in this repository.

## 🪛 You can get SeedConsole in two ways

1. Flash the [released .img files](https://github.com/DesobedienteTecnologico/seedconsole/releases) onto the MicroSD
2. Follow the manual installation you can find just below

### 🔖 Manual installation
1. Flash [Retropie](https://retropie.org.uk/download/) onto the MicroSD (min 4GB).
2. Copy the contents of the **retropie_partition** directory from this repository to the **retropie** partition on the MicroSD.
3. Do the same with the contents of **boot_partition** directory from this repository to the **boot** partition on the MicroSD.
4. Insert the MicroSD into the Raspberry Pi and power it on. The first boot will take ~4min. Do not be desperate, just wait 😁.
5. Enjoy! 🤗 


💡 You have to be root to do the first step correctly. Be smart, and launch your file browser with elevated privileges using sudo just for that. :)

### 📥 Add new games
1. You have to get[ROMs/Games](https://t.me/desobedientestecnologicos/1694/1696) and place them in **/home/pi/RetroPie/roms**. Is under **retropie** partition on the MicroSD.

### ⚠️ Windows & MacOS users
The Retropie partition on the MicroSD card uses the ext4 filesystem, which is not readable by default as the boot partition type (fat32).
To mount that partition and be able to place games into it actually you have to install this software:

- Windows users:
    - [ext2fsd](https://sourceforge.net/projects/ext2fsd/)

- MacOS users:
    - [extFS](https://www.paragon-software.com/home/extfs-mac) 

---

#### 🗂️ Sources

- https://www.waveshare.com/wiki/1.3inch_LCD_HAT
- https://github.com/adafruit/Adafruit-Retrogame
- https://retropie.org.uk/download/

---

[📨 Telegram Group](https://t.me/DesobedientesTecnologicos)
