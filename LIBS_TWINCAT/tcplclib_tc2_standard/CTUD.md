# CTUD

## Library
tcplclib_tc2_standard

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_Standard](ms-xhelp:///?Id=beckhoff-498a-4e2c-a861-2ffa4b1740a3)
2. [Function blocks](ms-xhelp:///?Id=beckhoff-e7be-4338-8e06-ae5851914a22)
3. [Counter](ms-xhelp:///?Id=beckhoff-1611-40f4-89ba-11582e37e522)
4. CTUD

# CTUD

![29858833](/tcplclib_tc2_standard/1033/Images/png/74448523__Web.png)

Incrementer and Decrementer

## VAR\_INPUT

```
VAR_INPUT  
    CU    : BOOL; (* Count Up *)  
    CD    : BOOL; (* Count Down *)  
    RESET : BOOL; (* Reset Counter to Null *)  
    LOAD  : BOOL; (* Load Start Value *)   
    PV    : WORD; (* Start Value / Counter Limit *)  
END_VAR
```

## VAR\_OUTPUT

```
VAR_OUTPUT  
    QU : BOOL; (* Counter reached Limit *)  
    QD : BOOL; (* Counter reached Null *)  
    CV : WORD; (* Current Counter Value *)  
END_VAR
```

If RESET is valid, the counter variable CV will be initialized with 0. If LOAD is valid, CV will be initialized with PV. If CU has a rising edge from FALSE to TRUE, CV will be raised by 1 pro-vided CV does not cause an overflow. If CD has a rising edge from FALSE to TRUE, CV will be lowered by 1 provided this does not cause the value to fall below 0.QU returns TRUE when CV has become greater than or equal to PV. QD returns TRUE when CV has become less than or equal to 0.

## Requirements

| Development environment | Target system type | PLC libraries to be linked |
| --- | --- | --- |
| TwinCAT v3.0.0 | PC or CX (x86) | Tc2\_Standard |

[TwinCAT 3 | PLC Library: Tc2\_Standard](ms-xhelp:///?Id=beckhoff-498a-4e2c-a861-2ffa4b1740a3)
