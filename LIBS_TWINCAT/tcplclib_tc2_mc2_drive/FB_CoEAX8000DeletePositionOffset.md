# FB_CoEAX8000DeletePositionOffset

## Library
tcplclib_tc2_mc2_drive

## Category
Motion Control

# FB\_CoEAX8000DeletePositionOffset

FB\_CoEAX8000DeletePositionOffset Execute  BOOLFeedback  E\_PositionOffsetFeedbackMemory  E\_PositionOffsetMemory↔Axis  Reference To AXIS\_REFBOOL  BusyBOOL  ErrorUDINT  ErrorID

With the function block FB\_CoEAX8000DeletePositionOffset, a position offset can be deleted from the memory of the AX8000 or from the digital name plate of the connected motor encoder.

## VAR\_INPUT

```
VAR_INPUT  
   Execute  :  BOOL;  
   Position :  LREAL;  
   Relative :  BOOL;  
   Feedback :  E_PositionOffsetFeedback;  
   Memory   :  E_PositionOffsetMemory;  
END_VAR
```

**Execute**: The function block is enabled via a positive edge at this input.

**Position**: New position of the NC axis is displayed.

**Relative**: When this flag is set, the position is interpreted relatively.

**Feedback**: Enumeration of the type [E\_PositionOffsetFeedback](ms-xhelp:///?Id=beckhoff-8f84-406b-9922-82c9f10e058d). Specifies which feedback is considered.

**Memory**: Enumeration of the type [E\_PositionOffsetMemory](ms-xhelp:///?Id=beckhoff-13bc-45db-a5c4-209330e5980e). Specifies the memory from which the position offset is to be deleted.

## VAR\_IN\_OUT

```
VAR_IN_OUT  
   Axis : AXIS_REF;  
END_VAR
```

**Axis**: The axis data structure of type AXIS\_REF addresses an axis unambiguously within the system. Among other things it contains the current status of the axis such as the position, the velocity and the error state.

## VAR\_OUTPUT

```
VAR_OUTPUT  
   Busy     :  BOOL;  
   Error    :  BOOL;  
   ErrorID  :  UDINT;  
END_VAR
```

**Busy**: This output is set when the function block is activated, and remains set until a feedback is received.

**Error**: This output is set after the Busy output has been reset when an error occurs in the transmission of the command.

**ErrorID**: In the event of a set error output returns the ADS error code.

## Requirements

| Development environment | Target platform type | PLC libraries to include |
| --- | --- | --- |
| TwinCAT ≥4020.57  TwinCAT ≥4022.30 | PC or CX (x86 or x64) | Tc2\_MC2\_Drive ≥V3.3.16.0 |
