# E_DALIInstanceAddressType

## Library
tcplclib_tc3_dali

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc3\_DALI](ms-xhelp:///?Id=beckhoff-3b50-4f78-8721-86f9c15e9bec)
2. [Programming](ms-xhelp:///?Id=beckhoff-b5e2-4347-b4c8-164a6e6f2543)
3. [DUTs](ms-xhelp:///?Id=beckhoff-e84a-422d-b94e-99adcaade658)
4. [Enumerations](ms-xhelp:///?Id=beckhoff-c968-4aa7-be35-e6241e64c6c6)
5. E\_DALIInstanceAddressType

# E\_DALIInstanceAddressType

```
TYPE E_DALIInstanceAddressType :  
(  
  InstanceNumber        := 0,  
  InstanceGroup         := 1,  
  InstanceType          := 2,  
  FeatureNumber         := 3,  
  FeatureGroup          := 4,  
  FeatureType           := 5,  
  FeatureBroadcast      := 6,  
  InstanceBroadcast     := 7,  
  FeatureDevice         := 8,  
  Device                := 9  
) BYTE := InstanceNumber;  
END_TYPE
```

**InstanceNumber**: Instance number (0…31).

**InstanceGroup**: Instance group (0…31).

**InstanceType**: Instance type (0…31).

**FeatureNumber**: Feature at instance number level (0...31).

**FeatureGroup**: Feature at instance group level (0...31).

**FeatureType**: Feature at instance type level (0...31).

**FeatureBroadcast**: Feature at instance broadcast level.

**InstanceBroadcast:** Instance broadcast.

**FeatureDevice:** Feature at device level.

**Device:** Device

## Requirements

| Development environment | required PLC library |
| --- | --- |
| TwinCAT from v3.1.4022.29 | Tc3\_DALI from v3.1.4.0 |

[TwinCAT 3 | PLC Library: Tc3\_DALI](ms-xhelp:///?Id=beckhoff-3b50-4f78-8721-86f9c15e9bec)
