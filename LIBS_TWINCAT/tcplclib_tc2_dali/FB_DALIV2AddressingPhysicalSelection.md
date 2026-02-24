# FB_DALIV2AddressingPhysicalSelection

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
7. FB\_DALIV2AddressingPhysicalSelection

# FB\_DALIV2AddressingPhysicalSelection

![61747774](/tcplclib_tc2_dali/1033/Images/gif/9007199398070283__en-US__Web.gif)

This function block addresses the control gears through 'physical selection' based on the addressing technique. This means that the individual control gears are selected (and therefore addressed) by removing the lamps. Short addresses are allocated (ascending) in the same order in which the lamps are removed.

Applying a positive edge to the *bStart* input starts the function block, and the *bBusy* output goes TRUE. Depending on the selected options (parameter *nOptions*) the group membership and scenarios are subsequently deleted. The *eCurrentAddressingState* output specifies the next required user operation. It determines whether for the next control gear the lamp should be removed or reinserted. The *arrAddressedDevices* output variable provides information about which control gears have already been allocated a short address. Once all control gears have been addressed, the addressing procedure is completed through a positive edge at input *bStop*, and the *bBusy* output switches back to FALSE.

## VAR\_INPUT

```
bStart                 : BOOL;  
bStop                  : BOOL;  
nStartWithShortAddress : BYTE := 0;  
nOptions               : DWORD := DALIV2_OPTION_OPTICAL_FEEDBACK;
```

**bStart:** A rising edge at this input activates the function block, thereby starting the addressing sequence.

**bStop:** A rising edge at this input deactivates the function block, thereby stopping the addressing sequence.

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
bBusy                   : BOOL;  
bError                  : BOOL;  
nErrorId                : UDINT;  
arrAddressedDevices     : ARRAY [0..63] OF BOOL;  
eCurrentAddressingState : E_DALIV2CurrentAddressingState;
```

**bBusy:** When the function block is activated the output is set, and it remains active until execution of the command has been completed.

**bError:** This output is switched to TRUE as soon as an error occurs during the execution of a command. The command-specific error code is contained in *nErrorId*. Is reset to FALSE by the execution of a command at the inputs.

**nErrorId:** Contains the command-specific error code of the most recently executed command. Is reset to 0 by the execution of a command at the inputs. (See [error codes](ms-xhelp:///?Id=beckhoff-f739-41c2-8ff6-b502954dc54f))

**arrAddressedDevices:** Once a short address is assigned to a control gear, the associated element is set in the structure. The structure index reflects the short address of the control gear.

**eCurrentAddressingState:** The output variable indicates the current step (see [E\_DALIV2CurrentAddressingState](ms-xhelp:///?Id=beckhoff-3ab6-41d9-9106-e66767a54b37)).

| Element | Description |
| --- | --- |
| eDALIV2AddrStateIdle | No addressing takes place. |
| eDALIV2AddrStateRemoveLamp | The function block waits for a lamp to be removed at a control gear. |
| eDALIV2AddrStateReinsertLamp | The function block has detected the control gear on which the lamp was removed (the control gear is selected) and now waits for it to be inserted again. |
| eDALIV2AddrStateAddressingLamp | The selected control gear is addressed. |

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
