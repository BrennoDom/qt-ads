# Example: Configuration of SMI devices

## Library
tcplclib_tc2_smi

## Category
Motion Control

# Example: Configuration of SMI devices

TwinCAT 3 project: [Tc2\_SMI\_Commissioning.zip](https://infosys.beckhoff.com/content/1033/tcplclib_tc2_smi/Resources/zip/27021598453157387.zip)

With the example it is possible to address SMI devices or to expand an existing installation. Moreover the dialogs for diagnostics and error analysis can be used. A total of 5 dialogs are available.

## Start

![40663130](/tcplclib_tc2_smi/1033/Images/gif/73713163__en-US__Web.gif)

Under *SMI\_Start* is the main menu, via which the four submenus can be accessed.

## Control

![30423852](/tcplclib_tc2_smi/1033/Images/gif/73715595__en-US__Web.gif)

On pressing the *StartScanning* button, a search is made for addressed SMI devices on the SMI line. All SMI devices found are displayed in the list on the left by the [manufacturer code](ms-xhelp:///?Id=beckhoff-ace2-4a81-9027-372d4eadb3b0) and the slave ID. An entry is selected by clicking it. The other buttons are always related to the selected entry. This allows all important SMI commands to be sent to every addressed SMI device. If an error is detected with an SMI command, this is indicated in the bottom right-hand corner by the [error code](ms-xhelp:///?Id=beckhoff-050f-4816-bd32-717f5461c1a7).

## Addressing

![5379216](/tcplclib_tc2_smi/1033/Images/gif/73718027__en-US__Web.gif)

Each SMI device can be assigned an address from 0 to 15. Each SMI device can be addressed via this address. Although there are other methods of addressing SMI devices (see [here](ms-xhelp:///?Id=beckhoff-137b-434b-94e3-430add645078)), a unique address is necessary for group addressing. Therefore it is advisable to assign an address to each SMI device. The *Start Scanning* button is used to search for all addressed SMI devices. If an address is to be changed, then the corresponding SMI device must be selected in the list. The desired address can be entered in the input box on the right next to the *Change Address* button and accepted by actuating the button.

If SMI devices do not have an address yet, all SMI devices are assigned an address by pressing the *Start Addressing* button. The user has no influence over which address is assigned to which SMI device. The addresses are assigned in descending order, starting with the address specified by the *HighestAddress* parameter. The *Current Manufacturer Id*, *Current Address* and *Current Search Slave-Id* fields provide information about the status of the addressing. The addressing can be prematurely cancelled by pressing *Cancel Addressing*.

## Library Status

![48412952](/tcplclib_tc2_smi/1033/Images/gif/73720459__en-US__Web.gif)

Communication between the individual PLC blocks and the Bus Terminal takes place within the PLC library via three central buffers (for each SMI terminal). The extent of utilisation of the buffers and possible overflows can be determined from the illustrated table.

## Terminal Status

![33063388](/tcplclib_tc2_smi/1033/Images/gif/73722891__en-US__Web.gif)

The status information from the process image of the terminal is displayed in this dialogue. In addition, messages requiring acknowledgement can be reset in this dialogue.
