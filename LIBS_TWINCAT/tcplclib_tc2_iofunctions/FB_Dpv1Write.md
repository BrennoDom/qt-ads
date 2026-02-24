# FB_Dpv1Write

## Library
tcplclib_tc2_iofunctions

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_IoFunctions](ms-xhelp:///?Id=beckhoff-89f3-4b36-bb70-6247b05e611b)
2. [Function blocks](ms-xhelp:///?Id=beckhoff-a079-48d4-9b63-20dc13645a2c)
3. [Profibus DPV1 (Sinamics)](ms-xhelp:///?Id=beckhoff-405b-4f91-aab8-55ebb5095cec)
4. FB\_Dpv1Write

# FB\_Dpv1Write

![4085744](/tcplclib_tc2_iofunctions/1033/Images/png/9007199314194059__Web.png)

The “FB\_Dpv1Write” function block writes one or more parameters of a Sinamics Profidrive via DPV1 (Profidrive Specification 3.1). The DPV1 write telegram must be created with [F\_CreateDpv1WriteReqPkg](ms-xhelp:///?Id=beckhoff-3a03-4616-b016-35b2ac820923) before a rising edge is present at bExecute. The DPV1 response telegram must be evaluated with [F\_SplitDpv1WriteResPkg](ms-xhelp:///?Id=beckhoff-f36a-4c13-ab40-b646d4ba7a6d) after a falling edge appears at bBusy.

The execution of this function block requires some time, depending on the number of parameters to be read. The function block sends the DPV1 telegram and polls for a response telegram.

## VAR\_INPUT

```
VAR_INPUT  
    bExecute          : BOOL;  
    aNetId            : T_AmsNetId; (* NetID of Profibus Master FC310x/EL6731 *)  
    iProfibusSlaveAdr : USINT; (* DP address of ProfiDrive *)  
    iDriveId          : USINT; (* 1..16 possible *)  
    pDpv1ReqData      : POINTER TO ARRAY [1..iMAX_DPV1_SIZE] OF BYTE;  
    iDpv1ReqDataLen   : UDINT;  
    pDpv1ResData      : POINTER TO ARRAY [1..iMAX_DPV1_SIZE] OF BYTE;  
    iDpv1ResDataLen   : UDINT;  
    tTmOut            : TIME := DEFAULT_ADS_TIMEOUT;  
END_VAR
```

**bExecute**: the block is activated by a positive edge at this input.

**aNetId**: The network address of the Profibus master device (see ADS tab of the Profibus master device in the I/O configuration in the TwinCAT system, type: T\_AmsNetID).

**iProfibusSlaveAdr**: The Profibus slave DP address of the drive. This is an address for several axes, specified in the TwinCAT system in the I/O configuration.

**iDriveID**: The ID is 1 for the controller unit, 2 for the drive object A and 3 for the drive object B of a double/triple drive. The drive ID is set in the starter software. 1 – 16 is possible.

**pDpv1ReqData**: Pointer to an array of 240 bytes containing the DPV1 write telegram. This telegram must be created by the [F\_CreateDpv1WriteReqPkg](ms-xhelp:///?Id=beckhoff-3a03-4616-b016-35b2ac820923) function before the DPV1 write is activated via bExecute.

**iDv1ReqDataLen**: Maximum length of the DPV1 data buffer (240 bytes).

**pDpv1ResData**: Pointer to an array of 240 bytes containing the DPV1 write response telegram. This telegram must be evaluated by the [F\_SplitDpv1WriteResPkg](ms-xhelp:///?Id=beckhoff-f36a-4c13-ab40-b646d4ba7a6d) function after a falling edge appears at bBusy.

**iDv1ResDataLen**: Maximum length of the DPV1 response data buffer (240 bytes).

**tTmOut**: Maximum time allowed for the execution of the command.

## VAR\_OUTPUT

```
VAR_OUTPUT  
    bBusy        : BOOL;  
    bError       : BOOL;  
    bErrorValues : BOOL;  
    iErrId       : UDINT;  
    iErrorClass  : BYTE;  
    iErrorCode   : BYTE;  
END_VAR
```

**bBusy**: This output goes TRUE as soon as the function block is activated via bExecute and remains TRUE as long as the block has not received a response.

**bError**: In case of errors this output goes TRUE and bBusy goes FALSE.

**bErrorValues**: TRUE if the DPV1 write was unsuccessful or only partly successful. The error causes are returned via the error ID (as well as class and code).

**nErrId**: Returns the [ADS error number](ms-xhelp:///?Id=beckhoff-721e-4655-8e94-3548ed43349a) or function-block-specific error numbers if bError = TRUE.

**nErrClass**: Profidrive error class.

**nErrCode**: Profidrive error code.

| Function-block-specific error codes | Description |
| --- | --- |
| 0x2 | incorrect response reference |
| 0x3 | DPV1 write was erroneous or partly erroneous |
| 0x4 | incorrect response ID |
| other error IDs | see ADS error code |

| Error classes | Description | Error code |
| --- | --- | --- |
| 0x0 - 0x9 | reserved | - |
| 0xA | Application errors | 0x0: read error  0x1: write error 0x2: module error  0x3 - 0x7: reserved  0x8: version conflict  0x9: not supported  0xA - 0xF: user-dependent |
| 0xB | Access errors | 0x0: invalid index (no data block DB47, parameter access not supported)  0x1: write length error  0x2: invalid slot  0x3: type conflict  0x4: invalid range  0x5: state conflict (access to DB47 temporarily not possible because of internal process states)  0x6: access denied  0x7: invalid range (write error in the DB47 header) 0x8: invalid parameter  0x9: invalid type  0xA - 0xF: user-dependent |
| 0xC | Resource errors | 0x0: read conflict  0x1: write conflict  0x2: resource busy  0x3: resource not attainable 0x4 - 0x7: reserved  0x8 - 0xF: user-dependent |
| 0xD - 0xF | User-defined errors | - |

## VAR\_IN\_OUT

```
VAR_OUTPUT  
    iRequestRef : USINT; (* 1..127; 0: reserved *)  
END_VAR
```

**iRefRequest**: Reference that is automatically incremented with each telegram. The reference is required for the allocation of the responses to the write/read requests.

## Requirements

| Development environment | Target platform | IO hardware | PLC libraries to be integrated (category group) |
| --- | --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86) | Beckhoff FC310x PCI, CX1500-M310, EL6731 | Tc2\_IoFunctions (IO) |

[TwinCAT 3 | PLC Library: Tc2\_IoFunctions](ms-xhelp:///?Id=beckhoff-89f3-4b36-bb70-6247b05e611b)
