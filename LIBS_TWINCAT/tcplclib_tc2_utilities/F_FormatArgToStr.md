# F_FormatArgToStr

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# F\_FormatArgToStr

![10740297](/tcplclib_tc2_utilities/1033/Images/gif/35817483__en-US__Web.gif)

Auxiliary format function. This function is used internally by the [FB\_FormatString](ms-xhelp:///?Id=beckhoff-5a86-4f47-ae1f-3b48b62e5a67) function block. The function can be used to convert a variable of type [T\_Arg](ms-xhelp:///?Id=beckhoff-9414-4e02-83ee-fc21ca340682) into a formatted string according to the [format specification](ms-xhelp:///?Id=beckhoff-e500-4c67-ba3d-fe4b073be6e3).

## FUNCTION F\_FormatArgToStr: UDINT

## VAR\_INPUT

```
VAR_INPUT  
   bSign      : BOOL;(* Sign prefix flag *)  
   bBlank     : BOOL;(* Blank prefix flag *)  
   bNull      : BOOL;(* Null prefix flag *)  
   bHash      : BOOL;(* Hash prefix flag *)  
   bLAlign    : BOOL;(* FALSE => Right align (default), TRUE => Left align *)  
   bWidth     : BOOL;(* FALSE => no width padding, TRUE => blank or zeros padding enabled *)  
   iWidth     : INT;(* Width length parameter *)  
   iPrecision : INT;(* Precision length parameter *)  
   eFmtType   : E_TypeFieldParam;    (* Format type field parameter *)  
   arg        : T_Arg;(* Format argument *)  
END_VAR
```

**bSign**: sign flag.

**bBlank**: blank flag.

**bNull**: null flag.

**bHash**: hash prefix flag.

**bLAlign**: alignment flag (TRUE=left align).

**bWidth**: If TRUE, the iWidth parameter is interpreted, otherwise not.

**iWidth**: Width parameter.

**iPrecision**: Precision parameter.

**eFmtType**: Type parameter (type: [E\_TypeFieldParam](ms-xhelp:///?Id=beckhoff-648a-46b7-91b9-a2f10d386340)).

**arg**: The argument to be formatted. The following auxiliary functions can be used for converting different types of PLC variables into the required data type [T\_Arg](ms-xhelp:///?Id=beckhoff-9414-4e02-83ee-fc21ca340682): [F\_BYTE](ms-xhelp:///?Id=beckhoff-d40f-4c2f-a0a9-d9581125e39f), [F\_WORD](ms-xhelp:///?Id=beckhoff-bf56-47a2-b979-8f8d1afba16a), [F\_DWORD](ms-xhelp:///?Id=beckhoff-08e6-4733-a65b-ffeb2bba9033), [F\_LWORD](ms-xhelp:///?Id=beckhoff-c9ce-42dd-99f5-1344a6bd2053), [F\_SINT](ms-xhelp:///?Id=beckhoff-b325-453e-ad3d-38b18f6a33da), [F\_INT](ms-xhelp:///?Id=beckhoff-8884-46d0-8401-e795f037a2cb), [F\_DINT](ms-xhelp:///?Id=beckhoff-a011-41ba-ac14-ddf227d9d3ec), [F\_LINT](ms-xhelp:///?Id=beckhoff-4138-4152-a8d3-6cd25a818ac9), [F\_USINT](ms-xhelp:///?Id=beckhoff-3296-4240-9ec5-2f84c4272563), [F\_UINT](ms-xhelp:///?Id=beckhoff-dc19-4c0e-9a2a-90a1c40e5430), [F\_UDINT](ms-xhelp:///?Id=beckhoff-9ba1-46a2-bb28-435ec870d7e2), [F\_ULINT](ms-xhelp:///?Id=beckhoff-3c34-4c70-a162-c672d8f68fa5), [F\_STRING](ms-xhelp:///?Id=beckhoff-6a77-44ce-a6fc-70c776b2fd5a), [F\_REAL](ms-xhelp:///?Id=beckhoff-9458-453d-8ade-48d9876779e4), [F\_LREAL](ms-xhelp:///?Id=beckhoff-c525-4b79-9cef-7e093c2ed20f).

## VAR\_IN\_OUT

```
VAR_IN_OUT  
   sOut     : T_MaxString;  
END_VAR
```

**sOut**: If successful, this variable returns the formatted output string (Type:T\_MaxString).

| Return parameter | Meaning |
| --- | --- |
| 0 | No error |
| <> 0 | Error. For error description see [Format error codes](ms-xhelp:///?Id=beckhoff-d559-4ad2-a5ba-469f9c5b3ce2) |

**Examples:**

Formatting a BYTE variable as a binary string.

```
PROGRAM MAIN  
VAR  
    s1      : T_MaxString;  
    s2      : T_MaxString;  
    s3      : T_MaxString;  
    s4      : T_MaxString;  
    s5      : T_MaxString;  
    errID   : UDINT;  
    varByte : BYTE;  
    double  : LREAL;  
    L1      : INT;  
    L2      : INT;  
    L3      : INT;  
    L4      : INT;  
    L5      : INT;  
END_VAR
```

```
varByte := 128;  
errID   := F_FormatArgToStr(FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, 20, 8, TYPEFIELD_B, F_BYTE( varByte ), s1 );  
errID   := F_FormatArgToStr(FALSE, FALSE, FALSE, FALSE, FALSE, TRUE, 20, 8, TYPEFIELD_B, F_BYTE( varByte ), s2 );  
errID   := F_FormatArgToStr(FALSE, FALSE, FALSE, FALSE, TRUE, TRUE, 20, 8, TYPEFIELD_B, F_BYTE( varByte ), s3 );  
errID   := F_FormatArgToStr(FALSE, FALSE, FALSE, TRUE, TRUE, TRUE, 20, 8, TYPEFIELD_B, F_BYTE( varByte ), s4 );  
L1 := LEN( s1 );  
L2 := LEN( s2 );  
L3 := LEN( s3 );  
L4 := LEN( s4 );
```

The result:

s1 = '10000000'  
s2 = '            10000000'  
s3 = '10000000            '  
s4 = '2#10000000          '  
L1 = 8  
L2 = 20  
L3 = 20  
L4 = 20

Formatting an LREAL variable.

```
double := 12345.6789;  
errID  := F_FormatArgToStr( FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, 20, 8, TYPEFIELD_F, F_LREAL( double ), s1 );  
errID  := F_FormatArgToStr( FALSE, FALSE, FALSE, FALSE, FALSE, TRUE, 20, 8, TYPEFIELD_F, F_LREAL( double ), s2 );  
errID  := F_FormatArgToStr( FALSE, FALSE, FALSE, FALSE, TRUE, TRUE, 20, 8, TYPEFIELD_F, F_LREAL( double ), s3 );  
errID  := F_FormatArgToStr( FALSE, FALSE, TRUE, FALSE, FALSE, TRUE, 20, 8, TYPEFIELD_F, F_LREAL( double ), s4 );  
errID  := F_FormatArgToStr( TRUE, FALSE, FALSE, TRUE, TRUE, TRUE, 20, 8, TYPEFIELD_F, F_LREAL( double ), s5 );  
L1 := LEN( s1 );  
L2 := LEN( s2 );  
L3 := LEN( s3 );  
L4 := LEN( s4 );  
L5 := LEN( s5 );
```

The result:

s1 = '12345.67890000'  
s2 = '      12345.67890000'  
s3 = '12345.67890000      '  
s4 = '00000012345.67890000'  
s5 = '+12345.67890000     '  
L1 = 14  
L2 = 20  
L3 = 20  
L4 = 20  
L5 = 20

## Requirements

| Development environment | Target platform | PLC libraries to be integrated (category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_Utilities (System) |
