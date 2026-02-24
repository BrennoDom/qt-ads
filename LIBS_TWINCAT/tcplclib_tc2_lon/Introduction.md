# Introduction

## Library
tcplclib_tc2_lon

## Category
Motion Control

# Introduction

The Tc2\_LON library is an extensive TwinCAT PLC library for data exchange with LON devices. The communication with these devices is realized via SNVTs (**S**tandard **N**etwork **V**ariable **T**ypes). These SNVTs are defined in the LONMark (see also [LONMARK](http://www.lonmark.org) and [LONMARK Network Variables](http://www.lonmark.org)). For each SNVT there is a function block for sending and another function block for receiving.

This library should only be used in conjunction with a KL6401 (LON master terminal).

The SNVT should be configured with the [KS2000](ms-xhelp:///?Id=beckhoff-e152-481f-b2af-e39de4dfc40b) in the terminal.

The SNVTs are linked with a LON configuration tool (e.g. LonMaker from Echelon). This tool is not provided by Beckhoff.

The user of this library requires basic knowledge of the following:

* TwinCAT XAE
* KS2000
* PC and network knowledge
* Structure and properties of the Beckhoff Embedded PC and its Bus Terminal system
* Technology of LON devices / LON configuration tools
* Relevant safety regulations for building technical equipment

This software library is intended for building automation system partners of Beckhoff Automation GmbH & Co. KG. The system partners operate in the field of building automation and are concerned with the installation, commissioning, expansion, maintenance and service of measurement, control and regulating systems for the technical equipment of buildings.

The Tc2\_LON library is usable on all hardware platforms that support TwinCAT 3.1 or higher.

Hardware documentation in the Beckhoff information system:  
[KL6401](https://infosys.beckhoff.com/content/1033/kl6401/index.html).
