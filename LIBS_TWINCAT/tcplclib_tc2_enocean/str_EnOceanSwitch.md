# str_EnOceanSwitch

## Library
tcplclib_tc2_enocean

## Category
Motion Control

# str\_EnOceanSwitch

State of the buttons.

```
TYPE STR_EnOceanSwitch :  
STRUCT  
  bT1_ON  : BOOL;  
  bT1_OFF : BOOL;  
  bT2_ON  : BOOL;  
  bT2_OFF : BOOL;  
  bT3_ON  : BOOL;  
  bT3_OFF : BOOL;  
  bT4_ON  : BOOL;  
  bT4_OFF : BOOL;  
END_STRUCT  
END_TYPE
```

**bT1\_ON:** Button 1 on.

**bT1\_OFF:** Button 1 off.

**bT2\_ON:** Button 2 on.

**bT2\_OFF:** Button 2 off.

**bT3\_ON:** Button 3 on.

**bT3\_OFF:** Button 3 off.

**bT4\_ON:** Button 4 on.

**bT4\_OFF:** Button 4 off.

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT v3.1.4020.14 | Tc2\_EnOcean from v3.3.5.0 |
