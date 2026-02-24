# FB_DALIV2x303SetReportTimer

## Library
tcplclib_tc2_dali

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_DALI](ms-xhelp:///?Id=beckhoff-bad6-4627-b8ac-544f0eee130c)
2. [Programming](ms-xhelp:///?Id=beckhoff-1e7b-43d6-a8da-8e0049d24778)
3. [POUs](ms-xhelp:///?Id=beckhoff-3c92-4da6-86d7-db508adfb4f0)
4. [Low-Level commands](ms-xhelp:///?Id=beckhoff-408c-4669-b5d5-6c547023c614)
5. [Part 303 (occupancy sensor)](ms-xhelp:///?Id=beckhoff-467d-4d16-a19c-69660e6a140b)
6. FB\_DALIV2x303SetReportTimer

# FB\_DALIV2x303SetReportTimer

![29135036](/tcplclib_tc2_dali/1033/Images/gif/4414927883__Web.gif)

Sets the value of the REPORT TIMER.

The unit is 1 s. The permissible value range is 1 s to 4 min 15 s.

## VAR\_INPUT

```
bStart            : BOOL;  
nAddr             : BYTE;  
eAddrType         : E_DALIV2AddrType := eDALIV2AddrTypeShort;  
nInstAddr         : BYTE := 0;  
eInstAddrType     : E_DALIV2InstAddrType := eDALIV2InstAddrTypeNumber;  
eCommandPriority  : E_DALIV2CommandPriority := eDALIV2CommandPriorityMiddle;  
nReport           : BYTE := 20;
```

**bStart:** The function block is activated by a positive edge at this input.

**nAddr**: The address of a participating device or of a group.

**eAddrType**: Short address, group address or broadcast (see [E\_DALIV2AddrType](ms-xhelp:///?Id=beckhoff-d59c-42a4-9d77-6cc67c0d1971)).

**nInstAddr**: Address of the instance within the DALI control unit.

**eInstAddrType**: Defines the access mode to the desired instance within the DALI control unit (see [DALIV2InstAddrType](ms-xhelp:///?Id=beckhoff-1db9-435a-aa0b-281c63218c51)).

**eCommandPriority**: Priority (high, medium or low) with which the command is processed by the library (see [E\_DALIV2CommandPriority](ms-xhelp:///?Id=beckhoff-9fcc-400f-b6a8-66e61c15362f)).

**nReport**: Value of the REPORT TIMER [s].

## VAR\_OUTPUT

```
bBusy    : BOOL;  
bError   : BOOL;  
nErrorId : UDINT;
```

**bBusy:** When the function block is activated the output is set, and it remains active until execution of the command has been completed.

**bError:** This output is switched to TRUE as soon as an error occurs during the execution of a command. The command-specific error code is contained in *nErrorId*. Is reset to FALSE by the execution of a command at the inputs.

**nErrorId:** Contains the command-specific error code of the most recently executed command. Is reset to 0 by the execution of a command at the inputs. (See [error codes](ms-xhelp:///?Id=beckhoff-f739-41c2-8ff6-b502954dc54f))

## VAR\_IN\_OUT

```
stCommandBuffer   : ST_DALIV2CommandBuffer;
```

**stCommandBuffer**: Reference to the internal structure for communication with the function block [FB\_KL6821Communication()](ms-xhelp:///?Id=beckhoff-24f5-4307-8c46-040081763250) (KL6821).

## Requirements

| Development environment | required PLC library |
| --- | --- |
| TwinCAT from v3.1.4022.4 | Tc2\_DALI from v3.6.2.0 |

[TwinCAT 3 | PLC Library: Tc2\_DALI](ms-xhelp:///?Id=beckhoff-bad6-4627-b8ac-544f0eee130c)
