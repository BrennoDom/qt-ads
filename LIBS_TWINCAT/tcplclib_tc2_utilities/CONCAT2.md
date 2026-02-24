# CONCAT2

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# CONCAT2

![41895032](/tcplclib_tc2_utilities/1033/Images/png/3515009547__Web.png)

The function concatenates two strings of the data type STRING of any length and checks whether the resulting string is longer than a specified output string. In this case the string is truncated.

The function returns

* TRUE if the concatenation was successful.
* FALSE if the resulting string is longer than the output string and doesn't fit in the given output buffer. The memory requirement for the resulting string is then larger than that for the output string. The string is then truncated.

The function stops the checking of the input length after 10,000 characters (`Parameterlist.cMaxCharacters`) in order to avoid an infinite loop.

## FUNCTION CONCAT2 : BOOL

## VAR\_INPUT

```
VAR_INPUT  
    pSrcString1 : POINTER TO STRING;  
    pSrcString2 : POINTER TO STRING;  
    pDstString  : POINTER TO STRING;  
    nDstSize    : UDINT;  
END_VAR
```

**pSrcString1:** Pointer to the first of the STRING variables to be concatenated (input string)

**pSrcString2:** Pointer to the second of the STRING variables to be concatenated (input string)

**pDstString:** Pointer to the resulting STRING variable following the concatenation (output string)

**nDstSize:** Size of the resulting STRING variable (output string) in bytes. The operator SIZEOF() can be used for the assignment.

## Requirements

| Development environment | Target platform | PLC libraries to be integrated (category group) |
| --- | --- | --- |
| TwinCAT v3.1.4022 | PC or CX (x86, x64, ARM) | Tc2\_Utilities (System) >= 3.3.21.0 |
