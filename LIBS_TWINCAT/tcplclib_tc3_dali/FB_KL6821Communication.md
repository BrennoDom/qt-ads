# FB_KL6821Communication

## Library
tcplclib_tc3_dali

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc3\_DALI](ms-xhelp:///?Id=beckhoff-3b50-4f78-8721-86f9c15e9bec)
2. [Programming](ms-xhelp:///?Id=beckhoff-b5e2-4347-b4c8-164a6e6f2543)
3. [POUs](ms-xhelp:///?Id=beckhoff-57a2-4b7a-aa99-0fc670e505a2)
4. [Communication](ms-xhelp:///?Id=beckhoff-3bba-42fc-adfa-d81c39a05f7b)
5. FB\_KL6821Communication

# FB\_KL6821Communication

![37451465](/tcplclib_tc3_dali/1033/Images/gif/27021603621185675__Web.gif)

The function blocks for the DALI commands do not directly access the process image of the KL6821, but place the individual DALI commands in a command buffer. The function block FB\_KL6821Communication sequentially reads the DALI commands from the command buffer and forwards them to the KL6821. This prevents multiple function blocks accessing the KL6821 process image at the same time.

The function block also reads the events of the DALI control devices from the KL6821 and stores them in a special table. The function blocks [FB\_DALIGetInputNotification](ms-xhelp:///?Id=beckhoff-c618-436b-ab58-cfa089cd9805) and [FB\_DALIGetPowerCycleNotification](ms-xhelp:///?Id=beckhoff-7a64-4556-97b3-3f691a9a086c) are used to filter out the desired events from this table.

One instance of the function block FB\_KL6821Communication must be created for each KL6821. This instance must be called in a separate, faster task. This faster communication task must have a higher priority than the task in which the function blocks for the individual DALI commands are called.

The utilization rate of the command buffer can be determined using the outputs of the function block. Three parameters are output for this purpose. If you find that the command buffer is overflowing regularly, you should take the following steps:

* How heavily are the individual PLC tasks utilized? TwinCAT provides suitable analysis tools.
* Try to reduce the cycle time of the task in which the function block FB\_KL6821Communication is called. The value should not be greater than 6 ms. The optimum value is 2 ms or less.
* Check the cycle time of the PLC task in which the function blocks for the individual DALI commands are called. This value should not be greater than 10 ms. The optimum value is 8 ms or less.
* If possible avoid polling (regular reading) of values. Only read values when they are actually required.
* Distribute the individual control gears evenly over several DALI lines. Since several DALI lines are processed simultaneously in each PLC cycle, this increases the data throughput.

## VAR\_INPUT

```
bResetMaximumDemandCounter : BOOL;  
bResetOverflowCounter      : BOOL;  
nOptions                   : DWORD := 0;  
bResetInactiveProcessImage : BOOL;  
bInitialise                : BOOL := FALSE;  
eCommandKBusWatchdog       : E_DALIConfigurationCommand := E_DALIConfigurationCommand.DoNothing;  
eCommandDI1RisingEdge      : E_DALIConfigurationCommand := E_DALIConfigurationCommand.Off;  
eCommandDI1FallingEdge     : E_DALIConfigurationCommand := E_DALIConfigurationCommand.DoNothing;  
eCommandDI2RisingEdge      : E_DALIConfigurationCommand := E_DALIConfigurationCommand.RecallMaxLevel;  
eCommandDI2FallingEdge     : E_DALIConfigurationCommand := E_DALIConfigurationCommand.DoNothing;  
bDoNotLockProcessImage     : BOOL := FALSE;  
eDisablePowerSupply        : BOOL := FALSE;
```

**bResetMaximumDemandCounter:** A positive edge resets the stored value for the maximum utilization of the command buffer, *nBufferMaximumDemandMeter* (0…100 %).

**bResetOverflowCounter:** A positive edge resets the stored value for the number of overflows of the command buffer, *nBufferOverflowCounter*.

**nOptions:** Reserved for future extensions.

**bResetInactiveProcessImage:** A positive edge cancels the blocking of the process image of the terminal. The output *bProcessImageInactive* is reset to FALSE. The blocking is activated as soon as one of the two digital inputs on the terminal has been actuated and the input parameter *bDoNotLockProcessImage* is FALSE.

**bInitialise:** Configuration of the Bus Terminal is started by a positive edge at this input. Initialization is also carried out automatically when the controller is started. During this time no DALI commands are processed.

**eCommandKBusWatchdog:** Defines the DALI command that is sent as soon as the Bus Terminal is no longer addressed via the K-bus. The value is written to the terminal by a positive edge at input *bInitialise* and stored there persistently.

**eCommandDI1RisingEdge, eCommandDI2RisingEdge:** Defines the DALI command that is sent as soon as a rising edge is detected at the respective input of the Bus Terminal. The value is written to the terminal by a positive edge at input *bInitialise* and stored there persistently.

**eCommandDI1FallingEdge, eCommandDI2FallingEdge:** Defines the DALI command that is sent as soon as a falling edge is detected at the respective input of the Bus Terminal. The value is written to the terminal by a positive edge at input *bInitialise* and stored there persistently.

**bDoNotLockProcessImage:** Defines whether the process image for the PLC is not blocked by actuating the digital inputs (see also *bInactiveProcessImage*). The value is written to the terminal by a positive edge at input *bInitialise* and stored there persistently.

**eDisablePOwerSupply:** Defines the operation mode of the internal DALI power supply. The value is written to the terminal by a positive edge at input *bInitialise* and stored there persistently.

## VAR\_OUTPUT

```
bError                     : BOOL;  
ipResultMessage            : I_TcMessage;  
bBusy                      : BOOL;  
nBufferDemandMeter         : BYTE;  
nBufferMaximumDemandMeter  : BYTE;  
nBufferOverflowCounter     : UINT;  
bDigitalInputnActive       : BOOL;  
bProcessImageInactive      : BOOL;  
bCollisionError            : BOOL;  
bPowerSupplyError          : BOOL;  
bShortCircuit              : BOOL;  
bInitialising              : BOOL;  
nTerminalDescription       : WORD;  
nFirmwareVersion           : WORD;
```

**bError:** This output is switched to TRUE if an error occurs during the execution. Further information about the error can be queried via the variable *ipResultMessage*. The output is set to FALSE again as soon as *bBusy* switches to TRUE.

**ipResultMessage:** Interface pointer (see [Error evaluation](ms-xhelp:///?Id=beckhoff-e964-4db2-800a-4efdb6dc0429)) that can be used to obtain detailed information about the processing of the function block (see [Runtime messages](ms-xhelp:///?Id=beckhoff-b989-448b-af68-d65e2e7a28f5)). The interface pointer is valid after *bBusy* has changed from TRUE to FALSE.

**bBusy:** The output is set as soon as the function block processes a DALI command and remains active until the DALI command has been processed.

**nBufferDemandMeter:** Utilization rate of the command buffer (0…100 %).

**nBufferMaximumDemandMeter:** Maximum utilization rate of the command buffer reached so far (0…100 %). The counter can be reset via the input *bResetMaximumDemandCounter*.

**nBufferOverflowCounter:** Number of command buffer overflows to date. The counter can be reset via the input *bResetOverflowCounter*.

**bDigitalInput1Active, bDigitalInput2Active:** One of the digital inputs at the terminal was actuated or is actuated (see also terminal documentation). If the *input bDoNotLockProcessImage* is not set, the output *bProcessImageInactive* is set and no further DALI commands can be sent via the Bus Terminal.

**bProcessImageInactive:** One of the two digital inputs on the Bus Terminal was actuated and *bDoNotLockProcessImage* is initialized with FALSE. No further DALI commands can be sent from the PLC via the Bus Terminal. The blockage can be released again via the input *bResetInactiveProcessImage*.

**bCollisionError:** A data collision was detected on the DALI bus while a DALI command was sent.

**bPowerSupplyError:** When using the internal DALI power supply unit: Power supply unit fault detected.

**bShortCircuit:** The 24 V DC supply voltage at connections 1 and 5 of the KL6821 is missing, or a short circuit has been detected on the DALI bus.

**bInitialising:** During initialization of the Bus Terminal, the output is set and remains active until initialization has been completed. Initialization is also carried out automatically when the controller is started. During this time no DALI commands are processed.

**nTerminalDescription:** Contains the Terminal Name (e.g. 6821). This corresponds to register 8 of the Bus Terminal.

**nFirmwareVersion:** Contains the firmware version. This corresponds to register 9 of the Bus Terminal.

## VAR\_IN\_OUT

```
stInData                         : ST_KL6821InData;  
stOutData                        : ST_KL6821OutData;
```

**stInData:** Structure in the input process image of the KL6821 (see [ST\_KL6821InData](ms-xhelp:///?Id=beckhoff-0a30-4102-93fb-5d3c192eb018)). It is used for communication from the KL6821 to the PLC.

**stOutData:** Structure in the output process image of the KL6821 (see [ST\_KL6821OutData](ms-xhelp:///?Id=beckhoff-4c75-442a-a99c-ba1337998536)). It is used for communication from the KL6821 to the PLC.

## Requirements

| Development environment | Required PLC library |
| --- | --- |
| TwinCAT from v3.1.4024.11 | Tc3\_DALI from v3.5.0.0 |

[TwinCAT 3 | PLC Library: Tc3\_DALI](ms-xhelp:///?Id=beckhoff-3b50-4f78-8721-86f9c15e9bec)
