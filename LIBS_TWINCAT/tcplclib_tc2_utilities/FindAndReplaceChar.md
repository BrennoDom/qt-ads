# FindAndReplaceChar

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# FindAndReplaceChar

![4860205](/tcplclib_tc2_utilities/1033/Images/png/6200730123__Web.png)

The function finds a character, which may occur more than once, in a string and replaces it with another character.

The function returns

* the number of replaced characters.
* the value 0 if the character was not found.

The function stops the checking of the input length after Parameterlist.cMaxCharacters characters in order to avoid an infinite loop.

## FUNCTION FindAndReplaceChar : UDINT

## VAR\_INPUT

```
VAR_INPUT  
    pSrcString    : POINTER TO STRING;  
    sDeleteChar   : STRING(1);  
    sInsertChar   : STRING(1);  
    pDstString    : POINTER TO STRING;  
    nDstSize      : UDINT;  
END_VAR
```

**pSrcString:** Pointer to the STRING variable whose string is to be searched (input string)

**sDeleteChar:** Character to be replaced

**sInsertChar:** Character to replace the other character

**pDstString:** Pointer to the resulting STRING variable (output string)

**nDstSize:** Size of the resulting STRING variable (output string) in bytes. The operator SIZEOF() can be used for the assignment.

## Requirements

| Development environment | Target platform | PLC libraries to be integrated (category group) |
| --- | --- | --- |
| TwinCAT v3.1.4022 | PC or CX (x86, x64, ARM) | Tc2\_Utilities (System) >=3.3.35.0 |
