# Functions, function blocks and types (from V3.0)

## Library
tf5810_tc3_hydraulic_positioning

## Category
Motion Control

1. [TwinCAT PLC Hydraulics](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
2. [General structure](ms-xhelp:///?Id=beckhoff-9339-4a46-a86a-a60aafa2ce96)
3. Functions, function blocks and types (from V3.0)

# Functions, function blocks and types (from V3.0)

|  |  |
| --- | --- |
| 42488815 | All the functions, function blocks and data types present in the library are listed here. |

You will find answers to frequently asked questions and notes on the use of the library, setting up, problem analysis and example projects in the [Knowledge Base](ms-xhelp:///?Id=beckhoff-873e-46cd-925a-b9a96eea638e).

Some of the components listed here are not intended to be used by an application. Their presence, interface and behavior is therefore not guaranteed. Because, however, a TwinCAT PLC library is strictly open, it is not possible to hide these internal components. It is, nevertheless, essential to avoid calling these components, identified with (internal use only) or (not recommended), directly from an application. If one of these components would, in practice, be useful for you, please make contact with our Support Department. We will then examine the possibility of making the function block available to you, independently of the library, and for you to then take the responsibility for using it.

If the library contains function blocks, types or constants that are not listed in the documentation, then these are elements that have not yet been approved, and are the subject of current software maintenance and development work. These elements must never be directly used in an application, because they are, as a general rule, not yet tested.

|  |  |
| --- | --- |
| 46855021 | The hydraulic library only offers a restricted range of functions, even in connection with electrical drives. TwinCAT NC PTP, NC I and CNC offer a significantly broader spectrum and more comprehensive support for commissioning and diagnosis. |

|  |  |
| --- | --- |
| 19042013 | A number of libraries are available, which deal with a typical axis configuration or special functionalities. These libraries require the TcPlcHydraulics library and have to be ordered separately. |

| Name | Description |
| --- | --- |
| TcPlcLibHydraulics\_30\_2R2Vgantry.LIB | in preparation |
| TcPlcLibHydraulics\_30\_4R3Vgantry.LIB | in preparation |

## PLC open Motion Control

The function blocks listed here are oriented towards:

Technical Specification

PLCopen - Technical Committee 2 - Task Force

Function blocks for motion control

Part 1 Version 1.1 and Part 2 Version 0.99F (definition not yet finalized)

The names of these function blocks begin with MC\_ and end with \_BkPlcMc.

![37160390](/tf5810_tc3_hydraulic_positioning/1033/Images/jpg/1599901323__Web.jpg)

|  |  |
| --- | --- |
| 66008059 | Parts of the PLCopen definitions have not yet been finalized. Future versions of the library may be subject to modifications. Such modifications may relate to |

* Names, behavior or even existence of functions, function blocks or derived data types
* Names, behavior, types or existence of input or output signals

## Administrative Function blocks

| Name | Description |
| --- | --- |
| [MC\_CamTableSelect\_BkPlcMc](ms-xhelp:///?Id=beckhoff-af26-44f2-901d-1b7a99b37e87) | The function block initializes a variable of type ST\_TcPlcMcCamId, thereby preparing a cam plate for the coupling of two axes. |
| [MC\_Power\_BkPlcMc](ms-xhelp:///?Id=beckhoff-f1de-4926-8132-1e2d75ae63fc) | Function block to control an external actuator. |
| [MC\_ReadActualPosition\_BkPlcMc](ms-xhelp:///?Id=beckhoff-0c50-411f-879e-5540fafa1c82) | The actual position of an axis is determined. |
| [MC\_ReadActualTorque\_BkPlcMc](ms-xhelp:///?Id=beckhoff-4aab-4e49-926e-221363b794ab) | The actual force or the actual pressure of an axis is determined. |
| [MC\_ReadActualVelocity\_BkPlcMc](ms-xhelp:///?Id=beckhoff-96fe-421e-a829-3c35bbbc8f90) | The actual velocity of an axis is determined. |
| [MC\_ReadAxisError\_BkPlcMc](ms-xhelp:///?Id=beckhoff-2349-410b-b8b6-306ce323bf22) | The current error code of an axis is found. |
| [MC\_ReadBoolParameter\_BkPlcMc](ms-xhelp:///?Id=beckhoff-9475-49ea-9ed4-a2fbfca6483f) | The boolean parameters of an axis are read. |
| [MC\_ReadDigitalOutput\_BkPlcMc](ms-xhelp:///?Id=beckhoff-4f7e-43c1-94d6-9bafa01240b0) | The current state of a digital output of a cam controller is determined. |
| [MC\_ReadParameter\_BkPlcMc](ms-xhelp:///?Id=beckhoff-f72f-4a3c-9ffa-5adf447fe918) | The non-boolean parameters of an axis are read. |
| [MC\_ReadStatus\_BkPlcMc](ms-xhelp:///?Id=beckhoff-58c4-46cf-8b8e-295e18039009) | The state of the axis is decoded. |
| [MC\_Reset\_BkPlcMc](ms-xhelp:///?Id=beckhoff-e4ba-44fd-a251-2f2b0aa0abc2) | The axis is placed in a state ready for operation. |
| [MC\_ResetAndStop\_BkPlcMc](ms-xhelp:///?Id=beckhoff-9025-42cf-b5c3-4abde4187a21) | The axis is placed in a state ready for operation and is stationary. |
| [MC\_SetOverride\_BkPlcMc](ms-xhelp:///?Id=beckhoff-48f4-4b85-87d8-d0da4f567cde) | The axis override is set. |
| [MC\_SetPosition\_BkPlcMc](ms-xhelp:///?Id=beckhoff-f65a-4c39-bec9-11940d456eda) | The actual position of the axis is set. |
| [MC\_SetReferenceFlag\_BkPlcMc](ms-xhelp:///?Id=beckhoff-a2d5-4fc5-b64a-c2738fc01d65) | The referencing flag of the axis is defined. (Function is not defined by PLCopen) |
| [MC\_WriteBoolParameter\_BkPlcMc](ms-xhelp:///?Id=beckhoff-0385-4ba1-91ad-2fe61a251600) | The boolean parameters of an axis are written. |
| [MC\_WriteDigitalOutput\_BkPlcMc](ms-xhelp:///?Id=beckhoff-4e0d-49b0-91f7-6fbd02e16d33) | The current state of a digital output of a cam controller is defined. |
| [MC\_WriteParameter\_BkPlcMc](ms-xhelp:///?Id=beckhoff-37ac-4014-b387-f8451c1ea86a) | The non-boolean parameters of an axis are written. |

## Motion Function Blocks, Single Axis

| Name | Description |
| --- | --- |
| [MC\_DigitalCamSwitch\_BkPlcMc](ms-xhelp:///?Id=beckhoff-f926-4994-ab22-ff25375bcbfc) | Generation of software cams as a function of position, direction of movement and velocity of an axis. |
| [MC\_EmergencyStop\_BkPlcMc](ms-xhelp:///?Id=beckhoff-b20e-4907-bca3-7e0069a79051) | Stopping a movement without reaching the target position. (Function is not defined by PLCopen) |
| [MC\_Halt\_BkPlcMc](ms-xhelp:///?Id=beckhoff-ed33-432b-852b-b8d24953eecd) | Stopping a movement without reaching the target position. |
| [MC\_Home\_BkPlcMc](ms-xhelp:///?Id=beckhoff-1b39-4911-8ef7-a4d128653cfd) | Initiation and monitoring of homing. |
| [MC\_ImediateStop\_BkPlcMc](ms-xhelp:///?Id=beckhoff-a719-4119-90f6-ffe5dfef2115) | Stopping a movement without reaching the target position. (Function is not defined by PLCopen) |
| [MC\_MoveAbsolute\_BkPlcMc](ms-xhelp:///?Id=beckhoff-d937-4450-b853-cb18922787db) | Start and monitoring of a positioning process at a specifiable velocity to absolutely stated target co-ordinates. |
| [MC\_MoveJoySticked\_BkPlcMc](ms-xhelp:///?Id=beckhoff-0ccf-40eb-80de-24ff874ef242) | Starting and controlling of an axis movement with a proportional control unit. (Function is not defined by PLCopen) |
| [MC\_MoveRelative\_BkPlcMc](ms-xhelp:///?Id=beckhoff-454e-4bc6-98b2-190ee9d324a9) | Start and monitoring of a positioning process at a specifiable velocity over an absolutely stated distance. |
| [MC\_MoveVelocity\_BkPlcMc](ms-xhelp:///?Id=beckhoff-1c72-400e-b9b3-29017b9cf80f) | Start and monitoring of a positioning process at a specifiable velocity but with no specified target. |
| [MC\_RampedStop\_BkPlcMc](ms-xhelp:///?Id=beckhoff-4f73-4281-96e0-48f6dd9f274b) | Stopping of a movement with a pure time ramp. |
| [MC\_Stop\_BkPlcMc](ms-xhelp:///?Id=beckhoff-9b19-4599-8840-88fa788b9ed6) | Stopping a movement without reaching the target position. |

## Motion Function blocks, Multiple Axis

| Name | Description |
| --- | --- |
| [MC\_CamIn\_BkPlcMc](ms-xhelp:///?Id=beckhoff-f22a-44e5-b98f-a23a18918289) | The function block starts and monitors a cam plates coupling between two axes. |
| [MC\_CamOut\_BkPlcMc](ms-xhelp:///?Id=beckhoff-f9e2-45c8-b5d2-c0ebfc965ddd) | The function block releases a cam plate coupling between two axes. |
| [MC\_GearIn\_BkPlcMc](ms-xhelp:///?Id=beckhoff-4041-4933-b290-4cbdc9cd7d51) | Start and monitoring of the gear coupling of two axes. |
| [MC\_GearInPos\_BkPlcMc](ms-xhelp:///?Id=beckhoff-cc38-448a-9d02-eed0b69f60f4) | On-the-fly gear coupling of two axes. |
| [MC\_GearOut\_BkPlcMc](ms-xhelp:///?Id=beckhoff-f42f-49a2-831a-c7c89ada8df9) | Cancelling the gear coupling of two axes. |

## System Function Blocks

| Name | Description |
| --- | --- |
| [MC\_AxRtDrive\_BkPlcMc](ms-xhelp:///?Id=beckhoff-1548-4af2-9a41-a84b4ffd8e5d) | Preparation of the control value of the axis for output on a hardware module, mapping information. |
| [MC\_AxRtEncoder\_BkPlcMc](ms-xhelp:///?Id=beckhoff-695e-4050-b1c6-c96353e7c191) | Determination of the actual position of the axis from the input information of a hardware module, mapping information. |
| [MC\_AxRtFinish\_BkPlcMc](ms-xhelp:///?Id=beckhoff-0bc7-4c7a-b544-8f2d601813cd) | Adaptation of the generated control value to the special features of the axis. |
| [MC\_AxRtFinishLinear\_BkPlcMc](ms-xhelp:///?Id=beckhoff-e15e-40cb-b1bb-32215a440336) | Adjustment of the generated control value to the special features of the axis, taking into account a characteristic curve. |
| [MC\_AxRuntime\_BkPlcMc](ms-xhelp:///?Id=beckhoff-44b8-4821-9e99-8f1493d2e551) | Position value generation and position control of the axis. |
| [MC\_AxRtGenerator\_BkPlcMc](ms-xhelp:///?Id=beckhoff-992b-440b-b677-39eccb14d862) | Control value generation for the axis. |
| [MC\_AxRtController\_BkPlcMc](ms-xhelp:///?Id=beckhoff-159d-454d-95b1-c0c7c593a76f) | Position control of the axis. |

## System function blocks, other actual values

| Name | Description |
| --- | --- |
| [MC\_AxRtReadForceDiff\_BkPlcMc](ms-xhelp:///?Id=beckhoff-1946-4575-bcf0-63dbcf7a8ec1) | Determination of the differential actual force of an axis. |
| [MC\_AxRtReadForceSingle\_BkPlcMc](ms-xhelp:///?Id=beckhoff-9b6c-4ec2-b19e-edaa3299193e) | Determination of the one-sided actual force of an axis. |
| [MC\_AxRtReadPressureDiff\_BkPlcMc](ms-xhelp:///?Id=beckhoff-56dc-4d1a-b49b-0b7b2af8cf24) | Determination of the differential actual pressure of an axis. |
| [MC\_AxRtReadPressureSingle\_BkPlcMc](ms-xhelp:///?Id=beckhoff-6b58-42dd-9f28-b93f3336f1ca) | Determination of the one-sided actual pressure of an axis. |

## System Function Blocks, Parameter

| Name | Description |
| --- | --- |
| [MC\_AxAdsCommServer\_BkPlcMc](ms-xhelp:///?Id=beckhoff-5702-45de-80d2-87ae2f7a2a8a) | The application is given the capacity to function as an ADS server. |
| [MC\_AxAdsReadDecoder\_BkPlcMc](ms-xhelp:///?Id=beckhoff-481a-4a03-8125-5c248c8f87e9) | The function block decodes ADS read accesses for an ADS server. |
| [MC\_AxAdsWriteDecoder\_BkPlcMc](ms-xhelp:///?Id=beckhoff-2966-42df-8743-cf2a33ec4367) | The function block decodes ADS write accesses for an ADS server. |
| [MC\_AxAdsPtrArrCommServer\_BkPlcMc](ms-xhelp:///?Id=beckhoff-456f-4146-aa13-7032608b0a05) | The application is given the capacity to function as an ADS server. |
| [MC\_AxParamAuxLabelsLoad\_BkPlcMc](ms-xhelp:///?Id=beckhoff-3d0d-45fe-ad0c-bbd985c13a84) | Loading the label texts for the client-specific axis parameters from a file. |
| [MC\_AxParamLoad\_BkPlcMc](ms-xhelp:///?Id=beckhoff-92c8-44d1-ae87-dd14f51905c7) | Load the parameters for an axis from a file. |
| [MC\_AxParamSave\_BkPlcMc](ms-xhelp:///?Id=beckhoff-aaf6-41ce-bb18-a1a64bda1099) | Write the parameters for an axis into a file. |
| [MC\_AxParamDelayedSave\_BkPlcMc](ms-xhelp:///?Id=beckhoff-160d-40ac-9a0e-b1473a98bb6f) | Delayed writing of the axis parameters. |
| [MC\_AxUtiReadCoeDriveTerm\_BkPlcMc](ms-xhelp:///?Id=beckhoff-90ba-4307-aaa4-2c022020860a) | Reading the contents of a register from the EL terminal, which is used as drive interface for the axis. |
| [MC\_AxUtiReadCoeEncTerm\_BkPlcMc](ms-xhelp:///?Id=beckhoff-7400-40fd-8294-07c2ecaab592) | Reading the contents of a register from the EL terminal, which is used as encoder interface for the axis. |
| [MC\_AxUtiReadRegDriveTerm\_BkPlcMc](ms-xhelp:///?Id=beckhoff-6cad-4416-a595-99af3f7e4d4d) | Reading the contents of a register from the KL terminal, which is used as drive interface for the axis. |
| [MC\_AxUtiReadRegEncTerm\_BkPlcMc](ms-xhelp:///?Id=beckhoff-ffcf-4474-9c04-758f97fa6a6f) | Reading the contents of a register from the KL terminal, which is used as encoder interface for the axis. |
| [MC\_AxUtiUpdateRegDriveTerm\_BkPlcMc](ms-xhelp:///?Id=beckhoff-dd55-4c8d-ae26-8aa901301651) | Writing a parameter set into the register of a KL terminal, which is used as drive interface for the axis. |
| [MC\_AxUtiUpdateRegEncTerm\_BkPlcMc](ms-xhelp:///?Id=beckhoff-aecd-46aa-8e3c-4d0e10d14cac) | Writing a parameter set into the register of a KL terminal, which is used as encoder interface for the axis. |
| [MC\_AxUtiWriteCoeDriveTerm\_BkPlcMc](ms-xhelp:///?Id=beckhoff-7cba-4405-8e9c-a8217c2e3371) | Writing the contents of a register into the EL terminal, which is used as drive interface for the axis. |
| [MC\_AxUtiWriteCoeEncTerm\_BkPlcMc](ms-xhelp:///?Id=beckhoff-df11-4e2f-b450-a36514470489) | Writing the contents of a register into the EL terminal, which is used as encoder interface for the axis. |
| [MC\_AxUtiWriteRegDriveTerm\_BkPlcMc](ms-xhelp:///?Id=beckhoff-278e-4ad1-9a74-c27725e3bc65) | Writing the contents of a register into the KL terminal, which is used as drive interface for the axis. |
| [MC\_AxUtiWriteRegEncTerm\_BkPlcMc](ms-xhelp:///?Id=beckhoff-4abb-470a-baef-ba638f5fbde2) | Writing the contents of a register into the KL terminal, which is used as encoder interface for the axis. |
| [MC\_LinTableExportToAsciFile\_BkPlcMc](ms-xhelp:///?Id=beckhoff-7b5f-4485-91c5-cf897aaf1d5c) | The function block exports a linearization table to a file in ASCI format. |
| [MC\_LinTableExportToBinFile\_BkPlcMc](ms-xhelp:///?Id=beckhoff-dc08-447c-8568-c4d63e15bc88) | The function block exports a linearization table to a file in binary format. |
| [MC\_LinTableImportFromAsciFile\_BkPlcMc](ms-xhelp:///?Id=beckhoff-cb84-41ca-bd1c-281a5c81f629) | The function block imports a linearization table from a file in ASCI format. |
| [MC\_LinTableImportFromBinFile\_BkPlcMc](ms-xhelp:///?Id=beckhoff-1afc-4f33-a3b7-d5196ffc6065) | The function block imports a linearization table from a file in binary format. |

## System Function Blocks, Controllers

| Name | Description |
| --- | --- |
| [MC\_AxCtrlAutoZero\_BkPlcMc](ms-xhelp:///?Id=beckhoff-0274-4561-8b6d-238ef2cdba3f) | Automatic zero balance. |
| [MC\_AxCtrlPressure\_BkPlcMc](ms-xhelp:///?Id=beckhoff-6561-479c-a264-3883abee8510) | Controller for pressure build-up control. |
| [MC\_AxCtrlPressureFF\_Ex\_BkPlcMc](ms-xhelp:///?Id=beckhoff-c513-4178-81ba-4229aa91ce08) | Extended controller for a pressure controller with a build-up action. |
| MC\_AxCtrlPullbackOnPressure\_BkPlcMc | Controller for pressure displacement control. |
| [MC\_AxCtrlSlowDownOnPressure\_BkPlcMc](ms-xhelp:///?Id=beckhoff-8098-43c1-8159-369473df0437) | Controller for pressure relief control. |
| [MC\_AxCtrlStepperDeStall\_BkPlcMc](ms-xhelp:///?Id=beckhoff-9822-4044-b66d-bf7ee61a787f) | Monitoring the movement of a stepper motor axis. |
| MC\_AxCtrlVelocity\_BkPlcMc | Controller for the axis velocity. |
| MC\_AxCtrlVeloMoving\_BkPlcMc | Controller for the axis velocity. |

## System Function blocks, TableFunctions

| Name | Description |
| --- | --- |
| [MC\_AxTableFromAsciFile\_BkPlcMc](ms-xhelp:///?Id=beckhoff-8d6b-4b54-866b-07f963e48ff8) | Reading the content of table from a text file. |
| [MC\_AxTableFromBinFile\_BkPlcMc](ms-xhelp:///?Id=beckhoff-26da-454d-bf85-f7e67b6d116b) | Reading the content of table from a binary file. |
| [MC\_AxTableReadOutNonCyclic\_BkPlcMc](ms-xhelp:///?Id=beckhoff-f89f-41f1-b246-85f58826df88) | Function block for determining the slave values assigned to a master value with the aid of a table. |
| [MC\_AxTableToAsciFile\_BkPlcMc](ms-xhelp:///?Id=beckhoff-ecf8-4658-8c8f-76a3e16c1b2a) | Writing the contents of a table to text file. |
| [MC\_AxTableToBinFile\_BkPlcMc](ms-xhelp:///?Id=beckhoff-0f95-4d36-9455-80a441ba1190) | Writing the contents of a table to a binary file. |

## System Function blocks, Message Logging

| Name | Description |
| --- | --- |
| [MC\_AxRtLogAxisEntry\_BkPlcMc](ms-xhelp:///?Id=beckhoff-943b-421d-917e-de636786c676) | An axis-related message is entered in the LogBuffer of the library. |
| [MC\_AxRtLogClear\_BkPlcMc](ms-xhelp:///?Id=beckhoff-f7d4-4dbb-9bd6-a8393afba665) | Clear and initialize all entries in the LogBuffer. |
| [MC\_AxRtLogEntry\_BkPlcMc](ms-xhelp:///?Id=beckhoff-d0eb-4668-9c40-37ea992b7dc9) | A message is entered in the LogBuffer of the library. |
| [MC\_AxRtLoggerDespool\_BkPlcMc](ms-xhelp:///?Id=beckhoff-4c01-4158-8f0c-ab6270fd0cfd) | Ensure the minimum number of free messages in the LogBuffer of the library. |
| [MC\_AxRtLoggerRead\_BkPlcMc](ms-xhelp:///?Id=beckhoff-5951-4fc8-b8f8-7dacb2ef4125) | Reading a message from the LogBuffer of the library. |
| [MC\_AxRtLoggerSpool\_BkPlcMc](ms-xhelp:///?Id=beckhoff-54e4-42b0-8b15-e29767b6b2eb) | Transferring messages from the LogBuffer of the library into the Windows event viewer. |

## System function blocks, runtime functions

| Name | Description |
| --- | --- |
| [MC\_AxRtCheckSyncDistance\_BkPlcMc](ms-xhelp:///?Id=beckhoff-2edb-4f90-9d1a-fa4956357d5e) | Monitoring of the distance between the referencing cam and zero pulse. |
| [MC\_AxRtCmdBufferExecute\_BkPlcMc](ms-xhelp:///?Id=beckhoff-a929-4cbb-8751-aeeb8454d408) | Processing of the command buffer. |
| [MC\_AxRtCommandsLocked\_BkPlcMc](ms-xhelp:///?Id=beckhoff-1784-40af-a48c-fa590068b6d1) | The function simplifies setting and deleting of a protective function in the status double word of an axis. |
| [MC\_AxRtGoErrorState\_BkPlcMc](ms-xhelp:///?Id=beckhoff-cb21-4ce5-b78e-f2e3b4609fb3) | (not recommended) The axis is placed into an error state. |
| [MC\_AxRtMoveChecking\_BkPlcMc](ms-xhelp:///?Id=beckhoff-f54f-44eb-9d45-02e475628c04) | Monitoring the movement of an axis. |
| [MC\_AxRtSetDirectOutput\_BkPlcMc](ms-xhelp:///?Id=beckhoff-923d-46ed-9f5e-b92fe27e2767) | Direct output of a control value. |
| [MC\_AxRtSetExtGenValues\_BkPlcMc](ms-xhelp:///?Id=beckhoff-47ec-4355-83da-221f9f967897) | Supplying an axis with command variables, which do not originate from the axis' own generator. |
| [MC\_AxStandardBody\_BkPlcMc](ms-xhelp:///?Id=beckhoff-1687-4c16-854c-a550eeaaa344) | Calls the usual sub-components for an axis (encoder, generator, finish, drive). |
| [MC\_AxUtiAutoIdent\_BkPlcMc](ms-xhelp:///?Id=beckhoff-6e26-4519-a6b1-d0581db76054) | Automatic determination of axis parameters. |
| MC\_AxUtiAutoIdentSlave\_BkPlcMc | in preparation: Automatic determination of slave axis parameters. |
| [MC\_AxUtiAverageDerivative\_BkPlcMc](ms-xhelp:///?Id=beckhoff-966d-4eeb-909f-949bdc1139b8) | Determination of the derivative of value through numeric differentiation over than one cycle. |
| [MC\_AxUtiPT1\_BkPlcMc](ms-xhelp:///?Id=beckhoff-b2b4-4b5a-8b30-ef234e33b238) | Calculation of a first-order low-pass. |
| [MC\_AxUtiPT2\_BkPlcMc](ms-xhelp:///?Id=beckhoff-869e-490b-a0b1-1e819b8bc4c5) | Calculation of a second-order low-pass. |
| [MC\_AxUtiSlewRateLimitter\_BkPlcMc](ms-xhelp:///?Id=beckhoff-2d11-4d1a-9ac2-6c635cfb69fe) | Generation of a rise-limited ramp. |
| [MC\_AxUtiSlidingAverage\_BkPlcMc](ms-xhelp:///?Id=beckhoff-7904-4049-b398-bf5aabb72e13) | Determination of a sliding average value. |
| [MC\_AxUtiStandardInit\_BkPlcMc](ms-xhelp:///?Id=beckhoff-b490-4a55-ac43-76ba1d070d46) | Initialization and monitoring of axis components. |
| [MC\_FunctionGeneratorFD\_BkPlcMc](ms-xhelp:///?Id=beckhoff-c220-4046-af00-f126004a753d) | A function generator. |
| [MC\_FunctionGeneratorSetFrq\_BkPlcMc](ms-xhelp:///?Id=beckhoff-b325-4204-a66a-f21961dd38a2) | Updates the operating frequency of a time base for one or several function generators. |
| [MC\_FunctionGeneratorTB\_BkPlcMc](ms-xhelp:///?Id=beckhoff-fa42-43f7-96f2-1438c3255a9d) | Updates a time base for one or several function generators. |

## Data types: Enumerations

| Name | Description |
| --- | --- |
| [E\_TcMcCurrentStep](ms-xhelp:///?Id=beckhoff-16b4-460f-9810-4e6a9be14841) | This enumeration returns codes for the internal states of the control value generators. |
| [E\_TcMcDriveType](ms-xhelp:///?Id=beckhoff-540a-458a-ab44-3657804f519c) | The constants in this enumeration are used to identify the hardware used to output the control values for an axis. |
| [E\_TcMcEncoderType](ms-xhelp:///?Id=beckhoff-1819-4c81-9982-5253100bd275) | The constants in this enumeration are used to identify the hardware used to acquire the actual values for an axis. |
| [E\_TcMCFbState](ms-xhelp:///?Id=beckhoff-ec30-4c5a-b456-5a14920f0c0b) | This enumeration supplies codes for the current state of an axis. |
| [E\_TcMcHomingType](ms-xhelp:///?Id=beckhoff-6975-4e0a-9321-fac7e60e8027) | This enumeration supplies codes for the referencing method used by an axis. |
| [E\_TcMCParameter](ms-xhelp:///?Id=beckhoff-ea11-4506-b969-56d5e1515b02) | The constants listed here are used for numbering parameters. |
| [E\_TcMcPressureReadingMode](ms-xhelp:///?Id=beckhoff-0fab-4419-8171-b0d510ff6e3f) | The constants in this list determine which actual value in the ST\_TcHydAxRtData structure of the axis is to be updated with the result of a pressure or force measurement. |
| [E\_TcMcProfileType](ms-xhelp:///?Id=beckhoff-8110-4345-a5e7-67028351ee24) | The constants listed here are used for identifying control value generators. |
| [E\_TcPlcBufferedCmdType\_BkPlcMc](ms-xhelp:///?Id=beckhoff-a02e-450d-967d-92f3fcb91e3f) | In preparation: The constants in this list are used to identify buffered axis commands. |
| [MC\_BufferMode\_BkPlcMc](ms-xhelp:///?Id=beckhoff-627d-413d-9066-b092a4bae445) | The constants in this list are used for controlling blending according to PLC Open. |
| [MC\_Direction\_BkPlcMc](ms-xhelp:///?Id=beckhoff-655d-48f0-bea8-21f606b985a9) | This enumeration supplies codes for the direction of movement if this information is not contained in other data or cannot be in determined on the basis of the situation. |
| [MC\_HomingMode\_BkPlcMc](ms-xhelp:///?Id=beckhoff-9007-49dc-a035-f71f1e0e29da) | This enumeration returns codes for specification of the referencing method. |
| [MC\_StartMode\_BkPlcMc](ms-xhelp:///?Id=beckhoff-09ff-451e-afa7-6320737ad1dd) | The constants in this list are used for identifying the modes during axis startups. |

## Data types: Structures

| Name | Description |
| --- | --- |
| [Axis\_Ref\_BkPlcMc](ms-xhelp:///?Id=beckhoff-002b-4aba-81ea-1693fb03013c) | A variable of this type contains all the necessary variables or pointers to variables that are associated with an axis. |
| [CAMSWITCH\_REF\_BkPlcMc](ms-xhelp:///?Id=beckhoff-f33f-4253-9407-ea045cafcc25) | A variable of this type is transferred to an [MC\_DigitalCamSwitch\_BkPlcMc](ms-xhelp:///?Id=beckhoff-f926-4994-ab22-ff25375bcbfc) function block. |
| [MC\_CAM\_ID\_BkPlcMc](ms-xhelp:///?Id=beckhoff-c699-42ea-8202-bcc2f3dbf8c5) | A variable of this type contains the description of a cam plate prepared for coupling. |
| [MC\_CAM\_REF\_BkPlcMc](ms-xhelp:///?Id=beckhoff-6249-4c3b-aefb-f2fdf2745e46) | A variable of this type contains the description of a provided cam plate. |
| [OUTPUT\_REF\_BkPlcMc](ms-xhelp:///?Id=beckhoff-f9aa-4587-a859-7e05ee8c20f1) | A variable of this type contains output data of an [MC\_DigitalCamSwitch\_BkPlcMc](ms-xhelp:///?Id=beckhoff-f926-4994-ab22-ff25375bcbfc) function block. |
| [ST\_FunctionGeneratorFD\_BkPlcMc](ms-xhelp:///?Id=beckhoff-41b5-46c5-8602-712cb9848321) | A variable of this type contains parameters for defining the output signals of a function generator. |
| [ST\_FunctionGeneratorTB\_BkPlcMc](ms-xhelp:///?Id=beckhoff-dcf9-46b9-a79a-60bb71ea0118) | A variable of this type contains parameter for defining a time base for a function generator. |
| [ST\_TcMcAutoIdent](ms-xhelp:///?Id=beckhoff-d8cd-4957-b2b8-b8cd53f4d9b3) | A variable of this type contains the parameters for an [MC\_AxUtiAutoIdent\_BkPlcMc](ms-xhelp:///?Id=beckhoff-6e26-4519-a6b1-d0581db76054) function block. |
| [ST\_TcMcAuxDataLabels](ms-xhelp:///?Id=beckhoff-50c8-4b5f-bdf7-0e14cb1fc422) | A variable of this type contains label texts for the client-specific axis parameters. |
| [ST\_TcHydAxParam](ms-xhelp:///?Id=beckhoff-12fe-4458-a931-b3c9fca583f2) | A variable of this type contains all the parameters for an axis. |
| [ST\_TcHydAxRtData](ms-xhelp:///?Id=beckhoff-1ffc-4f72-80ec-3f7c8585d12d) | A variable of this type contains the runtime data for an axis. |
| [ST\_TcPlcMcLogBuffer](ms-xhelp:///?Id=beckhoff-2e65-4b91-955d-12cfc3c231b1) | A variable with this structure forms the LogBuffer of the library. |
| [ST\_TcPlcMcLogEntry](ms-xhelp:///?Id=beckhoff-c2a3-4a8e-b580-6d17a51b8af8) | A variable with this structure contains a message of the LogBuffer of the library. |
| [ST\_TcPlcDeviceInput](ms-xhelp:///?Id=beckhoff-dec6-4dd6-a155-f200065a8d2d) | This structure contains the input image variables of an axis. |
| [ST\_TcPlcDeviceOutput](ms-xhelp:///?Id=beckhoff-fec4-45f2-b458-d8180069b32f) | This structure contains the output image variables of an axis. |
| [ST\_TcPlcRegDataItem](ms-xhelp:///?Id=beckhoff-4028-42e1-857f-5ce0a6d3d61c) | This structure contains a parameter set for a KL terminal. |
| [ST\_TcPlcRegDataTable](ms-xhelp:///?Id=beckhoff-0216-4cca-a486-a37a23eb2ef4) | This structure contains a parameter for a KL terminal. |
| [TRACK\_REF\_BkPlcMc](ms-xhelp:///?Id=beckhoff-ee5c-4cd0-a66f-7a08ab2a33b2) | In preparation. |

[TF5810 | TwinCAT 3 Hydraulic Positioning](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
