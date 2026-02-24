# HRESULTAdsErr_TO_TcEventEntry

## Library
tcplclib_tc3_eventlogger

## Category
Motion Control

# HRESULTAdsErr\_TO\_TcEventEntry

![38285619](/tcplclib_tc3_eventlogger/1033/Images/png/5026921867__Web.png)

This function converts a standard ADS error (HRESULT) into a TcEventEntry.

## Syntax

Definition:

```
FUNCTION HRESULTAdsErr_TO_TcEventEntry : BOOL  
VAR_INPUT  
    hr           : E_HRESULTAdsErr;  
    stEventEntry : REFERENCE TO TcEventEntry;  
END_VAR
```

## 9026257 Inputs

| Name | Type | Description |
| --- | --- | --- |
| hr | E\_HRESULTAdsErr | Error code to be converted. |
| stEventEntry | REFERENCE TO [TcEventEntry](ms-xhelp:///?Id=beckhoff-4224-46b9-ab9a-b442dc50ef2a) | Outputs the resulting event definition. |

## 14127452 Return value

| Name | Type | Description |
| --- | --- | --- |
| HRESULTAdsErr\_TO\_TcEventEntry | BOOL | Returns TRUE if the conversion was carried out successfully.  The call fails if the facility code in the specified HRESULT is unknown. |

## Requirements

| Development environment | Target platform | PLC libraries to include |
| --- | --- | --- |
| TwinCAT v3.1.4022.20 | PC or CX (x64, x86, ARM) | Tc3\_EventLogger |
