# The hydraulics library

## Library
tf5810_tc3_hydraulic_positioning

## Category
Motion Control

1. [TwinCAT PLC Hydraulics](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
2. [General structure](ms-xhelp:///?Id=beckhoff-9339-4a46-a86a-a60aafa2ce96)
3. The hydraulics library

# The hydraulics library

Special control algorithms are required to meet the requirements of the hydraulic systems. The PLC libraries TcPlcHydraulics\_30 (for TC2) and TC2\_Hydraulic (for TC3) contain a number of blocks and functions for hydraulic axes and the data types used in them. They extend support for this drive technology by enabling the operation of axes whose properties (limit frequency, scattering behavior) make them unsuitable for position control, or whose tasks differ from those of electrical servo axes.

The product presented here includes:

* the software library "TcPlcHydraulics.lib" or "Tc2\_Hydraulics.compiled-library"
* the commissioning tool "PlcMcManager.exe"

To simplify the use of the library, the function blocks are designed based on specifications by the IEC61131 user organization (PLCopen) and certified accordingly.

![57201619](/tf5810_tc3_hydraulic_positioning/1033/Images/jpg/1599901323__Web.jpg)

|  |  |
| --- | --- |
| 45052529 | The documentation for version V2.1 will continue to be available. |

**Library topics:**

* Evaluation of [encoders](ms-xhelp:///?Id=beckhoff-695e-4050-b1c6-c96353e7c191)
* Evaluation of pressure cells
* Various filter functions

+ Pt1 filter
+ [Moving average](ms-xhelp:///?Id=beckhoff-7904-4049-b398-bf5aabb72e13)
+ [Rise limitation](ms-xhelp:///?Id=beckhoff-2d11-4d1a-9ac2-6c635cfb69fe)

* Full access to internal parameters
* Motion control
* Controllers for

+ Pressure/force
+ Position
+ Velocity
+ Possibility of in-house controller development

* Synchronization of hydraulic and electric axes
* Adaptation of control values to output devices
* Full handling of complex devices
* Message logging
* Parameter handling

+ Storage and loading routines
+ Autosave

* Characteristic curve linearization

+ Section by section
+ [Characteristic compensation curve](ms-xhelp:///?Id=beckhoff-6e26-4519-a6b1-d0581db76054)

**The following motion controllers are supported:**

1. Time-based motion control:

* The controlling parameter for the profile generation is time.
* The generator does not “know” the axis.
* Only the pre-controlled position controller establishes the connection.

2. Displacement-based motion control:

* The controlling parameter for the profile generation is the residual path.
* The generator “knows” the axis.
* During motion no position control is possible/required.

3. Dependent motion control:

* The set values are calculated from the values of another axis, based on a mapping rule (gear formula, curve table).
* The generator does not “know” the axis.
* Only the pre-controlled position controller establishes the connection.

**Displacement- and time-based motion control:**

Time-based motion control uses time reference variable. The basic equations are

v=a\*t and

s=0.5\*a\*t\*t.

The set value generator provides a velocity and a position, which are evaluated by the position and velocity controller and offset against the current position.

During displacement-controlled positioning, in contrast to time-controlled the control value for the axis is calculated as a function of the residual path. Rearranging the above equations results in

v=sqrt(2\*a\*s).

Both methods have advantages and disadvantages.

* Time-controlled require closed-loop control, particularly for acceleration and deceleration processes. The feedback is essential to enable the velocity controller to generate the correct output value. However, such a control loop reacts strongly to stick/slip effects or supply pressure fluctuations, which can cause the system to start oscillating.
* Displacement-controlled axes do not have to be operated in closed-loop control. This method is therefore significantly more robust against external interference.
* Since displacement-control of axes is based on the displacement, not on the time, a velocity is provided, but not readjusted. This makes the positioning of hydraulic axes very robust.

Both methods are supported by the hydraulics library and can also be used in combination.

[TF5810 | TwinCAT 3 Hydraulic Positioning](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
