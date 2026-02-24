# Overview

## Library
tcplclib_tc2_iofunctions

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_IoFunctions](ms-xhelp:///?Id=beckhoff-89f3-4b36-bb70-6247b05e611b)
2. [Function blocks](ms-xhelp:///?Id=beckhoff-a079-48d4-9b63-20dc13645a2c)
3. [Third party devices](ms-xhelp:///?Id=beckhoff-8141-420b-ab48-e4c3c40c9d6b)
4. [Phoenix IBS SC/I-T](ms-xhelp:///?Id=beckhoff-5871-41bd-a1ed-a635485281c8)
5. Overview

# Overview

The library offers a convenient possibility to execute the most important firmware services of the Phoenix IBS SC/I-T interbus card for bus control from the TwinCAT PLC. The following diagram illustrates the states and the transition conditions of the bus control.

## Bus Control

![55365254](/tcplclib_tc2_iofunctions/1033/Images/gif/59485067__en-US__Web.gif)

[SCIT\_ActivateConfiguration](ms-xhelp:///?Id=beckhoff-bf21-4edf-9d7e-974e2c7d3fcd): Executes the **Activate\_Configuration** command.

[SCIT\_DeactivateConfiguration](ms-xhelp:///?Id=beckhoff-2673-4981-9e36-3032874da614): Executes the **Deactivate\_Configuration** command.

[SCIT\_StartDataTransfer](ms-xhelp:///?Id=beckhoff-eb03-4cdc-a6cd-4464514a8a27): Executes the **Start\_Data\_Transfer** command.

[SCIT\_StopDataTransfer](ms-xhelp:///?Id=beckhoff-a657-4940-a350-d5196904d232): Executes the **Stop\_Data\_Transfer** command.

[SCIT\_AlarmStop](ms-xhelp:///?Id=beckhoff-6e11-4400-99a3-8c740259fc72): Executes the **Alarm\_Stop** command.

## Configuration

[SCIT\_ControlActiveConfiguration](ms-xhelp:///?Id=beckhoff-3342-4761-b6d4-f1b249a60d96): Is used to affect the active configuration of the Interbus devices. This command can be executed in the *PAR\_READY* state as well as when in the *ACTIVE* or *RUN* states. Single, dependent and grouped devices can be activated and deactivated in this way.

## Error diagnosis

[SCIT\_GetErrorInfo](ms-xhelp:///?Id=beckhoff-ce44-4e66-8b14-32286fb94520): Returns the error type and error location of an Interbus device after a bus error.

[SCIT\_ConfDevErrAll](ms-xhelp:///?Id=beckhoff-b9a5-4cf3-99af-a2809a2527f7): Acknowledge periphery errors of all devices.

[TwinCAT 3 | PLC Library: Tc2\_IoFunctions](ms-xhelp:///?Id=beckhoff-89f3-4b36-bb70-6247b05e611b)
