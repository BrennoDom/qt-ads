# ST_LON_SNVT_trans_table

## Library
tcplclib_tc2_lon

## Category
Motion Control

# ST\_LON\_SNVT\_trans\_table

Used by: SNVT\_trans\_table

```
TYPE ST_LON_SNVT_trans_table :  
STRUCT  
  arrPoint            : ARRAY[0..6] OF REAL;  
  byInterp_pts_0_to_1 : BYTE;  
  byInterp_pts_1_to_2 : BYTE;  
  byInterp_pts_2_to_3 : BYTE;  
  byInterp_pts_3_to_4 : BYTE;  
  byInterp_pts_4_to_5 : BYTE;  
  byInterp_pts_5_to_6 : BYTE;  
  byInterp_pts_6_to_0 : BYTE;  
END_STRUCT  
END_TYPE
```

**arrPoint:** Points (array of 7 points).

**byInterp\_pts\_0\_to\_1:** Min: 0 / Max: 1 / Interpolation for point 0 to point 1 (interpolation method code).

**byInterp\_pts\_1\_to\_2:** Min: 0 / Max: 1 / Interpolation for point 1 to point 2 (interpolation method code).

**byInterp\_pts\_2\_to\_3:** Min: 0 / Max: 1 / Interpolation for point 2 to point 3 (interpolation method code).

**byInterp\_pts\_3\_to\_4:** Min: 0 / Max: 1 / Interpolation for point 3 to point 4 (interpolation method code).

**byInterp\_pts\_4\_to\_5:** Min: 0 / Max: 1 / Interpolation for point 4 to point 5 (interpolation method code).

**byInterp\_pts\_5\_to\_6:** Min: 0 / Max: 1 / Interpolation for point 5 to point 6 (interpolation method code).

**byInterp\_pts\_6\_to\_0:** Min: 0 / Max: 1 / Interpolation for point 6 to point 0 (interpolation method code). This field is used when multiple interpolation tables are linked.

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_LON from 3.3.4.0 |
