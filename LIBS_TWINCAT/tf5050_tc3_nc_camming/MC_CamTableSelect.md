# MC_CamTableSelect

## Library
tf5050_tc3_nc_camming

## Category
Motion Control

1. [TF5050 TC3 NC Camming](ms-xhelp:///?Id=beckhoff-984d-4c21-9ee9-97aff9b63946)
2. [Cam plates](ms-xhelp:///?Id=beckhoff-a988-474a-ac58-949c3c4ab0ef)
3. MC\_CamTableSelect

# MC\_CamTableSelect

![4876303](/tf5050_tc3_nc_camming/1033/Images/png/1004940939__en-US__Web.png)

With the function block *MC\_CamTableSelect*, a table can be specified and loaded into the NC. The block creates a new table and simultaneously fills it with data provided by the PLC.

*MC\_CamTableSelect* does not have to be used, if a table created with the TwinCAT cam plate editor is to be used. In this case, simple coupling with [MC\_CamIn](ms-xhelp:///?Id=beckhoff-9d6c-4e6e-b012-23819a633f2e) is sufficient.

## Inputs

```
VAR_INPUT  
   Execute        : BOOL;   
   Periodic       : BOOL;   
   MasterAbsolute : BOOL;   
   SlaveAbsolute  : BOOL;   
   CamTableID     : MC_CAM_ID;   
END_VAR
```

|  |  |
| --- | --- |
| **Execute** | The command is executed with a rising edge at input *Execute*. |
| **Periodic** | *Periodic* is TRUE if the cam plate is cyclically repeated. |
| **MasterAbsolute** | Absolute interpretation of master positions |
| **SlaveAbsolute** | Absolute interpretation of slave positions |
| **CamTableID** | ID of the cam plate used for the coupling |

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
| **Done** | Becomes TRUE if the cam plate was created successfully. |
| **Busy** | The *Busy* output becomes TRUE when the command is started with *Execute* and remains TRUE as long as the command is processed. If *Busy* becomes FALSE again, the function block is ready for a new job. At the same time one of the outputs, *Done* or *Error*, is set. |
| **Error** | Becomes TRUE, as soon as an error occurs. |
| **ErrorID** | If the error output is set, this parameter supplies the error number |

## Inputs/outputs

```
VAR_IN_OUT  
   Master   : AXIS_REF;  
   Slave    : AXIS_REF;  
   CamTable : MC_CAM_REF;  
END_VAR
```

|  |  |
| --- | --- |
| **Master** | Axis data structure of the master - currently not used. |
| **Slave** | Axis data structure of the slave - currently not used. |
| **CamTable** | The data structure of type [MC\_CAM\_REF](ms-xhelp:///?Id=beckhoff-1365-4325-92ea-77764879dfc0) describes the data storage for the cam plate in the PLC |

The axis data structure of type AXIS\_REF addresses an axis uniquely within the system. Among other parameters it contains the current axis status, including position, velocity or error status.

[TF5050 | TwinCAT 3 NC Camming](ms-xhelp:///?Id=beckhoff-984d-4c21-9ee9-97aff9b63946)
