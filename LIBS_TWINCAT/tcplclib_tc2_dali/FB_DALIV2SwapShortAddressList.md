# FB_DALIV2SwapShortAddressList

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
7. FB\_DALIV2SwapShortAddressList

# FB\_DALIV2SwapShortAddressList

![58047761](/tcplclib_tc2_dali/1033/Images/gif/9007199398086283__en-US__Web.gif)

The short addresses of several control gears can be swapped using this function block. In order to do this, however, it is necessary that a free, unused short address is present in the DALI line.

In the parameter *arrSwapShortAddressList*, a list of the control gears whose short addresses are to be changed is transferred. The index of the structure thereby corresponds to the short address of the control gear. The element *nNewShortAddress* contains the new short address. *bShortAddressValid* must be tested for TRUE, to ensure that the short address is changed in the corresponding control gear. Applying a positive edge to the *bStart* input starts the function block, and the *bBusy* output goes TRUE. Depending on the chosen options (*nOptions* parameter), all lamps will be set to the value MIN LEVEL. The elements of the output *arrSwapedShortAddresses* are reset. If the new short address is set for a control gear, the corresponding element in the output *arrSwapedShortAddresses* is set to TRUE. If the option DALIV2\_OPTION\_OPTICAL\_FEEDBACK is active, the lamp will in addition be set to the value MAX LEVEL.

## VAR\_INPUT

```
bStart            : BOOL;  
bCancel           : BOOL;  
nFreeShortAddress : BYTE;  
nOptions          : DWORD := DALIV2_OPTION_OPTICAL_FEEDBACK;
```

**bStart:** The function block is activated by a positive edge at this input.

**bCancel:** A rising edge at this input will deactivate the function block and hence abort the swapping of the short addresses.

**nFreeShortAddress:** Free short address (0 – 63).

**nOptions:** Options for swapping short addresses (see table). The individual constants must be linked with OR operators.

| Constant | Description |
| --- | --- |
| DALIV2\_OPTION\_OPTICAL\_FEEDBACK | Before swapping the short addresses, all ballasts are set to [MIN LEVEL](ms-xhelp:///?Id=beckhoff-1d79-413e-9ba3-da1d3f8e708e). After assigning the new short address, the brightness of the respective ballast will be changed to [MAX LEVEL](ms-xhelp:///?Id=beckhoff-1d79-413e-9ba3-da1d3f8e708e). |

## VAR\_OUTPUT

```
bBusy                   : BOOL;  
bError                  : BOOL;  
nErrorId                : UDINT;  
arrSwapedShortAddresses : ARRAY [0..63] OF BOOL;
```

**bBusy:** When the function block is activated the output is set, and it remains active until execution of the command has been completed.

**bError:** This output is switched to TRUE as soon as an error occurs during the execution of a command. The command-specific error code is contained in *nErrorId*. Is reset to FALSE by the execution of a command at the inputs.

**nErrorId:** Contains the command-specific error code of the most recently executed command. Is reset to 0 by the execution of a command at the inputs. (See [error codes](ms-xhelp:///?Id=beckhoff-f739-41c2-8ff6-b502954dc54f))

**arrSwapedShortAddresses:** If the new short address has been set for a control gear, the corresponding element will be set in the structure. The structure index reflects the short address of the control gear.

## VAR\_IN\_OUT

```
arrSwapShortAddressList : ARRAY [0..63] OF ST_DALIV2SwapShortAddressList;  
stCommandBuffer         : ST_DALIV2CommandBuffer;
```

**arrSwapShortAddressList:** A reference to the list containing the short addresses to be swapped (see [ST\_DALIV2SwapShortAddressList](ms-xhelp:///?Id=beckhoff-3579-43a9-bec8-057434735282)).

**stCommandBuffer:** Reference to the internal structure for communication with the function block [FB\_KL6811Communication()](ms-xhelp:///?Id=beckhoff-a20b-403b-a517-3ca6697b63e6) (KL6811) or [FB\_KL6821Communication()](ms-xhelp:///?Id=beckhoff-24f5-4307-8c46-040081763250) (KL6821).

## Requirements

| Development environment | required PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_DALI from v3.4.3.0 |

[TwinCAT 3 | PLC Library: Tc2\_DALI](ms-xhelp:///?Id=beckhoff-bad6-4627-b8ac-544f0eee130c)
