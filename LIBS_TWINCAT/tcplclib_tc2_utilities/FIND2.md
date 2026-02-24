# FIND2

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# FIND2

![6945858](/tcplclib_tc2_utilities/1033/Images/png/6200722443__Web.png)

The function finds a string, which may occur more than once, in another string.

The function returns

* is the position of the first character of the first string that was found.
* the value 0 if the string was not found.

The function stops the checking of the input length after Parameterlist.cMaxCharacters characters in order to avoid an infinite loop.

## FUNCTION FIND2 : UDINT

## VAR\_INPUT

```
VAR_INPUT  
    pSrcString  : POINTER TO STRING;  
    pFindString : POINTER TO STRING;  
END_VAR
```

**pSrcString:** Pointer to the STRING variable whose string is to be searched

**pFindString:** Pointer to the STRING variable whose string is being searched for

## Requirements

| Development environment | Target platform | PLC libraries to be integrated (category group) |
| --- | --- | --- |
| TwinCAT v3.1.4022 | PC or CX (x86, x64, ARM) | Tc2\_Utilities (System) >=3.3.35.0 |
