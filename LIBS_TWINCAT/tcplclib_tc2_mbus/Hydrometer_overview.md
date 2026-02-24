# Hydrometer overview

## Library
tcplclib_tc2_mbus

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_MBus](ms-xhelp:///?Id=beckhoff-18e3-4e49-a9fc-7977791d6960)
2. [Programming](ms-xhelp:///?Id=beckhoff-3a96-436d-9f67-e2d673372cb2)
3. [POUs](ms-xhelp:///?Id=beckhoff-22fb-41cd-a51c-d1597d45a6ca)
4. Hydrometer overview

# Hydrometer overview

The blocks only output a selection of the most common data. These data are described on the respective pages under "VAR\_OUTPUT". If more or all data are required, the blocks [FB\_MBUS\_General](ms-xhelp:///?Id=beckhoff-8e90-4a30-8684-e4959275ff37), [FB\_MBUS\_General\_Ext](ms-xhelp:///?Id=beckhoff-7616-46e1-8f68-e6176732685e) or [FB\_MBUS\_General\_Param](ms-xhelp:///?Id=beckhoff-ac86-411d-8af8-85905f72b0e0) from the folder "[General](ms-xhelp:///?Id=beckhoff-c2c9-4532-a008-46db7e04da46)" should be used. Note that these blocks do not run BC and BX systems. The block [FB\_MBUS\_General\_Send()](ms-xhelp:///?Id=beckhoff-7b44-4f8f-aefc-9ad31e83ecd2) can be used to send data to the device (e.g. setting of the primary address).

| Manufacturer | Type | Device | Block |
| --- | --- | --- | --- |
| **Hydrometer** | 2 pulse inputs | HYDRO-PORT Pulse | [FB\_MBUS\_HYD\_PortPulse](ms-xhelp:///?Id=beckhoff-e126-46f9-9340-6ccbb370ebd4) |
|  | 2 analog inputs + 1 temperature sensor | HYDRO-PORT Analog | [FB\_MBUS\_HYD\_PortAnalog](ms-xhelp:///?Id=beckhoff-f722-4ca0-9bb0-913821693554) |
|  | Water meter | Flypper | [FB\_MBUS\_HYD\_Flypper](ms-xhelp:///?Id=beckhoff-bfac-4a2d-bf3a-e7b9dedf9504) |
|  | Heat meter | Sharky 773 | [FB\_MBUS\_HYD\_Sharky](ms-xhelp:///?Id=beckhoff-41f9-420e-a041-22cdc21f5bec), [FB\_MBUS\_HYD\_Sharky\_00](ms-xhelp:///?Id=beckhoff-6f7c-4075-9022-42419a9f8748) |
|  | Heat meter | Sharky 775 | [FB\_MBUS\_HYD\_Sharky](ms-xhelp:///?Id=beckhoff-41f9-420e-a041-22cdc21f5bec), [FB\_MBUS\_HYD\_Sharky\_00](ms-xhelp:///?Id=beckhoff-6f7c-4075-9022-42419a9f8748) |

Further Information

* [FB\_MBUS\_HYD\_Flypper](ms-xhelp:///?Id=beckhoff-bfac-4a2d-bf3a-e7b9dedf9504)
* [FB\_MBUS\_HYD\_PortAnalog](ms-xhelp:///?Id=beckhoff-f722-4ca0-9bb0-913821693554)
* [FB\_MBUS\_HYD\_PortPulse](ms-xhelp:///?Id=beckhoff-e126-46f9-9340-6ccbb370ebd4)
* [FB\_MBUS\_HYD\_Sharky](ms-xhelp:///?Id=beckhoff-41f9-420e-a041-22cdc21f5bec)
* [FB\_MBUS\_HYD\_Sharky\_00](ms-xhelp:///?Id=beckhoff-6f7c-4075-9022-42419a9f8748)

[TwinCAT 3 | PLC Library: Tc2\_MBus](ms-xhelp:///?Id=beckhoff-18e3-4e49-a9fc-7977791d6960)
