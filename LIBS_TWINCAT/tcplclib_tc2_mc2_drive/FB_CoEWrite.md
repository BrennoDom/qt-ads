# FB_CoEWrite

## Library
tcplclib_tc2_mc2_drive

## Category
Motion Control

# FB\_CoEWrite

FB\_CoEWrite NetId  T\_AmsNetIDIndex  WORDSubIndex  BYTEpSrcBuf  PVOIDBufLen  UDINTExecute  BOOLTimeout  TIMECompleteAccess  BOOL↔Axis  Reference To AXIS\_REFBOOL  BusyBOOL  ErrorUINT  AdsErrIdUINT  CANopenErrId

With the function block FB\_CoEWrite, an object from the object directory of an EtherCAT slave can be written via an SDO (Service Data Object) download. This requires the slave to have a mailbox and to support the CoE (CANopen over EtherCAT) protocol. With the help of the SubIndex and Index parameters a selection is made as to which object should be written. Via CompleteAccess := TRUE the parameter can be written with sub-elements.

## VAR\_INPUT

```
VAR_INPUT  
   NetId          : T_AmsNetId;(*netID of PC with NC*)  
   Index          : WORD;(*CoE object index*)  
   SubIndex       : BYTE;(*CoE sub index*)  
   pSrcBuf        : PVOID;(*Contains the address of the buffer containing the data to be send*)  
   BufLen         : UDINT;(*Contains the max. number of bytes to be received*)  
   Execute        : BOOL;(*Function block execution is triggered by a rising edge at this input.*)  
   Timeout        : TIME := DEFAULT_ADS_TIMEOUT;(*States the time before the function is cancelled.*)  
   CompleteAccess : BOOL;(*Function block reads the complete object with all sub index*)  
END_VAR
```

**NetId:** string, which contains the AMS-Network ID of the PC (type: T\_AmsNetId).

**Index:** index of the object that is supposed to be written.

**SubIndex:** subindex of the object that is supposed to be written.

**pSrcBuf:** address (pointer) of the transmit buffer

**BufLen:** number of data to be sent in bytes

**Execute:** the function block is enabled via a positive edge at this input.

**Timeout:** maximum time that must not be exceeded when the function block is executed.

**CompleteAccess**: via Complete Access the complete object can be accessed at once.

|  |  |
| --- | --- |
| 51099989 | Index and SubIndex can be taken from the corresponding drive documentation. For the AX8000 from Beckhoff see [AX8000 object description](https://infosys.beckhoff.com/content/1033/ax8xxx_object/index.html?id=6839952144388621642). |

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
    fbCoEWrite     : FB_CoEWrite;  
    NetId          : T_AmsNetId := '';   
    Index          : WORD := 16#1018;  
    SubIndex       : BYTE := 1;   
    Execute        : BOOL := TRUE;  
    Timeout        : TIME := T#5S;  
    CompleteAccess : BOOL := TRUE;  
    Axis           : AXIS_REF;  
    vendorId       : UDINT := 2;  
    Error          : BOOL;  
    AdsErrId       : UDINT;  
    CANopenErrId   : UDINT;END_VAR  
  
fbCoEWrite(  
    NetId          := NetId,   
    Index          := Index,   
    SubIndex       := SubIndex,   
    pSrcBuf        := ADR(vendorId),   
    BufLen         := SIZEOF(vendorId),   
    Execute        := Execute,   
    Timeout        := Timeout,   
    CompleteAccess := CompleteAccess,   
    Axis := Axis  
);  
  
IF NOT fbCoEWrite.Busy THEN  
    Error        := fbCoEWrite.Error;  
    AdsErrId     := fbCoEWrite.AdsErrId;  
    CANopenErrId :=fbCoEWrite.CANopenErrId;  
    Execute      := FALSE;  
    fbCoEWrite(Execute := Execute, Axis := Axis);  
END_IF
```
