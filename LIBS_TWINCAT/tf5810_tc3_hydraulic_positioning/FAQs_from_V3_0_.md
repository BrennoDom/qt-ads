# FAQs (from V3.0)

## Library
tf5810_tc3_hydraulic_positioning

## Category
Motion Control

1. [TwinCAT PLC Hydraulics](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
2. [Knowledge Base](ms-xhelp:///?Id=beckhoff-873e-46cd-925a-b9a96eea638e)
3. FAQs (from V3.0)

# FAQs (from V3.0)

Here you will find answers to frequently asked questions.

| Name | Description |
| --- | --- |
| [FAQ #1](ms-xhelp:///?Id=beckhoff-18b7-49ad-a855-a0509f58bddd) | How do I integrate one or more axes into a PLC application? |
| [FAQ #2](ms-xhelp:///?Id=beckhoff-18b7-49ad-a855-a0509f58bddd) | What data has to be created in the PLC application for the axes? |
| [FAQ #3](ms-xhelp:///?Id=beckhoff-18b7-49ad-a855-a0509f58bddd) | How do I initialize the data and load the parameters for an axis when the PLC starts? |
| [FAQ #4](ms-xhelp:///?Id=beckhoff-18b7-49ad-a855-a0509f58bddd) | How is the actual position of the axes determined? |
| [FAQ #5](ms-xhelp:///?Id=beckhoff-18b7-49ad-a855-a0509f58bddd) | How is the control value for an axis created? |
| [FAQ #6](ms-xhelp:///?Id=beckhoff-18b7-49ad-a855-a0509f58bddd) | How is the control value for an axis prepared for output? |
| [FAQ #7](ms-xhelp:///?Id=beckhoff-18b7-49ad-a855-a0509f58bddd) | How is the control value output to an axis? |
| [FAQ #8](ms-xhelp:///?Id=beckhoff-18b7-49ad-a855-a0509f58bddd) | In what order should the function blocks of an axis be called? |
| [FAQ #9](ms-xhelp:///?Id=beckhoff-18b7-49ad-a855-a0509f58bddd) | How do I control a valve output stage (on-board or externally)? |
| [FAQ #10](ms-xhelp:///?Id=beckhoff-18b7-49ad-a855-a0509f58bddd) | How do I create a message buffer? |
| [FAQ #11](ms-xhelp:///?Id=beckhoff-18b7-49ad-a855-a0509f58bddd) | How do I abort monitoring of a function? |
| [FAQ #12](ms-xhelp:///?Id=beckhoff-18b7-49ad-a855-a0509f58bddd) | How do I monitor the communication with an I/O device? |
| [FAQ #13](ms-xhelp:///?Id=beckhoff-18b7-49ad-a855-a0509f58bddd) | How do I assign my own labels to customer-specific axis parameters? |
| [FAQ #14](ms-xhelp:///?Id=beckhoff-18b7-49ad-a855-a0509f58bddd) | How do I control a current valve? |
| [FAQ #15](ms-xhelp:///?Id=beckhoff-18b7-49ad-a855-a0509f58bddd) | Which axis variables should be logged with the Scope? |
| [FAQ #16](ms-xhelp:///?Id=beckhoff-18b7-49ad-a855-a0509f58bddd) | What is the purpose of the variable nDebugTag in Axis\_Ref\_BkPlcMc? |
| [FAQ #17](ms-xhelp:///?Id=beckhoff-18b7-49ad-a855-a0509f58bddd) | What has to be taken into account when Sercos drives are used? |
| [FAQ #18](ms-xhelp:///?Id=beckhoff-18b7-49ad-a855-a0509f58bddd) | How is a pressure or a force determined? |
| [FAQ #19](ms-xhelp:///?Id=beckhoff-18b7-49ad-a855-a0509f58bddd) | What has to be taken into account when AX5000 drives are used? |
| [FAQ #20](ms-xhelp:///?Id=beckhoff-18b7-49ad-a855-a0509f58bddd) | How do I prepare an axis for blending based on PLC Open? |
| [FAQ #21](ms-xhelp:///?Id=beckhoff-18b7-49ad-a855-a0509f58bddd) | How can I access registers of a terminal, to which an encoder or a valve of an axis is connected? |
| [FAQ #22](ms-xhelp:///?Id=beckhoff-18b7-49ad-a855-a0509f58bddd) | What is the structure of an ASCII file for a linearization table? |
| [FAQ #23](ms-xhelp:///?Id=beckhoff-18b7-49ad-a855-a0509f58bddd) | How can PlcMcManager commands be blocked? |
| [FAQ #24](ms-xhelp:///?Id=beckhoff-18b7-49ad-a855-a0509f58bddd) | What format do import/export files with characteristic curve data have? |
| Setup | How is operation of the axis begun, and how is it optimized? |

## FAQ #1 How do I integrate one or more axes into a PLC application?

The procedure here differs fundamentally from an axis guided by the NC task, because in this case everything done by the NC task is performed by the PLC. Ready-made function blocks are, however, available in most areas, so that the additional programming effort is held within reasonable limits. The following particular points must be considered:

* Axis data in the PLC application ([FAQ #2](ms-xhelp:///?Id=beckhoff-18b7-49ad-a855-a0509f58bddd))
* Initializing and loading the axis parameters when starting the PLC application ([FAQ #3](ms-xhelp:///?Id=beckhoff-18b7-49ad-a855-a0509f58bddd))
* Acquisition of actual values ([FAQ #4](ms-xhelp:///?Id=beckhoff-18b7-49ad-a855-a0509f58bddd))
* Generating control values ([FAQ #5](ms-xhelp:///?Id=beckhoff-18b7-49ad-a855-a0509f58bddd))
* Processing control values in preparation for output ([FAQ #6](ms-xhelp:///?Id=beckhoff-18b7-49ad-a855-a0509f58bddd))
* Setting up the axes (Setup)
* Commissioning of actual pressure determination with function blocks of type [MC\_AxRtReadPressureSingle\_BkPlcMc](ms-xhelp:///?Id=beckhoff-6b58-42dd-9f28-b93f3336f1ca) or [MC\_AxRtReadPressureDiff\_BkPlcMc](ms-xhelp:///?Id=beckhoff-56dc-4d1a-b49b-0b7b2af8cf24).
* Organization of the procedure for movement ([FAQ #7](ms-xhelp:///?Id=beckhoff-18b7-49ad-a855-a0509f58bddd))

|  |  |
| --- | --- |
| 13608105 | If only the usual blocks (encoder, generator, finish, drive) for the axis are to be called, a block of type MC\_AxStandardBody\_BkPlcMc should be used for simplicity. |

## FAQ #2 What data has to be created in the PLC application for the axes?

For each axis, one variables of each type [Axis\_Ref\_BkPlcMc](ms-xhelp:///?Id=beckhoff-002b-4aba-81ea-1693fb03013c), [ST\_TcPlcDeviceInput](ms-xhelp:///?Id=beckhoff-dec6-4dd6-a155-f200065a8d2d) and [ST\_TcPlcDeviceOutput](ms-xhelp:///?Id=beckhoff-fec4-45f2-b458-d8180069b32f) has to be created. The use of variable fields is highly recommended for multiple axes. Examples for one and five axes can be found in the first sample programs.

The procedure using [MC\_AxUtiStandardInit\_BkPlcMc](ms-xhelp:///?Id=beckhoff-b490-4a55-ac43-76ba1d070d46) function blocks shown in these examples ensures correct initialization on start-up of the PLC and initiates loading of the axis parameters from files.

Further data are required for realizing message logging. See also [FAQ #10](ms-xhelp:///?Id=beckhoff-18b7-49ad-a855-a0509f58bddd).

Further data are required for assigning one's own IDs to customer-specific axis parameters in the PlcMcManager. See also [FAQ #13](ms-xhelp:///?Id=beckhoff-18b7-49ad-a855-a0509f58bddd)

Further data are required in order to utilize blending according to PLC Open. See also [FAQ #20](ms-xhelp:///?Id=beckhoff-18b7-49ad-a855-a0509f58bddd).

## FAQ #3 How do I initialize the data for an axis?

A number of initializations must be carried out when the PLC applications starts. This is best done in three stages, which are provided by an [MC\_AxUtiStandardInit\_BkPlcMc](ms-xhelp:///?Id=beckhoff-b490-4a55-ac43-76ba1d070d46) function block and should only be realized directly by the application in special cases. They are described here only for the sake of completeness.

1. A number of pointers must be correctly set up to link the components of the axes together. This task should be solved with a function block of type [MC\_AxUtiStandardInit\_BkPlcMc](ms-xhelp:///?Id=beckhoff-b490-4a55-ac43-76ba1d070d46), which detects a shift or change in size in the memory or the change of a type code during a subsequent online change and then ensures that the pointers are reinitialised and the parameters are reloaded.
2. The parameters for the axis must be appropriately set. Although it would be technically possible for the application to do have these assignments hard-coded, this is not usually helpful. It is preferable to save the settings in files, which are loaded on system startup under control of the application through the [MC\_AxUtiStandardInit\_BkPlcMc](ms-xhelp:///?Id=beckhoff-b490-4a55-ac43-76ba1d070d46) function block. Notes on setting up an axis can be found under Setup.
3. The task cycle time should be applied in the axis parameters. This should be done at the end of the parameter loading procedure, in order to set this value correctly, in view of the fact that it is important for the function of many function blocks. An [MC\_AxUtiStandardInit\_BkPlcMc](ms-xhelp:///?Id=beckhoff-b490-4a55-ac43-76ba1d070d46) function block deals with this task automatically.

|  |  |
| --- | --- |
| 55364084 | If a function block of type MC\_AxAdsCommServer\_BkPlcMc is used in the application, the function block must be called in the same task that carries out the pointer assignments. If this is not possible, or for some reason difficult, then calling the function block must be prevented while the assignments are being carried out. The result, otherwise, can be that the PLC application crashes as a result of serious runtime errors (Page Fault Exception). |

|  |  |
| --- | --- |
| 28514710 | All activities listed here should through be realized and coordinated by an MC\_AxUtiStandardInit\_BkPlcMc function block. If the nInitState variable in Axis\_Ref\_BkPlcMc of the axis adopts either the value 2 or -2, then the initialization has been successful or has ended with an error. If the initialization is successful, MC\_AxUtiStandardInit\_BkPlcMc.Ready and bParamsEnable in Axis\_Ref\_BkPlcMc are TRUE, otherwise this variable remains FALSE. |

|  |  |
| --- | --- |
| 55305800 | The sample programs provided specify the name of the axis and the name (included the path) of the corresponding parameter file. It is essential that these specifications are modified to match the particular application. |

## FAQ #4: How is the actual position of the axes determined?

A range of signal transducers may be considered for use as position sensors, operating according to a variety of physical principles to generate a position-dependent electrical magnitude. This magnitude determines the type of I/O components that must be used. The variables of types [ST\_TcPlcDeviceInput](ms-xhelp:///?Id=beckhoff-dec6-4dd6-a155-f200065a8d2d) and [ST\_TcPlcDeviceOutput](ms-xhelp:///?Id=beckhoff-fec4-45f2-b458-d8180069b32f) must be created for each axis, and contain elements that are to be linked to the actual value, counter, latch, control and status variables associated with the I/O hardware.

Here are a few examples:

| I/O component | Signal | Encoder Type |
| --- | --- | --- |
| AX2000 B110 with absolute encoder | EtherCAT | [iTcMc\_EncoderAx2000\_B110A](ms-xhelp:///?Id=beckhoff-695e-4050-b1c6-c96353e7c191) |
| AX2000 B110 with resolver | EtherCAT | [iTcMc\_EncoderAx2000\_B110R](ms-xhelp:///?Id=beckhoff-1548-4af2-9a41-a84b4ffd8e5d) |
| AX2000 B200 with resolver | EtherCAT | [iTcMc\_EncoderAx2000\_B200R](ms-xhelp:///?Id=beckhoff-1548-4af2-9a41-a84b4ffd8e5d) |
| AX2000 B750 with absolute encoder | EtherCAT | [iTcMc\_EncoderAx2000\_B750A](ms-xhelp:///?Id=beckhoff-695e-4050-b1c6-c96353e7c191) |
| AX2000 B900 with resolver | EtherCAT | [iTcMc\_EncoderAx2000\_B900R](ms-xhelp:///?Id=beckhoff-1548-4af2-9a41-a84b4ffd8e5d) |
| AX5000 B110 with multi-turn absolute encoder | EtherCAT | [iTcMc\_EncoderAX5000\_B110A](ms-xhelp:///?Id=beckhoff-695e-4050-b1c6-c96353e7c191) |
| EtherCAT servo controllers with CoE DS402 support and  multi-turn encoder | EtherCAT | [iTcMc\_EncoderCoE\_DS402A](ms-xhelp:///?Id=beckhoff-695e-4050-b1c6-c96353e7c191) |
| EtherCAT servo controllers with CoE DS402 support and resolver or single-turn encoder | EtherCAT | [iTcMc\_EncoderCoE\_DS402SR](ms-xhelp:///?Id=beckhoff-695e-4050-b1c6-c96353e7c191) |
| EL3102 | -10V .. 10V | [iTcMc\_EncoderEL3102](ms-xhelp:///?Id=beckhoff-695e-4050-b1c6-c96353e7c191) |
| EL3142 | 0mA .. 20mA | [iTcMc\_EncoderEL3142](ms-xhelp:///?Id=beckhoff-695e-4050-b1c6-c96353e7c191) |
| EL3162 | 0 .. 10V | [iTcMc\_EncoderEL3162](ms-xhelp:///?Id=beckhoff-695e-4050-b1c6-c96353e7c191) |
| EL3255 | Potentiometric displacement transducer | [iTcMc\_EncoderEL3162](ms-xhelp:///?Id=beckhoff-695e-4050-b1c6-c96353e7c191) |
| EL5001 | SSI | [iTcMc\_EncoderEL5001](ms-xhelp:///?Id=beckhoff-695e-4050-b1c6-c96353e7c191) |
| EL5101 | A/B increments, RS422="TTL" | [iTcMc\_EncoderEL5101](ms-xhelp:///?Id=beckhoff-695e-4050-b1c6-c96353e7c191) |
| EL7041 | A/B increments, RS422="TTL" | [iTcMc\_EncoderEL7041](ms-xhelp:///?Id=beckhoff-695e-4050-b1c6-c96353e7c191) |
| EtherCAT encoder with CoE\_DS406 profile | EtherCAT | [iTcMc\_EncoderCoE\_DS406](ms-xhelp:///?Id=beckhoff-695e-4050-b1c6-c96353e7c191) |
| IE5009 | SSI | [iTcMc\_EncoderIx5009](ms-xhelp:///?Id=beckhoff-695e-4050-b1c6-c96353e7c191) |
| IP5009 | SSI | [iTcMc\_EncoderIx5009](ms-xhelp:///?Id=beckhoff-695e-4050-b1c6-c96353e7c191) |
| KL10xx | 2 bit, A/B increments | [iTcMc\_EncoderDigIncrement](ms-xhelp:///?Id=beckhoff-695e-4050-b1c6-c96353e7c191) |
| KL11xx | 2 bit, A/B increments | [iTcMc\_EncoderDigIncrement](ms-xhelp:///?Id=beckhoff-695e-4050-b1c6-c96353e7c191) |
| KL12xx | 2 bit, A/B increments | [iTcMc\_EncoderDigIncrement](ms-xhelp:///?Id=beckhoff-695e-4050-b1c6-c96353e7c191) |
| KL13xx | 2 bit, A/B increments | [iTcMc\_EncoderDigIncrement](ms-xhelp:///?Id=beckhoff-695e-4050-b1c6-c96353e7c191) |
| KL14xx | 2 bit, A/B increments | [iTcMc\_EncoderDigIncrement](ms-xhelp:///?Id=beckhoff-695e-4050-b1c6-c96353e7c191) |
| KL17xx | 2 bit, A/B increments | [iTcMc\_EncoderDigIncrement](ms-xhelp:///?Id=beckhoff-695e-4050-b1c6-c96353e7c191) |
| KL10xx | 4 bit, position cams | [iTcMc\_EncoderDigCam](ms-xhelp:///?Id=beckhoff-695e-4050-b1c6-c96353e7c191) |
| KL11xx | 4 bit, position cams | [iTcMc\_EncoderDigCam](ms-xhelp:///?Id=beckhoff-695e-4050-b1c6-c96353e7c191) |
| KL12xx | 4 bit, position cams | [iTcMc\_EncoderDigCam](ms-xhelp:///?Id=beckhoff-695e-4050-b1c6-c96353e7c191) |
| KL13xx | 4 bit, position cams | [iTcMc\_EncoderDigCam](ms-xhelp:///?Id=beckhoff-695e-4050-b1c6-c96353e7c191) |
| KL14xx | 4 bit, position cams | [iTcMc\_EncoderDigCam](ms-xhelp:///?Id=beckhoff-695e-4050-b1c6-c96353e7c191) |
| KL17xx | 4 bit, position cams | [iTcMc\_EncoderDigCam](ms-xhelp:///?Id=beckhoff-695e-4050-b1c6-c96353e7c191) |
| KL2521 | Pulse Train | [iTcMc\_EncoderKL2521](ms-xhelp:///?Id=beckhoff-695e-4050-b1c6-c96353e7c191) |
| KL2531 | Stepper motor, direct (encoder emulated through pulse counter) | [iTcMc\_EncoderKL2531](ms-xhelp:///?Id=beckhoff-695e-4050-b1c6-c96353e7c191) |
| KL2541 | Stepper motor, direct (with encoder or encoder emulates through pulse counter) | [iTcMc\_EncoderKL2541](ms-xhelp:///?Id=beckhoff-695e-4050-b1c6-c96353e7c191) |
| KL2542 | DC motor, direct with encoder | [iTcMc\_EncoderKL2542](ms-xhelp:///?Id=beckhoff-695e-4050-b1c6-c96353e7c191) |
| KL3001 | -10V .. 10V | [iTcMc\_EncoderKL3002](ms-xhelp:///?Id=beckhoff-695e-4050-b1c6-c96353e7c191) |
| KL3002 | -10V .. 10V | [iTcMc\_EncoderKL3002](ms-xhelp:///?Id=beckhoff-695e-4050-b1c6-c96353e7c191) |
| KL3011 | 0mA .. 20mA | [iTcMc\_EncoderKL3042](ms-xhelp:///?Id=beckhoff-695e-4050-b1c6-c96353e7c191) |
| KL3012 | 0mA .. 20mA | [iTcMc\_EncoderKL3042](ms-xhelp:///?Id=beckhoff-695e-4050-b1c6-c96353e7c191) |
| KL3021 | 4mA .. 20mA | [iTcMc\_EncoderKL3042](ms-xhelp:///?Id=beckhoff-695e-4050-b1c6-c96353e7c191) |
| KL3022 | 4mA .. 20mA | [iTcMc\_EncoderKL3042](ms-xhelp:///?Id=beckhoff-695e-4050-b1c6-c96353e7c191) |
| KL3041 | 0mA .. 20mA | [iTcMc\_EncoderKL3042](ms-xhelp:///?Id=beckhoff-695e-4050-b1c6-c96353e7c191) |
| KL3042 | 0mA .. 20mA | [iTcMc\_EncoderKL3042](ms-xhelp:///?Id=beckhoff-695e-4050-b1c6-c96353e7c191) |
| KL3044 | 0mA .. 20mA | [iTcMc\_EncoderKL3042](ms-xhelp:///?Id=beckhoff-695e-4050-b1c6-c96353e7c191) |
| KL3051 | 4mA .. 20mA | [iTcMc\_EncoderKL3042](ms-xhelp:///?Id=beckhoff-695e-4050-b1c6-c96353e7c191) |
| KL3052 | 4mA .. 20mA | [iTcMc\_EncoderKL3042](ms-xhelp:///?Id=beckhoff-695e-4050-b1c6-c96353e7c191) |
| KL3054 | 4mA .. 20mA | [iTcMc\_EncoderKL3042](ms-xhelp:///?Id=beckhoff-695e-4050-b1c6-c96353e7c191) |
| KL3061 | 0V .. 10V | [iTcMc\_EncoderKL3062](ms-xhelp:///?Id=beckhoff-695e-4050-b1c6-c96353e7c191) |
| KL3062 | 0V .. 10V | [iTcMc\_EncoderKL3062](ms-xhelp:///?Id=beckhoff-695e-4050-b1c6-c96353e7c191) |
| KL3064 | 0V .. 10V | [iTcMc\_EncoderKL3062](ms-xhelp:///?Id=beckhoff-695e-4050-b1c6-c96353e7c191) |
| KL3162 | 0V .. 10V | [iTcMc\_EncoderKL3162](ms-xhelp:///?Id=beckhoff-695e-4050-b1c6-c96353e7c191) |
| KL5001 | SSI | [iTcMc\_EncoderKL5001](ms-xhelp:///?Id=beckhoff-695e-4050-b1c6-c96353e7c191) |
| KL5101 | A/B increments, RS422="TTL" | [iTcMc\_EncoderKL5101](ms-xhelp:///?Id=beckhoff-695e-4050-b1c6-c96353e7c191) |
| KL5111 | A/B increments, RS422="HTL" | [iTcMc\_EncoderKL5111](ms-xhelp:///?Id=beckhoff-695e-4050-b1c6-c96353e7c191) |
| M2510 | -10V .. 10V | [iTcMc\_EncoderM2510](ms-xhelp:///?Id=beckhoff-695e-4050-b1c6-c96353e7c191) |
| M3100 | A/B increments, RS422="TTL" | [iTcMc\_EncoderM3120](ms-xhelp:///?Id=beckhoff-695e-4050-b1c6-c96353e7c191) |
| M3120 | A/B increments, RS422="TTL" | [iTcMc\_EncoderM3120](ms-xhelp:///?Id=beckhoff-695e-4050-b1c6-c96353e7c191) |

If one of the components mentioned here is used, then one of the encoder function blocks provided will usually be applied. The interfaces of these function blocks are not guaranteed and should therefore not be called directly by the application. It is better to set the encoder type according to the constants in [E\_TcMcEncoderType](ms-xhelp:///?Id=beckhoff-1819-4c81-9982-5253100bd275) under nEnc\_Type in [ST\_TcHydAxParam](ms-xhelp:///?Id=beckhoff-12fe-4458-a931-b3c9fca583f2), and to use a function block of type [MC\_AxRtEncoder\_BkPlcMc](ms-xhelp:///?Id=beckhoff-695e-4050-b1c6-c96353e7c191). This then automatically calls the correct type of sub-function-block for the type concerned.

All encoder function blocks use the parameters fEnc\_IncWeighting and fEnc\_IncInterpolation as increment assessment. fEnc\_ZeroShift is also used as a zero shift for absolute displacement sensors. Incremental sensors usually require a reference travel using a [MC\_Home\_BkPlcMc](ms-xhelp:///?Id=beckhoff-1b39-4911-8ef7-a4d128653cfd) function block, during which fEnc\_RefShift in [ST\_TcHydAxRtData](ms-xhelp:///?Id=beckhoff-1ffc-4f72-80ec-3f7c8585d12d) is determined. This value then does the job of the zero shift. It goes without saying that in special cases the zero shift can also be defined with an [MC\_SetPosition\_BkPlcMc](ms-xhelp:///?Id=beckhoff-f65a-4c39-bec9-11940d456eda) function block. The referenced status of the axis should be defined with [MC\_SetReferenceFlag\_BkPlcMc](ms-xhelp:///?Id=beckhoff-a2d5-4fc5-b64a-c2738fc01d65)().

If it is not possible to determine the actual position with function blocks from the library for technical reasons, this task can be handled by application function blocks, and the result can be entered in fActPos, and fActVelo can be entered in [ST\_TcHydAxRtData](ms-xhelp:///?Id=beckhoff-1ffc-4f72-80ec-3f7c8585d12d), if required. For the sake of uniformity use should again be made here of the fEnc\_IncWeighting, fEnc\_IncInterpolation and fEnc\_ZeroShift or fEnc\_RefShift parameters.

|  |  |
| --- | --- |
| 27990155 | If only the usual function blocks (encoder, generator, finish, drive) for the axis are to be called, a function block of type MC\_AxStandardBody\_BkPlcMc should be used for simplicity. |

|  |  |
| --- | --- |
| 50584809 | Commissioning of an actual pressure determination with function blocks of type MC\_AxRtReadPressureSingle\_BkPlcMc or MC\_AxRtReadPressureDiff\_BkPlcMc is described in the documentation for the function block. |

## FAQ #5: How is the control value for an axis created?

In each cycle, the PLC application must call a function block of type [MC\_AxRuntime\_BkPlcMc](ms-xhelp:///?Id=beckhoff-992b-440b-b677-39eccb14d862), or alternatively a suitable controller function block (e.g. a pressure regulator) for each axis. The parameter nProfileType in [ST\_TcHydAxParam](ms-xhelp:///?Id=beckhoff-12fe-4458-a931-b3c9fca583f2) specifies the procedure that is to be used to generate the control value. Velocity control values are calculated here according to the type, and depending on other parameters associated with the axis and on the movement data. These control values are, however, normalized to the abstract numerical range ±1.0, and have not yet been prepared for immediate output to I/O hardware.

|  |  |
| --- | --- |
| 52610097 | If only the usual function blocks (encoder, generator, finish, drive) for the axis are to be called, a function block of type [MC\_AxStandardBody\_BkPlcMc](ms-xhelp:///?Id=beckhoff-1687-4c16-854c-a550eeaaa344) should be used for simplicity. |

## FAQ #6: How is the control value for an axis prepared for output?

After calling the [MC\_AxRuntime\_BkPlcMc](ms-xhelp:///?Id=beckhoff-992b-440b-b677-39eccb14d862) function block, a function block of type [MC\_AxRtFinish\_BkPlcMc](ms-xhelp:///?Id=beckhoff-0bc7-4c7a-b544-8f2d601813cd) must be called for each axis. This function block assembles a number of velocity components (control value, controller output, offset compensation, overlap compensation), and also takes into account in the bends in the feed forward characteristic curve.

Numerical adjustment is usually necessary prior to output to an I/O module. An [MC\_AxRtDrive\_BkPlcMc](ms-xhelp:///?Id=beckhoff-1548-4af2-9a41-a84b4ffd8e5d) function block is to be called for each axis for this purpose. The value of nDrive\_Type in [ST\_TcHydAxParam](ms-xhelp:///?Id=beckhoff-12fe-4458-a931-b3c9fca583f2) selects the hardware-specific sub-function-block to be used.

The variables of types [ST\_TcPlcDeviceInput](ms-xhelp:///?Id=beckhoff-dec6-4dd6-a155-f200065a8d2d) and [ST\_TcPlcDeviceOutput](ms-xhelp:///?Id=beckhoff-fec4-45f2-b458-d8180069b32f) must be created for each axis, and contain elements that are to be linked to the set value and control variables of the I/O hardware.

|  |  |
| --- | --- |
| 3728830 | If only the usual function blocks (encoder, generator, finish, drive) for the axis are to be called, a function block of type [MC\_AxStandardBody\_BkPlcMc](ms-xhelp:///?Id=beckhoff-1687-4c16-854c-a550eeaaa344) should be used for simplicity. |

## FAQ #7: How is the control value output to an axis?

A range of devices and equipment might be functioning as actuators, applying a variety of physical principles to create a variable velocity that depends on an electrical magnitude. This magnitude determines the type of I/O components that must be used. The variables of types [ST\_TcPlcDeviceInput](ms-xhelp:///?Id=beckhoff-dec6-4dd6-a155-f200065a8d2d) and [ST\_TcPlcDeviceOutput](ms-xhelp:///?Id=beckhoff-fec4-45f2-b458-d8180069b32f) must be created for each axis, and contain elements that are to be linked to the variables of the I/O hardware.

Here are a few examples:

| I/O component | Signal | Drive Type |
| --- | --- | --- |
| AX2000 B110 with absolute encoder | EtherCAT | [iTcMc\_DriveAX2000\_B110A](ms-xhelp:///?Id=beckhoff-1548-4af2-9a41-a84b4ffd8e5d) |
| AX2000 B110 with resolver | EtherCAT | [iTcMc\_DriveAX2000\_B110R](ms-xhelp:///?Id=beckhoff-1548-4af2-9a41-a84b4ffd8e5d) |
| AX2000 B200 with resolver | EtherCAT | [iTcMc\_DriveAX2000\_B200R](ms-xhelp:///?Id=beckhoff-1548-4af2-9a41-a84b4ffd8e5d) |
| AX2000 B750 with absolute encoder | EtherCAT | [iTcMc\_DriveAx2000\_B750A](ms-xhelp:///?Id=beckhoff-1548-4af2-9a41-a84b4ffd8e5d) |
| AX2000 B900 with resolver | EtherCAT | [iTcMc\_DriveAX2000\_B900R](ms-xhelp:///?Id=beckhoff-1548-4af2-9a41-a84b4ffd8e5d) |
| AX5000 B110 with absolute encoder | EtherCAT | [iTcMc\_DriveAX5000\_B110A](ms-xhelp:///?Id=beckhoff-1548-4af2-9a41-a84b4ffd8e5d) |
| EtherCAT servo controllers with CoE DS402 support and resolver, single-turn or multi-turn encoder | EtherCAT | [iTcMc\_DriveCoE\_DS402](ms-xhelp:///?Id=beckhoff-1548-4af2-9a41-a84b4ffd8e5d) |
| EtherCAT valve with CoE\_DS408 profile | EtherCAT | [iTcMc\_Drive\_CoE\_DS408](ms-xhelp:///?Id=beckhoff-1548-4af2-9a41-a84b4ffd8e5d) |
| EL2535 | PWM | iTcMc\_DriveEL2535 |
| EL4031, EL4032, EL4034, EL4038  EL4131, EL4132, EL4134 | -10 V .. 10 V | [iTcMc\_DriveEL4132](ms-xhelp:///?Id=beckhoff-1548-4af2-9a41-a84b4ffd8e5d) |
| EL4011, EL4012, EL4014, EL4018,  EL4112 EL4021, EL4022, EL4024, EL4028, EL4122, EL4124 | 0..20 mA    4..20 mA | iTcMc\_DriveEL4x22 |
| EL7031 | Stepper motor, direct | [iTcMc\_DriveEL7031](ms-xhelp:///?Id=beckhoff-1548-4af2-9a41-a84b4ffd8e5d) |
| EL7041 | Stepper motor, direct | [iTcMc\_DriveEL7041](ms-xhelp:///?Id=beckhoff-1548-4af2-9a41-a84b4ffd8e5d) |
| IE2512 | PWM | [iTcMc\_DriveIx2512\_1Coil](ms-xhelp:///?Id=beckhoff-1548-4af2-9a41-a84b4ffd8e5d)  [iTcMc\_DriveIx2512\_2Coil](ms-xhelp:///?Id=beckhoff-1548-4af2-9a41-a84b4ffd8e5d) |
| IP2512 | PWM | [iTcMc\_DriveIx2512\_1Coil](ms-xhelp:///?Id=beckhoff-1548-4af2-9a41-a84b4ffd8e5d)  [iTcMc\_DriveIx2512\_2Coil](ms-xhelp:///?Id=beckhoff-1548-4af2-9a41-a84b4ffd8e5d) |
| KL20xx, KL21xx, KL22xx, KL24xx | 5 bit for operating a frequency converter with fixed frequencies | [iTcMc\_DriveLowCostInverter](ms-xhelp:///?Id=beckhoff-1548-4af2-9a41-a84b4ffd8e5d) |
| KL20xx, KL21xx, KL22xx, KL24xx | 4 bit for operating a voltage-controlled stepper motor | [iTcMc\_DriveLowCostStepper](ms-xhelp:///?Id=beckhoff-1548-4af2-9a41-a84b4ffd8e5d) |
| KL2521 | Pulse Train | [iTcMc\_DriveKL2521](ms-xhelp:///?Id=beckhoff-1548-4af2-9a41-a84b4ffd8e5d) |
| KL2531 | Stepper motor, direct | [iTcMc\_DriveKL2531](ms-xhelp:///?Id=beckhoff-1548-4af2-9a41-a84b4ffd8e5d) |
| KL2532 | DC motor, direct with encoder | [iTcMc\_DriveKL2532](ms-xhelp:///?Id=beckhoff-1548-4af2-9a41-a84b4ffd8e5d) |
| KL2535 | PWM | [iTcMc\_DriveKL2535\_1Coil](ms-xhelp:///?Id=beckhoff-1548-4af2-9a41-a84b4ffd8e5d)  [iTcMc\_DriveKL2535\_2Coil](ms-xhelp:///?Id=beckhoff-1548-4af2-9a41-a84b4ffd8e5d) |
| KL2541 | Stepper motor, direct | [iTcMc\_DriveKL2541](ms-xhelp:///?Id=beckhoff-1548-4af2-9a41-a84b4ffd8e5d) |
| KL2542 | DC motor, direct with encoder | [iTcMc\_DriveKL2542](ms-xhelp:///?Id=beckhoff-1548-4af2-9a41-a84b4ffd8e5d) |
| KL4031 | -10 V .. 10 V | [iTcMc\_DriveKL4032](ms-xhelp:///?Id=beckhoff-1548-4af2-9a41-a84b4ffd8e5d) |
| KL4032 | -10 V .. 10 V | [iTcMc\_DriveKL4032](ms-xhelp:///?Id=beckhoff-1548-4af2-9a41-a84b4ffd8e5d) |
| KL4034 | -10 V .. 10 V | [iTcMc\_DriveKL4032](ms-xhelp:///?Id=beckhoff-1548-4af2-9a41-a84b4ffd8e5d) |
| M2400 | -10 V .. 10 V | [iTcMc\_DriveM2400\_D1](ms-xhelp:///?Id=beckhoff-1548-4af2-9a41-a84b4ffd8e5d), iTcMc\_DriveM2400\_D2, iTcMc\_DriveM2400\_D3, iTcMc\_DriveM2400\_D4 |

If one of the components mentioned here is used, then one of the drive function blocks provided will usually be used. These interfaces of these function blocks are not guaranteed and should therefore not be called directly by the application. It is better to set the drive type according to the constants in [E\_TcMcDriveType](ms-xhelp:///?Id=beckhoff-540a-458a-ab44-3657804f519c) under nDrive\_Type in [ST\_TcHydAxParam](ms-xhelp:///?Id=beckhoff-12fe-4458-a931-b3c9fca583f2), and to use a function block of type [MC\_AxRtDrive\_BkPlcMc](ms-xhelp:///?Id=beckhoff-1548-4af2-9a41-a84b4ffd8e5d).

|  |  |
| --- | --- |
| 33559471 | If only the usual function blocks (encoder, generator, finish, drive) for the axis are to be called, a function block of type [MC\_AxStandardBody\_BkPlcMc](ms-xhelp:///?Id=beckhoff-1687-4c16-854c-a550eeaaa344) should be used for simplicity. |

## FAQ #8: In what order should the function blocks of an axis be called?

1. Obligatory: all function blocks, which detect the actual status of the axis. These include function blocks of types [MC\_AxRtEncoder\_BkPlcMc](ms-xhelp:///?Id=beckhoff-695e-4050-b1c6-c96353e7c191), [MC\_AxRtReadPressureDiff\_BkPlcMc](ms-xhelp:///?Id=beckhoff-56dc-4d1a-b49b-0b7b2af8cf24) or [MC\_AxRtReadPressureSingle\_BkPlcMc](ms-xhelp:///?Id=beckhoff-6b58-42dd-9f28-b93f3336f1ca).
2. Usual: function blocks or commands, which update the enable signals of the axis. This is usually a function block of type [MC\_Power\_BkPlcMc](ms-xhelp:///?Id=beckhoff-f1de-4926-8132-1e2d75ae63fc). For axes with an incremental encoder, which is referenced using a cam, a function call MC\_AxRtSetReferencingCamSignal\_BkPlcMc is used in addition.
3. Optional: Function blocks, which derive a decision or trigger a command based on an actual axis status, an I/O signal or an application signal. For example, an axis start can be triggered in response to the signal of a proximity limit switch, or an axis movement can be stopped before the target position is reached, depending on the pressure increase.
4. Obligatory: Control value generators such as function blocks of type [MC\_AxRuntime\_BkPlcMc](ms-xhelp:///?Id=beckhoff-992b-440b-b677-39eccb14d862).
5. Optional: Various controllers can be called at this point, as required. This can be a function block of type [MC\_AxCtrlSlowDownOnPressure\_BkPlcMc](ms-xhelp:///?Id=beckhoff-8098-43c1-8159-369473df0437) or similar.
6. Obligatory: An adaptation function block of type [MC\_AxRtFinish\_BkPlcMc](ms-xhelp:///?Id=beckhoff-0bc7-4c7a-b544-8f2d601813cd).
7. Optional: If required, a function block for the automatic commissioning can be called at this point.
8. Obligatory: An output function block of type [MC\_AxRtDrive\_BkPlcMc](ms-xhelp:///?Id=beckhoff-1548-4af2-9a41-a84b4ffd8e5d).

Instead of the library function blocks, application function blocks can be used. However, one should check carefully whether this is necessary, in which case compatibility with the library must be ensured. In some applications this may become necessary, in order to adapt a non-standard sensor or actuator, or to solve a special control task.

## FAQ #9: How do I control a valve output stage (on-board or externally)?

The [ST\_TcPlcDeviceOutput](ms-xhelp:///?Id=beckhoff-fec4-45f2-b458-d8180069b32f) structure is intended for the **bPowerOn** and **bEnable** signals and for controlling the output stage supply and activation. Both signals are set by function blocks of type [MC\_Power\_BkPlcMc](ms-xhelp:///?Id=beckhoff-f1de-4926-8132-1e2d75ae63fc), if the input **Enable is set.** At the same time this function block sets the software controller enable in [ST\_TcHydAxRtData](ms-xhelp:///?Id=beckhoff-1ffc-4f72-80ec-3f7c8585d12d).[nDeCtrlDWord](ms-xhelp:///?Id=beckhoff-d319-45ac-96c4-54e861345d4c).

The [ST\_TcPlcDeviceInput](ms-xhelp:///?Id=beckhoff-dec6-4dd6-a155-f200065a8d2d) structure is intended for the signals **bPowerOk, bEnAck** and **bReady** for the output stage supply control, feedback from the output stage activation and the status signal. The differences in the signals provided by different manufacturer can be very significant. **Currently, only the bPowerOk** signal is used for specifying the **Status** output of the [MC\_Power\_BkPlcMc](ms-xhelp:///?Id=beckhoff-f1de-4926-8132-1e2d75ae63fc) function block. If no suitable signal is available, or if no monitoring is to be realised, [ST\_TcHydAxParam](ms-xhelp:///?Id=beckhoff-12fe-4458-a931-b3c9fca583f2).bDrive\_DefaultPowerOk should be set.

## FAQ #10: How do I create a message buffer?

Direct output of messages from the function blocks would result in runtime variations that would be difficult to calculate. For this reason, the messages are stored in a buffer and output in the Windows Event Viewer one after another, if required.

In order to be able to use a message buffer, a variable of type [ST\_TcPlcMcLogBuffer](ms-xhelp:///?Id=beckhoff-2e65-4b91-955d-12cfc3c231b1) must be created. This buffer is used to hold the messages from **all** axes. It is important that only one such variable is created in the project, irrespective of the number of axes. The address of this buffer should be transferred to the [MC\_AxUtiStandardInit\_BkPlcMc](ms-xhelp:///?Id=beckhoff-b490-4a55-ac43-76ba1d070d46) function blocks of all axes, together with the addresses of the other individual axis components. This function blocks are usually called in the initialization part of the project. This address is stored in the element pStAxLogBuffer in the structure [Axis\_Ref\_BkPlcMc](ms-xhelp:///?Id=beckhoff-002b-4aba-81ea-1693fb03013c) and by the function block.

nLogLevel in [Axis\_Ref\_BkPlcMc](ms-xhelp:///?Id=beckhoff-002b-4aba-81ea-1693fb03013c) is used to specify the significance level threshold for storing messages in the buffer. The [values](ms-xhelp:///?Id=beckhoff-d319-45ac-96c4-54e861345d4c) to be used are defined in the global variables of the library. Note that this setting is required for each axis.

The library function blocks detect the preparations mentioned above and will commence issuing messages. However, if the message output is enabled, the buffer would fill up quickly and not accept further messages. There are two ways to avoid this.

## FAQ #10.1: Passing on messages to the Windows Event Viewer

In order to transfer messages from the LogBuffer of the library to the Windows Event Viewer, a function block of type [MC\_AxRtLoggerSpool\_BkPlcMc](ms-xhelp:///?Id=beckhoff-54e4-42b0-8b15-e29767b6b2eb) should be called cyclically. Witch each call a message is removed from the LogBuffer.

|  |  |
| --- | --- |
| 33599791 | Computers running Windows CE are also capable of amending an Event Viewer for the messages created by TwinCAT. To this end this service is emulated by the TwinCAT system service. However, usually only a flash disk will be available. In order to avoid overloading the relatively small message capacity of the Event Viewer, only errors should be logged. |

## FAQ #10.2: Deleting the oldest messages

In order to ensure a minimum number of messages that can be handled, a function block of type [MC\_AxRtLoggerDespool\_BkPlcMc](ms-xhelp:///?Id=beckhoff-4c01-4158-8f0c-ab6270fd0cfd) should be called cyclically. With each call, this function block removes the oldest message from the LogBuffer, until a transferred number of free messages is available. The deleted messages are lost.

## FAQ #10.3: Generating logger entries through the application

An application can output a message either axis-related or non-axis-related. The function blocks [MC\_AxRtLogAxisEntry\_BkPlcMc](ms-xhelp:///?Id=beckhoff-943b-421d-917e-de636786c676) and [MC\_AxRtLogEntry\_BkPlcMc](ms-xhelp:///?Id=beckhoff-d0eb-4668-9c40-37ea992b7dc9) are available for this purpose.

## FAQ #11: How do I abort monitoring of a function?

Some library function blocks start an activity, for which cyclic calling is no longer essential. However, these function blocks are also structured according to the rules of the PLCopen Motion Control guidelines in such a way that they fully monitor the activity and present it at their outputs. This is indicated by the output Busy, which most function blocks provide.

Omitting the cyclic call of a function block that is in this monitoring state would usually result in significant problems. The next function start with the respective function block would have problems with evaluating the edges at its inputs, or it would detect that meanwhile the axis has executed another function and indicated a problem that doesn't exist (CommandAborted).

In older versions of the library a function block of type MC\_AxUtiCancelMonitoring\_BkPlcMc() was provided, which for a few motion functions aborted the monitoring by the function block initiating the function. This function block is no longer required, in view of the fact that in the meantime the PLC Open rules have been implemented more fully.

To instruct a function block to terminate monitoring its function, in most cases it is sufficient to call it once or several times with **Execute**:=FALSE. This applies in particular to [MC\_MoveAbsolute\_BkPlcMc](ms-xhelp:///?Id=beckhoff-d937-4450-b853-cb18922787db)(), [MC\_MoveRelative\_BkPlcMc](ms-xhelp:///?Id=beckhoff-454e-4bc6-98b2-190ee9d324a9)() and [MC\_MoveVelocity\_BkPlcMc](ms-xhelp:///?Id=beckhoff-1c72-400e-b9b3-29017b9cf80f)().

Subsequently, a new functionality can be started in same or a later cycle with the same function block or an instance of the same or another type. This procedure can be repeated as required.

|  |  |
| --- | --- |
| 33962670 | Complex functions composed of several sub-actions, such as MC\_Home\_BkPlcMc(), require the continuous calling of the function block as the latter organizes the required processes itself [( MC\_Home\_BkPlcMc ())](ms-xhelp:///?Id=beckhoff-1b39-4911-8ef7-a4d128653cfd) |

## FAQ #12: How do I monitor the communication with an I/O device?

[ST\_TcPlcDeviceInput](ms-xhelp:///?Id=beckhoff-dec6-4dd6-a155-f200065a8d2d) and [ST\_TcPlcDeviceOutput](ms-xhelp:///?Id=beckhoff-fec4-45f2-b458-d8180069b32f) variables provide an element with the name **uiBoxState**. If the Bus Couplers or the interface cards of the power units used offer a corresponding variable and the variable assumes the value 0 with undisturbed communication in the fieldbus used, a link should be created. This is possible, for example, with **Beckhoff Lightbus** and **Real-time Ethernet**. If an [MC\_Power\_BkPlcMc](ms-xhelp:///?Id=beckhoff-f1de-4926-8132-1e2d75ae63fc) function block is used for the axis, the function block monitors the **uiBoxState** and reports problems with the communication. In such a case the axis is put in an error state.

**EtherCAT** offers enhanced options.

## FAQ #13: How do I assign my own labels to customer-specific axis parameters?

The [Axis\_Ref\_BkPlcMc](ms-xhelp:///?Id=beckhoff-002b-4aba-81ea-1693fb03013c) structure uses the pAuxLabels pointer to support the application of an array of texts, which are displayed by the PlcMcManager. These texts can be loaded by the [MC\_AxUtiStandardInit\_BkPlcMc](ms-xhelp:///?Id=beckhoff-b490-4a55-ac43-76ba1d070d46) function block when the application is started from a file. To this end this function block must be provided with the address of an [ST\_TcMcAuxDataLabels](ms-xhelp:///?Id=beckhoff-50c8-4b5f-bdf7-0e14cb1fc422) variable and a suitable file.

It goes without saying that it is also possible to define the elements of the [ST\_TcMcAuxDataLabels](ms-xhelp:///?Id=beckhoff-50c8-4b5f-bdf7-0e14cb1fc422) variable through direct assignment from the application. In this case, the file is not required.

|  |  |
| --- | --- |
| 37228582 | A number of controller function blocks of the library define the arrays texts automatically. |

## FAQ #14: How do I control a current valve?

In contrast to a 4/2 or 3/2 directional proportional valve or a servo-valve, a current valve is controlled with a 0..10 V signal (if a valve output stage is present) or actuated with a load-independent current of 0...INominal. In this control, only the magnitude of the velocity is transferred. The direction is transferred not with the sign, but by other means. This usually requires digital signals, which are used for controlling switching valves. The [ST\_TcPlcDeviceOutput](ms-xhelp:///?Id=beckhoff-fec4-45f2-b458-d8180069b32f) structure provides elements such as **bBrakeOff**, **bMovePos** and **bMoveNeg** for this purpose. For generating an absolute control value, bDrive\_AbsoluteOutput should be set in the axis parameters.

|  |  |
| --- | --- |
| 66621782 | This also enables the use of conventional frequency converters with asynchronous motor, encoder and brake, if the converter provides an analog input. |

## FAQ #15: Which axis variables should be logged with the Scope?

The following signal composition is recommended:

* Always: **actual axis position**: Axis\_Ref\_BkPlcMc.[ST\_TcHydAxRtData](ms-xhelp:///?Id=beckhoff-1ffc-4f72-80ec-3f7c8585d12d).fActPos: in actual value units, as specified by the encoder scaling.
* Only for gear or synchronization coupling, cam plate: **set axis position**: Axis\_Ref\_BkPlcMc.ST\_TcHydAxRtData.fSetPos: in actual value units, as specified by the encoder scaling.
* Particularly during commissioning: **actual velocity value**: Axis\_Ref\_BkPlcMc.ST\_TcHydAxRtData.fActVelo: velocity in physical representation.
* Particularly during commissioning: **Residual distance** or **target position**: Axis\_Ref\_BkPlcMc.ST\_TcHydAxRtData.fDistanceToTarget or Axis\_Ref\_BkPlcMc.ST\_TcHydAxRtData.fTargetPos: in actual value units, as specified by the encoder scaling.
* Only if pressure/force logging is active: **various actual pressure and force values**: in Axis\_Ref\_BkPlcMc.ST\_TcHydAxRtData: as required fActPressure fActPressureA fActPressureB fActForce fValvePressure fSupplyPressure: pressures and forces, unit is defined through parameterization of the logging function blocks.
* Particularly during commissioning: **velocity control value**: Axis\_Ref\_BkPlcMc.ST\_TcHydAxRtData.fSetVelo: velocity in physical representation.
* Particularly during commissioning: **controller output**: Axis\_Ref\_BkPlcMc.ST\_TcHydAxRtData.fLagCtrlOutput: velocity in physical representation.

|  |  |
| --- | --- |
| 62725128 | The signal selection in ScopeView is simplified if the Axis\_Ref\_BkPlcMc variables contain a name that begins with aaa\_. This approach is used in the sample programs and ensures that the variables can be found quickly in the symbol list. |

|  |  |
| --- | --- |
| 27655246 | In the signal composition of ScopeView, channels can be temporarily disabled. In this way it is possible to maintain a comprehensive configuration but limit logging to data that are currently of interest. |

## FAQ #16: What is the purpose of the variable nDebugTag in Axis\_Ref\_BkPlcMc?

|  |  |
| --- | --- |
| 47570623 | This variable exists in some versions. It has no meaning for the PLC project. |

This variable is used by nearly all library function blocks to store a unique ID for the duration of their execution. To this end the content that was found is stored in a local variable of the function block and restored immediately before the function block is exited.

Should the program crash, or if there is a suspicion that there was a problem in a library function block, the **nDebugTag** variables of all axes should be checked. If a value <> 0 is present, the function block was affected by the crash, and the reason should be investigated. The numeric values used are listed in the library under "Global constants". In addition, the contents of [ST\_TcHydAxRtData](ms-xhelp:///?Id=beckhoff-1ffc-4f72-80ec-3f7c8585d12d).**sTopBlockName** should be determined. Usually, the name of the function block called directly by the application can be found here.

## FAQ #17: What has to be taken into account when Sercos drives are used?

If Sercos drives (from V3.0.26) are used, the following rules must be followed:

* The Sercos master interface (e.g. FC7501 etc.) must be allocated the name "SercosMaster" in the System Manager. Otherwise neither control of the Sercos phase nor parameter and diagnostics communication is possible.
* Only a Sercos segment with the library can be used.
* In the System Manager, the drive devices at the Sercos Segment should be allocated the name under which they are known to the library by calling the MC\_AxUtiStandardInit\_BkPlcMc() function block. Otherwise neither control of the Sercos phase nor parameter and diagnostics communication is possible.
* The input variable [SystemState](ms-xhelp:///?Id=beckhoff-1548-4af2-9a41-a84b4ffd8e5d) of the Sercos master interface should be linked for each drive device of the Sercos segment.
* If one or several drives at the Sercos segment are reset, the segment can interrupt the fieldbus. In this case, the Sercos master interface will undergo a corresponding phase change. Usually, the startup up to phase 4 will be automatic. Then:

+ the axis addressed by the reset will be error-free, as long as there are no ongoing problems.
+ all other axes at the Sercos segment will be in error state (fieldbus failure, axis not ready for operation). Once the triggering reset of the first axis has been processed, the other axes can usually be brought into an error-free state through a reset without a phase change.

* This behavior is determined by characteristics of the Sercos fieldbus and cannot be influenced by the library. It must be taken into account in the application in a suitable manner.
* Depending on certain parameter settings of the drive actuator, axis parameters are determined automatically or have to be specified manually:

+ S-0-0076, bits 0 to 2 specify the weighting type of the position data. Supported features:
+ a) 0 0 1 translatory weighting:   
  S-0-0123 defines the rotation resolution (encoder-interpolation). The revolutional feed rate is calculated from this number and the weighting (S-0-0077, S-0-0078).
+ b) 0 1 0 rotary weighting:   
  S-0-0079 defines the rotation resolution (encoder-interpolation). The revolutional feed rate has to be set manually.
+ S-0-0044, bits 0 to 2 specify the weighting type of the velocity data. Supported features:
+ a) 0 0 1 translatory weighting:   
  The velocity control value is converted to a velocity in encoder increments per time, based on the revolutional feed rate and the rotation resolution. This information is offset against the velocity resolution (S-0-0045, S-0-0046) and output.
+ b) 0 1 0 rotational weighting   
  The velocity control value is converted to a speed based on the revolutional feed rate and output.
+ S-0-0091 is converted with the method described above for velocity control values and used as reference velocity. If the maximum speed exceeds the value determined in this way, it is limited accordingly.

## FAQ #18: How is a pressure or a force determined?

To determine an actual pressure or an actual force, one or several function blocks of types [MC\_AxRtReadPressureDiff\_BkPlcMc](ms-xhelp:///?Id=beckhoff-56dc-4d1a-b49b-0b7b2af8cf24), [MC\_AxRtReadForceDiff\_BkPlcMc](ms-xhelp:///?Id=beckhoff-1946-4575-bcf0-63dbcf7a8ec1), [MC\_AxRtReadForceSingle\_BkPlcMc](ms-xhelp:///?Id=beckhoff-9b6c-4ec2-b19e-edaa3299193e) or [MC\_AxRtReadPressureSingle\_BkPlcMc](ms-xhelp:///?Id=beckhoff-6b58-42dd-9f28-b93f3336f1ca) have to be called for each axis. Details for the call sequence can be found under [FAQ #8](ms-xhelp:///?Id=beckhoff-18b7-49ad-a855-a0509f58bddd).

The AD converter values to be transferred to the function blocks have to be linked with allocated variables of the application. Details regarding selection and parameterization can be found in the function blocks descriptions.

## FAQ #19: What has to be taken into account when AX5000 drives are used?

For AX5000 devices, a number of IDNs are read from the device, and a number of different parameters are calculated automatically.

| IDN | Used for parameter |
| --- | --- |
| 44 | Reference velocity, internally: scaling of the velocity output |
| 45 | Internal: scaling of the velocity output |
| 46 | Internal: scaling of the velocity output |
| 76 | Encoder interpolation |
| 79 | Encoder interpolation |
| 91 | Reference velocity |

The following parameters are thus set automatically and cannot be influenced via the PlcMcManager:

| Parameter |  | influences which other parameters |
| --- | --- | --- |
| Global: reference velocity | Calculated from the maximum speed of the device and the revolutional feed rate | Manuel velocities, max. appl. velocity |
| Encoder: inc. interpolation | Read from IDN79 of the device | **Attention:** the revolutional feed rate has to be entered as inc. evaluation |

## FAQ #20: How do I prepare an axis for blending based on PLC Open?

In Hydraulik.lib it is possible to command up to 12 buffered movements. For this purpose, a command buffer of type ST\_TcPlcCmdCmdBuffer\_BkPlcMc must be passed to the [MC\_AxUtiStandardInit\_BkPlcMc](ms-xhelp:///?Id=beckhoff-b490-4a55-ac43-76ba1d070d46) function block for updating the axis reference and a function block MC\_AxRtCmdBufferExecute\_BkPlcMc must be called cyclically.

If Move function blocks such as [MC\_MoveAbsolute\_BkPlcMc](ms-xhelp:///?Id=beckhoff-d937-4450-b853-cb18922787db), [MC\_MoveRelative\_BkPlcMc](ms-xhelp:///?Id=beckhoff-454e-4bc6-98b2-190ee9d324a9) or [MC\_MoveVelocity\_BkPlcMc](ms-xhelp:///?Id=beckhoff-1c72-400e-b9b3-29017b9cf80f) are now activated, they enter their data in the command buffer.

In buffered mode make sure that the Move function blocks and the [MC\_AxRuntime\_BkPlcMc](ms-xhelp:///?Id=beckhoff-992b-440b-b677-39eccb14d862) function block of the axis run in a PLC task.

## Transition between a slow and a fast section.

![25482430](/tf5810_tc3_hydraulic_positioning/1033/Images/gif/4775504907__Web.gif)

## Transition between a fast and a slow section.

![28015283](/tf5810_tc3_hydraulic_positioning/1033/Images/gif/4775507723__Web.gif)

## FAQ #21: How can I access registers of a terminal, to which an encoder or a valve of an axis is connected?

For register communication with terminals to which the encoder or the valve of an axis is connected, it is recommended to use function blocks of types [MC\_AxUtiReadRegDriveTerm\_BkPlcMc](ms-xhelp:///?Id=beckhoff-6cad-4416-a595-99af3f7e4d4d)(), [MC\_AxUtiReadRegEncTerm\_BkPlcMc](ms-xhelp:///?Id=beckhoff-ffcf-4474-9c04-758f97fa6a6f)(), [MC\_AxUtiWriteRegDriveTerm\_BkPlcMc](ms-xhelp:///?Id=beckhoff-278e-4ad1-9a74-c27725e3bc65)() and [MC\_AxUtiWriteRegEncTerm\_BkPlcMc](ms-xhelp:///?Id=beckhoff-4abb-470a-baef-ba638f5fbde2)().

## FAQ #22: What is the structure of an ASCII file for a linearization table?

The format of an ASCII file from a linearization table is specified as follows:

* One linearization point per row.
* For each row first a velocity value, then an output value.
* The velocity values are normalized to the reference velocity. They are therefore in the range -1,000 to 1,000 inclusive.
* The output values are normalized to the full scale value. They therefore cover the range -1,000 to 1,000.
* The first value in a row may be preceded by white space characters (space, tab).
* Between the two values in row there must be at least one white space character (space, tab).
* Between the two values of a row there may be further white space characters (space, tab).
* Point and comma are permitted as decimal separator.
* No non-digits are permitted between a negative sign and the first digit.
* The first point specifies the negative end of the table.
* The velocity value of all further points must be higher (i.e. less negative or more positive) than its predecessor.
* It makes sense if the output value of a point is higher (i.e. less negative or more positive) than its predecessor, since otherwise there would be a negative slope in this section. This would result in a change of sign of the gain and therefore instability in an active control.
* The zero point (i.e. both coordinates of the point are 0.000) has to be specified.

**Example**: The following (idealized) table describes a cylinder, which in negative direction only reaches half the velocity of the positive direction due to asymmetric effective areas (due to single-sided piston rod). It is assumed that the cylinder is operated with a zero overlap valve with a bend in the characteristic curve at 40%

| Normalized velocity | Normalized output |
| --- | --- |
| -0.500 | -1.000 |
| -0.430 | -0.900 |
| -0.360 | -0.800 |
| -0.290 | -0.700 |
| -0.220 | -0.600 |
| -0.150 | -0.500 |
| -0.080 | -0.400 |
| -0.060 | -0.300 |
| -0.040 | -0.200 |
| -0.020 | -0.100 |
| 0.000 | 0.000 |
| 0.040 | 0.100 |
| 0.080 | 0.200 |
| 0.120 | 0.300 |
| 0.160 | 0.400 |
| 0.300 | 0.500 |
| 0.440 | 0.600 |
| 0.580 | 0.700 |
| 0.720 | 0.800 |
| 0.860 | 0.900 |
| 1.000 | 1.000 |

## FAQ #23: How can PlcMcManager commands be blocked?

In some situations the triggering of commands by the PlcMcManager can be problematic. This would be the case if a certain sequence of actions has to be processed completely, for example. In order to prevent inadvertent issuing of commands by the PlcMcManager in such cases, the [MC\_AxRtCommandsLocked\_BkPlcMc](ms-xhelp:///?Id=beckhoff-1784-40af-a48c-fa590068b6d1) function can be used to enter a lock in the status double word of the axis. If this lock is active, any command sent by PlcMcManager sent is rejected with a write protection error.

|  |  |
| --- | --- |
| 50810959 | It is essential to remove the lock, once the action to be protected has been processed. This also and in particular applies in the event of errors. |

An [example](ms-xhelp:///?Id=beckhoff-6af5-4f42-8491-7a510b7dd9b7) is available.

**FAQ #24: What format do files with characteristic curve data have?**

If an axis is equipped with components for a characteristic curve-controlled linearization, the interpolation points can be exported to a file using a function block of the type MC\_LinTableExportToAsciiFile\_BkPlcMc(). The function block MC\_LinTableImportFromAsciiFile\_BkPlcMc() is available if such data are to be imported from a file created or modified in this way or in other ways.

So that such files can be used, the following format must be strictly adhered to.

* A row must be used for each point.
* Each row must be terminated with CR/LF.
* Each row initially contains the normalized velocity value in the range -1.0 to 1.0.
* After at least one separator (space or tab), the normalized output value follows for the full range from -1.0 to 1.0.
* The output value must exhibit a constant step size (distance between two points).
* The first row contains the negative end value. Its output value must be -1.0.
* The last row contains the positive end value. Its output value must be 1.0.
* A row must be provided for the output value 0.0.
* The file must therefore contain the same number of points in the negative and positive range. The total number must be odd.
* Both the velocity and the output value follow the same rules:
* Sign with negative numbers
* A digit
* A decimal separator: comma or point
* At least one decimal place
* Optional: An exponent, marked with "e", a minus sign and a digit
* Example: -1.81408951053528e-1 -5.0e-1
* Example: 0.333 0.5

[TF5810 | TwinCAT 3 Hydraulic Positioning](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
