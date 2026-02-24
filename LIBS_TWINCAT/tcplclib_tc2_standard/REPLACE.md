# REPLACE

## Library
tcplclib_tc2_standard

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_Standard](ms-xhelp:///?Id=beckhoff-498a-4e2c-a861-2ffa4b1740a3)
2. [String functions](ms-xhelp:///?Id=beckhoff-9743-4614-a000-b4e6c7fd9bcd)
3. REPLACE

# REPLACE

![24845910](/tcplclib_tc2_standard/1033/Images/png/74493323__Web.png)

The function REPLACE replaces a partial string from a larger string with a third string.  
REPLACE (STR1, STR2, L, P) means: Replace L characters from STR1 with STR2 beginning with the character in the P position.

## FUNCTION REPLACE: STRING (255)

```
VAR_INPUT  
    STR1 : STRING(255);  
    STR2 : STRING(255);  
    L    : INT;  
    P    : INT;  
END_VAR
```

Example in IL:

```
LD 'SUXYSI'  
REPLACE 'K',2,2  
ST Var1 (* Result is 'SKYSI' *)
```

Example in ST:

```
Var1 := REPLACE('SUXYSI','K',2,2);
```

## Requirements

| Development environment | Target system type | PLC libraries to be linked |
| --- | --- | --- |
| TwinCAT v3.0.0 | PC or CX (x86) | Tc2\_Standard |

[TwinCAT 3 | PLC Library: Tc2\_Standard](ms-xhelp:///?Id=beckhoff-498a-4e2c-a861-2ffa4b1740a3)
