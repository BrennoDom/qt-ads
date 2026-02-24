# FB_DALIV2xVerifyShortAddress

## Library
tcplclib_tc2_dali

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_DALI](ms-xhelp:///?Id=beckhoff-bad6-4627-b8ac-544f0eee130c)
2. [Programming](ms-xhelp:///?Id=beckhoff-1e7b-43d6-a8da-8e0049d24778)
3. [POUs](ms-xhelp:///?Id=beckhoff-3c92-4da6-86d7-db508adfb4f0)
4. [Low-Level commands](ms-xhelp:///?Id=beckhoff-408c-4669-b5d5-6c547023c614)
5. [Part 103 (control units)](ms-xhelp:///?Id=beckhoff-bcd5-40f9-b896-132b5f8dc7fd)
6. [Special commands](ms-xhelp:///?Id=beckhoff-d352-4198-9821-91a6a43c397a)
7. FB\_DALIV2xVerifyShortAddress

# FB\_DALIV2xVerifyShortAddress

![7437765](/tcplclib_tc2_dali/1033/Images/gif/4415269515__Web.gif)

If the short address of the control unit is equal to the parameter *nShortAddress*, the output *bAnswer* is set to TRUE.

## VAR\_INPUT

```
bStart            : BOOL;  
eCommandPriority  : E_DALIV2CommandPriority := eDALIV2CommandPriorityMiddle;  
nShortAddress     : BYTE;  
eDataFrameType    : E_DALIV2DataFrameType := eDALIV2DataFrameType24Bit;
```

**bStart:** The function block is activated by a positive edge at this input.

**eCommandPriority**: Priority (high, medium or low) with which the command is processed by the library (see [E\_DALIV2CommandPriority](ms-xhelp:///?Id=beckhoff-9fcc-400f-b6a8-66e61c15362f)).

**nShortAddress**: Short address with which the own address is to be compared.

**eDataFrameType**: Output format of the DALI command (*eDALIV2DataFrameType24Bit* or *eDALIV2DataFrameTypeOsram*) (see [E\_DALIV2DataFrameType](ms-xhelp:///?Id=beckhoff-fd87-4eb1-ba5f-fa6ea24f5b9d)).

## VAR\_OUTPUT

```
bBusy    : BOOL;  
bError   : BOOL;  
nErrorId : UDINT;  
bAnswer  : BOOL;
```

**bBusy:** When the function block is activated the output is set, and it remains active until execution of the command has been completed.

**bError:** This output is switched to TRUE as soon as an error occurs during the execution of a command. The command-specific error code is contained in *nErrorId*. Is reset to FALSE by the execution of a command at the inputs.

**nErrorId:** Contains the command-specific error code of the most recently executed command. Is reset to 0 by the execution of a command at the inputs. (See [Error codes](ms-xhelp:///?Id=beckhoff-f739-41c2-8ff6-b502954dc54f))

**bAnswer:** The *nShortAddress* parameter is the same as its own short address.

## VAR\_IN\_OUT

```
stCommandBuffer   : ST_DALIV2CommandBuffer;
```

**stCommandBuffer**: Reference to the internal structure for communication with the function block [FB\_KL6821Communication()](ms-xhelp:///?Id=beckhoff-24f5-4307-8c46-040081763250) (KL6821).

## Requirements

| Development environment | required PLC library |
| --- | --- |
| TwinCAT from v3.1.4022.4 | Tc2\_DALI from v3.6.2.0 |

[TwinCAT 3 | PLC Library: Tc2\_DALI](ms-xhelp:///?Id=beckhoff-bad6-4627-b8ac-544f0eee130c)
