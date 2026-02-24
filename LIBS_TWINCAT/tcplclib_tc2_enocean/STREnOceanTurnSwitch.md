# STREnOceanTurnSwitch

## Library
tcplclib_tc2_enocean

## Category
Motion Control

# STREnOceanTurnSwitch

*STREnOceanTurnSwitch* describes the position of the rotary switch at the room control unit.

```
TYPE STREnOceanTurnSwitch :  
STRUCT  
  bStageAuto : BOOL;  
  bStage_0   : BOOL;  
  bStage_1   : BOOL;  
  bStage_2   : BOOL;  
  bStage_3   : BOOL;  
END_STRUCT  
END_TYPE
```

**bStageAuto:** Switch in posture “Auto”.

**bStage\_0:** Switch in position “0”.

**bStage\_1:** Switch in position “1”.

**bStage\_2:** Switch in position “2”.

**bStage\_3:** Switch in position “3”.

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT v3.1.4020.14 | Tc2\_EnOcean from v3.3.5.0 |
