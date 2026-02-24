# Data type MC_CamActivationMode

## Library
tf5050_tc3_nc_camming

## Category
Motion Control

1. [TF5050 TC3 NC Camming](ms-xhelp:///?Id=beckhoff-984d-4c21-9ee9-97aff9b63946)
2. [Data type](ms-xhelp:///?Id=beckhoff-61cc-4984-82a9-77a1e817705f)
3. Data type MC\_CamActivationMode

# Data type MC\_CamActivationMode

```
TYPE MC_CamActivationMode :  
(  
   (* instantaneous change *)  
   MC_CAMACTIVATION_INSTANTANEOUS,   
  
   (* modify the data at a defined master position referring to the cam tables master position *)  
   MC_CAMACTIVATION_ATMASTERCAMPOS,  
  
   (* modify the data at a defined master position referring to the absolute master axis position *)  
   MC_CAMACTIVATION_ATMASTERAXISPOS  
  
   (* modify the data at the beginning of the next cam table cycle *)  
   MC_CAMACTIVATION_NEXTCYCLE,   
  
   (* not yet implemented!   
   modify the data at the beginning of the next cam table cycle, activation is valid for one cycle only *)  
   MC_CAMACTIVATION_NEXTCYCLEONCE,   
  
   (* modify the data as soon as the cam table is in a safe state to change its data *)  
   MC_CAMACTIVATION_ASSOONASPOSSIBLE,   
  
   (* don't accept any modification *)  
   MC_CAMACTIVATION_OFF,   
  
   (* delete all data which was written to modify the cam table but is still not activated *)  
   MC_CAMACTIVATION_DELETEQUEUEDDATA,   
  
   (* special mode at a defined master axis position in a defined positive direction *)  
   MC_CAMACTIVATION_ATMASTERAXISPOS_POSITVEDIRECTION,   
  
   (* special mode at a defined master axis position in a defined negative direction *)  
   MC_CAMACTIVATION_ATMASTERAXISPOS_NEGATIVEDIRECTION   
);  
END_TYPE
```

MC\_CamActivationMode specifies the timing and type of change for a cam plate. Changes can be affected through scaling, modification of the cam plate data, or switching of cam plates.

The following modes are possible:

## Scaling of cam plates

Cam plates can be scaled with the function block [MC\_CamScaling](ms-xhelp:///?Id=beckhoff-4b9c-4af2-8419-71548633a33c). The following activation modes are available.

|  |  |
| --- | --- |
| **MC\_CAMACTIVATION\_INSTANTANEOUS** | Scaling takes effect immediately. |
| **MC\_CAMACTIVATION\_ATMASTERCAMPOS** | Scaling takes effect at a certain cam plate position (master position within the cam plate). The scaling command must be issued ahead of this position.  The position refers to the non-scaled cam plate. If the position in the application refers to the scaled cam plate, it can be divided by the *MasterScaling* before the function block is called. |
| **MC\_CAMACTIVATION\_ATMASTERAXISPOS** | Scaling takes effect at a certain absolute position of the master axis. The scaling command must be issued ahead of this position. |
| **MC\_CAMACTIVATION\_NEXTCYCLE** | For a cyclic cam plate, scaling takes effect at the transition to the next period. |
| **MC\_CAMACTIVATION\_OFF** | No scaling is carried out. This can be used to limit scaling to one axis (master or slave), for example. |

## Setting the mode for changing a cam plate online (writing of point data)

[MC\_SetCamOnlineChangeMode](ms-xhelp:///?Id=beckhoff-d38a-4116-a7ad-dd65a8c72aaf) is used to specify when modified cam plate data become active (see also [MC\_WriteMotionFunction](ms-xhelp:///?Id=beckhoff-f4cf-455a-9065-f89bcc2425b4) and [MC\_WriteMotionFunctionPoint](ms-xhelp:///?Id=beckhoff-7a01-4003-99d3-69e74c0ccf29)).

In both cases the following modes are possible:

|  |  |
| --- | --- |
| **MC\_CAMACTIVATION\_INSTANTANEOUS** | The change takes effect immediately. |
| **MC\_CAMACTIVATION\_ATMASTERCAMPOS** | The change takes effect at a certain cam plate position (master position within the cam plate). The command must be issued ahead of this position.  The position refers to the non-scaled cam plate. If the position in the application refers to the scaled cam plate, it can be divided by the *MasterScaling* before the function block is called. |
| **MC\_CAMACTIVATION\_ATMASTERAXISPOS** | The change takes effect at a certain absolute position of the master axis. The command must be issued ahead of this position. |
| **MC\_CAMACTIVATION\_NEXTCYCLE** | For a cyclic cam plate, the change takes effect at the transition to the next period. |
| **MC\_CAMACTIVATION\_ASSOONASPOSSIBLE** | Modified cam plate data take effect as soon as system dynamics allow. |
| **MC\_CAMACTIVATION\_OFF** | Changes in cam plate data are ignored. |
| **MC\_CAMACTIVATION\_DELETEQUEUEDDATA** | Queued cam plate data are deleted. Data are queued if the change was requested at a certain master position or at the end of the cycle, for example. |

## Coupling with cam plates

The function block [MC\_CamIn](ms-xhelp:///?Id=beckhoff-9d6c-4e6e-b012-23819a633f2e) can be used to couple axes with cam plates. *ActivationMode* can optionally be used to specify from which position the slave axis becomes active.

|  |  |
| --- | --- |
| **MC\_CAMACTIVATION\_INSTANTANEOUS** | Cam plate coupling takes effect immediately, and the slave moves according to the cam plate data. |
| **MC\_CAMACTIVATION\_ATMASTERCAMPOS** | Cam plate coupling activation is suspended. The slave only moves from a defined cam plate position (master position within the cam plate) according to the cam plate data.  In coupling mode, the *ActivationMode* cannot be used in conjunction with [MC\_StartMode](ms-xhelp:///?Id=beckhoff-bb4a-4816-84ef-5a1abd389b8e) = MC\_STARTMODE\_RELATIVE or MC\_STARTMODE\_MASTERREL\_SLAVEABS.  The position refers to the non-scaled cam plate. If the position in the application refers to the scaled cam plate, it can be divided by the *MasterScaling* before the function block is called. |
| **MC\_CAMACTIVATION\_ATMASTERAXISPOS** | Cam plate coupling activation is suspended. The slave only moves from a defined absolute position of the master axis according to the cam plate data. |
| **MC\_CAMACTIVATION\_NEXTCYCLE** | Cam plate coupling activation is suspended. The slave moves from the next cycle transition (for cyclic cam plates).  In coupling mode, the *ActivationMode* cannot be used in conjunction with [MC\_StartMode](ms-xhelp:///?Id=beckhoff-bb4a-4816-84ef-5a1abd389b8e) = MC\_STARTMODE\_RELATIVE or MC\_STARTMODE\_MASTERREL\_SLAVEABS. |
| **MC\_CAMACTIVATION\_ATMASTERAXISPOS\_POSITVEDIRECTION** | The cam plate coupling is performed at a defined absolute position of the master axis, when the master passes the position in positive direction.  (This mode is a special case of MC\_CAMACTIVATION\_ATMASTERAXISPOS, which ensures safe activation in the immediate proximity around the current position, even at very low speeds with short-term changes of direction (noise)) |
| **MC\_CAMACTIVATION\_ATMASTERAXISPOS\_NEGATIVEDIRECTION** | The cam plate coupling is performed at a defined absolute position of the master axis, when the master passes the position in negative direction.  (This mode is a special case of MC\_CAMACTIVATION\_ATMASTERAXISPOS, which ensures safe activation in the immediate proximity around the current position, even at very low speeds with short-term changes of direction (noise)) |

## Switching of cam plates

The function block [MC\_CamIn](ms-xhelp:///?Id=beckhoff-9d6c-4e6e-b012-23819a633f2e) can be used to switch between cam plates in coupled state. *ActivationMode* can be used to specify from which position the changeover takes place.

|  |  |
| --- | --- |
| **MC\_CAMACTIVATION\_INSTANTANEOUS** | The cam plate is switched immediately, and the slave moves according to the new cam plate data. |
| **MC\_CAMACTIVATION\_ATMASTERCAMPOS** | Cam plate switching takes place at a defined cam plate position (master position within the cam plate).  The position refers to the non-scaled cam plate. If the position in the application refers to the scaled cam plate, it can be divided by the *MasterScaling* before the function block is called. |
| **MC\_CAMACTIVATION\_ATMASTERAXISPOS** | Cam plate switching takes place at a defined absolute master axis position. |
| **MC\_CAMACTIVATION\_NEXTCYCLE** | For cyclic cam plates cam plate switching takes place at the next cycle transition. For linear cam plates the switchover takes place at the edges of a defined region. |
| **MC\_CAMACTIVATION\_DELETEQUEUEDDATA** | A suspended cam plate switching process that has not been activated is discarded. |
| **MC\_CAMACTIVATION\_ATMASTERAXISPOS\_POSITVEDIRECTION** | The cam plate switching is performed at a defined absolute position of the master axis, when the master passes the position in positive direction.  (This mode is a special case of MC\_CAMACTIVATION\_ATMASTERAXISPOS, which ensures safe activation in the immediate proximity around the current position, even at very low speeds with short-term changes of direction (noise)) |
| **MC\_CAMACTIVATION\_ATMASTERAXISPOS\_NEGATIVEDIRECTION** | The cam plate switching is performed at a defined absolute position of the master axis, when the master passes the position in negative direction.  (This mode is a special case of MC\_CAMACTIVATION\_ATMASTERAXISPOS, which ensures safe activation in the immediate proximity around the current position, even at very low speeds with short-term changes of direction (noise)) |

[TF5050 | TwinCAT 3 NC Camming](ms-xhelp:///?Id=beckhoff-984d-4c21-9ee9-97aff9b63946)
