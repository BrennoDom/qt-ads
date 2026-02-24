# M_SetStopReason

## Library
tcplclib_tc3_packml_v2

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc3\_PackML\_V2](ms-xhelp:///?Id=beckhoff-962e-4424-bd3f-3a66f7e32e10)
2. [Packaging Machine State](ms-xhelp:///?Id=beckhoff-bf11-4534-b5f5-a9e819d4a1bd)
3. [Function Blocks](ms-xhelp:///?Id=beckhoff-ee52-4b21-b081-24a6fe023487)
4. [General](ms-xhelp:///?Id=beckhoff-0b63-427b-93e8-5ba0760ccf9f)
5. [PML\_AdminAlarm](ms-xhelp:///?Id=beckhoff-58eb-4578-8bb4-ab9891ebfb68)
6. M\_SetStopReason

# M\_SetStopReason

This method inserts a StopReason in the Admin-Tags. StopReason[].Trigger is set to TRUE and the value from Admin.PlcDateTime is entered in StopReason[].DateTime. The other values are taken from the transferred StopReason structure. The method returns TRUE if the StopReason was entered successfully. If the StopReason array is already full of entries, the oldest entry is deleted as a result.

|  |  |
| --- | --- |
| 24946770 | So that a valid timestamp can be entered, the function block PML\_AdminTime should be called cyclically in the program. |

## Syntax

```
METHOD M_SetStopReason : BOOL  
VAR_IN_OUT  
  stAdmin          : ST_PMLa;  
END_VAR  
VAR_INPUT  
  stStopReason     : ST_Alarm;  
END_VAR
```

Sample call:

```
StopReasonInserted := fbAdminAlarm.M_SetStopReason (stAdmin := PackTags.Admin, stStopReason := StopReason);
```

## Requirements

| Development environment | Target system type | PLC libraries to include |
| --- | --- | --- |
| TwinCAT v3.1 Build 4018 and higher | PC (i386) | Tc3\_PackML\_V2 |

[TwinCAT 3 | PLC Library: Tc3\_PackML\_V2](ms-xhelp:///?Id=beckhoff-962e-4424-bd3f-3a66f7e32e10)
