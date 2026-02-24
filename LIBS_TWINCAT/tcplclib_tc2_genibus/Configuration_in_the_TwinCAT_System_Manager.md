# Configuration in the TwinCAT System Manager

## Library
tcplclib_tc2_genibus

## Category
Motion Control

# Configuration in the TwinCAT System Manager

If the PLC program has been compiled without error, it is important that the communication variables in the TwinCAT System Manager are assigned to the correct task. Otherwise they would not be queried or written with the desired cycle time.  
 After reading in the PLC program, it is usually the case that the communication variables *stInData* and *stOutData* are assigned to the slower MAIN task. These have to be pulled into the fast task – in this case “Background” – by drag & drop.

![27155410](/tcplclib_tc2_genibus/1033/Images/jpg/2073618059__en-US__Web.jpg)

This should result in the following picture:

![43072099](/tcplclib_tc2_genibus/1033/Images/jpg/2073625995__en-US__Web.jpg)

The communication variables must now be linked to the hardware in use. The following options are available for this:

* [OnBoard RS485 interface (PcComm)](ms-xhelp:///?Id=beckhoff-e581-4b77-bb4d-7a9720d69806)
* [KL6021 (5Byte)](ms-xhelp:///?Id=beckhoff-3c87-4e97-8647-06be12a34c3d)
* [KL6041 (22Byte)](ms-xhelp:///?Id=beckhoff-d1d9-4986-a723-1331803e5358)
* [EL6021 (22Byte)](ms-xhelp:///?Id=beckhoff-c98f-4491-a63a-cc11503711bd)
