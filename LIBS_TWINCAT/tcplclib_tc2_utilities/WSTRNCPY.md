# WSTRNCPY

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# WSTRNCPY

![33119622](/tcplclib_tc2_utilities/1033/Images/png/3515036427__Web.png)

The function copies a character string of a variable of the data type WSTRING and checks whether the character string was completely copied.

The function returns

* TRUE if it was possible to copy the complete character string (content of the source array).
* FALSE if the character string was truncated when copying. If the input string is longer than the output string, only the number of characters (including null termination) corresponding to the length of the output string will be copied.

The function stops after 10,000 characters (`Parameterlist.cMaxCharacters`) in order to avoid an infinite loop.

## FUNCTION WSTRNCPY : BOOL

## VAR\_INPUT

```
VAR_INPUT  
    pDst     : POINTER TO WSTRING;  
    pSrc     : POINTER TO WSTRING;  
    nDstSize : UDINT;  
END_VAR
```

**pDst:** Pointer to the copied WSTRING variable (input string)

**pSrc:** Pointer to the WSTRING variable to be copied (output string)

**nDstSize:** Size of the resulting WSTRING variable (output string) in bytes. The operator SIZEOF() can be used for the assignment.

## Requirements

| Development environment | Target platform | PLC libraries to be integrated (category group) |
| --- | --- | --- |
| TwinCAT v3.1.4022 | PC or CX (x86, x64, ARM) | Tc2\_Utilities (System) >= 3.3.21.0 |
