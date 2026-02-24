# TcEventEntry_TO_HRESULTAdsErr

## Library
tcplclib_tc3_eventlogger

## Category
Motion Control

# TcEventEntry\_TO\_HRESULTAdsErr

![12872118](/tcplclib_tc3_eventlogger/1033/Images/png/5026925707__Web.png)

This function converts a TcEventEntry into a standard ADS error (HRESULT).

## Syntax

Definition:

```
FUNCTION TcEventEntry_TO_HRESULTAdsErr : BOOL  
VAR_INPUT  
    stEventEntry : TcEventEntry;  
    hr           : REFERENCE TO E_HRESULTAdsErr;  
END_VAR
```

## 48740201 Inputs

| Name | Type | Description |
| --- | --- | --- |
| stEventEntry | [TcEventEntry](ms-xhelp:///?Id=beckhoff-4224-46b9-ab9a-b442dc50ef2a) | Event definition to be converted. |
| hr | REFERENCE TO E\_HRESULTAdsErr | Outputs the resulting error code. |

## 36008632 Return value

| Name | Type | Description |
| --- | --- | --- |
| TcEventEntry\_TO\_HRESULTAdsErr | BOOL | Returns TRUE if the conversion was carried out successfully and FALSE if the event class is unknown. |

## Requirements

| Development environment | Target platform | PLC libraries to include |
| --- | --- | --- |
| TwinCAT v3.1.4022.20 | PC or CX (x64, x86, ARM) | Tc3\_EventLogger |
