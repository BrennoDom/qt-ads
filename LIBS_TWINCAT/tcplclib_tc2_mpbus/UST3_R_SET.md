# UST3_R_SET

## Library
tcplclib_tc2_mpbus

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_MPBus](ms-xhelp:///?Id=beckhoff-afbb-4e7a-a6f0-964a87283892)
2. [Programming](ms-xhelp:///?Id=beckhoff-177e-411b-bfa4-57549cd6742f)
3. [DUTs](ms-xhelp:///?Id=beckhoff-ec1f-451d-a0f5-4c656574c991)
4. [Enums](ms-xhelp:///?Id=beckhoff-a688-45f4-907e-ed52c85f5141)
5. UST3\_R\_SET

# UST3\_R\_SET

Resistance scaling

```
TYPE UST3_R_SET :  
(  
  R_1Ohm    := 0,  
  R_250mOhm := 1,  
  R_4Ohm    := 2  
)  
END_TYPE
```

**R\_1Ohm:** Scaling 0..20 kOhm

**R\_250mOhm:** Scaling 0..5 kOhm

**R\_4Ohm:** Scaling 0..262 kOhm

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_MPBus from 3.3.5.0 |

[TwinCAT 3 | PLC Library: Tc3\_MPBus](ms-xhelp:///?Id=beckhoff-afbb-4e7a-a6f0-964a87283892)
