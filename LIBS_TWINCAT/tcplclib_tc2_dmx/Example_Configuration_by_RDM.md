# Example: Configuration by RDM

## Library
tcplclib_tc2_dmx

## Category
Motion Control

# Example: Configuration by RDM

## Configuration of DMX slaves via Remote Device Management (RDM)

[Files](https://infosys.beckhoff.com/content/1033/tcplclib_tc2_dmx/Resources/zip/27021598341935115.zip) for TwinCAT 3.1.

![58082174](/tcplclib_tc2_dmx/1033/Images/gif/9007199832445835__en-US__Web.gif)

|  |  |
| --- | --- |
| 52977523 | EtherCAT functionality  The dialogue is only functioning when the ‘EtherCAT OK’ LED lights up green. A red LED indicates a fault in the EtherCAT communication. |

DMX slaves are sought on the DMX line with the '*DMX Discovery (without Addressing)*' button. All DMX slaves found are displayed in the list on the left. An entry is selected by clicking it. After confirming '*Identify*', the RDM command is sent to identify the respective DMX device. The start address can be entered in the input field adjacent to the '*Change Start Address*' button. After pressing the button, the new start address will be transmitted to the selected DMX device. The number of the DMX device, the start address in the DMX512 frame and the slot size (number of bytes in the DMX frame) for the selected device are displayed in the lower area.
