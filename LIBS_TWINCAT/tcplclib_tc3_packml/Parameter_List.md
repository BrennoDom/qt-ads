# Parameter List

## Library
tcplclib_tc3_packml

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc3\_PackML](ms-xhelp:///?Id=beckhoff-59be-4392-80fb-0b021151334d)
2. [Packaging Machine Functional Tag Description](ms-xhelp:///?Id=beckhoff-cfa1-4cf2-bed5-de71541a6707)
3. Parameter List

# Parameter List

Parameter for the Packaging Machine Tag Structures. While inserting the library they can be customized for the current project.

```
(* PMLc / PMLs *)  
iMAX_NODE_PARAMS               : INT := 10  
iMAX_NODES                     : INT := 10  
iMAX_PROCESS_VARS              : INT := 10  
iMAX_PROD_PROCESS_VARS         : INT := 10  
iMAX_INGREDIENT_PARAMS         : INT := 10  
iMAX_INGREDIENT                : INT := 10  
iMAX_LIMITS                    : INT := 10  
iMAX_PRODUCTS                  : INT := 10  
  
(* PMLa *)  
iMAX_ALARMS                    : INT := 10  
iMAX_CURR_NODE_IDS             : INT := 10
```

## Requirements

| Development environment | Target system type | PLC libraries to be linked |
| --- | --- | --- |
| TwinCAT v3.1, build 4018 onwards | PC (i386) | Tc3\_PackML |

[TwinCAT 3 | PLC Library: Tc3\_PackML](ms-xhelp:///?Id=beckhoff-59be-4392-80fb-0b021151334d)
