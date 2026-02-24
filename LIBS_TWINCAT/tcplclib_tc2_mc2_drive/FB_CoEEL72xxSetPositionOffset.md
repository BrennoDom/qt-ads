# FB_CoEEL72xxSetPositionOffset

## Library
tcplclib_tc2_mc2_drive

## Category
Motion Control

# FB\_CoEEL72xxSetPositionOffset

FB\_CoEEL72xxSetPositionOffset Execute  BOOLPosition  LREALRelative  BOOLFeedback  E\_PositionOffsetFeedbackMemory  E\_PositionOffsetMemory↔Axis  Reference To AXIS\_REFBOOL  BusyBOOL  ErrorUDINT  ErrorID

With the function block FB\_CoEEL72xxSetPositionOffset, a position offset can be stored in the memory of the EL72xx. Saving in the digital name plate of the connected motor encoder is not currently provided for.

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

**Position**: New actual position of the NC axis

**Relative**: When this flag is set, the position is interpreted relatively.

**Feedback**: Enumeration of the type [E\_PositionOffsetFeedback](ms-xhelp:///?Id=beckhoff-8f84-406b-9922-82c9f10e058d). Specifies which feedback is considered.

**Memory**: Enumeration of the type [E\_PositionOffsetMemory](ms-xhelp:///?Id=beckhoff-13bc-45db-a5c4-209330e5980e). Specifies which memory the newly calculated position offset should be stored in.

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

| Development environment | Target platform type | PLC libraries to include | Firmwareversion | Revision |
| --- | --- | --- | --- | --- |
| TwinCAT >4020.57  TwinCAT >4022.30  TwinCAT ≥4024.4 | PC or CX (x86 or x64) | Tc2\_MC2\_Drive ≥V3.3.17.0 | ≥ 19 | ≥0030 |
