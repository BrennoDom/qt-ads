# FB_SMIAddressing

## Library
tcplclib_tc2_smi

## Category
Motion Control

# FB\_SMIAddressing

![59011071](/tcplclib_tc2_smi/1033/Images/gif/9007199328429835__en-US__Web.gif)

This function block addresses the connected SMI devices according to the random principle. The user has no influence over which address is assigned to which SMI device. The addresses are assigned in descending order, starting with the address specified by the *byHighestAddress* parameter.

Applying a positive edge to the *bStart* input starts the function block, and the *bBusy* output goes TRUE. The function block now independently addresses all SMI devices. The output variable arrAddressedDevices provides information which SMI devices have already received an address. Once all SMI devices have been addressed, the *bBusy* output goes FALSE again. Addressing can be aborted through a positive edge at input *bCancel*. Processing this function block can take several minutes, depending on how many SMI devices are connected.

## VAR\_INPUT

```
bStart           : BOOL;  
bCancel          : BOOL;  
byHighestAddress : BYTE := 15;  
dwOptions        : DWORD := 0;
```

**bStart:** the function block is activated and the command is send by applying a positive edge to this input.

**bCancel:** the function block is deactivated and the search is aborted on applying a positive edge to this input.

**byHighestAddress:** address from which the SMI devices are addressed in descending order (0-15).

**dwOptions:** reserved for future extensions.

## VAR\_OUTPUT

```
bBusy                  : BOOL;  
bError                 : BOOL;  
udiErrorId             : UDINT;  
dwCurrentSearchSlaveId : DWORD;  
byCurrentManufacturer  : BYTE;  
byCurrentSlaveAddr     : BYTE;  
arrAddressedDevices    : ARRAY [0..15] OF BOOL;
```

**bBusy:** When the function block is activated the output is set, and it remains active until execution of the command has been completed.

**bError:** This output is switched to TRUE as soon as an error occurs during the execution of a command. The command-specific error code is contained in *udiErrorId*. The output is set back to FALSE by the reactivation of the function block via the *bStart* input.

**udiErrorId:** Contains the command-specific error code of the most recently executed command. It is set back to 0 by the reactivation of the function block via the *bStart* input (see [error codes](ms-xhelp:///?Id=beckhoff-050f-4816-bd32-717f5461c1a7)).

**dwCurrentSearchSlaveId:** current slave ID used in the search algorithm.

**byCurrentManufacturer:** current [manufacturer code](ms-xhelp:///?Id=beckhoff-ace2-4a81-9027-372d4eadb3b0) used in the search algorithm.

**byCurrentSlaveAddr:** current address used in the search algorithm.

**arrAddressedDevices:** if an address is assigned to an SMI device, then the corresponding element in the array is set to TRUE.

## VAR\_IN\_OUT

```
stCommandBuffer : ST_SMICommandBuffer;
```

**stCommandBuffer:** reference to the structure for communication (buffer) with the [FB\_KL6831KL6841Communication()](ms-xhelp:///?Id=beckhoff-0aca-49d9-bce6-66e1853bcec7) function block (see [ST\_SMICommandBuffer](ms-xhelp:///?Id=beckhoff-f0f7-4a8a-a4b0-c7cf3a9ab7f4)).

## Prerequisites

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_SMI from 3.3.5.0 |
