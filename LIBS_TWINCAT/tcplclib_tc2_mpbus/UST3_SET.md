# UST3_SET

## Library
tcplclib_tc2_mpbus

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_MPBus](ms-xhelp:///?Id=beckhoff-afbb-4e7a-a6f0-964a87283892)
2. [Programming](ms-xhelp:///?Id=beckhoff-177e-411b-bfa4-57549cd6742f)
3. [DUTs](ms-xhelp:///?Id=beckhoff-ec1f-451d-a0f5-4c656574c991)
4. [Structures](ms-xhelp:///?Id=beckhoff-9706-4771-ad0e-639d770876a0)
5. UST3\_SET

# UST3\_SET

Data structure for setting the scaling and the resistance measurement

```
TYPE UST3_SET :  
STRUCT  
  E1       : UST3_Ex;  
  E2       : UST3_Ex;  
  E3       : UST3_Ex;  
  R_SET    : UST3_R_set;  
  R_ON_OFF : BOOL;  
END_STRUCT  
END_TYPE
```

**E1:** parameter U1 (see [UST3\_Ex](ms-xhelp:///?Id=beckhoff-1dcf-4fcf-9309-5c61bf185ac2))

**E2:** parameter U2 (see [UST3\_Ex](ms-xhelp:///?Id=beckhoff-1dcf-4fcf-9309-5c61bf185ac2))

**E3:** parameter U3 (see [UST3\_Ex](ms-xhelp:///?Id=beckhoff-1dcf-4fcf-9309-5c61bf185ac2))

**R\_SET:** parameter Y (see [UST3\_R\_set](ms-xhelp:///?Id=beckhoff-cdcf-4d3d-9404-6404754febd8))

**R\_ON\_OFF:** Measurement R or U

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_MPBus from 3.3.5.0 |

[TwinCAT 3 | PLC Library: Tc3\_MPBus](ms-xhelp:///?Id=beckhoff-afbb-4e7a-a6f0-964a87283892)
