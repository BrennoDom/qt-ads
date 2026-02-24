# Execution of the sample project

## Library
tcplclib_tc3_module

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc3\_Module](ms-xhelp:///?Id=beckhoff-bcd3-40fe-aa49-602b4cdc62b7)
2. [Samples](ms-xhelp:///?Id=beckhoff-490b-4ce8-bb26-cd2b92b103ef)
3. [TcCOM\_Sample01\_PlcToPlc](ms-xhelp:///?Id=beckhoff-1aac-4aa9-9970-76eb4e225b7c)
4. Execution of the sample project

# Execution of the sample project

:   1. Select the destination system and compile the project.

:   2. Enable the TwinCAT configuration and execute a log-in and start both PLCs.

* In the online view of the PLC application “Provider” the generated object ID of the C++ object can be seen in the PLC function block FB\_Calculation. The project node “TcCOM Objects” keeps the generated object with its object ID and the selected name in its list.

![36352712](/tcplclib_tc3_module/1033/Images/png/2288423563__Web.png)

* In the online view of the PLC application “Caller” the Proxy function block has been allocated the same object ID via the process image. The interface pointer has a valid value and the methods are executed.

![58738960](/tcplclib_tc3_module/1033/Images/png/2288425995__Web.png)

[TwinCAT 3 | PLC Library:Tc3\_Module](ms-xhelp:///?Id=beckhoff-bcd3-40fe-aa49-602b4cdc62b7)
