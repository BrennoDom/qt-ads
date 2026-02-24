# Data type MC_CamScalingMode

## Library
tf5050_tc3_nc_camming

## Category
Motion Control

1. [TF5050 TC3 NC Camming](ms-xhelp:///?Id=beckhoff-984d-4c21-9ee9-97aff9b63946)
2. [Data type](ms-xhelp:///?Id=beckhoff-61cc-4984-82a9-77a1e817705f)
3. Data type MC\_CamScalingMode

# Data type MC\_CamScalingMode

```
TYPE MC_CamScalingMode :  
(  
   (* user defines scaling parameters -scaling and -offset *)  
   MC_CAMSCALING_USERDEFINED,   
  
   (* offset is calculated automatically for best result *)  
   MC_CAMSCALING_AUTOOFFSET,   
  
   (* no modification accepted *)  
   MC_CAMSCALING_OFF   
);  
END_TYPE
```

Type and scope of the scaling of a cam plate coupling via function block [MC\_CamScaling](ms-xhelp:///?Id=beckhoff-4b9c-4af2-8419-71548633a33c).

**MC\_CAMSCALING\_USERDEFINED** : The scaling and offset are retained unchanged. The user has to calculate the scaling and offset such that a jump in the position is avoided.

**MC\_CAMSCALING\_AUTOOFFSET** : The scaling takes effect and the system adjusts the offset such that a jump in the position is avoided. Scaling should nevertheless occur during a phase with slave velocity 0, since otherwise a jump in velocity cannot be avoided.

**MC\_CAMSCALING\_OFF**: The scaling and offset are ignored. This mode is used when only slave scaling (i.e. without master scaling) is to be implemented.

## Autooffset

*Autooffset* mode ensures automatic adaptation of a cam plate offset. *Autooffset* can be used independently for the master or slave axis of a cam plate and affects both switchover and scaling of cam plates. The function operates based on the rules described below.

## Master-Autooffset

*Master-Autooffset* prevents discontinuity of the master position of the cam plate in the axis coordinate system during switching of cam plates with different master cycle or scaling of cam plates (master scaling). This function is required because the relative position of a cam plate in the axis coordinate system depends on the master cycle. If the master cycle is changed, e.g. through scaling, the position would change.

As a rule, *Master Autooffset* assumes that a cam plate already exists as reference for the corresponding axis coupling. This option is therefore not available during initial coupling. *Master-Autooffset* determines the master offset of the cam plate such that the master position within the cam plate is maintained. For scaling or switchover to a cam plate with a different master cycle this means that the relative (percentage) position before and after the switchover is identical.

Example: A cam plate has master cycle of 360° and is scaled by a factor of 2 to 720°. Scaling takes place at the 90° position within the cam plate, i.e. at 25 % of the start of a cycle. After the scaling the relative master position in the cam plate at 180° is therefore also 25 % of the start of a cycle.

![49630856](/tf5050_tc3_nc_camming/1033/Images/gif/460565259__en-US__Web.gif)

During a switchover at the edges of a cam plate (see [MC\_CamActivationMode](ms-xhelp:///?Id=beckhoff-489c-4d73-9497-514dfe742957) = *MC\_CAMACTIVATION\_NEXTCYCLE*), Master-Autooffset ensures a seamless sequence of cam plates, both for cyclic and linear cam plates.

*Master-Autooffset* cannot be used for a cam plate with relative coupling or switching, since these functions are mutually exclusive. Further restrictions apply to initial coupling. These are shown in the following table.

![44024524](/tf5050_tc3_nc_camming/1033/Images/gif/460568459__en-US__Web.gif)

![60676403](/tf5050_tc3_nc_camming/1033/Images/gif/460571659__en-US__Web.gif)

## Slave-Autooffset

*Slave-Autooffset* calculates a slave offset such that discontinuities in the slave position are avoided during cam plate switching or scaling. The slave offset is adjusted to ensure that the slave position is identical before and after the action.

If both *Master Autooffset* and *Slave-Autooffset* are used for cam plate switching or scaling, the master offset is calculated first, followed by the slave offset.

*Slave Autooffset* can be used in conjunction with any [MC\_StartMode](ms-xhelp:///?Id=beckhoff-bb4a-4816-84ef-5a1abd389b8e). It adjusts the cam plate such that there is no jump in the slave position.

[TF5050 | TwinCAT 3 NC Camming](ms-xhelp:///?Id=beckhoff-984d-4c21-9ee9-97aff9b63946)
