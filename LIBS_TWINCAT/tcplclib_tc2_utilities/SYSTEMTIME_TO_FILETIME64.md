# SYSTEMTIME_TO_FILETIME64

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# SYSTEMTIME\_TO\_FILETIME64

![3709091](/tcplclib_tc2_utilities/1033/Images/gif/35903883__en-US__Web.gif)

The function can be used to convert the Windows system time structure into the Filetime format. The day of the week wDayOfWeek of the system time variable is ignored. The system time year must be greater than 1601 and less than 30827.

## FUNCTION SYSTEMTIME\_TO\_FILETIME64 : [T\_FILETIME64](ms-xhelp:///?Id=beckhoff-4145-4760-bacf-86b973e5260d)

## VAR\_INPUT

```
VAR_INPUT  
    systemTime : TIMESTRUCT;  
END_VAR
```

**systemTime**: The structure with the Windows system time requiring conversion (type: [TIMESTRUCT](ms-xhelp:///?Id=beckhoff-a743-45b8-ae0d-5212cada81b1)).

| Return parameter | Description |
| --- | --- |
| 0 | Error, wrong system time parameter value. |
| > 0 | No error. File time. |

## Requirements

| Development environment | Target platform | PLC libraries to be integrated (category group) |
| --- | --- | --- |
| TwinCAT v3.1.4024 | PC or CX (x86, x64, ARM) | Tc2\_Utilities (System) >= 3.3.44.0 |
