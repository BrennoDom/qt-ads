# Global parameters

## Library
tcplclib_tc3_packml_v2

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc3\_PackML\_V2](ms-xhelp:///?Id=beckhoff-962e-4424-bd3f-3a66f7e32e10)
2. [Packaging Machine Tags](ms-xhelp:///?Id=beckhoff-0c75-4616-a6ff-b521c2c6af13)
3. Global parameters

# Global parameters

Parameters for the construction of the packaging machine tag structures. These can be adapted when inserting the library for the current project.

```
(* PMLc / PMLs *)  
    MaxInterfaceParameter          : INT := 5  
    MaxProductProcessVariables     : INT := 10  
    MaxIngredients                 : INT := 10  
    MaxIngredientParameters        : INT := 10  
  
(* PMLc *)  
    MaxCommandRemoteInterfaces     : INT := 2  
    MaxCommandParameters           : INT := 10  
    MaxCommandProducts             : INT := 5  
  
(* PMLs *)  
    MaxStatusRemoteInterfaces      : INT := 2  
    MaxStatusParameters            : INT := 10  
    MaxStatusProducts              : INT := 5  
  
(* PMLa *)  
    MaxAdminParameters             : INT := 10  
    MaxAlarms                      : INT := 10  
    MaxHistoryAlarms               : INT := 10  
    MaxStopReasons                 : INT := 10  
    MaxWarnings                    : INT := 10  
    MaxConsumedCounts              : INT := 10  
    MaxProductCounts               : INT := 10
```

## Requirements

| Development environment | Target system type | PLC libraries to include |
| --- | --- | --- |
| TwinCAT v3.1 Build 4018 and higher | PC (i386) | Tc3\_PackML\_V2 |

[TwinCAT 3 | PLC Library: Tc3\_PackML\_V2](ms-xhelp:///?Id=beckhoff-962e-4424-bd3f-3a66f7e32e10)
