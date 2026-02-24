# ST_LON_SNVT_pump_sensor

## Library
tcplclib_tc2_lon

## Category
Motion Control

# ST\_LON\_SNVT\_pump\_sensor

Used by: SNVT\_pump\_sensor

```
TYPE ST_LON_SNVT_pump_sensor :  
STRUCT  
  rRotational_speed             : REAL;  
  rBody_temperature             : REAL;  
  rMotor_external_temperature   : REAL;  
  rMotor_internal_temperature   : REAL;  
  eMotor_overloaded             : E_LON_boolean_t;  
  eOil_level_low                : E_LON_boolean_t;  
  ePhase_imbalance_detected     : E_LON_boolean_t;  
  rCurrent_usage                : REAL;  
  rPower_usage                  : REAL;  
  eTemperature_control          : E_LON_unit_temp_t;  
  eElectromagnetic_brake_active : E_LON_boolean_t;  
  eFriction_brake_active        : E_LON_boolean_t;  
  eGas_brake_active             : E_LON_boolean_t;  
END_STRUCT  
END_TYPE
```

**rRotational\_speed:** Min: 0 / Max: 6553.5 / Rotational speed.

**rBody\_temperature:** Min: -274 / Max: 6279.5 / Body temperature.

**rMotor\_external\_temperature:** Min: -274 / Max: 6279.5 / Motor external temp.

**rMotor\_internal\_temperature:** Min: -274 / Max: 6279.5 / Motor internal temp.

**eMotor\_overloaded:** Motor overloaded (boolean) (see [E\_LON\_boolean\_t](ms-xhelp:///?Id=beckhoff-d20f-4a1d-946e-6e930b436d90)).

**eOil\_level\_low:** Oil level low (boolean) (see [E\_LON\_boolean\_t](ms-xhelp:///?Id=beckhoff-d20f-4a1d-946e-6e930b436d90)).

**ePhase\_imbalance\_detected:** Phase imbalance (boolean) (see [E\_LON\_boolean\_t](ms-xhelp:///?Id=beckhoff-d20f-4a1d-946e-6e930b436d90)).

**rCurrent\_usage:** Min: -3276.8 / Max: 3276.7 / Current usage.

**rPower\_usage:** Min: 0 / Max: 6553.5 / Power usage.

**eTemperature\_control:** Pump body temp control status (temperature control status names) (see [E\_LON\_unit\_temp\_t](ms-xhelp:///?Id=beckhoff-0d3d-4575-a8ba-399564bfdf1b)).

**eElectromagnetic\_brake\_active:** Electromagnetic brake active (boolean) (see [E\_LON\_boolean\_t](ms-xhelp:///?Id=beckhoff-d20f-4a1d-946e-6e930b436d90)).

**eFriction\_brake\_active:** Friction brake active (boolean) (see [E\_LON\_boolean\_t](ms-xhelp:///?Id=beckhoff-d20f-4a1d-946e-6e930b436d90)).

**eGas\_brake\_active:** Gas brake active (boolean) (see [E\_LON\_boolean\_t](ms-xhelp:///?Id=beckhoff-d20f-4a1d-946e-6e930b436d90)).

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_LON from 3.3.4.0 |
