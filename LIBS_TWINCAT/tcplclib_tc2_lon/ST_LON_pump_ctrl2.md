# ST_LON_pump_ctrl2

## Library
tcplclib_tc2_lon

## Category
Motion Control

# ST\_LON\_pump\_ctrl2

Used by: SNVT\_dev\_maint

```
TYPE ST_LON_pump_ctrl2 :  
STRUCT  
  bService_required   : BOOL;  
  bBearings_change    : BOOL;  
  bBearings_lubricate : BOOL;  
  bShaftseal_change   : BOOL;  
  byReserved1_4_7     : BYTE;  
  byReserved2_0_7     : BYTE;  
  byReserved3_0_7     : BYTE;  
END_STRUCT  
END_TYPE
```

**bService\_required:** Service required (boolean) . Service/maintenance is required

**bBearings\_change:** Change bearings (boolean) . Bearings need to be replaced

**bBearings\_lubricate:** Lubricate bearings (boolean) . Bearings need to be greased

**bShaftseal\_change:** Change shaft seal (boolean) . Seal on the shaft needs to be replaced

**byReserved1\_4\_7:** Reserve

**byReserved2\_0\_7:** Reserve

**byReserved3\_0\_7:** Reserve

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_LON from 3.3.4.0 |
