# Configuration software KS2000

## Library
tcplclib_tc2_lon

## Category
Motion Control

# Configuration software KS2000

## Commissioning procedure

:   1. Install the configuration software KS2000, version 4.3.0.39 or higher.
:   2. Plug the KL6401 into your Bus Coupler, and terminate the K-Bus with a KL9010.
:   3. Log on. Should the dialog box **Create new XML Device Files** be open, cancel at this point.  
    ![27134857](/tcplclib_tc2_lon/1033/Images/png/150440971__en-US__Web.png)
:   4. The terminal can be configured under **Settings** (![42887128](/tcplclib_tc2_lon/1033/Images/png/9007199405185163__en-US__Web.png)).  
    ![50439840](/tcplclib_tc2_lon/1033/Images/png/150447371__en-US__Web.png)
:   5. Enter the SNVTs in the table (![51305376](/tcplclib_tc2_lon/1033/Images/png/9007199405191563__en-US__Web.png)).  
    Use ![59095202](/tcplclib_tc2_lon/1033/Images/png/9007199405194763__en-US__Web.png) to add a variable and ![62094776](/tcplclib_tc2_lon/1033/Images/png/9007199405197963__en-US__Web.png) to remove a selected variable.  
    The column **Id** cannot be edited. It contains the NV index. This index is also required as input variable "wNVIndex" for the [PLC function blocks](ms-xhelp:///?Id=beckhoff-605d-4d2b-8903-4c856804dca7).
:   6. Enter any text in column **Nv Name**. These descriptions are required in the LON configuration tool (not provided by Beckhoff) for identifying the respective variables.
:   7. Select the required SNVT in column **Snvt Type**.
:   8. In column **Dir** (Direction) you can specify whether the variable is sent (out) or received (in).
:   9. Enter any project name (click on **PROJECTNAME**![21982073](/tcplclib_tc2_lon/1033/Images/png/9007199405201163__en-US__Web.png)).
:   10. Edit the program ID (Prog ID ![63620936](/tcplclib_tc2_lon/1033/Images/png/9007199405204363__en-US__Web.png)). Do this by clicking Program ID, and selecting a **Program ID**. This program ID may only be issued once in your LON project. A maximum of 256 (0-255) program IDs can be used. This means that you can use 256 different configurations in one project.  
    LON terminals with the same configuration also have the same program ID.
:   11. Press the button ![35717517](/tcplclib_tc2_lon/1033/Images/png/9007199405207563__en-US__Web.png) to create the Xif file. This file is required in the LON configuration tool (not provided by Beckhoff).
:   12. Use the button ![53022201](/tcplclib_tc2_lon/1033/Images/png/9007199405210763__en-US__Web.png) to save the configuration in a BLC file. This file can be used to load the configuration if a terminal is replaced or to use the same configuration in another terminal.
:   The data can now be written to the terminal.
:   13. Use the buttons [>>>] or [<<<] to select the required slot, then use the button **WRITE** to write the data to the terminal. The slot may not be activated (green) during this process.

|  |  |
| --- | --- |
| 7437765 | The terminal is delivered with active slot 0 (factory setting). This slot contains a fixed configuration and cannot be modified. To transfer other values a different slot has to be configured and activated. Only one slot at a time is active. |

:   The project must be activated after the download has successfully been completed.
:   14. Press the button **SET ACTIVE PROJECT**.
:   15. De-energies the KL6401.

:   After switching on the KL6401 (switching the power supply on again) the desired configuration is active.

## Description of the editing functions

![66939890](/tcplclib_tc2_lon/1033/Images/png/150472971__en-US__Web.png)

![65588106](/tcplclib_tc2_lon/1033/Images/gif/150476171__en-US__Web.gif) Deletes the table

![53422044](/tcplclib_tc2_lon/1033/Images/png/9007199405220363__en-US__Web.png) Opens an existing SNVT configuration file (\*.BLC) for the KL6401

![11036355](/tcplclib_tc2_lon/1033/Images/png/9007199405210763__en-US__Web.png) Saves the current configuration as a BLC file

![32218335](/tcplclib_tc2_lon/1033/Images/png/9007199405223563__en-US__Web.png) Edits an SNVT variable

![21529561](/tcplclib_tc2_lon/1033/Images/png/9007199405194763__en-US__Web.png) Inserts an SNVT variable

![59548322](/tcplclib_tc2_lon/1033/Images/png/9007199405197963__en-US__Web.png) Deletes an SNVT variable

![66172851](/tcplclib_tc2_lon/1033/Images/png/9007199405207563__en-US__Web.png) Creates an XIF file for a LON configuration tool (not provided by Beckhoff)

![58684749](/tcplclib_tc2_lon/1033/Images/gif/150485771__en-US__Web.gif) Opens the Help

![58400697](/tcplclib_tc2_lon/1033/Images/gif/150488971__en-US__Web.gif) Info
