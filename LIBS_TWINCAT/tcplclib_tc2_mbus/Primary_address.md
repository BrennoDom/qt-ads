# Primary address

## Library
tcplclib_tc2_mbus

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_MBus](ms-xhelp:///?Id=beckhoff-18e3-4e49-a9fc-7977791d6960)
2. [M-Bus](ms-xhelp:///?Id=beckhoff-da58-4a1f-8f86-2cb29e0d2232)
3. [Bulletin](ms-xhelp:///?Id=beckhoff-867f-4d59-be31-26fe64fe0f45)
4. Primary address

# Primary address

The counters are addressed via the primary address. This can be set at the device, via manufacturer software, or with the function blocks [FB\_MBUS\_ChangeAdr()](ms-xhelp:///?Id=beckhoff-e7b9-440c-a46d-f7b90ec2b87b) and [FB\_MBUS\_General\_send()](ms-xhelp:///?Id=beckhoff-7b44-4f8f-aefc-9ad31e83ecd2).

All meters on a level converter/serial interface must have a unique address (0..250).

**Address 0-250:** Addresses of the devices

**Address 251:** not used at present

**Address 252:** not used at present

**Address 253:** Use of secondary addressing

**Address 254:** Send to all M-bus devices with response (E5 hexadecimal). If several devices are connected, all will answer. This leads to data collisions. Therefore, this address should only be used if only one device is connected.

**Address 255:** Send to all M-Bus devices without response.

[TwinCAT 3 | PLC Library: Tc2\_MBus](ms-xhelp:///?Id=beckhoff-18e3-4e49-a9fc-7977791d6960)
