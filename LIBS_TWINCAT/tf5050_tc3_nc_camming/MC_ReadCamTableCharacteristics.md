# MC_ReadCamTableCharacteristics

## Library
tf5050_tc3_nc_camming

## Category
Motion Control

1. [TF5050 TC3 NC Camming](ms-xhelp:///?Id=beckhoff-984d-4c21-9ee9-97aff9b63946)
2. [Status](ms-xhelp:///?Id=beckhoff-73d1-444a-8db1-134222c28eaf)
3. MC\_ReadCamTableCharacteristics

# MC\_ReadCamTableCharacteristics

![44327440](/tf5050_tc3_nc_camming/1033/Images/png/1005453323__en-US__Web.png)

The function block *MC\_ReadCamTableCharacteristics* is used to calculate and read the characteristic parameters of a motion function. This includes minimum and maximum values of position, velocity, acceleration and jerk.

## Inputs

```
VAR_INPUT  
   Execute    : BOOL;  
   CamTableID : MC_CAM_ID;  
END_VAR
```

|  |  |
| --- | --- |
| **Execute** | The command is executed with rising edge. |
| **CamTableID** | Table [ID](ms-xhelp:///?Id=beckhoff-db88-4e03-9507-2b4b8a069dc4) |

## Outputs

```
VAR_OUTPUT  
   Done    : BOOL;  
   Busy    : BOOL;  
   Error   : BOOL;  
   ErrorID : UDINT;  
END_VAR
```

|  |  |
| --- | --- |
| **Done** | Becomes TRUE, if the calculation was carried out successfully. |
| **Busy** | The *Busy* output becomes TRUE when the command is started with *Execute* and remains TRUE as long as the command is processed. If *Busy* becomes FALSE again, the function block is ready for a new job. At the same time one of the outputs, *Done* or *Error*, is set. |
| **Error** | Becomes TRUE, as soon as an error occurs. |
| **ErrorID** | If the error output is set, this parameter supplies the error number |

## Inputs/outputs

```
VAR_IN_OUT  
   CamTableCharac : MC_TableCharacValues;  
END_VAR
```

|  |  |
| --- | --- |
| **CamTableCharac:** | [Data structure](ms-xhelp:///?Id=beckhoff-7103-4726-99b3-7d60ecd94d04) with characteristic parameters of the motion function |

[TF5050 | TwinCAT 3 NC Camming](ms-xhelp:///?Id=beckhoff-984d-4c21-9ee9-97aff9b63946)
