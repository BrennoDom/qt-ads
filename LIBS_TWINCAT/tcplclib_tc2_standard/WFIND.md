# WFIND

## Library
tcplclib_tc2_standard

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_Standard](ms-xhelp:///?Id=beckhoff-498a-4e2c-a861-2ffa4b1740a3)
2. [String functions (WSTRING)](ms-xhelp:///?Id=beckhoff-a835-44eb-81fb-fe5e0a1d71e0)
3. WFIND

# WFIND

![6587942](/tcplclib_tc2_standard/1033/Images/png/2260999691__Web.png)

The function WFIND searches for a part in WSTRING.  
WFIND (STR1, STR2) means: Find the position of the first character of first occurrence of STR2 in STR1. If STR2 does not occur in STR1, then OUT := 0 applies.

## FUNCTION WFIND: INT

```
VAR_INPUT  
    STR1 : WSTRING(255);  
    STR2 : WSTRING(255);  
END_VAR
```

Example in IL:

```
LD “SUXYSI“  
WFIND “XY“  
ST Var1 (*Result is 3*)
```

Example in ST:

```
Var1 := WFIND (“SUXYSI“,“XY“);
```

## Requirements

| Development environment | Target system type | PLC libraries to be linked |
| --- | --- | --- |
| TwinCAT v3.0.0 | PC or CX (x86) | Tc2\_Standard |

[TwinCAT 3 | PLC Library: Tc2\_Standard](ms-xhelp:///?Id=beckhoff-498a-4e2c-a861-2ffa4b1740a3)
