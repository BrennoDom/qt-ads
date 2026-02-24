# FB_AX2000_AXACT

## Library
tcplclib_tc2_iofunctions

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_IoFunctions](ms-xhelp:///?Id=beckhoff-89f3-4b36-bb70-6247b05e611b)
2. [Function blocks](ms-xhelp:///?Id=beckhoff-a079-48d4-9b63-20dc13645a2c)
3. [AX200x Profibus](ms-xhelp:///?Id=beckhoff-348f-457a-b6d5-7c82d7b5dd86)
4. FB\_AX2000\_AXACT

# FB\_AX2000\_AXACT

![17778899](/tcplclib_tc2_iofunctions/1033/Images/gif/9007199314136459__Web.gif)

## VAR\_IN\_OUT

```
VAR_IN_OUT  
    stPZDIN    : ST_PZD_IN;  
    stPZDOUT   : ST_PZD_OUT;  
END_VAR
```

**stPZDIN** : Data words from the drive to the PLC (type: [ST\_PZD\_IN](ms-xhelp:///?Id=beckhoff-6422-417f-94b7-09e221a421f3)).

**stPZDOUT**: Data words from the PLC to the drive (type: [ST\_PZD\_OUT](ms-xhelp:///?Id=beckhoff-260b-4dc5-bd95-54d0ad57159b)).

## VAR\_INPUT

```
VAR_INPUT  
    bMode_DigitalSpeed : BOOL;(*OP-Mode digital speed instead of Positioning*)  
    iDigitalSpeed      : DWORD;(*digital speed if OP-Mode = digital speed*)  
    iVelocity          : DWORD;(*Velocity*)  
    iPosition          : DINT;(*Position*)  
    imotion_tasknumber : WORD;(*number of EEPROM-saved motion-task*)  
    imotion_blocktype  : WORD;(*optional Parameters of motion tasks*)  
    bStart             : BOOL;(*START*)  
    bStop              : BOOL;(*STOP*)  
    bShortStop         : BOOL;(*1: break of motion task, 0: continue same motion task*)  
    bErrorResume       : BOOL;(*Error resume*)  
    tTimeOut           : TIME := DEFAULT_ADS_TIMEOUT;  
END_VAR
```

**bMode\_DigitalSpeed**: This is set if the drive is to be placed in the ‘digital speed’ operating mode during the initialization.

**iDigitalSpeed**: Speed in the ‘digital speed’ operating mode.

**iVelocity** : The parameter contains the required transport speed for a following transport instruction, e.g. µm/s.

**iPosition**: Target position in physical magnitudes, e.g. µm, degrees

**imotion\_tasknumber** : Travel block number. This input can be used to select a travel block that has previously been stored in the drive's memory.

**imotion\_blocktype**: Travel block type (optional). This input can be used to modify properties of a direct travel command.

**bStart**: A rising edge at this boolean input sends a start command to the axis.

**bStop** : A rising edge at this boolean input sends a stop command to the axis. The axis stops and enters the "disabled" state.

**bShortStop** : A rising edge at this boolean input sends a stop command to the axis. The axis stops but remains in the "enabled" state.

**bErrorResume** : A rising edge at this boolean input resets an "AX200X error" (not a time-out error).

**tTimeOut**: Maximum time allowed for the execution of the command.

## VAR\_OUTPUT

```
VAR_OUTPUT  
    bBusy       : BOOL;  
    bError      : BOOL;(*Errorstatus of Servo*)  
    bTimeOutErr : BOOL;  
END_VAR
```

**bBusy**: This output remains TRUE until the block has executed a command. While Busy = TRUE, no new command will be accepted at the inputs. Please note that it is not the execution of the service but its acceptance whose time is monitored.

**bError**: This output shows the error status.

**bTimeOutErr** : TimeOut error.

## Requirements

| Development environment | Target platform | IO hardware | PLC libraries to be integrated (category group) |
| --- | --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86) | AX2000 Profibus box | Tc2\_IoFunctions (IO) |

[TwinCAT 3 | PLC Library: Tc2\_IoFunctions](ms-xhelp:///?Id=beckhoff-89f3-4b36-bb70-6247b05e611b)
