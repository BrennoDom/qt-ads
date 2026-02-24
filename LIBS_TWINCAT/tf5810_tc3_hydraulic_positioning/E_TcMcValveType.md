# E_TcMcValveType

## Library
tf5810_tc3_hydraulic_positioning

## Category
Motion Control

1. [TwinCAT PLC Hydraulics](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
2. [PLCopen Motion Control](ms-xhelp:///?Id=beckhoff-1ded-451e-88ec-a82873484e92)
3. [Data types](ms-xhelp:///?Id=beckhoff-25bd-4475-8df7-6d29ea7ab5ff)
4. E\_TcMcValveType

# E\_TcMcValveType

The constants in this list are used to mark rules for automatically identifying characteristic curves of an axis.

```
                                TYPE E_TcMcValveType :  
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
iTcMc_ValveTypeDefault,  
iTcMc_ValveTypeAbrupt,   
iTcMc_ValveTypeDecomp,   
iTcMc_ValveTypeLinearP,   
iTcMc_ValveTypeLinearM,   
iTcMc_ValveTypeCopyToP,   
iTcMc_ValveTypeCopyToM  
);  
END_TYPE
```

**iTcMc\_ValveTypeDefault**: Standard method: Measurement in both directions of movement.

**iTcMc\_ValveTypeAbrupt**: This setting is provided on valves with an abrupt transition from the coverage area. This is only the case with very few valve variants, and without this setting it manifests itself through a very hard behavior, especially at the beginning of the automatic identification.

Note This setting should only be made in coordination with Hydraulic Support.

**iTcMc\_ValveTypeDecomp**: This setting is adapted to valves with pressure relief in the coverage area (h symbol).

**iTcMc\_ValveTypeLinearP**: With this setting, the identification is performed only in the negative direction. For the positive direction a linear characteristic curve is assumed, the endpoint of which is calculated from the maximum velocity in the negative direction using the set velocity ratio.

Note The velocity ratio is not determined automatically.

**iTcMc\_ValveTypeLinearM**: With this setting, the identification is carried out only in the positive direction. For the negative direction a linear characteristic curve is assumed, the endpoint of which is calculated from the maximum velocity in the positive direction using the set velocity ratio.

Note The velocity ratio is not determined automatically.

**iTcMc\_ValveTypeCopyToP**: With this setting, the identification is performed only in the negative direction. For the positive direction, the measuring points are calculated from the measuring points of the negative direction using the set velocity ratio.

Note The velocity ratio is not determined automatically.

**iTcMc\_ValveTypeCopyToM**: With this setting, the identification is carried out only in the positive direction. For the negative direction, the measuring points are calculated from the measuring points of the positive direction using the set velocity ratio.

Note The velocity ratio is not determined automatically.

[TF5810 | TwinCAT 3 Hydraulic Positioning](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
