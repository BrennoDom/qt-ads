# FB_KL6811Communication

## Library
tcplclib_tc3_dali

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc3\_DALI](ms-xhelp:///?Id=beckhoff-3b50-4f78-8721-86f9c15e9bec)
2. [Programming](ms-xhelp:///?Id=beckhoff-b5e2-4347-b4c8-164a6e6f2543)
3. [POUs](ms-xhelp:///?Id=beckhoff-57a2-4b7a-aa99-0fc670e505a2)
4. [Communication](ms-xhelp:///?Id=beckhoff-3bba-42fc-adfa-d81c39a05f7b)
5. FB\_KL6811Communication

# FB\_KL6811Communication

![28631516](/tcplclib_tc3_dali/1033/Images/gif/18014404366447627__Web.gif)

The function blocks for the DALI commands do not directly access the process image of the KL6811, but place the individual DALI commands in a command buffer. The function block FB\_KL6811Communication sequentially reads the DALI commands from the command buffer and forwards them to the KL6811. This prevents multiple function blocks accessing the KL6811 process image at the same time.

|  |  |
| --- | --- |
| 56357057 | Most function blocks have the input *eCommandPriority*, which has no function when using the KL6811. Priorities for the DALI commands are only supported from DALI-2 onwards. |

One instance of the function block FB\_KL6811Communication is required per KL6811. This instance must be called in a separate, faster task. This faster communication task must have a higher priority than the task in which the function blocks for the individual DALI commands are called.

The utilization rate of the command buffer can be determined using the outputs of the function block. If you find that the command buffer is overflowing regularly, you should take the following steps:

* How heavily are the individual PLC tasks utilized? TwinCAT provides suitable analysis tools.
* Try to reduce the cycle time of the task in which the function block FB\_KL6811Communication is called. The value should not be greater than 6 ms. The optimum value is 2 ms or less.
* Check the cycle time of the PLC task in which the function blocks for the individual DALI commands are called. This value should not be greater than 10 ms. The optimum value is 8 ms or less.
* If possible avoid polling (regular reading) of values. Only read values when they are actually required.
* Distribute the individual control gears evenly over several DALI lines. Since several DALI lines are processed simultaneously in each PLC cycle, this increases the data throughput.

## VAR\_INPUT

```
bResetMaximumDemandCounter       : BOOL;  
bResetOverflowCounter            : BOOL;  
nOptions                         : DWORD;  
bInitialise                      : BOOL := FALSE;  
bDisableInternalPowerSupply      : BOOL := FALSE;
```

**bResetMaximumDemandCounter:** A positive edge resets the stored value for the maximum utilization of the command buffer, *nBufferMaximumDemandMeter* (0...100%).

**bResetOverflowCounter:** A positive edge resets the stored value for the number of overflows of the command buffer, *nBufferOverflowCounter*.

**nOptions:** Reserved for future extensions.

**bInitialise:** Configuration of the Bus Terminal is started by a positive edge at this input. Initialization is also carried out automatically when the controller is started. During this time no DALI commands are processed.

**bDisableInternalPowerSupply:** Defines the operation mode of the internal DALI power supply. The value is written to the terminal by a positive edge at input *bInitialise* and stored there persistently.

## VAR\_OUTPUT

```
bError                     : BOOL;  
ipResultMessage            : I_TcMessage;  
bBusy                      : BOOL;  
nBufferDemandMeter         : BYTE;  
nBufferMaximumDemandMeter  : BYTE;  
nBufferOverflowCounter     : UINT;  
bCollisionErrorFC          : BOOL;  
bCollisionErrorBC          : BOOL;  
bPowerSupplyError          : BOOL;  
bInitialising              : BOOL;  
nTerminalDescription       : WORD;  
nFirmwareVersion           : WORD;
```

**bError:** This output is switched to TRUE if an error occurs during the execution. Further information about the error can be queried via the variable *ipResultMessage*. The output is set to FALSE again as soon as *bBusy* switches to TRUE.

**ipResultMessage:** Interface pointer (see [Error evaluation](ms-xhelp:///?Id=beckhoff-e964-4db2-800a-4efdb6dc0429)) that can be used to obtain detailed information about the processing of the function block (see [Runtime messages](ms-xhelp:///?Id=beckhoff-b989-448b-af68-d65e2e7a28f5)). The interface pointer is valid after *bBusy* has changed from TRUE to FALSE.

**bBusy:** The output is set as soon as execution of the DALI commands has started. It remains active until the DALI command has been processed.

**nBufferDemandMeter:** Utilization rate of the command buffer (0…100 %).

**nBufferMaximumDemandMeter:** Maximum utilization rate of the command buffer reached so far (0…100 %). The counter can be reset via the input *bResetMaximumDemandCounter*.

**nBufferOverflowCounter:** Number of command buffer overflows to date. The counter can be reset via the input *bResetOverflowCounter*.

**bCollisionErrorFC:** If the output is TRUE, a DALI collision was detected on the forward channel. This can mean that a collision with the send data of another DALI master was detected during the transmission of a DALI telegram. The output is automatically set to FALSE again as soon as no collision has occurred on the forward channel during transmission.

**bCollisionErrorBC:** If the output is TRUE, a DALI collision was detected on the backward channel. This can mean that a collision with the send data of another DALI slave was detected during the transmission of a DALI telegram. The output is automatically set to FALSE again as soon as no collision has occurred on the backward channel during transmission.

**bPowerSupplyError:** If the output is TRUE, an overload was detected when using the internal DALI power supply unit of the Bus Terminal (bus undervoltage).

**bInitialising:** During initialization of the Bus Terminal, the output is set and remains active until initialization has been completed. Initialization is also carried out automatically when the controller is started. During this time no DALI commands are processed.

**nTerminalDescription:** Contains the Terminal Name (e.g. 6811). This corresponds to register 8 of the Bus Terminal.

**nFirmwareVersion:** Contains the firmware version. This corresponds to register 9 of the Bus Terminal.

## VAR\_IN\_OUT

```
stInData                         : ST_KL6811InData;  
stOutData                        : ST_KL6811OutData;
```

**stInData:** Structure in the input process image of the KL6811 (see [ST\_KL6811InData](ms-xhelp:///?Id=beckhoff-f40b-4950-9d65-98773b01a0f5)). It is used for communication from the KL6811 to the PLC.

**stOutData:** Structure in the output process image of the KL6811 (see [ST\_KL6811OutData](ms-xhelp:///?Id=beckhoff-8247-490d-9a78-254355a2e486)). It is used for communication from the PLC to the KL6811.

## Requirements

| Development environment | Required PLC library |
| --- | --- |
| TwinCAT from v3.1.4024.11 | Tc3\_DALI from v3.5.0.0 |

[TwinCAT 3 | PLC Library: Tc3\_DALI](ms-xhelp:///?Id=beckhoff-3b50-4f78-8721-86f9c15e9bec)
