# FIND

## Library
tcplclib_tc2_standard

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_Standard](ms-xhelp:///?Id=beckhoff-498a-4e2c-a861-2ffa4b1740a3)
2. [String functions](ms-xhelp:///?Id=beckhoff-9743-4614-a000-b4e6c7fd9bcd)
3. FIND

# FIND

![10185684](/tcplclib_tc2_standard/1033/Images/png/74477323__Web.png)

The function FIND searches for a partial string within a string.   
FIND (STR1, STR2) means: Find the position of the first character where STR2 appears in STR1 for the first time. If STR2 is not found in STR1, then OUT:=0.

## FUNCTION FIND: INT

```
VAR_INPUT  
    STR1 : STRING(255);  
    STR2 : STRING(255);  
END_VAR
```

Example in IL:

```
LD 'SUXYSI'  
FIND 'XY'  
ST Var1 (* Result is 3 *)
```

Example in ST:

```
Var1 := FIND('SUXYSI','XY');
```

## Requirements

| Development environment | Target system type | PLC libraries to be linked |
| --- | --- | --- |
| TwinCAT v3.0.0 | PC or CX (x86) | Tc2\_Standard |

[TwinCAT 3 | PLC Library: Tc2\_Standard](ms-xhelp:///?Id=beckhoff-498a-4e2c-a861-2ffa4b1740a3)
