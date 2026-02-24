# ST_MBUS_Communication

## Library
tcplclib_tc2_mbus

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_MBus](ms-xhelp:///?Id=beckhoff-18e3-4e49-a9fc-7977791d6960)
2. [Programming](ms-xhelp:///?Id=beckhoff-3a96-436d-9f67-e2d673372cb2)
3. [DUTs](ms-xhelp:///?Id=beckhoff-150e-454f-9b9c-2dace1ed642c)
4. [Structures](ms-xhelp:///?Id=beckhoff-4dd1-4d9d-808a-6e4cba67de22)
5. ST\_MBUS\_Communication

# ST\_MBUS\_Communication

Interne Struktur.

This structure is used to link the block [FB\_MBUSKL6781()](ms-xhelp:///?Id=beckhoff-2b5d-4be4-b4d2-353673675260) with the meter blocks. ST\_MBUS\_Communication).

```
TYPE ST_MBUS_Communication :  
STRUCT  
  bStart           : BOOL;  
  bBusy            : BOOL;  
  bSND_NKE         : BOOL;  
  bSend            : BOOL;  
  bStartManuell    : BOOL;  
  bBlockadeSecAdr  : BOOL;  
  usiAddress       : USINT;  
  byCField         : BYTE;  
  stSecAdr         : ST_MBUS_SecAdr;  
  eError           : E_MBUS_ERROR;  
  eBaudrate        : E_MBUS_Baudrate := eMBUS_Baud2400;  
  arrMBusLongFrame : ARRAY[1..260] OF BYTE;  
  bySendByte       : BYTE;  
  uiMaxCount       : UINT;  
  uiCount          : UINT;  
  stKomRxBuffer    : ST_KL6781ComBuffer;  
  stKomTxBuffer    : ST_KL6781ComBuffer;  
END_STRUCT  
END_TYPE
```

**bStart:** Start.

**bBusy:** This bit is set for as long as the block is active.

**bSND\_NKE:** SND\_NKE is sent.

**bSend:** Data is being sent.

**bStartManuell:** Manual start.

**bBlockadeSecAdr:** Secondary addressing results in blocking.

**usiAddress:** Primary address.

**byCField:** C field.

**stSecAdr:**  Secondary address (see [ST\_MBUS\_SecAdr](ms-xhelp:///?Id=beckhoff-a78a-4fca-b07d-b2756fa9e090)).

**eError:** Error number (see [E\_MBUS\_ERROR](ms-xhelp:///?Id=beckhoff-4cab-465a-91d8-d2f9ff9e69d9)).

**eBaudrate:** Baud rate (see [E\_MBUS\_Baudrate](ms-xhelp:///?Id=beckhoff-9ee5-43e2-8e09-418785a2cd23)).

**arrMBusLongFrame:** Sent or received bytes.

**bySendByte:** Number of sent bytes.

**uiMaxCount:** Maximum number of read commands.

**uiCount:** Current read command.

**stKomRxBuffer:** Receive buffer.

**stKomTxBuffer:** Send buffer.

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_MBus from 3.3.4.0 |

[TwinCAT 3 | PLC Library: Tc2\_MBus](ms-xhelp:///?Id=beckhoff-18e3-4e49-a9fc-7977791d6960)
