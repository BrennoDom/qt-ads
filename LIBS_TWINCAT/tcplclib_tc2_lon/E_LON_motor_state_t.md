# E_LON_motor_state_t

## Library
tcplclib_tc2_lon

## Category
Motion Control

# E\_LON\_motor\_state\_t

Used by: SNVT\_motor\_state / SNVT\_pumpset\_mn

```
TYPE E_LON_motor_state_t :  
(  
  eLON_MOTOR_NUL          := -1,  
  eLON_MOTOR_STOPPED      := 0,  
  eLON_MOTOR_STARTING     := 1,  
  eLON_MOTOR_ACCELERATING := 2,  
  eLON_MOTOR_AT_STANDBY   := 3,  
  eLON_MOTOR_AT_NORMAL    := 4,  
  eLON_MOTOR_AT_REFERENCE := 5,  
  eLON_MOTOR_DECELERATING := 6,  
  eLON_MOTOR_STOPPING     := 7  
)  
END_TYPE
```

**eLON\_MOTOR\_NUL:**  The state of the motor is unknown (invalid value)

**eLON\_MOTOR\_STOPPED:**  The motor is not running

**eLON\_MOTOR\_STARTING:**  The motor is performing its start-up sequence

**eLON\_MOTOR\_ACCELERATING:**  The motor is running. Speed is increasing.

**eLON\_MOTOR\_AT\_STANDBY:**  The motor is running in its standby mode

**eLON\_MOTOR\_AT\_NORMAL:**  The motor is running in its normal operational mode

**eLON\_MOTOR\_AT\_REFERENCE:**  The motor is running at its reference speed.

**eLON\_MOTOR\_DECELERATING:**  The motor is running. Speed is decreasing.

**eLON\_MOTOR\_STOPPING:**  The motor is running, beginning its shutdown sequence.

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_LON from 3.3.4.0 |
