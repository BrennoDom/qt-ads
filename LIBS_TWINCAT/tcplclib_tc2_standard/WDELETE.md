# WDELETE

## Library
tcplclib_tc2_standard

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_Standard](ms-xhelp:///?Id=beckhoff-498a-4e2c-a861-2ffa4b1740a3)
2. [String functions (WSTRING)](ms-xhelp:///?Id=beckhoff-a835-44eb-81fb-fe5e0a1d71e0)
3. WDELETE

# WDELETE

![60384317](/tcplclib_tc2_standard/1033/Images/png/2261066251__Web.png)

The function WDELETE deletes part of a WSTRING from a certain point. The input STR is of type WSTRING. LEN and POS are of type INT. The return value of the function is of type WSTRING.  
WDELETE (STR, LEN, POS) means: Delete LEN characters from STR beginning with the POSth character.

## FUNCTION WDELETE: WSTRING (255)

```
VAR_INPUT  
    STR1 : WSTRING(255);  
    LEN  : INT;   
    POS  : INT;  
END_VAR
```

Example in IL:

```
LD “SUXYSI“  
WDELETE 2,3  
ST Var1 (*Result is “SUSI“*)
```

Example in ST:

```
Var1 := WDELETE (“SUXYSI“,2,3);
```

## Requirements

| Development environment | Target system type | PLC libraries to be linked |
| --- | --- | --- |
| TwinCAT v3.0.0 | PC or CX (x86) | Tc2\_Standard |

[TwinCAT 3 | PLC Library: Tc2\_Standard](ms-xhelp:///?Id=beckhoff-498a-4e2c-a861-2ffa4b1740a3)
