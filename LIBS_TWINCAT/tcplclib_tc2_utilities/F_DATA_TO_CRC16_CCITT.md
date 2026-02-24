# F_DATA_TO_CRC16_CCITT

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# F\_DATA\_TO\_CRC16\_CCITT

![16106447](/tcplclib_tc2_utilities/1033/Images/gif/35814283__en-US__Web.gif)

The function "F\_DATA\_TO\_CRC16\_CCITT" can be used to determine a 16-bit CRC CCITT (cyclic redundancy check) for any data. Internally the function [F\_BYTE\_TO\_CRC16\_CCITT](ms-xhelp:///?Id=beckhoff-1581-44e8-9f84-c03859e5cdc9) is used.

Further information on the algorithm used can be found in the documentation for the [F\_BYTE\_TO\_CRC16\_CCITT](ms-xhelp:///?Id=beckhoff-1581-44e8-9f84-c03859e5cdc9) function.

## FUNCTION F\_DATA\_TO\_CRC16\_CCITT: WORD

## VAR\_INPUT

```
VAR_INPUT  
    pData  : POINTER TO BYTE;(* Pointer to first data byte *)  
    cbData : UDINT;(* Length of data *)  
    crc    : WORD;(* Initial value (16#FFFF or 16#0000) or previous CRC-16 result *)  
END_VAR
```

**pData**: Address of the data buffer.

**cbData**: Length of the data buffer.

**crc**: Initial value = 16#FFFF or 16#0000 or the last CRC.

## Requirements

| Development environment | Target platform | PLC libraries to be integrated (category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_Utilities (System) |
