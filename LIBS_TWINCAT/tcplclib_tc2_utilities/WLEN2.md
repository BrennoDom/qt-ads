# WLEN2

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# WLEN2

![33004241](/tcplclib_tc2_utilities/1033/Images/png/3515030667__Web.png)

The function returns the number of characters in a Unicode string of the data type WSTRING (length of the WSTRING).

The function stops the checking of the input length after 10,000 characters (`Parameterlist.cMaxCharacters`) in order to avoid an infinite loop.

## FUNCTION WLEN2 : UDINT

## VAR\_INPUT

```
VAR_INPUT  
    pWSTRING : POINTER TO WSTRING;  
END_VAR
```

**pWSTRING:** pointer to the WSTRING variable

## Requirements

| Development environment | Target platform | PLC libraries to be integrated (category group) |
| --- | --- | --- |
| TwinCAT v3.1.4022 | PC or CX (x86, x64, ARM) | Tc2\_Utilities (System) >= 3.3.21.0 |
