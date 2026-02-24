# ST_MBus_Scan

## Library
tcplclib_tc2_mbus

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_MBus](ms-xhelp:///?Id=beckhoff-18e3-4e49-a9fc-7977791d6960)
2. [Programming](ms-xhelp:///?Id=beckhoff-3a96-436d-9f67-e2d673372cb2)
3. [DUTs](ms-xhelp:///?Id=beckhoff-150e-454f-9b9c-2dace1ed642c)
4. [Structures](ms-xhelp:///?Id=beckhoff-4dd1-4d9d-808a-6e4cba67de22)
5. ST\_MBus\_Scan

# ST\_MBus\_Scan

Scanning information.

```
TYPE ST_MBus_Scan :  
STRUCT  
  usiAddress : USINT;  
  dwIdNumber : DWORD;  
  byStatus   : BYTE;  
  eMedium    : E_MBUS_Medium;  
  sMan       : STRING(3);  
  byGEN      : BYTE;  
END_STRUCT  
END_TYPE
```

**usiAddress:**  [Primary address](ms-xhelp:///?Id=beckhoff-3e32-45c4-90d9-d20c91a7dc41) of the meter.

**dwIdNumber:** Serial number of the meter (secondary address)

**byStatus:** Status.

**eMedium:** Medium (see [E\_MBUS\_Medium](ms-xhelp:///?Id=beckhoff-c529-425e-8b1a-4d4c3080afd2)).

**sMan:** Manufacturer code.

**byGEN:** Software version of the device.

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_MBus from 3.3.4.0 |

[TwinCAT 3 | PLC Library: Tc2\_MBus](ms-xhelp:///?Id=beckhoff-18e3-4e49-a9fc-7977791d6960)
