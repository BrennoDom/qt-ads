# FB_SMISlaveIdCompare

## Library
tcplclib_tc2_smi

## Category
Motion Control

# FB\_SMISlaveIdCompare

![20602375](/tcplclib_tc2_smi/1033/Images/gif/9007199328439563__en-US__Web.gif)

A specified slave ID (32-bit key ID) is compared with the slave ID (32-bit key ID) of one or more drives which is defined on the motor side. The command can also be sent also to several SMI slaves.

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
dwSlaveId        : DWORD := 0;
```

**bStart:** the function block is activated and the command is send by applying a positive edge to this input.

**dwAddr:** [manufacturer code](ms-xhelp:///?Id=beckhoff-ace2-4a81-9027-372d4eadb3b0) (0-15), address of a device (0-15), bit field (16 bits) for the group addressing or slave ID (32-bit key ID). This input has no meaning if a collective call (broadcast) is sent.

**eAddrType:** defines whether the *dwAddr* input is to be evaluated as a [manufacturer code](ms-xhelp:///?Id=beckhoff-ace2-4a81-9027-372d4eadb3b0), the address of a device (see [E\_SMIAddrType](ms-xhelp:///?Id=beckhoff-d96f-4154-8b5a-ee3d83f1158a)), for group addressing or as a slave ID.

**dwAddrOption:** if the SMI device is addressed by slave ID (*eAddrType = eSMIAddrTypeSlaveId*), then the [manufacturer code](ms-xhelp:///?Id=beckhoff-ace2-4a81-9027-372d4eadb3b0) must be specified via this input.

**eCommandPriority:** priority (high, medium or low) with which the command is processed by the PLC library (see [E\_SMICommandPriority](ms-xhelp:///?Id=beckhoff-aeef-4170-a977-ee991c8e24eb)).

**dwSlaveId:** the Slave ID with which the Slave ID on the motor side is compared.

## VAR\_OUTPUT

```
bBusy                                : BOOL;  
bError                               : BOOL;  
udiErrorId                           : UDINT;  
eResSlaveAddrET0AndSlaveIdLTSerachId : E_SMICompResSlaveAddrET0AndSlaveIdLTSearchId;  
eResSlaveAddrET0AndSlaveIdGTSerachId : E_SMICompResSlaveAddrET0AndSlaveIdGTSearchId;  
eResSlaveAddrET0AndSlaveIdETSerachId : E_SMICompResSlaveAddrET0AndSlaveIdETSearchId;  
eResSlaveAddrNE0                     : E_SMICompResSlaveAddrNE0;
```

**bBusy:** When the function block is activated the output is set, and it remains active until execution of the command has been completed.

**bError:** This output is switched to TRUE as soon as an error occurs during the execution of a command. The command-specific error code is contained in *udiErrorId*. The output is set back to FALSE by the reactivation of the function block via the *bStart* input.

**udiErrorId:** Contains the command-specific error code of the most recently executed command. It is set back to 0 by the reactivation of the function block via the *bStart* input (see [error codes](ms-xhelp:///?Id=beckhoff-050f-4816-bd32-717f5461c1a7)).

**eResSlaveAddrET0AndSlaveIdLTSerachId:** For at least one motor / no motor has the address 0 and the slave ID is smaller than the slave ID sought (*dwSlave-Id*) / the value is undefined. (see [E\_SMICompResSlaveAddrET0AndSlaveIdLTSearchId](ms-xhelp:///?Id=beckhoff-5093-456f-a2d2-5abf2683ed90)).

**eResSlaveAddrET0AndSlaveIdGTSerachId:** For at least one motor / no motor the address is 0 and the slave ID is less than the searched slave ID (*dwSlave-Id*) / the value is undefined (see [E\_SMICompResSlaveAddrET0AndSlaveIdGTSearchId](ms-xhelp:///?Id=beckhoff-e5d4-4ea9-a135-c63aabf52bf7)).

**eResSlaveAddrET0AndSlaveIdETSerachId:** For at least one motor / no motor the address is 0 and the slave ID is greater than the searched slave ID (*dwSlave-Id*) / the value is undefined (see [E\_SMICompResSlaveAddrET0AndSlaveIdETSearchId](ms-xhelp:///?Id=beckhoff-67db-47bd-8490-9c471370a229)).

**eResSlaveAddrNE0:** at least one motor / no motor has an address unequal 0 / the value is undefined (see [E\_SMICompResSlaveAddrNE0](ms-xhelp:///?Id=beckhoff-f124-4f32-a49a-0dae18dab14c)).

## VAR\_IN\_OUT

```
stCommandBuffer : ST_SMICommandBuffer;
```

**stCommandBuffer:** reference to the structure for communication (buffer) with the [FB\_KL6831KL6841Communication()](ms-xhelp:///?Id=beckhoff-0aca-49d9-bce6-66e1853bcec7) function block (see [ST\_SMICommandBuffer](ms-xhelp:///?Id=beckhoff-f0f7-4a8a-a4b0-c7cf3a9ab7f4)).

## Examples

The following tables show the results of the function block with different initial situations. In all cases two SMI devices are connected to an SMI terminal and both addresses are greater than 0.

**The slave ID (dwSlaveId) sought lies between the slave IDs of the two drives:**

| Outputs | Meaning |
| --- | --- |
| eResSlaveAddrET0AndSlaveIdLTSerachId = eSMIDiagResAtLeastOneSlaveAddrET0AndSlaveIdLTSearchId | At least one motor has the slave address equal 0 and the slave ID is smaller than the slave ID sought. |
| eResSlaveAddrET0AndSlaveIdGTSerachId = eSMIDiagResAtLeastOneSlaveAddrET0AndSlaveIdGTSearchId | At least one motor has the slave address equal 0 and the slave ID is greater than the slave ID sought. |
| eResSlaveAddrET0AndSlaveIdETSerachId = eSMIDiagResNoSlaveAddrET0AndSlaveIdETSearchId | No motor has the slave address equal 0 and the slave ID is the same as the slave ID sought. |
| eResSlaveAddrNE0 = eSMIDiagResNoSlaveAddrNE0 | No motor has the slave address unequal 0. |

**The slave ID (dwSlaveId) sought is greater than the slave IDs of the two drives:**

| Outputs | Meaning |
| --- | --- |
| eResSlaveAddrET0AndSlaveIdLTSerachId = eSMIDiagResAtLeastOneSlaveAddrET0AndSlaveIdLTSearchId | At least one motor has the slave address equal 0 and the slave ID is smaller than the slave ID sought. |
| eResSlaveAddrET0AndSlaveIdGTSerachId = eSMIDiagResNoSlaveAddrET0AndSlaveIdGTSearchId | No motor has the slave address equal 0 and the slave ID is greater than the slave ID sought. |
| eResSlaveAddrET0AndSlaveIdETSerachId = eSMIDiagResNoSlaveAddrET0AndSlaveIdLTSearchId | No motor has the slave address equal 0 and the slave ID is smaller than the slave ID sought. |
| eResSlaveAddrNE0 = eSMIDiagResNoSlaveAddrNE0 | No motor has the slave address unequal 0. |

**The slave ID (dwSlaveId) sought is smaller than the slave IDs of the two drives:**

| Outputs | Meaning |
| --- | --- |
| eResSlaveAddrET0AndSlaveIdLTSerachId = eSMIDiagResNoSlaveAddrET0AndSlaveIdLTSearchId | No motor has the slave address equal 0 and the slave ID is smaller than the slave ID sought. |
| eResSlaveAddrET0AndSlaveIdGTSerachId = eSMIDiagResAtLeastOneSlaveAddrET0AndSlaveIdGTSearchId | At least one motor has the slave address equal 0 and the slave ID is greater than the slave ID sought. |
| eResSlaveAddrET0AndSlaveIdETSerachId = eSMIDiagResNoSlaveAddrET0AndSlaveIdETSearchId | No motor has the slave address equal 0 and the slave ID is the same as the slave ID sought. |
| eResSlaveAddrNE0 = eSMIDiagResNoSlaveAddrNE0 | No motor has the slave address unequal 0. |

**The slave ID (dwSlaveId) sought is the same as the slave ID of a drive:**

| Outputs | Meaning |
| --- | --- |
| eResSlaveAddrET0AndSlaveIdLTSerachId = eSMIDiagResNoSlaveAddrET0AndSlaveIdLTSearchId | No motor has the slave address equal 0 and the slave ID is smaller than the slave ID sought. |
| eResSlaveAddrET0AndSlaveIdGTSerachId = eSMIDiagResAtLeastOneSlaveAddrET0AndSlaveIdGTSearchId | At least one motor has the slave address equal 0 and the slave ID is greater than the slave ID sought. |
| eResSlaveAddrET0AndSlaveIdETSerachId = eSMIDiagResAtLeastOneSlaveAddrET0AndSlaveIdETSearchId | At least one motor has the slave address equal 0 and the slave ID is the same as the slave ID sought. |
| eResSlaveAddrNE0 = eSMIDiagResNoSlaveAddrNE0 | No motor has the slave address unequal 0. |

## Prerequisites

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_SMI from 3.3.5.0 |
