# E_MP_EP_R_R6_UnitSel

## Library
tcplclib_tc2_mpbus

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_MPBus](ms-xhelp:///?Id=beckhoff-afbb-4e7a-a6f0-964a87283892)
2. [Programming](ms-xhelp:///?Id=beckhoff-177e-411b-bfa4-57549cd6742f)
3. [DUTs](ms-xhelp:///?Id=beckhoff-ec1f-451d-a0f5-4c656574c991)
4. [Enums](ms-xhelp:///?Id=beckhoff-a688-45f4-907e-ed52c85f5141)
5. E\_MP\_EP\_R\_R6\_UnitSel

# E\_MP\_EP\_R\_R6\_UnitSel

Scaling.

```
TYPE E_MP_ER_R_R6_UnitSel :  
(  
  E_MP_m3_s  := 0,  
  E_MP_m3_h  := 1,  
  E_MP_l_s   := 2,  
  E_MP_l_min := 3,  
  E_MP_l_h   := 4,  
  E_MP_gpm   := 5,  
  E_MP_cfm   := 6  
);  
END_TYPE
```

**E\_MP\_m3\_s:** Sets scaling to m3/s.

**E\_MP\_m3\_h:** Sets scaling to m3/h.

**E\_MP\_l\_s:** Sets scaling to l/s.

**E\_MP\_l\_min:** Sets scaling to l/min.

**E\_MP\_l\_h:** Sets scaling to l/h.

**E\_MP\_gpm:** Sets scaling to gpm.

**E\_MP\_cfm:** Sets scaling to cfm.

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4022.14 | Tc2\_MPBus from 3.4.8.0 |

[TwinCAT 3 | PLC Library: Tc3\_MPBus](ms-xhelp:///?Id=beckhoff-afbb-4e7a-a6f0-964a87283892)
