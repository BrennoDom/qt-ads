# Format specification

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# Format specification

This format specification is used by the [FB\_FormatString](ms-xhelp:///?Id=beckhoff-5a86-4f47-ae1f-3b48b62e5a67) and [FB\_FormatString2](ms-xhelp:///?Id=beckhoff-0a0a-4c56-b137-73f98165f3c6) function blocks as well as the [F\_FormatArgToStr](ms-xhelp:///?Id=beckhoff-eb2c-4b18-8b80-a8518091c3d8) function. Whereas the format specification is transferred to the function blocks via a string input variable, it is transferred to the function via the individual function parameters.

The format specification includes various required and optional parameter fields:

* [Type](ms-xhelp:///?Id=beckhoff-e500-4c67-ba3d-fe4b073be6e3)
* [Flags](ms-xhelp:///?Id=beckhoff-e500-4c67-ba3d-fe4b073be6e3)
* [Width](ms-xhelp:///?Id=beckhoff-e500-4c67-ba3d-fe4b073be6e3)
* [Precision](ms-xhelp:///?Id=beckhoff-e500-4c67-ba3d-fe4b073be6e3)

The simplest format specification contains only the percentage sign and the type field (e.g. %s). All characters that follow the percentage sign are evaluated as parameter fields up to the type field. Characters before the percentage sign and after the type field are copied into the output string. Formatting is aborted with an error in the event of unidentifiable or illegal characters. In order to output the percentage sign in the output string, use two consecutive percentage signs (%%).

## Type

Required parameter field. The type field contains an ASCII character, which specifies whether the associated argument is interpreted as a string, an integer or a floating point number. Note that some type field parameters are case-sensitive.

| Type | Argument | Output |
| --- | --- | --- |
| **b, B** | BYTE, WORD, DWORD, REAL1,SINT2, INT2, DINT2, USINT, UINT, UDINT | Binary string (e.g. '101010111000') |
| **o, O** | BYTE, WORD, DWORD, REAL1,SINT2, INT2, DINT2, USINT, UINT, UDINT | Octal string |
| **u, U** | BYTE, WORD, DWORD, SINT2, INT2, DINT2, USINT, UINT, UDINT | Decimal string without sign |
| **c, C** | BYTE, USINT | Single (ASCII) byte character |
| **f, F** | REAL3, LREAL | Floating point number  The string has the form **[ – ]dddd.dddd**, (dddd are decimal numbers).  The number of digits before the decimal point depends on the value of the floating point number. The number of digits after the decimal point depends on the required precision.  The sign only appears for negative values. **'#INF'** is returned for an infinite positive value and **'-#INF'** for an infinite negative value.  If the variable transferred has an illegal value (NaN, Not-a-Number), **'#QNAN'** or **'-#QNAN'** is returned.  If the length of the formatted string exceeds the maximum permissible length of the resulting string, **'#OVF'** or **'-#OVF'** is returned. |
| **d, D** | BYTE, WORD, DWORD, SINT, INT, DINT, USINT, UINT, UDINT | Decimal string  The sign only appears for negative values. |
| **s, S** | STRING | Single byte character string  Characters are output until the final zero or the precision field parameter has been reached. |
| **X** | BYTE, WORD, DWORD, REAL1,SINT2, INT2, DINT2, USINT, UINT, UDINT | Hexadecimal string  Upper case letters ('ABCDEF') are used for formatting. |
| **x** | BYTE, WORD, DWORD, REAL1,SINT2, INT2, DINT2, USINT, UINT, UDINT | Hexadecimal string  Lower case letters ('abcdef') are used for formatting. |
| **E** | Not implemented. Reserved for future use. | Floating point numbers in scientific notation |
| **e** | Not implemented. Reserved for future use. | Floating point numbers in scientific notation |

1 The content of the REAL variable is returned as a binary, octal, hexadecimal or decimal string.

2 The content of the signed types is returned as a binary, octal, hexadecimal or decimal string.

3 The REAL variable is converted to the LREAL type and then formatted.

## Flags

Optional parameter field. One or more flags can be specified in any desired order in the flag field. The flag field parameters specify the alignment of the formatted value, the output of signs, spaces and the binary/octal/hex prefixes.

| Flag | Meaning | Type | Standard |
| --- | --- | --- | --- |
| **-** | Left alignment flag.  The formatted value is left aligned within the width aligned in parameter Width. | Can be used in conjunction with all types. | Right alignment. |
| **+** | Sign flag.  Forces output of the positive sign for signed positive numbers. | Only in conjunction with **e**, **E**, **f**, **F**, **d,D**, otherwise the flag is ignored. | The negative sign only appears for negative values. |
| **0** | Zero flag.  If this flag precedes the Width parameter, the resulting string is filled with zeros from the left until the required width is reached. | Only in conjunction with **e**, **E**, **f**, **F**, **s**, **S**, otherwise the flag is ignored.  The zero flag will also be ignored if the left-alignment flag (-) is additionally set. | No filling with zeros. |
| **Space (' ')** | Space flag  A positive value is preceded by a blank. | Only in conjunction with **e**, **E**, **f**, **F**, **d**, **D**, otherwise the flag is ignored.  The blank flag is also ignored if the left sign flag (+) was set at the same time | No blank. |
| **#** | Prefix flag.  An IEC or standard C prefix is placed before the formatted value.  IEC prefixes: **2#**, **8#**, **16#** (default)  Standard C prefixes: **0**, **0x**, **0X** | Only in conjunction with **b**, **B**, **o**, **O**, **x**, **X**, otherwise the flag is ignored.  The standard C prefix type can be activated by setting the global variable GLOBAL\_FORMAT\_HASH\_PREFIX\_TYPE in the program: GLOBAL\_FORMAT\_HASH\_PREFIX\_TYPE := HASHPREFIX\_STDC; | No prefix. |

## Width

Optional parameter field. The Width field contains a positive decimal value that specifies the minimum number of characters output in the output string.

Depending on the alignment flag, spaces will be appended to the left or right of the output string until the desired width is reached. If the zero flag is placed before the width field parameter, the resulting string will be filled with zeros from the left until the desired width is reached. The output string will never be truncated to the desired length by the width field parameter.

An asterisk (\*) can also be entered for the width field parameter. The required value is then provided by an argument (permissible types: BYTE, WORD, DWORD, USINT, UINT, UDINT). The argument for the width field parameter then follows the argument for the value to be formatted.

## Precision

Optional parameter field. The precision field follows the dot (.) and contains a positive decimal value. If the dot is not followed by a value, the default precision value is used (see table).

| Type | Meaning | Standard |
| --- | --- | --- |
| **b, B, o, O, u, U, x, X, d, D** | The precision field parameter specifies how many decimal characters (digits) are output in the output string.  If there are not enough digits, the string is filled with zeros from the left. The output string is never cut. | Standard: 1 |
| **c, C** | Has no meaning and is ignored. | One character is output. |
| **f, F** | The precision field parameter specifies the number of decimal places.  The argument value is always rounded to the respective number of decimal places. | Standard: 6 decimal places |
| **s, S** | The precision field parameter specifies how many characters from the argument string are output.  Characters exceeding the precision value are not output. | All characters up to the final zero are output. |

An asterisk (\*) can also be entered for the precision field parameter. The required value is then provided by an argument (permissible types: BYTE, WORD, DWORD, USINT, UINT, UDINT). The argument for the precision field parameter then follows the argument for the value to be formatted.
