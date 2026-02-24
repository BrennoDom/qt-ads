# MC_WriteMotionFunction

## Library
tf5050_tc3_nc_camming

## Category
Motion Control

1. [TF5050 TC3 NC Camming](ms-xhelp:///?Id=beckhoff-984d-4c21-9ee9-97aff9b63946)
2. [Motion functions](ms-xhelp:///?Id=beckhoff-78ed-4874-867e-fcf1d97d2c04)
3. MC\_WriteMotionFunction

# MC\_WriteMotionFunction

![36265071](/tf5050_tc3_nc_camming/1033/Images/png/1005342731__en-US__Web.png)

The function block *MC\_WriteMotionFunction* can be used to write the data of a motion function into the NC. Either the complete function with all interpolation points or only a part can be written. First, the data are stored within the PLC in the structure described by [CamTable](ms-xhelp:///?Id=beckhoff-1365-4325-92ea-77764879dfc0).

The function block [MC\_SetCamOnlineChangeMode](ms-xhelp:///?Id=beckhoff-d38a-4116-a7ad-dd65a8c72aaf) can be used to specify when the data are read into the cam plate. If activation of the data is to be delayed until the master reaches a certain position, the system will initially queue the written data and activate them at the master position.

The status flag Axis.Status.CamDataQueued (AXIS\_REF) can be used to check whether data have been queued, i.e. written but not yet activated.

## Inputs

```
VAR_INPUT  
   Execute    : BOOL;  
   CamTableID : MC_CAM_ID;  
   PointID    : MC_MotionFunctionPoint_ID;  
   NumPoints  : UDINT;   
END_VAR
```

|  |  |
| --- | --- |
| **Execute** | The command is executed with rising edge. |
| **CamTableID** | [ID](ms-xhelp:///?Id=beckhoff-db88-4e03-9507-2b4b8a069dc4) of the loaded table. |
| **PointID** | Point [ID](ms-xhelp:///?Id=beckhoff-b237-49b4-ad56-4040271b6939) of the first point of the motion function to be written. |
| **NumPoints** | Number of motion function points to be written. |

## Outputs

```
VAR_OUTPUT  
   Execute : BOOL;  
   Done    : BOOL;  
   Busy    : BOOL;  
   Error   : BOOL;  
   ErrorID : UDINT;  
END_VAR
```

|  |  |
| --- | --- |
| **Done** | Becomes TRUE, if the data were read successfully. |
| **Busy** | The *Busy* output becomes TRUE when the command is started with *Execute* and remains TRUE as long as the command is processed. If *Busy* becomes FALSE again, the function block is ready for a new job. At the same time one of the outputs, *Done* or *Error*, is set. |
| **Error** | Becomes TRUE, as soon as an error occurs. |
| **ErrorID** | If the error output is set, this parameter supplies the error number |

## Inputs/outputs

```
VAR_IN_OUT  
   CamTable : MC_CAM_REF;  
END_VAR
```

|  |  |
| --- | --- |
| **CamTable** | [Reference](ms-xhelp:///?Id=beckhoff-1365-4325-92ea-77764879dfc0) to the table (structure). The start address of the table data structure (CamTable.pArray) indicates the first point to be written. |

[TF5050 | TwinCAT 3 NC Camming](ms-xhelp:///?Id=beckhoff-984d-4c21-9ee9-97aff9b63946)
