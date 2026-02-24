# AdsErr_TO_TcEventEntry

## Library
tcplclib_tc3_eventlogger

## Category
Motion Control

# AdsErr\_TO\_TcEventEntry

![2630087](/tcplclib_tc3_eventlogger/1033/Images/png/18014408735481611__Web.png)

This function converts a standard ADS error into a TcEventEntry.

## Syntax

Definition:

```
FUNCTION AdsErr_TO_TcEventEntry : BOOL  
VAR_INPUT  
    eErrorId     : E_AdsErr;  
    stEventEntry : REFERENCE TO TcEventEntry;  
END_VAR
```

## 23670787 Inputs

| Name | Type | Description |
| --- | --- | --- |
| eErrorId | E\_AdsErr | Error code to be converted. |
| stEventEntry | REFERENCE TO [TcEventEntry](ms-xhelp:///?Id=beckhoff-4224-46b9-ab9a-b442dc50ef2a) | Outputs the resulting event definition. |

## 11710498 Return value

| Name | Type | Description |
| --- | --- | --- |
| AdsErr\_TO\_TcEventEntry | BOOL | Returns TRUE if the conversion was carried out successfully. |

## Requirements

| Development environment | Target platform | PLC libraries to include |
| --- | --- | --- |
| TwinCAT v3.1.4022.20 | PC or CX (x64, x86, ARM) | Tc3\_EventLogger |
