# E_LON_config_source_t

## Library
tcplclib_tc2_lon

## Category
Motion Control

# E\_LON\_config\_source\_t

Used by: SNVT\_config\_src

```
TYPE E_LON_config_source_t :  
(  
  eLON_CFG_NUL      := -1,  
  eLON_CFG_LOCAL    := 0,  
  eLON_CFG_EXTERNAL := 1  
)  
END_TYPE
```

**eLON\_CFG\_NUL:**  Invalid Value

**eLON\_CFG\_LOCAL:**  Device will use self-installation functions to set its own network image

**eLON\_CFG\_EXTERNAL:**  Device's network image will be set by an outside source

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_LON from 3.3.4.0 |
