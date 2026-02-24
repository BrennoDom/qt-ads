# F_StringIsASCII

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# F\_StringIsASCII

![38054464](/tcplclib_tc2_utilities/1033/Images/png/3515011467__Web.png)

The function checks whether a string contains only ASCII characters (0x000 to 0x7F) and returns the number of ASCII characters. The string is directly compatible to UTF-8 if it contains only ASCII characters.

The function stops the checking of the input length after 10000 characters (`Parameterlist.cMaxCharacters`) in order to avoid an infinite loop.

## FUNCTION F\_StringIsASCII : BOOL

The return value is TRUE if the string contains only ASCII characters.

## VAR\_INPUT

```
VAR_INPUT  
    pSTRING : POINTER TO STRING;  
END_VAR
```

**pString:** pointer to the STRING variable.

## VAR\_OUTPUT

```
VAR_OUTPUT  
    nLen : UDINT;  
END_VAR
```

**nLen:** Number of ASCII characters in the string

## Requirements

| Development environment | Target platform | PLC libraries to be integrated (category group) |
| --- | --- | --- |
| TwinCAT v3.1.4022 | PC or CX (x86, x64, ARM) | Tc2\_Utilities (System) >= 3.3.21.0 |
