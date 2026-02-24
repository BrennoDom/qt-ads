# MC_AxRtFinish_BkPlcMc (from V3.0)

## Library
tf5810_tc3_hydraulic_positioning

## Category
Motion Control

1. [TwinCAT PLC Hydraulics](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
2. [PLCopen Motion Control](ms-xhelp:///?Id=beckhoff-1ded-451e-88ec-a82873484e92)
3. [System](ms-xhelp:///?Id=beckhoff-cf25-4865-b897-b1877bc8684d)
4. [Runtime](ms-xhelp:///?Id=beckhoff-6898-463a-a8a2-80cf35a5250d)
5. MC\_AxRtFinish\_BkPlcMc (from V3.0)

# MC\_AxRtFinish\_BkPlcMc (from V3.0)

![12695920](/tf5810_tc3_hydraulic_positioning/1033/Images/gif/9007200854800395__Web.gif)

This function block adapts the control value that has been generated to the special features of the particular axis. An [MC\_AxRtFinishLinear\_BkPlcMc](ms-xhelp:///?Id=beckhoff-e15e-40cb-b1bb-32215a440336) function block should be used if a characteristic curve linearisation is required.

```
VAR_OUTPUT  
    Error:      BOOL;  
    ErrorID:    UDINT;  
END_VAR
```

```
VAR_INOUT  
    Axis:       Axis_Ref_BkPlcMc;  
END_VAR
```

**Error**: The occurrence of an error is indicated here.

**ErrorID**: An encoded indication of the cause of the error is provided here.

**Axis**: Here, the address of a variable of type [Axis\_Ref\_BkPlcMc](ms-xhelp:///?Id=beckhoff-002b-4aba-81ea-1693fb03013c) should be transferred.

## Behaviour of the function block

The function block investigates the axis interface that has been passed to it every time it is called. A number of problems can be detected and reported during this process:

* If one of the pointers has not been initialised the function block reacts with **Error** and with **ErrorID**:=dwTcHydErrCdPtrPlcMc or dwTcHydErrCdPtrMcPlc.

If these checks could be performed without problem, the control value for the axis is adapted according to the values in **Axis**.[ST\_TcHydAxParam](ms-xhelp:///?Id=beckhoff-12fe-4458-a931-b3c9fca583f2).

* The control value for the advance and the positional control reaction are combined to form the output control value.
* Area compensation is taken into account.
* Compensation is applied for a bend in the characteristic curve.
* The overlap compensation, the terminal control value and the offset compensation are included in the calculation.

If only the usual blocks (encoder, generator, finish, drive) for the axis are to be called, a block of type [MC\_AxStandardBody\_BkPlcMc](ms-xhelp:///?Id=beckhoff-1687-4c16-854c-a550eeaaa344) should be used for simplicity.

[TF5810 | TwinCAT 3 Hydraulic Positioning](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
