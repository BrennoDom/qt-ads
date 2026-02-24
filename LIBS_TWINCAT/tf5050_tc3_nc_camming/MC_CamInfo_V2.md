# MC_CamInfo_V2

## Library
tf5050_tc3_nc_camming

## Category
Motion Control

1. [TF5050 TC3 NC Camming](ms-xhelp:///?Id=beckhoff-984d-4c21-9ee9-97aff9b63946)
2. [Status](ms-xhelp:///?Id=beckhoff-73d1-444a-8db1-134222c28eaf)
3. MC\_CamInfo\_V2

# MC\_CamInfo\_V2

![19838352](/tf5050_tc3_nc_camming/1033/Images/png/1056862219__en-US__Web.png)

The *MC\_CamInfo\_V2* function block obtains data relating to the current state and current parameterization of a cam plate coupling. The command assumes that the slave axis is coupled by a cam plate. If the *AtMasterPosition* input is TRUE the state is determined with reference to the quoted master position instead of the current state. The data obtained is placed into the *CamInfo* data structure. For multi-cam plate coupling, the *CamTableId* also has to be transferred explicitly. If a single cam plate is involved in the coupling, the *CamTableId* can be set to 0.

*Notice*: If the coupled group of axes gets into an error situation (e.g. emergency stop), the function block will return the most recent valid state of the coupling. The function block must be called before decoupling the slave. The data that has been obtained can be used to restore the coupling to the original axis position.

## Inputs

```
VAR_INPUT  
   Execute          : BOOL;  
   CamTableId       : BOOL;  
   AtMasterPosition : BOOL;  
   MasterPosition   : LREAL;  
END_VAR
```

|  |  |
| --- | --- |
| **Execute** | The command is executed with rising edge. |
| **CamTableId** | For multi-cam plate coupling, this has to be transferred explicitly, in order to identify the cam unambiguously within the system. |
| **AtMasterPosition** | If *AtMasterPosition* is TRUE the data is determined with reference to the quoted *MasterPosition*. Otherwise the data refers to the current master position. |
| **MasterPosition** | Master position to which the data that is determined refers. This input parameter is not necessary if *AtMasterPosition* is FALSE. |

## Outputs

```
VAR_OUTPUT  
   Done    : BOOL;  
   Busy    : BOOL;  
   Error   : BOOL;  
   ErrorID : UDINT;  
   CamInfo : MC_CamInfoData;  
END_VAR
```

|  |  |
| --- | --- |
| **Done** | Becomes TRUE when the function has been successfully executed. |
| **Busy** | The *Busy* output becomes TRUE when the command is started with *Execute* and remains TRUE as long as the command is processed. If *Busy* becomes FALSE again, the function block is ready for a new job. At the same time one of the outputs, *Done* or *Error*, is set. |
| **Error** | Becomes TRUE, as soon as an error occurs. |
| **ErrorID** | If the error output is set, this parameter supplies the error number |
| **CamInfo** | The [CamInfo](ms-xhelp:///?Id=beckhoff-f37e-4737-b6c4-07899b1bbe18) data structure contains all the data determined about the cam plate coupling |

## Inputs/outputs

```
VAR_IN_OUT  
   Slave : AXIS_REF;  
END_VAR
```

|  |  |
| --- | --- |
| **Slave** | Axis data structure of the Slave. |

The axis data structure of type AXIS\_REF addresses an axis uniquely within the system. Among other parameters it contains the current axis status, including position, velocity or error status.

[TF5050 | TwinCAT 3 NC Camming](ms-xhelp:///?Id=beckhoff-984d-4c21-9ee9-97aff9b63946)
