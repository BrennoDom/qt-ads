# MID

## Library
tcplclib_tc2_standard

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_Standard](ms-xhelp:///?Id=beckhoff-498a-4e2c-a861-2ffa4b1740a3)
2. [String functions](ms-xhelp:///?Id=beckhoff-9743-4614-a000-b4e6c7fd9bcd)
3. MID

# MID

![54956439](/tcplclib_tc2_standard/1033/Images/png/74490123__Web.png)

The function MID returns a partial string from within a string.  
MID (STR, LEN, POS) means: Retrieve LEN characters from the STR string beginning with the character at position POS.

## FUNCTION MID: STRING (255)

```
VAR_INPUT  
    STR : STRING(255);  
    LEN : INT;  
    POS : INT;  
END_VAR
```

Example in IL:

```
LD 'SUSI'  
MID 2,2  
ST Var1 (* Result is 'US' *) 
```

Example in ST:

```
Var1 := MID ('SUSI',2,2); 
```

## Requirements

| Development environment | Target system type | PLC libraries to be linked |
| --- | --- | --- |
| TwinCAT v3.0.0 | PC or CX (x86) | Tc2\_Standard |

[TwinCAT 3 | PLC Library: Tc2\_Standard](ms-xhelp:///?Id=beckhoff-498a-4e2c-a861-2ffa4b1740a3)
