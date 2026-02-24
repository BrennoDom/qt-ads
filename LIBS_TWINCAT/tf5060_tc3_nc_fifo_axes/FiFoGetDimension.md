# FiFoGetDimension

## Library
tf5060_tc3_nc_fifo_axes

## Category
Motion Control

1. [TF5060 TC3 NC FIFO Axes](ms-xhelp:///?Id=beckhoff-8924-4fac-a694-64ecc6ef4125)
2. [PLC Library](ms-xhelp:///?Id=beckhoff-219f-474d-8a6f-c7740a7f9ad9)
3. FiFoGetDimension

# FiFoGetDimension

FiFoGetDimension iChannelId  UDINTbExecute  BOOLtTimeout  TIMEBOOL  bBusyBOOL  bErrUDINT  iErrIdUDINT  iNoOfAxesUDINT  iNoOfFifoEntries

The function block FiFoGetDimension determines the dimensioning, i.e. the number of the axes and the maximum number of FIFO entries in a FIFO channel.

## 57793596 Inputs

```
VAR_INPUT  
    iChannelId  : UDINT;  
    bExecute    : BOOL;  
    tTimeout    : TIME;  
END_VAR
```

| **Name** | **Type** | **Description** |
| --- | --- | --- |
| iChannelId | UDINT | Channel ID of the FIFO channel |
| bExecute | BOOL | Edge-triggered signal for execution of the command |
| tTimeout | TIME | ADS timeout (about 1 second) |

## 50380316 Outputs

```
VAR_OUTPUT  
    bBusy             : BOOL;  
    bErr              : BOOL;  
    iErrId            : UDINT;  
    iNoOfAxes         : UDINT;  
    iNoOfFifoEntries  : UDINT;  
END_VAR
```

| **Name** | **Type** | **Description** |
| --- | --- | --- |
| bBusy | BOOL | Becomes `TRUE` with a rising edge at bExecute, and remains TRUE until the block has executed the command. |
| bErr | BOOL | Becomes `TRUE` if an error occurs while executing the command. |
| iErrId | UDINT | Error number (ADS or NC error number) |
| iNoOfAxes | UDINT | Number of axes for which the FIFO channel has been parameterised. |
| iNoOfFifoEntries | UDINT | Number of FIFO entries for which the FIFO channel has been parameterised. |

## Requirements

| Development environment | Target platform | PLC libraries to be linked |
| --- | --- | --- |
| TwinCAT V3.1.0 | PC or CX (x86 or x64) | Tc2\_NcFifoAxes |

[TF5060 | TwinCAT 3 NC FIFO AXES](ms-xhelp:///?Id=beckhoff-8924-4fac-a694-64ecc6ef4125)
