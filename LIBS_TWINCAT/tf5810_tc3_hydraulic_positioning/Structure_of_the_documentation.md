# Structure of the documentation

## Library
tf5810_tc3_hydraulic_positioning

## Category
Motion Control

1. [TwinCAT PLC Hydraulics](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
2. [General structure](ms-xhelp:///?Id=beckhoff-9339-4a46-a86a-a60aafa2ce96)
3. Structure of the documentation

# Structure of the documentation

Each axis consists of an axis structure under the name "Axis\_ref\_BkPlcMc", which is composed of different external structures. This axis structure contains all the data (runtime data and parameter data) for this axis.

![42003681](/tf5810_tc3_hydraulic_positioning/1033/Images/gif/1599903755__Web.gif)

Certain function blocks have to be present in each application, to enable an axis to move. These function blocks include:

* [MC\_AxUtiStandardInit\_BkPlcMc](ms-xhelp:///?Id=beckhoff-b490-4a55-ac43-76ba1d070d46)**:** Initialization and monitoring of the different axis components. Such an FB should be called cyclically. Blocks such as **MC\_Power\_BkPlcMc,** etc. may only be called after successful initialization.
* [MC\_Power\_BkPlcMc](ms-xhelp:///?Id=beckhoff-f1de-4926-8132-1e2d75ae63fc)**:** The function block is used to control an external actuator. The function block issues release notifications to valve output stages or frequency converters, for example.
* [MC\_AxStandardBody\_BkPlcMc](ms-xhelp:///?Id=beckhoff-1687-4c16-854c-a550eeaaa344)**:** In each case the function block calls a function block of type  
   [MC\_AxRtEncoder\_BkPlcMc](ms-xhelp:///?Id=beckhoff-695e-4050-b1c6-c96353e7c191): Determination of the actual position of the axis from the input information of a hardware module.  
   [MC\_AxRuntime\_BkPlcMc](ms-xhelp:///?Id=beckhoff-992b-440b-b677-39eccb14d862): Deals with profile generation.  
   [MC\_AxRtFinish\_BkPlcMc](ms-xhelp:///?Id=beckhoff-0bc7-4c7a-b544-8f2d601813cd): Adaptation of the control value to the special characteristics of the axis (characteristic curve linearization)  
   [MC\_AxRtDrive\_BkPlcMc](ms-xhelp:///?Id=beckhoff-1548-4af2-9a41-a84b4ffd8e5d): The function block performs preparation of the control value for the axis for it to be output on a hardware module.
* [MC\_AxAdsCommServer\_BkPlcMc](ms-xhelp:///?Id=beckhoff-5702-45de-80d2-87ae2f7a2a8a)**:** Establishes the connection to PlcMcManager and monitors it. This block must be called independent of the initialization, in order to enable commissioning without existing parameters.

Optional useful function blocks are:

* [MC\_AxRtLoggerSpool\_BkPlcMc](ms-xhelp:///?Id=beckhoff-54e4-42b0-8b15-e29767b6b2eb)**:** The function block prevents overflowing of the LogBuffer of the library.
* MC\_AxParamDelayedSave\_BkPlcMc**:** Performs an auto-save of the axis parameters.

The so-called "PlcMcManager" is provided for commissioning. This tool consolidates setting parameters and is intended to facilitated commissioning of the system.

The first example is intended to illustrate the "first steps".

| Function groups | Description |
| --- | --- |
| [Management functions](ms-xhelp:///?Id=beckhoff-4720-4a6c-8984-3974598c0188) | Functions for management and monitoring of axes, parameter access and states. |
| [Single axis motion functions](ms-xhelp:///?Id=beckhoff-4720-4a6c-8984-3974598c0188) | Triggering and monitoring of active movements for individual axes. |
| [Axis group motion functions](ms-xhelp:///?Id=beckhoff-4720-4a6c-8984-3974598c0188) | Triggering and monitoring of active movements for axis groups. |
| [Drive adjustments](ms-xhelp:///?Id=beckhoff-4720-4a6c-8984-3974598c0188) | Function blocks for preparing axis control values for output on output devices (terminals, actuators etc.) in the periphery. |
| [Encoder adjustments](ms-xhelp:///?Id=beckhoff-4720-4a6c-8984-3974598c0188) | Function blocks for evaluating actual position data, which were read by input devices (terminals, encoders etc.) in the periphery. |
| [Parameter handling](ms-xhelp:///?Id=beckhoff-4720-4a6c-8984-3974598c0188) | Function blocks for saving, reading and communicating parameters. |
| [Motion generators](ms-xhelp:///?Id=beckhoff-4720-4a6c-8984-3974598c0188) | Control value generators for active axis movements |
| [Controller](ms-xhelp:///?Id=beckhoff-4720-4a6c-8984-3974598c0188) | Controllers for various state variables: position, velocity, pressure. |
| [Table functions](ms-xhelp:///?Id=beckhoff-4720-4a6c-8984-3974598c0188) | Table functions for non-linear mappings and cam plates |
| [Message logging](ms-xhelp:///?Id=beckhoff-4720-4a6c-8984-3974598c0188) | Message recording. |
| [Runtime functions](ms-xhelp:///?Id=beckhoff-4720-4a6c-8984-3974598c0188) | Various runtime functions. |
| Data types | [Enumerations](ms-xhelp:///?Id=beckhoff-4720-4a6c-8984-3974598c0188) and [structures](ms-xhelp:///?Id=beckhoff-4720-4a6c-8984-3974598c0188) used in the library |

[TF5810 | TwinCAT 3 Hydraulic Positioning](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
