# ST_MDP_Addr

## Library
tcplclib_tc2_mdp

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_MDP (IPC diagnostics)](ms-xhelp:///?Id=beckhoff-346f-40a1-8ce4-910757d45010)
2. [Data types](ms-xhelp:///?Id=beckhoff-6d60-48ae-9852-e20a070b1121)
3. [General data types](ms-xhelp:///?Id=beckhoff-25b1-40de-927b-a7efb7822b8e)
4. ST\_MDP\_Addr

# ST\_MDP\_Addr

```
TYPE ST_MDP_Addr :  
STRUCT  
    nArea       : BYTE;     (* Area [range: 0x0-0xF] *)  
    nModuleId   : BYTE;     (* Dynamic Module Id [range: 0x00-0xFF] *)  
    nTableId    : BYTE;     (* Table Id [range: 0x0-0xF] *)  
    nFlag       : BYTE;     (* Flags [range: 0x00-0xFF] *)  
    nSubIdx     : BYTE;     (* SubIndex [range: 0x00-0xFF] *)  
    arrReserved : ARRAY[0..2] OF BYTE;  
END_STRUCT  
END_TYPE
```

The structure contains information that is required for the MDP addressing.

**nArea**: Possible MDP areas are listed in [E\_MDP\_AddrArea](ms-xhelp:///?Id=beckhoff-eff3-4f20-967a-41d9fc56ea73).

**nModuleId**: The Module ID is assigned dynamically. It does not correspond to the module types listed in E\_MDP\_ModuleType. The function block [FB\_MDP\_ScanModules](ms-xhelp:///?Id=beckhoff-d602-4983-bfef-aeab48e864a1) can be used in order to determine a dynamic Module ID for a special type of module.

**nTableId**: This value specifies the number of the selected table of the selected module.

**nFlag**: This parameter is used internally only. It remains at the default value of 0x00.

**nSubIdx**: The Subindex parameter corresponds to the subindex in a table in an MDP module.

|  |  |
| --- | --- |
| 62792710 | More detailed information on MDP addressing can be found in the [Deive Manager documentation.](https://infosys.beckhoff.com/content/1033/devicemanager/index.html) |

[TwinCAT 3 | PLC Library:Tc2\_MDP](ms-xhelp:///?Id=beckhoff-346f-40a1-8ce4-910757d45010)
