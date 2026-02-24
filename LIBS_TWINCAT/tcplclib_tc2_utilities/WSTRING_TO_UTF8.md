# WSTRING_TO_UTF8

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# WSTRING\_TO\_UTF8

![47633640](/tcplclib_tc2_utilities/1033/Images/png/3515034507__Web.png)

The function converts a string of a variable of the data type WSTRING into a string in UTF-8 format.

The function returns

* TRUE if the conversion was possible.
* FALSE if the conversion was not possible due to the given character set.

If the input string is longer than the output string, the string will be truncated. The input string is too long to be coded to the output string. (The memory requirement for the output string can be higher than that for the input character string when converting to UTF-8). Unknown characters are skipped.

The function stops the conversion after `Tc2_Utilities.Parameterlist.cMaxCharacters`. With appropriate parameterization an infinite loop can be avoided.

## FUNCTION WSTRING\_TO\_UTF8 : BOOL

## VAR\_INPUT

```
VAR_INPUT  
    pDstUTF8    : PVOID;  
    pSrcWSTRING : POINTER TO WSTRING;  
    nDstSize    : UDINT;  
END_VAR
```

**pDstUTF8:** Pointer variable (output string)

**pSrcWSTRING:** Pointer to the WSTRING variable (input string)

**nDstSize:** Size of the resulting variable (output string) in bytes. The operator SIZEOF() can be used for the assignment.

|  |  |
| --- | --- |
| 26049579 | Documentation for attribute 'TcEncoding' := 'UTF-8'  For more information about strings in UTF-8 format see also the documentation on the 'TcEncoding' attribute. |

## Requirements

| Development environment | Target platform | PLC libraries to be integrated (category group) |
| --- | --- | --- |
| TwinCAT v3.1.4022 | PC or CX (x86, x64, ARM) | Tc2\_Utilities (System) >= 3.3.21.0 |
