# ST_MDP_CPU

## Library
tcplclib_tc2_mdp

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_MDP (IPC diagnostics)](ms-xhelp:///?Id=beckhoff-346f-40a1-8ce4-910757d45010)
2. [Data types](ms-xhelp:///?Id=beckhoff-6d60-48ae-9852-e20a070b1121)
3. [Structures specific MDP modules](ms-xhelp:///?Id=beckhoff-6f4d-4a3d-b56c-ef0db615c028)
4. ST\_MDP\_CPU

# ST\_MDP\_CPU

```
TYPE ST_MDP_CPU :  
STRUCT  
    iLen          : UINT;     (* Length *)  
    iCPUfrequency : UDINT;    (* CPU Frequency *)  
    iCPUusage     : UINT;     (* Current CPU Usage [%] *)  
END_STRUCT  
END_TYPE
```

The structure contains information on the IPC diagnostics module CPU.

This complete information can be queried by means of the function block [FB\_MDP\_CPU\_Read](ms-xhelp:///?Id=beckhoff-c070-434a-a495-bd512c854849).

The parameters existing in this structure correspond to the subindices of the first table (Table ID 1) within the IPC-diagnostics [CPU module](https://infosys.beckhoff.com/content/1033/devicemanager/54043195791430411.html).

[TwinCAT 3 | PLC Library:Tc2\_MDP](ms-xhelp:///?Id=beckhoff-346f-40a1-8ce4-910757d45010)
