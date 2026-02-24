# Error codes overview

## Library
tcplclib_tc3_ipcdiag

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc3\_IPCDiag](ms-xhelp:///?Id=beckhoff-3a11-4a24-824c-cda994a70d48)
2. [Error Codes](ms-xhelp:///?Id=beckhoff-2ff2-43df-b121-352c585ea18c)
3. Error codes overview

# Error codes overview

The function blocks in the Tc3\_IPCDiag PLC library feature an output `hrErrorCode`. This value is 4 bytes in size and returns the error code in the event of an error.

An error code is made up of two parts. The error code group, which is represented by the upper two bytes, describes the type of error that has occurred.

| Error code group | Type of error |
| --- | --- |
| 0x EC81 xxxx | Error codes of the Tc3\_IPCDiag PLC library |
| 0x ECA6 xxxx | General IPC diagnostic error codes |
| 0x ECA7 xxxx | API error codes (Win32 error codes) |
| 0x ECA8 xxxx | ADS error codes (TwinCAT ADS error codes) |
| 0x ECAF xxxx | Module-dependent error numbers |

## Error codes of the Tc3\_IPCDiag PLC library

| Code | Meaning |
| --- | --- |
| 0xEC810001 | invalid module list (initialization of IPCDiag required) Probably the instance of FB\_IPCDiag\_Register was not called successfully or it is still pending. |
| 0xEC810002 | module of parameter is unavailable (not existing) |
| 0xEC810003 | parameter is unavailable (not existing) |
| 0xEC810004 | no valid value available (reading is probably pending) |
| 0xEC810005 | allocated buffer is invalid (pointer is zero or buffer size is too small) |
| 0xEC810006 | allocated index is invalid |

## General IPC diagnosis error codes

| Code | Meaning |
| --- | --- |
| 0x00000000 | Success - No Error |
| 0xECA60001 | Fail - Unspecified error |
| 0xECA60100 | Invalid index |
| 0xECA60101 | Invalid access |
| 0xECA60102 | Buffer too small |
| 0xECA60103 | Type not supported |
| 0xECA60104 | Out of memory |
| 0xECA60105 | No data available |
| 0xECA60106 | Invalid data |
| 0xECA60107 | Invalid arg |
| 0xECA60108 | Value out of range |
| 0xECA60200 | Server is busy |
| 0xECA60201 | MDP API not initialized |
| 0xECA60F00 | Not implemented |
| 0xECA61000 | Not supported |
| 0xECA60FFF | Unexpected error |

## Module specific error codes

| Code | Module | Meaning |
| --- | --- | --- |
| 0xECAF0401 | User Mgmt | User already exists |
| 0xECAF0402 | User Mgmt | User does not exist |
| 0xECAF0403 | User Mgmt | Group already exists |
| 0xECAF0404 | User Mgmt | Group does not exist |
| 0xECAF0410 | SMB | Server is not installed |
| 0xECAF0411 | SMB | Share already exists |
| 0xECAF0412 | SMB | Share does not exist |
| 0xECAF0420 | TwinCAT | Ads route already exists |
| 0xECAF0421 | TwinCAT | Ads port could not be opened |
| 0xECAF0430 | Datastore | A variable with this name already exists |
| 0xECAF0431 | Datastore | Variable with requested name does not exist |
| 0xECAF0432 | Datastore | Section with specified name does not exist |
| 0xECAF0433 | Datastore | The name of the variable was invalid |
| 0xECAF0440 | Registry | The name of the key (e.g. "HKLM") was invalid |
| 0xECAF0601 | Display | RESTART/ computer must be restarted for the graphics mode to work |
| 0xECAF0602 | Display | FAILED/ display driver failed specified graphics mode |
| 0xECAF0603 | Display | BADMODE/ graphics mode is not supported |
| 0xECAF0604 | Display | NOTUPDATED/ unable to write settings to the registry |
| 0xECAF0605 | Display | BADFLAGS/ invalid set of flags |
| 0xECAF0606 | Display | BADPARAM/ Invalid parameter or invalid combination of flags |
| 0xECAF0607 | Display | BADDUALVIEW/ System is DualView capable |
| 0xECAF0608 | Display | Com Port not set |
| 0xECAF0609 | Display | Invalid Value |
| 0xECAF0610 | Display | Invalid Command |
| 0xECAF0611 | Display | Invalid Com Port |

## Examples:

```
hrErrorCode = 16#ECA8_0745
```

The error code group is 0xECA8, therefore it is a TwinCAT Ads error.  
With 0x0745 it is therefore a timeout error.

```
hrErrorCode = 16#ECA6_0105
```

The error code group is 0xECA6, therefore it is a general IPC diagnostic error.  
The error 0xECA60105 means "No data available". The selected parameter is not available.

```
hrErrorCode = 16#ECA8_0701
```

The error code group is 0xECA8, therefore it is a TwinCAT Ads error.  
The error 0x0701 means that a service is not supported. The TwinCAT minimal version described in the system requirements is probably not being used.

## ADS error codes

| Code | Meaning |
| --- | --- |
| 0xECA8xxxx | The low word contains a ADS result code |

See also: [ADS Return Codes](ms-xhelp:///?Id=beckhoff-8176-4791-ad7c-09356224e0d1)

## API error codes

| Code | Meaning |
| --- | --- |
| 0xECA7xxxx | The low word contains an error code from a system call. |

See also: [Win32 Error Codes](ms-xhelp:///?Id=beckhoff-83e6-4b25-bd25-d2802bc5ab8b)

[TwinCAT 3 | PLC Library: Tc3\_IPCDiag](ms-xhelp:///?Id=beckhoff-3a11-4a24-824c-cda994a70d48)
