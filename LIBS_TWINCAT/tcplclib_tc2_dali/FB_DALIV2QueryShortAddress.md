# FB_DALIV2QueryShortAddress

## Library
tcplclib_tc2_dali

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_DALI](ms-xhelp:///?Id=beckhoff-bad6-4627-b8ac-544f0eee130c)
2. [Programming](ms-xhelp:///?Id=beckhoff-1e7b-43d6-a8da-8e0049d24778)
3. [POUs](ms-xhelp:///?Id=beckhoff-3c92-4da6-86d7-db508adfb4f0)
4. [Low-Level commands](ms-xhelp:///?Id=beckhoff-408c-4669-b5d5-6c547023c614)
5. [Part 102 (control gears)](ms-xhelp:///?Id=beckhoff-2528-40a8-b5c9-22865af95d5d)
6. [Special commands](ms-xhelp:///?Id=beckhoff-9bdd-49d7-995c-2dd0b8a979ea)
7. FB\_DALIV2QueryShortAddress

# FB\_DALIV2QueryShortAddress

![10896307](/tcplclib_tc2_dali/1033/Images/gif/9007199398015883__en-US__Web.gif)

Once the control gear has been selected, it sends its short address ([SHORT ADDRESS](ms-xhelp:///?Id=beckhoff-1d79-413e-9ba3-da1d3f8e708e)).

Selected means:

* The [RANDOM ADDRESS](ms-xhelp:///?Id=beckhoff-1d79-413e-9ba3-da1d3f8e708e) of the control gear is the same as the [SEARCH ADDRESS](ms-xhelp:///?Id=beckhoff-1d79-413e-9ba3-da1d3f8e708e).
* Physical selection is determined by the control gear, as the lamp has been disconnected from the control gear (after receiving the [FB\_DALIV2PhysicalSelection()](ms-xhelp:///?Id=beckhoff-dfc6-4596-9764-6153ca2a7110) command).

## VAR\_INPUT

```
bStart           : BOOL;  
eCommandPriority : E_DALIV2CommandPriority := eDALIV2CommandPriorityMiddle;
```

**bStart:** The function block is activated by a positive edge at this input.

**eCommandPriority:** Priority (high, medium or low) with which the command is processed by the library (see [E\_DALIV2CommandPriority](ms-xhelp:///?Id=beckhoff-9fcc-400f-b6a8-66e61c15362f)).

## VAR\_OUTPUT

```
bBusy         : BOOL;  
bError        : BOOL;  
nErrorId      : UDINT;  
nShortAddress : BYTE;
```

**bBusy:** When the function block is activated the output is set, and it remains active until execution of the command has been completed.

**bError:** This output is switched to TRUE as soon as an error occurs during the execution of a command. The command-specific error code is contained in *nErrorId*. Is reset to FALSE by the execution of a command at the inputs.

**nErrorId:** Contains the command-specific error code of the most recently executed command. Is reset to 0 by the execution of a command at the inputs. (See [error codes](ms-xhelp:///?Id=beckhoff-f739-41c2-8ff6-b502954dc54f))

**nShortAddress:** Short address of the control gear (0 - 63).

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
