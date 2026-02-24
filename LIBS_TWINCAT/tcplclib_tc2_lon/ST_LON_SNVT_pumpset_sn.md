# ST_LON_SNVT_pumpset_sn

## Library
tcplclib_tc2_lon

## Category
Motion Control

# ST\_LON\_SNVT\_pumpset\_sn

Used by: SNVT\_pumpset\_sn

```
TYPE ST_LON_SNVT_pumpset_sn :  
STRUCT  
  uiTotal_dilution_flow        : UINT;  
  rExhaust_temperature         : REAL;  
  rExhaust_pressure            : REAL;  
  rShaft_seal_purge_pressure   : REAL;  
  rInlet_vacuum                : REAL;  
  rSupply_voltage              : REAL;  
  uiCoolant_flow               : UINT;  
  eCoolant_flow_low            : E_LON_boolean_t;  
  eDilution_active             : E_LON_boolean_t;  
  eBallast_dilution_active     : E_LON_boolean_t;  
  eInlet_purge_dilution_active : E_LON_boolean_t;  
  eExhaust_dilution_active     : E_LON_boolean_t;  
  eDilution_flow_Out_of_range  : E_LON_boolean_t;  
  ePower_supply_on             : E_LON_boolean_t;  
END_STRUCT  
END_TYPE
```

**uiTotal\_dilution\_flow:** Min: 0 / Max: 65535 / Dilution gas flow.

**rExhaust\_temperature:** Min: 274 / Max: 6279.5 / Exhaust line external temperature.

**rExhaust\_pressure:** Min: -3276.8 / Max: 3276.7 / Exhaust line pressure.

**rShaft\_seal\_purge\_pressure:** Min: -3276.8 / Max: 3276.7 / Shaft seal purge pressure.

**rInlet\_vacuum:** Min: -3.40E+38 / Max: 3.40E+38 / Process gas inlet pressure.

**rSupply\_voltage:** Min: -3276.8 / Max: 3276.7 / Pumpset power supply voltage.

**uiCoolant\_flow:** Min: 0 / Max: 65535 / Total coolant flow.

**eCoolant\_flow\_low:** Coolant flow too low (boolean) (see [E\_LON\_boolean\_t](ms-xhelp:///?Id=beckhoff-d20f-4a1d-946e-6e930b436d90)).

**eDilution\_active:** Coolant flow too low (boolean) (see [E\_LON\_boolean\_t](ms-xhelp:///?Id=beckhoff-d20f-4a1d-946e-6e930b436d90)).

**eBallast\_dilution\_active:** Dilution gas being used as ballast (boolean) (see [E\_LON\_boolean\_t](ms-xhelp:///?Id=beckhoff-d20f-4a1d-946e-6e930b436d90)).

**eInlet\_purge\_dilution\_active:** Dilution gas being used to purge process gas (boolean) (see [E\_LON\_boolean\_t](ms-xhelp:///?Id=beckhoff-d20f-4a1d-946e-6e930b436d90)).

**eExhaust\_dilution\_active:** Dilution gas being used to dilute exhaust (boolean) (see [E\_LON\_boolean\_t](ms-xhelp:///?Id=beckhoff-d20f-4a1d-946e-6e930b436d90)).

**eDilution\_flow\_Out\_of\_range:** Dilution gas flow outside normal range (boolean) (see [E\_LON\_boolean\_t](ms-xhelp:///?Id=beckhoff-d20f-4a1d-946e-6e930b436d90)).

**ePower\_supply\_on:** Dilution gas flow outside normal range (boolean) (see [E\_LON\_boolean\_t](ms-xhelp:///?Id=beckhoff-d20f-4a1d-946e-6e930b436d90)).

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_LON from 3.3.4.0 |
