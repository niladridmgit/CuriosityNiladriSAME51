If you are looking for Low cost Evaluation Kit with CAN FD support then you might go for SAM E51 Curiosity Nano Evaluation Kit which is 
one of the low cost 15$ Evaluation Kit with ARM Cortex-M4F CPU running at up to **120 MHz**. It has 2 **CAN FD** and **1024KB** program memory

Link of the product : https://www.microchip.com/Developmenttools/ProductDetails/EV76S68A

![alt text](https://www.microchip.com/_ImagedCopy/200511-MCU32-PHOTO-EV76S68A_SAM-E51-Curiosity-Nano-Front-Transparent.png)

This Arduino Board package you can use to develop your appication using Arduino IDE.
This package support most of the perpherals of SAME51J20A microcontroller which you may required for your project.
How to install this board package in your Arduino IDE? No worry, below you can found step by step guidence.

**1. Install "curiosniladri" board package:**
add below link to Arduino IDE (1.8.x) -> Preferences -> Additional Boards Mangers URLs

" **https://raw.githubusercontent.com/niladridmgit/CuriosityNiladriSAME51/master/package_curiosityniladri_same_index.json** "

![alt text](https://raw.githubusercontent.com/niladridmgit/curiosityniladri/master/images/arduino_ide_preferences.JPG)
   
![alt text](https://raw.githubusercontent.com/niladridmgit/curiosityniladri/master/images/package_link.JPG)

**2. Search "curiosniladri" in Boards Manager**

Install latest package

![alt text](https://raw.githubusercontent.com/niladridmgit/curiosityniladri/master/images/BoardsManager.JPG)


**3. Select proper board file chip number**
select chip no **SAME51J20A**

![alt text](https://raw.githubusercontent.com/niladridmgit/curiosityniladri/master/images/boards_selection.png)

**4. Write Hello world and blink LED0**

![alt text](https://raw.githubusercontent.com/niladridmgit/curiosityniladri/master/images/HelloWorld.JPG)

**5. Flash the binary using Microchip Studio**

![alt text](https://raw.githubusercontent.com/niladridmgit/curiosityniladri/master/images/programming.JPG)
