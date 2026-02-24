# Instantiating a TwinCAT++ class as a TwinCAT TcCOM Object

## Library
tcplclib_tc3_module

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc3\_Module](ms-xhelp:///?Id=beckhoff-bcd3-40fe-aa49-602b4cdc62b7)
2. [Samples](ms-xhelp:///?Id=beckhoff-490b-4ce8-bb26-cd2b92b103ef)
3. [TcCOM\_Sample02\_PlcToCpp](ms-xhelp:///?Id=beckhoff-4360-410c-b416-a7712740ef23)
4. Instantiating a TwinCAT++ class as a TwinCAT TcCOM Object

# Instantiating a TwinCAT++ class as a TwinCAT TcCOM Object

The TwinCAT C++ driver must be available on the target system. TwinCAT offers a deployment for this purpose, so that the components only have to be stored properly on the development computer.

The existing TwinCAT C++ driver as well as its TMC description file(s) are available as a driver archive. This archive (IncrementerCpp.zip) is unpacked in the following folder:  
*C:\TwinCAT\3.1\CustomConfig\Modules\IncrementerCpp\*

The TwinCAT Deployment copies the file(s) later in the following folder upon the activation of a configuration in the target system:  
*C:\TwinCAT\3.1\Driver\AutoInstall\*

:   1. Open a TwinCAT project or create a new project.

:   2. Add an instance of Class CIncrementModule in the solution under the node **TcCOM Objects**.

![58888592](/tcplclib_tc3_module/1033/Images/png/2284780811__Web.png)

|  |  |
| --- | --- |
| 60235282 | Creation of the C++ driver  In the documentation for TwinCAT C++ there is a detailed explanation on how C++ drivers for TwinCAT are created. To create the above-mentioned driver archive, **Publish TwinCAT Modules** is selected from the C++ project context as the last step in the creation of a driver. |

[TwinCAT 3 | PLC Library:Tc3\_Module](ms-xhelp:///?Id=beckhoff-bcd3-40fe-aa49-602b4cdc62b7)
