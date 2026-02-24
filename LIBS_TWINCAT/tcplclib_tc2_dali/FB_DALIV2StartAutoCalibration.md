# FB_DALIV2StartAutoCalibration

## Library
tcplclib_tc2_dali

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_DALI](ms-xhelp:///?Id=beckhoff-bad6-4627-b8ac-544f0eee130c)
2. [Programming](ms-xhelp:///?Id=beckhoff-1e7b-43d6-a8da-8e0049d24778)
3. [POUs](ms-xhelp:///?Id=beckhoff-3c92-4da6-86d7-db508adfb4f0)
4. [Low-Level commands](ms-xhelp:///?Id=beckhoff-408c-4669-b5d5-6c547023c614)
5. [Part 209 (color/color temperature control)](ms-xhelp:///?Id=beckhoff-a837-4797-bf19-33a8438d83d2)
6. FB\_DALIV2StartAutoCalibration

# FB\_DALIV2StartAutoCalibration

![24171358](/tcplclib_tc2_dali/1033/Images/gif/9007200267102859__en-US__Web.gif)

The calibration procedure is started in order to measure the x-coordinate, the y-coordinate and the TY value of all supported primary colors.

The command starts a 15-minute timer or initiates it again. Bit 2 of the [COLOR STATUS](ms-xhelp:///?Id=beckhoff-1ce6-4fd4-be82-75082326bd44) variable is 1 as long as the timer is active (see [FB\_DALIV2QueryColorStatus()](ms-xhelp:///?Id=beckhoff-ed62-4911-ad94-6cfea37f52ce)). On expiry of the timer the last color representation, the last color value and the last lamp power level are directly saved again.

During the timer period the DALI control gear carries out a calibration procedure in order to measure the x-coordinate, the y-coordinate and the TY value of all supported primary colors. Whilst the calibration procedure is running, the DALI control gear does not react to any commands apart from [TERMINATE](ms-xhelp:///?Id=beckhoff-294f-4f50-b7d8-4e71ae8254f5), [QUERY COLOR STATUS](ms-xhelp:///?Id=beckhoff-ed62-4911-ad94-6cfea37f52ce) and START AUTO CALIBRATION. In addition, bit 3 in the [COLOR STATUS](ms-xhelp:///?Id=beckhoff-1ce6-4fd4-be82-75082326bd44) variable is set to 0 at the start of the calibration. The [TERMINATE](ms-xhelp:///?Id=beckhoff-294f-4f50-b7d8-4e71ae8254f5) command ends the procedure and stops the timer.

If the calibration was successful, bit 3 in [COLOR STATUS](ms-xhelp:///?Id=beckhoff-1ce6-4fd4-be82-75082326bd44) is set to 1 and the timer is stopped. If the calibration was not successful, then the last successful calibration data are restored if the DALI control gear is able to do so. Subsequently, bit 3 of COLOR STATUS is set to 1. The ability to restore the last successful calibration data is a feature of the operating device (see [QUERY GEAR FEATURES/STATUS](ms-xhelp:///?Id=beckhoff-3ae6-44b0-b294-75a1916df3fa) command).

Due to the fact that the calibration can take longer than 15 minutes, the status of the automatic calibration should be checked periodically using the [QUERY COLOR STATUS](ms-xhelp:///?Id=beckhoff-ed62-4911-ad94-6cfea37f52ce) command and the calibration timer restarted with the START AUTO CALIBRATION command (if necessary).

The function block supports the following color representations:

* xy coordinates
* Color temperature Tc
* Primary (color) N
* RGBWAF

|  |  |
| --- | --- |
| 16215635 | This command belongs to the application-related expansion commands for lamps for the color/color temperature control with DALI interface. They function only if they are preceded by the *Enable Device Type 8* command, which can be sent with the [FB\_DALIV2EnableDeviceType()](ms-xhelp:///?Id=beckhoff-e277-46a4-85ba-43a8cbcb1cb1) function block. The *Enable Device Type 8* command is internally placed automatically before all application-related expansion commands for lamps for the color/color temperature control with DALI interface. |

## VAR\_INPUT

```
bStart           : BOOL;  
nAddr            : BYTE;  
eAddrType        : E_DALIV2AddrType := eDALIV2AddrTypeShort;  
eCommandPriority : E_DALIV2CommandPriority := eDALIV2CommandPriorityMiddle;
```

**bStart:** The function block is activated by a positive edge at this input.

**nAddr:** The address of a participating device or of a group.

**eAddrType:** Short address, group address or broadcast (see [E\_DALIV2AddrType](ms-xhelp:///?Id=beckhoff-d59c-42a4-9d77-6cc67c0d1971)).

**eCommandPriority:** Priority (high, medium or low) with which the command is processed by the library (see [E\_DALIV2CommandPriority](ms-xhelp:///?Id=beckhoff-9fcc-400f-b6a8-66e61c15362f)).

## VAR\_OUTPUT

```
bBusy    : BOOL;  
bError   : BOOL;  
nErrorId : UDINT;
```

**bBusy:** When the function block is activated the output is set, and it remains active until execution of the command has been completed.

**bError:** This output is switched to TRUE as soon as an error occurs during the execution of a command. The command-specific error code is contained in *nErrorId*. Is reset to FALSE by the execution of a command at the inputs.

**nErrorId:** Contains the command-specific error code of the most recently executed command. Is reset to 0 by the execution of a command at the inputs. (See [error codes](ms-xhelp:///?Id=beckhoff-f739-41c2-8ff6-b502954dc54f))

## VAR\_IN\_OUT

```
stCommandBuffer : ST_DALIV2CommandBuffer;
```

**stCommandBuffer:** Reference to the internal structure for communication with the function block [FB\_KL6811Communication()](ms-xhelp:///?Id=beckhoff-a20b-403b-a517-3ca6697b63e6) (KL6811) or [FB\_KL6821Communication()](ms-xhelp:///?Id=beckhoff-24f5-4307-8c46-040081763250) (KL6821).

## Requirements

| Development environment | required PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_DALI from v3.4.3.0 |

[TwinCAT 3 | PLC Library: Tc2\_DALI](ms-xhelp:///?Id=beckhoff-bad6-4627-b8ac-544f0eee130c)
