# MC_ReadMotionFunction

## Library
tf5050_tc3_nc_camming

## Category
Motion Control

1. [TF5050 TC3 NC Camming](ms-xhelp:///?Id=beckhoff-984d-4c21-9ee9-97aff9b63946)
2. [Motion functions](ms-xhelp:///?Id=beckhoff-78ed-4874-867e-fcf1d97d2c04)
3. MC\_ReadMotionFunction

# MC\_ReadMotionFunction

![65071067](/tf5050_tc3_nc_camming/1033/Images/png/1005339403__en-US__Web.png)

The function block *MC\_ReadMotionFunction* can be used to read the data of a motion function. Either the complete function with all interpolation points or only a part can be read. The data are stored within the PLC in the structure described by [CamTable](ms-xhelp:///?Id=beckhoff-1365-4325-92ea-77764879dfc0).

## Inputs

```
VAR_INPUT  
   Execute    : BOOL;  
   CamTableID : MC_CAM_ID;  
   PointID    : MC_MotionFunctionPoint_ID;  
   NumPoints  : UDINT; (* 0 = fill MFsize *)  
END_VAR
```

|  |  |
| --- | --- |
| **Execute** | The command is executed with rising edge. |
| **CamTableID** | [ID](ms-xhelp:///?Id=beckhoff-db88-4e03-9507-2b4b8a069dc4) of the loaded table. |
| **PointID** | Point [ID](ms-xhelp:///?Id=beckhoff-b237-49b4-ad56-4040271b6939) of the first point of the motion function to be read. |
| **NumPoints** | Number of motion function points to be read. For reading all points, 0 can be specified here, in which case the number that is actually read is returned in the output variable *NumPointsRead*. |

## Outputs

```
VAR_OUTPUT  
   Done          : BOOL;  
   Busy          : BOOL;  
   Error         : BOOL;  
   ErrorID       : UDINT;  
   NumPointsRead : UDINT; (* return value <= NumPoints *)  
END_VAR
```

|  |  |
| --- | --- |
| **Done** | Becomes TRUE, if the data were read successfully. |
| **Busy** | The *Busy* output becomes TRUE when the command is started with *Execute* and remains TRUE as long as the command is processed. If *Busy* becomes FALSE again, the function block is ready for a new job. At the same time one of the outputs, *Done* or *Error*, is set. |
| **Error** | Becomes TRUE, as soon as an error occurs. |
| **ErrorID** | If the error output is set, this parameter supplies the error number |
| **NumPointsRead** | The number of points that were actually read. The number may be less or equal *NumPoints*. |

## Inputs/outputs

```
VAR_IN_OUT  
   CamTable  : MC_CAM_REF;  
END_VAR
```

|  |  |
| --- | --- |
| **CamTable** | [Reference](ms-xhelp:///?Id=beckhoff-1365-4325-92ea-77764879dfc0) to the table (structure). |

[TF5050 | TwinCAT 3 NC Camming](ms-xhelp:///?Id=beckhoff-984d-4c21-9ee9-97aff9b63946)
