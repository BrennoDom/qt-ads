# WMID

## Library
tcplclib_tc2_standard

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_Standard](ms-xhelp:///?Id=beckhoff-498a-4e2c-a861-2ffa4b1740a3)
2. [String functions (WSTRING)](ms-xhelp:///?Id=beckhoff-a835-44eb-81fb-fe5e0a1d71e0)
3. WMID

# WMID

![5380904](/tcplclib_tc2_standard/1033/Images/png/2260989451__Web.png)

The function WMID supplies a substring of a WSTRING.  
WMID(STR, LEN, POS) means: Fetch LEN characters from WSTRING STR beginning with the character at position POS.

## FUNCTION WMID: WSTRING (255)

```
VAR_INPUT  
    STR : WSTRING(255);  
    LEN : INT;  
    POS : INT;  
END_VAR
```

Example in IL:

```
LD “SUSI“  
WMID 2,2  
ST Var1 (*Result is “US“*)
```

Example in ST:

```
Var1 := WMID (“SUSI“,2,2);
```

## Requirements

| Development environment | Target system type | PLC libraries to be linked |
| --- | --- | --- |
| TwinCAT v3.0.0 | PC or CX (x86) | Tc2\_Standard |

[TwinCAT 3 | PLC Library: Tc2\_Standard](ms-xhelp:///?Id=beckhoff-498a-4e2c-a861-2ffa4b1740a3)
