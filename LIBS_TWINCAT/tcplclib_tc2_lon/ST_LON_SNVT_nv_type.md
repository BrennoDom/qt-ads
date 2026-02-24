# ST_LON_SNVT_nv_type

## Library
tcplclib_tc2_lon

## Category
Motion Control

# ST\_LON\_SNVT\_nv\_type

Used by: SNVT\_nv\_type

```
TYPE ST_LON_SNVT_nv_type :  
STRUCT  
  arrType_program_ID : ARRAY[0..7] OF BYTE;  
  byType_scope       : BYTE;  
  uiType_index       : UINT;  
  eType_category     : E_LON_nv_type_category_t;  
  byType_length      : BYTE;  
  iScaling_factor_a  : INT;  
  iScaling_factor_b  : INT;  
  iScaling_factor_c  : INT;  
END_STRUCT  
END_TYPE
```

**arrType\_program\_ID:** Min: 0 / Max: 255 / Type program ID. Program ID template of the resource file containing the network variable type definition.

**byType\_scope:** Min: 0 / Max: 6 / Type scope (file scope). Scope of the resource file containing the network variable type definition.

**uiType\_index:** Min: 1 / Max: 65535 / Type index (type index). Index within the specified resource file of the network variable type definition.

**eType\_category:** Type category (type category names) (see [E\_LON\_nv\_type\_category\_t](ms-xhelp:///?Id=beckhoff-34c2-497e-a214-114bdadcec57)). Type category of the network variable type.

**byType\_length:** Min: 1 / Max: 31 / Type length (bytes). Length of the network variable type

**iScaling\_factor\_a:** Min: -32768 / Max: 32767 / Scaling factor a. Scaling multiplier 'a' where ScaledValue = a\*(10\*\*b)\*(RawValue+c)

**iScaling\_factor\_b:** Min: -32768 / Max: 32767 / Scaling factor b. Exponent 'b' where ScaledValue = a\*(10\*\*b)\*(RawValue+c)

**iScaling\_factor\_c:** Min: -32768 / Max: 32767 / Scaling Factor c. Offset 'c' where ScaledValue = a\*(10\*\*b)\*(RawValue+c)

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_LON from 3.3.4.0 |
