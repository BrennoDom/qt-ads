# FB_CSVMemBufferWriter

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# FB\_CSVMemBufferWriter

![33962670](/tcplclib_tc2_utilities/1033/Images/png/9007199290203275__Web.png)

This function block can be used to generate data sets in an external buffer in CSV format from individual data fields. The content of the buffer can then be written into a file, e.g. with the aid of the function blocks for file access. The new data field can be transferred to the block either via the *putValue* variable (string) or via the optional *pValue* and *cbValue* variables, depending on whether data fields without control characters (string), data fields with control character or binary data are to be written into the data set. The function block can generate several data sets in the buffer until the maximum available buffer size is reached. The end of the data set (last data field in the current data set) is automatically appended to the data field if the bCRLF variable was set to TRUE during writing of the data field. The block automatically adds the data field separators. The default data field separator is a semicolon. The separator can be configured from semicolon to comma via the global PLC variable **DEFAULT\_CSV\_FIELD\_SEP**.

## VAR\_INPUT

```
VAR_INPUT  
    eCmd     : E_EnumCmdType := eEnumCmd_First;  
    putValue : T_MaxString := '';  
    pValue   : POINTER TO BYTE := 0;  
    cbValue  : UDINT := 0;  
    bCRLF    : BOOL := FALSE;  
    pBuffer  : POINTER TO BYTE;  
    cbBuffer : UDINT;  
END_VAR
```

**eCmd**: Control parameter for the buffer component (type: [E\_EnumCmdType](ms-xhelp:///?Id=beckhoff-cb91-427b-a901-37149aa7aa27)). eEnumCmd\_First adds the first data field to the buffer, eEnumCmd\_Next adds the next data field. No other parameter values are used.

**putValue**: A new data field as a string (type: T\_MaxString). This input must be an empty string if the optional parameters *pValue* and *cbValue* are used instead of this input.

**pValue**: Optional: Address of an external byte buffer containing the new data field. Together with the cbValue parameter this input can then be used to write a data field with control characters or binary data into the data set, for example. Control characters or binary data in the data field could truncate the *putValue* string at an undesired location and are therefore transferred as a byte buffer. This input must be zero if it is not used.

**cbValue**: Optional: Length of the data field data in the external byte buffer. This input must be zero if it is not used.

**bCRLF**: If this input set the new data field is terminated with a CRLF data set separator. Subsequent data fields belong to the new data set.

**pBuffer**: Address (pointer) for the target buffer variable. The address can be determined with the ADR operator. In this buffer the function block generates the data sets in CSV format.

**cbBuffer**: Maximum available size (in bytes) of the target buffer variables. The size can be determined with the SIZEOF operator.

## VAR\_OUTPUT

```
VAR_OUTPUT  
    bOk      : BOOL;  
    cbSize   : UDINT;  
    cbFree   : UDINT;  
    nFields  : UDINT;  
    nRecords : UDINT;  
    cbWrite  : UDINT;  
END_VAR
```

**bOk**: TRUE = success, FALSE = buffer overflow or faulty input parameters.

**cbSize**: Current buffer fill status (number of data bytes created in the buffer).

**cbFree**: Number of free data bytes in the buffer.

**nFields**: Number of written data fields.

**nRecords**: Number of written data sets.

**cbWrite**: Number of last written data bytes (length of the last data field + any data set or data field separators).

**Example:**

See: [Example: Writing/reading of a CSV file.](ms-xhelp:///?Id=beckhoff-5087-4506-bf25-3cb1667c44bf)

## Requirements

| Development environment | Target platform | PLC libraries to be integrated (category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_Utilities (System) |
