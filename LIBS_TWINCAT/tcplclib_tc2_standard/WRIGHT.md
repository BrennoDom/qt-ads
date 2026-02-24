# WRIGHT

## Library
tcplclib_tc2_standard

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_Standard](ms-xhelp:///?Id=beckhoff-498a-4e2c-a861-2ffa4b1740a3)
2. [String functions (WSTRING)](ms-xhelp:///?Id=beckhoff-a835-44eb-81fb-fe5e0a1d71e0)
3. WRIGHT

# WRIGHT

![33200047](/tcplclib_tc2_standard/1033/Images/png/2260971531__Web.png)

WRIGHT supplies a right-hand start string for a WSTRING.  
WRIGHT (STR, SIZE) means: Take the first SIZE characters from the right in WString STR.

## FUNCTION WRIGHT: WSTRING (255)

```
VAR_INPUT  
    STR  : WSTRING(255);  
    SIZE : INT;  
END_VAR
```

Example in IL:

```
LD “SUSI“  
WRIGHT 3  
ST Var1 (*Result is “USI“*)
```

Example in ST:

```
Var1 := WRIGHT (“SUSI“,3);
```

## Requirements

| Development environment | Target system type | PLC libraries to be linked |
| --- | --- | --- |
| TwinCAT v3.0.0 | PC or CX (x86) | Tc2\_Standard |

[TwinCAT 3 | PLC Library: Tc2\_Standard](ms-xhelp:///?Id=beckhoff-498a-4e2c-a861-2ffa4b1740a3)
