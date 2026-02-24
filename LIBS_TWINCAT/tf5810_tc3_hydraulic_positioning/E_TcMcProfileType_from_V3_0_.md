# E_TcMcProfileType (from V3.0)

## Library
tf5810_tc3_hydraulic_positioning

## Category
Motion Control

1. [TwinCAT PLC Hydraulics](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
2. [PLCopen Motion Control](ms-xhelp:///?Id=beckhoff-1ded-451e-88ec-a82873484e92)
3. [Data types](ms-xhelp:///?Id=beckhoff-25bd-4475-8df7-6d29ea7ab5ff)
4. E\_TcMcProfileType (from V3.0)

# E\_TcMcProfileType (from V3.0)

The constants listed here are used to identify the rules used to generate the control value for an axis.

```
                                TYPE E_TcMcProfileType :  
(  
(*  
    The sequence below must not be changed!  
    New types have to be added at the end.  
    In case a type becomes obsolete it has to be replaced by a dummy  
    to ensure the numerical meaning of the other codes.  
*)  
(*  
    Die bestehende Reihenfolge darf nicht veraendert werden.  
    Neue Typen muessen am Ende eingefuegt werden.  
    Wenn ein Typ wegfallen sollte, muss er durch einen Dummy  
    ersetzt werden, um die numerische Zuordnung zu garantieren.  
*)  
iTcMc_ProfileConstAcc,  
iTcMc_ProfileTimePosCtrl,  
iTcMc_ProfileCosine,  
iTcMc_ProfileCtrlBased,  
iTcMc_ProfileTimeRamp,  
iTcMc_ProfileJerkBased,  
iTcMc_ProfileBufferedJerk,  
iTcMc_ProfileSwitchedVelo,  
iTcMc_Profile_TestOnly:=100  
);  
END_TYPE
```

**iTcMc\_ProfileConstAcc**: Only present for compatibility reasons; has been replaced by **iTcMc\_ProfileCtrlBased**.

**iTcMc\_ProfileTimePosCtrl:** Only present for compatibility reasons; no longer supported.

**iTcMc\_ProfileCosine:** Only present for compatibility reasons; no longer supported.

**iTcMc\_ProfileCtrlBased**: The control value for the drive is assembled from sections of constant acceleration and deceleration. Time (acceleration, change of velocity, stop) and distance (positioning) function as controlling values.

|  |  |
| --- | --- |
| 26731201 | This generator type can optionally operate in purely time-controlled mode with continuously closed position controller. |

**iTcMc\_ProfileTimeRamp**: The control value for the drive is generated with time-controlled ramps for accelerations and decelerations. The controlling parameters are time (acceleration, velocity change, stop) and path (braking, stopping).

|  |  |
| --- | --- |
| 39254219 | This generator type is intended for axes, which only have digital cams instead of an encoder.olgen |

**iTcMc\_ProfileJerkBased:** The control value for the drive is assembled from sections of constant acceleration and deceleration. The deceleration is reduced with limited jerk towards the target. Optionally, the acceleration can be increased with limited jerk. Time (acceleration, change of velocity, stop) and distance (positioning) function as controlling values.

|  |  |
| --- | --- |
| 17743659 | Some functions are not supported by this generator type, or not fully. |

|  |  |
| --- | --- |
| 25475209 | This generator type can optionally operate in purely time-controlled mode with continuously closed position controller. |

**iTcMc\_ProfileBufferedJerk:** Reserved.

**iTcMc\_ProfileSwitchedVelo:** Reserved for sector-specific packet.

**iTcMc\_Profile\_TestOnly:** This type is only intended for internal testing of function block prototypes, which have not yet been released. It cannot be set via the PlcMcManager.

[TF5810 | TwinCAT 3 Hydraulic Positioning](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
