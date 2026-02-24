# Communication

## Library
tcplclib_tc3_dali

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc3\_DALI](ms-xhelp:///?Id=beckhoff-3b50-4f78-8721-86f9c15e9bec)
2. [DALI](ms-xhelp:///?Id=beckhoff-7090-4d8c-9e10-2e356c321516)
3. Communication

# Communication

With regard to the communication, a distinction is made between three telegram types:

* 16-bit query, configuration and control telegram.
* 24-bit query, configuration and control telegram.
* 24-bit event telegram.

![27694303](/tcplclib_tc3_dali/1033/Images/jpg/5839436427__en-US__Web.jpg)

BF: backward frame  
FF: forward frame

## 16-bit telegrams

16-bit telegrams are always sent from a DALI controller to a DALI control gear. They are used for configuring the devices, querying parameters or sending control commands. For certain DALI commands the DALI control gear sends an 8-bit response. DALI control gears only send an 8-bit telegram when requested.

In the DALI library these commands are provided in the form of PLC function blocks with the prefix FB\_DALI102, e.g. FB\_DALI102QueryActualLevel.

## 24-bit telegrams

24-bit telegrams are always sent from a DALI controller to a DALI control device. They are used for configuring the devices, querying parameters or sending control commands. For certain DALI commands the DALI input device sends an 8-bit response.

In the DALI library these commands are provided in the form of PLC function blocks with the prefix FB\_DALI103, e.g. FB\_DALI103QueryOperatingMode.

## 24-bit events

DALI input devices are able to send events. They are always evaluated by the DALI controller and have a length of 24 bits.

Individual events can be filtered out and further processed with the function blocks FB\_DALIGetInputNotification and FB\_DALIGetPowerCycleNotification.

|  |  |
| --- | --- |
| 47922135 | Further information on DALI can be found on the homepage of the Digital Illumination Interface Alliance (<https://www.dali-alliance.org>) and in the IEC 62386 standard. |

|  |  |
| --- | --- |
| 28646034 | The KL6811 only supports the first revision of the DALI standard. It is not possible to operate control devices with the KL6811. |

[TwinCAT 3 | PLC Library: Tc3\_DALI](ms-xhelp:///?Id=beckhoff-3b50-4f78-8721-86f9c15e9bec)
