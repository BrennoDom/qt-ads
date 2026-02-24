# E_LON_sblnd_error_t

## Library
tcplclib_tc2_lon

## Category
Motion Control

# E\_LON\_sblnd\_error\_t

Used by: SNVT\_sblnd\_state

```
TYPE E_LON_sblnd_error_t :  
(  
  eLON_SBE_NUL            := -1,  
  eLON_SBE_NO_ERROR       := 0,  
  eLON_SBE_IN_PROGRESS    := 1,  
  eLON_SBE_LIMITS         := 2,  
  eLON_SBE_OBSTACLE_UP    := 3,  
  eLON_SBE_OBSTACLE_DOWN  := 4,  
  eLON_SBE_OVERHEAT       := 5,  
  eLON_SBE_POWER          := 6,  
  eLON_SBE_SENSOR         := 7,  
  eLON_SBE_MOTOR_CIRCUIT  := 8,  
  eLON_SBE_FUSE           := 9,  
  eLON_SBE_REFERENCE_LOST := 10,  
  eLON_SBE_HOST_COMM      := 11,  
  eLON_SBE_VOLTAGE_1      := 12,  
  eLON_SBE_VOLTAGE_2      := 13,  
  eLON_SBE_CONTROLLER     := 14  
)  
END_TYPE
```

**eLON\_SBE\_NUL:**  Invalid Value

**eLON\_SBE\_NO\_ERROR:**  No error

**eLON\_SBE\_IN\_PROGRESS:**  In progress

**eLON\_SBE\_LIMITS:**  Limits

**eLON\_SBE\_OBSTACLE\_UP:**  Obstacle up

**eLON\_SBE\_OBSTACLE\_DOWN:**  Obstacle down

**eLON\_SBE\_OVERHEAT:**  Overheat

**eLON\_SBE\_POWER:**  Power

**eLON\_SBE\_SENSOR:**  Sensor

**eLON\_SBE\_MOTOR\_CIRCUIT:**  Motor circuit

**eLON\_SBE\_FUSE:**  Fuse

**eLON\_SBE\_REFERENCE\_LOST:**  Reference lost

**eLON\_SBE\_HOST\_COMM:**  Host communication

**eLON\_SBE\_VOLTAGE\_1:**  Voltage 1

**eLON\_SBE\_VOLTAGE\_2:**  Voltage 2

**eLON\_SBE\_CONTROLLER:**  Controller

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_LON from 3.3.4.0 |
