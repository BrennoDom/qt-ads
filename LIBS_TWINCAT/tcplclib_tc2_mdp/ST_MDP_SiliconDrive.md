# ST_MDP_SiliconDrive

## Library
tcplclib_tc2_mdp

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_MDP (IPC diagnostics)](ms-xhelp:///?Id=beckhoff-346f-40a1-8ce4-910757d45010)
2. [Data types](ms-xhelp:///?Id=beckhoff-6d60-48ae-9852-e20a070b1121)
3. [Structures specific MDP modules](ms-xhelp:///?Id=beckhoff-6f4d-4a3d-b56c-ef0db615c028)
4. ST\_MDP\_SiliconDrive

# ST\_MDP\_SiliconDrive

```
TYPE ST_MDP_SiliconDrive :  
STRUCT  
    iLen                  : UINT;     (* Length *)  
    iTotalEraseCounts     : UDINT;    (* Total EraseCounts (lower 4 bytes) *)  
    iDriveUsage           : UINT;     (* Drive Usage (%) *)  
    iNbrSpares            : UINT;     (* Number of Spares *)  
    iNbrUsedSpares        : UINT;     (* Spares Used *)  
    iTotalEraseCountsHigh : UDINT;    (* Total EraseCounts (higher 4 bytes) *)  
END_STRUCT  
END_TYPE
```

The structure contains information on the MDP SiliconDrive module.

This complete information can be queried by means of the function block [FB\_MDP\_SiliconDrive\_Read](ms-xhelp:///?Id=beckhoff-f044-43a3-b4cf-9040ca68d131).

**iLen**: iLen indicates the number the MDP elements in the table in the MDP module.

**iTotalEraseCounts**: This value indicates the total number of write and delete cycles of all memory blocks of a Silicon Drive. This number is a 64-bit value. *iTotalEraseCounts* contains the lower 32 bits.

**iTotalEraseCountsHigh**: This value indicates the total number of write and delete cycles of all memory blocks of a Silicon Drive. This number is a 64-bit value. *iTotalEraseCountsHigh* contains the higher 32 bits.

**iDriveUsage**: This parameter indicates the calculated wear of the Silicon Drive. The value is based on two million write cycles per block as maximum value.

**iNbrSpares**: Reserved blocks are used to replace worn memory blocks. *iNbrSpares* indicates the number of spare blocks available on the Silicon Drive.

**iNbrUsedSpares**: The value indicates the number of spare blocks already in use.

The parameters existing in this structure correspond to the subindices of the first table (Table ID 1) within the IPC diagnostics SiliconDrive module.

|  |  |
| --- | --- |
| 28263486 | Obsolete functionality  The SiliconDrive hardware was replaced by newer memory card types. The functionality is therefore obsolete. We recommend using the query of the IPC diagnostic module[Physical Drive SMART](https://infosys.beckhoff.com/content/1033/devicemanager/45035997033048203.html) Parameters instead. |

[TwinCAT 3 | PLC Library:Tc2\_MDP](ms-xhelp:///?Id=beckhoff-346f-40a1-8ce4-910757d45010)
