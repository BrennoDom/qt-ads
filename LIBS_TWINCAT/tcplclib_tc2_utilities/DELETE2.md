# DELETE2

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# DELETE2

![41510976](/tcplclib_tc2_utilities/1033/Images/png/6200720523__Web.png)

The function removes nLen characters from a string, starting at position nPos.

The function returns

* TRUE if the characters were successfully removed.
* FALSE if the resulting string is longer than the output string and doesn't fit in the given output buffer. The memory requirement for the resulting string is then larger than that for the output string. The string is then truncated.

The function stops the checking of the input length after Parameterlist.cMaxCharacters characters in order to avoid an infinite loop.

## FUNCTION DELETE2 : BOOL

## VAR\_INPUT

```
VAR_INPUT  
    pSrcString : POINTER TO STRING;  
    pDstString : POINTER TO STRING;  
    nDstSize   : UDINT;  
    nLen       : UDINT  
    nPos       : UDINT  
END_VAR
```

**pSrcString:** Pointer to the STRING variable (input string)

**pDstString:** Pointer to the resulting STRING variable (output string)

**nDstSize:** Size of the resulting STRING variable (output string) in bytes. The operator SIZEOF() can be used for the assignment.

**nLen:** Number of characters to be removed

**nPos:** Position of the first character to be removed; the following characters are also to be removed (nPos = 1 = first character)

## Requirements

| Development environment | Target platform | PLC libraries to be integrated (category group) |
| --- | --- | --- |
| TwinCAT v3.1.4022 | PC or CX (x86, x64, ARM) | Tc2\_Utilities (System) >=3.3.35.0 |
