# MC_ReadCamTableSlaveDynamics

## Library
tf5050_tc3_nc_camming

## Category
Motion Control

1. [TF5050 TC3 NC Camming](ms-xhelp:///?Id=beckhoff-984d-4c21-9ee9-97aff9b63946)
2. [Status](ms-xhelp:///?Id=beckhoff-73d1-444a-8db1-134222c28eaf)
3. MC\_ReadCamTableSlaveDynamics

# MC\_ReadCamTableSlaveDynamics

![34213602](/tf5050_tc3_nc_camming/1033/Images/png/1005411595__en-US__Web.png)

The function block *MC\_ReadCamTableSlaveDynamics* can be used to determine the slave dynamics at a certain point of a cam plate table. The function evaluates the raw table data. Any scaling of the cam plate is not taken into account.

For older [cam plate table types](ms-xhelp:///?Id=beckhoff-ab33-42a6-ae57-69a7ddde9748), not all dynamic parameters can be determined. The following overview shows the expected result:

MC\_TABLETYPE\_MOTIONFUNCTION: slave position, velocity and acceleration are determined.

MC\_TABLETYPE\_EQUIDISTANT: slave position and velocity are determined. The acceleration is always 0.

MC\_TABLETYPE\_NONEQUIDISTANT: the slave position is determined. Velocity and acceleration are always 0.

## Inputs

```
VAR_INPUT  
   Execute        : BOOL;  
   CamTableID     : MC_CAM_ID;  
   MasterPosition : LREAL;  
END_VAR
```

|  |  |
| --- | --- |
| **Execute** | The command is executed with rising edge. |
| **CamTableID** | Table [ID](ms-xhelp:///?Id=beckhoff-db88-4e03-9507-2b4b8a069dc4). |
| **MasterPosition** | Master position within the table for which the slave dynamics is to be determined. |

## Outputs

```
VAR_OUTPUT  
   Done              : BOOL;  
   Busy              : BOOL;  
   SlavePosition     : LREAL;  
   SlaveVelocity     : LREAL;  
   SlaveAcceleration : LREAL;  
   Error             : BOOL;  
   ErrorID           : UDINT;  
END_VAR
```

|  |  |
| --- | --- |
| **Done** | Becomes TRUE, if the command was executed successfully. |
| **Busy** | The *Busy* output becomes TRUE when the command is started with *Execute* and remains TRUE as long as the command is processed. If *Busy* becomes FALSE again, the function block is ready for a new job. At the same time one of the outputs, *Done* or *Error*, is set. |
| **SlavePosition** | Position of the slave within the cam plate table at the specified master position. |
| **SlaveVelocity** | Velocity of the slave within the cam plate table at the specified master position. |
| **SlaveAcceleration** | Acceleration of the slave within the cam plate table at the specified master position. |
| **Error** | Becomes TRUE, as soon as an error occurs. |
| **ErrorID** | If the error output is set, this parameter supplies the error number |

[TF5050 | TwinCAT 3 NC Camming](ms-xhelp:///?Id=beckhoff-984d-4c21-9ee9-97aff9b63946)
