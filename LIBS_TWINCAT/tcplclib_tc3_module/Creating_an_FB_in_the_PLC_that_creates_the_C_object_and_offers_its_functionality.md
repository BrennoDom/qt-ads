# Creating an FB in the PLC that creates the C++ object and offers its functionality

## Library
tcplclib_tc3_module

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc3\_Module](ms-xhelp:///?Id=beckhoff-bcd3-40fe-aa49-602b4cdc62b7)
2. [Samples](ms-xhelp:///?Id=beckhoff-490b-4ce8-bb26-cd2b92b103ef)
3. [TcCOM\_Sample03\_PlcCreatesCpp](ms-xhelp:///?Id=beckhoff-2ba2-4ef9-b8ef-adb8768d10dd)
4. Creating an FB in the PLC that creates the C++ object and offers its functionality

# Creating an FB in the PLC that creates the C++ object and offers its functionality

:   1. Create a PLC and append a new function block there.   
    This Proxy function block should provide the functionality that was programmed in C++. It manages this via an interface pointer that was defined by C++ and is known in the PLC due to the TMC description file.   
    ![10683599](/tcplclib_tc3_module/1033/Images/png/2343018891__Web.png)

:   2. In the declaration part of the function block declare as an output an interface pointer to the interface (IIncrement) which later provides the functionality outward.   
    ![29043529](/tcplclib_tc3_module/1033/Images/png/2343020555__Web.png)

:   3. Create class ID and the interface ID as member variables.  
    While the interface ID is already available via a global list, the class IDs, provided they are not yet supposed to be known, are determined by other means. When you open the TMC description file of the associated C++ driver you will find the corresponding GUID there.   
    ![60065170](/tcplclib_tc3_module/1033/Images/png/2287297419__Web.png)

:   4. Add the FB\_init constructor method to the PLC Proxy function block.  
    For the case, that it is not an online change but rather the initialization of the function block, a new TcCOM object (Class instance of the specified class) is created and the interface pointer to the specified interface is obtained. In the process the used [FW\_ObjMgr\_CreateAndInitInstance() function](ms-xhelp:///?Id=beckhoff-6fd2-4107-995b-fcb0b3c16870) is also given the name and the destination state of the TcCOM object. These two parameters are declared here as input parameters of the FB\_init method, whereby they are to be specified in the instantiation of the Proxy function block. The TwinCAT C++ class to be instantiated manages without TcCOM initialization data and without TcCOM parameters.  
    In the case of this function call the object itself increments a reference counter.   
    ![3715619](/tcplclib_tc3_module/1033/Images/png/2343025291__Web.png)

:   5. It is imperative to release the used reference again and to delete the object, provided it is no longer being used. To this end call the [FW\_ObjMgr\_DeleteInstance()](ms-xhelp:///?Id=beckhoff-56ac-4d20-9507-131f65649bed) function in the FB\_exit destructor of the function block.   
    ![33440573](/tcplclib_tc3_module/1033/Images/png/2343026955__Web.png)

* This completes the implementation of the Proxy function block.

:   6. Declare an instance of the Proxy function block to call the methods provided via the interface in the application. The calls themselves take all place over the interface pointer defined as output of the function block. As is typical for pointers a prior null check must be made. Then the methods can be called directly, also via Intellisense.   
    ![32529705](/tcplclib_tc3_module/1033/Images/png/2343028619__Web.png)

* The sample is ready for testing.

[TwinCAT 3 | PLC Library:Tc3\_Module](ms-xhelp:///?Id=beckhoff-bcd3-40fe-aa49-602b4cdc62b7)
