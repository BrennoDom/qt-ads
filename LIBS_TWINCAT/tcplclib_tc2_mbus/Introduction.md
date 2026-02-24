# Introduction

## Library
tcplclib_tc2_mbus

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_MBus](ms-xhelp:///?Id=beckhoff-18e3-4e49-a9fc-7977791d6960)
2. Introduction

# Introduction

The Tc2\_MBus library is a comprehensive TwinCAT PLC library for reading M-Bus devices.

The application of this PLC library significantly simplifies the engineering in these areas of building technical equipment.

The function blocks are object-oriented and characterized by a self-contained, more or less complex function.

The input parameters form the interface to the user. The parameters can be used to adapt the function block to its specific task within the associated system.

Thanks to strongly object-oriented encapsulation of complex system functions within the function blocks, comprehensive system programs can be set up with a few function blocks. The blocks are linked to each other via a small number of PLC variables.

The status of all objects is indicated through a large number of different output variables at the function blocks. The simplifies the connection of HMI and visualization systems.

These features offer the following benefits for system programmers during system setup and for system operators during operation:

* Faster creation of system programs.
* Faster system parameterization and commissioning.
* Guarantee of a very large range of system functions at all times.
* Improved readability of programs (prerequisite for long-term maintainability and expandability of the systems)
* Improved reusability of templates for systems or system components
* Easier familiarization of personnel.
* Easier extension of existing systems.
* Programs are easier to document.

The user of this library requires basic knowledge of the following:

* TwinCAT XAE
* PC and network knowledge
* Structure and properties of the Beckhoff Embedded PC and its Bus Terminal system
* Technology of M-Bus devices
* Relevant safety regulations for building technical equipment

This software library is intended for building automation system partners of Beckhoff Automation GmbH & Co. KG. The system partners operate in the field of building automation and are concerned with the installation, commissioning, expansion, maintenance and service of measurement, control and regulating systems for the technical equipment of buildings.

The Tc2\_MBus library is usable on all hardware platforms that support TwinCAT 3.1 or higher.

Hardware documentation in the Beckhoff information system:

<https://infosys.beckhoff.com/content/1033/kl6781/index.html>

|  |  |
| --- | --- |
| 58950555 | Preferred format: LReal.  M-Bus devices may supply very large values (the DWord value range may be exceeded). They are therefore output in string format. Conversions to Real format may lead to inaccuracies/invalid values. Conversions to LReal format are therefore preferable. |

[TwinCAT 3 | PLC Library: Tc2\_MBus](ms-xhelp:///?Id=beckhoff-18e3-4e49-a9fc-7977791d6960)
