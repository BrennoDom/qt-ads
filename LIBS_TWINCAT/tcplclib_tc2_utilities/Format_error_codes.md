# Format error codes

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# Format error codes

The following error codes are returned by the [FB\_FormatString](ms-xhelp:///?Id=beckhoff-5a86-4f47-ae1f-3b48b62e5a67) and [FB\_FormatString2](ms-xhelp:///?Id=beckhoff-0a0a-4c56-b137-73f98165f3c6) function blocks as well as the [F\_FormatArgToStr](ms-xhelp:///?Id=beckhoff-eb2c-4b18-8b80-a8518091c3d8) function. If several arguments are used, the argument number (1..9) is returned in addition to the error code. The argument number provides information about where exactly an error was detected during formatting.

| Error code | Meaning |
| --- | --- |
| 16#00000000 | No error |
| 16#00000010 + Argument number (1..9) | Percent sign (%) at invalid position |
| 16#00000020 + Argument number (1..9) | Asterisk parameter at invalid position |
| 16#00000040 + Argument number (1..9) | Invalid width field value |
| 16#00000080 + Argument number (1..9) | Invalid precision field value |
| 16#00000100 + Argument number (1..9) | One of the flags at invalid position |
| 16#00000200 + Argument number (1..9) | The width or precision field value at invalid position |
| 16#00000400 + Argument number (1..9) | Dot "." sign of precision field at invalid position |
| 16#00000800 + Argument number (1..9) | Invalid (unsupported) type field value |
| 16#00001000 + Argument number (1..9) | Different type field and argument parameter |
| 16#00002000 + Argument number (1..9) | Invalid format string parameters |
| 16#00004000 + Argument number (1..9) | Too much arguments in format string |
| 16#00008000 + Argument number (1..9) | Destination string buffer overflow (formatted string is to long) |
| 16#00010000 + Argument number (1..9) | Invalid pointer input |

## Requirements

| Development environment | Target platform | PLC libraries to be integrated (category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_Utilities (System) |
