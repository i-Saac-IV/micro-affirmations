# µAffirmations
A microcontroller-based affection-giving MACHINE!

> [!IMPORTANT]
> This project is currently a work-in-progress, there __will__ be things that don't work, please bear with me will I work out the kinks!

# Table of Contents
- [Usage Guide](#usage-guide)
  - [Hardware](#hardware)
  - [Firmware](#firmware)
- [Photos](#photos)
- [Project Updates](#project-updates)
- [Copyright and Licensing](#copyright-and-licensing)
- [Contact](#contact)

# Usage Guide
## Hardware
The PCB files can be found [here](/hw/pcb/micro-affirmations.zip), be sure of order a solder stencil too(ideally with a stencil unless you love hand-soldering 200+ SMD connections). The [BOM](/hw/pcb/micro-affirmations_BOM.csv) will provide you with a list of parts required. Due to the limited size on the PCB, many of the reference designators have been removed to save space. Because of this, you will likely need to have KiCAD running as you are placing components. Or you can guess I suppose...

## Firmware
You will need access to an ST-Link programming device and have [stm32-for-vscode](https://open-vsx.org/extension/bmd/stm32-for-vscode) extension installed. Once you're ready, upload the code by:
- Cloning the repository
- Open in VS code
- Connect the ST-Link programmer to your computer
- Connect the µAffirmations' programming port to the ST-Link programmer
- Ensure the µAffirmations board is powered
- Open the STM32 for VS Code extention
- Click __Flash STM32__

### Message customisation
This device allows the user to create their own custom messages to be displayed on the LED matrix, to provide your messages, modify the following code found in [this](/Core/Src/messages.c) file.

For axample:
```c
__weak const char *messages[] = {
    "This is the first custom message!",
    "Below is a list of supported characters...",
    "!\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~"
};
```

# Photos
<table align="center">
  <tr>
    <td align="center">
      <img src=".//media/DSC01157.JPG" height="400"><br>
      <b>Programming port broken in RevB of the PCB</b>
    </td>
  </tr>
</table>

# Project Updates
## Hardware [RevD](https://github.com/i-Saac-IV/micro-affirmations/tree/v0.9.3)
After considerable development to the code, I found out that I had not connected the supercapacitor voltage sensing circuit to a ADC capable pin, this has been corrected.

## Hardware [RevC](https://github.com/i-Saac-IV/micro-affirmations/tree/v0.9.2)
After futher testing the following fixes to the hardware design have been made:
- The programming port has been connected to the correct pins on the mircocontroller
- The layout of the components has been adjusted for easier access to the push button
- The supercapacitor management circuit has been de-routed as per the spec sheet
- I added a QR to the PCB, because I could...

## Hardware [RevB](https://github.com/i-Saac-IV/micro-affirmations/tree/v0.9.1)
After hardware tesing the following fixes have been made to the hardware design:
- Supercapacitor charging circuit, now uses a dedecated IC
- LED matrix layout, the LED spacing has been decreased
- LED brightness was assessed and appropriate resistor have been selected
- The overall PCB dimentions have shrunk to 70x40mm
<table align="center">
  <tr>
    <td align="center">
      <img src=".//media/DSC01105.JPG" height="400"><br>
      <b>RevB PCB</b>
    </td>
  </tr>
</table>

## Hardware [RevA](https://github.com/i-Saac-IV/micro-affirmations/tree/v0.9.0)
Initial hardware design.

# Copyright and Licensing
See [licence](LICENSE) for in depth info.
<!--
This project uses the following third-party libraries:

- Lib ( License)

Copyright and license terms belong to their respective authors.

Contact me if anything here is incorrect.
-->

# Contact
If you'd like to get in touch, feel free to reach out!
<p>
  <a href="https://github.com/i-Saac-IV">
    <img src="https://img.shields.io/badge/GitHub-181717?style=for-the-badge&logo=github&logoColor=white"/>
  </a>
  <a href="https://www.linkedin.com/in/isaac-pawley/">
    <img src="https://img.shields.io/badge/LinkedIn-0A66C2?style=for-the-badge&logo=linkedin&logoColor=white"/>
  </a>
  <a href="https://www.instagram.com/i.saac.0100/">
    <img src="https://img.shields.io/badge/Instagram-E4405F?style=for-the-badge&logo=instagram&logoColor=white"/>
  </a>
</p>