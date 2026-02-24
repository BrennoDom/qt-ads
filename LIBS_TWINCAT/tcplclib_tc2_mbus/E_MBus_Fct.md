# E_MBus_Fct

## Library
tcplclib_tc2_mbus

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_MBus](ms-xhelp:///?Id=beckhoff-18e3-4e49-a9fc-7977791d6960)
2. [Programming](ms-xhelp:///?Id=beckhoff-3a96-436d-9f67-e2d673372cb2)
3. [DUTs](ms-xhelp:///?Id=beckhoff-150e-454f-9b9c-2dace1ed642c)
4. [Enums](ms-xhelp:///?Id=beckhoff-3e72-4e2d-b162-3a62166aa205)
5. E\_MBus\_Fct

# E\_MBus\_Fct

Value function.

```
TYPE E_MBus_Fct :  
(  
  eMBUS_ValueNull             := -1,  
  eMBUS_InstantaneousValue    := 0,  
  eMBUS_Max                   := 1,  
  eMBUS_Min                   := 2,  
  eMBUS_ValueDuringErrorState := 3,  
  eMBUS_ManufacturerSpecific  := 256  
)  
END_TYPE
```

**eMBUS\_ValueNull:** Not assigned.

**eMBUS\_InstantaneousValue:** Instantaneous value.

**eMBUS\_Max:** Maximum value.

**eMBUS\_Min:** Minimum value.

**eMBUS\_ValueDuringErrorState:** Faulty value.

**eMBUS\_ManufacturerSpecific:** Manufacturer-specific.

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_MBus from 3.3.4.0 |

[TwinCAT 3 | PLC Library: Tc2\_MBus](ms-xhelp:///?Id=beckhoff-18e3-4e49-a9fc-7977791d6960)
