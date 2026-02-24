# MC_AxRtFinishLinear_BkPlcMc (from V3.0.16)

## Library
tf5810_tc3_hydraulic_positioning

## Category
Motion Control

1. [TwinCAT PLC Hydraulics](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
2. [PLCopen Motion Control](ms-xhelp:///?Id=beckhoff-1ded-451e-88ec-a82873484e92)
3. [System](ms-xhelp:///?Id=beckhoff-cf25-4865-b897-b1877bc8684d)
4. [Runtime](ms-xhelp:///?Id=beckhoff-6898-463a-a8a2-80cf35a5250d)
5. MC\_AxRtFinishLinear\_BkPlcMc (from V3.0.16)

# MC\_AxRtFinishLinear\_BkPlcMc (from V3.0.16)

![47154420](/tf5810_tc3_hydraulic_positioning/1033/Images/gif/9007200854802827__Web.gif)

The function block deals with the adjustment of the generated control value to the special features of the axis, taking into account a characteristic curve.

```
VAR_INPUT  
    EnableLinearisation:   BOOL;  
    ValveTable:            POINTER TO LREAL:=0;  
    ValveTableLowIdx:      INT:=0;  
    ValveTableHighIdx:     INT:=0;  
END_VAR
```

```
VAR_OUTPUT  
    Error:                 BOOL;  
    ErrorID:               UDINT;  
END_VAR
```

```
VAR_INOUT  
    Axis:                  Axis_Ref_BkPlcMc;  
END_VAR
```

**EnableLinearisation**: TRUE at this input activates the linearisation.

**ValveTable**: The address of the linearisation table should be transferred here. If possible, this should be the ValveCharacteristicTable of an [ST\_TcMcAutoIdent](ms-xhelp:///?Id=beckhoff-d8cd-4957-b2b8-b8cd53f4d9b3) linked to the axis.

**ValveTableLowIdx**: The index of the first point in the linearisation table.

**ValveTableHighIdx**: The index of the last point in the linearisation table. If possible, this should be the ValveCharacteristicTblCount of an [ST\_TcMcAutoIdent](ms-xhelp:///?Id=beckhoff-d8cd-4957-b2b8-b8cd53f4d9b3) linked to the axis.

**Error**: The occurrence of an error is indicated here.

**ErrorID**: An encoded indication of the cause of the error is provided here.

**Axis**: Here, the address of a variable of type [Axis\_Ref\_BkPlcMc](ms-xhelp:///?Id=beckhoff-002b-4aba-81ea-1693fb03013c) should be transferred.

## Behaviour of the function block

The function block investigates the axis interface that has been passed to it every time it is called. A number of problems may be detected:

* **EnableLinearisation** is FALSE.
* The pointer **ValveTable** is not initialised.
* **ValveTableLowIdx** is less than 0.
* **ValveTableHighIdx** is less than or equal to **ValveTableLowIdx**.

In these cases an [MC\_AxRtFinish\_BkPlcMc](ms-xhelp:///?Id=beckhoff-0bc7-4c7a-b544-8f2d601813cd) function block is called internally, and its outputs are passed on. Otherwise the table linearisation for the axis is performed. Note the following special characteristics:

* The parameter for compensating the directionality (area ratio, gravity etc.) of the axis velocity has no effect. This compensation should be taken into account in the table.
* The parameters for compensating a kink in the characteristic curve have no effect. This compensation should be taken into account in the table.
* The parameter for the overlap compensation has no effect. This compensation should be taken into account in the table.
* A pressing power output or an offset compensation cannot be realized through a linearization. The corresponding parameters are active.

**Sample**: Display of a linearisation in the PlcMcManager:

![21736599](/tf5810_tc3_hydraulic_positioning/1033/Images/gif/1600064267__Web.gif)

The linearisation tables can be loaded from a text file with an MC\_AxTableFromAsciFile\_BkPlcMc or MC\_AxTableFromBinFile\_BkPlcMc function block.

A sample program can be found in the [SampleList](ms-xhelp:///?Id=beckhoff-6af5-4f42-8491-7a510b7dd9b7) of the [Knowledge Base](ms-xhelp:///?Id=beckhoff-873e-46cd-925a-b9a96eea638e). Demonstrates automatic determination of a characteristic curve with an [MC\_AxUtiAutoIdent\_BkPlcMc](ms-xhelp:///?Id=beckhoff-6e26-4519-a6b1-d0581db76054) function block.

[TF5810 | TwinCAT 3 Hydraulic Positioning](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
