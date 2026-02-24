# FB_AX200X_Profibus

## Library
tcplclib_tc2_iofunctions

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_IoFunctions](ms-xhelp:///?Id=beckhoff-89f3-4b36-bb70-6247b05e611b)
2. [Function blocks](ms-xhelp:///?Id=beckhoff-a079-48d4-9b63-20dc13645a2c)
3. [AX200x Profibus](ms-xhelp:///?Id=beckhoff-348f-457a-b6d5-7c82d7b5dd86)
4. FB\_AX200X\_Profibus

# FB\_AX200X\_Profibus

![12156768](/tcplclib_tc2_iofunctions/1033/Images/png/9007199314149259__Web.png)

## VAR\_IN\_OUT

```
VAR_IN_OUT  
    stPZD_IN  : ST_PZD_IN;   
    stPZD_OUT : ST_PZD_OUT;  
END_VAR
```

**stPZD\_IN**: Data words from the drive to the PLC (type: [ST\_PZD\_IN](ms-xhelp:///?Id=beckhoff-6422-417f-94b7-09e221a421f3)).

**stPZD\_OUT**: Data words from the PLC to the drive (type: [ST\_PZD\_OUT](ms-xhelp:///?Id=beckhoff-260b-4dc5-bd95-54d0ad57159b)).

## VAR\_INPUT

```
VAR_INPUT  
    bInit              : BOOL;(*Initialization*)  
    bMode_DigitalSpeed : BOOL;(*OP-Mode digital speed instead of Positioning*)  
    iDigitalSpeed      : DWORD;(*digital speed if OP-Mode = digital speed*)  
    iVelocity          : DWORD;(*Velocity*)  
    iPosition          : DINT;(*Position*)  
    iRunningMode       : BYTE;(*0:digital speed, 1: motiontask, 2: JogMode, 3: Calibration*)  
    imotion_tasknumber : WORD;(*number of EEPROM-saved motion-task*)  
    imotion_blocktype  : WORD:=16#2000;(*optional Parameters of motion tasks, default:SI-values*)  
    iJogModeBasicValue : INT;(*BasicVelocity for JogMode*)  
    iCalVelo           : WORD;(* basic velocity of Calibration*)  
    bSetRefPoint       : BOOL;(* set Reference Point*)  
    bStart             : BOOL;(*START*)  
    bStop              : BOOL;(*STOP*)  
    bShortStop         : BOOL;(* break of motion task*)  
    iSlaveAddress      : BYTE;(* Station Address of the Slave *)  
    iFC310xDeviceId    : WORD;(* Device-ID of the FCxxxx *)  
    bErrorResume       : BOOL;(*Error resume*)  
    tTimeOut           : TIME := DEFAULT_ADS_TIMEOUT;  
END_VAR
```

**bInit**: Initialization of the drive. If bInit is TRUE then operating mode 2, "positioning", is set in the drive.

**bMode\_DigitalSpeed**: This is set if the drive is to be placed in the ‘digital speed’ operating mode during the initialization.

**iDigitalSpeed**: Speed in the ‘digital speed’ operating mode.

**iVelocity** : The parameter contains the required transport speed for a following transport instruction, e.g. µm/s.

**iPosition**: Target position.

**iRunningMode**: 0: digital speed, 1: motiontask, 2: JogMode, 3: Calibration.

**imotion\_tasknumber** : Travel block number. This input can be used to select a travel block that has previously been stored in the drive's memory.

**imotion\_blocktype**: Travel block type (optional). This input can be used to modify properties of a direct travel command.

**iJogModeBasicValue** : Basic speed for jogging mode; the actual speed is derived from the basic speed and the "v-jogging mode" factor for the drive.

**iCalVelo** : Basic speed for the reference travel. The final speed is composed of the basic speed and the "v-jogging mode" factor for the drive.

**bSetRefPoint** : Setting the reference point.

**bStart**: Starting the action, depending on the state of iRunningMode.

**bStop** : Stopping the action, depending on the state of iRunningMode.

**bShortStop** :

**iSlaveAddress**: Station address.

**iFC310xDeviceId** : Device-Id.

**bErrorResume** : A rising edge at this boolean input resets an "AX200X error" (not a time-out error).

**tTimeOut**: Maximum time allowed for the execution of the command.

## VAR\_OUTPUT

```
VAR_OUTPUT  
    bBusy        : BOOL;  
    bError       : BOOL;(*Errorstatus of Servo*)  
    iErrID       : DWORD;  
    bTimeOutErr  : BOOL;  
    bInitOK      : BOOL;(*Initialization OK*)  
    iactPosition : DINT;(*actual Position SI-value*)  
END_VAR
```

**bBusy**: This output remains TRUE until the block has executed a command. While Busy = TRUE, no new command will be accepted at the inputs. Please note that it is not the execution of the service but its acceptance whose time is monitored.

**bError**: This output shows the error status.

**iErrID** : contains the command-specific error code of the most recently executed command. Is reset to 0 by the execution of a command at the inputs.

**bTimeOutErr** : TimeOut error.

**bInitOK** : Initialization state of the drive, bInit:= TRUE: The drive is initialized, and is in operating mode 2, "positioning".

**iactPosition** : Display of current position in running mode 1: Motiontask .

## Requirements

| Development environment | Target platform | IO hardware | PLC libraries to be integrated (category group) |
| --- | --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86) | AX2000 Profibus box | Tc2\_IoFunctions (IO) |

[TwinCAT 3 | PLC Library: Tc2\_IoFunctions](ms-xhelp:///?Id=beckhoff-89f3-4b36-bb70-6247b05e611b)
