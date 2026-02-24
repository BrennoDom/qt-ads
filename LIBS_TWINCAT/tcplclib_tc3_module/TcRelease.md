# TcRelease

## Library
tcplclib_tc3_module

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc3\_Module](ms-xhelp:///?Id=beckhoff-bcd3-40fe-aa49-602b4cdc62b7)
2. [Function blocks](ms-xhelp:///?Id=beckhoff-c8bb-4182-8afb-4dae11b93466)
3. [TcBaseModuleRegistered](ms-xhelp:///?Id=beckhoff-f3ea-41a6-b69c-7e7d3c1e0a59)
4. TcRelease

# TcRelease

![19388612](/tcplclib_tc3_module/1033/Images/png/1902020619__Web.png)

The TcRelease() method decrements the reference counter and returns the new value. If the reference counter is 0, the object deletes itself.

## Interface

**Parameter**

```
VAR_INPUT  
    (*none*)  
END_VAR
```

**Return value**

```
VAR_OUTPUT  
    TcRelease : UDINT;  
END_VAR
```

The resulting reference count value is returned.

## Requirements

| TwinCAT Version | Hardware | Libraries to be integrated |
| --- | --- | --- |
| TwinCAT 3.1, Build 4020 | x86, x64, ARM | Tc3\_Module |

[TwinCAT 3 | PLC Library:Tc3\_Module](ms-xhelp:///?Id=beckhoff-bcd3-40fe-aa49-602b4cdc62b7)
