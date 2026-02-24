# Samples

## Library
tcplclib_tc3_module

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc3\_Module](ms-xhelp:///?Id=beckhoff-bcd3-40fe-aa49-602b4cdc62b7)
2. Samples

# Samples

The [TcCOM\_Sample01 sample](ms-xhelp:///?Id=beckhoff-1aac-4aa9-9970-76eb4e225b7c) shows how TcCOM communication can take place between two PLCs. In the process functionalities from one PLC are directly called up from the other PLC.

The [TcCOM\_Sample02 sample](ms-xhelp:///?Id=beckhoff-4360-410c-b416-a7712740ef23) shows how a PLC application can use functionalities of an existing instance of a TwinCAT C++ class. In this way separate algorithms written C++ (or Matlab) can be used easily in the PLC.   
Although in the event of the use of an existing TwinCAT C++ driver the TwinCAT C++ license is required on the target system, a C++ development environment is not necessary on the target system or on the development computer.

The [TcCOM\_Sample03 sample](ms-xhelp:///?Id=beckhoff-2ba2-4ef9-b8ef-adb8768d10dd) shows how a PLC application uses functionalities of a TwinCAT C++ class by generating an instance of C++ class at the same time. In comparison to the previous sample this can offer increased flexibility.

You will find additional programming examples in the documentation of TwinCAT 3 C++. For example, it describes an additional option for calling an algorithm written in C++ from a PLC program (Sample11). In contrast to TcCOM\_Sample02, here a wrapper module is programmed that each interface method implements itself. Therefore this variant is more complex. However, if you have to forego interface pointers calling the functionalities in the PLC application due to users, this variant offers an option for doing this.

Another example in the documentation of TwinCAT 3 C++ shows how a TwinCAT C++ Module calls up a method of a function block of the PLC by TcCOM interface (Sample13).

Further Information

* [TcCOM\_Sample01\_PlcToPlc](ms-xhelp:///?Id=beckhoff-1aac-4aa9-9970-76eb4e225b7c)
* [TcCOM\_Sample02\_PlcToCpp](ms-xhelp:///?Id=beckhoff-4360-410c-b416-a7712740ef23)
* [TcCOM\_Sample03\_PlcCreatesCpp](ms-xhelp:///?Id=beckhoff-2ba2-4ef9-b8ef-adb8768d10dd)
* [TcCOM\_Sample13\_CppToPlc](ms-xhelp:///?Id=beckhoff-4cde-409e-97da-23b4bfcc2806)

[TwinCAT 3 | PLC Library:Tc3\_Module](ms-xhelp:///?Id=beckhoff-bcd3-40fe-aa49-602b4cdc62b7)
