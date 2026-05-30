# µAffirmations
A microcontroller-based affection-giving MACHINE!

> [!IMPORTANT]
> This project is currently a work-in-progress, there __will__ be things that don't work, please bear with me will I work out the kinks!

# Table of Contents
- [Usage Guide](#usage-guide)
  - [Hardware](#hardware)
  - [Firmware](#firmware)
- [Project Updates](#project-updates)
- [Copyright and Licensing](#copyright-and-licensing)
- [Contact](#contact)

# Usage Guide
## Hardware
The PCB files can be found [here](/hw/pcb/RevB.zip), be sure of order a solder stencil too(ideally with a stencil unless you love hand-soldering 200+ SMD connections). The [BOM](/hw/pcb/micro-affirmations_BOM.csv) will provide you with a list of parts required. Due to the limited size on the PCB, many of the reference designators have been removed to save space. Because of this, you will likely need to have KiCAD running as you are placing components.

## Firmware
You will need access to an ST-Link programming device and have Platform IO installed via VS code. Once you're ready, upload the code by:
- Cloning the repository
- Open in VS code
- Connect the ST-Link programmer to your computer
- Connect the µAffirmations' programming port to the ST-Link programmer
- Ensure the µAffirmations board is powered
- Open the STM32 for VS Code extention
- Click __Upload__

<!--
### Message customisation
This device allows the user to create their own custom messages to be displayed on the LED matrix, to provide your messages, modify the following code found in [this](/path/to/file.c) file.

For axample:
```c
uint8_t someVar = 0;
```
-->

# Project Updates
## Hardware [RevB](https://github.com/i-Saac-IV/micro-affirmations/tree/v0.9.1)
After hardware tesing the following fixes have been made to the hardware design:
- Supercapcitor charging circuit, now uses a dedecated IC
- LED matrix layout, the LED spacing has been decreased
- LED brightness was assessed and appropriate resistor have been selected
- The overall PCB dimentions have shrunk to 70x40mm

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