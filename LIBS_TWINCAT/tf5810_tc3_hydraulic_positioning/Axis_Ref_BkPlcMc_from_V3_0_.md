# Axis_Ref_BkPlcMc (from V3.0)

## Library
tf5810_tc3_hydraulic_positioning

## Category
Motion Control

1. [TwinCAT PLC Hydraulics](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
2. [PLCopen Motion Control](ms-xhelp:///?Id=beckhoff-1ded-451e-88ec-a82873484e92)
3. [Data types](ms-xhelp:///?Id=beckhoff-25bd-4475-8df7-6d29ea7ab5ff)
4. Axis\_Ref\_BkPlcMc (from V3.0)

# Axis\_Ref\_BkPlcMc (from V3.0)

The variables in this structure consolidate the subcomponents of the axis. A variable of this type is transferred to most function blocks of the library. This type therefore corresponds to the AXIS\_REF data type of PLCopen.

```
TYPE Axis_Ref_BkPlcMc:  
STRUCT  
    sAxisName:          STRING(83) := 'NoName';  
    pStAxLogBuffer:     POINTER TO ST_TcMcLogBuffer:=0;  
    pStDeviceInput:     POINTER TO ST_TcPlcDeviceInput:=0;  
    pStDeviceOutput:    POINTER TO ST_TcPlcDeviceOutput:=0;  
    pStAxAuxLabels:     POINTER TO ST_TcMcAuxDataLabels:=0;  
    pStAxAutoParams:    POINTER TO ST_TcMcAutoIdent:=0;  
    pStAxCommandBuf:    POINTER TO ST_TcPlcCmdBuffer_BkPlcMc:=0;  
    nActiveRequest:    UDINT := 0;  
    nNextRequest:      UDINT := 1;  
    bParamsEnable:     BOOL:=FALSE;  
    nState:            E_TcMCFbState:=McState_Standstill;  
    nInitState:        INT:=0;  
    nInitError:        DINT:=0;  
    nInterfaceType:    UINT := 16#FFFF;  
    nDeviceInType:     UINT := 16#FFFF;  
    nDeviceOutType:    UINT := 16#FFFF;  
    nRtDataType:       UINT := 16#FFFF;  
    nParamType:        UINT := 16#FFFF;  
    nLogBufferType:    UINT := 16#FFFF;  
    nAxAutoIdentType:  UINT := 16#FFFF;  
    nCmdBufferType:    UINT := 16#FFFF;  
    nLogLevel:         DINT := 0;  
    nDebugTag:         UDINT := 16#00000000;  
    stAxParams:        ST_TcHydAxParam;  
    stAxRtData:        ST_TcHydAxRtData;  
END_STRUCT  
END_TYPE
```

**sAxisName**: The text name of the axes.

**pStAxLogBuffer**: The address of a variable of type [ST\_TcMcLogBuffer](ms-xhelp:///?Id=beckhoff-2e65-4b91-955d-12cfc3c231b1). This variable contains the LogBuffer of the library.

**pStDeviceInput**: The address of a variable of type [ST\_TcPlcDeviceInput](ms-xhelp:///?Id=beckhoff-dec6-4dd6-a155-f200065a8d2d). This variable contains all input interfaces of the axis.

**pStDeviceOutput**: The address of a variable of type [ST\_TcPlcDeviceOutput](ms-xhelp:///?Id=beckhoff-fec4-45f2-b458-d8180069b32f). This variable contains all output interfaces of the axis.

**pStAxAuxLabels**: The address a variable of type [ST\_TcMcAuxDataLabels](ms-xhelp:///?Id=beckhoff-50c8-4b5f-bdf7-0e14cb1fc422). This variable optionally contains the application parameter IDs in ST\_TcHydAxParam:fCustomerData[..].

**pStAxAutoParams**: The address a variable of type [ST\_TcMcAutoIdent](ms-xhelp:///?Id=beckhoff-d8cd-4957-b2b8-b8cd53f4d9b3). This variable optionally contains the parameters for an [MC\_AxUtiAutoIdent\_BkPlcMc](ms-xhelp:///?Id=beckhoff-6e26-4519-a6b1-d0581db76054) function block.

**pStAxCommandBuf**: From V3.0.8, the input **BufferMode** is available in various function blocks, as defined by PLCopen. The functionality that can be controlled with this is currently in preparation. In this context this command buffer was amended.

**nActiveRequest**: Every function block sets a code here that starts a function on this axis. After this, the function block monitors this variable to see if it is changed by another function block that is taking over control through another function. In this way any function block can tell whether a function that it has started has been interrupted by another function block, and can generate appropriate signals.

**nNextRequest**: Reserved. Used for generating new values for **nActiveRequest**.

**bParamsEnable**: This variable is only TRUE if the parameters have been placed into a valid state by being loaded from the file. Saving the parameters will also assert this signal, because this also ensures consistency between the data in the parameter structure and in the file. The axis is not ready to operate while this variable is not TRUE.

|  |  |
| --- | --- |
| 54861794 | At run-time, write accesses to the parameter structure temporarily set this variable to FALSE, after which it is returned to its previous state. |

**nState**: The current state of the axis is stored here, encoded in accordance with [E\_TcMCFbState](ms-xhelp:///?Id=beckhoff-ec30-4c5a-b456-5a14920f0c0b).

**nInitState**: The current state of the initialization.

**nInitError**: Any error code detected during initialization.

**nInterfaceType**: The type code of the currently valid Axis\_Ref\_BkPlcMc variable type.

**nDeviceInType**: The type code of the currently valid [ST\_TcPlcDeviceInput](ms-xhelp:///?Id=beckhoff-dec6-4dd6-a155-f200065a8d2d) variable type.

**nDeviceOutType**: The type code of the currently valid [ST\_TcPlcDeviceOutput](ms-xhelp:///?Id=beckhoff-fec4-45f2-b458-d8180069b32f) variable type.

**nRtDataType**: The type code of the currently valid [ST\_TcHydAxRtData](ms-xhelp:///?Id=beckhoff-1ffc-4f72-80ec-3f7c8585d12d) variable type.

**nParamType**: The type code of the currently valid [ST\_TcHydAxParam](ms-xhelp:///?Id=beckhoff-12fe-4458-a931-b3c9fca583f2) variable type.

**nLogBufferType**: The type code of the currently valid [ST\_TcMcLogBuffer](ms-xhelp:///?Id=beckhoff-2e65-4b91-955d-12cfc3c231b1) variable type.

**nAxAutoIdentType**: The type code of the currently valid [ST\_TcMcAutoIdent](ms-xhelp:///?Id=beckhoff-d8cd-4957-b2b8-b8cd53f4d9b3) variable type.

**nCmdBufferType**: Reserved. The type code of the currently valid command buffer variable type.

**nLogLevel**: The [message level](ms-xhelp:///?Id=beckhoff-d319-45ac-96c4-54e861345d4c), from which entries in the logging buffer are to be made.

**nDebugTag**: Many library blocks enter a debug ID here for the duration of their execution.

**stAxParams**: This variable of type [ST\_TcHydAxParam](ms-xhelp:///?Id=beckhoff-12fe-4458-a931-b3c9fca583f2) contains the axis parameters.

**stAxRtData**: This variable of type [ST\_TcHydAxRtData](ms-xhelp:///?Id=beckhoff-1ffc-4f72-80ec-3f7c8585d12d) contains the runtime data of the axis.

|  |  |
| --- | --- |
| 23994101 | In order to make the data structures of the library independent of the CPU architecture (I86, Strong ARM), it is necessary to change the order of data or insert placeholders in some places. These placeholders contain a name in the form "bAlign\_1"; the number has no purpose. Neither existence, name, type or dimensioning are guaranteed. |

[TF5810 | TwinCAT 3 Hydraulic Positioning](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
