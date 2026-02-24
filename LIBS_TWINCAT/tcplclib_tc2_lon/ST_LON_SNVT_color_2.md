# ST_LON_SNVT_color_2

## Library
tcplclib_tc2_lon

## Category
Motion Control

# ST\_LON\_SNVT\_color\_2

Used by: SNVT\_color\_2

```
TYPE ST_LON_SNVT_color_2 :  
STRUCT  
  eEncoding     : E_LON_color_encoding_t;  
  stColor_value : ST_LON_color_value;  
END_STRUCT  
END_TYPE
```

**eEncoding:** Color encoding. Color encoding specified by the color\_value union; additional encodings may be added (see [E\_LON\_color\_encoding\_t](ms-xhelp:///?Id=beckhoff-45d8-453e-b8d0-3d26ef8652ea)).

**stColor\_value:** Color value. Color value encoded as specified by the encoding field (see [ST\_LON\_color\_value](ms-xhelp:///?Id=beckhoff-ad53-429e-a302-b3884215bd84)).

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_LON from 3.3.4.0 |
