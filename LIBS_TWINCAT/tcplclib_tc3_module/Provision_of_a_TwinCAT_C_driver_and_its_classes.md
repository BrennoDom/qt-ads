# Provision of a TwinCAT C++ driver and its classes

## Library
tcplclib_tc3_module

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc3\_Module](ms-xhelp:///?Id=beckhoff-bcd3-40fe-aa49-602b4cdc62b7)
2. [Samples](ms-xhelp:///?Id=beckhoff-490b-4ce8-bb26-cd2b92b103ef)
3. [TcCOM\_Sample03\_PlcCreatesCpp](ms-xhelp:///?Id=beckhoff-2ba2-4ef9-b8ef-adb8768d10dd)
4. Provision of a TwinCAT C++ driver and its classes

# Provision of a TwinCAT C++ driver and its classes

The TwinCAT C++ driver must be available on the target system. TwinCAT offers a deployment for this purpose, so that the components only have to be stored properly on the development computer.

The existing TwinCAT C++ driver as well as its TMC description file(s) are available as a driver archive. This archive (IncrementerCpp.zip) is unpacked in the following folder:  
*C:\TwinCAT\3.1\CustomConfig\Modules\IncrementerCpp\*

The TwinCAT Deployment copies the file(s) later in the following folder upon the activation of a configuration in the target system:  
*C:\TwinCAT\3.1\Driver\AutoInstall\*

:   1. Open a TwinCAT project or create a new project.

:   2. Select the required C++ driver in the solution under the **TcCOM Objects** node in the **Class Factories** tab.

* This ensures that the driver is loaded on the target system when TwinCAT starts up. In addition this selection provides for the described deployment.

![61441228](/tcplclib_tc3_module/1033/Images/png/2287174923__Web.png)

|  |  |
| --- | --- |
| 16100147 | Creation of the C++ driver  In the documentation for TwinCAT C++ there is a detailed explanation on how C++ drivers for TwinCAT are created. For Sample03 it is important to note that TwinCAT C++ drivers whose classes are supposed to be dynamically instantiated must be defined as “TwinCAT Module Class for RT Context”. The C++ Wizard offers a special template for this purpose. In addition this sample uses a TwinCAT C++ class which manages without TcCOM initialization data and without TcCOM parameters. |

[TwinCAT 3 | PLC Library:Tc3\_Module](ms-xhelp:///?Id=beckhoff-bcd3-40fe-aa49-602b4cdc62b7)
