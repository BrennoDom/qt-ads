# FB_SMISyn

## Library
tcplclib_tc2_smi

## Category
Motion Control

# FB\_SMISyn

![35154304](/tcplclib_tc2_smi/1033/Images/gif/9007199328422539__en-US__Web.gif)

The manufacturer code and the drive type are queried.

## VAR\_INPUT

```
bStart           : BOOL;  
dwAddr           : DWORD := 0;  
eAddrType        : E_SMIAddrType := eSMIAddrTypeAddress;  
dwAddrOption     : DWORD := 0;  
eCommandPriority : E_SMICommandPriority := eSMICommandPriorityMiddle;
```

**bStart:** The function block is activated and the command is send by applying a positive edge to this input.

**dwAddr:** [Manufacturer code](ms-xhelp:///?Id=beckhoff-ace2-4a81-9027-372d4eadb3b0) (0-15), address of a device (0-15), bit field (16 bits) for the group addressing or slave ID (32-bit key ID). This input has no meaning if a collective call (broadcast) is sent.

**eAddrType:** Determines whether the input *dwAddr* is evaluated as [manufacturer code](ms-xhelp:///?Id=beckhoff-ace2-4a81-9027-372d4eadb3b0), device address (see [E\_SMIAddrType](ms-xhelp:///?Id=beckhoff-d96f-4154-8b5a-ee3d83f1158a)) or as part of the group address. Addressing via slave ID (*eAddrType = eSMIAddrTypeSlaveId*) is not permitted.

**dwAddrOption:** Reserved for future extensions.

**eCommandPriority:** Priority (high, medium or low) with which the command is processed by the PLC library (see [E\_SMICommandPriority](ms-xhelp:///?Id=beckhoff-aeef-4170-a977-ee991c8e24eb)).

## VAR\_OUTPUT

```
bBusy            : BOOL;  
bError           : BOOL;  
udiErrorId       : UDINT;  
byManufactorCode : BYTE;  
byDriveType      : BYTE;
```

**bBusy:** When the function block is activated the output is set, and it remains active until execution of the command has been completed.

**bError:** This output is switched to TRUE as soon as an error occurs during the execution of a command. The command-specific error code is contained in *udiErrorId*. The output is set back to FALSE by the reactivation of the function block via the *bStart* input.

**udiErrorId:** Contains the command-specific error code of the most recently executed command. It is set back to 0 by the reactivation of the function block via the *bStart* input (see [error codes](ms-xhelp:///?Id=beckhoff-050f-4816-bd32-717f5461c1a7)).

**byManufactorCode:** the [manufacturer code](ms-xhelp:///?Id=beckhoff-ace2-4a81-9027-372d4eadb3b0) (1-14).

**byDriveType:** the type of drive (0-15). The meaning is manufacturer-specific.

## VAR\_IN\_OUT

```
stCommandBuffer : ST_SMICommandBuffer;
```

**stCommandBuffer:** reference to the structure for communication (buffer) with the [FB\_KL6831KL6841Communication()](ms-xhelp:///?Id=beckhoff-0aca-49d9-bce6-66e1853bcec7) function block (see [ST\_SMICommandBuffer](ms-xhelp:///?Id=beckhoff-f0f7-4a8a-a4b0-c7cf3a9ab7f4)).

## Prerequisites

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_SMI from 3.3.5.0 |
