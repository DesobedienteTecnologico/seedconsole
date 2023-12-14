<p align="center">
    <img alt="SeedConsole" src="https://repository-images.githubusercontent.com/728836080/6b77f0be-3e4a-4767-bbf9-b94c3807ebee" width="200"/>
</p>
<h1 align="center">SeedConsole</h1>

<p align="center">
  <a href="https://opensource.org/license/gpl-3-0/" title="License: GPLv3">
    <img src="https://img.shields.io/badge/License-GPLv3-red">
  </a>
  <a href="https://nostr.com/npub1dtmp3wrkyqafghjgwyk88mxvulfncc9lg6ppv4laet5cun66jtwqqpgte6" title="Nostr">
  <img src="https://img.shields.io/badge/%E2%9C%89%EF%B8%8F-Nostr-purple">
  </a>
<a href="https://t.me/DesobedientesTecnologicos" title="Telegram">
  <img src="https://img.shields.io/badge/📨-Telegram-blue">
  </a>
  <a href="https://twitter.com/DesobedienteTec" title="Twitter">
  <img src="https://img.shields.io/twitter/url?url=https%3A%2F%2Ftwitter.com%2FDesobedienteTec&label=Follow">
  </a>
  <a href="http://btcpay.desobedientetecnologico.com/" title="Bitcoin / BIP47">
  <img src="https://img.shields.io/badge/⚡️-btcpay-yellow?logo=bitcoin">
  </a>
  
</p>

# About

SeedConsole is a repository that contains everything needed to get RetroPie working out of the box for Raspberry Pi devices equipped with an RPi HAT 240x240 display (ST7789V) along with buttons.

SeedConsole is not intended to be a fork of RetroPie. The provided .img file only includes the setup configuration available in this repository.

## You can get SeedConsole in two ways

In both cases, you need to wait about 5 minutes to get everything setup at first boot.

1. Flash the [released .img files](https://github.com/DesobedienteTecnologico/seedconsole/releases) onto the MicroSD.
3. Follow the manual installation you can find just below.


### Manual installation
1. Flash [Retropie](https://retropie.org.uk/download/) onto the MicroSD (min 4GB).
2. Copy the contents of the **retropie_partition** directory from this repository to the **retropie** partition on the MicroSD.
3. Do the same with the contents of **boot_partition** directory from this repository to the **boot** partition on the MicroSD.
4. Insert the MicroSD into the Raspberry Pi and power it on.


💡 You have to be root to do the first step correctly. Be smart, and launch your file browser with elevated privileges using sudo just for that. :)

## What is included in the released images files?
The released images files contains all the configuration available in this repository which includes [127 open source games](https://github.com/DesobedienteTecnologico/seedconsole/pull/3) .

### Add new games

This HAT has only 3 buttons on the right (A,B and Start) and 5 on the left (Up, Down, Left, Right and Select). So, it has the same configuration as the Game Boy, NES, Sega Master system, Game Gear, Atari 2600 and Atari 7800.
1. Insert the MicroSD into your computer, go unter **boot** partition and add your [ROMs/Games](https://t.me/desobedientestecnologicos/1694/1696) under **roms/** correspondingly.


### Keymap
<img alt="Keymap" src="https://github.com/DesobedienteTecnologico/seedconsole/assets/52879067/33609f8e-0f8f-4346-a667-b754f9bc034e" width="500"/>

ℹ️ Press Start + Select to navigate to the main menu.
