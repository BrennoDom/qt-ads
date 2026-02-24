# E_CurMachSpd

## Library
tcplclib_tc3_packml

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc3\_PackML](ms-xhelp:///?Id=beckhoff-59be-4392-80fb-0b021151334d)
2. [Packaging Machine Functional Tag Description](ms-xhelp:///?Id=beckhoff-cfa1-4cf2-bed5-de71541a6707)
3. [DataTypes](ms-xhelp:///?Id=beckhoff-9ab3-480d-a692-669d690fad49)
4. [Common](ms-xhelp:///?Id=beckhoff-b1fd-4f94-a947-c1aa38112b6b)
5. E\_CurMachSpd

# E\_CurMachSpd

Enumeration to define different machine speeds

```
TYPE E_CurMachSpd :   
(  
    eCurMachSpd_UNDEFINED,  
    eCurMachSpd_JOG,  
    eCurMachSpd_PRIME,  
    eCurMachSpd_PRELUBE,  
    eCurMachSpd_MAINTENANCE,  
    eCurMachSpd_SLOW,  
    eCurMachSpd_MEDIUM,  
    eCurMachSpd_HIGH,  
    eCurMachSpd_SURGE,  
    eCurMachSpd_TRACKING,  
    eCurMachSpd_ANALOG_CTRL_ONLY := 99  
);  
END_TYPE
```

## Requirements

| Development environment | Target system type | PLC libraries to be linked |
| --- | --- | --- |
| TwinCAT v3.1, build 4018 onwards | PC (i386) | Tc3\_PackML |

[TwinCAT 3 | PLC Library: Tc3\_PackML](ms-xhelp:///?Id=beckhoff-59be-4392-80fb-0b021151334d)
