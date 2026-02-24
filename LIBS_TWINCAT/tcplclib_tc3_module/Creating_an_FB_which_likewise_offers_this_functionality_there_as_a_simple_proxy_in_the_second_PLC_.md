# Creating an FB which likewise offers this functionality there as a simple proxy in the second PLC,

## Library
tcplclib_tc3_module

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc3\_Module](ms-xhelp:///?Id=beckhoff-bcd3-40fe-aa49-602b4cdc62b7)
2. [Samples](ms-xhelp:///?Id=beckhoff-490b-4ce8-bb26-cd2b92b103ef)
3. [TcCOM\_Sample01\_PlcToPlc](ms-xhelp:///?Id=beckhoff-1aac-4aa9-9970-76eb4e225b7c)
4. Creating an FB which likewise offers this functionality there as a simple proxy in the second PLC,

# Creating an FB which likewise offers this functionality there as a simple proxy in the second PLC,

:   1. Create a PLC and append a new function block there.

* This proxy function block should provide the functionality which was programmed in the first PLC. It does this via an interface pointer of the type of the global interface I\_Calculation.

![19726002](/tcplclib_tc3_module/1033/Images/png/2342710027__Web.png)

:   2. In the declaration part of the function block declare as an output an interface pointer to the global interface which later provides the functionality outward.

![43316293](/tcplclib_tc3_module/1033/Images/png/2342711691__Web.png)

:   3. In addition create the object ID and the interface ID as local member variables.  
    While the interface ID is already available via a global list, the object ID is assigned via a link in the process image.

![54302323](/tcplclib_tc3_module/1033/Images/png/2288398347__Web.png)

:   4. Implement the PLC proxy function block. First add the GetInterfacePointer() method to the function block.  
    The interface pointer is fetched to the specified interface of the specified TcCOM object with the help of the [FW\_ObjMgr\_GetObjectInstance()](ms-xhelp:///?Id=beckhoff-b8a6-44df-acaa-44aa3a625bb0) function. This will only be executed if the object ID is valid and the interface pointer has not already been allocated. The object itself increments a reference counter.

![18958859](/tcplclib_tc3_module/1033/Images/png/2342717195__Web.png)

:   5. It is imperative to release the used reference again. To this end call the FW\_SafeRelease() function in the FB\_exit destructor of the function block.

![36412008](/tcplclib_tc3_module/1033/Images/png/2342721291__Web.png)

* This completes the implementation of the Proxy function block.

:   6. Instantiate the Proxy function block FB\_CalculationProxy in the application and call its method GetInterfacePointer() to get a valid interface pointer.  
    An instance of the proxy block is declared in the application to call the methods provided via the interface. The calls themselves take all place over the interface pointer defined as output of the function block. As is typical for pointers a prior null check must be made. Then the methods can be called directly, also via Intellisense.

![59272617](/tcplclib_tc3_module/1033/Images/png/2288419339__Web.png)

* The sample is ready for testing.

|  |  |
| --- | --- |
| 63691513 | Order irrelevant  The sequence in which the two PLCs start later is irrelevant in this implementation. |

[TwinCAT 3 | PLC Library:Tc3\_Module](ms-xhelp:///?Id=beckhoff-bcd3-40fe-aa49-602b4cdc62b7)
