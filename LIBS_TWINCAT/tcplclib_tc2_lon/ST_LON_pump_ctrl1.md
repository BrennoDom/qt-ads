# ST_LON_pump_ctrl1

## Library
tcplclib_tc2_lon

## Category
Motion Control

# ST\_LON\_pump\_ctrl1

Used by: SNVT\_dev\_fault

```
TYPE ST_LON_pump_ctrl1 :  
STRUCT  
  bSf_voltage_low      : BOOL;  
  bSf_voltage_high     : BOOL;  
  bSf_phase            : BOOL;  
  bSf_no_fluid         : BOOL;  
  bSf_press_low        : BOOL;  
  bSf_press_high       : BOOL;  
  bSf_general_fault    : BOOL;  
  bSf_reserved1_7      : BOOL;  
  bDf_motor_temp       : BOOL;  
  bDf_motor_failure    : BOOL;  
  bDf_pump_blocked     : BOOL;  
  bDf_elect_temp       : BOOL;  
  bDf_elect_failure_nf : BOOL;  
  bDf_elect_failure    : BOOL;  
  bDf_sensor_failure   : BOOL;  
  bDf_general_fault    : BOOL;  
  byReserved3_0_7      : BYTE;  
END_STRUCT  
END_TYPE
```

**bSf\_voltage\_low:** Supply fault - low voltage (boolean). Supply voltage is too low.

**bSf\_voltage\_high:** Supply fault - high voltage (boolean). Supply voltage is too high.

**bSf\_phase:** Supply fault - power phase (boolean). Supply power is missing phase.

**bSf\_no\_fluid:** Supply fault - no fluid (boolean). There is no fluid in the pump.

**bSf\_press\_low:** Supply fault - low pressure (boolean). System pressure is too low

**bSf\_press\_high:** Supply fault - high pressure (boolean). System pressure is too high

**bSf\_general\_fault:** General supply fault.

**bSf\_reserved1\_7:**

**bDf\_motor\_temp:** Device fault - motor temperature (boolean).Motor temperature is too high

**bDf\_motor\_failure:** Device fault - motor fatal failure (boolean).Motor has encountered a fatal failure

**bDf\_pump\_blocked:** Device fault - pump blocked (boolean).Pump is presently blocked

**bDf\_elect\_temp:** Device fault - electronics temperature (boolean).Temperature of the electronic circuitry is too high

**bDf\_elect\_failure\_nf:** Device fault - electronics failure (boolean).Electronic circuitry has encountered a non-fatal failure

**bDf\_elect\_failure:** Device fault - electronics fatal failure (boolean). Electronic circuitry has encountered a fatal failure

**bDf\_sensor\_failure:** Device fault - sensor failure (boolean). Sensor has failed on the device

**bDf\_general\_fault:** General device fault.

**byReserved3\_0\_7:**

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_LON from 3.3.4.0 |
