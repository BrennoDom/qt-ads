# FindAndReplace

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# FindAndReplace

![30366184](/tcplclib_tc2_utilities/1033/Images/png/6200728203__Web.png)

The function finds a string, which may occur more than once, in another string and replaces it with another string.

The function returns

* the number of replaced strings.
* the value 0 if the string was not found.

The function stops the checking of the input length after Parameterlist.cMaxCharacters characters in order to avoid an infinite loop.

## FUNCTION FindAndReplace : UDINT

## VAR\_INPUT

```
VAR_INPUT  
    pSrcString    : POINTER TO STRING;  
    pDeleteString : POINTER TO STRING;  
    pInsertString : POINTER TO STRING;  
    pDstString    : POINTER TO STRING;  
    nDstSize      : UDINT;  
END_VAR
```

**pSrcString:** Pointer to the STRING variable whose string is to be searched (input string)

**pDeleteString:** Pointer to the STRING variable whose string is to be replaced (input string)

**pInsertString:** Pointer to the STRING variable whose string is to replace the other string (input string)

**pDstString:** Pointer to the resulting STRING variable (output string)

**nDstSize:** Size of the resulting STRING variable (output string) in bytes. The operator SIZEOF() can be used for the assignment.

## Requirements

| Development environment | Target platform | PLC libraries to be integrated (category group) |
| --- | --- | --- |
| TwinCAT v3.1.4022 | PC or CX (x86, x64, ARM) | Tc2\_Utilities (System) >=3.3.35.0 |
