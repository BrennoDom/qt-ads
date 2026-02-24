# ST_MBUS_SecAdr

## Library
tcplclib_tc2_mbus

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_MBus](ms-xhelp:///?Id=beckhoff-18e3-4e49-a9fc-7977791d6960)
2. [Programming](ms-xhelp:///?Id=beckhoff-3a96-436d-9f67-e2d673372cb2)
3. [DUTs](ms-xhelp:///?Id=beckhoff-150e-454f-9b9c-2dace1ed642c)
4. [Structures](ms-xhelp:///?Id=beckhoff-4dd1-4d9d-808a-6e4cba67de22)
5. ST\_MBUS\_SecAdr

# ST\_MBUS\_SecAdr

Secondary address of a meter.

```
TYPE ST_MBUS_SecAdr :  
STRUCT  
  udiIdNumber    : UDINT := 16#FFFFFFFF;  
  uiManufacturer : UINT := 16#FFFF;  
  usiVersion     : USINT := 16#FF;  
  usiMedium      : USINT := 16#FF;  
END_STRUCT  
END_TYPE
```

**udiIdNumber:** Serial number of the meter.

**uiManufacturer:** Manufacturer code.

**usiVersion:** Counter software version.

**usiMedium:** Medium.

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_MBus from 3.3.4.0 |

[TwinCAT 3 | PLC Library: Tc2\_MBus](ms-xhelp:///?Id=beckhoff-18e3-4e49-a9fc-7977791d6960)
