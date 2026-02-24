# IOF_GetBoxAddrByNameEx

## Library
tcplclib_tc2_iofunctions

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_IoFunctions](ms-xhelp:///?Id=beckhoff-89f3-4b36-bb70-6247b05e611b)
2. [Function blocks](ms-xhelp:///?Id=beckhoff-a079-48d4-9b63-20dc13645a2c)
3. [General IO FBs](ms-xhelp:///?Id=beckhoff-45cd-441d-a862-564f8b5fb3d0)
4. IOF\_GetBoxAddrByNameEx

# IOF\_GetBoxAddrByNameEx

![27870469](/tcplclib_tc2_iofunctions/1033/Images/png/9007199314021259__Web.png)

The IOF\_GetBoxAddrByNameEx function block determines the fieldbus address of a box (box = slave, module, station), knowing the box name and the device name. If no fieldbus address is available, the function block returns a physical or a logical address. (In the case of the Beckhoff Lightbus, for instance, it is the physical box number in the optical fiber ring, while in Profibus it is the station address). The box identifier and the device identifier are passed as strings to the function block, and can be specified by the user during the configuration in the TwinCAT system.

## VAR\_INPUT

```
VAR_INPUT  
    NETID      : T_AmsNetId;  
    DEVICENAME : T_MaxString;  
    BOXNAME    : T_MaxString;  
    START      : BOOL;  
    TMOUT      : TIME := DEFAULT_ADS_TIMEOUT;  
END_VAR
```

**NETID**: The network address of the TwinCAT computer on which the function is to be executed can be entered here (type: T\_AmsNetID). If it is to be run on the local computer, an empty string can be entered.

**DEVICENAME**: The device name of an IO device as a string (type: T\_MaxString).

**BOXNAME**: The box name as a string (type: T\_MaxString).

**START**: the block is activated by a positive edge at this input.

**TMOUT**: States the length of the timeout that may not be exceeded during execution of the command.

## VAR\_OUTPUT

```
VAR_OUTPUT  
    BUSY    : BOOL;  
    ERR     : BOOL;  
    ERRID   : UDINT;  
    BOXADDR : UINT;  
END_VAR
```

**BUSY**: When the function block is activated this output is set. It remains set until a feedback is received.

**ERR**: If an error should occur during the transfer of the command, then this output is set once the BUSY output was reset.

**ERRID**: Supplies the [ADS error number](ms-xhelp:///?Id=beckhoff-721e-4655-8e94-3548ed43349a) when the ERR output is set.

**BOXADDR**: The fieldbus address or logical address of the box.

## Requirements

| Development environment | Target platform | IO hardware | PLC libraries to be integrated (category group) |
| --- | --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | All IO devices | Tc2\_IoFunctions (IO) |

[TwinCAT 3 | PLC Library: Tc2\_IoFunctions](ms-xhelp:///?Id=beckhoff-89f3-4b36-bb70-6247b05e611b)
