# FiFoOverwrite

## Library
tf5060_tc3_nc_fifo_axes

## Category
Motion Control

1. [TF5060 TC3 NC FIFO Axes](ms-xhelp:///?Id=beckhoff-8924-4fac-a694-64ecc6ef4125)
2. [PLC Library](ms-xhelp:///?Id=beckhoff-219f-474d-8a6f-c7740a7f9ad9)
3. FiFoOverwrite

# FiFoOverwrite

FiFoOverwrite iChannelId  UDINTAdrDataArray  Pointer To LREALiColDim  UDINTiRowsToWrite  UDINTbExecute  BOOLtTimeout  TIMEBOOL  bBusyBOOL  bErrUDINT  iErrId

The function blockFiFoOverwrite reads position data for *iColDim* FIFO channel axes from *AdrDataArray* and transfers *iRowsToWrite* entries to the FIFO. Existing FIFO data will be overwritten.

## 29992219 Inputs

```
VAR_INPUT  
    iChannelId    : UDINT;  
    AdrDataArray  : POINTER TO LREAL; (* PLC: ARRAY[ ROWS, COLUMNS ] OF LREAL *)  
    iColDim       : UDINT; (* second array dimension (COLUMNS) *)  
    iRowsToWrite  : UDINT; (* number of rows to write <= RowDim *)  
    bExecute      : BOOL;  
    tTimeout      : TIME;  
END_VAR
```

| **Name** | **Type** | **Description** |
| --- | --- | --- |
| iChannelId | UDINT | Channel ID of the FIFO channel |
| AdrDataArray | POINTER TO LREAL | The address of a data field containing position data for the master and slave axes. The first of the field's dimensions describes the table lines, and the second dimension describes the columns. |
| iColDim | UDINT | Number of columns in the data field. This value must correspond to the actual size of the second field dimension. |
| iRowsToWrite | UDINT | Number of table lines. This value may be less than or equal to the size of the first field dimension. |
| bExecute | BOOL | Edge-triggered signal for execution of the command |
| tTimeout | TIME | ADS timeout (about 1 second) |

## 1494521 Outputs

```
VAR_OUTPUT  
    bBusy   : BOOL;  
    bErr    : BOOL;  
    iErrId  : UDINT;  
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
