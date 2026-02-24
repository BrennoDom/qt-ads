# E_LON_privacyzone_t

## Library
tcplclib_tc2_lon

## Category
Motion Control

# E\_LON\_privacyzone\_t

Used by: SNVT\_privacyzone

```
TYPE E_LON_privacyzone_t :  
(  
  eLON_PZ_NUL         := -1,  
  eLON_PZ_DISABLE     := 0,  
  eLON_PZ_ENABLE      := 1,  
  eLON_PZ_UPPER_LEFT  := 2,  
  eLON_PZ_LOWER_RIGHT := 3,  
  eLON_PZ_ENTER       := 4,  
  eLON_PZ_EXIT        := 5  
)  
END_TYPE
```

**eLON\_PZ\_NUL:**  Invalid value

**eLON\_PZ\_DISABLE:**  Disable privacy zone warning

**eLON\_PZ\_ENABLE:**  Enable privacy zone warning

**eLON\_PZ\_UPPER\_LEFT:**  Set upper left corner

**eLON\_PZ\_LOWER\_RIGHT:**  Set lower right corner

**eLON\_PZ\_ENTER:**  Privacy zone enter warning

**eLON\_PZ\_EXIT:**  Privacy zone exit message

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_LON from 3.3.4.0 |
