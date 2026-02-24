# ST_MDP_TwinCAT

## Library
tcplclib_tc2_mdp

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_MDP (IPC diagnostics)](ms-xhelp:///?Id=beckhoff-346f-40a1-8ce4-910757d45010)
2. [Data types](ms-xhelp:///?Id=beckhoff-6d60-48ae-9852-e20a070b1121)
3. [Structures specific MDP modules](ms-xhelp:///?Id=beckhoff-6f4d-4a3d-b56c-ef0db615c028)
4. ST\_MDP\_TwinCAT

# ST\_MDP\_TwinCAT

```
TYPE ST_MDP_TwinCAT :  
STRUCT  
    iLen            : UINT;         (* Length *)  
    iMajorVersion   : UINT;         (* Major Version *)  
    iMinorVersion   : UINT;         (* Minor Version *)  
    iBuild          : UINT;         (* Build *)  
    sAmsNETid       : T_MaxString;  (* Ams NET ID *)  
    iRegLevel       : UDINT;        (* TwinCAT registration level *)  
    iStatus         : UINT;         (* TwinCAT status *)  
    iRunAsDev       : UINT;         (* Run As Device *)     (* available for WindowsCE *)  
    iShowTargetVisu : UINT;         (* show target visualization *) (* available for WindowsCE *)  
    iLogFileSize    : UDINT;        (* log file size *)     (* available for WindowsCE *)  
    sLogFilePath    : T_MaxString;  (* log file path *)     (* available for WindowsCE *)  
END_STRUCT  
END_TYPE
```

The structure contains information on the MDP TwinCAT module.

This complete information can be queried by means of the function block [FB\_MDP\_TwinCAT\_Read](ms-xhelp:///?Id=beckhoff-1ddc-4c21-8ef0-f5fe1eb3d38b).

The parameters existing in this structure correspond to the subindices of the first table (Table ID 1) within the [MDP TwinCAT module](https://infosys.beckhoff.com/content/1033/devicemanager/54043195791476491.html).

[TwinCAT 3 | PLC Library:Tc2\_MDP](ms-xhelp:///?Id=beckhoff-346f-40a1-8ce4-910757d45010)
