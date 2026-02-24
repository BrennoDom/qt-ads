# F_CmpLibVersion

## Library
tcplclib_tc2_system

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_System](ms-xhelp:///?Id=beckhoff-9909-45da-a773-a2ae0accd61a)
2. [Functions](ms-xhelp:///?Id=beckhoff-b451-4201-bd8f-306f1c54b27f)
3. [General functions](ms-xhelp:///?Id=beckhoff-1e7a-48a5-88e7-caf74e14975e)
4. F\_CmpLibVersion

# F\_CmpLibVersion

![62725128](/tcplclib_tc2_system/1033/Images/png/9007199286033163__Web.png)

The function F\_CmpLibVersion compares the version of the existing library with the required version. Each library has its own version information as a constant of type: ST\_LibVersion. The name of the constant has the format: stLibVersion\_libraryname.

## FUNCTION F\_CmpLibVersion: DINT

```
VAR_INPUT  
    stVersion   : ST_LibVersion;  
    iMajor      : UINT;  
    iMinor      : UINT;  
    iBuild      : UINT;  
    iRevision   : UINT;  
END_VAR
```

**stVersion**: Version of the existing library (type: ST\_LibVersion).

**iMajor**: Required major number.

**iMinor**: Required minor number.

**iBuild**: Required build number.

**iRevision**: Required revision number.

| Return parameter | Version relationship |
| --- | --- |
| -1 | Your version is lower than the required version |
| 0 | Your version is the required version |
| +1 | Your version is higher than then required version |

**Example in ST**:

```
IF F_CmpLibVersion( stLibVersion_Tc2_System, 3, 3, 8, 0) >= 0 THEN  
    (* newer lib ...*)  
ELSE  
    (* older lib... *)  
END_IF
```

## Requirements

| Development environment | Target system type | PLC libraries to include (Category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_System (System) |

[TwinCAT 3 | PLC Library: Tc2\_System](ms-xhelp:///?Id=beckhoff-9909-45da-a773-a2ae0accd61a)
