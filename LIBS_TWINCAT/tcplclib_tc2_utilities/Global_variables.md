# Global variables

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# Global variables

## VAR\_GLOBAL

| Name | Type | Value | Use | Meaning |
| --- | --- | --- | --- | --- |
| MAX\_AVERAGE\_MEASURES | INT | 10 | [Profiler](ms-xhelp:///?Id=beckhoff-06b5-46f0-b9a7-c7cbeb6e235d) | Number of averaged measurement readings. Possible values: 2..100 |
| GLOBAL\_FORMAT\_HASH\_PREFIX\_TYPE | E\_HashPrefixTypes | HASHPREFIX\_IEC | [FB\_FormatString](ms-xhelp:///?Id=beckhoff-5a86-4f47-ae1f-3b48b62e5a67), [F\_FormatArgToStr](ms-xhelp:///?Id=beckhoff-eb2c-4b18-8b80-a8518091c3d8) | Standard IEC prefix for binary, octal or hexadecimal formatting |
| GLOBAL\_SBCS\_TABLE | E\_SBCSType | eSBCS\_WesternEuropean | [F\_ToLCase](ms-xhelp:///?Id=beckhoff-2c8e-479d-b6ab-542ab6acb7e4), [F\_ToUCase](ms-xhelp:///?Id=beckhoff-7ffe-495f-96ad-aaf8b3eac001) | Windows SBCS (Single Byte Character Set) Code Page Table |
| GLOBAL\_DCF77\_PULSE\_SPLIT | TIME | T#140ms | [DCF77\_TIME](ms-xhelp:///?Id=beckhoff-9208-4bd2-b42f-0354e8f0bcca) | Pulse length. 0 == pulses < 140ms, 1 == pulses > 140 |
| GLOBAL\_DCF77\_SEQUENCE\_CHECK | BOOL | FALSE | [DCF77\_TIME](ms-xhelp:///?Id=beckhoff-9208-4bd2-b42f-0354e8f0bcca) | Plausibility check for two consecutive telegrams:  TRUE = active, FALSE = deactivated. |
| DEFAULT\_CSV\_FIELD\_SEP | BYTE | 16#2C | [FB\_CSVMemBufferWriter](ms-xhelp:///?Id=beckhoff-aa85-4a67-bf7a-9380e201eead), [FB\_CSVmemBufferReader](ms-xhelp:///?Id=beckhoff-1a3d-4151-8c6a-22708123ce55) | Data field separator. Semicolon= 16#3B => German field separator, comma = 16#2C => US field separator |

## Requirements

| Development environment | Target platform | PLC libraries to be integrated (category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_Utilities (System) |
