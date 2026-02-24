# E_MDP_ModuleType

## Library
tcplclib_tc2_mdp

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_MDP (IPC diagnostics)](ms-xhelp:///?Id=beckhoff-346f-40a1-8ce4-910757d45010)
2. [Data types](ms-xhelp:///?Id=beckhoff-6d60-48ae-9852-e20a070b1121)
3. [General data types](ms-xhelp:///?Id=beckhoff-25b1-40de-927b-a7efb7822b8e)
4. E\_MDP\_ModuleType

# E\_MDP\_ModuleType

```
TYPE E_MDP_ModuleType :(  
    eMDP_ModT_NIC              := 16#0002,  
    eMDP_ModT_Time             := 16#0003,  
    eMDP_ModT_UserManagement   := 16#0004,  
    eMDP_ModT_RAS              := 16#0005,  
    eMDP_ModT_FTP              := 16#0006,  
    eMDP_ModT_SMB              := 16#0007,  
    eMDP_ModT_TwinCAT          := 16#0008,  
    eMDP_ModT_Datastore        := 16#0009,  
    eMDP_ModT_Software         := 16#000A,  
    eMDP_ModT_CPU              := 16#000B,  
    eMDP_ModT_Memory           := 16#000C,  
    eMDP_ModT_Firewall         := 16#000E,  
    eMDP_ModT_FileSystemObject := 16#0010,  
    eMDP_ModT_PLC              := 16#0012,  
    eMDP_ModT_DisplayDevice    := 16#0013,  
    eMDP_ModT_EWF              := 16#0014,  
    eMDP_ModT_FBWF             := 16#0015,  
    eMDP_ModT_SiliconDrive     := 16#0017,  
    eMDP_ModT_OS               := 16#0018,  
    eMDP_ModT_Raid             := 16#0019,  
    eMDP_ModT_Fan              := 16#001B,  
    eMDP_ModT_Mainboard        := 16#001C,  
    eMDP_ModT_DiskManagement   := 16#001D,  
    eMDP_ModT_UPS              := 16#001E,  
    eMDP_ModT_Misc             := 16#0100  
);  
END_TYPE
```

The enumeration *E\_MDP\_ModuleType* defines constant values for the different module types in the MDP.  
 A module type can occur several times per device. Hence, a device with two Ethernet interfaces also has two MDP NIC modules.

Detailed information on the modules can be found in the documentation for the IPC diagnostics under [module types](https://infosys.beckhoff.com/content/1033/devicemanager/99079192065133835.html).

**Notice**: This module type is not the same as the dynamic module ID!

[TwinCAT 3 | PLC Library:Tc2\_MDP](ms-xhelp:///?Id=beckhoff-346f-40a1-8ce4-910757d45010)
