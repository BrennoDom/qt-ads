# FB_DALIV2FileLogging

## Library
tcplclib_tc2_dali

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_DALI](ms-xhelp:///?Id=beckhoff-bad6-4627-b8ac-544f0eee130c)
2. [Programming](ms-xhelp:///?Id=beckhoff-1e7b-43d6-a8da-8e0049d24778)
3. [POUs](ms-xhelp:///?Id=beckhoff-3c92-4da6-86d7-db508adfb4f0)
4. [High-Level commands](ms-xhelp:///?Id=beckhoff-19b2-4bc9-a63f-87f11156498e)
5. [Part 202 (emergency lighting)](ms-xhelp:///?Id=beckhoff-07b5-44cf-a3f3-1a7bf71ce22d)
6. FB\_DALIV2FileLogging

# FB\_DALIV2FileLogging

![59224828](/tcplclib_tc2_dali/1033/Images/gif/9007199398188683__en-US__Web.gif)

This function block reads the respective FIFO buffers (IN-OUT variable *fbStringRingBuffer*) written in the *FB\_DALIV2EmergencyLightingFT()* and *FB\_DALIV2EmergencyLightingDT()* function blocks and writes the contents into a log file.

## VAR\_INPUT

```
bStart    : BOOL;  
sPathName : STRING;  
sNetId    : STRING;
```

**bStart:** The function block is activated by a positive edge at this input.

sPathName: Contains the path and file name for the buffer file to be opened.

|  |  |
| --- | --- |
| 63261412 | The path can only point to the local file system of the computer! This means that network paths cannot be specified here. |

**sNetId**: A string containing the network address of the TwinCAT computer where the buffer file is to be written or read can be given here. If it is to be run on the local computer, an empty string can be entered.

## VAR\_OUTPUT

```
bBusy    : BOOL;  
bError   : BOOL;  
nErrorId : UDINT;
```

**bBusy**: When the function block is activated this output is set and remains set until the log buffer is cleared.

**bError**: If an error should occur during the transmission into the log file, then this output is set after the *bBusy* output has been reset.

**nErrId**: Supplies the ADS error number or the command-specific error code (see [error codes](ms-xhelp:///?Id=beckhoff-f739-41c2-8ff6-b502954dc54f)) when the *bError* output is set.

## VAR\_IN\_OUT

```
fbStringRingBuffer : FB_MemRingBuffer;
```

**fbStringRingBuffer:** Reference to the FIFO buffer in which the log entries are stored.

## Requirements

| Development environment | required PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_DALI from v3.4.3.0 |

[TwinCAT 3 | PLC Library: Tc2\_DALI](ms-xhelp:///?Id=beckhoff-bad6-4627-b8ac-544f0eee130c)
