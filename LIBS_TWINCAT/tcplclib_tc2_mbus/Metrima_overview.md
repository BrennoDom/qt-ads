# Metrima overview

## Library
tcplclib_tc2_mbus

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_MBus](ms-xhelp:///?Id=beckhoff-18e3-4e49-a9fc-7977791d6960)
2. [Programming](ms-xhelp:///?Id=beckhoff-3a96-436d-9f67-e2d673372cb2)
3. [POUs](ms-xhelp:///?Id=beckhoff-22fb-41cd-a51c-d1597d45a6ca)
4. Metrima overview

# Metrima overview

The blocks only output a selection of the most common data. These data are described on the respective pages under "VAR\_OUTPUT". If more or all data are required, the blocks [FB\_MBUS\_General](ms-xhelp:///?Id=beckhoff-8e90-4a30-8684-e4959275ff37), [FB\_MBUS\_General\_Ext](ms-xhelp:///?Id=beckhoff-7616-46e1-8f68-e6176732685e) or [FB\_MBUS\_General\_Param](ms-xhelp:///?Id=beckhoff-ac86-411d-8af8-85905f72b0e0) from the folder "[General](ms-xhelp:///?Id=beckhoff-c2c9-4532-a008-46db7e04da46)" should be used. Note that these blocks do not run BC and BX systems. The block [FB\_MBUS\_General\_Send()](ms-xhelp:///?Id=beckhoff-7b44-4f8f-aefc-9ad31e83ecd2) can be used to send data to the device (e.g. setting of the primary address).

| Manufacturer | Type | Device | Block |
| --- | --- | --- | --- |
| **Metrima** | Heat meter | F22 (standard values) | [FB\_MBUS\_SVM\_F22](ms-xhelp:///?Id=beckhoff-44a3-48d4-821a-f0fc976a1b24) |
|  | Heat meter | F22 (with additional output values) | [FB\_MBUS\_SVM\_F22\_Ext](ms-xhelp:///?Id=beckhoff-a18a-43b3-9142-e75458d25943) |

Further Information

* [FB\_MBUS\_SVM\_F22](ms-xhelp:///?Id=beckhoff-44a3-48d4-821a-f0fc976a1b24)
* [FB\_MBUS\_SVM\_F22\_Ext](ms-xhelp:///?Id=beckhoff-a18a-43b3-9142-e75458d25943)

[TwinCAT 3 | PLC Library: Tc2\_MBus](ms-xhelp:///?Id=beckhoff-18e3-4e49-a9fc-7977791d6960)
