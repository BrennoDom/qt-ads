# FB_DALI208SetDownSwitchOffThreshold

## Library
tcplclib_tc3_dali

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc3\_DALI](ms-xhelp:///?Id=beckhoff-3b50-4f78-8721-86f9c15e9bec)
2. [Programming](ms-xhelp:///?Id=beckhoff-b5e2-4347-b4c8-164a6e6f2543)
3. [POUs](ms-xhelp:///?Id=beckhoff-57a2-4b7a-aa99-0fc670e505a2)
4. [Commands](ms-xhelp:///?Id=beckhoff-e647-4709-92f0-6dc69db8d17c)
5. [Part 208 (device for switching functions)](ms-xhelp:///?Id=beckhoff-311e-40a1-9c96-ad05c0524017)
6. [Configuration commands](ms-xhelp:///?Id=beckhoff-b0eb-4bb3-8bbe-d0fd1fe497c6)
7. FB\_DALI208SetDownSwitchOffThreshold

# FB\_DALI208SetDownSwitchOffThreshold

![59472242](/tcplclib_tc3_dali/1033/Images/gif/10380437003__Web.gif)

This function block saves the value *nDownSwitchOffThreshold* in the variable [downSwitchOffThreshold](ms-xhelp:///?Id=beckhoff-c35d-4ca0-9bd6-597c2a99a83f) of the DALI control gear.

The output of the DALI control gear is reset as soon as the falling virtual output value reaches or falls below the threshold value *downSwitchOffThreshold*.

The threshold value is disabled with the value *nDownSwitchOffThreshold* = 255 (MASK).

The DALI command is then only supported by a DALI control gear if bit 3 of [features](ms-xhelp:///?Id=beckhoff-c35d-4ca0-9bd6-597c2a99a83f) is set.

|  |  |
| --- | --- |
| 65488131 | Prior to the DALI command SET DOWN SWITCH-OFF THRESHOLD, the function block sends the DALI command ENABLE DEVICE TYPE 7, as is necessary for application extended commands (see also [FB\_DALI102EnableDeviceType](ms-xhelp:///?Id=beckhoff-6f87-4d1b-b5a6-4f03ac5df1fb)). |

|  |  |
| --- | --- |
| 52522275 | The function block sends the DALI command SET DOWN SWITCH-OFF THRESHOLD twice, as foreseen by the DALI standard for certain commands. |

|  |  |
| --- | --- |
| 2938434 | The function block changes the DTR0 of all connected DALI control gears. |

## VAR\_INPUT

```
bStart                  : BOOL;  
nAddress                : BYTE;  
eAddressType            : E_DALIAddressType := E_DALIAddressType.Short;  
eCommandPriority        : E_DALICommandPriority := E_DALICommandPriority.MiddleLow;  
nDownSwitchOffThreshold : BYTE := 0;
```

**bStart:** Execution of the DALI commands is triggered via a positive edge at this input.

**nAddress:** Address of a DALI control gear or a DALI group.

**eAddressType:** Defines whether the input *nAddress* contains a short address (0…63) or a group address (0…15). Input *nAddress* has no meaning if a broadcast or a broadcast to unaddressed devices (BroadcastUnaddr) has been selected (see [E\_DALIAddressType](ms-xhelp:///?Id=beckhoff-8a4e-4869-9ea1-1920c00d61f5)).

**eCommandPriority:** Priority (low, middle low, middle, middle high, high) with which the DALI commands are sent (see [E\_DALICommandPriority](ms-xhelp:///?Id=beckhoff-0df2-4cc5-8ea6-5c4eb6040cf5)).

|  |  |
| --- | --- |
| 26445914 | *eCommandPriority* has no function with the KL6811. The command priorities are supported by the KL6821 from the firmware version BD. |

**nDownSwitchOffThreshold:** Threshold value (0…255) for switching off the output with a falling virtual output value.

## VAR\_OUTPUT

```
bError                  : BOOL;  
ipResultMessage         : I_TcMessage;  
bBusy                   : BOOL;
```

**bError:** This output is switched to TRUE if an error occurs during the execution. Further information about the error can be queried via the variable *ipResultMessage*. The output is set to FALSE again as soon as *bBusy* switches to TRUE.

**ipResultMessage:** Interface pointer (see [Error evaluation](ms-xhelp:///?Id=beckhoff-e964-4db2-800a-4efdb6dc0429)) that can be used to obtain detailed information about the processing of the function block (see [Runtime messages](ms-xhelp:///?Id=beckhoff-b989-448b-af68-d65e2e7a28f5)). The interface pointer is valid after *bBusy* has changed from TRUE to FALSE.

**bBusy:** The output is set as soon as execution of the DALI commands has commenced. It remains active until all DALI commands have been processed.

## Requirements

| Development environment | Required PLC library |
| --- | --- |
| TwinCAT from v3.1.4024.20 | Tc3\_DALI from v3.7.0.0 |

[TwinCAT 3 | PLC Library: Tc3\_DALI](ms-xhelp:///?Id=beckhoff-3b50-4f78-8721-86f9c15e9bec)
