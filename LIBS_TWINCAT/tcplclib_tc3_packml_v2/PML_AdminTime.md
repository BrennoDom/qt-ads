# PML_AdminTime

## Library
tcplclib_tc3_packml_v2

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc3\_PackML\_V2](ms-xhelp:///?Id=beckhoff-962e-4424-bd3f-3a66f7e32e10)
2. [Packaging Machine State](ms-xhelp:///?Id=beckhoff-bf11-4534-b5f5-a9e819d4a1bd)
3. [Function Blocks](ms-xhelp:///?Id=beckhoff-ee52-4b21-b081-24a6fe023487)
4. [General](ms-xhelp:///?Id=beckhoff-0b63-427b-93e8-5ba0760ccf9f)
5. PML\_AdminTime

# PML\_AdminTime

![66802302](/tcplclib_tc3_packml_v2/1033/Images/png/6301179787__Web.png)

This function block should be called cyclically and it then fills the following Admin-PackTags:

* *PlcDateTime*
* *AccTimeSinceReset*
* *ModeCurrentTime*[]
* *ModeCummulativeTime*[]
* *StateCurrentTime*[][]
* *StateCummulativeTime*[][]

The length of time for which the machine was in the different states is thus recorded. In the further process, this allows conclusions to be drawn about the machine efficiency. So that the times are calculated correctly, it is a prerequisite that the Status-PackTags *UnitCurrent* and *StateCurrent* have already been written meaningfully.

## Inputs

```
VAR_INPUT  
    bReset           : BOOL;  
    stOptions        : ST_AdminTimeOptions  
END_VAR
```

**bReset**: A signal at this input resets the recorded times.

**stOptions:** Additional options of the function block.

## Inputs/outputs

```
VAR_IN_OUT  
    stAdmin          : ST_PMLa;  
    stStatus         : ST_PMLs;  
END_VAR
```

**stAdmin**: Transfer of the Admin-PackTags

**stStatus**: Transfer of the Status-PackTags

## Requirements

| Development environment | Target system type | PLC libraries to include |
| --- | --- | --- |
| TwinCAT v3.1 Build 4018 and higher | PC (i386) | Tc3\_PackML\_V2 |

[TwinCAT 3 | PLC Library: Tc3\_PackML\_V2](ms-xhelp:///?Id=beckhoff-962e-4424-bd3f-3a66f7e32e10)
