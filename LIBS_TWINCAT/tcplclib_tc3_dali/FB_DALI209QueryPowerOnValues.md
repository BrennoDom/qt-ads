# FB_DALI209QueryPowerOnValues

## Library
tcplclib_tc3_dali

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc3\_DALI](ms-xhelp:///?Id=beckhoff-3b50-4f78-8721-86f9c15e9bec)
2. [Programming](ms-xhelp:///?Id=beckhoff-b5e2-4347-b4c8-164a6e6f2543)
3. [POUs](ms-xhelp:///?Id=beckhoff-57a2-4b7a-aa99-0fc670e505a2)
4. [Commands](ms-xhelp:///?Id=beckhoff-e647-4709-92f0-6dc69db8d17c)
5. [Part 209 (color/color temperature control)](ms-xhelp:///?Id=beckhoff-d816-4de1-bd09-5e02b92cfc27)
6. [Query commands](ms-xhelp:///?Id=beckhoff-7f84-4906-8744-e291b2a80913)
7. FB\_DALI209QueryPowerOnValues

# FB\_DALI209QueryPowerOnValues

![6475715](/tcplclib_tc3_dali/1033/Images/gif/9043486987__Web.gif)

The function block reads the variables [powerOnLevel](ms-xhelp:///?Id=beckhoff-e013-4a7e-9d50-4deaaa138af7) and the supported values of the color settings from the DALI control gear.

Initially, only the color temperature is readable.

|  |  |
| --- | --- |
| 58281439 | In addition to the DALI command QUERY POWER ON LEVEL, the function block sends the DALI commands QUERY COLOUR VALUE and ENABLE DEVICE TYPE 8, as is necessary for application-related extension commands (see [FB\_DALI102EnableDeviceType](ms-xhelp:///?Id=beckhoff-6f87-4d1b-b5a6-4f03ac5df1fb)). |

|  |  |
| --- | --- |
| 54770906 | The function block changes the DTR0 of all connected DALI control gears. |

## VAR\_INPUT

```
bStart            : BOOL;  
nAddress          : BYTE;  
eAddressType      : E_DALIAddressType := E_DALIAddressType.Short;  
eCommandPriority  : E_DALICommandPriority := E_DALICommandPriority.MiddleLow;
```

**bStart:** Execution of the DALI commands is triggered via a positive edge at this input.

**nAddress:** Address of a DALI control gear or a DALI group.

**eAddressType:** Defines whether the input *nAddress* contains a short address (0…63) or a group address (0…15). Input *nAddress* has no meaning if a broadcast or a broadcast to unaddressed devices (BroadcastUnaddr) has been selected (see [E\_DALIAddressType](ms-xhelp:///?Id=beckhoff-8a4e-4869-9ea1-1920c00d61f5)).

**eCommandPriority:** Priority (low, middle low, middle, middle high, high) with which the DALI commands are sent (see [E\_DALICommandPriority](ms-xhelp:///?Id=beckhoff-0df2-4cc5-8ea6-5c4eb6040cf5)).

|  |  |
| --- | --- |
| 23176109 | *eCommandPriority* has no function with the KL6811. The command priorities are supported by the KL6821 from the firmware version BD. |

## VAR\_OUTPUT

```
bError                    : BOOL;  
ipResultMessage           : I_TcMessage;  
bBusy                     : BOOL;  
nPowerOnLevel             : BYTE;  
eColourType               : E_DALIColourTypE;  
nXCoordinate              : UINT;  
nYCoordinate              : UINT;  
nColourTemperatureTc      : UINT;  
nPrimaryColour0           : UINT;  
nPrimaryColour1           : UINT;  
nPrimaryColour2           : UINT;  
nPrimaryColour3           : UINT;  
nPrimaryColour4           : UINT;  
nPrimaryColour5           : UINT;  
nRedDimlevel              : BYTE;  
nGreenDimlevel            : BYTE;  
nBlueDimlevel             : BYTE;  
nWhiteDimlevel            : BYTE;  
nAmberDimlevel            : BYTE;  
nFreecolourDimlevel       : BYTE;
```

**bError:** This output is switched to TRUE if an error occurs during the execution. Further information about the error can be queried via the variable *ipResultMessage*. The output is set to FALSE again as soon as *bBusy* switches to TRUE.

**ipResultMessage:** Interface pointer (see [error evaluation](ms-xhelp:///?Id=beckhoff-e964-4db2-800a-4efdb6dc0429)) that can be used to obtain detailed information about the processing of the function block (see [runtime messages](ms-xhelp:///?Id=beckhoff-b989-448b-af68-d65e2e7a28f5)). The interface pointer is valid after *bBusy* has changed from TRUE to FALSE.

**bBusy:** The output is set as soon as execution of the DALI commands has commenced. It remains active until all DALI commands have been processed.

**nPowerOnLevel:** Output of the switch-on value (see [powerOnLevel](ms-xhelp:///?Id=beckhoff-e013-4a7e-9d50-4deaaa138af7)) from the DALI control gear (0…255).

**eColourType:** Specifies the color setting with which the DALI control gear is operated (see [Variables](ms-xhelp:///?Id=beckhoff-996e-4deb-b831-825c7f1752f7)).

**nXCoordinate:** Output of the x-value of the color representation according to xy color type (see [X-coordinate](ms-xhelp:///?Id=beckhoff-996e-4deb-b831-825c7f1752f7)) in the color setting Xy coordinates (see [Variables](ms-xhelp:///?Id=beckhoff-996e-4deb-b831-825c7f1752f7)). Not currently implemented.

**nYCoordinate:** Output of the y-value of the color representation according to xy color type (see [Y-coordinate](ms-xhelp:///?Id=beckhoff-996e-4deb-b831-825c7f1752f7)) in the color setting Xy coordinates (see [Variables](ms-xhelp:///?Id=beckhoff-996e-4deb-b831-825c7f1752f7)). Not currently implemented.

**nColourTemperatureTc:** Output of the color temperature (see [Variables](ms-xhelp:///?Id=beckhoff-996e-4deb-b831-825c7f1752f7)) in the setting Color temperature Tc (see [Variables](ms-xhelp:///?Id=beckhoff-996e-4deb-b831-825c7f1752f7)).

**nPrimaryColourN:** Output of the color representation on the corresponding output channel on the operating device in the color setting Primary color N (see [Variables](ms-xhelp:///?Id=beckhoff-996e-4deb-b831-825c7f1752f7)). Not currently implemented.

**nRedDimlevel:** Output of the red dimming level (see [DimLevel](ms-xhelp:///?Id=beckhoff-996e-4deb-b831-825c7f1752f7)) in the color setting RGBWAF (see [Variables](ms-xhelp:///?Id=beckhoff-996e-4deb-b831-825c7f1752f7)). Not currently implemented.

**nGreenDimlevel:** Output of the green dimming level (see [DimLevel](ms-xhelp:///?Id=beckhoff-996e-4deb-b831-825c7f1752f7)) in the color setting RGBWAF (see [Variables](ms-xhelp:///?Id=beckhoff-996e-4deb-b831-825c7f1752f7)). Not currently implemented.

**nBlueDimlevel:** Output of the blue dimming level (see [DimLevel](ms-xhelp:///?Id=beckhoff-996e-4deb-b831-825c7f1752f7)) in the color setting RGBWAF (see [Variables](ms-xhelp:///?Id=beckhoff-996e-4deb-b831-825c7f1752f7)). Not currently implemented.

**nWhiteDimlevel:** Output of the white dimming level (see [DimLevel](ms-xhelp:///?Id=beckhoff-996e-4deb-b831-825c7f1752f7)) in the color setting RGBWAF (see [Variables](ms-xhelp:///?Id=beckhoff-996e-4deb-b831-825c7f1752f7)). Not currently implemented.

**nAmberDimlevel:** Output of the amber dimming level (see [DimLevel](ms-xhelp:///?Id=beckhoff-996e-4deb-b831-825c7f1752f7)) in the color setting RGBWAF (see [Variables](ms-xhelp:///?Id=beckhoff-996e-4deb-b831-825c7f1752f7)). Not currently implemented.

**nFreecolourDimlevel:** Output of the dimming level of the freely selectable color (see [DimLevel](ms-xhelp:///?Id=beckhoff-996e-4deb-b831-825c7f1752f7)) in the color setting RGBWAF (see [Variables](ms-xhelp:///?Id=beckhoff-996e-4deb-b831-825c7f1752f7)). Not currently implemented.

## Requirements

| Development environment | Required PLC library |
| --- | --- |
| TwinCAT from v3.1.4024.11 | Tc3\_DALI from v3.5.0.0 |

[TwinCAT 3 | PLC Library: Tc3\_DALI](ms-xhelp:///?Id=beckhoff-3b50-4f78-8721-86f9c15e9bec)
