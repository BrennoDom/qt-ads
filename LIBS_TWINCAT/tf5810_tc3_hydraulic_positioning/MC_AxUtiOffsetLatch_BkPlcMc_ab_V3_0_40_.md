# MC_AxUtiOffsetLatch_BkPlcMc (ab V3.0.40)

## Library
tf5810_tc3_hydraulic_positioning

## Category
Motion Control

1. [TwinCAT PLC Hydraulics](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
2. [PLCopen Motion Control](ms-xhelp:///?Id=beckhoff-1ded-451e-88ec-a82873484e92)
3. [System](ms-xhelp:///?Id=beckhoff-cf25-4865-b897-b1877bc8684d)
4. [Utilities](ms-xhelp:///?Id=beckhoff-05d5-4e7a-847c-eea5a0277852)
5. MC\_AxUtiOffsetLatch\_BkPlcMc (ab V3.0.40)

# MC\_AxUtiOffsetLatch\_BkPlcMc (ab V3.0.40)

![14650458](/tf5810_tc3_hydraulic_positioning/1033/Images/gif/9007203480581387__Web.gif)

The function block updates the offset compensation.

```
VAR_INPUT  
     Execute:      BOOL;  
     OffsetLimit:  LREAL:=0.5;  
END_VAR
```

```
VAR_OUTPUT  
     Done:       BOOL;  
     Error:        BOOL;  
     ErrorId:      UDINT;  
     Latched:      BOOL;  
     Offset:       LREAL;  
END_VAR
```

```
VAR_IN_OUT  
     Axis:       AXIS_REF_BkPlcMc;  
END_VAR
```

**Execute**: A positive edge triggers the update.

**OffsetLimit**: [V] The maximum permissible value range for the offset compensation.

**Done**: A successful update is indicated here.

**Error**: This output indicates any problems that may have occurred.

**ErrorId**: In the event of an error, coded information about the type of problem is reported here.

**Latched**: This output signals that the update was successfully completed.

**Offset**: [V] This output reports the offset value. It is only accepted as a new compensation when **Done**.

## Behavior of the function block

With a positive edge at **Execute**, **Offset** is updated with the current output of the position controller.

Before accepting this value as compensation, the function block checks for several possible errors:

* The axis must have a controller enable and must not be in an active motion state or error state (Axis.stAxRtData.iCurrentStep=iTcHydStateIdle). (error code dwTcHydAdsErrBusy)
* The detected controller output must not be outside ±**OffsetLimit**. (error code dwTcHydAdsErrIllegalValue)

If one of the errors has occurred, **Error** is reported and **ErrorId** is assigned the specified error code. In this case, the compensation remains unchanged.

Otherwise, **offset** is applied as the new compensation value. Since from this point in time the part of the output value previously provided by the position controller is taken over by the compensation, the output of the controller must be canceled. The following steps are carried out once only:

* The set and current target positions are updated with the actual position.
* The position error (lag error) is set to zero.
* The position controller output is set to zero.
* The I component of the default position controller is wiped.
* If a position controller other than the default position controller is used, its I component must be deleted by the application.

All outputs are set to the idle state with a negative edge at **Execute**.

[TF5810 | TwinCAT 3 Hydraulic Positioning](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
