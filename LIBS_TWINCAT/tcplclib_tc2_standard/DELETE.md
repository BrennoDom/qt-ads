# DELETE

## Library
tcplclib_tc2_standard

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_Standard](ms-xhelp:///?Id=beckhoff-498a-4e2c-a861-2ffa4b1740a3)
2. [String functions](ms-xhelp:///?Id=beckhoff-9743-4614-a000-b4e6c7fd9bcd)
3. DELETE

# DELETE

![30957904](/tcplclib_tc2_standard/1033/Images/png/74474123__Web.png)

The function DELETE removes a partial string from a larger string at a defined position. The input variable STR is type STRING, LEN and POS are type INT, the return value of the function is type STRING.  
DELETE (STR, LEN, POS) means: Delete LEN characters from STR beginning with the character in the POS.

## FUNCTION DELETE: STRING (255)

```
VAR_INPUT  
    STR  : STRING(255);  
    LEN  : INT;  
    POS  : INT;  
END_VAR
```

Example in IL:

```
LD 'SUXYSI'  
DELETE 2,3  
ST Var1 (* Result is 'SUSI' *)
```

Example in ST:

```
Var1 := DELETE ('SUXYSI',2,3);
```

## Requirements

| Development environment | Target system type | PLC libraries to be linked |
| --- | --- | --- |
| TwinCAT v3.0.0 | PC or CX (x86) | Tc2\_Standard |

[TwinCAT 3 | PLC Library: Tc2\_Standard](ms-xhelp:///?Id=beckhoff-498a-4e2c-a861-2ffa4b1740a3)
