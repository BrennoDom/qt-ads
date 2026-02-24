# NT_Shutdown

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# NT\_Shutdown

|  |  |
| --- | --- |
| 32455223 | This functionality is not available under Windows CE! |

![23661558](/tcplclib_tc2_utilities/1033/Images/png/9007199290376075__Web.png)

The Windows NT operating system can be shut down with the aid of the "NT\_Shutdown" function block. The function largely corresponds to the Shut Down command on the Windows taskbar. A delay before execution of the Shut Down command can be defined via the DELAY parameter.

## Notes:

Newer operating systems ( e.g. Windows 2000 ) perform with the aid of the "NT\_Shutdown" function block the "Shutdown with Power OFF" ( the computer switches its power OFF). This function can only be used on systems which are ACPI conform (Advanced Configuration and Power Interface). The ACPI functions should be activated in BIOS before the installation of the operating system.

The ACPI-functions have to be supported by the motherboard and the power supply of the PC. A change afterwards is not recognized by the operating system. If there is an ACPI-supporting PC, you can check e. g. at Windows 2000 in the following way:

1. In the "System Manager" open the folder "system".

2. on the tab "Hardware" choose the "Device Manager".

In the navigation tree with the devices now you can read at "Computer": "Advanced Configuration and Power Interface (ACPI) PC".

![11627434](/tcplclib_tc2_utilities/1033/Images/gif/35638283__en-US__Web.gif)

The default TwinCAT settings are to perform shutdown with power OFF. You can disable the power OFF function in windows registry. Please add following entry:

"**DisableACPIPowerOff**"**REG\_DWORD = 0x00000001** in Registry under: "**HKEY\_LOCAL\_MACHINE\SOFTWARE\Beckhoff\TwinCAT\System**"

## VAR\_INPUT

```
VAR_INPUT  
    NETID  : T_AmsNetId;  
    DELAY  : DWORD;  
    START  : BOOL;  
    TMOUT  : TIME := DEFAULT_ADS_TIMEOUT;  
END_VAR
```

**NETID**: It is possible here to provide the AmsNetId of the TwinCAT computer on which the operating system is to be shut down (type: T\_AmsNetID). If it is the local computer that is to be shut down, an empty string can be entered.

**DELAY**: The delay time, in seconds, before the Shut Down command is executed.

**START**: the block is activated by a positive edge at this input.

**TMOUT**: States the length of the timeout that may not be exceeded by execution of the ADS command.

## VAR\_OUTPUT

```
VAR_OUTPUT  
    BUSY  : BOOL;  
    ERR   : BOOL;  
    ERRID : UDINT;  
END_VAR
```

**BUSY**: When the function block is activated this output is set. It remains set until a feedback is received.

**ERR**: If an error should occur during the transfer of the command, then this output is set once the BUSY output was reset.

**ERRID**: Supplies the [ADS error number](ms-xhelp:///?Id=beckhoff-e821-44ae-982a-c8b931426e8c) when the ERR output is set.

## Requirements

| Development environment | Target platform | PLC libraries to be integrated (category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (WES7/Win7/Win10: TC RT x86/x64, WEC6/7: TC RT x86, WEC7: TC CE7 ARMV7) | Tc2\_Utilities (System) |
