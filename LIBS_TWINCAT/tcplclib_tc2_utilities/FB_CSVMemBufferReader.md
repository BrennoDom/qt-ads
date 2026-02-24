# FB_CSVMemBufferReader

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# FB\_CSVMemBufferReader

![33599791](/tcplclib_tc2_utilities/1033/Images/png/9007199290200075__Web.png)

This function block can be used to decompose/interpret data sets stored in an external buffer into individual data fields. The buffer data could first be read from a file with the aid of the function blocks for file access, for example. The function block reads the first or the next data field and returns its value either as a string at the *getValue* output or as an address/byte value at the *pValue*/*cbValue* output.

The data in the buffer must have a certain format to ensure that the function block can interpreted them correctly. CRLF (CR=Carriage Return, LF=Line Feed) must be used as a data set separator. The last data set must end with a CRLF. Individual data fields must be separated with the data field separator. The default data field separator is a semicolon. The separator can be configured from semicolon to comma via the global PLC variable **DEFAULT\_CSV\_FIELD\_SEP**.

## VAR\_INPUT

```
VAR_INPUT  
    eCmd     : E_EnumCmdType := eEnumCmd_First;  
    pBuffer  : POINTER TO BYTE;  
    cbBuffer : UDINT;  
END_VAR
```

**eCmd**: Control parameter for the buffer component (type: [E\_EnumCmdType](ms-xhelp:///?Id=beckhoff-cb91-427b-a901-37149aa7aa27)). eEnumCmd\_First reads the first data field, eEnumCmd\_Next reads the next data field. No other parameter values are used.

**pBuffer**: Address (pointer) for the source buffer variable. The address can be determined with the ADR operator. This buffer contains the data set/data field data to be read.

**cbBuffer**: The byte size of the data to be interpreted in the source buffer (data set/data field data). The buffer size may be much larger than the amount of data to be interpreted. Please enter the actual length of the data to be interpreted.

## VAR\_OUTPUT

```
VAR_OUTPUT  
    bOk      : BOOL;  
    getValue : T_MaxString := '';  
    pValue   : POINTER TO BYTE := 0;  
    cbValue  : UDINT := 0;  
    bCRLF    : BOOL := FALSE;  
    cbRead   : UDINT := 0;  
END_VAR
```

**bOk**: TRUE = Success, FALSE = faulty data/faulty input parameters, or the end of the data was reached and no further data field could be read.

**getValue**: The last read data field as a string (type: T\_MaxString). For data fields without control characters and binary data this output returns the complete data field as a zero-terminated string. Data fields with control characters or binary data may lead to an incomplete string being returned at this output. In this case the outputs *pValue/cbValue* are used to access the last read data field.

**pValue**: Address (pointer) to the first data byte in the data field. Please note that empty void data fields are not terminated with zero (as is usual for a PLC string) and therefore have no data. In this case the address is zero.

**cbValue**: Data field length in bytes. Please note that empty void data fields are not terminated with zero (as is usual for a PLC string) and therefore have no data. The length is also zero in this case.

**bCRLF**: This output is set if the end of the data set was reached during the last read command. The last read data field belongs to the previous data set. The next data field belongs to a new data set.

**cbRead**: Number of successfully read/interpreted data bytes. This number may be greater than the data field length at the *cbValue* output. The length at the *cbRead* output includes the interpreted data field/data set separators.

**Example:**

See: [Example: Writing/reading of a CSV file.](ms-xhelp:///?Id=beckhoff-5087-4506-bf25-3cb1667c44bf)

## Requirements

| Development environment | Target platform | PLC libraries to be integrated (category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_Utilities (System) |
