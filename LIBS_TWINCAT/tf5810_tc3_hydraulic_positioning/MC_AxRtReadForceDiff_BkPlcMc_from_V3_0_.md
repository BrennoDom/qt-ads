# MC_AxRtReadForceDiff_BkPlcMc (from V3.0)

## Library
tf5810_tc3_hydraulic_positioning

## Category
Motion Control

1. [TwinCAT PLC Hydraulics](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
2. [PLCopen Motion Control](ms-xhelp:///?Id=beckhoff-1ded-451e-88ec-a82873484e92)
3. [System](ms-xhelp:///?Id=beckhoff-cf25-4865-b897-b1877bc8684d)
4. [Encoder](ms-xhelp:///?Id=beckhoff-f3c4-4c4f-b160-19fe406dfb7c)
5. MC\_AxRtReadForceDiff\_BkPlcMc (from V3.0)

# MC\_AxRtReadForceDiff\_BkPlcMc (from V3.0)

![41816140](/tf5810_tc3_hydraulic_positioning/1033/Images/gif/4225803915__Web.gif)

The function block handles determination of the actual force of the axis from the input data of two analog input terminals. The actual pressure on the A- and B-sides is converted to the force acting on the load, taking into account the areas and the sliding friction.

If only one input signal is available, a function block of type [MC\_AxRtReadForceSingle\_BkPlcMc](ms-xhelp:///?Id=beckhoff-9b6c-4ec2-b19e-edaa3299193e) should be used. If the actual pressure is to be determined, a function block of type [MC\_AxRtReadPressureDiff\_BkPlcMc](ms-xhelp:///?Id=beckhoff-56dc-4d1a-b49b-0b7b2af8cf24) should be used.

```
VAR_INPUT  
    AdcValueA:      INT:=0;  
    AdcValueB:      INT:=0;  
    ScaleFactorA:   LREAL:=0.0;  
    ScaleOffsetA:   LREAL:=0.0;  
    ScaleFactorB:   LREAL:=0.0;  
    ScaleOffsetB:   LREAL:=0.0;  
    SlippingOffset: LREAL:=0.0;  
    ReadingMode:    E_TcMcPressureReadingMode:=iTcHydPressureReadingDefault;  
END_VAR
```

[E\_TcMcPressureReadingMode](ms-xhelp:///?Id=beckhoff-0fab-4419-8171-b0d510ff6e3f)

```
VAR_INOUT  
    Axis:       Axis_Ref_BkPlcMc;  
END_VAR
```

```
VAR_OUTPUT  
    Error:          BOOL;  
    ErrorID:        UDINT;  
END_VAR
```

**Error**: The occurrence of an error is indicated here.

**ErrorID**: An encoded indication of the cause of the error is provided here.

**AdcValueA**, **AdcValueB**: These parameters are used to transfer the input data of the analog terminals.

**ScaleFactorA**, **ScaleFactorB**: [N/ADC\_INC] This value represents the weighting. It determines which pressure increase corresponds to a stage of the AD converter.

**ScaleOffsetA**, **ScaleOffsetB**: [N/ADC\_INC] This offset is used to correct the zero point of the pressure scale.

**SlippingOffset**: [N] If the function block is used for calculating the active force, the force required to overcome the sliding friction can be entered here.

**ReadingMode**: The actual value to be determined can be specified here. [Axis\_Ref\_BkPlcMc](ms-xhelp:///?Id=beckhoff-002b-4aba-81ea-1693fb03013c).[ST\_TcHydAxRtData](ms-xhelp:///?Id=beckhoff-1ffc-4f72-80ec-3f7c8585d12d).**fActPressure** is selected as default target.

**Axis**: Here, the address of a variable of type [Axis\_Ref\_BkPlcMc](ms-xhelp:///?Id=beckhoff-002b-4aba-81ea-1693fb03013c) should be transferred.

## Behaviour of the function block:

The function block determines the actual pressure and the actual force of the axis by evaluating the variables **AdcValueA** and **AdcValueB**. The result is entered in [ST\_TcHydAxRtData](ms-xhelp:///?Id=beckhoff-1ffc-4f72-80ec-3f7c8585d12d).fActPressure.

|  |  |
| --- | --- |
| 40800942 | The parameters assigned to an axis can be saved in ST\_TcHydAxParam.fCustomerData[...], for example. This ensures that the data are loaded, saved and backed up together with the standard parameters of the axis and are also exported and imported, as required. |

## Determining a differential actual pressure

Commissioning is usually done in one of three ways.

## Commissioning option A (preferred for ±10V)

In this case, no movement of the axis is required. The achievable accuracy is sufficient for high-quality pressure sensors in most cases.

* The rated pressure of the pressure sensors divided by **AdcValueA**MAX or **AdcValueB**MAX should be entered as **ScaleFactorA** and **ScaleFactorB**.
* If the function block is used for determining the actual pressure, the parameters **ScaleArreaA** and **ScaleArreaB** should be set to 1.0. Otherwise these parameters should be specified for an actual force in N (= Newton) in mm2.

## Commissioning option B

For this option it is necessary that a function block can be approached with full system pressure in both directions. A genuine movement of the axis is not required. Approaching of the end stops can be modeled by limiting the axis movement through provisional limits or even complete mechanical fixing.

* All function blocks, which respond to the value of [ST\_TcHydAxRtData](ms-xhelp:///?Id=beckhoff-1ffc-4f72-80ec-3f7c8585d12d).fActPressure, must be deactivated.
* First, slowly approach the lower function block (in the direction of decreasing actual position). The values for **AdcValueA** and **AdcValueB** are determined and logged. The system pressure should now be present on the A-side and the tank pressure – and therefore the ambient pressure – on the B-side. Should this not be the case for some reason, the pressures on the A- and B-side should be determined through measurement.
* Then, slowly approach the upper function block (in the direction of increasing actual position). The values for **AdcValueA** and **AdcValueB** are again determined and logged. Now measure the pressures again.
* The parameters to be entered can then be calculated as follows:
* **ScaleFactorA** := (PressureAMAX - PressureAMIN) / (**AdcValueA**MAX - **AdcValueA**MIN)**;**
* **ScaleFactorB** := (PressureBMAX - PressureBMIN) / (**AdcValueB**MAX - **AdcValueB**MIN)**;**
* **ScaleOffsetA** := PressureAMIN - **ScaleFactorA** \* **AdcValueA;**MIN
* **ScaleOffsetB** := PressureBMIN - **ScaleFactorB** \* **AdcValueB;**MIN

## Commissioning option C

Alternatively, commissioning can be carried out without axis control. However, the accuracy that can be achieved in this way is much lower.

* First, the axis should be made pressure-free. To this end, switch off the compressor and relieve the pressure in the accumulator.
* Ensure that the axis does not build up pressure. To this end, an axis that is subject to external forces (gravity etc.) should be supported mechanically. Open the valve several times in both directions, either manually or electrically.
* Now determine and log the values for **AdcValueA** and **AdcValueB**. The tank pressure – and therefore the ambient pressure – should be present both on the A-side and on the B-side. Should this not be the case for some reason, the pressures on the A- and B-side should be determined through measurement. Use the values found in this way as **MIN** values in the equations mentioned above.
* Take the pressure for the upper limit of the electrical signal (10 V, 20 mA) from the data sheet specifications for the pressure sensors. Use the upper limit value for the converted electrical value as **AdcValueA** and **AdcValueB**. Use these values as **MAX** values in the equations mentioned above.
* The parameters to be entered can then be calculated as described above.

## Determining an active force

To determine an active force, first determine the actual pressure, as described above. Entering the active areas under **ScaleArreaA** and **ScaleArreaA** causes the function block to convert the pressures on both sides into forces, taking into account the areas.

[TF5810 | TwinCAT 3 Hydraulic Positioning](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
