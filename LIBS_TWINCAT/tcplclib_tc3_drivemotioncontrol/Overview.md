# Overview

## Library
tcplclib_tc3_drivemotioncontrol

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc3\_DriveMotionControl](ms-xhelp:///?Id=beckhoff-9642-4f70-a3aa-5117d509112d)
2. Overview

# Overview

The TwinCAT Motion Control PLC library Tc3\_DriveMotionControl contains function blocks for programming simple machine applications based on Beckhoff servo terminal technology. It is based on the PLCopen specification for Motion Control function blocks V2.0 ([www.PLCopen.org](http://www.PLCopen.org)).

|  |  |
| --- | --- |
| 31741019 | This library offers an alternative option for controlling simple movements without using TwinCAT NC PTP. The functionality is reduced compared to TwinCAT NC PTP. |

If the library is to be used in parallel with Tc2\_MC2, set the option "*Qualified access only*" = TRUE for one of the libraries.

This library can then be addressed via the corresponding namespace, e.g. Tc2\_MC2.MC\_Power.

Motion commands can be commanded directly to a servo terminal in the usual PLCopen-compliant manner.

![17233719](/tcplclib_tc3_drivemotioncontrol/1033/Images/png/18014398579661195__Web.png)

[TwinCAT 3 | PLC Library: Tc3\_DriveMotionControl](ms-xhelp:///?Id=beckhoff-9642-4f70-a3aa-5117d509112d)
