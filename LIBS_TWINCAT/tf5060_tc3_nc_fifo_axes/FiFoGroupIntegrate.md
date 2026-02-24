# FiFoGroupIntegrate

## Library
tf5060_tc3_nc_fifo_axes

## Category
Motion Control

1. [TF5060 TC3 NC FIFO Axes](ms-xhelp:///?Id=beckhoff-8924-4fac-a694-64ecc6ef4125)
2. [PLC Library](ms-xhelp:///?Id=beckhoff-219f-474d-8a6f-c7740a7f9ad9)
3. FiFoGroupIntegrate

# FiFoGroupIntegrate

FiFoGroupIntegrate iChannelId  UDINTiAxisId  UDINTiGroupPosition  UDINTbExecute  BOOLtTimeout  TIMEBOOL  bBusyBOOL  bErrUDINT  iErrId

The function block FiFoGroupIntegrate integrates an initially independent PTP axis into a FIFO channel. *iGroupPosition* specifies the logical sequence, and indicates the position within the channel at which the axis is to be inserted.

## 50769665 Inputs

```
VAR_INPUT  
    iChannelId     : UDINT;  
    iAxisId        : UDINT; (* [1..n] *)  
    iGroupPosition : UDINT; (* [1..m] *)  
    bExecute       : BOOL;  
    tTimeout       : TIME;  
END_VAR
```

| **Name** | **Type** | **Description** |
| --- | --- | --- |
| iChannelId | UDINT | Channel ID of the FIFO channel |
| iAxisId | UDINT | Axis ID of an axis that is to be inserted into the FIFO channel |
| iGroupPosition | UDINT | Position of the axis within the FIFO channel (iGroupPosition>=1) |
| bExecute | BOOL | Edge-triggered signal for execution of the command |
| tTimeout | TIME | ADS timeout (about 1 second) |

## 54273802 Outputs

```
VAR_OUTPUT  
    bBusy    : BOOL;  
    bErr     : BOOL;  
    iErrId   : UDINT;  
END_VAR
```

| **Name** | **Type** | **Description** |
| --- | --- | --- |
| bBusy | BOOL | Becomes `TRUE` with a rising edge at bExecute, and remains `TRUE` until the block has executed the command. |
| bErr | BOOL | Becomes `TRUE` if an error occurs while executing the command |
| iErrId | UDINT | Error number (ADS or NC error number) |

## Requirements

| Development environment | Target platform | PLC libraries to be linked |
| --- | --- | --- |
| TwinCAT V3.1.0 | PC or CX (x86 or x64) | Tc2\_NcFifoAxes |

[TF5060 | TwinCAT 3 NC FIFO AXES](ms-xhelp:///?Id=beckhoff-8924-4fac-a694-64ecc6ef4125)
