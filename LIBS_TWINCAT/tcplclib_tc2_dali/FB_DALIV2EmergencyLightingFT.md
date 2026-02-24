# FB_DALIV2EmergencyLightingFT

## Library
tcplclib_tc2_dali

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_DALI](ms-xhelp:///?Id=beckhoff-bad6-4627-b8ac-544f0eee130c)
2. [Programming](ms-xhelp:///?Id=beckhoff-1e7b-43d6-a8da-8e0049d24778)
3. [POUs](ms-xhelp:///?Id=beckhoff-3c92-4da6-86d7-db508adfb4f0)
4. [High-Level commands](ms-xhelp:///?Id=beckhoff-19b2-4bc9-a63f-87f11156498e)
5. [Part 202 (emergency lighting)](ms-xhelp:///?Id=beckhoff-07b5-44cf-a3f3-1a7bf71ce22d)
6. FB\_DALIV2EmergencyLightingFT

# FB\_DALIV2EmergencyLightingFT

![24757801](/tcplclib_tc2_dali/1033/Images/gif/9007199398185483__en-US__Web.gif)

This function block is for the function test of a DALI emergency lighting device. At the end of the test the test results are written over a FIFO buffer (IN-OUT variable *fbStringRingBuffer*), which in turn is read by the *FB\_DALIV2FileLogging()* function block into a file. Events that hinder or interrupt the test are displayed in addition to the result message at the *bError* and *nErrorID* outputs.

The following events prevent the execution of a function test:

* The device operates in automatic function test mode, i.e. a test interval is programmed in the device.
* The device is currently executing a test or a test is automatically pending (function or duration test).
* The device is not in emergency standby ("normal mode") at the start of the test.

The events that interrupt a function test that has begun include:

* The device has not reached the function test mode after the test has started.
* The test was not completed correctly, after the test start and a certain delay time the device is eventually neither in test mode nor (back) in emergency standby mode ("normal mode").
* A DALI command was incorrectly processed.
* The timeout has expired.

## VAR\_INPUT

```
bStart       : BOOL;  
nAddr        : BYTE;  
sController  : STRING(20);  
sLineName    : STRING(10);  
sDescription : STRING(20);  
sLocation    : STRING(20);  
stDateTime   : TIMESTRUCT;  
tTimeout     : TIME := t#120m;
```

**bStart:** The function block is activated by a positive edge at this input.

**nAddr:** Address of the device to be tested.

**sController:** Controller to which the DALI device belongs. Serves the description in the log file.

**sLineName:** Line to which the DALI device belongs. Serves the description in the log file.

**sDescription:** Further supplementary description of the device in the log file.

**sLocation:** Description of the installation location.

**stDateTime:** Input for current date and time.

**tTimeout:** Time within which the test must be completed.

## VAR\_OUTPUT

```
tElapsedTestTime : TIME;  
nEmergencyMode   : BYTE;  
nEmergencyStatus : BYTE;  
bBusy            : BOOL;  
bError           : BOOL;  
nErrorId         : UDINT;
```

**tElapsedTestTime:** Test duration. The time output is set to 0 by a rising edge at *bStart* and then counts up as long as the function block is active. Upon a falling edge at *bBusy* the output retains its present value, so that the test duration is still available even after function block processing.

**nEmergencyMode:** During the test, the presently internally queried [emergency mode](ms-xhelp:///?Id=beckhoff-5a16-4048-a4a1-4ec68f5b801b) of the DALI device is output at this output.

**nEmergencyStatus:** the same applies to [emergency status.](ms-xhelp:///?Id=beckhoff-5a16-4048-a4a1-4ec68f5b801b)

**bBusy:** When the function block is activated the output is set, and it remains active until execution of the command has been completed.

**bError:** This output is switched to TRUE if an error, as described above, occurs during the execution of the test. This output is reset on restarting a test.

**nErrorId:** Contains the command-specific error code of the most recently executed command. It is reset to 0 on executing a new test. (See [error codes](ms-xhelp:///?Id=beckhoff-f739-41c2-8ff6-b502954dc54f))

## VAR\_IN\_OUT

```
stCommandBuffer    : ST_DALIV2CommandBuffer;  
fbStringRingBuffer : FB_MemRingBuffer;
```

**stCommandBuffer:** Reference to the internal structure for communication with the function block [FB\_KL6811Communication()](ms-xhelp:///?Id=beckhoff-a20b-403b-a517-3ca6697b63e6) (KL6811) or [FB\_KL6821Communication()](ms-xhelp:///?Id=beckhoff-24f5-4307-8c46-040081763250) (KL6821).

**fbStringRingBuffer:** Reference to the FIFO buffer in which the log entries are stored.

|  |  |
| --- | --- |
| 21493617 | It is not possible for the log function block to write data to a file as long as that file is open. |

## Requirements

| Development environment | required PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_DALI from v3.4.3.0 |

[TwinCAT 3 | PLC Library: Tc2\_DALI](ms-xhelp:///?Id=beckhoff-bad6-4627-b8ac-544f0eee130c)
