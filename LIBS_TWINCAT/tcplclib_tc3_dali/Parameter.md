# Parameter

## Library
tcplclib_tc3_dali

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc3\_DALI](ms-xhelp:///?Id=beckhoff-3b50-4f78-8721-86f9c15e9bec)
2. [Programming](ms-xhelp:///?Id=beckhoff-b5e2-4347-b4c8-164a6e6f2543)
3. [GVLs](ms-xhelp:///?Id=beckhoff-1185-4c64-83e3-d3005d948f41)
4. Parameter

# Parameter

```
VAR_GLOBAL CONSTANT  
  cTimeoutTerminalResponse         : TIME := T#500MS;  
  cTimeoutSlaveResponse            : TIME := T#80MS;  
  cTimeoutResponseTable            : TIME := T#30S;  
  cTimeoutInitializeTerminal       : TIME := T#5S;  
  cTimeoutAddressing               : TIME := T#3M;  
  cTimeoutTransaction              : TIME := T#1M;  
  cMaxCommandBufferEntries         : USINT := 120;  
  cMaxResponseTableEntries         : USINT := 120;  
  cMaxEventTableEntries            : USINT := 20;  
END_VAR
```

The library contains some parameters which can be used to change general library settings. The parameter list can be accessed via the Library Manager. The values of the individual parameters can also be adjusted there.

Note

Note that some parameters have a profound effect on the way the library works.

![30668413](/tcplclib_tc3_dali/1033/Images/png/18014404504455179__Web.png)

[TwinCAT 3 | PLC Library: Tc3\_DALI](ms-xhelp:///?Id=beckhoff-3b50-4f78-8721-86f9c15e9bec)
