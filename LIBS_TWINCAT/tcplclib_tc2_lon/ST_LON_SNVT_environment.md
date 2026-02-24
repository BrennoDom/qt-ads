# ST_LON_SNVT_environment

## Library
tcplclib_tc2_lon

## Category
Motion Control

# ST\_LON\_SNVT\_environment

Used by: SNVT\_environment

```
TYPE ST_LON_SNVT_environment :  
STRUCT  
  uiLampCurrent   : UINT;  
  uiLampVoltage   : UINT;  
  uiSupplyVoltage : UINT;  
  uiSupplyCurrent : UINT;  
  rBallastTemp    : REAL;  
  rPower          : REAL;  
  rPowerFactor    : REAL;  
  udiRunHours     : UDINT;  
  lrEnergy        : LREAL;  
END_STRUCT  
END_TYPE
```

**uiLampCurrent:** Min: 0 / Max: 65534 / Invalid: 65535 / Lamp current (milliAmperes). This is the current the lamp consumes.

**uiLampVoltage:** Min: 0 / Max: 65535/ Lamp Voltage (Volts). This is the lamp voltage.

**uiSupplyVoltage:** Min: 0 / Max: 65535 / Supply Voltage (Volts). This is the luminaire supply voltage.

**uiSupplyCurrent:** Min: 0 / Max: 65534 / Invalid: 65535 / Supply Current (milliAmperes). This is the luminaire supply current.

**rBallastTemp:** Min: -273.17 / Max: 327.67 / Ballast temperature (degrees Celsius). This is the temperature at the ballast.

**rPower:** Min: 0 / Max: 6553.5 / Power (Watts). The value shows the at this moment consumed power of the ballast and the luminaire.

**rPowerFactor:** Min: -1 / Max: 1 / Power factor. This is the luminaire power-factor.

**udiRunHours:** Min: 0 / Max: 4294967294 / Run Hours (hours). This are the run hours since the last maintenance.

**lrEnergy:** Min: -214748364.8 / Max: 214748364.7 / Energy (kiloWatt-hours). This is the energy the luminair has consumed since the last maintenance.

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_LON from 3.3.4.0 |
