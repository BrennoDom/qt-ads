# CTD

## Library
tcplclib_tc2_standard

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_Standard](ms-xhelp:///?Id=beckhoff-498a-4e2c-a861-2ffa4b1740a3)
2. [Function blocks](ms-xhelp:///?Id=beckhoff-e7be-4338-8e06-ae5851914a22)
3. [Counter](ms-xhelp:///?Id=beckhoff-1611-40f4-89ba-11582e37e522)
4. CTD

# CTD

![64163473](/tcplclib_tc2_standard/1033/Images/png/74442123__Web.png)

Decrementer

## VAR\_INPUT

```
VAR_INPUT  
   CD   : BOOL; (* Count Down on rising edge *)  
   LOAD : BOOL; (* Load Start Value *)  
   PV   : WORD; (* Start Value *)  
END_VAR
```

## VAR\_OUTPUT

```
VAR_OUTPUT  
    Q  : BOOL; (* Counter reached 0 *)  
    CV : WORD; (* Current Counter Value *)  
END_VAR
```

When LOAD is TRUE, the counter variable CV will be initialized with the upper limit PV. If CD has a rising edge from FALSE to TRUE, CV will be lowered by 1 provided CV is greater than 0 (i.e., it doesn't cause the value to fall below 0).Q returns TRUE when CV is less than or equal to 0.

## Requirements

| Development environment | Target system type | PLC libraries to be linked |
| --- | --- | --- |
| TwinCAT v3.0.0 | PC or CX (x86) | Tc2\_Standard |

[TwinCAT 3 | PLC Library: Tc2\_Standard](ms-xhelp:///?Id=beckhoff-498a-4e2c-a861-2ffa4b1740a3)
