# FB_KL6831KL6841Communication

## Library
tcplclib_tc2_smi

## Category
Motion Control

# FB\_KL6831KL6841Communication

![54881489](/tcplclib_tc2_smi/1033/Images/gif/9007199328388491__en-US__Web.gif)

The function blocks for the SMI commands do not directly access the process image of the KL6831/KL6841; instead, they place the individual SMI commands into three different buffers. The *FB\_KL6831KL6841Communication()* block reads the SMI commands sequentially from these three buffers and forwards them to the KL6831/KL6841. This prevents multiple blocks accessing the KL6831/KL68411 process image at the same time. Each of these three buffers is processed with a different priority (high, medium or low). The parameter [eCommandPriority](ms-xhelp:///?Id=beckhoff-aeef-4170-a977-ee991c8e24eb), which is available for most function blocks, can be used to specify the priority with which the respective SMI command is processed by the block *FB\_KL6831KL6841Communication*().

The buffers in which the SMI commands are placed are all contained in a variable of the type [ST\_SMICommandBuffer](ms-xhelp:///?Id=beckhoff-f0f7-4a8a-a4b0-c7cf3a9ab7f4). For each KL6831/KL6841 there is an instance of the *FB\_KL6831KL6841Communication()* function block and a variable of the type *ST\_SMICommandBuffer*. If possible, the *FB\_KL6831KL6841Communication()* function block should be called in a separate, faster task.

The extent to which the buffers are utilized can be determined from the outputs of the block. Three arrays are output for this in which each element (0, 1 or 2) represents one of the three buffers (high, middle or low). If you detect regular overflow for one of the three buffers, you should consider the following:

* How heavily are the individual PLC tasks utilized? TwinCAT XAE provides suitable analysis tools.
* Try reducing the cycle time of the task in which the *FB\_KL6831KL6841Communication()* function block is called. The value should not exceed 6 ms. Ideally it should be 2 ms.
* Check the cycle time of the PLC task in which the blocks for the individual SMI commands are called. This value should be between 10 ms and 60 ms.
* If possible avoid polling (regular reading) of values. Only read values when they are actually required.
* Distribute the individual drives evenly over several SMI lines. Since several SMI lines are processed simultaneously per PLC cycle, the data throughput as a whole is increased as a result.

## VAR\_INPUT

```
bResetMaximumDemandCounter : BOOL;  
bResetOverflowCounter      : BOOL;  
bResetInactiveProcessImage : BOOL;  
bResetDataFrameError       : BOOL;  
dwOptions                  : DWORD := 0;
```

**bResetMaximumDemandCounter:** a positive edge resets the stored value of the maximum command buffer utilization *(arrBufferMaximumDemandMeter)*.

**bResetOverflowCounter:** a positive edge resets the stored value of the number of command buffer overflows *(arrBufferOverflowCounter)*.

**bResetInactiveProcessImage:** A positive edge cancels the blocking of the process image of the terminal. The *bProcessImageInactive*, *bDigitalInput1Active* and *bDigitalInput2Active* outputs are again set to FALSE. The blocking is activated as soon as one of the digital inputs *Input1* or *Input2* on the terminal is actuated.

**bResetDataFrameError:** a positive edge resets the message for a telegram error. The *bDataFrameError* output is set again to FALSE. The blocking is activated as soon as the terminal detects a telegram error.

**dwOptions:** reserved for future expansions.

## VAR\_OUTPUT

```
bBusy                       : BOOL;  
bError                      : BOOL;  
udiErrorId                  : UDINT;  
arrBufferDemandMeter        : ARRAY [0..2] OF BYTE;  
arrBufferMaximumDemandMeter : ARRAY [0..2] OF BYTE;  
arrBufferOverflowCounter    : ARRAY [0..2] OF UINT;  
bLineIsInitialized          : BOOL;  
b24VPowerSupplySwitchedOn   : BOOL;  
bDigitalInput1Active        : BOOL;  
bDigitalInput2Active        : BOOL;  
bProcessImageInactive       : BOOL;  
bDataFrameError             : BOOL;  
bChecksumError              : BOOL;
```

**bBusy:** this output is set as soon as the function block processes a command and remains active until the command has been processed.

**bError:** This output is switched to TRUE as soon as an error occurs during the execution of a command. The command-specific error code is contained in *udiErrorId*. The output is set back to FALSE by the reactivation of the function block via the *bStart* input.

**udiErrorId:** Contains the command-specific error code of the most recently executed command. It is set back to 0 by the reactivation of the function block via the *bStart* input (see [error codes](ms-xhelp:///?Id=beckhoff-050f-4816-bd32-717f5461c1a7)).

**arrBufferDemandMeter:** Occupancy of the respective buffer (0 - 100%).

**arrBufferMaximumDemandMeter:** previous maximum occupancy of the respective buffer (0 - 100%).

**arrBufferOverflowCounter:** Number of buffer overflows to date.

**bLineIsInitialized:** if the function block is being called for the first time (e.g. when the controller is starting up) an initialization process is executed. No SMI commands can be processed during this time. This output is set to TRUE once the initialization has been completed.

**b24VPowerSupplySwitchedOn:** the KL6831/KL6841 must be supplied with 24 V DC via two connections. The output is set as soon as 24 V DC is detected. If there is no 24 V DC the output goes FALSE and no SMI commands can be processed by the controller as long as there is no 24 V DC.

**bDigitalInput1Active:** the digital input *Input1* on the terminal has been or is actuated (see also the terminal documentation). The *bProcessImageInactive* output is set and no further SMI commands can be processed by the controller.

**bDigitalInput2Active:** the digital input *Input2* on the terminal has been or is actuated (see also the terminal documentation). The *bProcessImageInactive* output is set and no further SMI commands can be processed by the controller.

**bProcessImageInactive:** one of the digital inputs *Input1* or *Input2* has been actuated on the terminal. No further SMI commands can be processed by the controller. The blockage must be released again via the *bResetInactiveProcessImage* input.

**bDataFrameError:** the terminal has detected a telegram error on the SMI bus. The error must be reset via the *bResetDataFrameError* input.

**bChecksumError:** the terminal has detected a checksum error on the SMI bus. The message is automatically reset as soon as a telegram is transmitted without error once again.

## VAR\_IN\_OUT

```
stInData        : ST_KL6831KL6841InData;  
stOutData       : ST_KL6831KL6841OutData;  
stCommandBuffer : ST_SMICommandBuffer;
```

**stInData :** Reference to the structure for communication with the KL6831/KL6841 (see [ST\_KL6831KL6841InData](ms-xhelp:///?Id=beckhoff-a24c-4afa-b979-d7030f7fcf67) ).

**stOutData :** Reference to the structure for communication with the KL6831/KL6841 (see [ST\_KL6831KL6841OutData](ms-xhelp:///?Id=beckhoff-acfb-4280-bad8-ec342196d7dc)).

**stCommandBuffer:** Reference to the structure for communication with the SMI blocks (see [ST\_SMICommandBuffer](ms-xhelp:///?Id=beckhoff-f0f7-4a8a-a4b0-c7cf3a9ab7f4)).

## Prerequisites

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_SMI from 3.3.5.0 |
