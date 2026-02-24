# IOF_SER_IDN_Read

## Library
tcplclib_tc2_iofunctions

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_IoFunctions](ms-xhelp:///?Id=beckhoff-89f3-4b36-bb70-6247b05e611b)
2. [Function blocks](ms-xhelp:///?Id=beckhoff-a079-48d4-9b63-20dc13645a2c)
3. [SERCOS](ms-xhelp:///?Id=beckhoff-3607-4eaf-b256-e8662f77e8c2)
4. IOF\_SER\_IDN\_Read

# IOF\_SER\_IDN\_Read

![42455531](/tcplclib_tc2_iofunctions/1033/Images/png/9007199314098059__Web.png)

The “IOF\_SER\_IDN\_Read” function block allows a value to be read from an S- or P-parameter of a Sercos drive. Data type and size are determined automatically on the basis of the attribute.

## VAR\_INPUT

```
VAR_INPUT  
    sNetId     : T_AmsNetId;  
    nIDN       : UINT;  
    bExecute   : BOOL;  
    nPort      : UINT;  
    nMode      : DINT;  
    nAttrib    : DWORD;  
    cbLen      : UDINT;  
    dwDestAddr : PVOID;  
    tTimeout   : TIME := DEFAULT_ADS_TIMEOUT;  
END_VAR
```

**sNetId**: The network address of the TwinCAT computer on which the ADS command is to be executed can be entered here (type: T\_AmsNetId). If it is to be run on the local computer, an empty string can be entered.

**nIDN**: contains the Sercos parameter number to be accessed for reading. nIDN must lie between 0 and 32767 for S-parameters and between 32768 and 65535 for P-parameters.

**bExecute**: the block is activated by a positive edge at this input.

**nPort**: The port number nPort is assigned by the TwinCAT system during the hardware configuration.

**nMode**: The read mode determines which part of the parameter is to be read.  
 nMode = 0: Value  
 nMode = 2: Name  
 nMode = 3: Attribute (always read in order to determine data type and size, unless nAttrib is <> 0)  
 nMode = 4: Unit (not available for every parameter)  
 nMode = 5: Minimum (not available for every parameter)  
 nMode = 6: Maximum (not available for every parameter)

**nAttrib**: Attribute of the parameter, if known. If nAttrib = 0, IOF\_SER\_IDN\_Write first reads the parameter attribute of the drive before the value is written to the parameter of the drive.

**cbLen**: Maximum length of the data buffer that is to accept the value.

**dwDestAddr**: Address of the data buffer that is to accept the value.

**tTimeout**: States the length of the timeout that may not be exceeded during execution of the command.

## VAR\_OUTPUT

```
VAR_OUTPUT  
    cbRead    : UDINT;  
    nAttribRd : DWORD;  
    sAttrib   : ST_SercosParamAttrib;  
    bBusy     : BOOL;  
    bError    : BOOL;  
    nErrId    : UDINT;  
END_VAR
```

**cbRead**: Number of bytes read and copied to dwDestAddr.

**nAttribRd**: Attribute of the parameter; can be saved for the next access (nAttrib) to the parameter.  
**sAttrib**: contains the attribute nAttribRd of the Sercos parameter, broken down into individual variables (type: [ST\_SercosParamAttrib](ms-xhelp:///?Id=beckhoff-f606-4da3-823a-c9773b98cf7e)).  
**bBusy**: When the function block is activated this output is set. It remains set until a feedback is received.

**bError**: If an error should occur during the transfer of the command, then this output is set once the bBusy output was reset.

**nErrId**: Returns the [ADS error number](ms-xhelp:///?Id=beckhoff-721e-4655-8e94-3548ed43349a) or the specific function block error number if the ERR output is set.

| specific function block error number | Description |
| --- | --- |
| 0x1003 | Incorrect parameter mode |
| 0x1004 | Incorrect parameter data size |

## Requirements

| Development environment | Target platform | IO hardware | PLC libraries to be integrated (category group) |
| --- | --- | --- | --- |
| TwinCAT v3.1.0 | PC (x86) | Sercans SCS-P ISA; Sercans SCS-P PCI; Beckhoff FC750x PCI | Tc2\_IoFunctions (IO) |

[TwinCAT 3 | PLC Library: Tc2\_IoFunctions](ms-xhelp:///?Id=beckhoff-89f3-4b36-bb70-6247b05e611b)
