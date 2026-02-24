# FB_SMIPos1Write

## Library
tcplclib_tc2_smi

## Category
Motion Control

# FB\_SMIPos1Write

![28290863](/tcplclib_tc2_smi/1033/Images/gif/9007199328405515__en-US__Web.gif)

Writes the fixed position *Pos1* which is configurable on the motor side. *Pos1* can be changed using the [FB\_SMIPos1Read()](ms-xhelp:///?Id=beckhoff-177a-4c70-9de2-35e9ca93915c) block.

## VAR\_INPUT

```
bStart           : BOOL;  
dwAddr           : DWORD := 0;  
eAddrType        : E_SMIAddrType := eSMIAddrTypeAddress;  
dwAddrOption     : DWORD := 0;  
eCommandPriority : E_SMICommandPriority := eSMICommandPriorityMiddle;  
wPosition        : WORD := 0;
```

**bStart:** the function block is activated and the command is send by applying a positive edge to this input.

**dwAddr:** [manufacturer code](ms-xhelp:///?Id=beckhoff-ace2-4a81-9027-372d4eadb3b0) (0-15), address of a device (0-15), bit field (16 bits) for the group addressing or slave ID (32-bit key ID). This input has no meaning if a collective call (broadcast) is sent.

**eAddrType:** defines whether the *dwAddr* input is to be evaluated as a [manufacturer code](ms-xhelp:///?Id=beckhoff-ace2-4a81-9027-372d4eadb3b0), the address of a device (see [E\_SMIAddrType](ms-xhelp:///?Id=beckhoff-d96f-4154-8b5a-ee3d83f1158a)), for group addressing or as a slave ID.

**dwAddrOption:** if the SMI device is addressed by slave ID (*eAddrType = eSMIAddrTypeSlaveId*), then the [manufacturer code](ms-xhelp:///?Id=beckhoff-ace2-4a81-9027-372d4eadb3b0) must be specified via this input.

**eCommandPriority:** priority (high, medium or low) with which the command is processed by the PLC library (see [E\_SMICommandPriority](ms-xhelp:///?Id=beckhoff-aeef-4170-a977-ee991c8e24eb)).

**wPosition:** the new fixed position *Pos1*. The value 0 corresponds here to the upper final position and the value 65535 (0xFFFF) to the lower final position.

## VAR\_OUTPUT

```
bBusy      : BOOL;  
bError     : BOOL;  
udiErrorId : UDINT;
```

**bBusy:** When the function block is activated the output is set, and it remains active until execution of the command has been completed.

**bError:** This output is switched to TRUE as soon as an error occurs during the execution of a command. The command-specific error code is contained in *udiErrorId*. The output is set back to FALSE by the reactivation of the function block via the *bStart* input.

**udiErrorId:** Contains the command-specific error code of the most recently executed command. It is set back to 0 by the reactivation of the function block via the *bStart* input (see [error codes](ms-xhelp:///?Id=beckhoff-050f-4816-bd32-717f5461c1a7)).

## VAR\_IN\_OUT

```
stCommandBuffer : ST_SMICommandBuffer;
```

**stCommandBuffer:** reference to the structure for communication (buffer) with the [FB\_KL6831KL6841Communication()](ms-xhelp:///?Id=beckhoff-0aca-49d9-bce6-66e1853bcec7) function block (see [ST\_SMICommandBuffer](ms-xhelp:///?Id=beckhoff-f0f7-4a8a-a4b0-c7cf3a9ab7f4)).

## Prerequisites

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_SMI from 3.3.5.0 |
