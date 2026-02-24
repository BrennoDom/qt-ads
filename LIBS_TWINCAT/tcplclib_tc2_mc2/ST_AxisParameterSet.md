# ST_AxisParameterSet

## Library
tcplclib_tc2_mc2

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_MC2](ms-xhelp:///?Id=beckhoff-63a7-4c0e-8569-314547c8cffc)
2. [Data types](ms-xhelp:///?Id=beckhoff-683b-4615-8584-914eb091e041)
3. [Status and parameter](ms-xhelp:///?Id=beckhoff-a949-4038-af4c-900da2b41d28)
4. ST\_AxisParameterSet

# ST\_AxisParameterSet

This data type contains the entire parameter data set of an axis that can be read with the function block [MC\_ReadParameterSet](ms-xhelp:///?Id=beckhoff-e668-4cb9-b75c-028db01e438b).

Individual parameters that can be changed at runtime can be written with [MC\_WriteParameter](ms-xhelp:///?Id=beckhoff-ef67-4902-b8d1-6b471791eec2). It is not possible to write back the parameter dataset as a whole.

The individual parameters are described in the NC ADS documentation.

```
TYPE ST_AxisParameterSet :  
STRUCT  
    (* AXIS: *)  
    AxisId                      : DWORD;        (* 0x00000001 *)  
    sAxisName                   : STRING(31);   (* 0x00000002 *)  
    nAxisType                   : DWORD;        (* 0x00000003 *)  
    bEnablePositionAreaControl  : WORD;         (* 0x0000000F *)  
    fPositionAreaControlRange   : LREAL;        (* 0x00000010 *)  
    bEnableMotionControl        : WORD;         (* 0x00000011 *)  
    fMotionControlTime          : LREAL;        (* 0x00000012 *)  
    bEnableLoop                 : WORD;         (* 0x00000013 *)  
    fLoopDistance               : LREAL;        (* 0x00000014 *)  
    bEnableTargetPosControl     : WORD;         (* 0x00000015 *)  
    fTargetPosControlRange      : LREAL;        (* 0x00000016 *)  
    fTargetPosControlTime       : LREAL;        (* 0x00000017 *)  
    fVeloMaximum                : LREAL;        (* 0x00000027 *)  
    fMotionControlRange         : LREAL;        (* 0x00000028 *)  
    bEnablePEHTimeControl       : WORD;         (* 0x00000029 *)  
    fPEHControlTime             : LREAL;        (* 0x0000002A *)  
    bEnableBacklashCompensation : WORD;         (* 0x0000002B *)  
    fBacklash                   : LREAL;        (* 0x0000002C *)  
    sAmsNetId                   : T_AmsNetId;   (* 0x00000031 *)  
    nPort                       : WORD;         (* 0x00000031 *)  
    nChnNo                      : WORD;         (* 0x00000031 *)  
    fAcceleration               : LREAL;        (* 0x00000101 *)  
    fDeceleration               : LREAL;        (* 0x00000102 *)  
    fJerk                       : LREAL;        (* 0x00000103 *)  
  
    (* ENCODER: *)  
    nEncId                      : DWORD;        (* 0x00010001 *)  
    sEncName                    : STRING(31);   (* 0x00010002 *)  
    nEncType                    : DWORD;        (* 0x00010003 *)  
    fEncScaleFactor             : LREAL;        (* 0x00010006 *)  
    fEncOffset                  : LREAL;        (* 0x00010007 *)  
    bEncIsInverse               : WORD;         (* 0x00010008 *)  
    fEncModuloFactor            : LREAL;        (* 0x00010009 *)  
    nEncMode                    : DWORD;        (* 0x0001000A *)  
    bEncEnableSoftEndMinControl : WORD;         (* 0x0001000B *)  
    bEncEnableSoftEndMaxControl : WORD;         (* 0x0001000C *)  
    fEncSoftEndMin              : LREAL;        (* 0x0001000D *)  
    fEncSoftEndMax              : LREAL;        (* 0x0001000E *)  
    nEncMaxIncrement            : DWORD;        (* 0x00010015 *)  
    bEncEnablePosCorrection     : WORD;         (* 0x00010016 *)  
    fEncPosCorrectionFilterTime : LREAL;        (* 0x00010017 *)  
  
    (* CONTROLLER: *)  
    nCtrlId                     : DWORD;        (* 0x00020001 *)  
    sCtrlName                   : STRING(31);   (* 0x00020002 *)  
    nCtrlType                   : DWORD;        (* 0x00020003 *)  
    bCtrlEnablePosDiffControl   : WORD;         (* 0x00020010 *)  
    bCtrlEnableVeloDiffControl  : WORD;         (* 0x00020011 *)  
    fCtrlPosDiffMax             : LREAL;        (* 0x00020012 *)  
    fCtrlPosDiffMaxTime         : LREAL;        (* 0x00020013 *)  
    fCtrlPosKp                  : LREAL;        (* 0x00020102 *)  
    fCtrlPosTn                  : LREAL;        (* 0x00020103 *)  
    fCtrlPosTv                  : LREAL;        (* 0x00020104 *)  
    fCtrlPosTd                  : LREAL;        (* 0x00020105 *)  
    fCtrlPosExtKp               : LREAL;        (* 0x00020106 *)  
    fCtrlPosExtVelo             : LREAL;        (* 0x00020107 *)  
    fCtrlAccKa                  : LREAL;        (* 0x00020108 *)  
  
    (* DRIVE: *)  
    nDriveId                    : DWORD;        (* 0x00030001 *)  
    sDriveName                  : STRING(31);   (* 0x00030002 *)  
    nDriveType                  : DWORD;        (* 0x00030003 *)  
    bDriveIsInverse             : WORD;         (* 0x00030006 *)  
    fDriveVeloReferenz          : LREAL;        (* 0x00030101 *)  
    fDriveOutputReferenz        : LREAL;        (* 0x00030102 *)  
  
    (* fill up *)  
    arrReserved : ARRAY[455..512] OF BYTE; (* fill up to 512 bytes *)  
END_STRUCT  
END_TYPE
```

## Requirements

| Development environment | Target system type | PLC libraries to include |
| --- | --- | --- |
| TwinCAT v3.0.0 | PC or CX (x86 or x64) | Tc2\_MC2 |

[TwinCAT 3 | PLC Library: Tc2\_MC2](ms-xhelp:///?Id=beckhoff-63a7-4c0e-8569-314547c8cffc)
