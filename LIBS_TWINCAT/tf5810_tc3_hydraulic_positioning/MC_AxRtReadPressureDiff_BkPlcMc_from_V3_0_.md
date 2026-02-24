# MC_AxRtReadPressureDiff_BkPlcMc (from V3.0)

## Library
tf5810_tc3_hydraulic_positioning

## Category
Motion Control

1. [TwinCAT PLC Hydraulics](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
2. [PLCopen Motion Control](ms-xhelp:///?Id=beckhoff-1ded-451e-88ec-a82873484e92)
3. [System](ms-xhelp:///?Id=beckhoff-cf25-4865-b897-b1877bc8684d)
4. [Encoder](ms-xhelp:///?Id=beckhoff-f3c4-4c4f-b160-19fe406dfb7c)
5. MC\_AxRtReadPressureDiff\_BkPlcMc (from V3.0)

# MC\_AxRtReadPressureDiff\_BkPlcMc (from V3.0)

![14660263](/tf5810_tc3_hydraulic_positioning/1033/Images/gif/9007200854756619__Web.gif)

The function block handles determination of the actual pressure of the axis from the input data of two analog input terminals.

|  |  |
| --- | --- |
| 64833508 | If only one input signal is available, a function block of type [MC\_AxRtReadPressureSingle\_BkPlcMc](ms-xhelp:///?Id=beckhoff-6b58-42dd-9f28-b93f3336f1ca) should be used. If the force is to be determined, instead of the pressure, a function block of type [MC\_AxRtReadForceDiff\_BkPlcMc](ms-xhelp:///?Id=beckhoff-1946-4575-bcf0-63dbcf7a8ec1) should be used. |

```
VAR_INPUT  
    AdcValueA:      INT:=0;  
    AdcValueB:      INT:=0;  
    ScaleFactorA:   LREAL:=0.0;  
    ScaleOffsetA:   LREAL:=0.0;  
    ScaleFactorB:   LREAL:=0.0;  
    ScaleOffsetB:   LREAL:=0.0;  
    ReadingMode:    E_TcMcPressureReadingMode:=iTcHydPressureReadingDefault;  
END_VAR
```

```
VAR_INOUT  
    Axis:           Axis_Ref_BkPlcMc;  
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

**ScaleFactorA**, **ScaleFactorB**: [bar/ADC\_INC] This value represents the weighting. It determines which pressure increase corresponds to a stage of the AD converter.

**ScaleOffsetA**, **ScaleOffsetB**: [bar] This offset is used to correct the zero point of the pressure scale.

**ReadingMode**: This parameter is used to specify where the result of the evaluation is to be stored.

**Axis**: Here, the address of a variable of type [Axis\_Ref\_BkPlcMc](ms-xhelp:///?Id=beckhoff-002b-4aba-81ea-1693fb03013c) should be transferred.

## Behaviour of the function block:

The function block investigates the axis interface that has been passed to it every time it is called. During this process, a problem may be detected and reported:

* If the pointer pStAxRtData in [Axis\_Ref\_BkPlcMc](ms-xhelp:///?Id=beckhoff-002b-4aba-81ea-1693fb03013c) is not initialized, the function block reacts with an **Error** and **ErrorID**:=dwTcHydErrCdPtrMcPlc. In this case, the axis cannot be placed into a fault state.

If these checks could be performed without problem, the actual pressure of the axis is determined by evaluating the variables **AdcValueA** and **AdcValueB**. The result is entered in [ST\_TcHydAxRtData](ms-xhelp:///?Id=beckhoff-1ffc-4f72-80ec-3f7c8585d12d).fActPressure.

The parameters assigned to an axis can be saved in [ST\_TcHydAxParam](ms-xhelp:///?Id=beckhoff-12fe-4458-a931-b3c9fca583f2).fCustomerData[...], for example. This ensures that the data are loaded, saved and backed up together with the standard parameters of the axis and are also exported and imported, as required.

## Commissioning option A

In this case, no movement of the axis is required. The achievable accuracy is sufficient for high-quality pressure sensors in most cases.

* The rated pressure of the pressure sensors divided by **AdcValueA**MAX or **AdcValueB**MAX should be entered as **ScaleFactorA** and **ScaleFactorB**.

## Commissioning option B

In this case, no movement of the axis is required. The achievable accuracy is sufficient for high-quality pressure sensors in most cases.

* The rated pressure of the pressure sensors divided by **AdcValueA**MAX or **AdcValueB**MAX should be entered as **ScaleFactorA** and **ScaleFactorB**.

## Commissioning option C

For this option it is necessary that a function block can be approached with full system pressure in both directions. A genuine movement of the axis is not required. Approaching of the end stops can be modeled by limiting the axis movement through provisional limits or even complete mechanical fixing.

* All function blocks, which respond to the value of [ST\_TcHydAxRtData](ms-xhelp:///?Id=beckhoff-1ffc-4f72-80ec-3f7c8585d12d).fActPressure, must be deactivated.
* First, slowly approach the lower function block (in the direction of decreasing actual position). The values for **AdcValueA** and **AdcValueB** are determined and logged. The system pressure should now be present on the B-side and the tank pressure – and therefore the ambient pressure – on the A-side. Should this not be the case for some reason, the pressures on the A- and B-side should be determined through measurement.
* Then, slowly approach the upper function block (in the direction of increasing actual position). The values for **AdcValueA** and **AdcValueB** are again determined and logged. Now measure the pressures again.
* The parameters to be entered can then be calculated as follows:
* **ScaleFactorA** := (PressureAMAX - PressureAMIN) / (**AdcValueA**MAX - **AdcValueA**MIN)**;**
* **ScaleFactorB** := (PressureBMAX - PressureBMIN) / (**AdcValueB**MAX - **AdcValueB**MIN)**;**
* **ScaleOffsetA** := PressureAMIN - **ScaleFactorA** \* **AdcValueA;**MIN
* **ScaleOffsetB** := PressureBMIN - **ScaleFactorB** \* **AdcValueB;**MIN

## Commissioning option D

Alternatively, commissioning can be carried out without axis control. However, the accuracy that can be achieved in this way is much lower.

* First, the axis should be made pressure-free. To this end, switch off the compressor and relieve the pressure in the accumulator.
* Ensure that the axis does not build up pressure. To this end, an axis that is subject to external forces (gravity etc.) should be supported mechanically. Open the valve several times in both directions, either manually or electrically.
* Now determine and log the values for **AdcValueA** and **AdcValueB**. The tank pressure – and therefore the ambient pressure – should be present both on the A-side and on the B-side. Should this not be the case for some reason, the pressures on the A- and B-side should be determined through measurement. Use the values found in this way as **MIN** values in the equations mentioned above.
* Take the pressure for the upper limit of the electrical signal (10 V, 20 mA) from the data sheet specifications for the pressure sensors. Use the upper limit value for the converted electrical value as **AdcValueA** and **AdcValueB**. Use these values as **MAX** values in the equations mentioned above.
* The parameters to be entered can then be calculated as described above.

[TF5810 | TwinCAT 3 Hydraulic Positioning](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
