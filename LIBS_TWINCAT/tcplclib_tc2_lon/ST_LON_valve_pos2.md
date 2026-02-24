# ST_LON_valve_pos2

## Library
tcplclib_tc2_lon

## Category
Motion Control

# ST\_LON\_valve\_pos2

Used by: SNVT\_dev\_maint

```
TYPE ST_LON_valve_pos2 :  
STRUCT  
  bMotor_maint       : BOOL;  
  bPacking_change    : BOOL;  
  bElectronics_check : BOOL;  
  bPositioning_check : BOOL;  
  bLubrication_check : BOOL;  
  bReturn_check      : BOOL;  
  battery_check      : BOOL;  
  bReserved1_7       : BOOL;  
  byReserved2_0_7    : BYTE;  
  byReserved3_0_6    : BYTE;  
  bGeneral_maint     : BOOL;  
END_STRUCT  
END_TYPE
```

**bMotor\_maint:** Motor Maintenance. The motor requires servicing

**bPacking\_change:** Packing Change. The packing needs to be controlled or changed

**bElectronics\_check:** Check Electronics. The electronics need to be checked (temperature too high)

**bPositioning\_check:** Check Position. The positioning needs to be checked (mechanical or electronic)

**bLubrication\_check:** Check Lubrication. The lubrication need to be checked

**bReturn\_check:** Check Spring-Return Function. The spring-return function needs to be checked

**battery\_check:** Check battery. The battery needs to be checked

**bReserved1\_7:** This field is reserved.. This field is reserved.

**byReserved2\_0\_7:** This field is reserved.. This field is reserved.

**byReserved3\_0\_6:** This field is reserved.. This field is reserved.

**bGeneral\_maint:** General Maintenance. General Maintenance needs to be performed. Please consult the documentation or your Maintenance Department.

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_LON from 3.3.4.0 |
