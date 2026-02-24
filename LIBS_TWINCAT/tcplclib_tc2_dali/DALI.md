# DALI

## Library
tcplclib_tc2_dali

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_DALI](ms-xhelp:///?Id=beckhoff-bad6-4627-b8ac-544f0eee130c)
2. DALI

# DALI

DALI (Digital Addressable Lighting Interface) is a definition for the standardization of digital interfaces between control gears (lamps) and control units (sensors). The standard (IEC 62386) allows the manufacturers of lighting components to implement complex lighting tasks easily and conveniently.

The KL6811 (DALI/DSI master) and KL6821 (² master) Bus Terminals are integrated into the Bus Terminal system as normal Bus Terminals and are therefore fieldbus-independent. The DALI data is forwarded to the DALI devices via the respective Bus Coupler. Bus controllers also offer a facility for decentralized execution of PLC programs in IEC61131-3.

## IEC 62386

DALI is specified in the IEC 62386 standard and offers advantages such as flexibility, simplicity, user friendliness and robustness. IEC 62386 has been revised several times and was extended considerably in November 2014 with the publication of the second revision. While in the first revision only control gears (lamps) were considered, from the second revision onwards control units (sensors) are also included. These are described in the respective section of IEC 62386:

|  |  |
| --- | --- |
| IEC 62386-101 | General system properties such as cabling, feed-in and telegram structure |
| IEC 62386-102 | General properties of the control gears |
|  | IEC 62386-201: Fluorescent lamps (device type 0) IEC 62386-202: Emergency lighting (device type 1) IEC 62386-203: Discharge lamps (device type 2) … |
| IEC 62386-103 | General properties of the control devices |
|  | IEC 62386-301: Push buttons IEC 62386-303: Occupancy sensor IEC 62386-304: Brightness sensor … |

The IEC 62386-101, IEC 62386-102 and IEC 62386-103 standards describe general properties, while the IEC 62386-2xx and IEC 62386-3xx standards specify the individual device types.

IEC 62386-103 and IEC 62386-3xx were included in Revision 2 of the DALI standard.

![3913996](/tcplclib_tc2_dali/1033/Images/jpg/4345193355__en-US__Web.jpg)

In each DALI line up to 64 control gears and up to 64 input devices can be connected. The KL6821 represents the DALI controller. One such device exists for each DALI line. Any number of DALI lines (KL6821) can be operated with a single TwinCAT controller.

## Communication

With regard to the communication, a distinction is made between three telegram types:

* 16-bit query, configuration and control telegram.
* 24-bit query, configuration and control telegram.
* 24-bit event telegram.

![35225966](/tcplclib_tc2_dali/1033/Images/jpg/4345187851__en-US__Web.jpg)

BF: backward frame  
FF: forward frame

## 16-bit telegrams

16-bit telegrams are always sent from a DALI controller to a DALI control gear. They are used for configuring the devices, querying parameters or sending control commands. For certain DALI commands the DALI control gear sends an 8-bit response. DALI control gears only send an 8-bit telegram when requested.

In the DALI library these commands are provided in the form of PLC function blocks with the prefix *FB\_DALIV2*, e.g. FB\_DALIV2QueryActualLevel().

## 24-bit telegrams

24-bit telegrams are always sent from a DALI controller to a DALI input device. They are used for configuring the devices, querying parameters or sending control commands. For certain DALI commands the DALI input device sends an 8-bit response.

In the DALI library these commands are provided in the form of PLC function blocks with the prefix *FB\_DALIV2x*, e.g. FB\_DALIV2xQueryOperatingMode().

## 24-bit events

DALI input devices are able to send events. They are always evaluated by the DALI controller and have a length of 24 bits.

Individual events can be filtered out with the function block [FB\_DALIV2xGetEventData()](ms-xhelp:///?Id=beckhoff-6432-4bdb-9c76-010ed74b7fc8) for further processing.

## Note

Further information on DALI can be found on the website of the DALI Activity Group (<http://www.dali-ag.org>) or the Digital Illumination Interface Alliance ([https://www.digitalilluminationinterface.org](http://www.dali-ag.org)) and in the IEC 62386 standard.

The KL6811 only supports the first revision of the DALI standard. It is not possible to operate control units (sensors) with the KL6811. The KL6821 is backward compatible with the KL6811, but it does not support DSI.

[TwinCAT 3 | PLC Library: Tc2\_DALI](ms-xhelp:///?Id=beckhoff-bad6-4627-b8ac-544f0eee130c)
