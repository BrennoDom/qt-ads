# WLEN

## Library
tcplclib_tc2_standard

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_Standard](ms-xhelp:///?Id=beckhoff-498a-4e2c-a861-2ffa4b1740a3)
2. [String functions (WSTRING)](ms-xhelp:///?Id=beckhoff-a835-44eb-81fb-fe5e0a1d71e0)
3. WLEN

# WLEN

![37880580](/tcplclib_tc2_standard/1033/Images/png/2260992011__Web.png)

The function WLEN outputs the length of a WSTRING.

## FUNCTION WLEN: INT

```
VAR_INPUT  
    STR : WSTRING(255);  
END_VAR
```

Example in IL:

```
LD “SUSI“  
WLEN  
ST Var1 (*Result is 4*)
```

Example in ST:

```
Var1 := WLEN (“SUSI“);
```

## Requirements

| Development environment | Target system type | PLC libraries to be linked |
| --- | --- | --- |
| TwinCAT v3.0.0 | PC or CX (x86) | Tc2\_Standard |

[TwinCAT 3 | PLC Library: Tc2\_Standard](ms-xhelp:///?Id=beckhoff-498a-4e2c-a861-2ffa4b1740a3)
