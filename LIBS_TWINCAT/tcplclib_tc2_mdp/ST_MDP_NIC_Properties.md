# ST_MDP_NIC_Properties

## Library
tcplclib_tc2_mdp

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_MDP (IPC diagnostics)](ms-xhelp:///?Id=beckhoff-346f-40a1-8ce4-910757d45010)
2. [Data types](ms-xhelp:///?Id=beckhoff-6d60-48ae-9852-e20a070b1121)
3. [Structures specific MDP modules](ms-xhelp:///?Id=beckhoff-6f4d-4a3d-b56c-ef0db615c028)
4. ST\_MDP\_NIC\_Properties

# ST\_MDP\_NIC\_Properties

```
TYPE ST_MDP_NIC_Properties :  
STRUCT  
    iLen        : UINT;         (* Length *)  
    sMACAddress : T_MaxString;  (* MAC Address *)  
    sIPAddress  : T_MaxString;  (* IP Address *)  
    sSubnetMask : T_MaxString;  (* Subnet Mask *)  
    bDHCP       : BOOL;         (* DHCP *)  
END_STRUCT  
END_TYPE
```

The structure contains information on the IPC diagnostics module NIC (Network Interface Card).

This complete information can be queried by means of the function block [FB\_MDP\_NIC\_Read](ms-xhelp:///?Id=beckhoff-cf3d-4f07-a1d7-71f6650550e0).

The parameters existing in this structure correspond to the subindices of the first table (Table ID 1) within the IPC-diagnostics [NIC module](https://infosys.beckhoff.com/content/1033/devicemanager/54043195791459083.html).

[TwinCAT 3 | PLC Library:Tc2\_MDP](ms-xhelp:///?Id=beckhoff-346f-40a1-8ce4-910757d45010)
