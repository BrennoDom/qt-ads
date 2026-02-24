# Configuration of an axis

## Library
tf5810_tc3_hydraulic_positioning

## Category
Motion Control

1. [TwinCAT PLC Hydraulics](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
2. [Knowledge Base](ms-xhelp:///?Id=beckhoff-873e-46cd-925a-b9a96eea638e)
3. Configuration of an axis

# Configuration of an axis

In contrast to the Beckhoff NC, the axis in the hydraulic library is configured by the application itself. This means that the function blocks for operating an axis (read actual value, generate setpoints, generate position rules, linearization and output) must be called up individually.

All function blocks work on a common axis reference, which must be created globally. If there is more than one axis, the axis references must be created as an array.

In addition to the axis reference ([AXIS\_REF\_BkPlcMc](ms-xhelp:///?Id=beckhoff-002b-4aba-81ea-1693fb03013c)), the I/O structures [ST\_TcPlcDeviceInput](ms-xhelp:///?Id=beckhoff-dec6-4dd6-a155-f200065a8d2d) and [ST\_TcPlcDeviceOutput](ms-xhelp:///?Id=beckhoff-fec4-45f2-b458-d8180069b32f) must be declared for each axis. Further optional elements are added, depending on the application.

To view messages a [ST\_TcPlcMcLogBuffer](ms-xhelp:///?Id=beckhoff-2e65-4b91-955d-12cfc3c231b1) should be declared. This buffer is shared by all axes.

If other sensors such as pressure or load cells are used in the application in addition to position detection, the I/O value must be set in the application. The parameterization of the scaling can be managed in the fCustomerData[] section of the axis. For each axis 20 customer-specific data are provided in this section. This data is saved via the axis, loaded and displayed in the PLcMcManager. For the display in the PlcMcManager the label can be changed by declaring the structure [ST\_TcMcAuxDataLabels](ms-xhelp:///?Id=beckhoff-50c8-4b5f-bdf7-0e14cb1fc422).

![25151514](/tf5810_tc3_hydraulic_positioning/1033/Images/gif/6898867723__Web.gif)

Sample for the data of an axis

## General settings

An attribute must be set in TwinCAT 3 so that the I/O is always read in with a constant time interval, regardless of the time required by the program.

![25037038](/tf5810_tc3_hydraulic_positioning/1033/Images/png/6806073995__Web.png)

In TwinCAT 2, the **I/O flag at the start of the task** must be set in the System Manager under **PLC configuration**.

![24006753](/tf5810_tc3_hydraulic_positioning/1033/Images/png/6806075659__en-US__Web.png)

In contrast to NC, the hydraulic axis itself (setpoint generator, controller, etc.) is calculated directly in the PLC. It is therefore recommended to set the cycle time of the task to less than 10 ms.

## Initialization

The PLCopen standard specifies that all Motion function blocks of the application are called with an instance of type AXIS\_REF\_BkPlcMc. For technical reasons, some axis components cannot be contained in such an instance, since they must be located in separate areas (e.g. process images). Other elements are optional and are only be added if required. To link them to the axis reference, they are transferred to an initialization function block of type [MC\_AxUtiStandardInit\_BkPlcMc](ms-xhelp:///?Id=beckhoff-b490-4a55-ac43-76ba1d070d46).

![14734188](/tf5810_tc3_hydraulic_positioning/1033/Images/png/4246153611__Web.png)

When called for the first time, the function block links the input and output structures and all optional elements with the axis reference. Variables that have to be passed as addresses are marked with the prefix "p". The function block should be called cyclically to check the pointer addresses.

|  |  |
| --- | --- |
| 65498832 | It is not permitted to bind an instance of ST\_TcPlcDeviceInput, ST\_TcPlcDeviceOutput or ST\_TcMcAutoUdent to multiple axes. It is not permitted to connect more than one instance of ST\_TcMcLogBuffer to axes. |

The function block loads the parameters from the given file path and transfers them to the axis reference. All parameters are stored in binary form in an *Axis name.dat* file.

Once the parameters have been loaded successfully, the bParamsEnable flag in the axis reference becomes TRUE. Only now is the use of parameters that have not yet been defined ruled out, and all other axis-related function blocks may be called.

## Actual value acquisition

![52618583](/tf5810_tc3_hydraulic_positioning/1033/Images/gif/6898949387__Web.gif)

The encoder type set in the parameter structure of the axis reference determines how and from which variables of the input structure the [MC\_AxRtEncoder\_BkPlcMc](ms-xhelp:///?Id=beckhoff-695e-4050-b1c6-c96353e7c191) function block will read the actual value and convert it to a position [mm] and a velocity [mm/s]. The connection is monitored when EtherCAT components are used.

If the actual values are very noisy, it is possible to filter them via a sliding average value ([MC\_AxUtiSlidingAverage\_BkPlcMc](ms-xhelp:///?Id=beckhoff-7904-4049-b398-bf5aabb72e13)) or a Pt1 element ([MC\_AxUtiPT1\_BkPlcMc](ms-xhelp:///?Id=beckhoff-b2b4-4b5a-8b30-ef234e33b238)). The use of custom filters is possible.

Filter function blocks must be called after the encoder function block. The variable to be filtered must be passed to their input. The result can be written back to the corresponding variable of the axis reference. This causes the old noisy value to be replaced by a new, stabilized value.

|  |  |
| --- | --- |
| 3805200 | If a heavily filtered actual value is used for control purposes, the dynamics and controllability can be affected due to the filter jump response. |

Additional function blocks are available for reading in pressure and force values. The function block to be used depends on the variable to be measured. In contrast to position determination, for force and pressure determination the mapping interface and terminal monitoring must be provided by the application.

|  |  |
| --- | --- |
| 34246806 | [MC\_AxRtHybridAxisActuals\_BkPlcMc](ms-xhelp:///?Id=beckhoff-2939-4fc5-b645-2205eba49080) is an adapted function block for determining the essential actual values of a servo-electric/hydraulic hybrid axis. |

## Setpoint generation and default position controller

If, for example, [MC\_MoveAbsolute\_BkPlcMc](ms-xhelp:///?Id=beckhoff-d937-4450-b853-cb18922787db) triggers an active movement of the axis, the setpoint generator calculates the current values for the set velocity and the set position in each cycle. This can be done in a time-controlled or path-controlled manner. Permanent position control is required for time-controlled generation, otherwise this is only required at standstill. Several profile variants are supported. For more information, please refer to the documentation for the function block.

![39785801](/tf5810_tc3_hydraulic_positioning/1033/Images/gif/6899000331__Web.gif)

If the axis does not have a command buffer, a command is entered directly in the runtime data of the axis. Otherwise, commands are buffered, subjected to path planning, and then made effective according to the blending rules.

If required, the application can handle the setpoint generation. An [MC\_AxRtSetExtGenValues\_BkPlcMc](ms-xhelp:///?Id=beckhoff-47ec-4355-83da-221f9f967897) function block must be used for this purpose. If external generation is active, the library block to be called is switched to a passive state and then reactivated. In this way, application-specific gear units and other non-standard mechanisms can be realized.

The setpoint generator and a default position controller that is adequate in most cases are integrated in the [MC\_AxRuntime\_BkPlcMc](ms-xhelp:///?Id=beckhoff-992b-440b-b677-39eccb14d862) function block.

## Alternative position controller

If another controller is called after the default position controller and fLagCtrlOutput is overwritten in the runtime data of the axis reference, another position controller can be activated. This can be a customer-specific controller or another controller from the library such as the FB [MC\_AxRtPosPiControllerEx\_BkPlcMc](ms-xhelp:///?Id=beckhoff-feba-4c4e-afbf-2a4ddc9e9d94).

![22527890](/tf5810_tc3_hydraulic_positioning/1033/Images/gif/9051354379__Web.gif)

This library controller is a PID controller with optional extensions such as condition feedback and acceleration pre-control.

## Further controllers

Pressure or force controllers are used in many applications with hydraulic axes. As an example, an [MC\_AxCtrlPressure\_BkPlcMc](ms-xhelp:///?Id=beckhoff-6561-479c-a264-3883abee8510) function block is shown here.

![1424418](/tf5810_tc3_hydraulic_positioning/1033/Images/png/4246138251__Web.png)

In the active state, the function block overwrites the output of the setpoint generator. In order for the controller response to take effect, it must be called up before linearization.

|  |  |
| --- | --- |
| 12819762 | When activating or deactivating, step changes in the control values of the axis can occur depending on the parameter values. |

## Final processing

At this point, the control values of the axis are present in a form that assumes linear behavior of the axis and its components. In practice, this is rarely the case. To take this into account, the control values (setpoints, controller outputs, overlap compensation) are combined to an output value and subjected to linearization. This adjustment can be carried out in sections or based on characteristic curves.

## Sectional linearization

The library provides the function block [MC\_AxRtFinish\_BkPlcMc](ms-xhelp:///?Id=beckhoff-0bc7-4c7a-b544-8f2d601813cd) for simple linearization.

![48268995](/tf5810_tc3_hydraulic_positioning/1033/Images/gif/9007200854800395__Web.gif)

The set velocity weighted with the pre-control and the controller output are added to the output velocity.

An active overlap compensation is selected such that it is ramped linearly from zero to the set overlap compensation Ovl between 0 and VCreep. It is fully effective for the remaining area.

![31767774](/tf5810_tc3_hydraulic_positioning/1033/Images/bmp/4721397899__Web.bmp)

The direction dependency is compensated. The output velocity is multiplied by fAreaRatio from the axis parameters if the velocity is positive and fAreaRatio ≥ 1.0. If the velocity is negative and fAreaRatio ≤ 1.0 division is applied.

The output is formed by adding the weighted target velocity, the controller output, the active overlap compensation and the offset correction.

## Linearization based on characteristic curve

The library provides the function block [MC\_AxRtFinishLinear\_BkPlcMc](ms-xhelp:///?Id=beckhoff-e15e-40cb-b1bb-32215a440336) for this linearization with higher resolution.

![17474517](/tf5810_tc3_hydraulic_positioning/1033/Images/png/4246144011__Web.png)

If the use of the characteristic curve is not enabled or not possible, an internal function block is used for sectional linearization. This is the case if at least one of the following reasons applies:

* FALSE is transferred at the enable input of the function block.
* No instance of type ST\_TcMcAutoIdent has been linked to the axis reference.
* bLinTabAvailable in the axis parameters is FALSE: The characteristic curve is not valid.

Otherwise, the target velocity weighted with the pre-control and the controller output are added to the output velocity. The two characteristic curve points closest to the calculated value are determined and the output value is formed by intermediate interpolation and addition of the offset correction.

## Characteristic curve measurement

![23052927](/tf5810_tc3_hydraulic_positioning/1033/Images/png/4246149771__Web.png)

The function block [MC\_AxUtiAutoIdent\_BkPlcMc](ms-xhelp:///?Id=beckhoff-6e26-4519-a6b1-d0581db76054) supports the measurement of a characteristic curve by means of a standardized automatic sequence. The parameters to be set for this are stored in the structure [ST\_TcMcAutoIdent](ms-xhelp:///?Id=beckhoff-d8cd-4957-b2b8-b8cd53f4d9b3). If a characteristic curve measurement and a characteristic curve-based linearization are to be used, such an element must be created and connected to the axis reference.

|  |  |
| --- | --- |
| 6149759 | An MC\_AxUtiAutoIdent\_BkPlcMc function block must be called after the [MC\_AxRtFinishLinear\_BkPlcMc](ms-xhelp:///?Id=beckhoff-e15e-40cb-b1bb-32215a440336) function block and before the [MC\_AxRtDrive\_BkPlcMc](ms-xhelp:///?Id=beckhoff-1548-4af2-9a41-a84b4ffd8e5d) function block of the axis. |

The characteristic curve determined in this way combines the influences of a number of sources:

* Non-linearities of the valve
* Asymmetry of the cylinder
* Flow effects at higher velocities
* Possible limitations due to a pump
* Positional influences such as gravitation
* Influences of other components in the oil flow

|  |  |
| --- | --- |
| 55347837 | With a servo-electric/hydraulic hybrid axis, no MC\_AxUtiAutoIdent\_BkPlcMc function block may be activated. |

## Output adjustment

![28368490](/tf5810_tc3_hydraulic_positioning/1033/Images/png/4246140171__Web.png)

At this point, the control values for the axis are available as physical or standardized parameters. Only the [MC\_AxRtDrive\_BkPlcMc](ms-xhelp:///?Id=beckhoff-1548-4af2-9a41-a84b4ffd8e5d) function block determines an output parameter that represents these parameters in a form that is converted to the desired response by the device used. The method used and its parameters are set in the parameter structure of the axis reference.

## Interfacing of the PlcMcManager

In preparation.

![53989823](/tf5810_tc3_hydraulic_positioning/1033/Images/png/4246136331__Web.png)

The PlcMcManager is connected via the TwinCAT ADS service. Since this allows only one port per application, all axes must use a common connection. Multiple instances of this function block are not permitted.

The sample shown applies to an application with only one axis. Multi-axis projects must combine the axis references in an array whose address and first and last index are transferred.

This FB must be called independently of whether axes can load their parameters.

## Message logging

![16146366](/tf5810_tc3_hydraulic_positioning/1033/Images/png/4246145931__Web.png)

All axes of an application share a logging buffer. To send the messages that arrive there to the Event Log of the operating system and, if available, to the message window of the development environment, create an instance of the function block [MC\_AxRtLoggerSpool\_BkPlcMc](ms-xhelp:///?Id=beckhoff-4c01-4158-8f0c-ab6270fd0cfd) for each application. The call of the function block is independent of whether axes can load their parameters.

Further Information

* [FB\_Power](ms-xhelp:///?Id=beckhoff-75cc-46f9-ab66-dfc385b34a13)

[TF5810 | TwinCAT 3 Hydraulic Positioning](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
