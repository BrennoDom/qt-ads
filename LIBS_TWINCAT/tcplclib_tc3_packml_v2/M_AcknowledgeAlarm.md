# M_AcknowledgeAlarm

## Library
tcplclib_tc3_packml_v2

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc3\_PackML\_V2](ms-xhelp:///?Id=beckhoff-962e-4424-bd3f-3a66f7e32e10)
2. [Packaging Machine State](ms-xhelp:///?Id=beckhoff-bf11-4534-b5f5-a9e819d4a1bd)
3. [Function Blocks](ms-xhelp:///?Id=beckhoff-ee52-4b21-b081-24a6fe023487)
4. [General](ms-xhelp:///?Id=beckhoff-0b63-427b-93e8-5ba0760ccf9f)
5. [PML\_AdminAlarm](ms-xhelp:///?Id=beckhoff-58eb-4578-8bb4-ab9891ebfb68)
6. M\_AcknowledgeAlarm

# M\_AcknowledgeAlarm

This method acknowledges an alarm in the Admin-Tags. Alarm[].Trigger is set to FALSE and the value from Admin.PlcDateTime is entered in Alarm[].AckDateTime. The method returns TRUE if the alarm was found and acknowledged successfully. Acknowledging the alarm does not delete it. The alarm remains in the Alarm array until an M\_ClearAlarm has been called, then it is moved to the AlarmHistory array. If the AlarmHistory array is already full of entries, the oldest entry is deleted as a result.

|  |  |
| --- | --- |
| 47893437 | So that a valid timestamp can be entered, the function block PML\_AdminTime should be called cyclically in the program. |

## Syntax

```
METHOD M_AcknowledgeAlarm : BOOL  
VAR_IN_OUT  
  stAdmin          : ST_PMLa;  
END_VAR  
VAR_INPUT  
  stAlarm          : ST_Alarm;  
END_VAR
```

Sample call:

```
AlarmAcknowledged := fbAdminAlarm.M_AcknowledgeAlarm(stAdmin := PackTags.Admin, stAlarm := Alarm);
```

## Requirements

| Development environment | Target system type | PLC libraries to include |
| --- | --- | --- |
| TwinCAT v3.1 Build 4018 and higher | PC (i386) | Tc3\_PackML\_V2 |

[TwinCAT 3 | PLC Library: Tc3\_PackML\_V2](ms-xhelp:///?Id=beckhoff-962e-4424-bd3f-3a66f7e32e10)
