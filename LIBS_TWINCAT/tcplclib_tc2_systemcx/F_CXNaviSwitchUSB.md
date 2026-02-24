# F_CXNaviSwitchUSB

## Library
tcplclib_tc2_systemcx

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_SystemCX](ms-xhelp:///?Id=beckhoff-b6aa-4d30-a149-d8e2b64ec5d0)
2. [Functions](ms-xhelp:///?Id=beckhoff-48c8-4ac6-bc46-6e026efec7f3)
3. F\_CXNaviSwitchUSB

# F\_CXNaviSwitchUSB

![35356632](/tcplclib_tc2_systemcx/1033/Images/png/2242889355__Web.png)

The function F\_CXNaviSwitchUSB converts the value of the CX2100 navigation switch or an EL6090 into an enum value of type E\_CX2100\_NaviSwitch.

## FUNCTION F\_CXNaviSwitchUSB: E\_CX2100\_NaviSwitch

```
VAR_INPUT  
    icx2100_IN : USINT;  
END_VAR
```

**icx2100\_IN**: Value of the CX2100 input 'IN‘

## Enum E\_CX2100\_NaviSwitch

```
TYPE E_CX2100_NaviSwitch : (  
    e_CX2100_NaviSwitch_IDLE  := 0,  
    e_CX2100_NaviSwitch_MIDDLE  := 15,  
    e_CX2100_NaviSwitch_ENTER  := 16,  
    e_CX2100_NaviSwitch_ENTER_MIDDLE  := 31,  
  
    (* clockwise in 45 degree steps, 1-2 switches on *)  
    e_CX2100_NaviSwitch_TOP  := 1,  
    e_CX2100_NaviSwitch_TOPRIGHT  := 9,  
    e_CX2100_NaviSwitch_RIGHT  := 8,  
    e_CX2100_NaviSwitch_BOTTOMRIGHT  := 10,  
    e_CX2100_NaviSwitch_BOTTOM  := 2,  
    e_CX2100_NaviSwitch_BOTTOMLEFT  := 6,  
    e_CX2100_NaviSwitch_LEFT  := 4,  
    e_CX2100_NaviSwitch_TOPLEFT  := 5,  
  
    (* clockwise in 90 degree, 3 switches on*)  
    e_CX2100_NaviSwitch_TOPLEFTRIGHT  := 13,  
    e_CX2100_NaviSwitch_RIGHTTOPBOTTOM  := 11,  
    e_CX2100_NaviSwitch_BOTTOMLEFTRIGHT  := 14,  
    e_CX2100_NaviSwitch_LEFTTOPBOTTOM  := 7,  
  
    (* clockwise in 45 degree steps with enter switch pressed, 1-2 switches on *)  
    e_CX2100_NaviSwitch_ENTER_TOP  := 17,  
    e_CX2100_NaviSwitch_ENTER_TOPRIGHT  := 25,  
    e_CX2100_NaviSwitch_ENTER_RIGHT  := 24,  
    e_CX2100_NaviSwitch_ENTER_BOTTOMRIGHT  := 26,  
    e_CX2100_NaviSwitch_ENTER_BOTTOM  := 18,  
    e_CX2100_NaviSwitch_ENTER_BOTTOMLEFT  := 22,  
    e_CX2100_NaviSwitch_ENTER_LEFT  := 20,  
    e_CX2100_NaviSwitch_ENTER_TOPLEFT  := 21  
  
    (* clockwise in 90 degree steps with enter switch pressed, 3 switches on *)  
    e_CX2100_NaviSwitch_ENTER_TOPLEFTRIGHT  := 29,  
    e_CX2100_NaviSwitch_ENTER_RIGHTTOPBOTTOM  := 27,  
    e_CX2100_NaviSwitch_ENTER_BOTTOMLEFTRIGHT  := 30,  
    e_CX2100_NaviSwitch_ENTER_LEFTTOPBOTTOM  := 23,  
)
```

## Requirements when using the CX2100

| Development environment | Target platform | PLC libraries to include |
| --- | --- | --- |
| TwinCAT v3.1 | CX (WES7/Win7/Win10: TC RT x86/x64, WEC6/7: TC RT x86, TC/BSD: TC RT x64) | Tc2\_SystemCX |

## Requirements when using the EL6090

| Development environment | Target platform | PLC libraries to include |
| --- | --- | --- |
| TwinCAT v3.1 | PC or CX (WES7/Win7/Win10: TC RT x86/x64, WEC6/7: TC RT x86, WEC7: TC CE7 ARMV7, TC/BSD: TC RT x64, TC OS ARMT2) | Tc2\_SystemCX |

[TwinCAT 3 | PLC Library: Tc2\_SystemCX](ms-xhelp:///?Id=beckhoff-b6aa-4d30-a149-d8e2b64ec5d0)
