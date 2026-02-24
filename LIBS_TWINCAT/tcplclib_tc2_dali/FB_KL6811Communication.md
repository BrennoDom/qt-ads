# FB_KL6811Communication

## Library
tcplclib_tc2_dali

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_DALI](ms-xhelp:///?Id=beckhoff-bad6-4627-b8ac-544f0eee130c)
2. [Programming](ms-xhelp:///?Id=beckhoff-1e7b-43d6-a8da-8e0049d24778)
3. [POUs](ms-xhelp:///?Id=beckhoff-3c92-4da6-86d7-db508adfb4f0)
4. [Low-Level commands](ms-xhelp:///?Id=beckhoff-408c-4669-b5d5-6c547023c614)
5. [Base](ms-xhelp:///?Id=beckhoff-48f6-479b-b1fc-0ba402ee9f92)
6. FB\_KL6811Communication

# FB\_KL6811Communication

![42455531](/tcplclib_tc2_dali/1033/Images/gif/4439185931__Web.gif)

The function blocks for the DALI commands do not access the process image of the KL6811 directly, but place the individual DALI commands in three different buffers. The function block FB\_KL6821Communication() sequentially reads the DALI commands from these three buffers and passes the DALI commands to the KL6821. This prevents multiple function blocks accessing the KL6811 process image at the same time. Each of these three buffers is processed with a different priority (high, medium or low). The parameter [eCommandPriority](ms-xhelp:///?Id=beckhoff-9fcc-400f-b6a8-66e61c15362f), which is available for most function blocks, can be used to specify the priority with which the respective DALI command is processed by the function block FB\_KL6811Communication().

All buffers in which the DALI commands are stored are associated with a variable of type ST\_DALIV2CommandBuffer. For each KL6811 there is one instance of the function block FB\_KL6811Communication() and one variable of type ST\_DALIV2CommandBuffer. If possible, the FB\_KL6811Communication() function block should be called in a separate, faster task.

The extent to which the buffers are utilized can be determined from the outputs of the function block. Three arrays are output for this in which each element (0, 1 or 2) represents one of the three buffers (high, middle or low). If you detect regular overflow for one of the three buffers, you should consider the following:

* How heavily are the individual PLC tasks utilized? The TwinCAT System Manager offers various appropriate utilities for the analysis.
* Try to reduce the cycle time of the task in which the function block FB\_KL6811Communication() is called. The value should not exceed 6 ms. Ideally it should be 2 ms.
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
bBusy                       : BOOL;  
bError                      : BOOL;  
nErrorId                    : BYTE;  
arrBufferDemandMeter        : ARRAY [0..2] OF BYTE;  
arrBufferMaximumDemandMeter : ARRAY [0..2] OF BYTE;  
arrBufferOverflowCounter    : ARRAY [0..2] OF UINT;  
bLineIsBusy                 : BOOL;  
bLineIsInitialized          : BOOL;
```

**bBusy:** When the function block is activated the output is set, and it remains active until execution of the command has been completed.

**bError:** This output is switched to TRUE as soon as an error occurs during the execution of a command. The command-specific error code is contained in *nErrorId*. Is reset to FALSE by the execution of a command at the inputs.

**nErrorId:** Contains the command-specific error code of the most recently executed command. Is reset to 0 by the execution of a command at the inputs. (See [error codes](ms-xhelp:///?Id=beckhoff-f739-41c2-8ff6-b502954dc54f))

**arrBufferDemandMeter:** Occupancy of the respective buffer (0 - 100%).

**arrBufferMaximumDemandMeter:** previous maximum occupancy of the respective buffer (0 - 100%).

**arrBufferOverflowCounter:** Number of buffer overflows to date.

**bLineIsBusy:** The output is set as long as the function block [FB\_KL6811Communication()](ms-xhelp:///?Id=beckhoff-a20b-403b-a517-3ca6697b63e6) is active.

**bLineIsInitialized:** if the function block is being called for the first time (e.g. when the controller is starting up) an initialization process is executed. No DALI commands can be processed during this time.

## VAR\_IN\_OUT

```
stDALIInData    : ST_KL6811InData;  
stDALIOutData   : ST_KL6811OutData;  
stCommandBuffer : ST_DALIV2CommandBuffer;
```

**stDALIInData:** Structure in the input process image of the KL6811. It is used for communication from the KL6811 to the PLC (see [ST\_KL6811InData](ms-xhelp:///?Id=beckhoff-dccd-4fd7-8cb9-1937ea392bcd)).

**stDALIOutData:** Structure in the output process image of the KL6811. It is used for communication from the PLC to the KL6811 (see [ST\_KL6811OutData](ms-xhelp:///?Id=beckhoff-899f-4690-b8a5-8d44960469d0)).

**stCommandBuffer:** A reference to the structure for communication (buffer) with the FB\_EL6811Communication() function block.

## Requirements

| Development environment | required PLC library |
| --- | --- |
| TwinCAT from v3.1.4022.4 | Tc2\_DALI from v3.6.2.0 |

[TwinCAT 3 | PLC Library: Tc2\_DALI](ms-xhelp:///?Id=beckhoff-bad6-4627-b8ac-544f0eee130c)
