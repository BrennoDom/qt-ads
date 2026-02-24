# E_LON_hvac_t

## Library
tcplclib_tc2_lon

## Category
Motion Control

# E\_LON\_hvac\_t

Used by: SNVT\_chlr\_status / SNVT\_hvac\_mode / SNVT\_hvac\_status

```
TYPE E_LON_hvac_t :  
(  
  eLON_HVAC_NUL         := -1,  
  eLON_HVAC_AUTO        := 0,  
  eLON_HVAC_HEAT        := 1,  
  eLON_HVAC_MRNG_WRMUP  := 2,  
  eLON_HVAC_COOL        := 3,  
  eLON_HVAC_NIGHT_PURGE := 4,  
  eLON_HVAC_PRE_COOL    := 5,  
  eLON_HVAC_OFF         := 6,  
  eLON_HVAC_TEST        := 7,  
  eLON_HVAC_EMERG_HEAT  := 8,  
  eLON_HVAC_FAN_ONLY    := 9,  
  eLON_HVAC_FREE_COOL   := 10,  
  eLON_HVAC_ICE         := 11,  
  eLON_HVAC_MAX_HEAT    := 12,  
  eLON_HVAC_ECONOMY     := 13,  
  eLON_HVAC_DEHUMID     := 14,  
  eLON_HVAC_CALIBRATE   := 15,  
  eLON_HVAC_EMERG_COOL  := 16,  
  eLON_HVAC_EMERG_STEAM := 17,  
  eLON_HVAC_MAX_COOL    := 18,  
  eLON_HVAC_HVC_LOAD    := 19,  
  eLON_HVAC_NO_LOAD     := 20  
)  
END_TYPE
```

**eLON\_HVAC\_NUL:**  Invalid value

**eLON\_HVAC\_AUTO:**  Controller automatically changes between application modes

**eLON\_HVAC\_HEAT:**  Heating only

**eLON\_HVAC\_MRNG\_WRMUP:**  Application-specific morning warm-up

**eLON\_HVAC\_COOL:**  Cooling only

**eLON\_HVAC\_NIGHT\_PURGE:**  Application-specific night purge

**eLON\_HVAC\_PRE\_COOL:**  Application-specific pre-cool

**eLON\_HVAC\_OFF:**  Controller not controlling outputs

**eLON\_HVAC\_TEST:**  Equipment being tested

**eLON\_HVAC\_EMERG\_HEAT:**  Emergency heat mode (heat pump)

**eLON\_HVAC\_FAN\_ONLY:**  Air not conditioned, fan turned on

**eLON\_HVAC\_FREE\_COOL:**  Cooling with compressor not running

**eLON\_HVAC\_ICE:**  Ice-making mode

**eLON\_HVAC\_MAX\_HEAT:**  Maximum heating mode

**eLON\_HVAC\_ECONOMY:**  Economic Heat/Cool mode

**eLON\_HVAC\_DEHUMID:**  Dehumidification mode

**eLON\_HVAC\_CALIBRATE:**  Calibration mode

**eLON\_HVAC\_EMERG\_COOL:**  Emergency cool mode

**eLON\_HVAC\_EMERG\_STEAM:**  Emergency steam mode

**eLON\_HVAC\_MAX\_COOL:**

**eLON\_HVAC\_HVC\_LOAD:**

**eLON\_HVAC\_NO\_LOAD:**

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_LON from 3.3.4.0 |
