# IOF_SER_IDN_Write

## Library
tcplclib_tc2_iofunctions

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_IoFunctions](ms-xhelp:///?Id=beckhoff-89f3-4b36-bb70-6247b05e611b)
2. [Function blocks](ms-xhelp:///?Id=beckhoff-a079-48d4-9b63-20dc13645a2c)
3. [SERCOS](ms-xhelp:///?Id=beckhoff-3607-4eaf-b256-e8662f77e8c2)
4. IOF\_SER\_IDN\_Write

# IOF\_SER\_IDN\_Write

![46555465](/tcplclib_tc2_iofunctions/1033/Images/png/9007199314101259__Web.png)

The “IOF\_SER\_IDN\_Write” function block allows a value to be written to an S- or P-parameter of a Sercos drive. Data type and size are determined automatically on the basis of the attribute.

## VAR\_INPUT

```
VAR_INPUT  
    sNetId    : T_AmsNetId;  
    nIDN      : UINT; (* S: 0******* ********, P: 1******* ******** *)  
    bExecute  : BOOL;  
    nPort     : UINT;  
    nAttrib   : DWORD;  
    cbLen     : UDINT;  
    dwSrcAddr : PVOID;  
    tTimeout  : TIME := DEFAULT_ADS_TIMEOUT;  
END_VAR
```

**sNetId**: The network address of the TwinCAT computer on which the ADS command is to be executed can be entered here (type: T\_AmsNetId). If it is to be run on the local computer, an empty string can be entered.

**nIDN**: contains the Sercos parameter number to be accessed for writing. nIDN must lie between 0 and 32767 for S-parameters and between 32768 and 65535 for P-parameters.

**bExecute**: the block is activated by a positive edge at this input.

**nPort**: The port number nPort is assigned by the TwinCAT system during the hardware configuration.

**nAttrib**: Attribute of the parameter, if known. If nAttrib = 0, IOF\_SER\_IDN\_Write first reads the parameter attribute of the drive before the value is written to the parameter of the drive.

**cbLen**: Length of the data buffer containing the value.

**dwSrcAddr**: Address of the data buffer containing the value.

**tTimeout**: States the length of the timeout that may not be exceeded during execution of the command.

## VAR\_OUTPUT

```
VAR_OUTPUT  
    nAttribRd : DWORD;  
    sAttrib   : ST_SercosParamAttrib;  
    bBusy     : BOOL;  
    bError    : BOOL;  
    nErrId    : UDINT;  
END_VAR
```

**nAttribRd**: Attribute of the parameter; can be saved for the next access (nAttrib) to the parameter.

**sAttrib**: contains the attribute nAttribRd of the Sercos parameter, broken down into individual variables (type: [ST\_SercosParamAttrib](ms-xhelp:///?Id=beckhoff-f606-4da3-823a-c9773b98cf7e)).

**bBusy**: When the function block is activated this output is set. It remains set until a feedback is received.

**bError**: If an error should occur during the transfer of the command, then this output is set once the bBusy output was reset.

**nErrId**: Supplies the [ADS error number](ms-xhelp:///?Id=beckhoff-721e-4655-8e94-3548ed43349a) when the ERR output is set.

## Requirements

| Development environment | Target platform | IO hardware | PLC libraries to be integrated (category group) |
| --- | --- | --- | --- |
| TwinCAT v3.1.0 | PC (x86) | Sercans SCS-P ISA; Sercans SCS-P PCI; Beckhoff FC750x PCI | Tc2\_IoFunctions (IO) |

[TwinCAT 3 | PLC Library: Tc2\_IoFunctions](ms-xhelp:///?Id=beckhoff-89f3-4b36-bb70-6247b05e611b)
