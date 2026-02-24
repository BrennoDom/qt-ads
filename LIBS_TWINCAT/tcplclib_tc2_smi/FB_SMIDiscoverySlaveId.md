# FB_SMIDiscoverySlaveId

## Library
tcplclib_tc2_smi

## Category
Motion Control

# FB\_SMIDiscoverySlaveId

![61337593](/tcplclib_tc2_smi/1033/Images/gif/9007199328432267__en-US__Web.gif)

The first drive is sought that corresponds to the specified manufacturer code and has the address 0. This function block is used in the addressing of SMI devices and is used in the [FB\_SMIAddressing()](ms-xhelp:///?Id=beckhoff-9403-414a-8dad-6e9bbab3f426) function block.

## VAR\_INPUT

```
bStart         : BOOL;  
bCancel        : BOOL;  
byManufacturer : BYTE := 0;  
dwOptions      : DWORD := 0;
```

**bStart:** the function block is activated and the search is started by applying a positive edge to this input.

**bCancel:** the function block is deactivated and the search is aborted on applying a positive edge to this input.

**byManufacturer:** the [manufacturer code](ms-xhelp:///?Id=beckhoff-ace2-4a81-9027-372d4eadb3b0) specified for the search for the SMI device. Some SMI devices do not permit the manufacturer code 0.

**dwOptions:** reserved for future extensions.

## VAR\_OUTPUT

```
bBusy                                : BOOL;  
bError                               : BOOL;  
udiErrorId                           : UDINT;  
dwCurrentSearchSlaveId               : DWORD;  
eResSlaveAddrET0AndSlaveIdLTSerachId : E_SMICompResSlaveAddrET0AndSlaveIdLTSearchId;  
eResSlaveAddrET0AndSlaveIdGTSerachId : E_SMICompResSlaveAddrET0AndSlaveIdGTSearchId;  
eResSlaveAddrET0AndSlaveIdETSerachId : E_SMICompResSlaveAddrET0AndSlaveIdETSearchId;  
eResSlaveAddrNE0                     : E_SMICompResSlaveAddrNE0;
```

**bBusy:** When the function block is activated the output is set, and it remains active until execution of the command has been completed.

**bError:** This output is switched to TRUE as soon as an error occurs during the execution of a command. The command-specific error code is contained in *udiErrorId*. The output is set back to FALSE by the reactivation of the function block via the *bStart* input.

**udiErrorId:** Contains the command-specific error code of the most recently executed command. It is set back to 0 by the reactivation of the function block via the *bStart* input (see [error codes](ms-xhelp:///?Id=beckhoff-050f-4816-bd32-717f5461c1a7)).

**dwCurrentSearchSlaveId:** as soon as the execution of the function block has ended (*bBusy* changes from TRUE to FALSE) this output indicates the slave ID of the SMI device found.

**eResSlaveAddrET0AndSlaveIdLTSerachId:** For at least one motor / no motor has the address 0 and the slave ID is smaller than the slave ID sought (*dwSlave-Id*) / the value is undefined. (see [E\_SMICompResSlaveAddrET0AndSlaveIdLTSearchId](ms-xhelp:///?Id=beckhoff-5093-456f-a2d2-5abf2683ed90)).

**eResSlaveAddrET0AndSlaveIdGTSerachId:** For at least one motor / no motor the address is 0 and the slave ID is less than the searched slave ID (*dwSlave-Id*) / the value is undefined (see [E\_SMICompResSlaveAddrET0AndSlaveIdGTSearchId](ms-xhelp:///?Id=beckhoff-e5d4-4ea9-a135-c63aabf52bf7)).

**eResSlaveAddrET0AndSlaveIdETSerachId:** For at least one motor / no motor the address is 0 and the slave ID is greater than the searched slave ID (*dwSlave-Id*) / the value is undefined (see [E\_SMICompResSlaveAddrET0AndSlaveIdETSearchId](ms-xhelp:///?Id=beckhoff-67db-47bd-8490-9c471370a229)).

**eResSlaveAddrNE0:** at least one motor / no motor has an address unequal 0 / the value is undefined (see [E\_SMICompResSlaveAddrNE0](ms-xhelp:///?Id=beckhoff-f124-4f32-a49a-0dae18dab14c)).

## VAR\_IN\_OUT

```
stCommandBuffer : ST_SMICommandBuffer;
```

**stCommandBuffer:** reference to the structure for communication (buffer) with the [FB\_KL6831KL6841Communication()](ms-xhelp:///?Id=beckhoff-0aca-49d9-bce6-66e1853bcec7) function block (see [ST\_SMICommandBuffer](ms-xhelp:///?Id=beckhoff-f0f7-4a8a-a4b0-c7cf3a9ab7f4)).

## Prerequisites

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_SMI from 3.3.5.0 |
