# UTF8_TO_WSTRING

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# UTF8\_TO\_WSTRING

![37617525](/tcplclib_tc2_utilities/1033/Images/png/3515022987__Web.png)

The function converts a string in UTF-8 format into a string (variable) of the data type WSTRING.

The function returns

* TRUE if the conversion was possible.
* FALSE if the conversion was not possible due to the given character set.

If the input string is longer than the output string, the string will be truncated. The input string is too long to be coded to the output string. The memory requirement for the output string can be higher than that for the input string when converting to UTF-8. Unknown characters are skipped.

The function stops the conversion after `Tc2_Utilities.Parameterlist.cMaxCharacters`. With appropriate parameterization an infinite loop can be avoided.

## FUNCTION UTF8\_TO\_WSTRING : BOOL

The return value is TRUE if the conversion was successful.

## VAR\_INPUT

```
VAR_INPUT  
    pDstWSTRING : POINTER TO WSTRING;  
    pSrcUTF8    : PVOID;  
    nDstSize    : UDINT;  
END_VAR
```

**pDstWSTRING:** Pointer to the converted WSTRING variable (output string)

**pSrcUTF8:** Pointer variable (input string)

**nDstSize:** Size of the resulting WSTRING variable (output string) in bytes. The operator SIZEOF() can be used for the assignment.

## VAR\_OUTPUT

```
VAR_OUTPUT  
    nDstLen : UDINT;  
END_VAR
```

**nDstLen:** Actual length of the output string as number of characters.

|  |  |
| --- | --- |
| 3013405 | Documentation for attribute 'TcEncoding' := 'UTF-8'  For more information about strings in UTF-8 format see also the documentation on the 'TcEncoding' attribute. |

## Requirements

| Development environment | Target platform | PLC libraries to be integrated (category group) |
| --- | --- | --- |
| TwinCAT v3.1.4022 | PC or CX (x86, x64, ARM) | Tc2\_Utilities (System) >= 3.3.21.0 |
