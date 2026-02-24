# Landis & Gyr overview

## Library
tcplclib_tc2_mbus

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_MBus](ms-xhelp:///?Id=beckhoff-18e3-4e49-a9fc-7977791d6960)
2. [Programming](ms-xhelp:///?Id=beckhoff-3a96-436d-9f67-e2d673372cb2)
3. [POUs](ms-xhelp:///?Id=beckhoff-22fb-41cd-a51c-d1597d45a6ca)
4. Landis & Gyr overview

# Landis & Gyr overview

The blocks only output a selection of the most common data. These data are described on the respective pages under "VAR\_OUTPUT". If more or all data are required, the blocks [FB\_MBUS\_General](ms-xhelp:///?Id=beckhoff-8e90-4a30-8684-e4959275ff37), [FB\_MBUS\_General\_Ext](ms-xhelp:///?Id=beckhoff-7616-46e1-8f68-e6176732685e) or [FB\_MBUS\_General\_Param](ms-xhelp:///?Id=beckhoff-ac86-411d-8af8-85905f72b0e0) from the folder "[General](ms-xhelp:///?Id=beckhoff-c2c9-4532-a008-46db7e04da46)" should be used. Note that these blocks do not run BC and BX systems. The block [FB\_MBUS\_General\_Send()](ms-xhelp:///?Id=beckhoff-7b44-4f8f-aefc-9ad31e83ecd2) can be used to send data to the device (e.g. setting of the primary address).

| Manufacturer | Type | Device | Block |
| --- | --- | --- | --- |
| **Landis & Gyr** | Heat/cold meter | ULTRAHEAT 2WR5 | [FB\_MBUS\_LUG\_Heat](ms-xhelp:///?Id=beckhoff-fe8d-4da3-8a4d-e26c51422457) |
|  | Heat/cold meter | ULTRAHEAT 2WR6 | [FB\_MBUS\_LUG\_Heat](ms-xhelp:///?Id=beckhoff-fe8d-4da3-8a4d-e26c51422457) |
|  | Heat/cold meter | ULTRAHEAT UH50 | [FB\_MBUS\_LUG\_Heat](ms-xhelp:///?Id=beckhoff-fe8d-4da3-8a4d-e26c51422457) |

Further Information

* [FB\_MBUS\_LUG\_Heat](ms-xhelp:///?Id=beckhoff-fe8d-4da3-8a4d-e26c51422457)

[TwinCAT 3 | PLC Library: Tc2\_MBus](ms-xhelp:///?Id=beckhoff-18e3-4e49-a9fc-7977791d6960)
