# Creating an FB which provides its functionality globally in the first PLC

## Library
tcplclib_tc3_module

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc3\_Module](ms-xhelp:///?Id=beckhoff-bcd3-40fe-aa49-602b4cdc62b7)
2. [Samples](ms-xhelp:///?Id=beckhoff-490b-4ce8-bb26-cd2b92b103ef)
3. [TcCOM\_Sample01\_PlcToPlc](ms-xhelp:///?Id=beckhoff-1aac-4aa9-9970-76eb4e225b7c)
4. Creating an FB which provides its functionality globally in the first PLC

# Creating an FB which provides its functionality globally in the first PLC

:   1. Create a PLC and prepare a new function block (FB) (here: FB\_Calculation). Derive the function block from the [TcBaseModuleRegistered](ms-xhelp:///?Id=beckhoff-f3ea-41a6-b69c-7e7d3c1e0a59) class, so that an instance of this function block is not only available in the same PLC, but can also be reached from a second.  
    **Note**: as an alternative you can also modify an FB in an existing PLC.

![42406858](/tcplclib_tc3_module/1033/Images/png/2311005707__Web.png)

:   2. The function block must offer its functionality by means of methods. These are defined in a global interface, whose type is system-wide and known regardless of programming language. To create a global interface, open the Context menu in the “Interface” tab of System Properties and choose the option “New”.

* The TMC Editor opens, which provides you with support in creating a global interface.

![46117407](/tcplclib_tc3_module/1033/Images/png/2288106379__Web.png)

:   3. Specify the name (here: I\_Calculation) and append the desired methods. The interface is automatically derived from ITcUnknown, in order to fulfill the TwinCAT TcCOM module concept.

![12403484](/tcplclib_tc3_module/1033/Images/png/2288110731__Web.png)

:   4. Specify the name of the methods analogously (here: Addition() and Subtraction()) and select HRESULT as return data type. This return type is mandatory if this type of TcCOM communication should be implemented.

:   5. Specify the method parameters last and then close the TMC Editor.

![44522499](/tcplclib_tc3_module/1033/Images/png/2288317963__Web.png)

:   6. Now implement the I\_Calculation interface in the FB\_Calculation function block and append the c++\_compatible attribute.

![65158171](/tcplclib_tc3_module/1033/Images/png/2288320395__Web.png)

:   7. Choose the “Implement interfaces...” option in the Context menu of the function block in order to obtain the methods belonging to this interface.

![49552630](/tcplclib_tc3_module/1033/Images/png/2288322827__Web.png)

:   8. Delete the two methods TcAddRef()and TcRelease() because the existing implementation of the base class should be used.

![43320494](/tcplclib_tc3_module/1033/Images/png/2288325259__Web.png)

:   9. Create the FB\_reinit() method for the FB\_Calculation function block and call the basic implementation. This ensures that the FB\_reinit() method of the base class will run during the online change. This is imperative.

![54340131](/tcplclib_tc3_module/1033/Images/png/2288327691__Web.png)

:   10. Implement the TcQueryInterface() method of the [Interface ITcUnknown](ms-xhelp:///?Id=beckhoff-c839-4bdf-98ea-b60f82d20e77). Via this method it is possible for other TwinCAT components to obtain an interface pointer to an instance of this function block and thus actuate method calls. The call for TcQueryInterface is successful if the function block or its base class provides the interface queried by means of iid (Interface ID). For this case the handed over interface pointer is allocated the address to the function block type-changed and the reference counter is incremented by means of TcAddRef().

:   11. Fill the two methods Addition() and Subtraction() with the corresponding code to produce the functionality: `nRes := nIn1 + nIn2` and `nRes := nIn1 - nIn2`

:   12. Add one or more instances of this function block in the MAIN program block or in a global variable list.

* The implementation in the first PLC is complete.

![19299134](/tcplclib_tc3_module/1033/Images/png/2288384523__Web.png)

* After compiling the PLC, the object ID of the TcCOM object which represents the instance of FB\_Calculation is available as an outlet in the in the process image.

![39474480](/tcplclib_tc3_module/1033/Images/png/2288386187__Web.png)

[TwinCAT 3 | PLC Library:Tc3\_Module](ms-xhelp:///?Id=beckhoff-bcd3-40fe-aa49-602b4cdc62b7)
