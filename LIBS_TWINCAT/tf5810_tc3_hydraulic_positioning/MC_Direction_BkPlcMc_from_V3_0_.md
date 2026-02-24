# MC_Direction_BkPlcMc (from V3.0)

## Library
tf5810_tc3_hydraulic_positioning

## Category
Motion Control

1. [TwinCAT PLC Hydraulics](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
2. [PLCopen Motion Control](ms-xhelp:///?Id=beckhoff-1ded-451e-88ec-a82873484e92)
3. [Data types](ms-xhelp:///?Id=beckhoff-25bd-4475-8df7-6d29ea7ab5ff)
4. MC\_Direction\_BkPlcMc (from V3.0)

# MC\_Direction\_BkPlcMc (from V3.0)

The constants listed here are used to identify the direction in which axes are moving.

```
TYPE MC_Direction_BkPlcMc:  
(  
MC_Positive_Direction_BkPlcMc := 1,  
MC_Shortest_Way_BkPlcMc,  
MC_Negative_Direction_BkPlcMc,  
MC_Current_Direction_BkPlcMc,  
MC_SwitchPositive_Direction_BkPlcMc,  
MC_SwitchNegative_Direction_BkPlcMc  
);  
END_TYPE
```

**MC\_Positive\_Direction\_BkPlcMc**: The movement is in the direction of rising values of position.

**MC\_Shortest\_Way\_BkPlcMc**: The direction of movement is selected so that the distance covered is as short as possible.

**MC\_Negative\_Direction\_BkPlcMc**: The movement is in the direction of falling values of position.

**MC\_Current\_Direction\_BkPlcMc**: The movement is in the same direction as the most recently executed movement.

**MC\_SwitchPositive\_Direction\_BkPlcMc:** not supported.

**MC\_SwitchNegative\_Direction\_BkPlcMc:** not supported.

[TF5810 | TwinCAT 3 Hydraulic Positioning](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
