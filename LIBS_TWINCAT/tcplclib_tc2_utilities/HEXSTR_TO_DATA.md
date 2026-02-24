# HEXSTR_TO_DATA

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# HEXSTR\_TO\_DATA

![60797095](/tcplclib_tc2_utilities/1033/Images/gif/35868683__en-US__Web.gif)

The function converts a hexadecimal string into binary data and returns the number of successfully converted data bytes as result. Only spaces may be used as separators in the hexadecimal string to be converted. Lower and upper case letters are permitted as hex characters. In the event of an error or an illegal character the conversion is aborted and a zero length is returned as result.

## FUNCTION HEXSTR\_TO\_DATA: UDINT

## VAR\_INPUT

```
VAR_INPUT  
    sHex   : T_MaxString;  
    pData  : POINTER TO BYTE;  
    cbData : UDINT;  
END_VAR
```

**sHex**: The hexadecimal string to be converted (type: T\_MaxString, e.g.: 'AB CD 01 23' ).

**pData**: Start address (pointer) to the target buffer into which the converted data bytes are to be written. The address can be determined with the ADR operator.

**cbData**: Max. available length of the target buffer. The length can be determined with the SIZEOF operator.

**Example:**

```
PROGRAM MAIN  
VAR  
    sH     : STRING := 'AB CD EF 01 23 45 67 89';  
    data   : ARRAY[0..10] OF BYTE;  
    cbData : UDINT;  
END_VAR
```

```
cbData := HEXSTR_TO_DATA( sH, ADR( data ), SIZEOF( data ) );
```

The result (online):

![10302948](/tcplclib_tc2_utilities/1033/Images/gif/35871883__Web.gif)

## Requirements

| Development environment | Target platform | PLC libraries to be integrated (category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_Utilities (System) |
