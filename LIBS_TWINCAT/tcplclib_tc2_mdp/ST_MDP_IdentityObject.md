# ST_MDP_IdentityObject

## Library
tcplclib_tc2_mdp

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_MDP (IPC diagnostics)](ms-xhelp:///?Id=beckhoff-346f-40a1-8ce4-910757d45010)
2. [Data types](ms-xhelp:///?Id=beckhoff-6d60-48ae-9852-e20a070b1121)
3. [Structures specific MDP modules](ms-xhelp:///?Id=beckhoff-6f4d-4a3d-b56c-ef0db615c028)
4. ST\_MDP\_IdentityObject

# ST\_MDP\_IdentityObject

```
TYPE ST_MDP_IdentityObject :  
STRUCT  
    iLen          : UINT;      (* Length *)  
    iVendor       : UDINT;     (* Vendor *)  
    iProductCode  : UDINT;     (* Product Code *)     (* not yet supported *)  
    iRevNumber    : UDINT;     (* Revision Number *) (* not yet supported *)  
    iSerialNumber : UDINT;     (* Serial Number *)  
END_STRUCT  
END_TYPE
```

The structure contains information on the ‘IdentityObject’ table, which can be found in the IPC diagnostics general area.

This complete information can be queried by means of the function block [FB\_MDP\_IdentityObj\_Read](ms-xhelp:///?Id=beckhoff-c999-4885-9b85-ca69aff6ed77).

The parameters in this structure correspond to the subindices of the 'identity object' table in the IPC diagnostics [general area](https://infosys.beckhoff.com/content/1033/devicemanager/36028797281945355.html).

[TwinCAT 3 | PLC Library:Tc2\_MDP](ms-xhelp:///?Id=beckhoff-346f-40a1-8ce4-910757d45010)
