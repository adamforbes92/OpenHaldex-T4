# OpenHaldex - Teensy 4.0

An open-source Generation 1, 2 & 4 Haldex Controller which originates/is a fork from ABangingDonk's 'OpenHaldex T4'.  

### Concept
The basis of the module is to act as a middle man - read the incoming CAN frames destined for the OEM Haldex controller, and if required, adjust these messages to 'trick' the Haldex into thinking more (or less) lock is required.  

### Teensy 4.0
The Teensy 4.0 microcontroller allows for two CAN streams with the use of the 'FlexCAN_T4' library.  Future boards are looking to move to ESP32 as this allows Apple support.

### The Modes

The controller allows for 3 main modes: Stock (act as OEM), FWD, 7535 (some slippage) and a 100% lockup at the Haldex.  Both Generation 1 & Generation 2 has been tested on the bench to allow for a full understanding of what the stock CAN messages look like & therefore what messages need to be editted / created. 

The forked code has been tweaked to support the remote screen, standalone modes (so conversations/swaps into non-CANBUS) as well as Gen2 & Gen4 support.

### Uploading Code
For users wishing to customise or edit the code, it is released here for free use.  

For pre-compiled versions, navigate to the latest version and download the 'Teensy.exe' & your generation.  Connect the Haldex controller via. a data micro-USB cable (note some are ONLY power, so this needs to be checked).
Load the .hex file in Teensy.exe (File, Open) and press upload.  Some units may require the small internal white button to be pressed.

It is recommended to check back here regularly to find updates.

### The PCB & Enclosure
The Gerber files for the PCB, should anyone wish to build their own, is under the "PCB" folder.  This is the latest board.
Similarly, the enclosures are also here.
V2 enclosure continued to use the Deusche connector, which meant additional crimping & assembly.  
V3 enclosure moved to an onboard connector which results in a smaller footprint and less crimping.  

>Pinout & functionality remains the same for ALL generations of enclosure.

### Nice to Haves
The board supports Haldex output via. CAN - which allows pairing with the FIS controller to capture (and received) current and new modes.

Flashing LED if there is an issue with writing CAN messages.

Flashing LED to show installed Generation.

### Future / To Do
Incorporate 'live' switching of Generations.

## Disclaimer
It should be noted that this will modify Haldex operation and therefore can only be operated off-road and on a closed course.  

It should always be assumed that the unit may crash/hang or cause the Haldex to operate unprediably and caution should be exercised when in use.

Using this unit in any way will exert more strain on drivetrain components, and while the OEM safety features are still in place, it should be understood that having the Haldex unit locked up permanently may cause acceleated wear.

Forbes-Automotive takes no responsiblity for damages as a result of using this unit or code in any form.
