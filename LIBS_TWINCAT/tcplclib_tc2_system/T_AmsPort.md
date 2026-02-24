# T_AmsPort

## Library
tcplclib_tc2_system

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_System](ms-xhelp:///?Id=beckhoff-9909-45da-a773-a2ae0accd61a)
2. [Data types](ms-xhelp:///?Id=beckhoff-7553-4b92-b20d-33716049fde4)
3. T\_AmsPort

# T\_AmsPort

A variable of this type contains the ADS port number. ADS devices in the TwinCAT network are identified by an AMS network address and a port number. The following port numbers are invariably specified on every individual TwinCAT system.

```
TYPE T_AmsPort : UINT;  
END_TYPE
```

**Table with specified ADS port numbers:**

| ADS device | Port number |
| --- | --- |
| Cam controller | 900 |
| Runtime system 1 Runtime system 2 Runtime system 3 Runtime system 4 Runtime system 5 Runtime system n | Runtime system 1: 851 (in TwinCAT 2: 801) Runtime system 2: 852 (in TwinCAT 2: 811) Runtime system 3: 853 (in TwinCAT 2: 821) Runtime system 4: 854 (in TwinCAT 2: 831) Runtime system 5: 855 Runtime system n: 850 + n, and so on |
| NC | 500 |
| Reserved | 400 |
| I/O | 300 |
| Real-time core | 200 |
| Event System (logger) | 100 |

Up to four independent PLC runtime systems (PLC projects) can run on a TwinCAT 2 system; each PLC project is to be regarded as a stand-alone PLC. The port number and the network address are both required as input parameters when the ADS blocks are called.

The ADS ports from 800 to 899 are generally available for the PLC in TwinCAT3. In order to separate TwinCAT 2 and TwinCAT 3 systems, however, we recommend using only the ports from 851 to 899.

If you set the ADS port with the help of the dialog, port 851 is displayed as the lowest port that can be set. In order to use the range 800-850, you need to type in the port number.

Proceed as follows to enter the port number via the dialog box:

:   1. Right-click the desired PLC project.

:   2. Click **Change ADS Port**.

![61772230](/tcplclib_tc2_system/1033/Images/png/8118176011__Web.png)

* The dialog box opens.

![19079158](/tcplclib_tc2_system/1033/Images/png/8116164491__Web.png)

:   3. Select the desired port number using the arrow keys or type in the desired port number.

:   4. Confirm the entry with **OK**.

* The port number has been entered in the system.

|  |  |
| --- | --- |
| 37494699 | To ensure separation between TwinCAT 2 and TwinCAT 3 systems, we recommend using only the ADS ports from 851 to 899.  ADS ports outside the range from 800 bis 899 will not be accepted by the input system. |

## Requirements

| Development environment | Target system type | PLC libraries to include (Category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_System (System) |

[TwinCAT 3 | PLC Library: Tc2\_System](ms-xhelp:///?Id=beckhoff-9909-45da-a773-a2ae0accd61a)
