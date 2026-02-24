# DATA_TO_HEXSTR

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# DATA\_TO\_HEXSTR

![55280873](/tcplclib_tc2_utilities/1033/Images/gif/35734283__en-US__Web.gif)

The function converts binary data into a hexadecimal string. This function can be used for converting simple data types and structure variables. The maximum length of the binary data must not exceed 85 bytes. If the maximum length is exceeded, a dot ('.') is added to the results string and the conversion is aborted. The remaining data bytes are not converted. In the event of faulty function parameters (*pData* = zero or *cbData* = zero) the function returns an empty string.

## FUNCTION DATA\_TO\_HEXSTR: T\_MaxString

## VAR\_INPUT

```
VAR_INPUT  
    pData   : POINTER TO BYTE;  
    cbData  : UDINT(0..85);  
    bLoCase : BOOL := FALSE;  
END_VAR
```

**pData**: Start address (pointer) for the binary data to be converted. The address can be determined with the ADR operator.

**cbData**: Max. length of the binary data to be converted. The length may not exceed 85 bytes. The length can be determined with the SIZEOF operator.

**bLoCase:** This parameter determines whether capital or lower-case letters are to be used in the conversion. TRUE = lower-case letters, FALSE = capital letters.

**Example:**

Please ensure that that the data size of the *overflow* variables does not exceed 85 bytes. For this reason, a dot is added to the results string *sH5*.

The byte order in the *number* variable is interchanged, since the memory organization of the counter variable is based on the little-endian-format (also referred to as Intel format).

```
PROGRAM MAIN  
VAR  
    str    : T_MaxString := 'abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789';  
    number : DWORD := 16#BECF1234;  
    char   : BYTE := 16#07;  
    null   : UDINT := 0;  
  
    overflow   : ARRAY[0..86] OF BYTE; (* data overflow *)  
    cbOverflow : UDINT;  
  
    sH1, sH2, sH3, sH4, sH5 : T_MaxString;  
END_VAR
```

```
sH1 := DATA_TO_HEXSTR( pData := ADR(str), cbData := LEN(str), FALSE );  
sH2 := DATA_TO_HEXSTR( pData := ADR(number), cbData := SIZEOF(number), FALSE );  
sH3 := DATA_TO_HEXSTR( pData := ADR(char), cbData := SIZEOF(char), FALSE );  
sH4 := DATA_TO_HEXSTR( pData := ADR(null), cbData := SIZEOF(null), FALSE );  
cbOverflow:= SIZEOF(overflow);  
sH5 := DATA_TO_HEXSTR( pData := ADR(overflow), cbData := cbOverflow, FALSE );
```

The result:

sH1 = '61 62 63 64 65 66 67 68 69 6A 6B 6C 6D 6E 6F 70 71 72 73 74 75 76 77 78 79 7A 41 42 43 44 45 46 47 48 49 4A 4B 4C 4D 4E 4F 50 51 52 53 54 55 56 57 58 59 5A 30 31 32 33 34 35 36 37 38 39'

sH2 = '34 12 CF BE'

sH3 = '07'

sH4 = '00 00 00 00'

sH5 = '00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00.'

## Requirements

| Development environment | Target platform | PLC libraries to be integrated (category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_Utilities (System) |
