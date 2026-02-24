# sLiteral_TO_UTF8

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# sLiteral\_TO\_UTF8

![26514531](/tcplclib_tc2_utilities/1033/Images/png/5780529547__en-US__Web.png)

This function converts any character string of the data type STRING into a character string in UTF-8 format. The function is particularly suitable for the assignment of literals.

When assigning literals to a UTF-8 STRING, the rules are:

* Literals that only use the ASCII character set can be directly assigned.
* Literals that use the STRING character set can be assigned by means of sLiteral\_TO\_UTF8().
* Literals that use the WSTRING character set can be assigned by means of [wsLiteral\_TO\_UTF8()](ms-xhelp:///?Id=beckhoff-29e7-4105-940d-4aa23630c02f).

An empty string will be returned if the literal is longer than the possible output character string.

## FUNCTION sLiteral\_TO\_UTF8 : STRING(511)

## VAR\_INPUT

```
VAR_IN_OUT CONSTANT  
    sLiteral   : STRING;  
END_VAR
```

**sLiteral:** STRING character string to be converted.

## Examples

```
{attribute 'TcEncoding' := 'UTF-8'}  
sMyText : STRING := sLiteral_TO_UTF8('Hühner legen Eier.');
```

```
{attribute 'TcEncoding' := 'UTF-8'}  
sMyText1 : STRING := sLiteral_TO_UTF8('The dinner costs 30 €.');
```

|  |  |
| --- | --- |
| 37304191 | Documentation for attribute 'TcEncoding' := 'UTF-8'  For more information about strings in UTF-8 format see also the documentation on the 'TcEncoding' attribute. |

## Requirements

| Development environment | Target platform | PLC libraries to be integrated (category group) |
| --- | --- | --- |
| TwinCAT v3.1.4022 | PC or CX (x86, x64, ARM) | Tc2\_Utilities (System) >=3.3.34.0 |
