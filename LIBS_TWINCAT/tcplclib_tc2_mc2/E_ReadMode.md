# E_ReadMode

## Library
tcplclib_tc2_mc2

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_MC2](ms-xhelp:///?Id=beckhoff-63a7-4c0e-8569-314547c8cffc)
2. [Data types](ms-xhelp:///?Id=beckhoff-683b-4615-8584-914eb091e041)
3. [Status and parameter](ms-xhelp:///?Id=beckhoff-a949-4038-af4c-900da2b41d28)
4. E\_ReadMode

# E\_ReadMode

This data type is used in conjunction with the function blocks [MC\_ReadParameter](ms-xhelp:///?Id=beckhoff-638b-4828-b4a1-530fffab7a85) and [MC\_ReadBoolParameter](ms-xhelp:///?Id=beckhoff-c7c6-47de-bf44-0da5d62370d1) to specify a single or cyclic operation.

```
TYPE E_ReadMode :  
(  
    READMODE_ONCE := 1,  
    READMODE_CYCLIC  
);  
END_TYPE
```

## Requirements

| Development environment | Target system type | PLC libraries to include |
| --- | --- | --- |
| TwinCAT v3.0.0 | PC or CX (x86 or x64) | Tc2\_MC2 |

[TwinCAT 3 | PLC Library: Tc2\_MC2](ms-xhelp:///?Id=beckhoff-63a7-4c0e-8569-314547c8cffc)
