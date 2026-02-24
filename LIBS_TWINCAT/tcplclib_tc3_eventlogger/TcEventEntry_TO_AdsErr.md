# TcEventEntry_TO_AdsErr

## Library
tcplclib_tc3_eventlogger

## Category
Motion Control

# TcEventEntry\_TO\_AdsErr

![60038205](/tcplclib_tc3_eventlogger/1033/Images/png/18014408735486987__Web.png)

This function converts a TcEventEntry into a standard ADS error.

## Syntax

Definition:

```
FUNCTION TcEventEntry_TO_AdsErr : BOOL  
VAR_INPUT  
    stEventEntry : TcEventEntry;  
    eErrorId     : REFERENCE TO E_AdsErr;  
END_VAR
```

## 3472933 Inputs

| Name | Type | Description |
| --- | --- | --- |
| stEventEntry | [TcEventEntry](ms-xhelp:///?Id=beckhoff-4224-46b9-ab9a-b442dc50ef2a) | Event definition to be converted. |
| eErrorId | REFERENCE TO E\_AdsErr | Outputs the resulting error code. |

## 31256397 Return value

| Name | Type | Description |
| --- | --- | --- |
| TcEventEntry\_TO\_AdsErr | BOOL | Returns TRUE if the conversion was carried out successfully and FALSE if the event class is unknown. |

## Requirements

| Development environment | Target platform | PLC libraries to include |
| --- | --- | --- |
| TwinCAT v3.1.4022.20 | PC or CX (x64, x86, ARM) | Tc3\_EventLogger |
