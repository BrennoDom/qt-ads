# PLC HMI

## Library
tcplclib_tc3_dali

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc3\_DALI](ms-xhelp:///?Id=beckhoff-3b50-4f78-8721-86f9c15e9bec)
2. [Appendix](ms-xhelp:///?Id=beckhoff-799a-4543-a757-72ecd85fb150)
3. [Commissioning and diagnosis](ms-xhelp:///?Id=beckhoff-0748-4e01-bcff-c71c095ae5b7)
4. PLC HMI

# PLC HMI

The PLC project **Tc3\_DALI\_Commissioning** offers the user the possibility to configure DALI devices and the KL6821 with the aid of the PLC HMI (see [Tc3\_DALI\_Commissioning\_V3.6.0.0.zip](https://infosys.beckhoff.com/content/1033/tcplclib_tc3_dali/Resources/zip/10466952971.zip)).

This project can be extended for specific applications, or it can only be used for configuration purposes. The KL6821 is supported as standard; the user can add the KL6811.

The dialogs offer not only functions for addressing control gears and control devices, but also for writing and reading parameters.

Using the drop-down menu, the user can select whether to parameterize control gears or control devices.

![15569626](/tcplclib_tc3_dali/1033/Images/gif/27021603741335947__Web.gif)

Addressing of the devices and querying of the addresses that are already assigned takes place under the **Addressing** tab, which is available for both control gears and sensors.

![5908907](/tcplclib_tc3_dali/1033/Images/gif/9007205231822475__Web.gif)

Parameters can be read based on selected short addresses and can be written, as far as possible.

![53180163](/tcplclib_tc3_dali/1033/Images/gif/9007205231851019__Web.gif)

There are also dialogs for

* Executing DALI commands
* Reading current states
* Reading and configuring group allocations
* Reading and configuring assignments within scenes
* Reading and writing the configuration of the following device types:

+ 0 (generic inputs, part 103)
+ 1 (push buttons, part 301)
+ 2 (absolute input devices, part 302)
+ 3 (occupancy sensors, part 303)
+ 4 (light sensor, part 304)
+ 6 (LED modules, part 207)

For this purpose, one page is available for reading the configuration and one for writing.

* Adjustment of the fading settings
* Reading and, if the vendor wishes, configuration of the memory banks.
* Memory bank 1 for the control gears (part 102) contains the extension (device type 50).
* The device type 51 (energy report) is available by querying the memory banks 202, 203 and 204.
* The device type 52 (diagnostics and maintenance) is available by querying the memory banks 205, 206 and 207.
* Configuration of the KL6821 (switching the power supply unit on/off, behavior on triggering of the K-Bus watchdog, behavior in case of rising or falling edges on the two digital inputs of the terminal, enablement of the process image after the inputs were actuated, deactivation of the blocking of the process image when using the digital inputs of the KL6821).

## Requirements

| Required PLC library | DALI Commissioning Tool |
| --- | --- |
| Tc3\_DALI from v3.6.0.0 | Tc3\_DALI\_Commissioning v3.6.0.0 |

[TwinCAT 3 | PLC Library: Tc3\_DALI](ms-xhelp:///?Id=beckhoff-3b50-4f78-8721-86f9c15e9bec)
