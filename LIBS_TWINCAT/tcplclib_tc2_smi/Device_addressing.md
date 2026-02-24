# Device addressing

## Library
tcplclib_tc2_smi

## Category
Motion Control

# Device addressing

SMI defines various modes of device addressing. In principle distinction can be made between individual addressing, group addressing and the collective call (broadcast). Most PLC function blocks have the *dwAddr* input and *eAddrType* for this. While the *dwAddr* input contains the necessary address details, *eAddrType* defines the mode of addressing. The individual modes of addressing are described below. Note that not every command supports all addressing modes. Details can be found in the description of the respective PLC function block.

## by the address of a device (eAddrType: = eSMIAddrTypeAddress)

Each SMI device can be assigned an address from 0 to 15. The address is stored in the SMI device and must be correctly set again when exchanging the drive. Since each address should only be assigned once, each SMI device can be addressed individually. With this mode of addressing the *dwAddr* input contains the address in the range 0 to 15. If a value outside the valid range is specified, then the respective function block outputs an [error](ms-xhelp:///?Id=beckhoff-050f-4816-bd32-717f5461c1a7).

This address is also occasionally called the slave address. The slave address must not be confused with the slave ID (see below).

## per slave ID (eAddrType := eSMIAddrTypeSlaveId)

The individual device manufacturers store a unique 32-bit number in each SMI device. This slave ID, also called the key ID, can also be used for the addressing of a device. With this mode of addressing the *dwAddr* input contains the 32-bit slave ID and the *dwAddrOption* input contains the manufacturer code (see below). This ensures that SMI devices can be addressed worldwide without them requiring an address.

With some SMI devices the slave ID is printed on the name plate or is made visible by a label on the cable.

Most read commands do not support addressing by Slave ID.

## by the manufacturer code (eAddrType := eSMIAddrTypeManufacturer)

In addition to the slave ID, SMI defines a further unique ID, the so-called [manufacturer code](ms-xhelp:///?Id=beckhoff-ace2-4a81-9027-372d4eadb3b0). The manufacturer code is permanently stored in the SMI device and cannot be changed. The possible range of values is from 0 to 15, wherein the values 0 and 14 have a special meaning. The manufacturer code 0 addresses all devices, irrespective of the manufacturer. This addressing mode can therefore also be used to dispatch broadcast commands. The value 15 is reserved for future expansions and may not be used. The English designation *manufacturer code* or the abbreviation *M-ID* is frequently found here. All devices from a manufacturer are always addressed by this addressing. With this mode of addressing the *dwAddr* input contains the manufacturer code in the range from 0 to 14. If a value outside the valid range is specified, then the respective function block outputs an [error](ms-xhelp:///?Id=beckhoff-050f-4816-bd32-717f5461c1a7).

With some SMI devices the manufacturer code is printed on the name plate or is made visible by a label on the cable.

## by group addressing (eAddrType: = eSMIAddrTypeGroup)

Each device that is to be controlled via group addressing must have an address from 0 to 15. Each bit of the *dwAddr* input corresponds to an address in the case of group addressing. If bit 0 of *dwAddr* is set, then the device with the address 0 is addressed. If bit 1 is set, then device 1 is addressed and so on. The group addressing thus occupies the bits 0 to 15, which corresponds to a range of values from 0 to 65535. If a value outside the valid range is specified, then the respective function block outputs an [error](ms-xhelp:///?Id=beckhoff-050f-4816-bd32-717f5461c1a7).

Example: The drives with the addresses 1, 4, 7 and 12 are to be addressed. The value 2#00010000\_10010010 or 16#1092 or 4242 must therefore be supplied to *dwAddr*.

## by Broadcast (eAddrType := eSMIAddrTypeBroadcast)

When addressing by broadcast all devices are always addressed, irrespective of the address set on the device. The *dwAddr* input is not required with this method of addressing and is not evaluated either. Internally the PLC function blocks use addressing by manufacturer code, wherein the manufacturer code 0 is used.
