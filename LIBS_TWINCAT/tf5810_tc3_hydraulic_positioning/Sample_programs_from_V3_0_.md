# Sample programs (from V3.0)

## Library
tf5810_tc3_hydraulic_positioning

## Category
Motion Control

1. [TwinCAT PLC Hydraulics](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
2. [Knowledge Base](ms-xhelp:///?Id=beckhoff-873e-46cd-925a-b9a96eea638e)
3. Sample programs (from V3.0)

# Sample programs (from V3.0)

**Structure of the application**

The application is largely made up of PLCopen function blocks. A selection of function blocks is available, which are equipped with an interface defined by the PLCopen. A number of examples are described below, which provide a good basis for project configuration.

Each example contains the project file, the required axis parameter files and a scope configuration. The axis parameter files must be stored in a folder on the target system. The file path must be adjusted in the global constant "cnst\_ParamFilePath" of the project file.

**Example 1: Single axis**

For TC2: [TcPlcMcEx\_1.zip](https://infosys.beckhoff.com/content/1033/tf5810_tc3_hydraulic_positioning/Resources/zip/27021599364076427.zip)

For TC3: [TC3\_TcPlcMcEx\_1.zip](https://infosys.beckhoff.com/content/1033/tf5810_tc3_hydraulic_positioning/Resources/zip/27021602701686155.zip)

The [MC\_AxUtiStandardInit\_BkPlcMc](ms-xhelp:///?Id=beckhoff-b490-4a55-ac43-76ba1d070d46) function block loads the parameters and monitors the pointer addresses. After the data has been loaded successfully, "bParamsEnable" becomes TRUE and the actual axis blocks are called.

[MC\_AxStandardBody\_BkPlcMc](ms-xhelp:///?Id=beckhoff-1687-4c16-854c-a550eeaaa344) internally calls the required function blocks such as [MC\_AxRtEncoder\_BkPlcMc](ms-xhelp:///?Id=beckhoff-695e-4050-b1c6-c96353e7c191), [MC\_AxRuntime\_BkPlcMc](ms-xhelp:///?Id=beckhoff-992b-440b-b677-39eccb14d862), [MC\_AxRtFinish\_BkPlcMc](ms-xhelp:///?Id=beckhoff-0bc7-4c7a-b544-8f2d601813cd) and [MC\_AxRtDrive\_BkPlcMc](ms-xhelp:///?Id=beckhoff-1548-4af2-9a41-a84b4ffd8e5d). However, if a filter, a pressure regulator, a characteristic curve measurement or similar is required, the individual components must be called instead of [MC\_AxStandardBody\_BkPlcMc](ms-xhelp:///?Id=beckhoff-1687-4c16-854c-a550eeaaa344).  
By using a [MC\_AxAdsCommServer\_BkPlcMc](ms-xhelp:///?Id=beckhoff-5702-45de-80d2-87ae2f7a2a8a) function block the axis can be commanded via the PlcMcManager. The MC\_AxParamDelayedSave\_BkPlcMc function block saves changes made by the PlcMcManager after a given time (here 10 s).  
Via the PlcMcManager you can log onto the target system and actively move the axis.

**Example 2: Multi-axis application**

For TC2: [TcPlcMcEx\_2.zip](https://infosys.beckhoff.com/content/1033/tf5810_tc3_hydraulic_positioning/Resources/zip/27021599364078603.zip)

For TC3: [TC3\_TcPlcMcEx\_2.zip](https://infosys.beckhoff.com/content/1033/tf5810_tc3_hydraulic_positioning/Resources/zip/27021602701688715.zip)

The example illustrates a configuration with arrays of function blocks and structures. The range of functions corresponds to example 1.

**Example 3: Pressure-controlled braking**

For TC2: [TcPlcMcEx\_3.zip](https://infosys.beckhoff.com/content/1033/tf5810_tc3_hydraulic_positioning/Resources/zip/18014400109339787.zip)

For TC3: [TC3\_TcPlcMcEx\_3.zip](https://infosys.beckhoff.com/content/1033/tf5810_tc3_hydraulic_positioning/Resources/zip/27021602701691275.zip)

The example shows how the pressure regulator [MC\_AxCtrlSlowDownOnPressure\_BkPlcMc](ms-xhelp:///?Id=beckhoff-8098-43c1-8159-369473df0437) throttles the feed rate of an axis depending on the pressure. In this example, the controller becomes active when the actual pressure exceeds the set pressure. Since the result is transferred via an application code to "fLagCtrlOutput", the controller must be called after the setpoint generator. Otherwise, fLagCtrlOutput would be overwritten by the position controller in [MC\_AxRuntime\_BkPlcMc](ms-xhelp:///?Id=beckhoff-992b-440b-b677-39eccb14d862).  
If a command is started in the PlcMcManager with a velocity of 100 mm/s and a position of 500 mm, for example, the scope shows that the pressure increases continuously with increasing position. At a position of 400 mm, the system has reached the set pressure of 50 bar and stops.

**Example 5: Move function blocks**

For TC2: [TcPlcMcEx\_5.zip](https://infosys.beckhoff.com/content/1033/tf5810_tc3_hydraulic_positioning/Resources/zip/18014400109341963.zip)

For TC3: [TC3\_TcPlcMcEx\_5.zip](https://infosys.beckhoff.com/content/1033/tf5810_tc3_hydraulic_positioning/Resources/zip/27021602701770635.zip)

In this example, various function blocks are used for motion control. If the variable bStart becomes TRUE, the state machine starts the axis with [MC\_MoveAbsolute\_BkPlcMc](ms-xhelp:///?Id=beckhoff-d937-4450-b853-cb18922787db) to the position 500 mm. When the axis has reached the target and the target window conditions are met (in PosRang, in TargetRange for TargetFilterTime and in BrakeDistance), a [MC\_MoveVelocity\_BkPlcMc](ms-xhelp:///?Id=beckhoff-1c72-400e-b9b3-29017b9cf80f) automatically starts with a velocity of 400 mm/s. This velocity remains active for 5 seconds and is then terminated with [MC\_Stop\_BkPlcMc](ms-xhelp:///?Id=beckhoff-9b19-4599-8840-88fa788b9ed6), so that the axis comes to a standstill. This is followed by a relative movement of 100 mm with [MC\_MoveRelative\_BkPlcMc](ms-xhelp:///?Id=beckhoff-454e-4bc6-98b2-190ee9d324a9) and a move to position 0.0 mm. Different acceleration and deceleration ramps are used in the different motion profiles.

**Example 6: Time ramp generator**

For TC2: [TcPlcMcEx\_6.zip](https://infosys.beckhoff.com/content/1033/tf5810_tc3_hydraulic_positioning/Resources/zip/18014400109344139.zip)

For TC3: [TC3\_TcPlcMcEx\_6.zip](https://infosys.beckhoff.com/content/1033/tf5810_tc3_hydraulic_positioning/Resources/zip/27021602701773195.zip)

An axis without encoder cannot be controlled via the standard setpoint generator. For this type of axis, [iTcMc\_ProfileTimeRamp](ms-xhelp:///?Id=beckhoff-992b-440b-b677-39eccb14d862) provides an alternative setpoint generator. If the variable "bUp" or "bDown" is TRUE in the global variables, the axis moves at the specified velocity (here 500 mm/s) to the first limit switch (DigCamP – for positive/ DigCamM – for negative) and then slows down to the corresponding creep velocity. After reaching DigCamPP – for positive/ DigCamMM – for negative the output is deleted.

**Example 7: Override and function generator**

For TC2: [TcPlcMcEx\_7.zip](https://infosys.beckhoff.com/content/1033/tf5810_tc3_hydraulic_positioning/Resources/zip/18014400109346315.zip)

For TC3: [TC3\_TcPlcMcEx\_7.zip](https://infosys.beckhoff.com/content/1033/tf5810_tc3_hydraulic_positioning/Resources/zip/27021602701775755.zip)

Demonstration of the function block [MC\_SetOverride\_BkPlcMc](ms-xhelp:///?Id=beckhoff-48f4-4b85-87d8-d0da4f567cde). Global variables (bOverrideSinusoidal, fOverrideCycleTime, fOverrideMinValue, fOverrideMaxValue) can be used to specify the sequence, the period and the limitations of a signal generator, which modifies the override. Function blocks of type [MC\_FunctionGeneratorFD\_BkPlcMc](ms-xhelp:///?Id=beckhoff-c220-4046-af00-f126004a753d), [MC\_FunctionGeneratorTB\_BkPlcMc](ms-xhelp:///?Id=beckhoff-fa42-43f7-96f2-1438c3255a9d) and [MC\_FunctionGeneratorSetFrq\_BkPlcMc](ms-xhelp:///?Id=beckhoff-b325-4204-a66a-f21961dd38a2) are used for generating the override.

**Example 8: Digital cam controller**

For TC2: [TcPlcMcEx\_8.zip](https://infosys.beckhoff.com/content/1033/tf5810_tc3_hydraulic_positioning/Resources/zip/18014400109348491.zip)

For TC3: [TC3\_TcPlcMcEx\_8.zip](https://infosys.beckhoff.com/content/1033/tf5810_tc3_hydraulic_positioning/Resources/zip/27021602701778315.zip)

The example shows how to control digital cams through an axis and [MC\_DigitalCamSwitch\_BkPlcMc](ms-xhelp:///?Id=beckhoff-f926-4994-ab22-ff25375bcbfc). In the example two cams are activated in [TRACK\_REF\_BkPlcMc](ms-xhelp:///?Id=beckhoff-ee5c-4cd0-a66f-7a08ab2a33b2) (maximum 32). The first cam is activated under three different conditions:  
1. from position -1000 mm to 1000 mm and positive direction  
2. from position 2000 mm to 3000 mm and positive direction  
3. from position 3000 mm to 2500 mm and negative direction  
The second cam has only one condition:  
1. to be active in positive and negative direction for a time of 1.35 s from position 3000 mm.  
In addition to the switching conditions, a cam can also have a switch-on and switch-off delay. For cam 1, the switch-on delay is set to 0.125 s and the switch-off delay is set to 0.250 s. The conditions for switching a cam are specified in [CAMSWITCH\_REF\_BkPlcMc](ms-xhelp:///?Id=beckhoff-f33f-4253-9407-ea045cafcc25). The output of a cam is specified in [OUTPUT\_REF\_BkPlcMc](ms-xhelp:///?Id=beckhoff-f9aa-4587-a859-7e05ee8c20f1).  
The axis must be commanded via the PlcMcManger (position greater than 3000 mm).

**Example 9: Joystick**

For TC2: [TcPlcMcEx\_9.zip](https://infosys.beckhoff.com/content/1033/tf5810_tc3_hydraulic_positioning/Resources/zip/18014400109350667.zip)

For TC3: [TC3\_TcPlcMcEx\_9.zip](https://infosys.beckhoff.com/content/1033/tf5810_tc3_hydraulic_positioning/Resources/zip/27021602701780875.zip)

The example demonstrates the use of the function block [MC\_MoveJoySticked\_BkPlcMc](ms-xhelp:///?Id=beckhoff-0ccf-40eb-80de-24ff874ef242). With this function block, the axis is moved in an endless motion at a velocity specified by JoyStick. Joystick is a normalized value between +/-1.0, which, multiplied by the commanded velocity, results in the set velocity.

**Example 10: Identification and linearization**

For TC2: [TcPlcMcEx\_10.zip](https://infosys.beckhoff.com/content/1033/tf5810_tc3_hydraulic_positioning/Resources/zip/18014400109352843.zip)

For TC3: [TC3\_TcPlcMcEx\_10.zip](https://infosys.beckhoff.com/content/1033/tf5810_tc3_hydraulic_positioning/Resources/zip/27021602701834635.zip)

The example describes the automatic characteristic curve measurement with [MC\_AxUtiAutoIdent\_BkPlcMc](ms-xhelp:///?Id=beckhoff-6e26-4519-a6b1-d0581db76054) and the use of the characteristic curve with [MC\_AxRtFinishLinear\_BkPlcMc](ms-xhelp:///?Id=beckhoff-e15e-40cb-b1bb-32215a440336). The settings for the automatic characteristic curve measurement are accessible in the PlcMcManger under the **LinDef** tab and can be found in the structure [ST\_TcMcAutoIdent](ms-xhelp:///?Id=beckhoff-d8cd-4957-b2b8-b8cd53f4d9b3).   
In the example, you can choose between three different valve simulations using the global variable nTest. A suitable *.dat* file is loaded according to the selected simulation. The parameters for the characteristic curve measurement are preset in the *.dat* file as required. Caution: If nTest is switched while the PLC is running, the PlcMcManager must be reconnected. The following scenarios can be selected via nTest:

1. Only the overlap and velocity ratio is missing
2. A zero overlap characteristic curve with bend is missing
3. A characteristic curve with overlap is missing

The variable "bStartAuto" can be used to start [MC\_AxUtiAutoIdent\_BkPlcMc](ms-xhelp:///?Id=beckhoff-6e26-4519-a6b1-d0581db76054). During the measurement the function block returns Busy, and the already measured characteristic curve is displayed on the **LinTab** tab.  
If the measurement was successful, the characteristic curve can be used by the function block [MC\_AxRtFinishLinear\_BkPlcMc](ms-xhelp:///?Id=beckhoff-e15e-40cb-b1bb-32215a440336). The characteristic curve is automatically saved and loaded in the *.dat* file of the axis. The function block [MC\_AxTableToAsciFile\_BkPlcMc](ms-xhelp:///?Id=beckhoff-ecf8-4658-8c8f-76a3e16c1b2a) is available for exporting the characteristic curve in an ASCII-readable format.

**Example 11: Stop function blocks**

For TC2: [TcPlcMcEx\_11.zip](https://infosys.beckhoff.com/content/1033/tf5810_tc3_hydraulic_positioning/Resources/zip/18014400109355019.zip)

For TC3: [TC3\_TcPlcMcEx\_11.zip](https://infosys.beckhoff.com/content/1033/tf5810_tc3_hydraulic_positioning/Resources/zip/27021602701837195.zip)

The different ways of stopping an axis are compared here. The example can be started by setting the variable bStart to TRUE.

[MC\_Stop\_BkPlcMc](ms-xhelp:///?Id=beckhoff-9b19-4599-8840-88fa788b9ed6): Executes a stop with preset deceleration parameters. The axis reports ready when the calculated target including target tolerances (in PosRange, in TargetRange for target filter time and in BrakeDistance) has been reached.

[MC\_EmergencyStop\_BkPlcMc](ms-xhelp:///?Id=beckhoff-b20e-4907-bca3-7e0069a79051): Brakes with preset ramp to standstill.

[MC\_ImediateStop\_BkPlcMc](ms-xhelp:///?Id=beckhoff-a719-4119-90f6-ffe5dfef2115): Sets the set value to zero without ramp.

**Example 12: Buffering and blending**

For TC2: [TcPlcMcEx\_12.zip](https://infosys.beckhoff.com/content/1033/tf5810_tc3_hydraulic_positioning/Resources/zip/18014400109357195.zip)

For TC3: [TC3\_TcPlcMcEx\_12.zip](https://infosys.beckhoff.com/content/1033/tf5810_tc3_hydraulic_positioning/Resources/zip/27021602701839755.zip)

The basic procedure for buffered movements is explained in [FAQ 20](ms-xhelp:///?Id=beckhoff-18b7-49ad-a855-a0509f58bddd). To start the example, the variable bStart must become TRUE. The Scope View shows that there are six movements, which are processed in coupled mode.

**Example 13: Filter**

For TC2: [TcPlcMcEx\_13.zip](https://infosys.beckhoff.com/content/1033/tf5810_tc3_hydraulic_positioning/Resources/zip/18014400109359371.zip)

For TC3: [TC3\_TcPlcMcEx\_13.zip](https://infosys.beckhoff.com/content/1033/tf5810_tc3_hydraulic_positioning/Resources/zip/27021602701842315.zip)

The example shows the behavior of several filter types and what to consider when using filters.   
If all signals with the name "Noisy" are switched off in Scope View, the original signal and the filtered signals can be seen with corresponding offsets. The shape of the signal is retained. The more a signal is filtered, the stronger the phase shift between the original and filtered signal. This phase shift has a direct influence on the controllability of axes and other sections.  
If the noisy signals are made visible in the Scope, it can be seen that the noise portion in the signal is considerably lower both through a [MC\_AxUtiSlidingAverage\_BkPlcMc](ms-xhelp:///?Id=beckhoff-7904-4049-b398-bf5aabb72e13) and after a [MC\_AxUtiPT1\_BkPlcMc](ms-xhelp:///?Id=beckhoff-b2b4-4b5a-8b30-ef234e33b238).

**Example 14: Function generator**

For TC2: [TcPlcMcEx\_14.zip](https://infosys.beckhoff.com/content/1033/tf5810_tc3_hydraulic_positioning/Resources/zip/18014400109361547.zip)

For TC3: [TC3\_TcPlcMcEx\_14.zip](https://infosys.beckhoff.com/content/1033/tf5810_tc3_hydraulic_positioning/Resources/zip/27021602701844875.zip)

In some applications, a setpoint generator is required to generate sinusoidal, trapezoidal or sawtooth signals. For example, the signals generated with [MC\_FunctionGeneratorTB\_BkPlcMc](ms-xhelp:///?Id=beckhoff-fa42-43f7-96f2-1438c3255a9d) and [MC\_FunctionGeneratorFD\_BkPlcMc](ms-xhelp:///?Id=beckhoff-c220-4046-af00-f126004a753d) can be transferred to an axis via [MC\_AxRtSetExtGenValues\_BkPlcMc](ms-xhelp:///?Id=beckhoff-47ec-4355-83da-221f9f967897).

**Example 15: Pressure regulator**

For TC2: [TcPlcMcEx\_15.zip](https://infosys.beckhoff.com/content/1033/tf5810_tc3_hydraulic_positioning/Resources/zip/18014400109363723.zip)

For TC3: [TC3\_TcPlcMcEx\_15.zip](https://infosys.beckhoff.com/content/1033/tf5810_tc3_hydraulic_positioning/Resources/zip/27021602701847435.zip)

The example shows the reading and scaling of an actual pressure value in the application. A pressure control for an axis with [MC\_AxCtrlPressure\_BkPlcMc](ms-xhelp:///?Id=beckhoff-6561-479c-a264-3883abee8510) is demonstrated.  
The application first moves to a position at which a pressure increase is expected via a fast movement. The movement continues at a slower velocity and the controller is activated when the set pressure has been reached.

**Example 16: Distributed axis references**

For TC2: [TcPlcMcEx\_16.zip](https://infosys.beckhoff.com/content/1033/tf5810_tc3_hydraulic_positioning/Resources/zip/18014400109365899.zip)

For TC3: [TC3\_TcPlcMcEx\_16.zip](https://infosys.beckhoff.com/content/1033/tf5810_tc3_hydraulic_positioning/Resources/zip/27021602701849995.zip)

The example shows the use of a list of POINTER TO Axis\_Ref\_BkPlcMc. The use of [MC\_AxAdsPtrArrCommServer\_BkPlcMc](ms-xhelp:///?Id=beckhoff-456f-4146-aa13-7032608b0a05) instead of [MC\_AxAdsCommServer\_BkPlcMc](ms-xhelp:///?Id=beckhoff-5702-45de-80d2-87ae2f7a2a8a) makes it possible to distribute the axis references.

The list must be updated in each cycle. This update must be carried out before calling [MC\_AxAdsPtrArrCommServer\_BkPlcMc](ms-xhelp:///?Id=beckhoff-456f-4146-aa13-7032608b0a05).

**Sample 17: External setpoint generation**

For TC2: [TcPlcMcEx\_17.zip](https://infosys.beckhoff.com/content/1033/tf5810_tc3_hydraulic_positioning/Resources/zip/18014404916506123.zip)

For TC3: [TC3\_TcPlcMcEx\_17.zip](https://infosys.beckhoff.com/content/1033/tf5810_tc3_hydraulic_positioning/Resources/zip/9326778891.zip)

The simple sample shows the basic use of a function block of the type [MC\_AxRtSetGenValues](ms-xhelp:///?Id=beckhoff-47ec-4355-83da-221f9f967897).

**Example 18: Locking PlcMcManager**

For TC2: [TcPlcMcEx\_18.zip](https://infosys.beckhoff.com/content/1033/tf5810_tc3_hydraulic_positioning/Resources/zip/18014400109368075.zip)

For TC3: [TC3\_TcPlcMcEx\_18.zip](https://infosys.beckhoff.com/content/1033/tf5810_tc3_hydraulic_positioning/Resources/zip/27021602701852555.zip)

It may be necessary to disable PlcMcManager commands such as Jog, MoveAbs or Stop. This can be done in the PLC with [MC\_AxRtCommandsLocked\_BkPlcMc](ms-xhelp:///?Id=beckhoff-1784-40af-a48c-fa590068b6d1).

**Sample 19: External setpoint generation**

For TC2: [TcPlcMcEx\_19.zip](https://infosys.beckhoff.com/content/1033/tf5810_tc3_hydraulic_positioning/Resources/zip/9326087819.zip)

For TC3: [TC3\_TcPlcMcEx\_19.zip](https://infosys.beckhoff.com/content/1033/tf5810_tc3_hydraulic_positioning/Resources/zip/9326781195.zip)

Here, a larger project demonstrates the possibilities of the external setpoint generator.

**Example 100: Electronic gearing**

For TC2: [TcPlcMcEx\_100.zip](https://infosys.beckhoff.com/content/1033/tf5810_tc3_hydraulic_positioning/Resources/zip/18014400109370251.zip)

For TC3: [TC3\_TcPlcMcEx\_100.zip](https://infosys.beckhoff.com/content/1033/tf5810_tc3_hydraulic_positioning/Resources/zip/27021602701886603.zip)

The example shows how two slave axes can be coupled by an electronic gearing via a master axis (axis 3). The coupling is created and released by [MC\_GearIn\_BkPlcMc](ms-xhelp:///?Id=beckhoff-4041-4933-b290-4cbdc9cd7d51) and [MC\_GearOut\_BkPlcMc](ms-xhelp:///?Id=beckhoff-f42f-49a2-831a-c7c89ada8df9).  
It must be ensured that the dynamic parameters of the master and slave are compatible with each other, otherwise the slave cannot follow the master.  
To establish the coupling, the master and slave must be in idle state. The coupling can be released during the motion. The master axis moves to the target and the slave axis is stopped when the coupling is released.

**Example 101: Electronic cam plate**

For TC2: [TcPlcMcEx\_101.zip](https://infosys.beckhoff.com/content/1033/tf5810_tc3_hydraulic_positioning/Resources/zip/18014400109372427.zip)

For TC3: [TC3\_TcPlcMcEx\_101.zip](https://infosys.beckhoff.com/content/1033/tf5810_tc3_hydraulic_positioning/Resources/zip/27021602701889163.zip)

Axes 1 and 2 are coupled to virtual axis 3 via a cam plate. In this example, the coupling parameters for axis 1 are stored in the text file *TcPlcMcEx\_101\_2.txt*. For axis 2, the coupling parameters are calculated in function block "FB\_CalculateCamTable2". [MC\_CamTableSelect\_BkPlcMc](ms-xhelp:///?Id=beckhoff-af26-44f2-901d-1b7a99b37e87) is used to specify the master and slave axis and the cam table. In function block [MC\_CamIn\_BkPlcMc](ms-xhelp:///?Id=beckhoff-f22a-44e5-b98f-a23a18918289) the coupling is generated and the set values for the slave are calculated. If the master axis is moved via the PlcMcManager, the slave axis follows the corresponding cam plate. The coupling is canceled with [MC\_CamOut\_BkPlcMc](ms-xhelp:///?Id=beckhoff-f9e2-45c8-b5d2-c0ebfc965ddd).

**Example 103: Flying gear coupling**

For TC2: [TcPlcMcEx\_103.zip](https://infosys.beckhoff.com/content/1033/tf5810_tc3_hydraulic_positioning/Resources/zip/18014400109374603.zip)

For TC3: [TC3\_TcPlcMcEx\_103.zip](https://infosys.beckhoff.com/content/1033/tf5810_tc3_hydraulic_positioning/Resources/zip/27021602701891723.zip)

Demonstration of an activated flying gear coupling with function blocks [MC\_GearInPos\_BkPlcMc](ms-xhelp:///?Id=beckhoff-cc38-448a-9d02-eed0b69f60f4) and [MC\_GearOut\_BkPlcMc](ms-xhelp:///?Id=beckhoff-f42f-49a2-831a-c7c89ada8df9).

**Example 104: Synchronization control**

For TC2: [TcPlcMcEx\_104.zip](https://infosys.beckhoff.com/content/1033/tf5810_tc3_hydraulic_positioning/Resources/zip/18014400109376779.zip)

For TC3: [TC3\_TcPlcMcEx\_104.zip](https://infosys.beckhoff.com/content/1033/tf5810_tc3_hydraulic_positioning/Resources/zip/27021602701894283.zip)

Demonstration of a synchronization control for a two-axis gantry using a virtual master. Synchronization control is always used where two or more axes have to be controlled in a balanced manner. A virtual master axis is used for generating the set values. The set values are distributed to the slave axes, which add their local position controller. For example, the current position of the virtual master axis is calculated as an average value over the slave axes.  
In order to ensure smooth commissioning, it is essential that certain parameters are kept the same. This applies in some cases within the group of slave axes, partly also for the master axis. In "FB\_Parameter" this is forced by cyclic copying.

**Example 105: Linearization for synchronization control**

For TC2: [TcPlcMcEx\_105.zip](https://infosys.beckhoff.com/content/1033/tf5810_tc3_hydraulic_positioning/Resources/zip/18014400109378955.zip)

For TC3: [TC3\_TcPlcMcEx\_105.zip](https://infosys.beckhoff.com/content/1033/tf5810_tc3_hydraulic_positioning/Resources/zip/27021602701896843.zip)

This example demonstrates the characteristic curve determination for a two-axis gantry (see also example 104) with the function blocks [MC\_AxUtiAutoIdent\_BkPlcMc](ms-xhelp:///?Id=beckhoff-6e26-4519-a6b1-d0581db76054) and MC\_AxUtiAutoIdentSlave\_BkPlcMc.

**Sample 106: Flying coupling**

For TC2: [TcPlcMc\_106.zip](https://infosys.beckhoff.com/content/1033/tf5810_tc3_hydraulic_positioning/Resources/zip/9326092427.zip)

For TC3: [TC3\_TcPlcMcEx\_106.zip](https://infosys.beckhoff.com/content/1033/tf5810_tc3_hydraulic_positioning/Resources/zip/9326783499.zip)

Some of the possibilities offered by the flying coupling and uncoupling of an electronic gear unit are illustrated here.

[TF5810 | TwinCAT 3 Hydraulic Positioning](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
