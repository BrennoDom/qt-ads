# MC_AxCtrlPressureFF_BkPlcMc

## Library
tf5810_tc3_hydraulic_positioning

## Category
Motion Control

1. [TwinCAT PLC Hydraulics](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
2. [PLCopen Motion Control](ms-xhelp:///?Id=beckhoff-1ded-451e-88ec-a82873484e92)
3. [System](ms-xhelp:///?Id=beckhoff-cf25-4865-b897-b1877bc8684d)
4. [Controller](ms-xhelp:///?Id=beckhoff-d178-4221-a79e-98bd3d3716b1)
5. MC\_AxCtrlPressureFF\_BkPlcMc

# MC\_AxCtrlPressureFF\_BkPlcMc

![5847780](/tf5810_tc3_hydraulic_positioning/1033/Images/gif/9074616843__Web.gif)

The function block regulates the pressure acting on an axis in such a way that the desired default value **SetPoint** is set up and maintained in **Actual**. Alternatively, forces can also be used as actual values and setpoints.

In most cases the actual pressure can be logged with function blocks of type [MC\_AxRtReadPressureSingle\_BkPlcMc](ms-xhelp:///?Id=beckhoff-6b58-42dd-9f28-b93f3336f1ca) or [MC\_AxRtReadPressureDiff\_BkPlcMc](ms-xhelp:///?Id=beckhoff-56dc-4d1a-b49b-0b7b2af8cf24). Function blocks of type [MC\_AxRtReadForceSingle\_BkPlcMc](ms-xhelp:///?Id=beckhoff-9b6c-4ec2-b19e-edaa3299193e) or [MC\_AxRtReadForceDiff\_BkPlcMc](ms-xhelp:///?Id=beckhoff-1946-4575-bcf0-63dbcf7a8ec1) are suitable for an actual force.

```
VAR_INPUT  
    Enable:       BOOL:=FALSE;   
    Enable_P:     BOOL:=TRUE;   
    Enable_I:     BOOL:=TRUE;   
    Enable_D:     BOOL:=TRUE;  
    Reset:        BOOL:=TRUE;   
    Setpoint:     LREAL:=0.0;   
    Actual:       LREAL:=0.0;   
    FeedVelocity: LREAL:=0.0;  
    FeedCharge:   LREAL:=0.0;  
    pParam:       POINTER TO ST_TcPctrlParam;   
END_VAR
```

```
VAR_INOUT  
    Axis:         Axis_Ref_BkPlcMc;  
END_VAR
```

```
VAR_OUTPUT  
    Error:        BOOL;  
    ErrorID:      UDINT;  
    InWindup:     UDINT;   
    Deviation:    LREAL;   
    Proportional: LREAL;   
    Integrator:   LREAL;  
    Differential: LREAL;  
    Response:     LREAL;  
END_VAR
```

**Enable**: TRUE at this input activates the controller.

**Enable\_P**: A TRUE at this input activates the proportional component of the controller.

**Enable\_I**: A TRUE at this input activates the integrator of the controller if the proportional component is active.

**Enable\_D**: A TRUE at this input activates the differential component of the controller if the proportional component is active.

**Reset**: TRUE at this input resets the controller. The memory of the I component is cleared.

**Setpoint:** The setpoint of the controller.

**Actual:** The actual value of the controller.

**FeedVelocity:** The default value for a lower-level pre-control.

**FeedCharge:** An instantaneously effective and permanent change in the integral component.

**pParam:** The address of a structure with the controller parameters. If zero is transferred here, the controller uses the parameters in stAxParams.stPctrl.

**Error:** A TRUE here signals an error.

**ErrorID:** A numerically encoded error indication.

**InWindup:** A TRUE here signals that the integrator is limited by the WindupLimit.

**Deviation:** The current controller deviation.

**Proportional:** The current proportional component.

**Integrator:** The current integral component.

**Differential:** The current differential component.

**Response:** The output of the controller.

![52630025](/tf5810_tc3_hydraulic_positioning/1033/Images/gif/9075174027__Web.gif)

The controller has a complete PID core, the individual components of which can be switched on and off via Boolean inputs regardless of their parameters.

In addition, a pre-control input is available, which makes it easier to adapt the control against a moving object to the velocity of the object. If necessary, the component of the integrator can be instantaneously changed with the input FeedCharge.

[TF5810 | TwinCAT 3 Hydraulic Positioning](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
