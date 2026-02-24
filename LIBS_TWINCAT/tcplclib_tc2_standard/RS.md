# RS

## Library
tcplclib_tc2_standard

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_Standard](ms-xhelp:///?Id=beckhoff-498a-4e2c-a861-2ffa4b1740a3)
2. [Function blocks](ms-xhelp:///?Id=beckhoff-e7be-4338-8e06-ae5851914a22)
3. [Bistable](ms-xhelp:///?Id=beckhoff-b68d-4899-8fe3-d83b0c0ccab9)
4. RS

# RS

![28961294](/tcplclib_tc2_standard/1033/Images/png/74435723__Web.png)

Resetting Bistable Function Blocks

Q1 = RS (SET, RESET1)

means: Q1 = NOT RESET1 AND (Q1 OR SET)

## VAR\_INPUT

```
VAR_INPUT  
    SET    : BOOL;   
    RESET1 : BOOL;  
END_VAR
```

## VAR\_OUTPUT

```
VAR_OUTPUT  
    Q1 : BOOL;   
END_VAR
```

Internal implementation of fb:

```
Q1: = NOT RESET1 AND (Q1 OR SET);
```

## Requirements

| Development environment | Target system type | PLC libraries to be linked |
| --- | --- | --- |
| TwinCAT v3.0.0 | PC or CX (x86) | Tc2\_Standard |

[TwinCAT 3 | PLC Library: Tc2\_Standard](ms-xhelp:///?Id=beckhoff-498a-4e2c-a861-2ffa4b1740a3)
