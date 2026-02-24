# UTF8Len

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# UTF8Len

![27120652](/tcplclib_tc2_utilities/1033/Images/png/3515024907__Web.png)

The function returns the number of characters in a UTF-8 string.

If the string does not correspond to the UTF-8 format, the function returns the value 0.

In addition, the function checks whether all the characters are valid ASCII characters and outputs this via the `bASCII` output.

The function stops the verification after `Tc2_Utilities.Parameterlist.cMaxCharacters`. With appropriate parameterization an infinite loop can be avoided.

## FUNCTION UTF8Len : UDINT

The return value returns the number of characters in the UTF-8 string.

## VAR\_INPUT

```
VAR_INPUT  
    pUTF8 : PVOID;  
END_VAR
```

**pUTF8:** pointer to the null-terminated UTF-8 string

## VAR\_OUTPUT

```
VAR_OUTPUT  
    bASCII   : BOOL;  
    nSize    : UDINT;  
END_VAR
```

**bASCII:** TRUE if the UTF-8 characters are valid ASCII characters.

**nSize:** Size of the string in bytes (without zero termination). Depending on the characters, the size in bytes may be larger than the length of the string.

|  |  |
| --- | --- |
| 42759282 | Documentation for attribute 'TcEncoding' := 'UTF-8'  For more information about strings in UTF-8 format see also the documentation on the 'TcEncoding' attribute. |

## Requirements

| Development environment | Target platform | PLC libraries to be integrated (category group) |
| --- | --- | --- |
| TwinCAT v3.1.4022 | PC or CX (x86, x64, ARM) | Tc2\_Utilities (System) >= 3.3.21.0 |
