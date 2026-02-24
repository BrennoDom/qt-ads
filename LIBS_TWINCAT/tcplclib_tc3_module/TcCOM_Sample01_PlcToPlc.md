# TcCOM_Sample01_PlcToPlc

## Library
tcplclib_tc3_module

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc3\_Module](ms-xhelp:///?Id=beckhoff-bcd3-40fe-aa49-602b4cdc62b7)
2. [Samples](ms-xhelp:///?Id=beckhoff-490b-4ce8-bb26-cd2b92b103ef)
3. TcCOM\_Sample01\_PlcToPlc

# TcCOM\_Sample01\_PlcToPlc

This sample describes a TcCOM communication between two PLCs.

Functionalities provided by a function block in the first PLC (also called "provider" in the sample), are called from the second PLC (also called "caller" in the sample). To this end it is not necessary for the function block or its program code to be copied. Instead the program works directly with the object instance in the first PLC.

Both PLCs must be in a TwinCAT runtime. In this connection a function block offers its methods system-wide via a globally defined interface and represents itself a TcCOM object. As is the case with every TcCOM object, such a function block is also listed at runtime in the **TcCOM Objects** node.

![66803900](/tcplclib_tc3_module/1033/Images/png/2257466507__Web.png)

The procedure is explained in the following sub-chapters:

* [Creating an FB in the first PLC that provides its functionality globally](ms-xhelp:///?Id=beckhoff-0117-4d02-9e31-acd38e862f83)
* [Creating an FB in the second PLC that, as a simple proxy, also offers this functionality there](ms-xhelp:///?Id=beckhoff-79d7-4eb8-a275-cd3addc8b146)
* [Execution of the sample project](ms-xhelp:///?Id=beckhoff-08de-4017-af28-9334dddd62dc)

Downloading the sample: [TcCOM\_Sample01\_PlcToPlc.zip](https://infosys.beckhoff.com/content/1033/tcplclib_tc3_module/Resources/zip/9007201597787659.zip)

|  |  |
| --- | --- |
| 64364196 | Race Conditions in the case of Multi-Tasking (Multi-Threading) use  The function block that provides its functionality globally is instantiated in the first PLC. It can be used there like any function block. In addition, if it is used from a different PLC (or, for example, from a C++ module), make sure that the methods offered are thread-safe, as the various calls could take place simultaneously from different task contexts or mutually interrupt one another, depending on the system configuration. In this case the methods must not access member variables of the function block or global variables of the first PLC. If this should be absolutely necessary, prevent simultaneous access. Observe the function TestAndSet() from the Tc2\_System library. |

## System requirements

| TwinCAT version | Hardware | Libraries to be integrated |
| --- | --- | --- |
| TwinCAT 3.1, Build 4020 | x86, x64, ARM | Tc3\_Module |

Further Information

* [Creating an FB which provides its functionality globally in the first PLC](ms-xhelp:///?Id=beckhoff-0117-4d02-9e31-acd38e862f83)
* [Creating an FB which likewise offers this functionality there as a simple proxy in the second PLC,](ms-xhelp:///?Id=beckhoff-79d7-4eb8-a275-cd3addc8b146)
* [Execution of the sample project](ms-xhelp:///?Id=beckhoff-08de-4017-af28-9334dddd62dc)

[TwinCAT 3 | PLC Library:Tc3\_Module](ms-xhelp:///?Id=beckhoff-bcd3-40fe-aa49-602b4cdc62b7)
