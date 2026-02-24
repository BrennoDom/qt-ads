# Relay overview

## Library
tcplclib_tc2_mbus

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_MBus](ms-xhelp:///?Id=beckhoff-18e3-4e49-a9fc-7977791d6960)
2. [Programming](ms-xhelp:///?Id=beckhoff-3a96-436d-9f67-e2d673372cb2)
3. [POUs](ms-xhelp:///?Id=beckhoff-22fb-41cd-a51c-d1597d45a6ca)
4. Relay overview

# Relay overview

The blocks only output a selection of the most common data. These data are described on the respective pages under "VAR\_OUTPUT". If more or all data are required, the blocks [FB\_MBUS\_General](ms-xhelp:///?Id=beckhoff-8e90-4a30-8684-e4959275ff37), [FB\_MBUS\_General\_Ext](ms-xhelp:///?Id=beckhoff-7616-46e1-8f68-e6176732685e) or [FB\_MBUS\_General\_Param](ms-xhelp:///?Id=beckhoff-ac86-411d-8af8-85905f72b0e0) from the folder "[General](ms-xhelp:///?Id=beckhoff-c2c9-4532-a008-46db7e04da46)" should be used. Note that these blocks do not run BC and BX systems. The block [FB\_MBUS\_General\_Send()](ms-xhelp:///?Id=beckhoff-7b44-4f8f-aefc-9ad31e83ecd2) can be used to send data to the device (e.g. setting of the primary address).

| Manufacturer | Type | Device | Block |
| --- | --- | --- | --- |
| **Relay** | 1-4 analog inputs | AnDi 1-4 | [FB\_MBUS\_REL\_AnDi](ms-xhelp:///?Id=beckhoff-b0a9-485a-b852-0e80b03a00c0) |
|  | 4 digital inputs | PadIn 4 | [FB\_MBUS\_REL\_PadIn4](ms-xhelp:///?Id=beckhoff-8ecb-427d-a02b-f593c8a75091) |
|  | 1-way pulse adapter | PadPuls M1 | [FB\_MBUS\_REL\_PadPulsM1](ms-xhelp:///?Id=beckhoff-4c58-47d3-b905-ba9c34fc3b50) |
|  | 1-way pulse adapter | PadPuls M1C | [FB\_MBUS\_REL\_PadPulsM1](ms-xhelp:///?Id=beckhoff-4c58-47d3-b905-ba9c34fc3b50) |
|  | 2-way pulse adapter | PadPuls M2 | [FB\_MBUS\_REL\_PadPulsM2](ms-xhelp:///?Id=beckhoff-fa6f-45a4-a6cb-3a23dafaf118) |
|  | 2-way pulse adapter | PadPuls M2C | [FB\_MBUS\_REL\_PadPulsM2](ms-xhelp:///?Id=beckhoff-fa6f-45a4-a6cb-3a23dafaf118) |
|  | 4-way pulse adapter | PadPuls M4 | [FB\_MBUS\_REL\_PadPulsM4](ms-xhelp:///?Id=beckhoff-2de0-4375-b290-96ce3350325b) |
|  | 4-way pulse adapter | PadPuls M4L | [FB\_MBUS\_REL\_PadPulsM4](ms-xhelp:///?Id=beckhoff-2de0-4375-b290-96ce3350325b) |

Further Information

* [FB\_MBUS\_REL\_AnDi](ms-xhelp:///?Id=beckhoff-b0a9-485a-b852-0e80b03a00c0)
* [FB\_MBUS\_REL\_PadIn4](ms-xhelp:///?Id=beckhoff-8ecb-427d-a02b-f593c8a75091)
* [FB\_MBUS\_REL\_PadPulsM1](ms-xhelp:///?Id=beckhoff-4c58-47d3-b905-ba9c34fc3b50)
* [FB\_MBUS\_REL\_PadPulsM2](ms-xhelp:///?Id=beckhoff-fa6f-45a4-a6cb-3a23dafaf118)
* [FB\_MBUS\_REL\_PadPulsM4](ms-xhelp:///?Id=beckhoff-2de0-4375-b290-96ce3350325b)

[TwinCAT 3 | PLC Library: Tc2\_MBus](ms-xhelp:///?Id=beckhoff-18e3-4e49-a9fc-7977791d6960)
