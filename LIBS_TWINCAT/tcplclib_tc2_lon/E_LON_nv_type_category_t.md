# E_LON_nv_type_category_t

## Library
tcplclib_tc2_lon

## Category
Motion Control

# E\_LON\_nv\_type\_category\_t

Used by: SNVT\_nv\_type

```
TYPE E_LON_nv_type_category_t :  
(  
  eLON_NVT_CAT_NUL            := -1,  
  eLON_NVT_CAT_INITIAL        := 0,  
  eLON_NVT_CAT_SIGNED_CHAR    := 1,  
  eLON_NVT_CAT_UNSIGNED_CHAR  := 2,  
  eLON_NVT_CAT_SIGNED_SHORT   := 3,  
  eLON_NVT_CAT_UNSIGNED_SHORT := 4,  
  eLON_NVT_CAT_SIGNED_LONG    := 5,  
  eLON_NVT_CAT_UNSIGNED_LONG  := 6,  
  eLON_NVT_CAT_ENUM           := 7,  
  eLON_NVT_CAT_ARRAY          := 8,  
  eLON_NVT_CAT_STRUCT         := 9,  
  eLON_NVT_CAT_UNION          := 10,  
  eLON_NVT_CAT_BITFIELD       := 11,  
  eLON_NVT_CAT_FLOAT          := 12,  
  eLON_NVT_CAT_SIGNED_QUAD    := 13,  
  eLON_NVT_CAT_REFERENCE      := 14  
)  
END_TYPE
```

**eLON\_NVT\_CAT\_NUL:**  Invalid Value

**eLON\_NVT\_CAT\_INITIAL:**

**eLON\_NVT\_CAT\_SIGNED\_CHAR:**  8-bit signed character

**eLON\_NVT\_CAT\_UNSIGNED\_CHAR:**  8-bit unsigned character

**eLON\_NVT\_CAT\_SIGNED\_SHORT:**  8-bit signed integer

**eLON\_NVT\_CAT\_UNSIGNED\_SHORT:**  8-bit unsigned integer

**eLON\_NVT\_CAT\_SIGNED\_LONG:**  16-bit signed integer

**eLON\_NVT\_CAT\_UNSIGNED\_LONG:**  16-bit unsigned integer

**eLON\_NVT\_CAT\_ENUM:**  8-bit enumeration

**eLON\_NVT\_CAT\_ARRAY:**  Array

**eLON\_NVT\_CAT\_STRUCT:**  Structure

**eLON\_NVT\_CAT\_UNION:**  Union

**eLON\_NVT\_CAT\_BITFIELD:**  Bitfield

**eLON\_NVT\_CAT\_FLOAT:**  32-bit IEC 60559 (IEEE 754) floating-point value

**eLON\_NVT\_CAT\_SIGNED\_QUAD:**  32-bit signed integer

**eLON\_NVT\_CAT\_REFERENCE:**  Reference type

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_LON from 3.3.4.0 |
