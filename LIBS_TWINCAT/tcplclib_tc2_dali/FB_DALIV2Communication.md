# FB_DALIV2Communication

## Library
tcplclib_tc2_dali

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_DALI](ms-xhelp:///?Id=beckhoff-bad6-4627-b8ac-544f0eee130c)
2. [Programming](ms-xhelp:///?Id=beckhoff-1e7b-43d6-a8da-8e0049d24778)
3. [POUs](ms-xhelp:///?Id=beckhoff-3c92-4da6-86d7-db508adfb4f0)
4. [[obsolete]](ms-xhelp:///?Id=beckhoff-eb1c-4b28-ba1b-364cf88c04c2)
5. FB\_DALIV2Communication

# FB\_DALIV2Communication

![4945408](/tcplclib_tc2_dali/1033/Images/gif/9007199397817483__en-US__Web.gif)

The function blocks for the DALI commands do not access the process image of the KL6811 directly, but place the individual DALI commands in three different buffers. The FB\_DALIV2Communication() function block sequentially reads the DALI commands from these three buffers and passes the DALI commands to the KL6811. This prevents several function blocks accessing the process image of the KL6811 at the same time. Each of these three buffers is processed with a different priority (high, medium or low). The parameter [eCommandPriority](ms-xhelp:///?Id=beckhoff-9fcc-400f-b6a8-66e61c15362f), which is available for most function blocks, can be used to specify the priority with which the respective DALI command is processed by the function block FB\_DALIV2Communication().

All buffers in which the DALI commands are stored are associated with a variable of type ST\_DALIV2CommandBuffer. There is one instance of the FB\_DALIV2Communication() function block and a variable of type ST\_DALIV2CommandBuffer for each KL6811. If possible, the FB\_DALIV2Communication() function block should be called in a separate, faster task.

The extent to which the buffers are utilized can be determined from the outputs of the function block. Three arrays are output for this in which each element (0, 1 or 2) represents one of the three buffers (high, middle or low). If you detect regular overflow for one of the three buffers, you should consider the following:

* How heavily are the individual PLC tasks utilized? The TwinCAT System Manager offers various appropriate utilities for the analysis.
* Try reducing the cycle time of the task in which the FB\_DALIV2Communication() function block is called. The value should not exceed 6 ms. Ideally it should be 2 ms.
* Check the cycle time of the PLC task in which the function blocks for the individual DALI commands are called. This value should be between 10 ms and 60 ms.
* If possible avoid polling (regular reading) of values. Only read values when they are actually required.
* Distribute the individual control gears evenly over several DALI lines. Overall data throughput is increased by the fact that several DALI lines are processed simultaneously during each PLC cycle.

## VAR\_INPUT

```
bResetMaximumDemandCounter : BOOL;  
bResetOverflowCounter      : BOOL;
```

**bResetMaximumDemandCounter:** a positive edge resets the stored value of the maximum command buffer utilization, *arrBufferMaximumDemandMeter* (0 - 100%, see VAR\_OUTPUT).

**bResetOverflowCounter:** a positive edge resets the stored value of the number of command buffer overflows, *arrBufferOverflowCounter* (see VAR\_OUTPUT).

## VAR\_OUTPUT

```
arrBufferDemandMeter        : ARRAY [0..2] OF BYTE;  
arrBufferMaximumDemandMeter : ARRAY [0..2] OF BYTE;  
arrBufferOverflowCounter    : ARRAY [0..2] OF UINT;  
bLineIsBusy                 : BOOL;  
bLineIsInitialized          : BOOL;
```

**arrBufferDemandMeter:** Occupancy of the respective buffer (0 - 100%).

**arrBufferMaximumDemandMeter:** previous maximum occupancy of the respective buffer (0 - 100%).

**arrBufferOverflowCounter:** Number of buffer overflows to date.

**bLineIsBusy:** This output is set as long as the FB\_DALIV2Communication() function block is active.

**bLineIsInitialized:** if the function block is being called for the first time (e.g. when the controller is starting up) an initialization process is executed. No DALI commands can be processed during this time.

## VAR\_IN\_OUT

```
stDALIInData    : ST_DALIV2InData;  
stDALIOutData   : ST_DALIV2OutData;  
stCommandBuffer : ST_DALIV2CommandBuffer;
```

**stDALIInData:** Structure in the input process image of the KL6811. It is used for communication from the KL6811 to the PLC (see [ST\_DALIV2InData](ms-xhelp:///?Id=beckhoff-1dfe-4c40-a48b-5f314b982fef)).

**stDALIOutData:** Structure in the output process image of the KL6811. It is used for communication from the PLC to the KL6811 (see [ST\_DALIV2OutData](ms-xhelp:///?Id=beckhoff-1b01-4a19-bd19-87de7e897cf3)).

**stCommandBuffer:** Reference to the structure for communication (buffer) with the FB\_DALIV2Communication() function block.

## Requirements

| Development environment | required PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_DALI from v3.4.3.0 |

[TwinCAT 3 | PLC Library: Tc2\_DALI](ms-xhelp:///?Id=beckhoff-bad6-4627-b8ac-544f0eee130c)
