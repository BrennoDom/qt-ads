# Osram

## Library
tcplclib_tc2_dali

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_DALI](ms-xhelp:///?Id=beckhoff-bad6-4627-b8ac-544f0eee130c)
2. [Programming](ms-xhelp:///?Id=beckhoff-1e7b-43d6-a8da-8e0049d24778)
3. [POUs](ms-xhelp:///?Id=beckhoff-3c92-4da6-86d7-db508adfb4f0)
4. [Third-party function blocks](ms-xhelp:///?Id=beckhoff-3be5-46f6-9609-796403dd277e)
5. Osram

# Osram

## Function blocks

Osram has defined its own special DALI commands. These commands extend beyond the possible DALI commands in accordance with the IEC 62386 standard. However, these commands are only applicable to certain Osram devices. Please contact Osram for a more detailed description of the commands.

| Name | Description |
| --- | --- |
| [FB\_DALIV2xOsramProfSensorCoupler](ms-xhelp:///?Id=beckhoff-bbb7-45a8-8d7d-766b8ce0ca16) | This function block evaluates the measured brightness and presence of the Osram DALI Professional Sensor Coupler. This function block can also be used to initialize the DALI control units. |
| [FB\_DALIV2xOsramProfPushbuttonCoupler](ms-xhelp:///?Id=beckhoff-0c28-406b-bb59-370be5623bab) | This function block evaluates the status of the digital input of the Osram DALI Professional Pushbutton Coupler. This function block can also be used to initialize the DALI control units. |
| FB\_DALIV2xOsramDisableSignalMode | Disables the *Input Signal Mode* for a channel. |
| FB\_DALIV2xOsramEnableSignalMode | Enables the *Input Signal Mode* for a channel. |
| FB\_DALIV2xOsramQueryConfigurationId | Reading the configuration for a channel. |
| FB\_DALIV2xOsramQueryInputDeviceType | Reading the device type. |
| FB\_DALIV2xOsramQueryInputValue | Reading the input value of a channel. |
| FB\_DALIV2xOsramQueryResolution | Queries the resolution of the input values of the control unit. |
| FB\_DALIV2xOsramStoreConfigurationId | Writes the configuration for a channel. |
| FB\_DALIV2xOsramIdentifySelectedDevice | Starts the identification routine for the selected control unit (random address and search address are the same). |
| FB\_DALIV2xOsramQueryChannelSize | Reads the number of channels supported by the control unit. |
| FB\_DALIV2xOsramQueryConfigurationFeature | Reads the possible configuration values for a channel. |
| FB\_DALIV2xOsramQueryDeviceError | Queries whether the control unit has detected an error. |
| FB\_DALIV2xOsramQueryStatus | Reads the device status. |
| FB\_DALIV2xOsramReadMemoryLocation | A byte is read from the memory of the control unit. |

Further Information

* [FB\_DALIV2xOsramProfPushbuttonCoupler](ms-xhelp:///?Id=beckhoff-0c28-406b-bb59-370be5623bab)
* [FB\_DALIV2xOsramProfSensorCoupler](ms-xhelp:///?Id=beckhoff-bbb7-45a8-8d7d-766b8ce0ca16)

[TwinCAT 3 | PLC Library: Tc2\_DALI](ms-xhelp:///?Id=beckhoff-bad6-4627-b8ac-544f0eee130c)
