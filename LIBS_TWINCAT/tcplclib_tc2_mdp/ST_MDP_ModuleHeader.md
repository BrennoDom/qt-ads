# ST_MDP_ModuleHeader

## Library
tcplclib_tc2_mdp

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_MDP (IPC diagnostics)](ms-xhelp:///?Id=beckhoff-346f-40a1-8ce4-910757d45010)
2. [Data types](ms-xhelp:///?Id=beckhoff-6d60-48ae-9852-e20a070b1121)
3. [General data types](ms-xhelp:///?Id=beckhoff-25b1-40de-927b-a7efb7822b8e)
4. ST\_MDP\_ModuleHeader

# ST\_MDP\_ModuleHeader

```
TYPE ST_MDP_ModuleHeader :  
STRUCT  
    iLen     :UINT;  
    nAddr    :DWORD;  
    sType    :T_MaxString;  
    sName    :T_MaxString;  
    nDevType :DWORD;  
END_STRUCT  
END_TYPE
```

The structure contains device information. This information always corresponds to the Table ID 0 of an MDP module. Each module possesses this module header.

|  |  |
| --- | --- |
| **iLen** | Specifies the number of parameters in the Table ID, in this case the module header. |
| **nAddr** | Specifies the address of the module. |
| **sType** | Specifies the type of module. Possible types are listed in the [MDP module list.(Device Manager documentation).](https://infosys.beckhoff.com/content/1033/devicemanager/99079192065133835.html) |
| **sName** | Specifies the name of this MDP module. |
| **nDevType** | Specifies the type of MDP module as code. |

[TwinCAT 3 | PLC Library:Tc2\_MDP](ms-xhelp:///?Id=beckhoff-346f-40a1-8ce4-910757d45010)
