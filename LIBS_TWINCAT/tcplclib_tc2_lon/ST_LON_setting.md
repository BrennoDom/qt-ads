# ST_LON_setting

## Library
tcplclib_tc2_lon

## Category
Motion Control

# ST\_LON\_setting

Used by: SNVT\_switch\_2

```
TYPE ST_LON_setting :  
STRUCT  
  rValue          : REAL;  
  rChange         : REAL;  
  byDelay         : BYTE;  
  byGroup_number  : BYTE;  
  rMultiplier     : REAL;  
  iAngle          : INT;  
  siFan_level     : SINT;  
  byButton_number : BYTE;  
END_STRUCT  
END_TYPE
```

**rValue:** Min: 0 / Max: 100 / Value. Percent of full level when state is on. Reports last level for outputs when state is off.

**rChange:** Min: 0 / Max: 100 / Percent change. Percent change to level.

**byDelay:** Min: 0 / Max: 255 / On or off delay (seconds) (seconds). Time delay before changing state to on or off.

**byGroup\_number:** Min: 0 / Max: 63 / Group number. Group number that is enabled or disabled by the SW\_ENABLE\_GROUP and SW\_DISABLE\_GROUIP states in the state field; if 0, all groups are enabled or disabled.

**rMultiplier:** Min: 0 / Max: 2.54 / Factor (percent). Multiplier for the level

**iAngle:** Min: -180 / Max: 180 / Rotation angle (degrees). Rotation angle for devices that support a rotation setting such as blinds.

**siFan\_level:** Min: -100 / Max: 100 / Fan level. Percent of full level fan speed when state is on. Reports last fan speed for outputs when state is off. Positive values represent the down direction, and negative values represent the up direction.

**byButton\_number:** Min: 0 / Max: 255 / Button number. The button number to activate when the state field is set to SW\_SET\_BUTTON, no invalid value

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_LON from 3.3.4.0 |
