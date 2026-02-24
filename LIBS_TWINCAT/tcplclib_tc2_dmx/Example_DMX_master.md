# Example: DMX master

## Library
tcplclib_tc2_dmx

## Category
Motion Control

# Example: DMX master

## Sending the cyclic process data as a DMX master (EL6851)

[Files](https://infosys.beckhoff.com/content/1033/tcplclib_tc2_dmx/Resources/zip/18014399039931019.zip) for TwinCAT 3.1.

**Preparation**

The application samples have been tested with a test configuration and are described accordingly. Certain deviations when setting up actual applications are possible.

The following hardware and software were used for the test configuration:

* TwinCAT master PC with Windows 7 operating system, TwinCAT version 3.1 (Build 4014.2) and TwinCAT Intel PCI Ethernet adapter (Gigabit).
* Beckhoff EtherCAT coupler EK1100, EL6851 and EL9011 terminals
* RGB-LED DMX slave with 3 channels (one for each color). One slot is occupied per channel.

**Starting the sample program**

:   1. Save the [\*.zip file](https://infosys.beckhoff.com/content/1033/tcplclib_tc2_dmx/Resources/zip/18014399039931019.zip) on your hard disk and unzip it.
:   2. Open the file *DMX\_Master.sln* with TwinCAT XAE.
:   3. Connect the hardware accordingly and connect the Ethernet adapter of your PCs to the EtherCAT coupler.
:   4. Select the local Ethernet adapter (with real-time driver, if required) under DMX\_Demo > I/O > Devices > Device 1 (EtherCAT). Then select the corresponding adapter under “Search...” in the “Adapter” tab and actuate it.
![7035667](/tcplclib_tc2_dmx/1033/Images/gif/530457355__en-US__Web.gif)
![63321005](/tcplclib_tc2_dmx/1033/Images/gif/535121419__en-US__Web.gif):   5. Activate the configuration and confirm.
![33018140](/tcplclib_tc2_dmx/1033/Images/gif/535123851__en-US__Web.gif)
![28727808](/tcplclib_tc2_dmx/1033/Images/gif/535125515__en-US__Web.gif):   6. Start TwinCAT in RUN mode.
![57223682](/tcplclib_tc2_dmx/1033/Images/gif/535127179__en-US__Web.gif):   7. Compile the project in TwinCAT XAE by selecting the command “Build DMX\_Demo” in the “Build” menu.
![45251091](/tcplclib_tc2_dmx/1033/Images/gif/535128843__en-US__Web.gif):   8. Log in and confirm loading of the program.
![4606636](/tcplclib_tc2_dmx/1033/Images/gif/535632779__en-US__Web.gif)
![41459726](/tcplclib_tc2_dmx/1033/Images/gif/535634443__en-US__Web.gif):   9. Start the program.

![37593218](/tcplclib_tc2_dmx/1033/Images/gif/535636107__en-US__Web.gif)

**Visualization**

Specification of the control values for the three colors of the DMX slave in TwinCAT XAE:

![2794650](/tcplclib_tc2_dmx/1033/Images/gif/535637771__en-US__Web.gif)

The example transmits the DMX data cyclically to a DMX slave. The DMX device used here occupies three slots (bytes) in the DMX 512 frame. Each slot addresses one of the three colors. If the “Start/Stop” button is pressed, then automatically generated data are transmitted to the DMX device. The speed of the changes can be altered using the horizontal slide control. If the “Start/Stop” button is not pressed, you can change the values manually using the three horizontal sliders.
