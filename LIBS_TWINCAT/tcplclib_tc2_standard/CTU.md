# CTU

## Library
tcplclib_tc2_standard

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_Standard](ms-xhelp:///?Id=beckhoff-498a-4e2c-a861-2ffa4b1740a3)
2. [Function blocks](ms-xhelp:///?Id=beckhoff-e7be-4338-8e06-ae5851914a22)
3. [Counter](ms-xhelp:///?Id=beckhoff-1611-40f4-89ba-11582e37e522)
4. CTU

# CTU

![40600350](/tcplclib_tc2_standard/1033/Images/png/74445323__Web.png)

Incrementer

## VAR\_INPUT

```
VAR_INPUT  
    CU    : BOOL; (* Count Up *)  
    RESET : BOOL; (* Reset Counter to 0 *)  
    PV    : WORD; (* Counter Limit *)  
END_VAR
```

## VAR\_OUTPUT

```
VAR_OUTPUT  
    Q  : BOOL; (* Counter reached the Limit *)  
    CV : WORD; (* Current Counter Value *)  
END_VAR
```

The counter variable CV will be initialized with 0 if RESET is TRUE. If CU has a rising edge from FALSE to TRUE, the function block CV will be raised by 1 provided CV is smaller than PV (i.e., it doesn't cause an overflow). Q will return TRUE when CV is greater than or equal to the upper limit PV.

## Requirements

| Development environment | Target system type | PLC libraries to be linked |
| --- | --- | --- |
| TwinCAT v3.0.0 | PC or CX (x86) | Tc2\_Standard |

[TwinCAT 3 | PLC Library: Tc2\_Standard](ms-xhelp:///?Id=beckhoff-498a-4e2c-a861-2ffa4b1740a3)
