# E_LON_unit_temp_t

## Library
tcplclib_tc2_lon

## Category
Motion Control

# E\_LON\_unit\_temp\_t

Used by: SNVT\_pump\_sensor

```
TYPE E_LON_unit_temp_t :  
(  
  eLON_TEMP_NUL        := -1,  
  eLON_TEMP_INACTIVE   := 0,  
  eLON_TEMP_AT_DESIRED := 1,  
  eLON_TEMP_TOO_HOT    := 2,  
  eLON_TEMP_TOO_COLD   := 3  
)  
END_TYPE
```

**eLON\_TEMP\_NUL:**  The status of the apparatus or unit is unknown, or not applicable (Invalid Value).

**eLON\_TEMP\_INACTIVE:**  The temperature-sensing apparatus is present, but not currently operating.

**eLON\_TEMP\_AT\_DESIRED:**  The unit temperature is within the desired range.

**eLON\_TEMP\_TOO\_HOT:**  The unit temperature is above the upper limit of the desired range.

**eLON\_TEMP\_TOO\_COLD:**  The unit temperature is below the lower limit of the desired range.

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_LON from 3.3.4.0 |
