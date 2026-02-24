# MC_FlyingGear_BkPlcMc

## Library
tf5810_tc3_hydraulic_positioning

## Category
Motion Control

1. [TwinCAT PLC Hydraulics](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
2. [PLCopen Motion Control](ms-xhelp:///?Id=beckhoff-1ded-451e-88ec-a82873484e92)
3. [Motion](ms-xhelp:///?Id=beckhoff-c1ef-44e8-b7a5-0096a7da1950)
4. MC\_FlyingGear\_BkPlcMc

# MC\_FlyingGear\_BkPlcMc

![18911189](/tf5810_tc3_hydraulic_positioning/1033/Images/gif/9007205540303371__Web.gif)

The function block takes over the control of a flying gear coupling.

```
VAR_IN_OUT  
    Master:                 AXIS_REF_BkPlcMc;  
    Slave:                  AXIS_REF_BkPlcMc;  
END_VAR  
VAR_INPUT  
    Enable:                 BOOL;  
    Ratio:                  LREAL;  
    MasterSyncPosition:     LREAL;   
    SlaveSyncPosition:      LREAL;   
    SlaveDesyncPosition:    LREAL;   
    SlaveStopPosition:      LREAL;   
    DefaultSlaveNegative:   BOOL;   
VAR_OUTPUT  
    StartSync:              BOOL;  
    InSync:                 BOOL;  
    Busy:                   BOOL;  
    Active:                 BOOL;  
    Error:                  BOOL;  
    ErrorId:                BOOL;  
END_VAR
```

**Active:** This signal goes TRUE as soon as the master passes the MasterSyncPosition in the designated direction. It goes FALSE when the SlaveStopPosition is reached in the opposite direction of the slave.

**Busy:** This signal goes TRUE if Enable is TRUE, master and slave are ready and not in an error state and the transferred parameters are suitable.

**DefaultSlaveNegative:** In some cases, the function block cannot determine the intended work direction from the transferred parameters. Additional information is then required from the application.

**Enable:** This signal allows the function block to become active as soon as the master's position passes the MasterSyncPosition in the designated direction.

**Error:** This signal goes TRUE if there are unsuitable parameters on a rising edge at Enable or if the master or slave is in an error state on a TRUE at Enable.

**ErrorId:** A numerically encoded indication of an error cause.

**InSync:** This signal is TRUE if the coupling is fully active.

**Master:** Here, the address of a variable of type [AxisRef\_BkPlcMc](ms-xhelp:///?Id=beckhoff-002b-4aba-81ea-1693fb03013c) should be transferred.

**MasterSyncPosition:** This parameter indicates the position in the designated direction of the master at which the coupling should have been fully established.

**Ratio:** This parameter specifies the gear ratio between master and slave for the fully coupled case.

**Slave:** Here, the address of a variable of type [AxisRef\_BkPlcMc](ms-xhelp:///?Id=beckhoff-002b-4aba-81ea-1693fb03013c) should be transferred.

**SlaveDesyncPosition:** This parameter indicates the position in the designated direction of the slave at which the release of the coupling should start.

**SlaveStopPosition:** This parameter indicates the position in the designated direction of the slave at which the release of the coupling should have been completed.

**SlaveSyncPosition:** This parameter indicates the position in the designated direction of the slave at which the coupling should have been fully established.

**StartSync:** This signal is TRUE if the master is within the section for the establishment of the coupling.

## Behavior of the function block

The function block establishes a coupling between a master and a slave axis that is established and released on the fly. The parameterization and enable can vary the behavior in wide areas. In combination with positioning commands, a variety of motion sequences can be realized. Just a few samples are shown here.

Note The scopes were created using the sample S106\_FlyingGear. The number of the sample corresponds to the selected nSequence.

## During commissioning

When measuring the position of the master, the zero point should be shifted so that the actual position represents comprehensible information about the situation in the machine.

For the slave, the zero shift should be chosen in such a way that the actual position, taking into account the dimensions of the material, tools and other installations, matches that of the master, if the remaining gap has just become 0. To avoid elastic deformation, no force should have been built up.

## Sample #1

Here, master and slave move in the same direction. Both return to their starting position.

![35982977](/tf5810_tc3_hydraulic_positioning/1033/Images/gif/9110059787__Web.gif)

Preparation:

* The master was positioned at 800.0 mm.
* The slave was positioned at 500.0 mm.
* The location at which the slave begins with the establishment of the synchronization is thus defined.
* The final coupling factor (ratio) has been set to 1.0 for better understanding. In practical use, this factor is often chosen slightly smaller in order to trigger a transition to a pressure or force control.
* The point for achieving synchronization has been set to 460.0 mm for the master (MasterSyncPosition) and 450.0 mm for the slave (SlaveSyncPosition).
* The difference of 10.0 mm between master and slave represents the distance required for material, tools and other installations and is chosen here in such a way that the representation illustrates the behavior.
* The distance for synchronizing the slave is calculated from the starting position of the slave and the SlaveSyncPosition and is in this case 500.0 - 450.0 => 50 mm.
* With a ratio of 1.0, the master has a distance to synchronize of 2.0 \* 50 mm => 100 mm. So the synchronization of the master will start at 460.0 mm+100 mm => 560 mm (MasterSyncPosition plus distance). If the master is below this position when the coupling is enabled, an error is signaled.
* The point for leaving the synchronization has been set to 450.0 mm for the slave (SlaveDesyncPosition).
* The point for the complete release of the coupling (SlaveStopPosition) has been set to 500.0 mm. The intended distance for this is thus 500.0 mm – 450 mm => 50 mm.
* With a ratio of 1.0, the master will also travel a distance of 2.0 \* 50 mm => 100 mm.
* Distances that the master travels before TM\_1 and after TM\_4 in the above scope do not concern the slave.
* If the master changes its speed between TM\_1 and TM\_2 or between TM\_3 and TM\_4, the slave will take this into account. Then its speed curve may be less clear than in the above scope.

## Sample #2

Here, the master and slave move in opposite directions. Both return to their starting position.

![55411339](/tf5810_tc3_hydraulic_positioning/1033/Images/gif/9117088651__Web.gif)

* Here, the starting position is not 50 mm above the SlaveSyncPosition, but by the same amount below it.

## Sample #3

Here, master and slave move in the same direction. However, the slave only returns to its starting position by means of an MC\_MoveAbsolut\_BkPlcMc().

![28940004](/tf5810_tc3_hydraulic_positioning/1033/Images/gif/9117091211__Web.gif)

* Here, the initial situation is the same as in the sample #1.
* However, the SlaveStopPosition is different here. The slave accordingly stops earlier.
* The distance between SlaveDesyncPosition and SlaveStopPosition is 100 mm here. As a result, the release of the coupling creates a different profile than the establishment of the coupling.
* Once the master has completed its movement, the function block is deactivated and the slave is driven to the starting position with its own command.

[TF5810 | TwinCAT 3 Hydraulic Positioning](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
