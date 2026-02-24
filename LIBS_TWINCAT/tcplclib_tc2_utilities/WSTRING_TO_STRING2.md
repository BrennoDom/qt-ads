# WSTRING_TO_STRING2

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# WSTRING\_TO\_STRING2

![35118788](/tcplclib_tc2_utilities/1033/Images/png/3515032587__Web.png)

The function converts a variable of the data type WSTRING into a variable of the data type STRING.

The function returns

* TRUE if the conversion of the complete string was possible.
* FALSE if the input string is longer than the output string and the result doesn't fit in the given output buffer.

Characters that cannot be converted are skipped during the conversion.

The function stops the conversion after 10,000 characters (`Parameterlist.cMaxCharacters`) in order to avoid an infinite loop.

## FUNCTION WSTRING\_TO\_STRING2 : BOOL

## VAR\_INPUT

```
VAR_INPUT  
    pDstString  : POINTER TO STRING;  
    pSrcWString : POINTER TO WSTRING;  
    nDstSize    : UDINT;  
END_VAR
```

**pDstSTRING:** Pointer to the converted STRING variable (output string)

**pSrcWSTRING:** Pointer to the WSTRING variable to be converted (input string)

**nDstSize:** Size of the resulting STRING variable (output string) in bytes. The operator SIZEOF() can be used for the assignment.

## Requirements

| Development environment | Target platform | PLC libraries to be integrated (category group) |
| --- | --- | --- |
| TwinCAT v3.1.4022 | PC or CX (x86, x64, ARM) | Tc2\_Utilities (System) >= 3.3.21.0 |
