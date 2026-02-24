# MC_ReadCamTableMasterPosition

## Library
tf5050_tc3_nc_camming

## Category
Motion Control

1. [TF5050 TC3 NC Camming](ms-xhelp:///?Id=beckhoff-984d-4c21-9ee9-97aff9b63946)
2. [Status](ms-xhelp:///?Id=beckhoff-73d1-444a-8db1-134222c28eaf)
3. MC\_ReadCamTableMasterPosition

# MC\_ReadCamTableMasterPosition

![63402646](/tf5050_tc3_nc_camming/1033/Images/png/1005454987__en-US__Web.png)

The function block *MC\_ReadCamTableMasterPosition* can be used to calculate the master position for a given slave position. While the slave position for a given master position must be unique, the inverse is not true. In order to limit the number of master output options for the function block, for a given master position (*MasterStartPosition*) the smaller (*MasterLow*) and larger master position (*MasterHigh*) for the slave value is output.

For example, for the cam plate in Fig. 1, for a slave value of 80 and a master start value of 180, the output values are 225 for *MasterHigh* and 135 for *MasterLow*. If the cam plate is cyclic, for a master start value of 90 in addition to the *MasterHigh* of 135 a *MasterLow* of -135 is calculated. In the linear cam plate case (non-cyclic) only the value *MasterHigh* is shown as valid in Fig. 2.

![33752906](/tf5050_tc3_nc_camming/1033/Images/gif/460558859__en-US__Web.gif)

Fig. 1

In cyclic cam plates with hub the master position can not only lie in one of the cycles adjacent to the StartMasterpos, but several cycles further, depending on the slave position.

![35340701](/tf5050_tc3_nc_camming/1033/Images/gif/460562059__en-US__Web.gif)

Fig. 2

The master position is calculated with numeric algorithms, the precision of which can be set via the variable *MasterAccuracy*.

## Inputs

```
    VAR_INPUT      
   Execute             : BOOL;  
   CamTableID          : MC_CAM_ID;  
   SlavePosition       : LREAL; (* absolute slave axis position *)  
   MasterOffset        : LREAL; (* E *)  
   SlaveOffset         : LREAL; (* E *)  
   MasterScaling       : LREAL := 1.0; (* E *)  
   SlaveScaling        : LREAL := 1.0; (* E *)  
   MasterStartPosition : LREAL; (* Master position to start the iteration from *)  
   MasterAccuracy      : LREAL; (* Master iteration accuracy *)  
END_VAR
```

|  |  |
| --- | --- |
| **Execute** | The command is executed with a rising edge at input *Execute*. |
| **CamTableID** | [ID](ms-xhelp:///?Id=beckhoff-db88-4e03-9507-2b4b8a069dc4) of the cam plate for which the calculation is carried out |
| **SlavePosition** | The slave position for which the master position is sought |
| **MasterOffset** | Offset to the master position of the cam plate |
| **SlaveOffset** | Offset to the slave position of the cam plate |
| **MasterScaling** | Scaling of the master position of the cam plate |
| **SlaveScaling** | Scaling of the slave position of the cam plate |
| **MasterStartPosition** | Start position of the master |
| **MasterAccuracy** | Precision for the calculation |

## Outputs

```
VAR_OUTPUT  
   Execute    : BOOL;  
   Done       : BOOL;  
   Busy       : BOOL;   
   Active     : BOOL;   
   Error      : BOOL;  
   ErrorID    : UDINT;  
   MasterLow  : ST_CamMasterData; (* position information of the lower bound master position *)  
   MasterHigh : ST_CamMasterData; (* position information of the upper bound master position *)  
END_VAR
```

|  |  |
| --- | --- |
| **Done** | Becomes TRUE, if the coupling was successful and the cam plate is active. |
| **Busy** | The *Busy* output becomes TRUE when the command is started with *Execute* and remains TRUE as long as the command is processed. If *Busy* becomes FALSE again, the function block is ready for a new job. At the same time one of the outputs, *Done* or *Error*, is set. |
| **Error** | Becomes TRUE, as soon as an error occurs. |
| **ErrorID** | If the error output is set, this parameter supplies the error number |
| **MasterLow** | Master position is smaller than the MasterStartPosition in the data structure  [ST\_CamMasterData](ms-xhelp:///?Id=beckhoff-9c3a-45c6-96bc-e3fdb70b1c3d) |
| **MasterHigh** | Master position is smaller than the MasterStartPosition in the data structure [ST\_CamMasterData](ms-xhelp:///?Id=beckhoff-9c3a-45c6-96bc-e3fdb70b1c3d) |

[TF5050 | TwinCAT 3 NC Camming](ms-xhelp:///?Id=beckhoff-984d-4c21-9ee9-97aff9b63946)
