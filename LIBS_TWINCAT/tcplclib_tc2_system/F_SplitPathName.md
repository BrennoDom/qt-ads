# F_SplitPathName

## Library
tcplclib_tc2_system

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_System](ms-xhelp:///?Id=beckhoff-9909-45da-a773-a2ae0accd61a)
2. [Functions](ms-xhelp:///?Id=beckhoff-b451-4201-bd8f-306f1c54b27f)
3. [General functions](ms-xhelp:///?Id=beckhoff-1e7a-48a5-88e7-caf74e14975e)
4. F\_SplitPathName

# F\_SplitPathName

![40977906](/tcplclib_tc2_system/1033/Images/png/9007199286036363__Web.png)

This function splits a complete path name into its four components. These are stored in the strings named sDrive, sDir, sFileName and sExt.

## FUNCTION F\_SplitPathName : BOOL

```
VAR_INPUT  
    sPathName : T_MaxString;  
END_VAR
```

**sPathName**: Complete file name as string (type: [T\_MaxString](ms-xhelp:///?Id=beckhoff-77e0-4f6f-a54e-eec93d1cd558)) in the form: 'X:\DIR\SUBDIR\FILENAME.EXT'.

```
VAR_IN_OUT  
    sDrive    : STRING(3);  
    sDir      : T_MaxString;  
    sFileName : T_MaxString;  
    sExt      : T_MaxString;  
END_VAR
```

**sDrive**: Drive ID (type: [T\_MaxString](ms-xhelp:///?Id=beckhoff-77e0-4f6f-a54e-eec93d1cd558)) with a colon ('C:', 'A:' etc.).

**sDir**: Directory name (type: [T\_MaxString](ms-xhelp:///?Id=beckhoff-77e0-4f6f-a54e-eec93d1cd558)) including the leading and trailing backslash ('\BC \INCLUDE\', '\SOURCE\' etc.).

**sFileName**: File name (type: [T\_MaxString](ms-xhelp:///?Id=beckhoff-77e0-4f6f-a54e-eec93d1cd558)).

**sExt**: Contains the dot and the file extension (type: [T\_MaxString](ms-xhelp:///?Id=beckhoff-77e0-4f6f-a54e-eec93d1cd558)) (example: '.C', '.EXE' etc.).

| Return parameter | Description |
| --- | --- |
| TRUE | No error |
| FALSE | Error. Check the function parameters. |

**Example for a call in ST:**

The path name: C:\TwinCAT\Plc\Project01\Data.txt is splitted in the following components:

sDrive: = 'C:'  
sDir: '\TwinCAT\Plc\Project01\'  
sFileName: 'Data'  
sExt: '.txt'

```
PROGRAM MAIN  
VAR  
    bSplit     : BOOL;  
    sPathName  : T_MaxString := 'C:\TwinCAT\Plc\Project01\Data.txt';  
    sDrive     : STRING(3);  
    sDir       : T_MaxString;  
    sFileName  : T_MaxString;  
    sExt       : T_MaxString;  
    bSuccess   : BOOL;  
END_VAR  
  
IF bSplit THEN  
    bSplit := FALSE;  
    bSuccess := F_SplitPathName( sPathName := sPathName,  
                sDrive := sDrive,  
                sDir := sDir,  
                sFileName := sFileName,  
                sExt := sExt );  
END_IF
```

## Requirements

| Development environment | Target system type | PLC libraries to include (Category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_System (System) |

[TwinCAT 3 | PLC Library: Tc2\_System](ms-xhelp:///?Id=beckhoff-9909-45da-a773-a2ae0accd61a)
