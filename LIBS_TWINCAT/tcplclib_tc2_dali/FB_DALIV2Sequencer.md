# FB_DALIV2Sequencer

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
7. FB\_DALIV2Sequencer

# FB\_DALIV2Sequencer

![8340425](/tcplclib_tc2_dali/1033/Images/gif/9007199398124683__en-US__Web.gif)

Function block for realizing light sequences with up to 50 interpolation points.

The core of this function block is a ramp block that drives over an adjustable time to individual brightness values defined in a table and then remains at this brightness value for a similarly definable time. After the dwell time the next value is then driven to. As already mentioned, the table *arrSequenceTable* consists of 50 entries with the values for *nTargetValue* (target value), *tRampTime* (time taken to reach the target value) and *tProlongTime* (dwell time at the target value). It is not absolutely necessary to use all 50 values. A 0 entry of all 3 values marks the end of a sequence. Beyond that it is possible using the *nStartIndex* input to have a light sequence begin at any desired place in the table. This allows several different light sequences to be programmed even within the 50 entries, the sequences being separated from one another by 0 entry elements:

![7954964](/tcplclib_tc2_dali/1033/Images/jpg/143386891__en-US__Web.jpg)

Over the course of time sequence 1, for example, looks like the following (*nStartIndex=1, nOptions.bit0=TRUE*, see below for explanation):

![4485813](/tcplclib_tc2_dali/1033/Images/jpg/143390091__en-US__Web.jpg)

Beyond that the function block can be switched "normally" on and off (On: maximum value of the lamps, Off: 0) and switched back and forth between "On" and "Off" using the *bToggle* input. However, none of the command inputs is active unless the *bEnable* input is *TRUE*. If it is reset to *FALSE*, no more commands are accepted and the light value retains its current state – even from a ramp.

|  |  |
| --- | --- |
| 40372317 | As explained at the beginning, this function block is based on the [FB\_DALIV2Ramp](ms-xhelp:///?Id=beckhoff-09a7-4775-ba66-3a603bff468b). The ramp block tries to map the set ramp time as accurately as possible. Nevertheless it is necessary to query data from the DALI control gears both once and cyclically, which takes a different amount of time depending on the set PLC cycle time. Therefore inaccuracies in the ramp time cannot be ruled out. |

## VAR\_INPUT

```
bEnable                    : BOOL := TRUE;  
bOn                        : BOOL;  
bOff                       : BOOL;  
bToggle                    : BOOL;  
bStart                     : BOOL;  
nStartIndex                : USINT := 0;  
arrSequenceTable           : ARRAY [1..nMaxSequenceValues] OF ST_DALIV2SequenceTable;  
nOptions                   : DWORD := 0;  
nAddr                      : BYTE := 0;  
eAddrType                  : E_DALIV2AddrType := eDALIV2AddrTypeShort;  
nMasterDevAddr             : BYTE := 0;  
tCycleActualLevelMasterDev : TIME := t#0s;
```

**bEnable:** The *bOn*, *bOff*, *bToggle* and *bStart* inputs are active as long as this input is *TRUE*. A negative state deactivates the inputs and resets the function block.

**bOn:** A positive edge directly switches *nActualLevelMasterDevice* to the maximum value.

**bOff:** A positive edge immediately switches *nActualLevelMasterDevice* to “0”.

**bToggle:** Switches the light state back and forth respectively between On (maximum value) and Off (0).

**bStart:** A positive edge starts a light sequence from the beginning defined under *nStartIndex*.

**nStartIndex:** see *bStart.*

**arrSequenceTable:** Light value table with the associated ramp and dwell times (see [ST\_DALIV2SequenceTable](ms-xhelp:///?Id=beckhoff-55a1-453c-bf30-fdf25bce59e6)).

**nOptions:** Parameterization input. The setting (or non-setting) of the individual bits of this variable of the type *DWORD* has the following effect:

| Bit | Description |
| --- | --- |
| 0 | **not set:** The function block ceases its activity following the expiry of a sequence. Another positive edge at *bStart* would be required for a sequence restart. **set:** Following the expiry of a sequence, the function block automatically continues at the point defined at *nStartIndex*. |
| 1..31 | -- reserved for future options -- |

**nAddr:** Address of the single device in case of individual control or of the group in the case of group control.

**nMasterDevAddr:** The address of the master device for group and common switching operations.

**eAddrType:** Short address, group address or broadcast (see [E\_DALIV2AddrType](ms-xhelp:///?Id=beckhoff-d59c-42a4-9d77-6cc67c0d1971)).

**tCycleActualLevelMasterDev:** Cycle time with which the actual value is read in the background (see [ACTUAL DIM LEVEL](ms-xhelp:///?Id=beckhoff-1d79-413e-9ba3-da1d3f8e708e)). So that the controlling of the lamps is not disturbed, reading always has the lowest priority. If the value is set to 0, reading is prohibited.

## VAR\_OUTPUT

```
nActualLevelMasterDev : BYTE;  
nActualIndex          : USINT;  
bLight                : BOOL;  
bSequenceActive       : BOOL;  
bBusy                 : BOOL;  
bError                : BOOL;  
nErrorId              : UDINT;
```

**nActualLevelMasterDev:** Current output value of the master device (always the respectively addressed device if *eAddrType = eAddrTypeShort*).

**nActualIndex** **:** Reference to the current element in the sequence table. Once a sequence is finished (*bSequenceActive* = FALSE, see below), this output becomes "0".

**bLight:** This output is set as long as *nActualLevelMasterDev* is greater than "0".

**bSequenceActive:** On processing a sequence this output is set to *TRUE*.

**bBusy:** This output is always active as long as the processing of a command (*bOn, bOff, bToggle* or ramp) is active.

**bError:** This output is switched to TRUE as soon as an error occurs during the execution of a command. The command-specific error code is contained in *nErrorId*. Is reset to FALSE by the execution of a command at the inputs.

**nErrorId:** Contains the specific error code of the most recently executed command. Is reset to "0" by the execution of a command at the inputs. (See [error codes](ms-xhelp:///?Id=beckhoff-f739-41c2-8ff6-b502954dc54f))

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
