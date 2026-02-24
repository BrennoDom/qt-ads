# ST_LON_SNVT_hvac_satsts

## Library
tcplclib_tc2_lon

## Category
Motion Control

# ST\_LON\_SNVT\_hvac\_satsts

Used by: SNVT\_hvac\_satsts

```
TYPE ST_LON_SNVT_hvac_satsts :  
STRUCT  
  bPri_heat              : BOOL;  
  bSec_heat              : BOOL;  
  bPri_cool              : BOOL;  
  bSec_cool              : BOOL;  
  bPri_duct_starved      : BOOL;  
  bSec_duct_starved      : BOOL;  
  bReserved1             : BOOL;  
  bReserved2             : BOOL;  
  byReserved1            : BYTE;  
  byManufacturer_defined : BYTE;  
END_STRUCT  
END_TYPE
```

**bPri\_heat:** Primary heating saturation status (boolean). A value of 0 indicates primary heating is not saturated. A value of 1 indicates primary heating is saturated.

**bSec\_heat:** Secondary heating saturation status (boolean). A value of 0 indicates secondary heating is not saturated. A value of 1 indicates secondary heating is saturated.

**bPri\_cool:** Primary cooling saturation status (boolean). A value of 0 indicates primary cooling is not saturated. A value of 1 indicates primary cooling is saturated.

**bSec\_cool:** Secondary cooling saturation status (boolean). A value of 0 indicates secondary cooling is not saturated. A value of 1 indicates secondary cooling is saturated.

**bPri\_duct\_starved:** Primary duct saturation status (boolean). A value of 0 indicates primary duct is not saturated (starved). A value of 1 indicates primary duct is saturated (starved).

**bSec\_duct\_starved:** Secondary duct saturation status (boolean). A value of 0 indicates secondary duct is not saturated (starved). A value of 1 indicates secondary duct is saturated (starved).

**bReserved1:**

**bReserved2:**

**byReserved1:** Min: 0 / Max: 15

**byManufacturer\_defined:** Min: 0 / Max: 15 / Manufacturer defined (boolean). Four manufacturer-defined bits -- please see product documentation for proper interpretation of these bits

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_LON from 3.3.4.0 |
