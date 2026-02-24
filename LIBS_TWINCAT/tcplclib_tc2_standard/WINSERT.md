# WINSERT

## Library
tcplclib_tc2_standard

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_Standard](ms-xhelp:///?Id=beckhoff-498a-4e2c-a861-2ffa4b1740a3)
2. [String functions (WSTRING)](ms-xhelp:///?Id=beckhoff-a835-44eb-81fb-fe5e0a1d71e0)
3. WINSERT

# WINSERT

![59291480](/tcplclib_tc2_standard/1033/Images/png/2260997131__Web.png)

The function WINSERT adds a WString in another WString from a particular location.  
WINSERT (STR1, STR2, POS) means: Add STR2 in STR1 after the POSth position.

## FUNCTION WINSERT: WSTRING (255)

```
VAR_INPUT  
    STR1 : WSTRING(255);  
    STR2 : WSTRING(255);  
    POS  : INT;  
END_VAR
```

Example in IL:

```
LD “SUSI“  
WINSERT “XY“,2  
ST Var1 (*Result is “SUXYSI“*)
```

Example in ST:

```
Var1 := WINSERT (“SUSI“,“XY“,2);
```

## Requirements

| Development environment | Target system type | PLC libraries to be linked |
| --- | --- | --- |
| TwinCAT v3.0.0 | PC or CX (x86) | Tc2\_Standard |

[TwinCAT 3 | PLC Library: Tc2\_Standard](ms-xhelp:///?Id=beckhoff-498a-4e2c-a861-2ffa4b1740a3)
