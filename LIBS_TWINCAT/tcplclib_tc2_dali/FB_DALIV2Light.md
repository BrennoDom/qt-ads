# FB_DALIV2Light

## Library
tcplclib_tc2_dali

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_DALI](ms-xhelp:///?Id=beckhoff-bad6-4627-b8ac-544f0eee130c)
2. [Programming](ms-xhelp:///?Id=beckhoff-1e7b-43d6-a8da-8e0049d24778)
3. [POUs](ms-xhelp:///?Id=beckhoff-3c92-4da6-86d7-db508adfb4f0)
4. [High-Level commands](ms-xhelp:///?Id=beckhoff-19b2-4bc9-a63f-87f11156498e)
5. [Part 102 (control gears)](ms-xhelp:///?Id=beckhoff-9f59-405b-9b5e-1a946f4c914f)
6. [Power control](ms-xhelp:///?Id=beckhoff-4c5d-4a51-898b-3f3ce005dcad)
7. FB\_DALIV2Light

# FB\_DALIV2Light

![64665535](/tcplclib_tc2_dali/1033/Images/gif/9007199398111883__en-US__Web.gif)

The FB\_DALIV2Light() function block is a simple function block for switching DALI lamps on and off.

## Operation

A positive edge applied to the *bOn* input will switch the light to the maximum value ([MAX LEVEL](ms-xhelp:///?Id=beckhoff-1d79-413e-9ba3-da1d3f8e708e)) of the control gear. If the function block is executed successfully, the *bLight* output is set to TRUE. Applying a positive edge to the *bOff* input will switch the light off, and the *bLight* output will be set to FALSE. If a positive edge is applied to *bToggle*, the function block first reads the current light value from the master device, and then decides whether the status of the lamp is on or off. Once this decision has been reached, the lamp is then placed into whatever the other state is, i.e. it is switched from on to off or from off to on.

## Comment on the nMasterDevAddr parameter

The DALI system provides facilities not just for controlling lamps individually, but also for addressing them as groups or through common commands. Since the individual devices may belong to different groups, the individual lamps may have different brightness states before a group or common control command. So that it is nevertheless possible to be clear whether the lamps now are to be switched on or off, a master device is assigned to each group, whose state is followed by the other devices. It is not necessary to specify a master device if the function block is to be used to control a single lamp, *eAddrType* = *eAddrTypeShort*. *In this case, the nMasterDevAddr* parameter has no significance.

## VAR\_INPUT

```
bOn                        : BOOL;  
bOff                       : BOOL;  
bToggle                    : BOOL;  
nAddr                      : BYTE := 0;  
eAddrType                  : E_DALIV2AddrType := eDALIV2AddrTypeShort;  
nMasterDevAddr             : BYTE := 0;  
tCycleActualLevelMasterDev : TIME := t#0s;
```

**bOn:** Switches the addressed devices on (to the value [MAX LEVEL](ms-xhelp:///?Id=beckhoff-1d79-413e-9ba3-da1d3f8e708e)).

**bOff:** Switches the addressed devices off (to value 0).

**bToggle:** Reverses the status of the addressed devices.

**nAddr:** The address of a participating device or of a group.

**eAddrType:** Short address, group address or broadcast (see [E\_DALIV2AddrType](ms-xhelp:///?Id=beckhoff-d59c-42a4-9d77-6cc67c0d1971)).

**nMasterDevAddr:** The address of the master device for group and common switching operations.

**tCycleActualLevelMasterDev:** Cycle time required to read the current actual value (see [ACTUAL DIM LEVEL](ms-xhelp:///?Id=beckhoff-1d79-413e-9ba3-da1d3f8e708e)) in the background. So that the dimming of the lamps is not disturbed, reading always has the lowest priority. If the value is set to 0, reading is prohibited.

## VAR\_OUTPUT

```
bLight   : BOOL;  
bBusy    : BOOL;  
bError   : BOOL;  
nErrorId : UDINT;
```

**bLight:** The status of the lamp or group after the function block has been called.

**bBusy:** When the function block is activated the output is set, and it remains active until execution of the command has been completed.

**bError:** This output is switched to TRUE as soon as an error occurs during the execution of a command. The command-specific error code is contained in *nErrorId*. Is reset to FALSE by the execution of a command at the inputs.

**nErrorId:** Contains the command-specific error code of the most recently executed command. Is reset to 0 by the execution of a command at the inputs. (See [error codes](ms-xhelp:///?Id=beckhoff-f739-41c2-8ff6-b502954dc54f))

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
