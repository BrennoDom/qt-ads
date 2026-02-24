# E_EnOceanRotarySwitch

## Library
tcplclib_tc2_enocean

## Category
Motion Control

# E\_EnOceanRotarySwitch

*E\_EnOceanRotarySwitch* describes the position of the rotary switch at the room control unit.

```
TYPE E_EnOceanRotarySwitch :  
(  
  eEnOceanRotarySwitchStep0 := 0,  
  eEnOceanRotarySwitchStep1 := 1,  
  eEnOceanRotarySwitchStep2 := 2,  
  eEnOceanRotarySwitchStep3 := 3,  
  eEnOceanRotarySwitchAuto  := 4  
)  
END_TYPE
```

**eEnOceanRotarySwitchStep0:** Switch in position “0”.

**eEnOceanRotarySwitchStep1:** Switch in position “1”.

**eEnOceanRotarySwitchStep2:** Switch in position “2”.

**eEnOceanRotarySwitchStep3:** Switch in position “3”.

**eEnOceanRotarySwitchAuto:** Switch in posture “Auto”.

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT v3.1.4020.14 | Tc2\_EnOcean from v3.3.5.0 |
