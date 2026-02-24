# Basic settings

## Library
tf5810_tc3_hydraulic_positioning

## Category
Motion Control

1. [TwinCAT PLC Hydraulics](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
2. [Knowledge Base](ms-xhelp:///?Id=beckhoff-873e-46cd-925a-b9a96eea638e)
3. [Commissioning](ms-xhelp:///?Id=beckhoff-89eb-40cd-9eeb-3b237fbc590a)
4. Basic settings

# Basic settings

In order to start up the real axis, various default settings must be applied.

The corresponding encoder type must be entered in the **General** tab. To do this, the corresponding encoder must be selected via the selection menu and written to the runtime variables via **Activate**. The currently active type is displayed to the left of the selection window.

![66515904](/tf5810_tc3_hydraulic_positioning/1033/Images/gif/9007203500867723__en-US__Web.gif)

The Knowledge Base contains a [table](ms-xhelp:///?Id=beckhoff-18b7-49ad-a855-a0509f58bddd), which helps to select the correct encoder type and explains the mapping interface to I/O.

If, for technical reasons, it is not possible to determine the actual position with the standard encoder function block of the library, this task can also be executed by application function blocks. Then enter the result in fActPos and fActVelo in ST\_TcHydAxRtData and update the position change in the current cycle in fActPosDelta. bEncoderResponse should be used to indicate whether the actual values could be updated. For the sake of uniformity use should again be made here of the fEnc\_IncWeighting, fEnc\_IncInterpolation and fEnc\_ZeroShift or fEnc\_RefShift parameters.

A range of devices and equipment might be functioning as actuators (Drivetyp), applying a variety of physical principles to create a variable velocity that depends on an electrical magnitude. Depending on the corresponding I/O component, the Drivetype must be set in the selection window and the variables must be linked to the field device. The Knowledge Base contains a [table](ms-xhelp:///?Id=beckhoff-18b7-49ad-a855-a0509f58bddd) which supports the selection of the type to be set.

If the position measuring system is an incremental system, the corresponding [referencing method](ms-xhelp:///?Id=beckhoff-6975-4e0a-9321-fac7e60e8027) must also be defined.

On the **Global** tab you should initially enter 100 for the reference velocity. The value is corrected later, but in this way, overlap etc. can be entered directly in %.

The acceleration and deceleration should be set to 100 mm/s². With this setting, this axis will accelerate to reference velocity in 1 s. The jog parameters should be set to 5 mm/s and 10 mm/s. The creep velocity should be set to 5 mm/sec, the creep distance should be 10 mm and the braking distance 2 mm.

If the valve is covered and the valve data sheet is available, you can enter the overlap from the data sheet on the **Valve** tab.

On the **Encoder** tab, enter the resolution per increment in **Inc. evaluation**. Alternatively, an increment number can also be specified in **Inc. interpolation** and the corresponding path in **Inc. evaluation**.

In the **Controller** tab, the lag and velocity controller must be set to zero.

For further commissioning, a Scope with the following variables should be recorded:

* SetVelo
* ActVelo
* SetPos
* ActPos
* fOutput
* fLagCtrlOutput

If available, record pressures, forces and valve slide position.

If the controller enable and feed enable of the axis are set, the axis must not move. If this is the case, a temporary zero balance must be carried out.

[TF5810 | TwinCAT 3 Hydraulic Positioning](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
