# wsLiteral_TO_UTF8

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# wsLiteral\_TO\_UTF8

![28602718](/tcplclib_tc2_utilities/1033/Images/png/5780636811__en-US__Web.png)

This function converts any character string of the data type WSTRING into a character string in UTF-8 format. The function is particularly suitable for the assignment of literals.

When assigning literals to a UTF-8 STRING, the rules are:

* Literals that only use the ASCII character set can be directly assigned.
* Literals that use the STRING character set can be assigned by means of [sLiteral\_TO\_UTF8()](ms-xhelp:///?Id=beckhoff-7d26-4fb5-b7c8-75a331f934fd).
* Literals that use the WSTRING character set can be assigned by means of wsLiteral\_TO\_UTF8().

An empty string will be returned if the literal is longer than the possible output character string.

## FUNCTION wsLiteral\_TO\_UTF8 : STRING(511)

## VAR\_INPUT

```
VAR_IN_OUT CONSTANT  
    wsLiteral   : WSTRING;  
END_VAR
```

**sLiteral:** WSTRING character string to be converted.

## Examples

```
{attribute 'TcEncoding' := 'UTF-8'}  
sMyText : STRING := wsLiteral_TO_UTF8("Hühner legen Eier.");
```

```
{attribute 'TcEncoding' := 'UTF-8'}  
sMyText2 : STRING := wsLiteral_TO_UTF8("The dinner costs 30 €.");
```

|  |  |
| --- | --- |
| 56097870 | Documentation for attribute 'TcEncoding' := 'UTF-8'  For more information about strings in UTF-8 format see also the documentation on the 'TcEncoding' attribute. |

## Requirements

| Development environment | Target platform | PLC libraries to be integrated (category group) |
| --- | --- | --- |
| TwinCAT v3.1.4022 | PC or CX (x86, x64, ARM) | Tc2\_Utilities (System) >=3.3.34.0 |
