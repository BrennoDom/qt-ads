# Tag Types

## Library
tcplclib_tc3_packml

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc3\_PackML](ms-xhelp:///?Id=beckhoff-59be-4392-80fb-0b021151334d)
2. [Packaging Machine Functional Tag Description](ms-xhelp:///?Id=beckhoff-cfa1-4cf2-bed5-de71541a6707)
3. Tag Types

# Tag Types

PackTags are broken out into three groups; Command, Status and Administration. Command and Status tags contain data required for interfacing between machines and line control for coordination, or for recipe / parameter download. Command tags are "written" to and consumed by the machine program, as the “Information Receiver”, while status tags are produced by and read from the machine program. Administration Tags contain data collected by higher level systems for machine performance analysis, or operator information.

Each grouping of data should be in a contiguous grouping of registers to optimise communications.

Generally informational data is passed using OPC on an Ethernet-based communication network.

Command Tags are prefixed by “PMLc”.

Status Tags are prefixed by “PMLs”.

Administration Tags are prefixed by “PMLa”.

![10959316](/tcplclib_tc3_packml/1033/Images/png/1075777803__en-US__Web.png)

[TwinCAT 3 | PLC Library: Tc3\_PackML](ms-xhelp:///?Id=beckhoff-59be-4392-80fb-0b021151334d)
