# Memory banks

## Library
tcplclib_tc3_dali

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc3\_DALI](ms-xhelp:///?Id=beckhoff-3b50-4f78-8721-86f9c15e9bec)
2. [DALI](ms-xhelp:///?Id=beckhoff-7090-4d8c-9e10-2e356c321516)
3. Memory banks

# Memory banks

Memory banks are freely accessible memory areas in which device-specific information and properties can be stored. Part of the memory banks is marked as read-only and contains further, vendor-specific information. The contents of the memory banks can be read with FB\_DALI10xReadMemoryLocation (see [FB\_DALI102ReadMemoryLocation](ms-xhelp:///?Id=beckhoff-068d-4f67-9b76-ef840e719dd1) and [FB\_DALI103ReadMemoryLocation](ms-xhelp:///?Id=beckhoff-d4cc-4dd9-8186-fb9b9e6df41d)) and, if enabled, written to with FB\_DALI10xWriteMemoryLocationNoReply (see [FB\_DALI102WriteMemoryLocationNoReply](ms-xhelp:///?Id=beckhoff-1200-4470-b7c0-b31cb2322754) and [FB\_DALI103WriteMemoryLocationNoReply](ms-xhelp:///?Id=beckhoff-9e72-4636-8693-7affde540e3b)).

Part of the memory banks can be provided with write protection.

A DALI device can support a maximum of 256 memory banks, each with up to 255 bytes, with memory banks 200 to 255 being reserved. In the current standard, memory bank 0 and a large part of memory bank 1 are predefined.

## Structure of memory bank 0:

Memory bank 0 contains information on the DALI control gear or DALI control device. It exists inside all of these devices.

| Address | Description | Default values |
| --- | --- | --- |
| 0x00 | Address of the last memory area inside the memory bank that can be accessed. | Vendor-specific |
| 0x01 | Reserved, not implemented |  |
| 0x02 | Number of the last memory bank that can be accessed. | Vendor-specific |
| 0x03 | GTIN byte0 (MSB) | Vendor-specific |
| 0x04 | GTIN byte1 | Vendor-specific |
| 0x05 | GTIN byte2 | Vendor-specific |
| 0x06 | GTIN byte3 | Vendor-specific |
| 0x07 | GTIN byte4 | Vendor-specific |
| 0x08 | GTIN byte5 (LSB) | Vendor-specific |
| 0x09 | Firmware Version (major) | Vendor-specific |
| 0x0A | Firmware Version (minor) | Vendor-specific |
| 0x0B | Identification number byte 0 (MSB) | Vendor-specific |
| 0x0C | Identification number byte 1 | Vendor-specific |
| 0x0D | Identification number byte 2 | Vendor-specific |
| 0x0E | Identification number byte 3 | Vendor-specific |
| 0x0F | Identification number byte 4 | Vendor-specific |
| 0x10 | Identification number byte 5 | Vendor-specific |
| 0x11 | Identification number byte 6 | Vendor-specific |
| 0x12 | Identification number byte 7 (LSB) | Vendor-specific |
| 0x13 | Hardware Version (major) | Vendor-specific |
| 0x14 | Hardware Version (minor) | Vendor-specific |
| 0x15 | 101 Version number of the current DALI standard | Vendor-specific |
| 0x16 | 102 Version numbers of all integrated DALI control gears | Vendor-specific |
| 0x17 | 103 Version numbers of all integrated DALI control devices | Vendor-specific |
| 0x18 | Number of logical control units in the device | Vendor-specific |
| 0x19 | Number of logical control gears in the device | Vendor-specific |
| 0x1A | Index number of this logical DALI control gear or DALI control device | Vendor-specific |
| 0x1B – 0x7F | Reserved, not implemented |  |
| 0x80 – 0xFE | Additional device information | Vendor-specific |
| 0xFF | Reserved, not implemented |  |

## Structure of memory bank 1:

Memory bank 1 can be used by the device vendor to store further information in the DALI device. If this memory bank is used, all fields up to address 0x10 are occupied as follows.

| Address | Description | Default values | Memory |
| --- | --- | --- | --- |
| 0x00 | Address of the last memory area inside the memory bank that can be accessed. | Vendor-specific  (0x10-0xFE) |  |
| 0x01 | Indicator byte | Vendor-specific |  |
| 0x02 | Lock byte for memory bank 1. Writeable bytes become changeable through the value 0x55. No other values make writing possible. | 0xFF |  |
| 0x03 | OEM GTIN byte0 (MSB) | 0xFF | Lockable by byte 0x02 |
| 0x04 | OEM GTIN byte1 | 0xFF | Lockable by byte 0x02 |
| 0x05 | OEM GTIN byte2 | 0xFF | Lockable by byte 0x02 |
| 0x06 | OEM GTIN byte3 | 0xFF | Lockable by byte 0x02 |
| 0x07 | OEM GTIN byte4 | 0xFF | Lockable by byte 0x02 |
| 0x08 | OEM GTIN byte5 (LSB) | 0xFF | Lockable by byte 0x02 |
| 0x09 | OEM Identification number byte 0 (MSB) | 0xFF | Lockable by byte 0x02 |
| 0x0A | OEM Identification number byte 1 | 0xFF | Lockable by byte 0x02 |
| 0x0B | OEM Identification number byte 2 | 0xFF | Lockable by byte 0x02 |
| 0x0C | OEM Identification number byte 3 | 0xFF | Lockable by byte 0x02 |
| 0x0D | OEM Identification number byte 4 | 0xFF | Lockable by byte 0x02 |
| 0x0E | OEM Identification number byte 5 | 0xFF | Lockable by byte 0x02 |
| 0x0F | OEM Identification number byte 6 | 0xFF | Lockable by byte 0x02 |
| 0x10 | OEM Identification number byte 7 (LSB) | 0xFF | Lockable by byte 0x02 |
| 0x11 – 0xFE | Additional device information | Vendor-specific |  |
| 0xFF | Reserved, not implemented |  |  |

## Structure of memory banks 2 to 199:

The device vendor can use memory banks 2 to 199 to supply further parameters. The structure of the memory banks is always as shown below. The vendor of the DALI device must be consulted regarding the contents and the possibility to write individual bytes.

| Address | Description | Default values | Memory |
| --- | --- | --- | --- |
| 0x00 | Address of the last memory area inside the memory bank that can be accessed. | Vendor-specific  (0x03 - 0xFE) |  |
| 0x01 | Indicator byte | Vendor-specific |  |
| 0x02 | Lock byte for the memory bank. Writeable bytes become changeable through the value 0x55. No other values make writing possible. | 0xFF |  |
| 0x03 – 0xFE | Additional device information | Vendor-specific | Vendor-specific; lockable by byte 0x02 if enabled by the vendor |
| 0xFF | Reserved, not implemented |  |  |

[TwinCAT 3 | PLC Library: Tc3\_DALI](ms-xhelp:///?Id=beckhoff-3b50-4f78-8721-86f9c15e9bec)
