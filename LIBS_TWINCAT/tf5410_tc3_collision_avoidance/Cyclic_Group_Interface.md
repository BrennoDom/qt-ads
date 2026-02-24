# Cyclic Group Interface

## Library
tf5410_tc3_collision_avoidance

## Category
Motion Control

# Cyclic Group Interface

The cyclic group interface provides the cyclical data exchange between PLC and a NC group object. The group interface contains the directions [NcToPlc](ms-xhelp:///?Id=beckhoff-892b-44d6-8ea2-407e79e859eb) and [PlcToNc](ms-xhelp:///?Id=beckhoff-bdeb-45e1-b156-f307964dc862). Both direction are divided in common and group specific data.

## AXES\_GROUP\_REF

```
TYPE AXES_GROUP_REF :   
STRUCT  
    PlcToNc AT %Q*       : CDT_PLCTOMC_GROUP;  
    NcToPlc AT %I*       : CDT_MCTOPLC_GROUP;  
END_STRUCT  
END_TYPE
```

**PlcToNc**: [PlcToNc](ms-xhelp:///?Id=beckhoff-bdeb-45e1-b156-f307964dc862) is a data structure that is cyclically exchanged between PLC and NC. Via this data structure the MC function blocks communicate with the motion group and send control information from the PLC to the NC. This data structure is automatically placed in the output process image of the PLC and must be linked with the input process image of a motion group.

**NcToPlc**: [NcToPlc](ms-xhelp:///?Id=beckhoff-892b-44d6-8ea2-407e79e859eb) is a data structure that is cyclically exchanged between PLC and NC. Via this data structure the MC function blocks communicate with the NC and receive status information from the NC. This data structure is automatically placed in the input process image of the PLC and must be linked in TwinCAT System Manager with the output process image of an NC axis.

Further Information

* [NcToPlc](ms-xhelp:///?Id=beckhoff-892b-44d6-8ea2-407e79e859eb)
* [PlcToNc](ms-xhelp:///?Id=beckhoff-bdeb-45e1-b156-f307964dc862)
