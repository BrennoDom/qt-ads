# FB_KL6821Communication

## Library
tcplclib_tc2_dali

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_DALI](ms-xhelp:///?Id=beckhoff-bad6-4627-b8ac-544f0eee130c)
2. [Programming](ms-xhelp:///?Id=beckhoff-1e7b-43d6-a8da-8e0049d24778)
3. [POUs](ms-xhelp:///?Id=beckhoff-3c92-4da6-86d7-db508adfb4f0)
4. [Low-Level commands](ms-xhelp:///?Id=beckhoff-408c-4669-b5d5-6c547023c614)
5. [Base](ms-xhelp:///?Id=beckhoff-48f6-479b-b1fc-0ba402ee9f92)
6. FB\_KL6821Communication

# FB\_KL6821Communication

![48957711](/tcplclib_tc2_dali/1033/Images/gif/4415384459__Web.gif)

The function blocks for the DALI commands do not directly access the process image of the DALI Bus Terminal, but store the individual DALI commands in three different buffers. The function block FB\_KL6821Communication() sequentially reads the DALI commands from these three buffers and passes the DALI commands to the KL6821. This prevents several function block accessing the process image of the Bus Terminal at the same time. Each of these three buffers is processed with a different priority (high, medium or low). The parameter *eCommandPriority*, which is available for most function blocks, can be used by the PLC library user to influence the priority with which the respective DALI command is processed by the function block FB\_KL6821Communication().

All buffers in which the DALI commands are stored are associated with a variable of type ST\_DALIV2CommandBuffer. For each KL6821 there is one instance of the function block FB\_KL6821Communication() and one variable of type ST\_DALIV2CommandBuffer. If possible, the FB\_KL6821Communication() function block should be called in a separate, faster task.

The extent to which the buffers are utilized can be determined from the outputs of the function block. Three arrays are output for this in which each element (0, 1 or 2) represents one of the three buffers (high, middle or low). If you find that one of the three buffers overflows on a regular basis, you should consider the following measures:

How heavily are the individual PLC tasks utilized? The TwinCAT System Manager offers various appropriate utilities for the analysis.

* Try to reduce the cycle time of the task in which the function block FB\_KL6821Communication() is called. The value should not exceed 6 ms. Ideally it should be 2 ms.
* Check the cycle time of the PLC task in which the function blocks for the individual DALI commands are called. This value should be between 10 ms and 60 ms.
* If possible avoid polling (regular reading) of values. Only read values when they are actually required.
* Distribute the individual control gears evenly over several DALI lines. Overall data throughput is increased by the fact that several DALI lines are processed simultaneously during each PLC cycle.

## VAR\_INPUT

```
bResetMaximumDemandCounter   : BOOL;  
bResetOverflowCounter        : BOOL;  
bResetInactiveProcessImage   : BOOL;  
nOptions : DWORD := 0;
```

**bResetMaximumDemandCounter**: a positive edge resets the stored value of the maximum command buffer utilization, arrBufferMaximumDemandMeter (0 - 100%, see VAR\_OUTPUT).

**bResetOverflowCounter:** a positive edge resets the stored value of the number of command buffer overflows, arrBufferOverflowCounter (see VAR\_OUTPUT).

**bResetInactiveProcessImage:** a positive edge cancels the blocking of the process image of the terminal. The *bProcessImageInactive*, *bDigitalInput1Active* and *bDigitalInput2Active* outputs are again set to FALSE. The lock is activated when one of the two digital inputs on the terminal is activated.

**nOptions**: reserved for future expansions.

## VAR\_OUTPUT

```
bBusy                        : BOOL;  
bError                       : BOOL;  
nErrorId                     : UDINT;  
arrBufferDemandMeter         : ARRAY [0..2] OF BYTE;  
arrBufferMaximumDemandMeter  : ARRAY [0..2] OF BYTE;  
arrBufferOverflowCounter     : ARRAY [0..2] OF UINT;  
bLineIsBusy                  : BOOL;  
bLineIsInitialized           : BOOL;  
bDigitalInput1Active         : BOOL;  
bDigitalInput2Active         : BOOL;  
bProcessImageInactive        : BOOL;  
bCollisionError              : BOOL;  
bPowerSupplyError            : BOOL;  
bShortCircuit                : BOOL;
```

**bBusy**: This output is set as soon as the function block processes a command and remains active until the command has been processed.

**bError**: This output is switched to TRUE if an error has occurred during execution of the function block. The command-specific error code is contained in *nErrorId*.

**nErrorId**: Contains the command-specific error code of the most recently executed command. (See [error codes](ms-xhelp:///?Id=beckhoff-f739-41c2-8ff6-b502954dc54f))

**arrBufferDemandMeter:** Occupancy of the respective buffer (0 - 100%).

**arrBufferMaximumDemandMeter:** Previous maximum occupancy of the respective buffer (0 - 100%).

**arrBufferOverflowCounter:** Number of buffer overflows to date.

**bLineIsBusy:** The output is set as long as the function block [FB\_KL6821Communication()](ms-xhelp:///?Id=beckhoff-24f5-4307-8c46-040081763250) is active.

**bLineIsInitialized:** if the function block is being called for the first time (e.g. when the controller is starting up) an initialization process is executed. No DALI commands can be processed during this time.

**bDigitalInput1Active**: The digital input 1 on the terminal was or is actuated (see also terminal documentation). The *bProcessImageInactive* output is set and no further DALI commands can be processed by the controller.

**bDigitalInput2Active**: The digital input 2 on the terminal was or is actuated (see also terminal documentation). The *bProcessImageInactive* output is set and no further DALI commands can be processed by the controller.

**bProcessImageInactive:** One of the two digital inputs was actuated at the terminal. No further DALI commands can be processed by the controller. The blockage must be released again via the *bResetInactiveProcessImage* input.

**bCollisionError:** A data collision on the DALI bus was detected while a command was sent.

**bPowerSupplyError:** The KL6821 has detected an error in the internal DALI power supply.

**bShortCircuit:** Short circuit on the DALI bus.

## VAR\_IN\_OUT

```
stInData                     : ST_KL6821InData;  
stOutData                    : ST_KL6821OutData;  
stCommandBuffer              : ST_DALIV2CommandBuffer;
```

**stInData**: Structure in the input process image of the KL6821. It is used for communication from the KL6821 to the PLC. When using [FB\_KL6821Config](ms-xhelp:///?Id=beckhoff-cda8-4c6a-8113-c4463e2d43c2), this structure is linked to the parameter *stInData*.

**stOutData**: Structure in the output process image of the KL6821. It is used for communication from the KL6821 to the PLC. When using [FB\_KL6821Config](ms-xhelp:///?Id=beckhoff-cda8-4c6a-8113-c4463e2d43c2), this structure is linked to the parameter *stOutData*.

**stCommandBuffer**: Reference to the internal structure for communication with the DALI function blocks.

## Requirements

| Development environment | required PLC library |
| --- | --- |
| TwinCAT from v3.1.4022.4 | Tc2\_DALI from v3.6.2.0 |

[TwinCAT 3 | PLC Library: Tc2\_DALI](ms-xhelp:///?Id=beckhoff-bad6-4627-b8ac-544f0eee130c)
