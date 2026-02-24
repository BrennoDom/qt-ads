# ST_LON_valve_pos3

## Library
tcplclib_tc2_lon

## Category
Motion Control

# ST\_LON\_valve\_pos3

Used by: SNVT\_dev\_status

```
TYPE ST_LON_valve_pos3 :  
STRUCT  
  bRunning            : BOOL;  
  bAdapting           : BOOL;  
  bInitializing       : BOOL;  
  bLocal_control      : BOOL;  
  bSetpt_Out_of_range : BOOL;  
  bRemote_ctrl_signal : BOOL;  
  byReserved1_6_7     : BYTE;  
  bHw_emergency       : BOOL;  
  bSw_emergency       : BOOL;  
  byReserved2_2_7     : BYTE;  
  byReserved3_0_7     : BYTE;  
END_STRUCT  
END_TYPE
```

**bRunning:** Valve Running. Valve is presently being positioned.

**bAdapting:** Adapting. Valve is presently adapting.

**bInitializing:** Initializing. Valve is presently initializing.

**bLocal\_control:** Local Control. The valve operation is being locally controlled.

**bSetpt\_Out\_of\_range:** Setpoint out of range. Chosen override setpoint value is lower than the manufacturer-defined low-setpoint limit or higher than the manufacturer-defined high-setpoint limit.

**bRemote\_ctrl\_signal:** Remote Control Signal. The remote-control signal is active.

**byReserved1\_6\_7:** This field is reserved.. This field is reserved.

**bHw\_emergency:** Hardware Emergency. The hardware-emergency state is active

**bSw\_emergency:** Software Emergency. The software-emergency state is active

**byReserved2\_2\_7:** This field is reserved.. This field is reserved.

**byReserved3\_0\_7:** This field is reserved.. This field is reserved.

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_LON from 3.3.4.0 |
