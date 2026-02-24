# STRING_TO_WSTRING2

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# STRING\_TO\_WSTRING2

![15665491](/tcplclib_tc2_utilities/1033/Images/png/3515017227__Web.png)

The function converts a variable of the data type STRING into a variable of the data type WSTRING and checks whether the input string is longer than the output string. In this case the string is truncated.

The function returns

* TRUE if the conversion of the complete string was possible.
* FALSE if the input string is longer than the output string and the result doesn't fit in the given output buffer. The memory requirement for the output string is higher than that for the input string. The string is then truncated.

The function stops the conversion after 10,000 characters (`Parameterlist.cMaxCharacters`) in order to avoid an infinite loop.

## FUNCTION STRING\_TO\_WSTRING2 : BOOL

## VAR\_INPUT

```
VAR_INPUT  
    pDstWSTRING : POINTER TO WSTRING;  
    pSrcSTRING  : POINTER TO STRING;  
    nDstSize    : UDINT;  
END_VAR
```

**pDstWSTRING:** Pointer to the converted WSTRING variable (output string)

**pSrcSTRING:** Pointer to the STRING variable to be converted (input string)

**nDstSize:** Size of the resulting WSTRING variable (output string) in bytes. The operator SIZEOF() can be used for the assignment.

## Requirements

| Development environment | Target platform | PLC libraries to be integrated (category group) |
| --- | --- | --- |
| TwinCAT v3.1.4022 | PC or CX (x86, x64, ARM) | Tc2\_Utilities (System) >= 3.3.21.0 |
