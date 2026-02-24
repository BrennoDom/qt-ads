# WREPLACE

## Library
tcplclib_tc2_standard

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_Standard](ms-xhelp:///?Id=beckhoff-498a-4e2c-a861-2ffa4b1740a3)
2. [String functions (WSTRING)](ms-xhelp:///?Id=beckhoff-a835-44eb-81fb-fe5e0a1d71e0)
3. WREPLACE

# WREPLACE

![48428136](/tcplclib_tc2_standard/1033/Images/png/2260974091__Web.png)

The function WREPLACE replaces a substring of a WSTRING with another WSTRING.  
WREPLACE (STR1, STR2, L, P) means: Replace L characters from STR1 with STR2 beginning with the Pth character.

## FUNCTION WREPLACE: WSTRING (255)

```
VAR_INPUT  
    STR1 : WSTRING(255);  
    STR2 : WSTRING(255);  
    L    : INT;  
    P    : INT;  
END_VAR
```

Example in IL:

```
LD “SUXYSI“  
WREPLACE “XY“,2  
ST Var1 (*Result is “SKYSI“*)
```

Example in ST:

```
Var1 := WREPLACE (“SUXYSI“,“K“,2,2);
```

## Requirements

| Development environment | Target system type | PLC libraries to be linked |
| --- | --- | --- |
| TwinCAT v3.0.0 | PC or CX (x86) | Tc2\_Standard |

[TwinCAT 3 | PLC Library: Tc2\_Standard](ms-xhelp:///?Id=beckhoff-498a-4e2c-a861-2ffa4b1740a3)
