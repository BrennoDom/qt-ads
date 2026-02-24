# ST_LON_SNVT_clothes_w_m

## Library
tcplclib_tc2_lon

## Category
Motion Control

# ST\_LON\_SNVT\_clothes\_w\_m

Used by: SNVT\_clothes\_w\_m

```
TYPE ST_LON_SNVT_clothes_w_m :  
STRUCT  
  bDoor_ajar : BOOL;  
  bDrain_on  : BOOL;  
  byReserved : BYTE;  
END_STRUCT  
END_TYPE
```

**bDoor\_ajar:** Door/Lid Ajar. The door/lid of the washer is not fully closed.

**bDrain\_on:** Drain On.The drain is on.

**byReserved:** Reserve.

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_LON from 3.3.4.0 |
