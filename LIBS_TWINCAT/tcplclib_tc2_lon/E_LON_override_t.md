# E_LON_override_t

## Library
tcplclib_tc2_lon

## Category
Motion Control

# E\_LON\_override\_t

Used by: SNVT\_override

```
TYPE E_LON_override_t :  
(  
  eLON_OV_NUL       := -1,  
  eLON_OV_RETAIN    := 0,  
  eLON_OV_SPECIFIED := 1,  
  eLON_OV_DEFAULT   := 2  
)  
END_TYPE
```

**eLON\_OV\_NUL:**  Invalid Value

**eLON\_OV\_RETAIN:**  Retain current level

**eLON\_OV\_SPECIFIED:**  Go to specified level

**eLON\_OV\_DEFAULT:**  Go to default level

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_LON from 3.3.4.0 |
