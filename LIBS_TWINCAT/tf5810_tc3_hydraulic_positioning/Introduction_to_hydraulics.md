# Introduction to hydraulics

## Library
tf5810_tc3_hydraulic_positioning

## Category
Motion Control

1. [TwinCAT PLC Hydraulics](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
2. Introduction to hydraulics

# Introduction to hydraulics

## Hydraulics vs electromechanics: a technology comparison

Hydraulic drives differ from electric drives in that they have a fundamentally different design, so that their behavior is only comparable to a limited degree. This special behavior and the distinctly different fields of application require adapted control and monitoring mechanisms. The following table provides an overview of these differences.

The electromechanical axes controlled by TwinCAT NC/NCI/CNC typically consist of an AX servo drive and an AM synchronous motor with integrated position measuring system. The differences mainly relate to the design, since linear or asynchronous motors can also be traced back to this basic principle. The servo drive generates a rotating or moving magnetic field through the currents it controls, which is followed by the moving part of the motor. The strength, speed and angular/rotational speed difference of this magnetic field to the rotor is controlled in such a way that the desired movement is achieved. With appropriate design, a configuration is created that can be easily modeled. Since the basic structure is constant, this basically also applies to the model.

Hydraulic axes are a much more varied in terms of their design. In addition to the various variants of linear cylinders (plungers, synchronous, differential, area-switchable cylinders etc.), several rotary drives (swivel cylinders, rotary cylinders, various types of hydraulic motors) are available as actuators. The velocity can be defined through continuous valves or primary or secondary controlled pumps. In addition, there are various hydraulic circuits in which further components influencing the amount of oil or pressure are added. Most of these have a non-linear or situation-dependent behavior.

Ultimately, these differences mean that applications which can be achieved by a precisely defined and then precisely executed movement are nowadays largely realized electromechanically. The more complex, less standardized and difficult to handle hydraulic axes are used for tasks in which their particular strengths can be exploited. For example, they are ideally suited for applying large forces and energies over long periods or in applications where space is limited. In many cases, the behavior they are used to controlled is atypical for electromechanical drives, such as limiting or relieving pressure or force control. The plastics industry and metal forming are just two examples.

## Electric/hydraulic hybrid axes

Electromechanical servo axes and hydraulic axes both offer specific advantages. The combination of these technologies creates a hybrid system that offers a new mixture of positive and negative properties from both worlds. Even though it is not possible to utilize all advantages in this way while avoiding all disadvantages, overall a clear advantage can be achieved by combining the technologies in a suitable manner. The following section provides an overview of these concepts.

Proportional valve-controlled hydraulic axes are less efficient than servo axes, which is a significant disadvantage. Their efficiency is limited by the principle of throttle control. Electric drive control based on the PWM principle has been used for decades. For technical reasons (no switching valves with high flow rate and low switching time << 1ms) this is not possible for hydraulic axes. In hybrid axes the oil flow is controlled by changing the speed and possibly the direction of rotation of a constant current pump with a servo drive, rather than by using a variable throttle. In theory, there is no pressure drop between the pump and the cylinder. The pump can be regarded as a friction-locked but not form-locked gear unit, while the cylinder assumes the role of a spindle.

A selectable feed constant can be made available by making provision for changing the effective cylinder areas or the quantity of oil pumped per revolution by switching the oil paths depending on the situation. The result is a true gear shift that is not available for an electromechanical axis. In applications that require alternating high velocity and high power, this can lead to considerable savings.

Switching valves can be used to hydraulically fix a force once it has built up and relieve the load on the electric drive. In this way, the torque reduction of an electromechanical axis can be avoided.

All components of the hybrid axis can be assembled as a self-contained module up to performance values that can be quite considerable. In this case, all hydraulic connections are encapsulated internally, and the only external connections are electrical ones. The axis is mountable and also exchangeable like an electromechanical axis. In situations where higher performance is required, a conventional discrete structure has to be used. However, it should be noted that a comparable electromechanical axis is also anything but compact or light.

Further details on the configuration concept and commissioning can be found in the Knowledge Base (in preparation).

## Overview of differences

The differences in design described above have a considerable effect on the operating behavior of hydraulic and electric drives. An overview of these effects is presented below.

Typical natural frequencies of electromechanical axes are in the range >80 Hz. Values below 20 Hz are not uncommon for hydraulic axes. In both technologies, axes with >200 Hz can be realized, but for technical and/or calculation reasons they are only used when necessary. The natural frequency has a direct influence on controllability, since it limits the usable kP of the position controller. The controllability of electromechanical axes is a prerequisite for standard NCs.

* For hydraulic axes, differential cylinders with just one piston rod are preferred. This makes the feed constant (here defined as travel per oil quantity) direction-dependent. Standard NCs do not take this behavior into account, because there is no such effect with electromechanical axes.
* The asymmetrical working surfaces of a differential cylinder require an asymmetrical pressure distribution on the surfaces for a standstill in force equilibrium. If the axis starts in the opposite direction, a different pressure distribution must be established. For this purpose, an amount of oil has to be transported through the valves, which are initially only slightly opened, without any movement taking place. This leads to a delayed startup. A comparable but much fiercer phenomenon occurs if the axis has built up a pressing force beforehand. Standard NCs do not take this behavior into account, because there is no such effect with electromechanical axes.
* Hydraulic actuators rely on seals to separate their workspaces from each other and from ambient. These seals, which in some cases have long circumferential edges, are in contact with metal surfaces and must slide on them. Above all, the transition from standstill to movement is accompanied by pronounced changes in adhesion/sliding friction. The comparable effects with electromechanical axes are several orders of magnitude smaller and are usually negligible. In the case of hydraulic axes, they play a key role in determining the behavior on startup, when approaching the target and when moving at low speeds.
* Hydraulic axes use continuously adjustable valves or pumps as actuators. These components are always more or less non-linear. The system gain to be taken into account by the controller and the feed constant to be used by the pilot control are dependent on the operating point. Compromises in motion control can be reduced through linearization, but not completely avoided. Standard NCs do not take this behavior into account, because there is no such effect with electromechanical axes.
* A dead range around the zero point of several 10 % of full scale is not uncommon for valves. Even with linearization, position control at standstill is then only possible to a limited extent. Standard NCs do not take this behavior into account, because there is no such effect with electromechanical axes.
* The output value sent to the valve defines the slider position and thus, via a non-linear mechanical function, the openings for the oil flow. However, the pressure drop across the opening has a strong influence on the actual oil quantity and thus on the cylinder speed. Fluctuations in the supply pressure or cylinder pressure (resulting from the process force) have a strong influence on the axis velocity.
* It is not easily possible to use of an I component in the controller. In combination with the adhesion/sliding friction changes, low-frequency oscillations can easily occur, which are difficult to control. The cylinder oscillates periodically around positions determined by the working cycle, resulting in damage to seals and surfaces in the medium term.

It may be possible to operate a hydraulic axis with a standard NC. The higher the quality of the component selection and configuration, the easier it is to do this. However, expectations regarding the behavior then offer little room for compromise. Conventional hydraulic axis configurations usually require adapted solutions, which are provided by Beckhoff Automation in the hydraulic library.

## Motion Control in a different way

The key function of a Motion Control solution is the set value generator. It calculates or resolves instantaneous set values for position, velocity, acceleration and possibly jerk. The time-controlled mode of operation of the NC is well known in this context. However, there is an often overlooked alternative that is of particular interest for hydraulic axes. Its derivation and the differences are described below.

A set value generator can operate either as a function of or independently of the variables of another axis. The former is the case if the values for a cam plate coupling are derived from the values of another axis via a table or, in the case of a gear coupling, via a calculation formula. This requires a position controller that is active during the motion. Both the hydraulics library and, above all, the NC offer various options here.

If the values are calculated independently of other axes, a distinction must be made between time-based and displacement-based generation. Like practically all current MC systems, TwinCAT NC/NCI/CNC works on a time-controlled basis. The core technology of the hydraulic library is path-controlled, although here, too, time-controlled operation is possible. The differences are shown below.

A time-controlled Motion Control solution uses equations in which the motion profile runs on a time basis. This is shown below for an accelerated movement:

V := A \* t

P := ½ \* A \* t2

If the first equation is squared and then both equations are resolved to t2 and equated, the following equation is obtained:

V := SQRT( 2 \* A \* P )

If the absolute value of the remaining distance s to a target position is used for P and the sign is restored, a suitable braking ramp results.

V := ± SQRT( 2 \* A \* ABS( s ) )

It should be noted that the time as the controlling variable has been replaced by the path. Combining this braking ramp with a ramp for the acceleration phase and a constant phase provides the basis for a simple but particularly robust Motion Control solution that is characterized by the following features:

* Delayed axis responses at the start of a motion are ignored. The valve is not initially opened excessively and without effect by a position controller, only to be controlled back down again to a standstill once the cylinder springs into action.
* No position control takes place even during the active motion. If the axis does not move at the correct velocity or at varying velocity, this is automatically compensated for by a premature or delayed initiation of the brake phase.
* Counter forces generated by the process slow down the axis. However, this inevitably leads to an increase in pressure even without a reaction from the control unit, possibly up to the supply pressure and thus to the maximum available force. If this is not sufficient for a further movement, it would not be affected by a controller either. Even without position control, there is no risk of the axis stopping.
* When approaching the target position, the velocity is adjusted according to the remaining distance. This adjustment happens continuously and thus compensates for inaccurate braking.
* Non-linearities are also compensated. However, they can appear as interfering irregularities in the acceleration. In this case, the behavior can be improved by a more precise linearization.
* The permanently active position controller, which is inevitable with the time-controlled principle, increases the tendency to oscillate and generates undesirable changes in the speeds. With electromechanical axes, this effect is less pronounced and can be tolerated. Hydraulic axes are subjected to considerably more excitation sources, and they have lower frequency and are less attenuated. The effect is distinct and often rather troublesome.
* The accuracy at the target does not depend on the method used. In the time-controlled "vertical" principle, a deviation of the axis behavior from the ideal is compensated by an added controller output. With the displacement-based principle, the reaction takes place by "horizontal" stretching or compressing of the profile.
* With the time-based principle, two axes that are operated with the same parameters and started simultaneously with the same commands will move as if they were mechanically connected. Both axes move at the right time in the right place and at the right velocity. The deviation is limited to the (typically small) lag errors and is not integrated.
* With the displacement-based principle, influences from the process or even manufacturing tolerances of the components are not compensated. Deviations are integrated within a movement. There is no definitive expectation of a link between two axes that are operated with the same parameters and started simultaneously with the same commands. They are positioned in the target with the achievable accuracy, but do not necessarily arrive there at exactly the same time.

## Structure of the library

In contrast to the NC, the library functions work entirely in the PLC runtime. This has several consequences, which are listed below.

* Internal function blocks are usually also visible. This makes the online view less transparent. On the other hand, local variables can be used for an analysis.
* All parameters and even runtime variables are visible and accessible. This creates opportunities for specific manipulations. It should be obvious why this should be done with the utmost care.
* Nothing is done without a corresponding function block being called directly or indirectly. In contrast to the NC, the internal operation of the Motion Control is very transparent. This is particularly true for:

+ Loading and saving of parameters.
+ Recording of actual values.
+ Setpoint generator.
+ Regulation.
+ Output adjustment.

* In contrast to NC, there are no "finished" axes. This increases the initial effort, but also offers opportunities for realizing adapted properties.
* Since the axis is configured in the PLC application, it is easily possible that unexpected and difficult to comprehend effects are created by an incorrect sequence or combination of the called function blocks. It is highly advisable to follow the examples.
* Since the function blocks are called by the PLC, the Motion Control also works with the cycle time of the PLC task. A task with a typical NC cycle time of considerably less than 10 ms should be used.

In order to make the projects more transparent, the most important function blocks are implemented according to the PLCopen standards. Among other things, this standard specifies that the function blocks are linked to an axis via a reference named AxisRef. Since there is no hidden task level in the library, all data (parameters, runtime values) required for the axis are integrated in this structure. The communication of the function blocks of an axis is based on shared use of this reference. The only exceptions are the signals defined by PLCopen. The Execute input can be controlled by the Done output of another function block, for example, in order to create a desired sequence.

## Structure of an application

In a PLC application realized with the hydraulics library, a distinction should be made between three different types of function block:

* System function blocks related to all axes. This includes communication with the PlcMcManager IBN tool or handling of message recording. Regardless of the number of axes, these function blocks must be instantiated exactly once per project and called up exactly once per cycle. This should obviously be done from the Main() routine of a program.
* Function blocks used for the configuration of an axis. These include, for example, the encoder function block and the set value generator etc. Exactly one instance of these function blocks must be created for each axis. The call should be made exactly once per cycle.
* Function blocks related to an axis. These include, for example, the MC\_MoveAbsolute\_BkPlcMc function block and the MC\_Stop\_BkPlcMc function block etc. More than one instance of these function blocks can be created for each axis. As a rule, the call must be made exactly once per cycle.

If the application has only one axis, this difference is less clear, but must still be considered.

## System function blocks

The system function blocks include the following:

* MC\_AxAdsCommServer\_BkPlcMc()

This function block provides an joint ADS connection for the PlcMcManager for all axes. If this function block is not called cyclically, no connection is established.

* MC\_AxRtLoggerSpool\_BkPlcMc() or MC\_AxRtLoggerDespool\_BkPlcMc

This function block manages the message buffer. If exactly one of these function blocks is not called cyclically, the message buffer overflows, and subsequent messages are lost.

As you can see, the system function blocks require access to all affected structures. At the same time, the axis-related function blocks also require access. This can be easily ensured by creating the structures as VAR\_GLOBAL. This is shown in the examples and applies especially to:

* The axis references. They should be created as ARRAY[1... number of axes] OF Axis\_Ref\_BkPlcMc.

+ This means that it is not possible to distribute the axis references in modules of the application.
+ There is an alternative method that works with POINTER lists. Special care is required in his case. This method is therefore not recommended for general use.

* The message buffer of type ST\_TcPlcMcLogBuffer. The buffer is shared by all axes, and the management function block therefore cannot be assigned to an axis.

## Function blocks for the structure of an axis

These always include:

* The initialization function block MC\_AxUtiStandardInit\_BkPlcMc().
* The function blocks of the actual value acquisition. These always include a function block of type MC\_AxRtEncoder\_BkPlcMc() and one or more function blocks for determining pressures or forces, as required. Filtering can be used, if necessary.
* A function block of type MC\_AxRuntime\_BkPlcMc() for setpoint generation. This function block contains a standard position controller.
* A function block of type MC\_AxAxRtFinish\_BkPlcMc() or MC\_AxRtFinishLinear\_BkPlcMc. Various output parameters are combined here, and a section-by-section or characteristic curve-controlled output linearization is carried out.
* A function block of type MC\_AxRtDrive\_BkPlcMc() that adapts to the I/O variables of the output hardware.

If necessary, this minimum structure must be supplemented by function blocks that give the axis additional capabilities. These include, for example, function blocks for controlling pressures or forces, as an alternative position controller or for automatic measurement of characteristic curves. To be effective, the calls of these function blocks must be inserted at the correct position between the above-mentioned function blocks.

The transparency of the application can be improved by combining these function blocks into an axis block with general interfaces.

## Axis-related function blocks

These include the usual function blocks for configuring the working cycle of an axis.

* MC\_Power\_BkPlcMc
* MC\_MoveAbsolute\_BkPlcMc
* MC\_Stop\_BkPlcMc
* MC\_Reset\_BkPlcMc
* MC\_Home\_BkPlcMc
* MC\_GearIn\_BkPlcMc
* MC\_GearOut\_BkPlcMc
* etc.

Since the behavior of these function blocks corresponds to the PLCopen definitions, they can largely be used like the corresponding function blocks of the TC\_MC libraries. However, the function blocks of these libraries only send commands to the NC driver and observe its reactions and feedback. Various function blocks of the hydraulic library contain essential parts of the functionality and must be called continuously and in every cycle. This must be taken into account when creating the application.

[TF5810 | TwinCAT 3 Hydraulic Positioning](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
