# ST_LON_pump_ctrl3

## Library
tcplclib_tc2_lon

## Category
Motion Control

# ST\_LON\_pump\_ctrl3

Used by: SNVT\_dev\_status

```
TYPE ST_LON_pump_ctrl3 :  
STRUCT  
  bDevice_fault       : BOOL;  
  bSupply_fault       : BOOL;  
  bReserved1_2        : BOOL;  
  bSpeed_low          : BOOL;  
  bSpeed_high         : BOOL;  
  bReserved1_5        : BOOL;  
  bSetpt_Out_of_range : BOOL;  
  bReserved1_7        : BOOL;  
  bLocal_control      : BOOL;  
  bReserved2_1        : BOOL;  
  bRunning            : BOOL;  
  bReserved2_3        : BOOL;  
  bRemote_press       : BOOL;  
  bRemote_flow        : BOOL;  
  bRemote_temp        : BOOL;  
  bReserved2_7        : BOOL;  
  byReserved3_0_7     : BYTE;  
END_STRUCT  
END_TYPE
```

**bDevice\_fault:** Pump controller fault (boolean). See SNVT\_pump\_fault network variable declaration on device

**bSupply\_fault:** Supply fault (boolean). No electrical power, no fluid in pump, etc. See SNVT\_pump\_fault network variable declaration on device.

**bReserved1\_2:**

**bSpeed\_low:** Low-speed limit of pump (boolean). Pump is running at the lowest possible speed, therefore the requested performance is not possible.

**bSpeed\_high:** High-speed limit of pump (boolean). Pump is running at the highest possible speed, therefore the requested performance is not possible.

**bReserved1\_5:**

**bSetpt\_Out\_of\_range:** Setpoint out of range (boolean). Chosen override setpoint value is lower than the manufacturer-defined low-setpoint limit or higher than the manufacturer-defined high-setpoint limit.

**bReserved1\_7:**

**bLocal\_control:** Locally controlled pump (boolean). Pump is locally operated (hardware override)

**bReserved2\_1:**

**bRunning:** Running pump (boolean). Pump is presently running

**bReserved2\_3:**

**bRemote\_press:** Remote pressure sensor (boolean). Pump controller is using a remote pressure sensor

**bRemote\_flow:** Remote flow sensor (boolean). Pump controller is using a remote flow sensor

**bRemote\_temp:** Remote temperature sensor (boolean). Pump controller is using a remote temperature sensor

**bReserved2\_7:**

**byReserved3\_0\_7:**

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_LON from 3.3.4.0 |
