# CONCAT

## Library
tcplclib_tc2_standard

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_Standard](ms-xhelp:///?Id=beckhoff-498a-4e2c-a861-2ffa4b1740a3)
2. [String functions](ms-xhelp:///?Id=beckhoff-9743-4614-a000-b4e6c7fd9bcd)
3. CONCAT

# CONCAT

![10896307](/tcplclib_tc2_standard/1033/Images/png/74470923__Web.png)

Concatenation (combination) of two strings.

## FUNCTION CONCAT: STRING (255)

```
VAR_INPUT  
     STR1 : STRING(255);  
     STR2 : STRING(255);  
END_VAR
```

Example in IL:

```
LD 'SUSI'  
CONCAT 'WILLI'  
ST Var1 (* Result is 'SUSIWILLI' *)
```

Example in ST:

```
Var1 := CONCAT ('SUSI','WILLI');
```

## Requirements

| Development environment | Target system type | PLC libraries to be linked |
| --- | --- | --- |
| TwinCAT v3.0.0 | PC or CX (x86) | Tc2\_Standard |

[TwinCAT 3 | PLC Library: Tc2\_Standard](ms-xhelp:///?Id=beckhoff-498a-4e2c-a861-2ffa4b1740a3)
