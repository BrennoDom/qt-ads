# F_BYTE_TO_CRC16_CCITT

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# F\_BYTE\_TO\_CRC16\_CCITT

![11877685](/tcplclib_tc2_utilities/1033/Images/gif/35801483__en-US__Web.gif)

The function "F\_BYTE\_TO\_CRC16\_CCITT" can be used to determine a 16-bit CRC CCITT (cyclic redundancy check) for individual data bytes.

The generator polynomial used: Name: CRC-16 CCITT

* Standard: CRC-CCITT
* References: ITU X.25/T.30, ADCCP, SDLC/HDLC, ...
* Polynomial value: 0x1021
* Polynomial: x^16 + x^12 + x^5 + 1

## FUNCTION F\_BYTE\_TO\_CRC16\_CCITT: WORD

## VAR\_INPUT

```
VAR_INPUT  
    value   : BYTE;(* Data value *)  
    crc     : WORD;(* Initial value (16#FFFF or 16#0000) or previous CRC-16 result *)  
END_VAR
```

**value**: The data byte to be converted.

**crc**: Initial value = 16#FFFF or 16#0000 or the last CRC.

## Requirements

| Development environment | Target platform | PLC libraries to be integrated (category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_Utilities (System) |
