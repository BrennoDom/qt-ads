# E_IPCDiag_ParameterKey

## Library
tcplclib_tc3_ipcdiag

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc3\_IPCDiag](ms-xhelp:///?Id=beckhoff-3a11-4a24-824c-cda994a70d48)
2. [Data types](ms-xhelp:///?Id=beckhoff-b9ab-473c-b827-d56bd995675b)
3. E\_IPCDiag\_ParameterKey

# E\_IPCDiag\_ParameterKey

This enumeration lists all parameters of the IPC diagnostics that can be read and, in some cases, written in a simple way with the function blocks from the library.

Below is an excerpt from the enumeration containing more than 150 parameters:

| Enumeration value | Comment |
| --- | --- |
| E\_IPCDiag\_ParameterKey.IPCDeviceName | IPC device name, STRING, read/write (MDP general area) |
| E\_IPCDiag\_ParameterKey.CPU\_Usage | CPU usage (%), UINT, read-only |
| E\_IPCDiag\_ParameterKey.CPU\_Temp | CPU temperature (°C), INT, read-only |
| E\_IPCDiag\_ParameterKey.Fan\_Speed | Fan speed (rpm), INT, read-only |
| E\_IPCDiag\_ParameterKey.NIC\_IPv4Address | IPv4 address, STRING, read/write |
| E\_IPCDiag\_ParameterKey.TC\_VersionBuild | TwinCAT build version, UINT, read-only |

Some parameters may exist several times. In this case, the function block [FB\_IPCDiag\_ReadParameter](ms-xhelp:///?Id=beckhoff-41de-431c-804d-3aa55cec49b6) reads all existing values at once and these values can be copied individually or all at once using the GetParameter() methods.

The parameters are subdivided into groups. Some of these groups correspond to the modules of the 'Configuration Area' in the MDP. Modules may be instanced several times. Accordingly, a parameter of a multi-instanced module exists several times or has a correspondingly large number of values.

On the other hand, there are list parameters whose identifier already makes this clear. According to the number of list entries, the parameter also exists here several times or has several values.

The comment for each enumeration entry contains the access possibility   
(e.g.: read-only) and the data types of the parameter value.

Not every parameter is available on every system. Hardware and software may differ and reflect the availability of the parameters accordingly.

For further information on the individual parameters, please refer to the documentation on the [Beckhoff Device Manager](https://infosys.beckhoff.de/content/1033/devicemanager/108086391319871755.html).

|  |  |
| --- | --- |
| 56511253 | Extensions  The parameters available herewith are continuously supplemented. It is recommended to use the latest version of the PLC library in order to take advantage of the full range of functions. |

[TwinCAT 3 | PLC Library: Tc3\_IPCDiag](ms-xhelp:///?Id=beckhoff-3a11-4a24-824c-cda994a70d48)
