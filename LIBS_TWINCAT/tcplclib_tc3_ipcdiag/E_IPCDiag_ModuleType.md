# E_IPCDiag_ModuleType

## Library
tcplclib_tc3_ipcdiag

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc3\_IPCDiag](ms-xhelp:///?Id=beckhoff-3a11-4a24-824c-cda994a70d48)
2. [Data types](ms-xhelp:///?Id=beckhoff-b9ab-473c-b827-d56bd995675b)
3. E\_IPCDiag\_ModuleType

# E\_IPCDiag\_ModuleType

The enumeration defines constant values for the different module types in the MDP (Modular Device Profile).   
A module type can occur several times per device. Hence, a device with two Ethernet interfaces also has two NIC modules.

```
TYPE E_IPCDiag_ModuleType :(  
    NIC                := 16#0002,  
    Time_              := 16#0003,  
    UserManagement     := 16#0004,  
    RAS                := 16#0005,  
    FTP                := 16#0006,  
    SMB                := 16#0007,  
    TwinCAT            := 16#0008,  
    Datastore          := 16#0009,  
    Software           := 16#000A,  
    CPU                := 16#000B,  
    Memory             := 16#000C,  
    Firewall           := 16#000E,  
    FileSystemObject   := 16#0010,  
    PLC                := 16#0012,  
    DisplayDevice      := 16#0013,  
    EWF                := 16#0014,  
    FBWF               := 16#0015,  
    SiliconDrive       := 16#0017,  
    OS                 := 16#0018,  
    Raid               := 16#0019,  
    Fan                := 16#001B,  
    Mainboard          := 16#001C,  
    DiskManagement     := 16#001D,  
    UPS                := 16#001E,  
    PhysicalDrive      := 16#001F,  
    MassStorage        := 16#0020,  
    UWF                := 16#0021,  
    Misc               := 16#0100  
) WORD;  
END_TYPE
```

Detailed information on the modules can be found in the documentation for the IPC diagnostics under module types:

<https://infosys.beckhoff.de/content/1033/devicemanager/99079192065133835.html>

[TwinCAT 3 | PLC Library: Tc3\_IPCDiag](ms-xhelp:///?Id=beckhoff-3a11-4a24-824c-cda994a70d48)
