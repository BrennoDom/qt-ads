# E_MDP_ErrCodesPLC

## Library
tcplclib_tc2_mdp

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_MDP (IPC diagnostics)](ms-xhelp:///?Id=beckhoff-346f-40a1-8ce4-910757d45010)
2. [Error Codes](ms-xhelp:///?Id=beckhoff-d04b-4b23-afee-c6539244fc0e)
3. E\_MDP\_ErrCodesPLC

# E\_MDP\_ErrCodesPLC

```
TYPE E_MDP_ErrCodesPLC :(  
(* list of PLC library internal error codes *)  
    eMDP_ErrPLC_NoError     := 16#0000,  
    eMDP_ErrPLC_TimeOut     := 16#0001,  
    eMDP_ErrPLC_ModuleNotFound     := 16#0002,  
    eMDP_ErrPLC_BufferTooSmall     := 16#0003,  
    eMDP_ErrPLC_ElementNotFound     := 16#0004  
);  
END_TYPE
```

The enumeration *E\_MDP\_ErrCodesPLC* defines constant values for the different errors that can be generated internally in the library.  
These values appear in the [error codes](ms-xhelp:///?Id=beckhoff-dcf9-45e5-b79d-97610e81bb4a), which are output by a PLC MDP function block in the event of an error.

|  |  |
| --- | --- |
| **eMDP\_ErrPLC\_TimeOut** | The error *eMDP\_ErrPLC\_TimeOut* is generated if the time period *tTimeout* applied to the input of the function block has expired.  The length of the processing time can vary depending on the MDP query. Due to the internal processes, the processing time can sometimes exceed the Standard ADS Timeout. This can be remedied by increasing the time period tTimeout applied to the input of the function block. |
| **eMDP\_ErrPLC\_ModuleNotFound** | A list of active modules exists in the MDP. The function blocks in the PLC MDP library search this list for the queried module. If the list does not contain the module, then the error *eMDP\_ErrPLC\_ModuleNotFound* is output. This is the case when the particular module/device is not installed on the system or does not even exist. |
| **eMDP\_ErrPLC\_BufferTooSmall** | If a buffer has been specified at the input of the function block by means of pointers, then it is possible that this is not large enough for the existing data. In this case the error *eMDP\_ErrPLC\_BufferTooSmall* is output. |
| **eMDP\_ErrPLC\_ElementNotFound** | The query of a certain element was not successful. The element was not found. The respective module or element may not even be present on the system. |

A general description can be found in the [MDP Information Model](https://infosys.beckhoff.com/content/1033/devicemanager/99079192065129227.html).(IPC Diagnosis)

## Requirements

| Development environment | Target platform | PLC libraries to include |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_MDP |

[TwinCAT 3 | PLC Library:Tc2\_MDP](ms-xhelp:///?Id=beckhoff-346f-40a1-8ce4-910757d45010)
