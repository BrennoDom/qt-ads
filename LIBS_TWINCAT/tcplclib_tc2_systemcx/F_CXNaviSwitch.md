# F_CXNaviSwitch

## Library
tcplclib_tc2_systemcx

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_SystemCX](ms-xhelp:///?Id=beckhoff-b6aa-4d30-a149-d8e2b64ec5d0)
2. [Functions](ms-xhelp:///?Id=beckhoff-48c8-4ac6-bc46-6e026efec7f3)
3. F\_CXNaviSwitch

# F\_CXNaviSwitch

![26298136](/tcplclib_tc2_systemcx/1033/Images/png/9007199440682763__Web.png)

The function F\_CXNaviSwitch converts the value of the CX1100 navigation switch into an enum value of type E\_CX1100\_NaviSwitch.

## FUNCTION F\_CXNaviSwitch: E\_CX1100\_NaviSwitch

```
VAR_INPUT  
    iCX1100_IN : USINT  
END_VAR
```

**E\_CX1100\_NaviSwitch**: Value of the CX1100 input 'IN'

## E**num** E\_CX1100\_NaviSwitch

```
TYPE E_CX1100_NaviSwitch : (  
    e_CX1100_NaviSwitch_IDLE := 0,  
    e_CX1100_NaviSwitch_MIDDLE := 16,  
  
    (* clockwise in 45 degree steps *)  
    e_CX1100_NaviSwitch_TOP := 1,  
    e_CX1100_NaviSwitch_TOPRIGHT := 9,  
    e_CX1100_NaviSwitch_RIGHT := 8,  
    e_CX1100_NaviSwitch_BOTTOMRIGHT := 10,  
    e_CX1100_NaviSwitch_BOTTOM := 2,  
    e_CX1100_NaviSwitch_BOTTOMLEFT := 6,  
    e_CX1100_NaviSwitch_LEFT := 4,  
    e_CX1100_NaviSwitch_TOPLEFT := 5,  
  
    (* clockwise in 45 degree steps with middle switch pressed *)  
    e_CX1100_NaviSwitch_MIDDLE_TOP := 17,  
    e_CX1100_NaviSwitch_MIDDLE_TOPRIGHT := 25,  
    e_CX1100_NaviSwitch_MIDDLE_RIGHT := 24,  
    e_CX1100_NaviSwitch_MIDDLE_BOTTOMRIGHT := 26,  
    e_CX1100_NaviSwitch_MIDDLE_BOTTOM := 18,  
    e_CX1100_NaviSwitch_MIDDLE_BOTTOMLEFT := 22,  
    e_CX1100_NaviSwitch_MIDDLE_LEFT := 20,  
    e_CX1100_NaviSwitch_MIDDLE_TOPLEFT := 21  
END_VAR 
```

Values other than those defined in enum (e.g. 11) are displayed as "\*\*\* INVALID: value \*\*\*" in online mode (e.g. "\*\*\* INVALID: 11 \*\*\*"). The function F\_CXNaviSwitch then returns the invalid value (e.g. 11).

## Requirements

| Development environment | Target platform | PLC libraries to include |
| --- | --- | --- |
| TwinCAT v3.1.0 | CX (x86) | Tc2\_SystemCX |

[TwinCAT 3 | PLC Library: Tc2\_SystemCX](ms-xhelp:///?Id=beckhoff-b6aa-4d30-a149-d8e2b64ec5d0)
