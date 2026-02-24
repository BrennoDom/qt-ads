# TRIGGER_REF

## Library
tcplclib_tc2_mc2

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_MC2](ms-xhelp:///?Id=beckhoff-63a7-4c0e-8569-314547c8cffc)
2. [Data types](ms-xhelp:///?Id=beckhoff-683b-4615-8584-914eb091e041)
3. [Touch probe](ms-xhelp:///?Id=beckhoff-cbed-493e-ab05-255e22e5dafd)
4. TRIGGER\_REF

# TRIGGER\_REF

```
TYPE TRIGGER_REF :  
STRUCT  
    EncoderID       : UDINT; (* 1..255 *)  
    TouchProbe      : E_TouchProbe; (* probe unit definition *)  
    SignalSource    : E_SignalSource; (* optional physical signal source used by the probe unit *)  
    Edge            : E_SignalEdge; (* rising or falling signal edge *)  
    Mode            : E_TouchProbeMode; (* single shot or continuous monitoring *)  
    PlcEvent        : BOOL; (* PLC trigger signal input when TouchProbe signal source is set to 'PlcEvent' *)  
    ModuloPositions : BOOL; (* interpretation of FirstPosition, LastPosition and RecordedPosition as modulo positions when TRUE *)  
END_STRUCT  
END_TYPE
```

**EncoderID**: The ID of an encoder is indicated in the TwinCAT System Manager.

**TouchProbe**: Defines the latch unit (probe unit) within the encoder hardware used.

```
TYPE E_TouchProbe :  
(  
    TouchProbe1 := 1, (* 1st hardware probe unit with Sercos, CanOpen, KL5xxx and others *)  
    TouchProbe2,      (* 2nd probe unit *)  
    TouchProbe3,      (* currently not available *)  
    TouchProbe4,      (* currently not available *)  
    PlcEvent := 10    (* simple PLC signal TRUE/FALSE *)  
);  
END_TYPE
```

**SignalSource**: Optionally defines the signal source, if it can be selected via the controller. In many cases the signal source is permanently configured in the drive and should then be set to the default value "SignalSource\_Default".

```
TYPE E_SignalSource :  
(  
    SignalSource_Default,    (* undefined or externally configured *)  
    SignalSource_Input1,     (* digital drive input 1 *)  
    SignalSource_Input2,     (* digital drive input 2 *)  
    SignalSource_Input3,     (* digital drive input 3 *)  
    SignalSource_Input4,     (* digital drive input 4 *)  
    SignalSource_ZeroPulse := 128, (* encoder zero pulse *)  
    SignalSource_DriveDefined (* defined by drive parameters - e. g. CAN object 0x60D0 *)  
);  
END_TYPE
```

**Edge:** Defines whether the positive or negative edge of the trigger signal is evaluated.

```
TYPE E_SignalEdge :  
(  
    RisingEdge,  
    FallingEdge  
);  
END_TYPE
```

**Mode**: Specifies the operation mode of the latch unit. In single mode only the first edge is recorded. In continuous mode each PLC cycle edge is signaled.

```
TYPE E_TouchProbeMode :  
(  
    TOUCHPROBEMODE_SINGLE_COMPATIBILITYMODE, (* for TwinCAT 2.10 and 2.11 before Build 2022 *)  
    TOUCHPROBEMODE_SINGLE, (* multi probe interface - from 2.11 Build 2022 *)  
    TOUCHPROBEMODE_CONTINOUS (* multi probe interface - from 2.11 Build 2022 *)  
);  
END_TYPE
```

**Note regarding Beckhoff drives:**

For the SINGLE or CONTINUOUS modes the probe unit must be configured as an "Extended Nc Probe Unit".

![101341](/tcplclib_tc2_mc2/1033/Images/png/9007199325103755__Web.png)

**PlcEvent**: If the signal source "TouchProbe" is set to the type "PlcEvent", a positive edge on these variables triggers the recording of the current axis position. "PlcEvent" is not a real latch function, but depends on the cycle time.

**ModuloPositions**: If the variable "ModuloPositions" is FALSE, the axis position is interpreted in an absolute linear range from -∞ to +∞. The positions "FirstPosition", "LastPosition" and "RecordedPosition" of the function block [MC\_TouchProbe](ms-xhelp:///?Id=beckhoff-cdf3-4593-9d50-fd29cc644812) are then also absolute.  
If "ModuloPositions" is TRUE, all positions are interpreted as modulo values in the modulo range of the axis used (e.g. 0..359.9999). At the same time this means that a defined trigger window repeats itself cyclically.

## Requirements

| Development environment | Target system type | PLC libraries to include |
| --- | --- | --- |
| TwinCAT v3.0.0 | PC or CX (x86 or x64) | Tc2\_MC2 |

[TwinCAT 3 | PLC Library: Tc2\_MC2](ms-xhelp:///?Id=beckhoff-63a7-4c0e-8569-314547c8cffc)
