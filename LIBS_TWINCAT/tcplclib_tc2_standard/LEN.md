# LEN

## Library
tcplclib_tc2_standard

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_Standard](ms-xhelp:///?Id=beckhoff-498a-4e2c-a861-2ffa4b1740a3)
2. [String functions](ms-xhelp:///?Id=beckhoff-9743-4614-a000-b4e6c7fd9bcd)
3. LEN

# LEN

![43388973](/tcplclib_tc2_standard/1033/Images/png/74486923__Web.png)

The function LEN returns the length of a string.

## FUNCTION LEN: INT

```
VAR_INPUT  
    STR : STRING(255);  
END_VA
```

Example in IL:

```
LD 'SUSI'  
LEN  
ST Var1 (* Result is 4 *)
```

Example in ST:

```
Var1 := LEN ('SUSI');
```

## Requirements

| Development environment | Target system type | PLC libraries to be linked |
| --- | --- | --- |
| TwinCAT v3.0.0 | PC or CX (x86) | Tc2\_Standard |

[TwinCAT 3 | PLC Library: Tc2\_Standard](ms-xhelp:///?Id=beckhoff-498a-4e2c-a861-2ffa4b1740a3)
