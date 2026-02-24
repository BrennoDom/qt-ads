# INSERT2

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# INSERT2

![53428882](/tcplclib_tc2_utilities/1033/Images/png/6200732043__Web.png)

The function inserts a string into another string after position nPos. If nPos = 0, the string is inserted before the first character of the other string.

The function returns

* TRUE if the string was successfully inserted.
* FALSE if the resulting string is longer than the output string and doesn't fit in the given output buffer. The memory requirement for the resulting string is then larger than that for the output string. The string is then truncated.

The function stops the checking of the input length after Parameterlist.cMaxCharacters characters in order to avoid an infinite loop.

## FUNCTION INSERT2 : BOOL

## VAR\_INPUT

```
VAR_INPUT  
    pSrcString    : POINTER TO STRING;  
    pInsertString : POINTER TO STRING;  
    pDstString    : POINTER TO STRING;  
    nDstSize      : UDINT;  
    nPos          : UDINT;  
END_VAR
```

**pSrcString:** Pointer to the STRING variable whose string is to be searched (input string)

**pInsertString:** Pointer to the STRING variable whose string is to be inserted in the other string (input string)

**pDstString:** Pointer to the resulting STRING variable (output string)

**nDstSize:** Size of the resulting STRING variable (output string) in bytes. The operator SIZEOF() can be used for the assignment.

**nPos:** Position of the character after which the string is to be inserted

## Requirements

| Development environment | Target platform | PLC libraries to be integrated (category group) |
| --- | --- | --- |
| TwinCAT v3.1.4022 | PC or CX (x86, x64, ARM) | Tc2\_Utilities (System) >=3.3.35.0 |
