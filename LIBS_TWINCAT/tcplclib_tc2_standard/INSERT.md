# INSERT

## Library
tcplclib_tc2_standard

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_Standard](ms-xhelp:///?Id=beckhoff-498a-4e2c-a861-2ffa4b1740a3)
2. [String functions](ms-xhelp:///?Id=beckhoff-9743-4614-a000-b4e6c7fd9bcd)
3. INSERT

# INSERT

![24562296](/tcplclib_tc2_standard/1033/Images/png/74480523__Web.png)

The function INSERT inserts a string into another string at a defined point.  
INSERT (STR1, STR2, POS) means: Insert STR2 into STR1 after position POS.

## FUNCTION INSERT: STRING (255)

```
VAR_INPUT  
    STR1 : STRING(255);  
    STR2 : STRING(255);  
    POS  : INT;  
END_VAR
```

Example in IL:

```
LD 'SUSI'  
INSERT 'XY',2  
ST Var1 (* Result is 'SUXYSI' *) 
```

Example in ST:

```
Var1 := INSERT('SUSI','XY',2); 
```

## Requirements

| Development environment | Target system type | PLC libraries to be linked |
| --- | --- | --- |
| TwinCAT v3.0.0 | PC or CX (x86) | Tc2\_Standard |

[TwinCAT 3 | PLC Library: Tc2\_Standard](ms-xhelp:///?Id=beckhoff-498a-4e2c-a861-2ffa4b1740a3)
