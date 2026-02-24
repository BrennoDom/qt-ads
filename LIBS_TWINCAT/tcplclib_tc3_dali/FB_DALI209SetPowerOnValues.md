# FB_DALI209SetPowerOnValues

## Library
tcplclib_tc3_dali

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc3\_DALI](ms-xhelp:///?Id=beckhoff-3b50-4f78-8721-86f9c15e9bec)
2. [Programming](ms-xhelp:///?Id=beckhoff-b5e2-4347-b4c8-164a6e6f2543)
3. [POUs](ms-xhelp:///?Id=beckhoff-57a2-4b7a-aa99-0fc670e505a2)
4. [Commands](ms-xhelp:///?Id=beckhoff-e647-4709-92f0-6dc69db8d17c)
5. [Part 209 (color/color temperature control)](ms-xhelp:///?Id=beckhoff-d816-4de1-bd09-5e02b92cfc27)
6. [Configuration commands](ms-xhelp:///?Id=beckhoff-f3ea-46ec-bc38-9595d9dc880e)
7. FB\_DALI209SetPowerOnValues

# FB\_DALI209SetPowerOnValues

![10586246](/tcplclib_tc3_dali/1033/Images/gif/9042950411__Web.gif)

The function block stores the values of the variables [nPowerOnLevel](ms-xhelp:///?Id=beckhoff-e013-4a7e-9d50-4deaaa138af7) and [nColourTemperatureTc](ms-xhelp:///?Id=beckhoff-996e-4deb-b831-825c7f1752f7) in the DALI control gear.

Initially, only the color temperature is adjustable.

|  |  |
| --- | --- |
| 28167350 | Prior to the DALI command SET POWER ON LEVEL, the function block sends the DALI command ENABLE DEVICE TYPE 8, as is necessary for application extended commands (see [FB\_DALI102EnableDeviceType](ms-xhelp:///?Id=beckhoff-6f87-4d1b-b5a6-4f03ac5df1fb)). |

|  |  |
| --- | --- |
| 52179558 | The function block changes the DTR0 and the DTR1 of all connected DALI control gears. |

## VAR\_INPUT

```
bStart                         : BOOL;  
nAddress                       : BYTE;  
eAddressType                   : E_DALIAddressType := E_DALIAddressType.Short;  
eCommandPriority               : E_DALICommandPriority := E_DALICommandPriority.MiddleLow;  
nPowerOnLevel                  : BYTE;  
eColourType                    : E_DALIColourType := E_DALIColourType.MASK;  
nXCoordinate                   : UINT;  
nYCoordinate                   : UINT;  
nColourTemperatureTc           : UINT := 65534;  
nPrimaryColour0                : UINT;  
nPrimaryColour1                : UINT;  
nPrimaryColour2                : UINT;  
nPrimaryColour3                : UINT;  
nPrimaryColour4                : UINT;  
nPrimaryColour5                : UINT;  
nRedDimlevel                   : BYTE;  
nGreenDimlevel                 : BYTE;  
nBlueDimlevel                  : BYTE;  
nWhiteDimlevel                 : BYTE;  
nAmberDimlevel                 : BYTE;  
nFreecolourDimlevel            : BYTE;
```

**bStart:** Execution of the DALI commands is triggered via a positive edge at this input.

**nAddress:** Address of a DALI device or a DALI group.

**eAddressType:** Defines whether the input *nAddress* contains a short address (0…63) or a group address (0…15). Input *nAddress* has no meaning if a broadcast or a broadcast to unaddressed devices (BroadcastUnaddr) has been selected (see [E\_DALIAddressType](ms-xhelp:///?Id=beckhoff-8a4e-4869-9ea1-1920c00d61f5)).

**eCommandPriority:** Priority (low, middle low, middle, middle high, high) with which the DALI commands are sent (see [E\_DALICommandPriority](ms-xhelp:///?Id=beckhoff-0df2-4cc5-8ea6-5c4eb6040cf5)).

|  |  |
| --- | --- |
| 66962839 | *eCommandPriority* has no function with the KL6811. The command priorities are supported by the KL6821 from the firmware version BD. |

**nPowerOnLevel:** Switch-on value (0…255).

**eColourType:** Defines the color setting with which the function block is operated (see [Variables](ms-xhelp:///?Id=beckhoff-996e-4deb-b831-825c7f1752f7)). MASK prevents the color representation from being changed. Currently, the function block only supports the setting of color temperature Tc and MASK.

**nXCoordinate:** Entry of the x-value of the color representation according to xy color type (see [X-coordinate](ms-xhelp:///?Id=beckhoff-996e-4deb-b831-825c7f1752f7)) in the color setting Xy coordinates (see [Variables](ms-xhelp:///?Id=beckhoff-996e-4deb-b831-825c7f1752f7)). Not currently implemented.

**nYCoordinate:** Entry of the y-value of the color representation according to xy color type (see [Y-coordinate](ms-xhelp:///?Id=beckhoff-996e-4deb-b831-825c7f1752f7)) in the color setting Xy coordinates (see [Variables](ms-xhelp:///?Id=beckhoff-996e-4deb-b831-825c7f1752f7)). Not currently implemented.

**nColourTemperatureTc:** Entry of the desired color temperature (see [Variables](ms-xhelp:///?Id=beckhoff-996e-4deb-b831-825c7f1752f7)) in the setting Color temperature Tc (see [Variables](ms-xhelp:///?Id=beckhoff-996e-4deb-b831-825c7f1752f7)).

**nPrimaryColourN:** Entry of the color representation on the corresponding output channel on the operating device in the color setting Primary color N (see [Variables](ms-xhelp:///?Id=beckhoff-996e-4deb-b831-825c7f1752f7)). Not currently implemented.

**nRedDimlevel:** Setting of the red dimming level (see [DimLevel](ms-xhelp:///?Id=beckhoff-996e-4deb-b831-825c7f1752f7)) in the color setting RGBWAF (see [Variables](ms-xhelp:///?Id=beckhoff-996e-4deb-b831-825c7f1752f7)). Not currently implemented.

**nGreenDimlevel:** Setting of the green dimming level (see [DimLevel](ms-xhelp:///?Id=beckhoff-996e-4deb-b831-825c7f1752f7)) in the color setting RGBWAF (see [Variables](ms-xhelp:///?Id=beckhoff-996e-4deb-b831-825c7f1752f7)). Not currently implemented.

**nBlueDimlevel:** Setting of the blue dimming level (see [DimLevel](ms-xhelp:///?Id=beckhoff-996e-4deb-b831-825c7f1752f7)) in the color setting RGBWAF (see [Variables](ms-xhelp:///?Id=beckhoff-996e-4deb-b831-825c7f1752f7)). Not currently implemented.

**nWhiteDimlevel:** Setting of the white dimming level (see [DimLevel](ms-xhelp:///?Id=beckhoff-996e-4deb-b831-825c7f1752f7)) in the color setting RGBWAF (see [Variables](ms-xhelp:///?Id=beckhoff-996e-4deb-b831-825c7f1752f7)). Not currently implemented.

**nAmberDimlevel:** Setting of the amber dimming level (see [DimLevel](ms-xhelp:///?Id=beckhoff-996e-4deb-b831-825c7f1752f7)) in the color setting RGBWAF (see [Variables](ms-xhelp:///?Id=beckhoff-996e-4deb-b831-825c7f1752f7)). Not currently implemented.

**nFreecolourDimlevel:** Setting of the dimming level of the freely selectable color (see [DimLevel](ms-xhelp:///?Id=beckhoff-996e-4deb-b831-825c7f1752f7)) in the color setting RGBWAF (see [Variables](ms-xhelp:///?Id=beckhoff-996e-4deb-b831-825c7f1752f7)). Not currently implemented.

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
| TwinCAT from v3.1.4024.11 | Tc3\_DALI from v3.5.0.0 |

[TwinCAT 3 | PLC Library: Tc3\_DALI](ms-xhelp:///?Id=beckhoff-3b50-4f78-8721-86f9c15e9bec)
