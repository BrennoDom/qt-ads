# TRIGGER_REF

## Library
tcplclib_tc3_drivemotioncontrol

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc3\_DriveMotionControl](ms-xhelp:///?Id=beckhoff-9642-4f70-a3aa-5117d509112d)
2. [Data types](ms-xhelp:///?Id=beckhoff-6026-4a24-928a-c60b12336bae)
3. [Touch probe](ms-xhelp:///?Id=beckhoff-b993-44ab-b2cf-970a8c13dec8)
4. TRIGGER\_REF

# TRIGGER\_REF

```
TYPE TRIGGER_REF :  
STRUCT  
    TouchProbe      : E_TouchProbe; (* probe unit definition *)  
    SignalSource    : E_SignalSource; (* optional physical signal source used by the probe unit *)  
    Edge            : E_SignalEdge; (* rising or falling signal edge *)  
    Mode            : E_TouchProbeMode; (* single shot or continuous monitoring *)  
    PlcEvent        : BOOL; (* PLC trigger signal input when TouchProbe signal source is set to 'PlcEvent' *)  
    ModuloPositions : BOOL; (* interpretation of FirstPosition, LastPosition and RecordedPosition as modulo positions when TRUE *)  
END_STRUCT  
END_TYPE
```

**TouchProbe**: Defines the latch unit (probe unit) within the encoder hardware used.

```
TYPE E_TouchProbe :  
(  
    TouchProbe1  := 1, (* 1st hardware probe unit *)  
    PlcEvent     := 10    (* simple PLC signal TRUE/FALSE *)  
);  
END_TYPE
```

**SignalSource**: Optionally defines the signal source, if it can be selected via the controller. In many cases the signal source is permanently configured in the drive and should then be set to the default value "SignalSource\_Default".

```
TYPE E_SignalSource :  
(  
    SignalSource_Default,          (* undefined or externally configured *)  
    SignalSource_ZeroPulse := 128, (* encoder zero pulse *)  
);  
END_TYPE
```

**Edge:** Defines whether the rising or falling edge of the trigger signal is evaluated.

```
TYPE E_SignalEdge :  
(  
    RisingEdge,  
    FallingEdge  
);  
END_TYPE
```

**Mode**: Specifies the operation mode of the latch unit. In single mode only the first edge is recorded.

```
TYPE E_TouchProbeMode :  
(  
    TOUCHPROBEMODE_SINGLE := 1  
);  
END_TYPE
```

**PlcEvent**: If the signal source "TouchProbe" is set to the type "PlcEvent", a rising edge on these variables triggers the recording of the current axis position. "PlcEvent" is not a real latch function, but depends on the cycle time.

**ModuloPositions**: If the variable "ModuloPositions" is FALSE, the axis position is interpreted in an absolute linear range from -∞ to +∞. The positions "FirstPosition", "LastPosition" and "RecordedPosition" of the function block [MC\_TouchProbe](ms-xhelp:///?Id=beckhoff-7b55-4ce7-b7ea-d057db5b17ae) are then also absolute.  
If "ModuloPositions" is TRUE, all positions are interpreted in modulo mode in the modulo range of the axis used (e.g. 0..359.9999). At the same time this means that a defined trigger window repeats itself cyclically.

[TwinCAT 3 | PLC Library: Tc3\_DriveMotionControl](ms-xhelp:///?Id=beckhoff-9642-4f70-a3aa-5117d509112d)
