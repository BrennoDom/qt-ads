# E_LON_scene_config_t

## Library
tcplclib_tc2_lon

## Category
Motion Control

# E\_LON\_scene\_config\_t

Used by: SNVT\_scene\_cfg

```
TYPE E_LON_scene_config_t :  
(  
  eLON_SCF_NUL    := -1,  
  eLON_SCF_SAVE   := 0,  
  eLON_SCF_CLEAR  := 1,  
  eLON_SCF_REPORT := 2,  
  eLON_SCF_SIZE   := 3,  
  eLON_SCF_FREE   := 4  
)  
END_TYPE
```

**eLON\_SCF\_NUL:**  Invalid Value

**eLON\_SCF\_SAVE:**  Overwrite this scene with new data

**eLON\_SCF\_CLEAR:**  Delete this scene from the list

**eLON\_SCF\_REPORT:**  Display this scene's data

**eLON\_SCF\_SIZE:**  Report the number of programmed scenes

**eLON\_SCF\_FREE:**  Report the number of free scene storage spaces

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_LON from 3.3.4.0 |
