JD40 Split
======

Supported controller (tested) Atmega32u4 chip on Elite-c board

!Do not remove TRRS/TRS cable while powered up

## Build && flashing 
```py
# Download jd40_split  
git clone https://github.com/d0rsha/jd40_split
cd jd40_split 
# Download qmk firmware 
git clone https://github.com/qmk/qmk_firmware
# Copy config && cd 
cd qmk_firmware
```
Connect left half. Edit your portmapping for the left side in `left/config.h` update the defined constants
```py
MATRIX_ROW_PINS     # 
MATRIX_COL_PINS     # 
UNUSED_PINS         #
DIODE_DIRECTION     #
SOFT_SERIAL_PIN     # Communication pin
PRODUCT             # Product ID 
```
Build && Flash the left side 
```
make handwired/jd40_split/left:d0rsha:dfu-split-left
```
Unlug left half and conntect right half. Edit your portmapping for the right side in `right/config.h` && update the above mentioned constants to match the right side. 
```
make handwired/jd40_split/right:d0rsha:dfu-split-right
```
Enjoy! 
