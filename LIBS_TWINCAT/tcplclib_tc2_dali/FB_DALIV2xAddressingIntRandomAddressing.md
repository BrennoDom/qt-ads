# FB_DALIV2xAddressingIntRandomAddressing

## Library
tcplclib_tc2_dali

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_DALI](ms-xhelp:///?Id=beckhoff-bad6-4627-b8ac-544f0eee130c)
2. [Programming](ms-xhelp:///?Id=beckhoff-1e7b-43d6-a8da-8e0049d24778)
3. [POUs](ms-xhelp:///?Id=beckhoff-3c92-4da6-86d7-db508adfb4f0)
4. [High-Level commands](ms-xhelp:///?Id=beckhoff-19b2-4bc9-a63f-87f11156498e)
5. [Part 103 (control units)](ms-xhelp:///?Id=beckhoff-7c75-4e57-be0c-df25a53078a0)
6. [Addressing](ms-xhelp:///?Id=beckhoff-547a-48a7-9385-05f772490234)
7. FB\_DALIV2xAddressingIntRandomAddressing

# FB\_DALIV2xAddressingIntRandomAddressing

![62509834](/tcplclib_tc2_dali/1033/Images/gif/4415303179__Web.gif)

This function block addresses the control units (sensors) at random. The user has no influence on which control unit is assigned which short address. Short addresses are allocated in ascending order.

Applying a positive edge to the *bStart* input starts the function block, and the *bBusy* output goes TRUE. The terminal now addresses all control units independently. If all control units are addressed, the *bBusy* output goes back to FALSE. The output variable *nAddressedDevices* provides information on how many control units were assigned a short address. Depending on the number of connected control units, processing of this function block can take several minutes.

## VAR\_INPUT

```
bStart                 : BOOL;  
nStartWithShortAddress : BYTE := 0;  
nOptions               : DWORD := DALIV2_OPTION_OPTICAL_FEEDBACK;  
eDataFrameType         : E_DALIV2DataFrameType := eDALIV2DataFrameType24Bit;
```

**bStart:** A positive edge at this input activates the function block, thereby starting the addressing sequence.

**nStartWithShortAddress**: Short address assigned to the first control unit (0... 63).

**nOptions**: Options for addressing control units (see table). The individual constants must be linked with OR operators.

**eDataFrameType**: Output format of the DALI command (*eDALIV2DataFrameType24Bit* or *eDALIV2DataFrameTypeOsram*).

| Constant | Description |
| --- | --- |
| DALIV2\_OPTION\_COMPLETE\_NEW\_INSTALLATION | All control units are redirected, even those that already have a short address. |
| DALIV2\_OPTION\_OPTICAL\_FEEDBACK | Newly addressed control units receive the DALI command IDENTIFY DEVICE after the short addresses have been assigned. |

## VAR\_OUTPUT

```
bBusy                   : BOOL;  
bError                  : BOOL;  
nErrorId                : UDINT;  
nAddressedDevices       : BYTE;
```

**bBusy**: When the function block is activated the output is set, and it remains active until execution of the command has been completed.

**bError**: This output is switched to TRUE as soon as an error occurs during the execution of a command. The command-specific error code is contained in *nErrorId*. Is reset to FALSE by the execution of a command at the inputs.

**nErrorId**: Contains the command-specific error code of the most recently executed command. Is reset to 0 by the execution of a command at the inputs. (See [error codes](ms-xhelp:///?Id=beckhoff-f739-41c2-8ff6-b502954dc54f))

**nAddressedDevices**: When addressing is completed (*bBusy* is FALSE), the number of addressed control units is displayed at this output.

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
