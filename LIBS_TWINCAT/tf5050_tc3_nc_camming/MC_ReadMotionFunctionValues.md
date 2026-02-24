# MC_ReadMotionFunctionValues

## Library
tf5050_tc3_nc_camming

## Category
Motion Control

1. [TF5050 TC3 NC Camming](ms-xhelp:///?Id=beckhoff-984d-4c21-9ee9-97aff9b63946)
2. [Motion functions](ms-xhelp:///?Id=beckhoff-78ed-4874-867e-fcf1d97d2c04)
3. MC\_ReadMotionFunctionValues

# MC\_ReadMotionFunctionValues

![63453834](/tf5050_tc3_nc_camming/1033/Images/png/1005347723__en-US__Web.png)

The function block *MC\_ReadMotionFunctionValues* can be used to read the interpolated data of a motion function in the form of a table.

This function can be used for visualizing a motion function, for example. The complete curve is digitized with a parameterizable step size. The data determined in this way are easier to display then a motion function.

## Inputs

```
VAR_INPUT  
   Execute         : BOOL;  
   CamTableID      : MC_CAM_ID;  
   ValueSelectMask : UINT; (* MC_ValueSelectType; position, velocity, acceleration, jerk… *)  
   StartPosMaster  : LREAL; (* master position of first point *)  
   EndPosMaster    : LREAL; (* master position of last point *)  
   Increment       : LREAL; (* increment of master position *)  
END_VAR
```

|  |  |
| --- | --- |
| **Execute** | The command is executed with rising edge. |
| **CamTableID** | [ID](ms-xhelp:///?Id=beckhoff-db88-4e03-9507-2b4b8a069dc4) of the loaded table (motion function type). |
| **ValueSelectMask** | The selection mask can be used to specify which data are to be interpolated and returned. The value is formed through addition of individual values of data type [MC\_ValueSelectType](ms-xhelp:///?Id=beckhoff-6a4e-43db-990d-3d642d13a5c3).  The number of columns of the data structure described by [CamTable](ms-xhelp:///?Id=beckhoff-1365-4325-92ea-77764879dfc0) must match the number of columns defined by [ValueSelectMask](ms-xhelp:///?Id=beckhoff-6a4e-43db-990d-3d642d13a5c3). If, for example, only position data are read, the number of columns is 2 (master and slave position). With each further derivative (speed, acceleration, jerk), the number of columns increases by 1. |
| **StartPosMaster** | Position value of the master axis of the first interpolated point |
| **EndPosMaster** | Position value of the master axis of the last interpolated point |
| **Increment** | Interpolation step size |

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
| **CamTable** | [Reference](ms-xhelp:///?Id=beckhoff-1365-4325-92ea-77764879dfc0) to the table (structure). |

[TF5050 | TwinCAT 3 NC Camming](ms-xhelp:///?Id=beckhoff-984d-4c21-9ee9-97aff9b63946)
