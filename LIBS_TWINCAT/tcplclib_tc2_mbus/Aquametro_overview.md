# Aquametro overview

## Library
tcplclib_tc2_mbus

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_MBus](ms-xhelp:///?Id=beckhoff-18e3-4e49-a9fc-7977791d6960)
2. [Programming](ms-xhelp:///?Id=beckhoff-3a96-436d-9f67-e2d673372cb2)
3. [POUs](ms-xhelp:///?Id=beckhoff-22fb-41cd-a51c-d1597d45a6ca)
4. Aquametro overview

# Aquametro overview

The blocks only output a selection of the most common data. These data are described on the respective pages under "VAR\_OUTPUT". If more or all data are required, the blocks [FB\_MBUS\_General](ms-xhelp:///?Id=beckhoff-8e90-4a30-8684-e4959275ff37), [FB\_MBUS\_General\_Ext](ms-xhelp:///?Id=beckhoff-7616-46e1-8f68-e6176732685e) or [FB\_MBUS\_General\_Param](ms-xhelp:///?Id=beckhoff-ac86-411d-8af8-85905f72b0e0) from the folder "[General](ms-xhelp:///?Id=beckhoff-c2c9-4532-a008-46db7e04da46)" should be used. Note that these blocks do not run BC and BX systems. The block [FB\_MBUS\_General\_Send()](ms-xhelp:///?Id=beckhoff-7b44-4f8f-aefc-9ad31e83ecd2) can be used to send data to the device (e.g. setting of the primary address).

| Manufacturer | Type | Device | Block |
| --- | --- | --- | --- |
| **Aquametro** | Water meter | SAPHIR | [FB\_MBUS\_AMT\_SAPHIR](ms-xhelp:///?Id=beckhoff-3e86-483c-8e6d-37e2e4621399) |
|  | Heat meter | CALEC | [FB\_MBUS\_AMT\_CALEC](ms-xhelp:///?Id=beckhoff-e2e7-4e8a-9a75-20e18c73e50b) |
|  | Heat meter | CALEC ST, version C4 | [FB\_MBUS\_AMT\_CALEC\_STC4](ms-xhelp:///?Id=beckhoff-37f7-4d30-9a80-fe80dec37f42) |
|  | Heat meter | AMTRON | [FB\_MBUS\_AMT\_AMTRON](ms-xhelp:///?Id=beckhoff-9422-44d8-a1b5-506cd9afd967) |
|  | Pulse collector | AMBUS | [FB\_MBUS\_AMT\_AMBUS](ms-xhelp:///?Id=beckhoff-4f46-4cdd-be17-2ce57b7fd89a) |
|  | Heat meter | AMTRON SONIC D | [FB\_MBUS\_HYD\_Sharky](ms-xhelp:///?Id=beckhoff-41f9-420e-a041-22cdc21f5bec), [FB\_MBUS\_HYD\_Sharky\_00](ms-xhelp:///?Id=beckhoff-6f7c-4075-9022-42419a9f8748) |

Further Information

* [FB\_MBUS\_AMT\_AMBUS](ms-xhelp:///?Id=beckhoff-4f46-4cdd-be17-2ce57b7fd89a)
* [FB\_MBUS\_AMT\_AMTRON](ms-xhelp:///?Id=beckhoff-9422-44d8-a1b5-506cd9afd967)
* [FB\_MBUS\_AMT\_CALEC](ms-xhelp:///?Id=beckhoff-e2e7-4e8a-9a75-20e18c73e50b)
* [FB\_MBUS\_AMT\_CALEC\_STC4](ms-xhelp:///?Id=beckhoff-37f7-4d30-9a80-fe80dec37f42)
* [FB\_MBUS\_AMT\_SAPHIR](ms-xhelp:///?Id=beckhoff-3e86-483c-8e6d-37e2e4621399)

[TwinCAT 3 | PLC Library: Tc2\_MBus](ms-xhelp:///?Id=beckhoff-18e3-4e49-a9fc-7977791d6960)
