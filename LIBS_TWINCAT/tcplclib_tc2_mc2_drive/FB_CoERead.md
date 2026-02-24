# FB_CoERead

## Library
tcplclib_tc2_mc2_drive

## Category
Motion Control

# FB\_CoERead

FB\_CoERead NetId  T\_AmsNetIDIndex  WORDSubIndex  BYTEpDstBuf  PVOIDBufLen  UDINTExecute  BOOLTimeout  TIMECompleteAccess  BOOL↔Axis  Reference To AXIS\_REFBOOL  BusyBOOL  ErrorUINT  AdsErrIdUINT  CANopenErrId

The function block FB\_CoERead allows data to be read from an object dictionary of an EtherCAT slave through an SDO (Service Data Object) access. This requires the slave to have a mailbox and to support the CoE (CANopen over EtherCAT) protocol. With the help of the SubIndex and Index parameters a selection is made as to which object should be read out. Via CompleteAccess := TRUE the parameter can be read with sub-elements.

```
VAR_INPUT  
   NetId          : T_AmsNetId;(*netID of PC with NC*)  
   Index          : WORD;(*CoE object index*)  
   SubIndex       : BYTE;(*CoE sub index*)  
   pDstBuf        : PVOID;(*Contains the address of the buffer for the received data*)  
   BufLen         : UDINT;(*Contains the max. number of bytes to be received*)  
   Execute        : BOOL;(*Function block execution is triggered by a rising edge at this input.*)  
   Timeout        : TIME := DEFAULT_ADS_TIMEOUT;(*States the time before the function is cancelled.*)  
   CompleteAccess : BOOL;(*Function block reads the complete object with all sub index*)  
END_VAR
```

**NetId:** string, which contains the AMS-Network ID of the PC. (Type: T\_AmsNetId)

**Index:** index of the object that is to be read.

**SubIndex:** subindex of the object that is to be read.

**pDstBuf:** address (pointer) of the receive buffer

**BufLen:** maximum available buffer size (in bytes) for the data to be read

**Execute:** the function block is enabled via a positive edge at this input.

**Timeout:** maximum time that must not be exceeded when the function block is executed.

**CompleteAccess**: via Complete Access the complete object can be accessed at once.

|  |  |
| --- | --- |
| 5677776 | Index and SubIndex can be taken from the corresponding drive documentation. For the AX8000 from Beckhoff see [AX8000 object description](https://infosys.beckhoff.com/content/1033/ax8xxx_object/index.html?id=6839952144388621642). |

## VAR\_OUTPUT

```
VAR_OUTPUT  
    Busy         : BOOL;  
    Error        : BOOL;  
    AdsErrId     : UINT;  
    CANopenErrId : UINT;  
END_VAR
```

**Busy**: This output is set when the function block is activated, and remains set until a feedback is received.

**Error**: This output is set after the Busy output has been reset when an error occurs in the transmission of the command.

**AdsErrId**: In the event of a set error output returns the ADS error code.

**CANopenErrId**: In the event of a set error output returns the CANopen error code.

## VAR\_IN\_OUT

```
VAR_IN_OUT  
   Axis : AXIS_REF;  
END_VAR
```

**Axis**: The axis data structure of type AXIS\_REF addresses an axis unambiguously within the system. Among other things it contains the current status of the axis such as the position, the velocity and the error state.

## Example of an implementation in ST:

```
PROGRAM MAIN  
VAR  
    fbCoERead         : FB_CoERead;  
    NetId             : T_AmsNetId := '';   
    Index             : WORD := 16#1018;  
    SubIndex          : BYTE := 1;   
    Execute           : BOOL := TRUE;  
    Timeout           : TIME := T#5S;  
    CompleteAccess    : BOOL := TRUE;  
    Axis              : AXIS_REF;  
    vendorId          : UDINT := 2;  
    Error             : BOOL;  
    AdsErrId          : UDINT;  
    CANopenErrId      : UDINT;  
END_VAR  
  
fbCoERead(  
    NetId          := NetId,   
    Index          := Index,   
    SubIndex       := SubIndex,   
    pDstBuf        := ADR(vendorId),   
    BufLen         := SIZEOF(vendorId),   
    Execute        := Execute,   
    Timeout        := Timeout,   
    CompleteAccess := CompleteAccess,   
    Axis           := Axis  
);  
  
IF NOT fbCoERead.Busy THEN  
    Error        :=fbCoERead.Error;  
    AdsErrId     :=fbCoERead.AdsErrId;  
    CANopenErrId :=fbCoERead.CANopenErrId;  
    Execute      := FALSE;  
    fbCoERead(Execute := Execute, Axis := Axis);  
END_IF
```
