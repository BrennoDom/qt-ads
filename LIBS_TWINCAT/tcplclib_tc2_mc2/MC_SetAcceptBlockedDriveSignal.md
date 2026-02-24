# MC_SetAcceptBlockedDriveSignal

## Library
tcplclib_tc2_mc2

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_MC2](ms-xhelp:///?Id=beckhoff-63a7-4c0e-8569-314547c8cffc)
2. [Organization blocks](ms-xhelp:///?Id=beckhoff-7981-40e5-8240-8b7aa05d05b3)
3. [Special extensions](ms-xhelp:///?Id=beckhoff-8c7a-4985-bc2a-8740f4381d5f)
4. MC\_SetAcceptBlockedDriveSignal

# MC\_SetAcceptBlockedDriveSignal

![45732164](/tcplclib_tc2_mc2/1033/Images/png/2240510859__Web.png)

There are situations in which a drive no longer follows the set NC values, e.g. if an axis reaches a limit switch. The NC interprets such a situation as an error, and the drive is stopped. In some cases the user may want to provoke such a situation deliberately, e.g. in order to move to a limit switch for a reference run. The function MC\_SetAcceptBlockedDriveSignal can be used to temporarily prevent the NC axis generating an error in situations where the drive no longer follows the set NC values.

**Notes**:

* See also bit 8 of the ControlDWord in AXIS\_REF.
* A SERCOS/SoE drive reports "Drive follows the command values" via status bit 3 of drive status word S-0-0135.
* A CANopen/CoE drive reports "Drive follows the command values" via status bit 12 of object 6041h.

## FUNCTION MC\_SetAcceptBlockedDriveSignal: BOOL

## Inputs

```
VAR_INPUT  
    Enable :  BOOL;  
END_VAR
```

**Enable:** NC controller enable for the axis.

## Inputs/outputs

```
VAR_IN_OUT  
    Axis : AXIS_REF;  
END_VAR
```

**Axis:** Axis data structure that unambiguously addresses an axis in the system. Among other parameters it contains the current axis status, including position, velocity or error state. (Type: [AXIS\_REF](ms-xhelp:///?Id=beckhoff-7cdc-4b2f-b455-b38811ddad01))

## Requirements

| Development environment | Target system type | PLC libraries to include |
| --- | --- | --- |
| TwinCAT v3.0.0 | PC or CX (x86 or x64) | Tc2\_MC2 |

[TwinCAT 3 | PLC Library: Tc2\_MC2](ms-xhelp:///?Id=beckhoff-63a7-4c0e-8569-314547c8cffc)
