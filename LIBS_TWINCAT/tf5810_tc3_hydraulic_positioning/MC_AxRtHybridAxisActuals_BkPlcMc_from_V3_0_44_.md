# MC_AxRtHybridAxisActuals_BkPlcMc (from V3.0.44)

## Library
tf5810_tc3_hydraulic_positioning

## Category
Motion Control

1. [TwinCAT PLC Hydraulics](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
2. [PLCopen Motion Control](ms-xhelp:///?Id=beckhoff-1ded-451e-88ec-a82873484e92)
3. [System](ms-xhelp:///?Id=beckhoff-cf25-4865-b897-b1877bc8684d)
4. [Encoder](ms-xhelp:///?Id=beckhoff-f3c4-4c4f-b160-19fe406dfb7c)
5. MC\_AxRtHybridAxisActuals\_BkPlcMc (from V3.0.44)

# MC\_AxRtHybridAxisActuals\_BkPlcMc (from V3.0.44)

![36667404](/tf5810_tc3_hydraulic_positioning/1033/Images/gif/9007205226899979__Web.gif)

The function block determines the essential actual values of a servo-electric/hydraulic hybrid axis.

```
                                                                                                        VAR_IN_OUT  
 Axis:                AXIS_REF_BkPlcMc;  
END_VAR  
VAR_INPUT  
    stSystem_PrsIn:        ST_TcPlcInputAnalog;  
    stAside_PrsIn:        ST_TcPlcInputAnalog;  
    stBside_PrsIn:        ST_TcPlcInputAnalog;   
  
    nTorqueFeedback:        INT;   
    udiMotorEnc_Count:    UDINT;   
  
    bUpdateActForce:        ST_ BOOL;   
  
    bPumpSwitch_Ext:        BOOL;   
    bAreaSwitch_Ext:        BOOL;   
VAR_OUTPUT  
    Error:                BOOL;  
    ErrorId:            BOOL;  
END_VAR
```

**Axis:** Here, the address of a variable of type [AxisRef\_BkPlcMc](ms-xhelp:///?Id=beckhoff-002b-4aba-81ea-1693fb03013c) should be transferred.

**bAreaSwitch\_Ext:** This signal notifies the function block that area switching of the axis is active.

**bPumpSwitch\_Ext:** This signal notifies the function block that pump switching of the axis is active.

**bUpdateActForce:** With this signal, the function block calculates the current actual force of the axis and updates it in stAxRtData.fActForce.

**Error:** The occurrence of an error is indicated here.

**ErrorId:** An encoded indication of the cause of the error is provided here.

**nTorqueFeedback:** The torque feedback signal of the drive is to be transferred here.

**stAside\_PrsIn:** If a pressure sensor is present on the positive area of the cylinder, the input variables of the terminal are transferred here.

**stBside\_PrsIn:** If a pressure sensor is present on the negative area of the cylinder, the input variables of the terminal are transferred here.

**stSystem\_PrsIn:** If a pressure sensor is present at the pressurized reservoir, the input variables of the terminal are transferred here.

**udiMotorEnc\_Count:** The counter value of the motor encoder must be transferred here.

## Behavior of the function block

If the axis is identified as 'hybrid', the function block performs the following steps.

* If a permissible encoder type for the motor encoder is specified for the axis, the function block determines the current actual angle from **udiMotorEnc\_Count**. Otherwise, the axis is set to a error state and the angle is set to 0.0°.
* The modulo actual angle is updated with the set number of pump cavities.
* The actual pump speed is determined.
* The pump torque is determined.
* If a scaling pressure is set for the system pressure and the connection monitoring in **stSystem\_PrsIn** does not indicate a problem, the input value is converted to a pressure and updated in stAxRtData.fSupplyPressure of the axis.
* If a scaling pressure is set for the pressure on the positive side and the connection monitoring in **stAside\_PrsIn** does not indicate a problem, the input value is converted to a pressure and updated in stAxRtData.fActPressureA of the axis.
* If a scaling pressure is set for the pressure on the negative side and the connection monitoring in **stBside\_PrsIn** does not indicate a problem, the input value is converted to a pressure and updated in stAxRtData.fActPressureB of the axis.
* If TRUE is passed in **bUpdateActForce**, the function block stAxRtData.fActForce updates the axis, using the currently effective areas.
* If an edge is detected at one of the switch signals (**bAreaSwitch\_Ext**, **bPumpSwitch\_Ext**), the function block initiates a ramp for changing the feed constant and the maximum speed.

Irrespective of whether the axis is identified as 'hybrid', this function block calls a local instance of [MC\_AxRtEncoder\_BkPlcMc()](ms-xhelp:///?Id=beckhoff-695e-4050-b1c6-c96353e7c191) for the axis.

|  |  |
| --- | --- |
| 61571180 | If no function block of this type is called for a servo-electric/hydraulic axis, changeovers are not handled correctly. This could lead to unexpected behavior of the axis. In this case, the axis is set to the error state and a message is output. |

[TF5810 | TwinCAT 3 Hydraulic Positioning](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
