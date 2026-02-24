# ARG_TO_CSVFIELD

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# ARG\_TO\_CSVFIELD

![57250251](/tcplclib_tc2_utilities/1033/Images/png/9007199290462475__Web.png)

The function converts the value of a PLC variable to a data field in CSV format. Single quotation marks in the source file are replaced with double quotation marks. If the bQM parameter is set (QM = quotation marks) the outer quotation marks (around the CSV data field) are also added. If successful the function returns the length of the converted data as the result. The function returns zero if a conversion error occurred or in the event of missing data. The result is written into the byte buffer provided. The application must ensure that the buffer is large enough to contain the result.

The function is usually used together with the function block [FB\_CSVMemBufferWriter](ms-xhelp:///?Id=beckhoff-aa85-4a67-bf7a-9380e201eead) to generate data sets in the PLC memory in CSV format. In the next step the memory content can be written to the file. In contrast to the [STRING\_TO\_CSVFIELD](ms-xhelp:///?Id=beckhoff-1943-47a0-a7c9-12bc3a3fad05) function this function can also be used to convert PLC variables with binary data into CSV data fields.

## FUNCTION ARG\_TO\_CSVFIELD: UDINT

## VAR\_INPUT

```
VAR_INPUT  
    in       : T_Arg;  
    bQM      : BOOL;  
    pOutput  : POINTER TO BYTE;  
    cbOutput : UDINT;  
END_VAR
```

**in**: PLC source variable whose value is to be converted into a data field in CSV format (type: [T\_Arg](ms-xhelp:///?Id=beckhoff-9414-4e02-83ee-fc21ca340682)).

**bQM**: If this input is TRUE the converted field data are enclosed in quotation marks.

**pOutput:** Start address (pointer) for the output buffer. The buffer address can be determined with the ADR operator. The result data are written into this buffer.

**cbOutput:** The maximum available size of the output buffer in bytes. The length of the output buffer can be determined with the SIZEOF operator.

**Example:**

The following example illustrates how PLC variables of different types can be converted to CSV format and vice versa. With ARG\_TO\_CSVFIELD conversion the result is copied into the byte buffer (field1..field6). With [CSVFIELD\_TO\_ARG](ms-xhelp:///?Id=beckhoff-ecdd-4181-86b0-997b40f67d70) conversion the source data are in the byte buffer (field1..field6), and the result is copied into the TwinCAT PLC variable.

```
PROGRAM P_ArgToConvExample  
VAR  
    (* PLC data to be converted to or from CSV format *)  
    bOperating : BOOL := TRUE;  
    fAxPos     : LREAL := 12.2;  
    nCounter   : UDINT := 7;  
    sName      : T_MaxString := 'Module: "XAF", $04$05, 20';  
    binData    : ARRAY[0..9] OF BYTE := [0, 1, 2, 3, 4, 5, 6, 7, 8, 9];  
    sShort     : STRING(10) := 'XAF';  
  
    (* conversion buffer *)  
    field1 : ARRAY[0..50 ] OF BYTE;  
    field2 : ARRAY[0..50 ] OF BYTE;  
    field3 : ARRAY[0..50 ] OF BYTE;  
    field4 : ARRAY[0..50 ] OF BYTE;  
    field5 : ARRAY[0..50 ] OF BYTE;  
    field6 : ARRAY[0..50 ] OF BYTE;  
  
    cbField1 : UDINT;  
    cbField2 : UDINT;  
    cbField3 : UDINT;  
    cbField4 : UDINT;  
    cbField5 : UDINT;  
    cbField6 : UDINT;  
  
    cbVar1 : UDINT;  
    cbVar2 : UDINT;  
    cbVar3 : UDINT;  
    cbVar4 : UDINT;  
    cbVar5 : UDINT;  
    cbVar6 : UDINT;  
END_VAR
```

```
cbField1 := ARG_TO_CSVFIELD( F_BOOL( bOperating ), TRUE, ADR( field1 ), SIZEOF( field1 ) );  
cbField2 := ARG_TO_CSVFIELD( F_LREAL( fAxPos ), TRUE, ADR( field2 ), SIZEOF( field2 ) );  
cbField3 := ARG_TO_CSVFIELD( F_UDINT( nCounter ), TRUE, ADR( field3 ), SIZEOF( field3 ) );  
cbField4 := ARG_TO_CSVFIELD( F_STRING( sName ), TRUE, ADR( field4 ), SIZEOF( field4 ) );  
cbField5 := ARG_TO_CSVFIELD( F_BIGTYPE( ADR( binData ), SIZEOF( binData ) ), TRUE, ADR( field5 ), SIZEOF( field5 ) );  
cbField6 := ARG_TO_CSVFIELD( F_BIGTYPE( ADR( sShort ), LEN( sShort ) ), TRUE, ADR( field6 ), SIZEOF( field6 ) );  
  
cbVar1 := CSVFIELD_TO_ARG( ADR( field1 ), cbField1, TRUE, F_BOOL( bOperating ) );  
cbVar2 := CSVFIELD_TO_ARG( ADR( field2 ), cbField2, TRUE, F_LREAL( fAxPos ) );  
cbVar3 := CSVFIELD_TO_ARG( ADR( field3 ), cbField3, TRUE, F_UDINT( nCounter ) );  
cbVar4 := CSVFIELD_TO_ARG( ADR( field4 ), cbField4, TRUE, F_STRING( sName ) );  
cbVar5 := CSVFIELD_TO_ARG( ADR( field5 ), cbField5, TRUE, F_BIGTYPE( ADR( binData ), SIZEOF( binData ) ) );  
cbVar6 := CSVFIELD_TO_ARG( ADR( field6 ), cbField6, TRUE, F_BIGTYPE( ADR( sShort ), LEN( sShort ) ) );
```

The result (byte buffer as hexadecimal string):

cbField1 = 3, field1 = '22 01 22'

cbField2 = 10, field2 = '22 66 66 66 66 66 66 28 40 22'

cbField3 = 6, field3 = '22 07 00 00 00 22'

cbField4 = 25, field4 = '22 4D 6F 64 75 6C 65 3A 20 22 22 58 41 46 22 22 2C 20 04 05 2C 20 32 30 22'

cbField5 = 12, field5 = '22 00 01 02 03 04 05 06 07 08 09 22'

cbField6 = 5, field6 = '22 58 41 46 22'

cbVar1 = 1

cbVar2 = 8

cbVar3 = 4

cbVar4 = 22

cbVar5 = 10

cbVar6 = 3

Further information can be found here: [Example: Writing/reading of a CSV file](ms-xhelp:///?Id=beckhoff-5087-4506-bf25-3cb1667c44bf).

## Requirements

| Development environment | Target platform | PLC libraries to be integrated (category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_Utilities (System) |
