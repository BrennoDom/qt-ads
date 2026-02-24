# SERCOS file format of the backup file

## Library
tcplclib_tc2_iofunctions

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_IoFunctions](ms-xhelp:///?Id=beckhoff-89f3-4b36-bb70-6247b05e611b)
2. [Appendix](ms-xhelp:///?Id=beckhoff-6af7-46b2-b3e4-1069fad0c1b1)
3. SERCOS file format of the backup file

# SERCOS file format of the backup file

1. File header of the type ST\_SercosFileHeader

2. n \* data  
a) Parameter header of the type ST\_ParamHeader   
b) Parameter data as bytes

## Example of n parameters

```
1 * ST_SercosFileHeader (268  
Bytes)  
  
  
-----------------------------------------------------  
  
nVersion     ( 4 Bytes)  
  
nListType    ( 4 Bytes)  
  
cbCommentLen ( 4 Bytes)  
  
sComment     ( 256 Bytes)  
  
  
n * (ST_SercosParamHeader + Data)  
  
-----------------------------------------------------  
  
nIDN         ( 2 Bytes)  
  
cbSize       ( 2 Bytes)  
  
nAttrib      ( 4 Bytes)  
  
arrData      (cbSize Bytes),  
kann für jeden Parameter verschieden groß sein, je nach Typ oder  
Listenlänge
```

## Example of 3 parameters

```
ST_SercosFileHeader (268 Bytes)  
----------------------------------------------------------------------------  
nVersion ( 4 Bytes), i.e. = 01 00 00 00 (= 1)  
nListType ( 4 Bytes), i.e. = 00 00 00 00   
cbCommentLen ( 4 Bytes), i.e. = 00 00 00 00 (= 0)  
sComment ( 256 Bytes), i.e. = 00 00 00 00 00 00 00 ... 00  
(256 * 00)  
1st parameter ST_SercosParamHeader + Data (10 Bytes)  
----------------------------------------------------------------------------  
nIDN ( 2 Bytes), i.e. = nnnncbSize( 2 Bytes), i.e. = 02 00 (= 2)nAttrib ( 4 Bytes), i.e. = xx xx xx xx  
arrData     (2 Bytes), i.e. = 12 342nd parameter ST_SercosParamHeader + Data (16 Bytes)  
  
----------------------------------------------------------------------------  
nIDN ( 2 Bytes), i.e. = nnnncbSize( 2 Bytes), i.e. = 08 00 (= 8)nAttrib( 4 Bytes), i.e. = xx xx xx xx  
arrData ( 8 Bytes), i.e. = 12 34 56 78 9a bc de f03rd parameter ST_SercosParamHeader + Data (12 Bytes)  
----------------------------------------------------------------------------  
nIDN ( 2 Bytes), i.e. = nn nncbSize ( 2 Bytes), i.e. = 04 00 (= 4)nAttrib ( 4 Bytes), i.e. = xx xx xx xx  
arrData ( 4 Bytes), i.e. = 12 34 56 78
```

## **TYPE** **ST\_SercosFileHeader** (268 bytes)

The file header of the Sercos backup file is based on the ST\_SercosFileHeader structure.

```
TYPE ST_SercosFileHeader :  
STRUCT  
    nVersion      : UDINT;(* 4 Bytes *)  
    nListType     : UDINT;(* 4 Bytes *)  
    cbCommentLen  : UDINT;(* 4 Bytes *)  
    sComment      : T_MaxString;(* 256 Bytes *)  
END_STRUCT  
END_TYPE
```

**nVersion**: contains the file version, momentarily 1.

**nListType**: contains the IDN parameter list that was used for the backup. The default value is 192 (list of all backup parameters): the value is 0 in case of user-defined backup list. Alternatively, the list of all Sercos parameters (IDN 17) can be used. The restore, however, requires the list from parameter 192 or the user-defined list (0).

**cbCommentLen**: Length of the comment of the backup file.

**sComment**: Comment of the backup file. The string is written with all 256 characters.

## **TYPE ST\_SercosParamHeader (8 bytes)**

In the backup file, the file header is followed by a parameter header of the type ST\_SercosParamHeader for each parameter.

```
TYPE ST_SercosParamHeader :  
STRUCT  
    nIDN     : UINT;(* 2 Bytes *)  
    cbSize   : UINT;(* 2 Bytes *)  
    nAttrib  : DWORD;(* 4 Bytes *)  
END_STRUCT  
END_TYPE
```

**nIDN**: Sercos parameter number.

**cbSize**: Length of the data in bytes that follow this header. Can be different for each parameter, depending on the parameter type or list length.

**nAttrib**: Attribute of the Sercos parameter (see [ST\_SercosParamData](ms-xhelp:///?Id=beckhoff-f606-4da3-823a-c9773b98cf7e)); required for the determination of length and data type.

## **Parameter data (cbSize bytes)**

The data directly follow each Sercos parameter header in the backup file. The number of data bytes is saved in the parameter header in cbSize.

## Requirements

| Development environment | Target platform | IO hardware | PLC libraries to be integrated (category group) |
| --- | --- | --- | --- |
| TwinCAT v3.1.0 | PC (x86) | Sercans SCS-P ISA; Sercans SCS-P PCI; Beckhoff FC750x PCI | Tc2\_IoFunctions (IO) |

[TwinCAT 3 | PLC Library: Tc2\_IoFunctions](ms-xhelp:///?Id=beckhoff-89f3-4b36-bb70-6247b05e611b)
