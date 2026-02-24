# LEFT

## Library
tcplclib_tc2_standard

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_Standard](ms-xhelp:///?Id=beckhoff-498a-4e2c-a861-2ffa4b1740a3)
2. [String functions](ms-xhelp:///?Id=beckhoff-9743-4614-a000-b4e6c7fd9bcd)
3. LEFT

# LEFT

![19734077](/tcplclib_tc2_standard/1033/Images/png/74483723__Web.png)

The function LEFT returns the left, initial string for a given string.  
LEFT (STR, SIZE) means: Take the first SIZE character from the left in the string STR.

## FUNCTION LEFT: STRING (255)

```
VAR_INPUT  
    STR  : STRING(255);  
    SIZE : INT;  
END_VAR
```

Example in IL:

```
LD 'SUSI'  
LEFT 3  
ST Var1 (* Result is 'SUS' *)
```

Example in ST:

```
Var1 := LEFT ('SUSI',3);
```

## Requirements

| Development environment | Target system type | PLC libraries to be linked |
| --- | --- | --- |
| TwinCAT v3.0.0 | PC or CX (x86) | Tc2\_Standard |

[TwinCAT 3 | PLC Library: Tc2\_Standard](ms-xhelp:///?Id=beckhoff-498a-4e2c-a861-2ffa4b1740a3)
