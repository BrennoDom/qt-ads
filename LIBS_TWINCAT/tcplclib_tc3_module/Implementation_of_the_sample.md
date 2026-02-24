# Implementation of the sample

## Library
tcplclib_tc3_module

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc3\_Module](ms-xhelp:///?Id=beckhoff-bcd3-40fe-aa49-602b4cdc62b7)
2. [Samples](ms-xhelp:///?Id=beckhoff-490b-4ce8-bb26-cd2b92b103ef)
3. [TcCOM\_Sample13\_CppToPlc](ms-xhelp:///?Id=beckhoff-4cde-409e-97da-23b4bfcc2806)
4. Implementation of the sample

# Implementation of the sample

The PLC page adopted by [TcCOM Sample 01](ms-xhelp:///?Id=beckhoff-1aac-4aa9-9970-76eb4e225b7c). The function block registered there as TcCOM module offers the object ID allocated to it as an output variable.  
It is the C++ module’s task to make the offered interface of this function block accessible.

* A C++ project with a Cycle IO module is assumed.

:   1. In the TMC editor, create an interface pointer of the type I\_Calculation with the name Calculationn). Later access occurs via this.  
    ![17660485](/tcplclib_tc3_module/1033/Images/png/2312922251__Web.png)

:   2. The Data Area Inputs have already been created by the module wizard with the type Input-Destination. Here in the TMC editor you create an input of the type OTCID with the name oidProvider, via which the Object ID will be linked from the PLC later. ![24726637](/tcplclib_tc3_module/1033/Images/png/2312923915__Web.png)

:   3. All other symbols are irrelevant for the sample and can be deleted.

* The TMC-Code-Generator prepares the code accordingly.   
  In the header of the module some variables are created in order to carry out the methods calls later.  
  ![21213148](/tcplclib_tc3_module/1033/Images/png/2312925579__Web.png)  
  In the actual code of the module in CycleUpdate() the interface pointer is set using the object ID transmitted from the PLC. It is important that this happens in the CycleUpdate() and thus in real-time context, since the PLC must first provide the function block.   
  When this has taken place once, the methods can be called.   
  ![56700610](/tcplclib_tc3_module/1033/Images/png/2312927243__Web.png)  
  In addition, as can be seen above, the interface pointer is cleared when the program shuts down. This happens in the SetObjStateOS method.

:   4. Now build the C++ project.

:   5. Create an instance of the module.

:   6. Connect the input of the C++ module to the output of the PLC.  
    ![40543448](/tcplclib_tc3_module/1033/Images/png/2312928907__Web.png)

* The project can be started. When the PLC is running, the OID is made known through the mapping to the C++ instance. Once this has occurred, the method can be called.

[TwinCAT 3 | PLC Library:Tc3\_Module](ms-xhelp:///?Id=beckhoff-bcd3-40fe-aa49-602b4cdc62b7)
