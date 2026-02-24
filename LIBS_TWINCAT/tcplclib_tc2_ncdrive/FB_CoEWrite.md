# FB_CoEWrite

## Library
tcplclib_tc2_ncdrive

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_NcDrive](ms-xhelp:///?Id=beckhoff-4c50-4727-bae6-a5b8e82c9354)
2. [Function blocks](ms-xhelp:///?Id=beckhoff-725e-4601-b0fd-30492204b699)
3. [General CoE](ms-xhelp:///?Id=beckhoff-7a03-4e27-9ad5-e210a9749acf)
4. [Function blocks for determining current values](ms-xhelp:///?Id=beckhoff-229e-4ae6-96b1-a8a38821b7b4)
5. FB\_CoEWrite

# FB\_CoEWrite

![21351620](/tcplclib_tc2_ncdrive/1033/Images/gif/2299260427__Web.gif)

With the function block FB\_CoEWrite, an object from the object directory of an EtherCAT slave can be written via an SDO (Service Data Object) download. This requires the slave to have a mailbox and to support the CoE (CANopen over EtherCAT) protocol. With the help of the SubIndex and Index parameters a selection is made as to which object should be written. Via CompleteAccess := TRUE the parameter can be written with sub-elements.

## VAR\_INPUT

```
VAR_INPUT  
   sNetId          : T_AmsNetId;(*netID of PC with NC*)  
   iIndex          : WORD;(*CoE object index*)  
   iSubIndex       : BYTE;(*CoE sub index*)  
   pDstBuf         : PVOID;(*Contains the address of the buffer for the received data*)  
   iBufLen         : UDINT;(*Contains the max. number of bytes to be received*)  
   bExecute        : BOOL;(*Function block execution is triggered by a rising edge at this input.*)  
   tTimeout        : TIME := DEFAULT_ADS_TIMEOUT;(*States the time before the function is cancelled.*)  
   bCompleteAccess : BOOL;(*Function block reads the complete object with all sub index*)  
END_VAR
```

**sNetId:** String containing the AMS network ID of the PC. (type: T\_AmsNetId)

**iIndex:** Index of the object that is supposed to be written.

**iSubIndex:** Sub-index of the object that is supposed to be written.

**pDstBuf:** Address (pointer) to the send buffer

**iBufLen:** Maximum available buffer size (in bytes) for the data to be read

**bExecute:** The function block is enabled via a positive edge at this input.

**tTimeout:** Maximum time allowed for the execution of the function block.

**bCompleteAccess**: Via Complete Access the complete object can be accessed at once.

## VAR\_OUTPUT

```
VAR_OUTPUT  
    bBusy         : BOOL;  
    bError        : BOOL;  
    iAdsErrId     : UINT;  
    iCANopenErrId : UINT;  
END_VAR
```

**bBusy**: This output is set when the function block is activated, and remains set until a feedback is received.

**bError**: This output is set after the bBusy output has been reset when an error occurs in the transmission of the command.

**iAdsErrId**: In the event of a set bError output returns the ADS error code.

**iCANopenErrId**: In the event of a set bError output returns the CANopen error code.

## VAR\_IN\_OUT

```
VAR_IN_OUT  
    Axis  :  NCTOPLC_AXIS_REF;  
END_VAR
```

**Axis**: Axis data structure of type NCTOPLC\_AXIS\_REF, which addresses an axis uniquely within the system. Among other things it contains the current status of the axis such as the position, the velocity and the error state.

[TwinCAT 3 | PLC Library: Tc2\_NcDrive](ms-xhelp:///?Id=beckhoff-4c50-4727-bae6-a5b8e82c9354)
