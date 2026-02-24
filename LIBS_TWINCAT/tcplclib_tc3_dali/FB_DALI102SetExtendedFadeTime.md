# FB_DALI102SetExtendedFadeTime

## Library
tcplclib_tc3_dali

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc3\_DALI](ms-xhelp:///?Id=beckhoff-3b50-4f78-8721-86f9c15e9bec)
2. [Programming](ms-xhelp:///?Id=beckhoff-b5e2-4347-b4c8-164a6e6f2543)
3. [POUs](ms-xhelp:///?Id=beckhoff-57a2-4b7a-aa99-0fc670e505a2)
4. [Commands](ms-xhelp:///?Id=beckhoff-e647-4709-92f0-6dc69db8d17c)
5. [Part 102 (control gears)](ms-xhelp:///?Id=beckhoff-f3c7-4b21-a3cb-088caa074ef9)
6. [Configuration commands](ms-xhelp:///?Id=beckhoff-eee7-4e07-967c-ceeaeb6fb2ff)
7. FB\_DALI102SetExtendedFadeTime

# FB\_DALI102SetExtendedFadeTime

![7492614](/tcplclib_tc3_dali/1033/Images/gif/9007206133409675__Web.gif)

This function block writes the values *eExtendedFadeTimeBase* and *eExtendedFadeTimeMultiplier* to the variables [extendedFadeTimeBase](ms-xhelp:///?Id=beckhoff-e013-4a7e-9d50-4deaaa138af7) and [extendedFadeTimeMultiplier](ms-xhelp:///?Id=beckhoff-e013-4a7e-9d50-4deaaa138af7)*.*

The Extended Fade Time is calculated from the product of the two variables *extendedFadeTimeBase* and *extendedFadeTimeMultiplier.*

The value can be set between 100 ms and 16 min. With a value of 0 s, the lighting output reaches the required value as quickly as possible.

The *extendedFadeTime* is used in the function blocks [FB\_DALI102DirectArcPowerControl](ms-xhelp:///?Id=beckhoff-0c46-458d-aa43-e38363cdead0) and [FB\_DALI102GoToScene](ms-xhelp:///?Id=beckhoff-a569-4c24-b493-8153725be7b8).

|  |  |
| --- | --- |
| 324668 | The two variables *extendedFadeTimeBase* and *extendedFadeTimeMultiplier* are used for the calculation only if [fadeTime](ms-xhelp:///?Id=beckhoff-e013-4a7e-9d50-4deaaa138af7) was set to *E\_DALIFadeTime.Disabled* and, if implemented, [fastFadeTime](ms-xhelp:///?Id=beckhoff-3c7f-4aa8-b05d-20b713e3c6a0) is equal to *E\_DALIFastFadeTime.Disabled*. |

|  |  |
| --- | --- |
| 2922015 | The function block changes the DTR0 of all connected DALI control gears. |

|  |  |
| --- | --- |
| 26298136 | The function block sends the command SET EXTENDED FADE TIME twice, as foreseen by the DALI standard for certain commands. |

## VAR\_INPUT

```
bStart                       : BOOL;  
nAddress                     : BYTE;  
eAddressType                 : E_DALIAddressType := E_DALIAddressType.Short;  
eCommandPriority             : E_DALICommandPriority := E_DALICommandPriority.MiddleLow;  
eExtendedFadeTimeBase        : E_DALIExtendedFadeTimeBase := E_DALIExtendedFadeTimeBase.Base01;  
eExtendedFadeTimeMultiplier  : E_DALIExtendedFadeTimeMultplier := E_DALIExtendedFadeTimeMultplier.NoFade;
```

**bStart:** Execution of the DALI commands is triggered via a positive edge at this input.

**nAddress:** Address of a DALI device or a DALI group.

**eAddressType:** Defines whether the input *nAddress* contains a short address (0…63) or a group address (0…15). Input *nAddress* has no meaning if a broadcast or a broadcast to unaddressed devices (BroadcastUnaddr) has been selected (see [E\_DALIAddressType](ms-xhelp:///?Id=beckhoff-8a4e-4869-9ea1-1920c00d61f5)).

**eCommandPriority:** Priority (low, middle low, middle, middle high, high) with which the DALI commands are sent (see [E\_DALICommandPriority](ms-xhelp:///?Id=beckhoff-0df2-4cc5-8ea6-5c4eb6040cf5)).

|  |  |
| --- | --- |
| 35356632 | *eCommandPriority* has no function with the KL6811. The command priorities are supported by the KL6821 from the firmware version BD. |

**eExtendedFadeTimeBase:** Basis for the calculation of the Extended FadeTime (see [E\_DALIExtendedFadeTimeBase](ms-xhelp:///?Id=beckhoff-148d-4d6f-b8c8-a2df66a7851b)).

**eExtendedFadeTimeMultiplier:** Time multiplier for the calculation of the Extended FadeTime (see [E\_DALIExtendedFadeTimeMultiplier](ms-xhelp:///?Id=beckhoff-876c-47dc-b80f-957ea84b912b)).

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
| TwinCAT from v3.1.4024.4 | Tc3\_DALI from v3.2.0.0 |

[TwinCAT 3 | PLC Library: Tc3\_DALI](ms-xhelp:///?Id=beckhoff-3b50-4f78-8721-86f9c15e9bec)
