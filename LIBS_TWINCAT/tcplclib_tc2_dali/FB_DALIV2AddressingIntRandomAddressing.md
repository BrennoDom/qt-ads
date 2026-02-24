# FB_DALIV2AddressingIntRandomAddressing

## Library
tcplclib_tc2_dali

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_DALI](ms-xhelp:///?Id=beckhoff-bad6-4627-b8ac-544f0eee130c)
2. [Programming](ms-xhelp:///?Id=beckhoff-1e7b-43d6-a8da-8e0049d24778)
3. [POUs](ms-xhelp:///?Id=beckhoff-3c92-4da6-86d7-db508adfb4f0)
4. [High-Level commands](ms-xhelp:///?Id=beckhoff-19b2-4bc9-a63f-87f11156498e)
5. [Part 102 (control gears)](ms-xhelp:///?Id=beckhoff-9f59-405b-9b5e-1a946f4c914f)
6. [Addressing](ms-xhelp:///?Id=beckhoff-4c3b-4992-8862-5b6f028dc3ef)
7. FB\_DALIV2AddressingIntRandomAddressing

# FB\_DALIV2AddressingIntRandomAddressing

![34731002](/tcplclib_tc2_dali/1033/Images/gif/9007199398076683__en-US__Web.gif)

This function block addresses the control gears in random order. The user has no influence over which short address is assigned to which control gear. Short addresses are allocated in ascending order.

Applying a positive edge to the *bStart* input starts the function block, and the *bBusy* output goes TRUE. Depending on the selected options (parameter *nOptions*) the group membership and scenarios are subsequently deleted.
The terminal now addresses all control gears independently. Once all control gears have been addressed, the *bBusy* output switches back to FALSE. The *nAddressedDevices* output variable supplies information about how many control gears have received a short address.
Processing this function block can take several minutes, depending on how many control gears are attached. Since the addressing is performed directly by the terminal, this method is somewhat faster than the [FB\_DALIV2AddressingRandomAddressing()](ms-xhelp:///?Id=beckhoff-89e0-442c-bff4-24d9b263b726) function block. However, this function block does not supply any feedback during addressing. In addition to that, addressing cannot be terminated prematurely.

|  |  |
| --- | --- |
| 44143566 | This function block can only be executed if the terminal has the firmware version 2A or newer. |

## VAR\_INPUT

```
bStart                 : BOOL;  
nStartWithShortAddress : BYTE := 0;  
nOptions               : DWORD := DALIV2_OPTION_OPTICAL_FEEDBACK;
```

**bStart:** A rising edge at this input activates the function block, thereby starting the addressing sequence.

**nStartWithShortAddress:** Short address allocated to the first ballast (0 ... 63).

**nOptions:** Options for addressing the ballasts (see table). The individual constants must be linked with OR operators.

| Constant | Description |
| --- | --- |
| DALIV2\_OPTION\_COMPLETE\_NEW\_INSTALLATION | All ballasts are re-addressed, including ballasts that already have a short address. |
| DALIV2\_OPTION\_DELETE\_ALL\_GROUP\_ASSIGNMENTS | Prior to addressing, the group associations are deleted for any ballasts, even those which may not be addressed by the addressing method (see variables [GROUP 0-7](ms-xhelp:///?Id=beckhoff-1d79-413e-9ba3-da1d3f8e708e) and [GROUP 8-15](ms-xhelp:///?Id=beckhoff-1d79-413e-9ba3-da1d3f8e708e)). |
| DALIV2\_OPTION\_DELETE\_ALL\_SCENE\_ASSIGNMENTS | Prior to addressing, the scenes are deleted for any ballasts, even those which may not be addressed by the addressing method (see variables [SCENE 0](ms-xhelp:///?Id=beckhoff-1d79-413e-9ba3-da1d3f8e708e) to [SCENE 15](ms-xhelp:///?Id=beckhoff-1d79-413e-9ba3-da1d3f8e708e)). |
| DALIV2\_OPTION\_OPTICAL\_FEEDBACK | Prior to addressing, all ballasts are set to [MIN LEVEL](ms-xhelp:///?Id=beckhoff-1d79-413e-9ba3-da1d3f8e708e). Newly addressed ballasts are assigned [MAX LEVEL](ms-xhelp:///?Id=beckhoff-1d79-413e-9ba3-da1d3f8e708e) brightness after allocation of the short address. |

## VAR\_OUTPUT

```
bBusy             : BOOL;  
bError            : BOOL;  
nErrorId          : UDINT;  
nAddressedDevices : BYTE;
```

**bBusy:** When the function block is activated the output is set, and it remains active until execution of the command has been completed.

**bError:** This output is switched to TRUE as soon as an error occurs during the execution of a command. The command-specific error code is contained in *nErrorId*. Is reset to FALSE by the execution of a command at the inputs.

**nErrorId:** Contains the command-specific error code of the most recently executed command. Is reset to 0 by the execution of a command at the inputs. (See [error codes](ms-xhelp:///?Id=beckhoff-f739-41c2-8ff6-b502954dc54f))

**nAddressedDevices:** If addressing has been completed (*bBusy* is FALSE), then the number of addressed control gears is shown at this output.

## VAR\_IN\_OUT

```
stCommandBuffer   : ST_DALIV2CommandBuffer;
```

**stCommandBuffer**: Reference to the internal structure for communication with the function block [FB\_KL6821Communication()](ms-xhelp:///?Id=beckhoff-24f5-4307-8c46-040081763250) (KL6821).

## Requirements

| Development environment | required PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_DALI from v3.4.3.0 |

[TwinCAT 3 | PLC Library: Tc2\_DALI](ms-xhelp:///?Id=beckhoff-bad6-4627-b8ac-544f0eee130c)
