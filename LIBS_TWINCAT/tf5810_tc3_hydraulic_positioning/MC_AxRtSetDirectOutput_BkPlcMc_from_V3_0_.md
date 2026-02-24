# MC_AxRtSetDirectOutput_BkPlcMc (from V3.0)

## Library
tf5810_tc3_hydraulic_positioning

## Category
Motion Control

1. [TwinCAT PLC Hydraulics](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
2. [PLCopen Motion Control](ms-xhelp:///?Id=beckhoff-1ded-451e-88ec-a82873484e92)
3. [System](ms-xhelp:///?Id=beckhoff-cf25-4865-b897-b1877bc8684d)
4. [Runtime](ms-xhelp:///?Id=beckhoff-6898-463a-a8a2-80cf35a5250d)
5. MC\_AxRtSetDirectOutput\_BkPlcMc (from V3.0)

# MC\_AxRtSetDirectOutput\_BkPlcMc (from V3.0)

![7492614](/tf5810_tc3_hydraulic_positioning/1033/Images/gif/9007200854812555__Web.gif)

The function block issues a control value, regardless of a profile generation.

```
VAR_INPUT  
     Enable:           BOOL;  
     OutValue:         LREAL;  
     RampTime:         LREAL;  
END_VAR
```

```
VAR_OUPUT  
     Busy:             BOOL;  
     CommandAborted:   BOOL;  
     Error:            BOOL;  
     ErrorID:          UDINT;  
END_VAR
```

```
VAR_INOUT  
     Axis:             Axis_Ref_BkPlcMc;  
END_VAR
```

**Enable**: **TRUE** at this input activates the output.

**OutValue**: The control value to be output should be transferred here.

**RampTime**: [s] Here, the time should be specified in which the control value would reach full scale.

**Busy**: Indicates that a command is being processed.

**CommandAborted**: This indicates abortion of the function.

**Error**: The occurrence of an error is indicated here.

**ErrorID**: An encoded indication of the cause of the error is provided here.

**Axis**: Here, the address of a variable of type [Axis\_Ref\_BkPlcMc](ms-xhelp:///?Id=beckhoff-002b-4aba-81ea-1693fb03013c) should be transferred.

## Behavior of the function block

A positive edge at **Enable** activates the function. The axis is put into states [McState\_Continousmotion](ms-xhelp:///?Id=beckhoff-ec30-4c5a-b456-5a14920f0c0b) and [iTcHydStateExtGenerated](ms-xhelp:///?Id=beckhoff-16b4-460f-9810-4e6a9be14841), and **Busy** becomes **TRUE**. The control value of the axis is updated with OutValue. The rate of change is specified through **RampTime**.

If **Enable** is set to **FALSE,** the control value is brought to 0.0 using **RampTime**, and the function is terminated. Only then does **Busy** become **FALSE**.

If another function block takes over control of the axis while the **MC\_AxRtSetDirectOutput\_BkPlcMc** is active, the function block terminates its function and indicates **CommandAborted**.

[TF5810 | TwinCAT 3 Hydraulic Positioning](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
