# STRNCPY

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# STRNCPY

![6771693](/tcplclib_tc2_utilities/1033/Images/png/3515019147__Web.png)

The function copies the character string of a variable of the data type STRING and checks whether the character string was completely copied.

The function returns

* TRUE if it was possible to copy the complete character string (content of the source array).
* FALSE if the character string was truncated when copying. If the input string is longer than the output string, only the number of characters (including null termination) corresponding to the length of the output string will be copied.

The function stops after 10,000 characters (`Parameterlist.cMaxCharacters`) in order to avoid an infinite loop.

## FUNCTION STRNCPY : BOOL

## VAR\_INPUT

```
VAR_INPUT  
    pDst     : POINTER TO STRING;  
    pSrc     : POINTER TO STRING;  
    nDstSize : UDINT;  
END_VAR
```

**pDst:** Pointer to the copied STRING variable (input string)

**pSrc:** Pointer to the STRING variable to be copied (output string)

**nDstSize:** Size of the resulting STRING variable (output string) in bytes. The operator SIZEOF() can be used for the assignment.

## Requirements

| Development environment | Target platform | PLC libraries to be integrated (category group) |
| --- | --- | --- |
| TwinCAT v3.1.4022 | PC or CX (x86, x64, ARM) | Tc2\_Utilities (System) >= 3.3.21.0 |
