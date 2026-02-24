# FB_DALIV2QueryColourValue

## Library
tcplclib_tc2_dali

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_DALI](ms-xhelp:///?Id=beckhoff-bad6-4627-b8ac-544f0eee130c)
2. [Programming](ms-xhelp:///?Id=beckhoff-1e7b-43d6-a8da-8e0049d24778)
3. [POUs](ms-xhelp:///?Id=beckhoff-3c92-4da6-86d7-db508adfb4f0)
4. [Low-Level commands](ms-xhelp:///?Id=beckhoff-408c-4669-b5d5-6c547023c614)
5. [Part 209 (color/color temperature control)](ms-xhelp:///?Id=beckhoff-a837-4797-bf19-33a8438d83d2)
6. FB\_DALIV2QueryColourValue

# FB\_DALIV2QueryColourValue

![36502600](/tcplclib_tc2_dali/1033/Images/gif/9007200263744395__en-US__Web.gif)

The specified variable (color value) is read from the DALI control gear. The value to be read is defined by *nParameter* (see table below).

Certain variables can be read out directly via DALI commands (e.g. [FB\_QueryColorStatus()](ms-xhelp:///?Id=beckhoff-ed62-4911-ad94-6cfea37f52ce) or [FB\_QueryRGBWAFControl ()](ms-xhelp:///?Id=beckhoff-ba08-4f18-a1c9-7d1513ad636d)). Further details on the variables can be found in section [Variables](ms-xhelp:///?Id=beckhoff-1ce6-4fd4-be82-75082326bd44).

| Value | Description |
| --- | --- |
| 0 | x-COORDINATE |
| 1 | y-COORDINATE |
| 2 | COLOR TEMPERATURE Tc |
| 3 | PRIMARY N DIMLEVEL 0 |
| 4 | PRIMARY N DIMLEVEL 1 |
| 5 | PRIMARY N DIMLEVEL 2 |
| 6 | PRIMARY N DIMLEVEL 3 |
| 7 | PRIMARY N DIMLEVEL 4 |
| 8 | PRIMARY N DIMLEVEL 5 |
| 9 | RED DIMLEVEL |
| 10 | GREEN DIMLEVEL |
| 11 | BLUE DIMLEVEL |
| 12 | WHITE DIMLEVEL |
| 13 | AMBER DIMLEVEL |
| 14 | FREECOLOR DIMLEVEL |
| 15 | RGBWAF CONTROL |
| 64 | x-COORDINATE PRIMARY N 0 |
| 65 | y-COORDINATE PRIMARY N 0 |
| 66 | TY PRIMARY N 0 |
| 67 | x-COORDINATE PRIMARY N 1 |
| 68 | y-COORDINATE PRIMARY N 1 |
| 69 | TY PRIMARY N 1 |
| 70 | x-COORDINATE PRIMARY N 2 |
| 71 | y-COORDINATE PRIMARY N 2 |
| 72 | TY PRIMARY N 2 |
| 73 | x-COORDINATE PRIMARY N 3 |
| 74 | y-COORDINATE PRIMARY N 3 |
| 75 | TY PRIMARY N 3 |
| 76 | x-COORDINATE PRIMARY N 4 |
| 77 | y-COORDINATE PRIMARY N 4 |
| 78 | TY PRIMARY N 4 |
| 79 | x-COORDINATE PRIMARY N 5 |
| 80 | y-COORDINATE PRIMARY N 5 |
| 81 | TY PRIMARY N 5 |
| 82 | NUMBER OF PRIMARIES |
| 128 | COLOR TEMPERATURE Tc COOLEST |
| 129 | COLOR TEMPERATURE Tc PHYSICAL COOLEST |
| 130 | COLOR TEMPERATURE Tc WARMEST |
| 131 | COLOR TEMPERATURE Tc PHYSICAL WARMEST |
| 192 | TEMPORARY x-COORDINATE |
| 193 | TEMPORARY y-COORDINATE |
| 194 | TEMPORARY COLOR TEMPERATURE Tc |
| 195 | TEMPORARY PRIMARY N DIMLEVEL 0 |
| 196 | TEMPORARY PRIMARY N DIMLEVEL 1 |
| 197 | TEMPORARY PRIMARY N DIMLEVEL 2 |
| 198 | TEMPORARY PRIMARY N DIMLEVEL 3 |
| 199 | TEMPORARY PRIMARY N DIMLEVEL 4 |
| 200 | TEMPORARY PRIMARY N DIMLEVEL 5 |
| 201 | TEMPORARY RED DIMLEVEL |
| 202 | TEMPORARY GREEN DIMLEVEL |
| 203 | TEMPORARY BLUE DIMLEVEL |
| 204 | TEMPORARY WHITE DIMLEVEL |
| 205 | TEMPORARY AMBER DIMLEVEL |
| 206 | TEMPORARY FREECOLOR DIMLEVEL |
| 207 | TEMPORARY RGBWAF CONTROL |
| 208 | TEMPORARY COLOR TYPE |
| 224 | REPORT x-COORDINATE |
| 225 | REPORT y-COORDINATE |
| 226 | REPORT COLOR TEMPERATURE Tc |
| 227 | REPORT PRIMARY N DIMLEVEL 0 |
| 228 | REPORT PRIMARY N DIMLEVEL 1 |
| 229 | REPORT PRIMARY N DIMLEVEL 2 |
| 230 | REPORT PRIMARY N DIMLEVEL 3 |
| 231 | REPORT PRIMARY N DIMLEVEL 4 |
| 232 | REPORT PRIMARY N DIMLEVEL 5 |
| 233 | REPORT RED DIMLEVEL |
| 234 | REPORT GREEN DIMLEVEL |
| 235 | REPORT BLUE DIMLEVEL |
| 236 | REPORT WHITE DIMLEVEL |
| 237 | REPORT AMBER DIMLEVEL |
| 238 | REPORT FREECOLOR DIMLEVEL |
| 239 | REPORT RGBWAF CONTROL |
| 240 | REPORT COLOR TYPE |

Responses that concern an active color representation are valid only if the color representation of the requested color value is active (see [FB\_DALIV2QueryColorStatus()](ms-xhelp:///?Id=beckhoff-ed62-4911-ad94-6cfea37f52ce)) or if the control gear is capable or reconverting the demanded color value from the active color representation to a color value of another color representation.

The reply must be 255 (MASK) if the control gear does not know the coordinates or if the primary color is not present.

The function block changes the DTR (data transfer registers) and DTR1 for all DALI control gears of the DALI line.

The function block supports the following color representations:

* xy coordinates
* Color temperature Tc
* Primary (color) N
* RGBWAF

|  |  |
| --- | --- |
| 60087944 | This command belongs to the application-related expansion commands for lamps for the color/color temperature control with DALI interface. They function only if they are preceded by the *Enable Device Type 8* command, which can be sent with the [FB\_DALIV2EnableDeviceType()](ms-xhelp:///?Id=beckhoff-e277-46a4-85ba-43a8cbcb1cb1) function block. The *Enable Device Type 8* command is internally placed automatically before all application-related expansion commands for lamps for the color/color temperature control with DALI interface. |

## VAR\_INPUT

```
bStart           : BOOL;  
nAddr            : BYTE;  
eAddrType        : E_DALIV2AddrType := eDALIV2AddrTypeShort;  
eCommandPriority : E_DALIV2CommandPriority := eDALIV2CommandPriorityMiddle;  
nParameter       : BYTE;
```

**bStart:** The function block is activated by a positive edge at this input.

**nAddr:** The address of a participating device or of a group.

**eAddrType:** Short address, group address or broadcast (see [E\_DALIV2AddrType](ms-xhelp:///?Id=beckhoff-d59c-42a4-9d77-6cc67c0d1971)).

**eCommandPriority:** Priority (high, medium or low) with which the command is processed by the library (see [E\_DALIV2CommandPriority](ms-xhelp:///?Id=beckhoff-9fcc-400f-b6a8-66e61c15362f)).

**nParameter:** color value to be read out (see table above).

## VAR\_OUTPUT

```
bBusy    : BOOL;  
bError   : BOOL;  
nErrorId : UDINT;  
nValue   : UINT;
```

**bBusy:** When the function block is activated the output is set, and it remains active until execution of the command has been completed.

**bError:** This output is switched to TRUE as soon as an error occurs during the execution of a command. The command-specific error code is contained in *nErrorId*. Is reset to FALSE by the execution of a command at the inputs.

**nErrorId:** Contains the command-specific error code of the most recently executed command. Is reset to 0 by the execution of a command at the inputs. (See [error codes](ms-xhelp:///?Id=beckhoff-f739-41c2-8ff6-b502954dc54f))

**nValue:** contains the value read out.

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
