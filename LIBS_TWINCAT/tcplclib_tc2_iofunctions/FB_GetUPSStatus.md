# FB_GetUPSStatus

## Library
tcplclib_tc2_iofunctions

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_IoFunctions](ms-xhelp:///?Id=beckhoff-89f3-4b36-bb70-6247b05e611b)
2. [Function blocks](ms-xhelp:///?Id=beckhoff-a079-48d4-9b63-20dc13645a2c)
3. [Beckhoff UPS (configured with Windows UPS Service](ms-xhelp:///?Id=beckhoff-6247-4bba-89cf-f687a8658bf0)
4. FB\_GetUPSStatus

# FB\_GetUPSStatus

![34731002](/tcplclib_tc2_iofunctions/1033/Images/png/9007199314219659__Web.png)

**Requirements:**

* Beckhoff UPS software components have been installed:

+ Windows 7, Windows Embedded Standard 7 and higher: Configuration dialog under "*Start->Programs->Beckhoff->UPS Software Components"*.
+ NT4, Win2K, WinXP, WinXP embedded: Additional tabs under "*Control Panel->Power Options->Beckhoff UPS Configuration"* or "*Control Panel->Power Options->UPS*".
+ Beckhoff CE devices with 24V UPS support are delivered with a special Beckhoff Battery Driver for Windows CE. In these devices the driver is included in the standard CE image.

* The UPS has been activated and configured. You can find more information about UPS configuration in the corresponding advanced UPS software and device documentation.

+ Windows 7, Windows Embedded Standard 7 and higher: Configuration dialog under "*Start->Programs->Beckhoff->UPS Software Components"*.
+ NT4, Win2K, WinXP, WinXP embedded: Configuration dialog under "*Control Panel->Power Options->Beckhoff UPS Configuration"*.
+ Windows CE: By default the UPS function is disabled and must be enabled via a RegFile. Newer images have a configuration dialog under "*Start->Control Panel->BECKHOFF UPS Configuration"*.

The function block FB\_GetUPSStatus reads the status of the UPS hardware from the PLC. The function block is level triggered, which means that the status information of the UPS is only cyclically read while the *bEnable* input is set. To maintain system loading at a low level, the status information is only read approximately every 4.5 s. When the *bValid* output is set, the most recently read data is valid. The most recent read cycle was, in other words, executed without error. If an error occurs, the read cycle is repeated, and the error signal is automatically reset as soon as the cause of the error (e.g. no communication with the UPS) has been corrected.

## VAR\_INPUT

```
VAR_INPUT  
    sNetId : T_AmsNetId;  
    nPort  : T_AmsPort;(* 0 = Windows UPS service / Windows Battery Driver *)  
 bEnable   : BOOL;  
END_VAR
```

**sNetId**: A string with the network address of the TwinCAT computer whose UPS status is to be read can be entered here (type: T\_AmsNetID). If it is to be run on the local computer, an empty string can be entered.

**nPort**: The ADS port number (type: T\_AmsPort). Set this value to zero. Other port numbers are reserved for future applications.

**bEnable**: The UPS status is read cyclically if this input is set.

## VAR\_OUTPUT

```
VAR_OUTPUT  
    bValid     :BOOL;  
    bError     :BOOL;  
    nErrId     :UDINT;  
    stStatus   :ST_UPSStatus;  
END_VAR
```

**bValid**: If this output is set, the data in the ST\_UPSstatus structure are valid (no error occurred during the last reading cycle).

**bError**: This output is set if an error occurred when executing the function.

**nErrId**: Supplies the [ADS error number](ms-xhelp:///?Id=beckhoff-721e-4655-8e94-3548ed43349a) or the command-specific error code (table) when the *bError* output is set.

| Error Codes | Error description |
| --- | --- |
| 0x0000 | No error |
| 0x8001 | UPS configuration error. It is possible that the UPS is not configured correctly or that no UPS is configured at all. |
| 0x8002 | Communication error. Communication with the UPS was interrupted. |
| 0x8003 | Error during the reading of the status data. |

**stStatus**: Structure with the status information of the UPS (type: [ST\_UPSStatus](ms-xhelp:///?Id=beckhoff-c978-4ecb-b6f8-733f39caf230)).

Not every UPS device can supply all the status information. Some devices, for example, cannot supply the *BatteryLifeTime* or *BatteryReplace* status.

## Example:

Online data with status information of a UPS:

![44143566](/tcplclib_tc2_iofunctions/1033/Images/gif/59481867__en-US__Web.gif)

## Requirements

| Development environment | Target platform | UPS hardware | PLC libraries to be integrated (category group) |
| --- | --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | * Beckhoff BAPI v1; * Beckhoff P24Vxxxx; * Beckhoff CP903x card (PCI/ISA); * Beckhoff CX2100-09x4 models (e.g. CX2100-0904 or CX2100-0914 + "Smart Battery" CX2900-0192); * The APC devices that come supplied with Beckhoff Industrial PC support the Smart protocol and can be configured with the Windows UPS service. | Tc2\_IoFunctions (IO) |

[TwinCAT 3 | PLC Library: Tc2\_IoFunctions](ms-xhelp:///?Id=beckhoff-89f3-4b36-bb70-6247b05e611b)
