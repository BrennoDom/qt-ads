# FB_GENIbusCommunication

## Library
tcplclib_tc2_genibus

## Category
Motion Control

# FB\_GENIbusCommunication

![35285314](/tcplclib_tc2_genibus/1033/Images/gif/18014400583393675__en-US__Web.gif)

The function blocks for the GENIbus commands do not directly access the process image of the selected serial interface; instead, they place the individual GENIbus commands into three different buffers. The FB\_GENIbusCommunication() function block sequentially reads the GENIbus commands from these three buffers and forwards the GENIbus commands to the serial interface. This prevents multiple function blocks accessing the process image of the serial interface at the same time. Each of these three buffers is processed with a different priority (high, medium or low). The parameter [eCommandPriority](ms-xhelp:///?Id=beckhoff-fec5-40f5-b468-f6cc55cf7f3b), which is available for most function blocks, can be used to specify the priority with which the respective GENIbus command is processed by the function block FB\_GENIbusCommunication().

The buffers in which the GENIbus commands are placed are all contained in a variable of the type [ST\_GENIbusCommandBuffer](ms-xhelp:///?Id=beckhoff-6978-4399-b7ee-a1d3e3b97d03). There is one instance of the FB\_GENIbusCommunication() function block and one variable of the type ST\_GENIbusCommandBuffer per serial interface. If possible, the FB\_GENIbusCommunication() function block should be called in a separate, faster task.

The extent to which the buffers are utilized can be determined from the outputs of the block. Three arrays are output for this in which each element (0, 1 or 2) represents one of the three buffers (high, middle or low). If you detect regular overflow for one of the three buffers, you should consider the following:

* How heavily are the individual PLC tasks utilized? TwinCAT XAE provides suitable analysis tools.
* Try reducing the cycle time of the task in which the FB\_GENIbusCommunication() function block is called. The value should not exceed 6 ms. Ideally it should be 2 ms.
* Check the cycle time of the PLC task in which the blocks for the individual GENIbus commands are called. This value should be between 10 ms and 60 ms.
* If possible avoid polling (regular reading) of values. Only read values when they are actually required.

## VAR\_INPUT

```
bResetMaximumDemandCounter    : BOOL;  
bResetOverflowCounter         : BOOL;  
byMasterAddr                  : BYTE;  
dwOptions                     : DWORD := 0;  
eComMode                      : E_GENIbusComMode;
```

**bResetMaximumDemandCounter:** a rising edge resets the stored value of the maximum command buffer utilization, *arrBufferMaximumDemandMeter* (0 - 100%, see VAR\_OUTPUT).

**bResetOverflowCounter:** a rising edge resets the stored value of the number of command buffer overflows, *arrBufferOverflowCounter* (see VAR\_OUTPUT).

**byMasterAddr:** specifies the address that the TwinCAT controller should have within the GENIbus line. Possible input range: 0 - 31.

**dwOptions:** reserved for future applications.

**eComMode:** the selection of the serial communication interface must be entered at this parameter (see [E\_GENIbusComMode](ms-xhelp:///?Id=beckhoff-ee29-461f-b949-4975620a14ff)). If a KL terminal or an EtherCAT Terminal is in use, then a configuration of the connection parameters is internally and automatically started:

* Baud Rate: 9600
* Data bits: 8
* Parity: None
* Stop bits: 1

Unfortunately this is not possible for PC-based interfaces; in this case the parameters must be directly entered in the TwinCAT XAE.

## VAR\_OUTPUT

```
bBusy                        : BOOL;  
bError                       : BOOL;  
udiErrorId                   : UDINT;  
udiErrorArg                  : UDINT;  
arrBufferDemandMeter         : ARRAY[0..2] OF BYTE;  
arrBufferMaximumDemandMeter  : ARRAY[0..2] OF BYTE;  
arrBufferOverflowCounter     : ARRAY[0..2] OF UINT;  
bLineIsBusy                  : BOOL;  
bLineIsInitialized           : BOOL;  
bLineIsConfigured            : BOOL;
```

**bBusy:** a GENIbus command is converted into a serial telegram and transmitted. This flag is reset again following a successful response or following an abort after an error.

**bError:** This output is switched to TRUE as soon as an error occurs during the execution of a command. The command-specific error code is contained in *udiErrorId*.

**udiErrorId:** Contains the command-specific error code of the most recently executed command (see [error codes](ms-xhelp:///?Id=beckhoff-f282-4a41-a9c6-fb23ce5f066d)). It is set back to 0 by the reactivation of the function block via the *bStart* input.

**udiErrorArg:**  if applicable, contains an extended description of the error code.

**arrBufferDemandMeter:** Occupancy of the respective buffer (0 - 100%).

**arrBufferMaximumDemandMeter:** previous maximum occupancy of the respective buffer (0 - 100%).

**arrBufferOverflowCounter:** Number of buffer overflows to date.

**bLineIsBusy:** this output is set as long as the serial communication is active.

**bLineIsInitialized:** if the block is being called for the first time (e.g. when the controller is starting up) an initialization process is executed. No GENIbus commands can be processed during this time.

**bLineIsConfigured:** this output indicates with TRUE that the terminal has been successfully configured with the above serial parameters. This output is automatically set if the interface is a PC interface, since the user has to enter the parameters himself in the TwinCAT XAE.

|  |  |
| --- | --- |
| 49132373 | since an error may not interrupt the execution of the function block, bError, udiErrorId and udiErrorArg are initially reset in every PLC cycle and then re-evaluated. |

## VAR\_IN\_OUT

```
stInData              : ST_GENIbusInData;  
stOutData             : ST_GENIbusOutData;  
stCommandBuffer       : ST_GENIbusCommandBuffer;
```

**stInData :** reference to the structure which contains the input process image for communication with the serial interface (see [ST\_GENIbusInData](ms-xhelp:///?Id=beckhoff-ec87-4348-878f-1a7fa2e635be)).

**stOutData :** reference to the structure which contains the output process image for communication with the serial interface (see [ST\_GENIbusOutData](ms-xhelp:///?Id=beckhoff-9690-4e4a-bd84-1e36c04099db)).

**stCommandBuffer:** reference to the structure for communication (buffer) with the GENIbus function blocks (see [ST\_GENIbusCommandBuffer](ms-xhelp:///?Id=beckhoff-6978-4399-b7ee-a1d3e3b97d03)).

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_GENIbus from v3.3.0.0 |
