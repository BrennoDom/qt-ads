# E_DALIEventScheme

## Library
tcplclib_tc3_dali

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc3\_DALI](ms-xhelp:///?Id=beckhoff-3b50-4f78-8721-86f9c15e9bec)
2. [Programming](ms-xhelp:///?Id=beckhoff-b5e2-4347-b4c8-164a6e6f2543)
3. [DUTs](ms-xhelp:///?Id=beckhoff-e84a-422d-b94e-99adcaade658)
4. [Enumerations](ms-xhelp:///?Id=beckhoff-c968-4aa7-be35-e6241e64c6c6)
5. E\_DALIEventScheme

# E\_DALIEventScheme

```
TYPE E_DALIEventScheme :  
(  
  Instance                 := 0,  
  Device                   := 1,  
  DeviceInstance           := 2,  
  DeviceGroup              := 3,  
  InstanceGroup            := 4,  
  Unknown                  := 255  
) BYTE := Unknown;  
END_TYPE
```

**Instance**: Instance addressing with instance type and instance number.

**Device:** Device addressing with short address and instance type.

**DeviceInstance**: Device/instance addressing with short address and instance number.

**DeviceGroup**: Addressing of device groups with device group and instance type.

**InstanceGroup**: Addressing of instance groups with instance group and instance type.

## Requirements

| Development environment | required PLC library |
| --- | --- |
| TwinCAT from v3.1.4022.29 | Tc3\_DALI from v3.1.4.0 |

[TwinCAT 3 | PLC Library: Tc3\_DALI](ms-xhelp:///?Id=beckhoff-3b50-4f78-8721-86f9c15e9bec)
