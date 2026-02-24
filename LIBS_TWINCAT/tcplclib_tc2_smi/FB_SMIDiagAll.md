# FB_SMIDiagAll

## Library
tcplclib_tc2_smi

## Category
Motion Control

# FB\_SMIDiagAll

![38398082](/tcplclib_tc2_smi/1033/Images/gif/9007199328393355__en-US__Web.gif)

Using this command it is possible to determine the direction in which the drives are driving, whether they have stopped or whether there is a motor error. The command can also be sent also to several SMI slaves. The states of all SMI slaves can thus be queried with a single command.

The result of the query is forwarded by four outputs. Each of these outputs can assume three states:

* The condition applies to at least one drive.
* The condition does not apply to any drive.
* The condition could not be determined.

Some examples of this are explained further below.

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
bBusy          : BOOL;  
bError         : BOOL;  
udiErrorId     : UDINT;  
eResDrivesUp   : E_SMIDiagResDrivesUp;  
eResDrivesDown : E_SMIDiagResDrivesDown;  
eResIsStopped  : E_SMIDiagResIsStopped;  
eResWithError  : E_SMIDiagResWithError;
```

**bBusy:** When the function block is activated the output is set, and it remains active until execution of the command has been completed.

**bError:** This output is switched to TRUE as soon as an error occurs during the execution of a command. The command-specific error code is contained in *udiErrorId*. The output is set back to FALSE by the reactivation of the function block via the *bStart* input.

**udiErrorId:** Contains the command-specific error code of the most recently executed command. It is set back to 0 by the reactivation of the function block via the *bStart* input (see [error codes](ms-xhelp:///?Id=beckhoff-050f-4816-bd32-717f5461c1a7)).

**eResDrivesUp:** At least one motor is driving up / no motor is driving up / the value is undefined. (see [E\_SMIDiagResDrivesUp](ms-xhelp:///?Id=beckhoff-501a-42a3-8a30-41c964d198b8)).

**eResDrivesDown:** at least one motor is driving down / no motor is driving down / the value is undefined (see [E\_SMIDiagResDrivesDown](ms-xhelp:///?Id=beckhoff-1746-4ec7-b7c7-16cf21c0408c)).

**eResIsStopped:** at least one motor is stopped / no motor is stopped / the value is undefined (see [E\_SMIDiagResIsStopped](ms-xhelp:///?Id=beckhoff-c379-42a5-92f0-880da0e73946)).

**eResWithError:** at least one motor is in an error state / no motor is in an error state / the value is undefined (see [E\_SMIDiagResWithError](ms-xhelp:///?Id=beckhoff-8a96-40f7-9307-157a8912a434)).

## VAR\_IN\_OUT

```
stCommandBuffer : ST_SMICommandBuffer;
```

**stCommandBuffer:** reference to the structure for communication (buffer) with the [FB\_KL6831KL6841Communication()](ms-xhelp:///?Id=beckhoff-0aca-49d9-bce6-66e1853bcec7) function block (see [ST\_SMICommandBuffer](ms-xhelp:///?Id=beckhoff-f0f7-4a8a-a4b0-c7cf3a9ab7f4)).

## Examples

**All drives have stopped:**

| Outputs | Meaning |
| --- | --- |
| eResDrivesUp = eSMIDiagResNoMotorDrivesUp | No drive is driving up. |
| eResDrivesDown = eSMIDiagResNoMotorDrivesDown | No drive is driving down. |
| eResIsStopped = eSMIDiagResAtLeastOneMotorIsStopped | At least one drive has stopped. |
| eResWithError = eSMIDiagResNoMotorWithError | No drive has a motor error. |

**All drives are driving up:**

| Outputs | Meaning |
| --- | --- |
| eResDrivesUp = eSMIDiagResAtLeastOneMotorDrivesUp | At least one drive is driving up. |
| eResDrivesDown = eSMIDiagResNoMotorDrivesDown | No drive is driving down. |
| eResIsStopped = eSMIDiagResNoMotorIsStopped | No drive has stopped. |
| eResWithError = eSMIDiagResNoMotorWithError | No drive has a motor error. |

**One drive has stopped and one drive is driving up:**

| Outputs | Meaning |
| --- | --- |
| eResDrivesUp = eSMIDiagResAtLeastOneMotorDrivesUp | At least one drive is driving up. |
| eResDrivesDown = eSMIDiagResNoMotorDrivesDown | No drive is driving down. |
| eResIsStopped = eSMIDiagResAtLeastOneMotorIsStopped | At least one drive has stopped. |
| eResWithError = eSMIDiagResNoMotorWithError | No drive has a motor error. |

**One drive has stopped, one drive is driving up and one drive is driving down:**

| Outputs | Meaning |
| --- | --- |
| eResDrivesUp = eSMIDiagResAtLeastOneMotorDrivesUp | At least one drive is driving up. |
| eResDrivesDown = eSMIDiagResAtLeastOneMotorDrivesDown | At least one drive is driving down. |
| eResIsStopped = eSMIDiagResAtLeastOneMotorIsStopped | At least one drive has stopped. |
| eResWithError = eSMIDiagResNoMotorWithError | No drive has a motor error. |

## Prerequisites

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_SMI from 3.3.5.0 |
