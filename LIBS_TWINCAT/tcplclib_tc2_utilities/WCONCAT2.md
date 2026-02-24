# WCONCAT2

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# WCONCAT2

![40949840](/tcplclib_tc2_utilities/1033/Images/png/3515028747__Web.png)

The function concatenates two strings of the data type WSTRING of any length and checks whether the resulting string is longer than a specified output string. In this case the string is truncated.

The function returns

* TRUE if the concatenation was successful.
* FALSE if the resulting string is longer than the output string and doesn't fit in the given output buffer. The memory requirement for the resulting string is then larger than that for the output string. The string is then truncated.

The function stops the checking of the input length after 10,000 characters (`Parameterlist.cMaxCharacters`) in order to avoid an infinite loop.

## FUNCTION WCONCAT2 : BOOL

## VAR\_INPUT

```
VAR_INPUT  
    pSrcWString1 : POINTER TO WSTRING;  
    pSrcWString2 : POINTER TO WSTRING;  
    pDstWString  : POINTER TO WSTRING;  
    nDstSize     : UDINT;  
END_VAR
```

**pSrcWString1:** Pointer to the first of the WSTRING variables to be concatenated (input string)

**pSrcWString2:** Pointer to the second of the WSTRING variables to be concatenated (input string)

**pDstWString:** Pointer to the resulting WSTRING variable following the concatenation (output string)

**nDstSize:** Size of the resulting WSTRING variable (output string) in bytes. The operator SIZEOF() can be used for the assignment.

## Requirements

| Development environment | Target platform | PLC libraries to be integrated (category group) |
| --- | --- | --- |
| TwinCAT v3.1.4022 | PC or CX (x86, x64, ARM) | Tc2\_Utilities (System) >= 3.3.21.0 |
