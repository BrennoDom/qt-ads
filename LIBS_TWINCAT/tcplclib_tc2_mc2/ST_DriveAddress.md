# ST_DriveAddress

## Library
tcplclib_tc2_mc2

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_MC2](ms-xhelp:///?Id=beckhoff-63a7-4c0e-8569-314547c8cffc)
2. [Data types](ms-xhelp:///?Id=beckhoff-683b-4615-8584-914eb091e041)
3. [Status and parameter](ms-xhelp:///?Id=beckhoff-a949-4038-af4c-900da2b41d28)
4. ST\_DriveAddress

# ST\_DriveAddress

This data type contains the ADS access data of a drive device. The data is read with the function block [MC\_ReadDriveAddress](ms-xhelp:///?Id=beckhoff-b4a9-4575-a32b-c3347b2f4e29).

```
TYPE ST_DriveAddress :  
STRUCT  
    NetID        : T_AmsNetId;    (* AMS NetID of the drive as a string *)  
    NetIdBytes   : T_AmsNetIdArr; (* AMS NetID of the drive as a byte array (same information as NetID) *)  
    SlaveAddress : T_AmsPort;     (* slave address of the drive connected to a bus master *)  
    Channel      : BYTE;          (* channel number of the drive *)  
(* new since 2013-04-04 - just available with versions after this date, otherwise zero *)  
    NcDriveId    :DWORD;          (* ID [1..255] of the NC software drive of an axis *)  
    NcDriveIndex   : DWORD;       (* index [0..9] of the NC software drive of an axis *)  
    NcDriveType    : DWORD;       (* type enumeration of the NC software drive of an axis *)  
    NcEncoderId    : DWORD;       (* ID [1..255] of the NC software encoder of an axis *)  
    NcEncoderIndex : DWORD;       (* index [0..9] of the NC software encoder of an axis *)  
    NcEncoderType  : DWORD;       (* type enumeration of the NC encoder drive of an axis *)  
    NcAxisId       : DWORD;       (* ID [1..255] of the NC axis *)  
    NcAxisType     : DWORD;       (* type enumeration of the NC axis *)  
END_STRUCT  
END_TYPE 
```

## Requirements

| Development environment | Target system type | PLC libraries to include |
| --- | --- | --- |
| TwinCAT v3.0.0 | PC or CX (x86 or x64) | Tc2\_MC2 |

[TwinCAT 3 | PLC Library: Tc2\_MC2](ms-xhelp:///?Id=beckhoff-63a7-4c0e-8569-314547c8cffc)
