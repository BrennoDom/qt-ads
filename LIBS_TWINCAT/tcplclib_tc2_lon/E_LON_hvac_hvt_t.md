# E_LON_hvac_hvt_t

## Library
tcplclib_tc2_lon

## Category
Motion Control

# E\_LON\_hvac\_hvt\_t

Used by: SNVT\_hvac\_type

```
TYPE E_LON_hvac_hvt_t :  
(  
  eLON_HVT_NUL        := -1,  
  eLON_HVT_GENERIC    := 0,  
  eLON_HVT_FAN_COIL   := 1,  
  eLON_HVT_VAV        := 2,  
  eLON_HVT_HEAT_PUMP  := 3,  
  eLON_HVT_ROOFTOP    := 4,  
  eLON_HVT_UNIT_VENT  := 5,  
  eLON_HVT_CHILL_CEIL := 6,  
  eLON_HVT_RADIATOR   := 7,  
  eLON_HVT_AHU        := 8,  
  eLON_HVT_SELF_CONT  := 9  
)  
END_TYPE
```

**eLON\_HVT\_NUL:**  Invalid Value

**eLON\_HVT\_GENERIC:**  Generic

**eLON\_HVT\_FAN\_COIL:**  Fan Coil

**eLON\_HVT\_VAV:**  Variable Air Volume Terminal

**eLON\_HVT\_HEAT\_PUMP:**  Heat Pump

**eLON\_HVT\_ROOFTOP:**  Rooftop Unit

**eLON\_HVT\_UNIT\_VENT:**  Unit Ventilator

**eLON\_HVT\_CHILL\_CEIL:**  Chilled Ceiling

**eLON\_HVT\_RADIATOR:**  Radiator

**eLON\_HVT\_AHU:**  Air Handling Unit

**eLON\_HVT\_SELF\_CONT:**  Self-Contained Unit

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_LON from 3.3.4.0 |
