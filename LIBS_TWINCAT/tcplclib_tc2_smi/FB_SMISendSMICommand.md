# FB_SMISendSMICommand

## Library
tcplclib_tc2_smi

## Category
Motion Control

# FB\_SMISendSMICommand

![11722994](/tcplclib_tc2_smi/1033/Images/gif/9007199328390923__en-US__Web.gif)

This function block is for the general sending of an SMI command. The precise structure of an SMI command and the functioning of the KL6831/KL6841 must be known for this. The use of this function block is necessary only if an SMI command is to be sent that is not covered by the other PLC function blocks.

## VAR\_INPUT

```
bStart                  : BOOL;  
dwAddr                  : DWORD := 0;  
eAddrType               : E_SMIAddrType := eSMIAddrTypeAddress;  
dwAddrOption            : DWORD := 0;  
eCommandPriority        : E_SMICommandPriority := eSMICommandPriorityMiddle;  
eCommandType            : E_SMICommandType := eSMICommandTypeWrite;  
eResponseFormat         : E_SMIResponseFormat := eSMIResponseFormatDiagnosis;  
arrIdentificationBytes  : ARRAY [0..2] OF BYTE;  
arrParameters           : ARRAY [0..2] OF DWORD;  
bSuppressResponseBuffer : BOOL := FALSE;  
dwOptions               : DWORD := 0;
```

**bStart:** The function block is activated by a positive edge at this input.

**dwAddr:** [manufacturer code](ms-xhelp:///?Id=beckhoff-ace2-4a81-9027-372d4eadb3b0) (0-15), address of a device (0-15), bit field (16 bits) for the group addressing or slave ID (32-bit key ID). This input has no meaning if a collective call (broadcast) is sent.

**eAddrType:** defines whether the *dwAddr* input is to be evaluated as a [manufacturer code](ms-xhelp:///?Id=beckhoff-ace2-4a81-9027-372d4eadb3b0), the address of a device (see [E\_SMIAddrType](ms-xhelp:///?Id=beckhoff-d96f-4154-8b5a-ee3d83f1158a)), for group addressing or as a slave ID.

**dwAddrOption:** if the SMI device is addressed by slave ID (*eAddrType = eSMIAddrTypeSlaveId*), then the [manufacturer code](ms-xhelp:///?Id=beckhoff-ace2-4a81-9027-372d4eadb3b0) must be specified via this input.

**eCommandPriority:** priority (high, medium or low) with which the command is processed by the PLC library (see [E\_SMICommandPriority](ms-xhelp:///?Id=beckhoff-aeef-4170-a977-ee991c8e24eb)).

**eCommandType:** Command type: Write/Read (see [E\_SMICommandType](ms-xhelp:///?Id=beckhoff-ce46-4aa7-a633-c141bd3f71f0)). This parameter affects bit 5 of the start byte of the SMI telegram.

**eResponseFormat:** ResponseFormat: Special diagnostic formats/standard (see [E\_SMIResponseFormat](ms-xhelp:///?Id=beckhoff-585b-4dc6-ae2e-5cd98b10e1b5)). This parameter affects bit 6 of the start byte of the SMI telegram.

**arrIdentificationBytes:** an SMI telegram can consist of up to 3 blocks. Each block possesses an identifier byte. Each block possesses an identifier byte.

**arrParameters:** an SMI telegram can consist of up to 3 blocks. Each block possesses up to four value bytes. The value bytes of the individual blocks are defined by this array.

**bSuppressResponseBuffer:** if this input is set to TRUE the internal software buffer is not filled with the responses from the [FB\_KL6831KL6841Communication()](ms-xhelp:///?Id=beckhoff-0aca-49d9-bce6-66e1853bcec7) block.

**dwOptions:** reserved for future expansions.

## VAR\_OUTPUT

```
bBusy                        : BOOL;  
bError                       : BOOL;  
udiErrorId                   : UDINT;  
arrResponseData              : ARRAY [0..7] OF BYTE;  
byResponseDataLength         : BYTE;  
byResponseIdentificationByte : BYTE;
```

**bBusy:** When the function block is activated the output is set, and it remains active until execution of the command has been completed.

**bError:** This output is switched to TRUE as soon as an error occurs during the execution of a command. The command-specific error code is contained in *udiErrorId*. The output is set back to FALSE by the reactivation of the function block via the *bStart* input.

**udiErrorId:** Contains the command-specific error code of the most recently executed command. It is set back to 0 by the reactivation of the function block via the *bStart* input (see [error codes](ms-xhelp:///?Id=beckhoff-050f-4816-bd32-717f5461c1a7)).

**arrResponseData:** the data received from the SMI devices.

**byResponseDataLength:** the length of the data received in bytes.

**byResponseIdentificationByte:** the identifier byte received.

## VAR\_IN\_OUT

```
stCommandBuffer : ST_SMICommandBuffer;
```

**stCommandBuffer:** reference to the structure for communication (buffer) with the [FB\_KL6831KL6841Communication()](ms-xhelp:///?Id=beckhoff-0aca-49d9-bce6-66e1853bcec7) function block (see [ST\_SMICommandBuffer](ms-xhelp:///?Id=beckhoff-f0f7-4a8a-a4b0-c7cf3a9ab7f4)).

## Prerequisites

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_SMI from 3.3.5.0 |
