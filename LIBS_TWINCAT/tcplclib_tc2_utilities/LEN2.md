# LEN2

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# LEN2

![11097898](/tcplclib_tc2_utilities/1033/Images/png/3515013387__Web.png)

The function returns the number of characters in a string (length of the STRING).

The function stops the checking of the input length after 10,000 characters (`Parameterlist.cMaxCharacters`) in order to avoid an infinite loop.

## FUNCTION LEN2 : UDINT

## VAR\_INPUT

```
VAR_INPUT  
    pSTRING : POINTER TO STRING;  
END_VAR
```

**pString:** pointer to the STRING variable

## Requirements

| Development environment | Target platform | PLC libraries to be integrated (category group) |
| --- | --- | --- |
| TwinCAT v3.1.4022 | PC or CX (x86, x64, ARM) | Tc2\_Utilities (System) >= 3.3.21.0 |
