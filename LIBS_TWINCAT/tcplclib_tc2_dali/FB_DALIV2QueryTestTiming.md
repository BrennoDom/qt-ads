# FB_DALIV2QueryTestTiming

## Library
tcplclib_tc2_dali

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_DALI](ms-xhelp:///?Id=beckhoff-bad6-4627-b8ac-544f0eee130c)
2. [Programming](ms-xhelp:///?Id=beckhoff-1e7b-43d6-a8da-8e0049d24778)
3. [POUs](ms-xhelp:///?Id=beckhoff-3c92-4da6-86d7-db508adfb4f0)
4. [Low-Level commands](ms-xhelp:///?Id=beckhoff-408c-4669-b5d5-6c547023c614)
5. [Part 202 (emergency lighting)](ms-xhelp:///?Id=beckhoff-d13a-4887-aecd-3e1c1e84a57b)
6. FB\_DALIV2QueryTestTiming

# FB\_DALIV2QueryTestTiming

![15334348](/tcplclib_tc2_dali/1033/Images/gif/9007199398239883__en-US__Web.gif)

This function block reads the test times (intervals, time until next event, etc.) from the control gear. This takes place depending on the value applied at the *nDTR* input. The background to this is that the DALI basic command 242 “Query test timing” works together with the contents of the Data Transfer Register (DTR), which must be written to accordingly beforehand. The *FB\_DALIV2QueryTestTiming* function block combines these two actions. The following data are read from the device, depending on the *nDTR* value:

| nDTR | read value |
| --- | --- |
| 0 (2#0000 0000) | If automatic test is activated: Time to the next **function test** (high byte) in 15-minute intervals  If automatic test is **not** enabled: MASK (255) |
| 1 (2#0000 0001) | If automatic test is activated: Time to the next **function test** (low byte) in 15-minute intervals  If automatic test is **not** enabled: MASK (255) |
| 2 (2#0000 0010) | If automatic test is activated: Time to the next **duration test** (high byte) in 15-minute intervals If automatic test is **not** enabled: MASK (255) |
| 3 (2#0000 0011) | If automatic test is activated: Time to the next **duration test** (low byte) in 15-minute intervals If automatic test is **not** enabled: MASK (255) |
| 4 (2#0000 0100) | If automatic test is activated: Test interval of the **function test** in days If automatic test is **not** enabled: MASK (255) |
| 5 (2#0000 0101) | If automatic test is activated: Test interval of the **duration test** in weeks If automatic test is **not** enabled: MASK (255) |
| 6 (2#0000 0110) | Test execution timeout in days (maximum execution period for one test). Applies only to the automatic test! |
| 7 (2#0000 0111) | Lamp-on extension time after exiting from emergency operating mode, measured in 0.5-min steps |

|  |  |
| --- | --- |
| 3791404 | This command belongs to the application-related expansion commands for DALI emergency lighting. They function only if they are preceded by the *Enable Device Type 1* command, which can be sent with the [FB\_DALIV2EnableDeviceType()](ms-xhelp:///?Id=beckhoff-e277-46a4-85ba-43a8cbcb1cb1) function block. The *Enable Device Type 1* command is internally placed automatically before all application-related expansion commands for DALI emergency lighting. |

## VAR\_INPUT

```
bStart           : BOOL;  
nAddr            : BYTE;  
eAddrType        : E_DALIV2AddrType;  
eCommandPriority : E_DALIV2CommandPriority;  
nDTR             : BYTE;
```

**bStart:** The function block is activated by a positive edge at this input.

**nAddr:** The address of a participating device or of a group.

**eAddrType:** Short address, group address or broadcast (see [E\_DALIV2AddrType](ms-xhelp:///?Id=beckhoff-d59c-42a4-9d77-6cc67c0d1971)).

**eCommandPriority:** Priority (high, medium or low) with which the command is processed by the library (see [E\_DALIV2CommandPriority](ms-xhelp:///?Id=beckhoff-9fcc-400f-b6a8-66e61c15362f)).

**nDTR:** The corresponding values are read in accordance to this input, see above.

## VAR\_OUTPUT

```
bBusy    : BOOL;  
bError   : BOOL;  
nErrorId : UDINT;  
nValue   : BYTE;
```

**bBusy:** When the function block is activated the output is set, and it remains active until execution of the command has been completed.

**bError:** This output is switched to TRUE as soon as an error occurs during the execution of a command. The command-specific error code is contained in *nErrorId*. Is reset to FALSE by the execution of a command at the inputs.

**nErrorId:** Contains the command-specific error code of the most recently executed command. Is reset to 0 by the execution of a command at the inputs. (See [error codes](ms-xhelp:///?Id=beckhoff-f739-41c2-8ff6-b502954dc54f))

**nValue:** Result.

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
