# ST_LON_Communication

## Library
tcplclib_tc2_lon

## Category
Motion Control

# ST\_LON\_Communication

Connection between "FB\_LON\_KL6401" and the send/receive function blocks

```
TYPE ST_LON_Communication :  
STRUCT  
  arrWriteLONdata       : ARRAY[0..iLONBufferSize] OF ST_LON_WriteData;  
  bWrite                : BOOL;  
  bWriteBusy            : BOOL;  
  bReadBusy             : BOOL;  
  arrParameterReadValue : ARRAY[1..32] OF BYTE;  
  wNV_Index             : WORD;  
  eParameterDataType    : E_LON_Parameter_Datatypes;  
  bWriteLONdataToTable  : BOOL;  
  bTerminalOk           : BOOL;  
  byActBuffer           : BYTE;  
  rActBuffer            : REAL;  
  rMaxBuffer            : REAL;  
END_STRUCT  
END_TYPE
```

**arrWriteLONdata:** Send buffer.

**bWrite:** Data is being sent.

**bWriteBusy:** Write-OnChange active.

**bReadBusy:** Read-OnChange active.

**arrParameterReadValue:** 32 data bytes.

**wNV\_Index:** NV index.

**eParameterDataType:** Data type of the LON variable (SNVT) (see [E\_LON parameter data types](ms-xhelp:///?Id=beckhoff-4a34-41ac-b22e-830e7b3c774f)).

**bWriteLONdataToTable:** Writing of the data in the table is active.

**bTerminalOk:** Initialization of the KL6401 was completed successfully.

**byActBuffer:** Number of instructions in the send buffer.

**rActBuffer:** Current utilization of the send buffer in percent.

**rMaxBuffer:** Maximum utilization of the send buffer in percent. The value can be cancelled with the input variable "bResetMaxBuffer".

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_LON from 3.3.4.0 |
