# Tag Types

## Library
tcplclib_tc3_packml_v2

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc3\_PackML\_V2](ms-xhelp:///?Id=beckhoff-962e-4424-bd3f-3a66f7e32e10)
2. [Packaging Machine Tags](ms-xhelp:///?Id=beckhoff-0c75-4616-a6ff-b521c2c6af13)
3. Tag Types

# Tag Types

PackTags are broken down into three groups: Command, Status and Administration. Command and State tags contain data for interfacing the machine with the line control for coordination or for downloading recipes/parameters. Command tags are transferred as “information recipients” to the machine program and “consumed” by it. State tags are created and read by the machine program. Administration tags contain data, which are collected by higher-level systems for machine performance analysis or operator information.

The grouping of data should take place in adjacent registers, in order to optimize the communication.

Information data are usually transferred via OPC in an Ethernet-based communication network.

The prefix of Command tags is “PMLc”.

The prefix of State tags is “PMLs”.

The prefix of Administration tags is “PMLa”.

![1953275](/tcplclib_tc3_packml_v2/1033/Images/png/1075777803__en-US__Web.png)

[TwinCAT 3 | PLC Library: Tc3\_PackML\_V2](ms-xhelp:///?Id=beckhoff-962e-4424-bd3f-3a66f7e32e10)
