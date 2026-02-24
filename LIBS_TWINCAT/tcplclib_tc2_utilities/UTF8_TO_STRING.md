# UTF8_TO_STRING

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# UTF8\_TO\_STRING

![60945241](/tcplclib_tc2_utilities/1033/Images/png/3515021067__Web.png)

The function converts a string in UTF-8 format (pointer variable of the data type PVOID) into a string (variable) of the data type STRING.

The function returns

* TRUE if the conversion was possible.
* FALSE if the conversion was not possible due to the given character set.

If the input string is longer than the output string, the string will be truncated. Unknown characters are skipped.

The function stops the conversion after `Tc2_Utilities.Parameterlist.cMaxCharacters`. With appropriate parameterization an infinite loop can be avoided.

## FUNCTION UTF8\_TO\_STRING : BOOL

The return value is TRUE if the conversion was successful.

## VAR\_INPUT

```
VAR_INPUT  
    pDstSTRING : POINTER TO STRING;  
    pSrcUTF8   : PVOID;  
    nDstSize   : UDINT;  
END_VAR
```

**pDstSTRING:** Pointer to the converted STRING variable (output string)

**pSrcUTF8:** Pointer variable (input string)

**nDstSize:** Size of the resulting STRING variable (output string) in bytes. The operator SIZEOF() can be used for the assignment.

## VAR\_OUTPUT

```
VAR_OUTPUT  
    nDstLen        : UDINT;  
END_VAR
```

**nDstLen:** Actual length of the output string as number of characters.

|  |  |
| --- | --- |
| 11636265 | Documentation for attribute 'TcEncoding' := 'UTF-8'  For more information about strings in UTF-8 format see also the documentation on the 'TcEncoding' attribute. |

## Requirements

| Development environment | Target platform | PLC libraries to be integrated (category group) |
| --- | --- | --- |
| TwinCAT v3.1.4022 | PC or CX (x86, x64, ARM) | Tc2\_Utilities (System) >= 3.3.21.0 |
