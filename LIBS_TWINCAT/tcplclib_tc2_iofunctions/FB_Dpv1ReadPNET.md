# FB_Dpv1ReadPNET

## Library
tcplclib_tc2_iofunctions

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_IoFunctions](ms-xhelp:///?Id=beckhoff-89f3-4b36-bb70-6247b05e611b)
2. [Function blocks](ms-xhelp:///?Id=beckhoff-a079-48d4-9b63-20dc13645a2c)
3. [Profinet DPV1 (Sinamics)](ms-xhelp:///?Id=beckhoff-38a9-44b2-a8a7-a6b5d32d9089)
4. FB\_Dpv1ReadPNET

# FB\_Dpv1ReadPNET

![2750866](/tcplclib_tc2_iofunctions/1033/Images/png/9007199314203659__Web.png)

The “FB\_Dpv1ReadPNET” function block reads one or more parameters of a Sinamics Profidrive via DPV1 (Profidrive Specification 3.1) via Profinet. The DPV1 read telegram must be created with [F\_CreateDpv1ReadReqPkgPNET](ms-xhelp:///?Id=beckhoff-c4b4-41b0-9293-93b140220885) before a rising edge is present at bExecute. The DPV1 response telegram must be evaluated with [F\_SplitDpv1ReadResPkgPNET](ms-xhelp:///?Id=beckhoff-3165-49c5-a093-70ac2a37c8be) after a falling edge appears at bBusy.

The execution of this function block requires some time, depending on the number of parameters to be read. The function block sends the DPV1 telegram and polls for a response telegram.

## VAR\_INPUT

```
VAR_INPUT  
    bExecute        : BOOL;(* drive access info *)  
    aNetId          : T_AmsNetId; (* NetID of Profibus Master EL6631 *)  
    iProfinetPort   : UINT; (* Port of ProfiDrive *)  
    iDriveId        : USINT; (* 0..255 possible *)  
    pDpv1ReqData    : POINTER TO ARRAY [1..iMAX_DPV1_SIZE_PNET_REQ] OF BYTE;  
    iDpv1ReqDataLen : UDINT;  
    pDpv1ResData    : POINTER TO ARRAY [1..iMAX_DPV1_SIZE_PNET_RES] OF BYTE;  
    iDpv1ResDataLen : UDINT;  
    tTmOut          : TIME;  
END_VAR
```

**bExecute**: the block is activated by a positive edge at this input.

**aNetId**: The network address of the Profibus master device (see ADS tab of the Profibus master device in the I/O configuration in the TwinCAT system, type: T\_AmsNetID).

**iProfinetPort**: The Profinet port number of the drive. This is an address for several axes, specified in the TwinCAT system in the I/O configuration.

**iDriveID**: The ID is 1 for the controller unit, 2 for the drive object A and 3 for the drive object B of a double/triple drive. The drive ID is set in the starter software. 1 – 16 is possible.

**pDpv1ReqData**: Pointer to an array of 240 bytes containing the DPV1 read telegram. This telegram must be created by the [F\_CreateDpv1ReadReqPkg](ms-xhelp:///?Id=beckhoff-a2a1-41e2-a8af-0f84c11b2d61) function before the DPV1 read is activated via bExecute.

**iDv1ReqDataLen**: Maximum length of the DPV1 data buffer (240 bytes).

**pDpv1ResData**: Pointer to an array of 240 bytes containing the DPV1 read response telegram. This telegram must be evaluated by the [F\_SplitDpv1ReadResPkg](ms-xhelp:///?Id=beckhoff-a74d-44a7-92a3-34916f2e712d) function after a falling edge appears at bBusy.

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

**bErrorValues**: TRUE if the DPV1 read was unsuccessful or only partly successful. The error causes are returned via the error ID (as well as class and code).

**nErrId**: Returns the [ADS error number](ms-xhelp:///?Id=beckhoff-721e-4655-8e94-3548ed43349a) or function-block-specific error numbers if bError = TRUE.

**nErrClass**: Profidrive error class.

**nErrCode**: Profidrive error code.

| Function-block-specific error codes | Description |
| --- | --- |
| 0x2 | incorrect response reference |
| 0x3 | DPV1 read was erroneous or partly erroneous |
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
| TwinCAT v3.1.0 | PC or CX (x86) | Beckhoff EL6632 | Tc2\_IoFunctions (IO) |

[TwinCAT 3 | PLC Library: Tc2\_IoFunctions](ms-xhelp:///?Id=beckhoff-89f3-4b36-bb70-6247b05e611b)
