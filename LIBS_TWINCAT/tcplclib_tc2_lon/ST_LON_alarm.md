# ST_LON_alarm

## Library
tcplclib_tc2_lon

## Category
Motion Control

# ST\_LON\_alarm

Used by: SNVT\_clothes\_w\_s

```
TYPE ST_LON_alarm :  
STRUCT  
  bAlarm_reset         : BOOL;  
  bWar_water_supply    : BOOL;  
  bWar_drain_slow      : BOOL;  
  bWar_door_open       : BOOL;  
  bWar_load_unbalanced : BOOL;  
  bWar_filter_cleaning : BOOL;  
  bWar_hoses_reversed  : BOOL;  
  bWar_voltage_low     : BOOL;  
  bWar_power_failure   : BOOL;  
  bWar_drain_open      : BOOL;  
  bWar_execute_fail    : BOOL;  
  bWar_door_locked     : BOOL;  
  bWar_service         : BOOL;  
  bWar_rsrvd5          : BOOL;  
  bWar_rsrvd6          : BOOL;  
  bWar_rsrvd7          : BOOL;  
  bErr_motor_stall     : BOOL;  
  bErr_water_temp      : BOOL;  
  bErr_pressure        : BOOL;  
  bErr_overflow        : BOOL;  
  bErr_water_heat      : BOOL;  
  bErr_water_leak      : BOOL;  
  bErr_motor_speed     : BOOL;  
  bErr_wash_thermistor : BOOL;  
  bErr_dry_thermistor  : BOOL;  
  bErr_dry_overheat    : BOOL;  
  bErr_dry_heating     : BOOL;  
  bErr_dry_fan         : BOOL;  
  bErr_rsrvd4          : BOOL;  
  bErr_rsrvd5          : BOOL;  
  bErr_rsrvd6          : BOOL;  
  bErr_rsrvd7          : BOOL;  
  byErr_rsrvd0_7       : BYTE;  
  byErr_manuf_code     : BYTE;  
END_STRUCT  
END_TYPE
```

**bAlarm\_reset:**

**bWar\_water\_supply:**

**bWar\_drain\_slow:**

**bWar\_door\_open:**

**bWar\_load\_unbalanced:**

**bWar\_filter\_cleaning:**

**bWar\_hoses\_reversed:**

**bWar\_voltage\_low:**

**bWar\_power\_failure:**

**bWar\_drain\_open:**

**bWar\_execute\_fail:**

**bWar\_door\_locked:**

**bWar\_service:**

**bWar\_rsrvd5:**

**bWar\_rsrvd6:**

**bWar\_rsrvd7:**

**bErr\_motor\_stall:**

**bErr\_water\_temp:**

**bErr\_pressure:**

**bErr\_overflow:**

**bErr\_water\_heat:**

**bErr\_water\_leak:**

**bErr\_motor\_speed:**

**bErr\_wash\_thermistor:**

**bErr\_dry\_thermistor:**

**bErr\_dry\_overheat:**

**bErr\_dry\_heating:**

**bErr\_dry\_fan:**

**bErr\_rsrvd4:**

**bErr\_rsrvd5:**

**bErr\_rsrvd6:**

**bErr\_rsrvd7:**

**byErr\_rsrvd0\_7:**

**byErr\_manuf\_code:** Min: 0 / Max: 255

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_LON from 3.3.4.0 |
