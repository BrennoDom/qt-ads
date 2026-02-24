# ST_LON_valve_pos1

## Library
tcplclib_tc2_lon

## Category
Motion Control

# ST\_LON\_valve\_pos1

Used by: SNVT\_dev\_fault

```
TYPE ST_LON_valve_pos1 :  
STRUCT  
  bDf_valve_blocked           : BOOL;  
  bDf_blocked_direction_open  : BOOL;  
  bDf_blocked_direction_close : BOOL;  
  bDf_position_error          : BOOL;  
  bDf_stroke_Out_of_range     : BOOL;  
  bDf_initialization          : BOOL;  
  bDf_vibration_cavitation    : BOOL;  
  bDf_ed_too_high             : BOOL;  
  byReserved1_0_2             : BYTE;  
  bEe_oscillating             : BOOL;  
  bEe_valve_too_large         : BOOL;  
  bEe_valve_too_small         : BOOL;  
  byReserved2_6_7             : BYTE;  
  bReserved3_0_7              : BOOL;  
  bSf_voltage_Out_of_range    : BOOL;  
  bSf_electronic_high_temp    : BOOL;  
  bSf_frictional_resistance   : BOOL;  
  byReserved4_4_6             : BYTE;  
  bGeneral_fault              : BOOL;  
END_STRUCT  
END_TYPE
```

**bDf\_valve\_blocked:** Device fault - valve blocked. The valve is presently blocked.

**bDf\_blocked\_direction\_open:** Device fault - blocked direction open. The device is blocked while attempting to open.

**bDf\_blocked\_direction\_close:** Device fault - blocked direction close. The device is blocked while attempting to close

**bDf\_position\_error:** Device fault - position error. The valve position is not correct

**bDf\_stroke\_Out\_of\_range:** Device fault - stroke out of range. The valve stroke is out of operating range

**bDf\_initialization:** Device fault - initialization error. The was an error during initialization of the device

**bDf\_vibration\_cavitation:** Device fault - vibration / cavitation. There are excessive vibrations or cavitations detected

**bDf\_ed\_too\_high:** Device fault - ED too high. The ED is too high

**byReserved1\_0\_2:** This field is reserved.. This field is reserved.

**bEe\_oscillating:** Engineering error - oscillating. There is an oscillating error

**bEe\_valve\_too\_large:** Engineering error - valve too big. The valve size is too large

**bEe\_valve\_too\_small:** Engineering error - valve too small. The valve size is too small

**byReserved2\_6\_7:** This field is reserved.. This field is reserved.

**bReserved3\_0\_7:** This field is reserved.. This field is reserved.

**bSf\_voltage\_Out\_of\_range:** Supply fault - voltage out of range. The voltage is out of the specified acceptable range

**bSf\_electronic\_high\_temp:** Supply fault - electronics temperature. The temperature of the electronics is too high

**bSf\_frictional\_resistance:** Supply fault - frictional resistance. Resistance due to friction is detected

**byReserved4\_4\_6:** This field is reserved.. This field is reserved.

**bGeneral\_fault:** General Fault. A General Fault has occurred. Please consult the documentation or contact the valve-controller manufacturer.

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_LON from 3.3.4.0 |
