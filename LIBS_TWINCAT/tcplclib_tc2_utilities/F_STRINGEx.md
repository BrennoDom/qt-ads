# F_STRINGEx

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# F\_STRINGEx

Help function that returns a structure with information (type: [T\_Arg](ms-xhelp:///?Id=beckhoff-9414-4e02-83ee-fc21ca340682)) about a STRING variable. Unlike the [F\_STRING](ms-xhelp:///?Id=beckhoff-6a77-44ce-a6fc-70c776b2fd5a) function, the length of the transferred STRING variable is arbitrary.

## FUNCTION F\_STRINGEx : T\_Arg

## VAR\_IN\_OUT

```
VAR_IN_OUT CONSTANT  
    in : STRING;  
END_VAR
```

## Requirements

| Development environment | Target platform | PLC libraries to be integrated (category group) |
| --- | --- | --- |
| TwinCAT v3.1.4022 | PC or CX (x86, x64, ARM) | Tc2\_Utilities (System) >= v3.3.34.0 |
