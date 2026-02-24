# Creating an FB in the PLC that, as a simple proxy, offers the functionality of the C++ object

## Library
tcplclib_tc3_module

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc3\_Module](ms-xhelp:///?Id=beckhoff-bcd3-40fe-aa49-602b4cdc62b7)
2. [Samples](ms-xhelp:///?Id=beckhoff-490b-4ce8-bb26-cd2b92b103ef)
3. [TcCOM\_Sample02\_PlcToCpp](ms-xhelp:///?Id=beckhoff-4360-410c-b416-a7712740ef23)
4. Creating an FB in the PLC that, as a simple proxy, offers the functionality of the C++ object

# Creating an FB in the PLC that, as a simple proxy, offers the functionality of the C++ object

:   1. Create a PLC and append a new function block there.   
    This Proxy function block should provide the functionality that was programmed in C++. It is able to do this via an interface pointer that was defined from the C++ class and is known in the PLC due to the TMC description file.  
    ![5246632](/tcplclib_tc3_module/1033/Images/png/2342811787__Web.png)

:   2. In the declaration part of the function block declare as an output an interface pointer to the interface which later provides the functionality outward.

:   3. Create the object ID and the interface ID as local member variables.  
    While the interface ID is already available via a global list, the object ID is allocated via the TwinCAT symbol initialization. The TcInitSymbol attribute ensures that the variable appears in a list for external symbol initialization. The object ID of the created C++ object should be allocated.  
    ![47219689](/tcplclib_tc3_module/1033/Images/png/2285711499__Web.png)

* The object ID is displayed upon selection of the object under the **TcCOM Objects** node.  
  Provided the TcInitSymbol attribute was used, the list of symbol initializations is located in the node of the PLC instance in the **Symbol Initialization** tab.  
  ![22324024](/tcplclib_tc3_module/1033/Images/png/2284989835__Web.png)

:   4. Here, assign an existing object ID to the symbol name of the variable by drop-down. This value is assigned when the PLC is downloaded so it can be defined prior to the PLC run-time. New symbol initializations or changes are accordingly entered with a new download of the PLC.  
    ![66698493](/tcplclib_tc3_module/1033/Images/png/2284991499__Web.png)As an alternative, the passing of the object ID could also be implemented by means of process image linking as implemented in the first sample ([TcCOM\_Sample01\_PlcToPlc](ms-xhelp:///?Id=beckhoff-1aac-4aa9-9970-76eb4e225b7c)).

:   5. Implement the PLC Proxy function block.  
    First the FB\_init constructor method is added to the function block. For the case that it is no longer an OnlineChange but rather the initialization of the function block, the interface pointer to the specified interface of the specified TcCOM object is obtained with the help of the function [FW\_ObjMgr\_GetObjectInstance()](ms-xhelp:///?Id=beckhoff-b8a6-44df-acaa-44aa3a625bb0). In this connection the object itself increments a reference counter.  
    ![63415529](/tcplclib_tc3_module/1033/Images/png/2342816523__Web.png)

:   6. It is imperative to release the used reference again. To this end call the [FW\_SafeRelease() function](ms-xhelp:///?Id=beckhoff-818e-43af-a421-fa6c2298170d) in the FB\_exit destructor of the function block.  
    ![33868853](/tcplclib_tc3_module/1033/Images/png/2342818187__Web.png)

* This completes the implementation of the Proxy function block.

:   7. Declare an instance of the Proxy function block to call the methods provided via the interface in the application.  
    The calls themselves take all place over the interface pointer defined as output of the function block. As is typical for pointers a prior null check must be made. Then the methods can be called directly, also via Intellisense.  
    ![36384226](/tcplclib_tc3_module/1033/Images/png/2342822923__Web.png)

* The sample is ready for testing.

[TwinCAT 3 | PLC Library:Tc3\_Module](ms-xhelp:///?Id=beckhoff-bcd3-40fe-aa49-602b4cdc62b7)
