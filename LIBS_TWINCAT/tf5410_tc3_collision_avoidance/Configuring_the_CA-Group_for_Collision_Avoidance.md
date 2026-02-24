# Configuring the CA-Group for Collision Avoidance

## Library
tf5410_tc3_collision_avoidance

## Category
Motion Control

# Configuring the CA-Group for Collision Avoidance

In principle, the configuration described here applies to all motion objects in the Advanced Motion Pack.

:   1. Add a new **NC/PTP NCI configuration** in the **Motion** section.

![40414969](/tf5410_tc3_collision_avoidance/1033/Images/png/6326430987__Web.png)![28190407](/tf5410_tc3_collision_avoidance/1033/Images/png/6326433547__Web.png)

:   2. Add all axes to the NC configuration.
![52387077](/tf5410_tc3_collision_avoidance/1033/Images/png/6326436107__Web.png)![1721653](/tf5410_tc3_collision_avoidance/1033/Images/png/6326438667__Web.png):   3. Add the corresponding group to the **Objects** entry in the NC configuration:  
    For coordinated movement, multi-dimensional movements: [CA Group (TF5410 TwinCAT 3 Collision Avoidance)](ms-xhelp:///?Id=beckhoff-db68-4aa8-b9c7-ce918ad20973).

![15494878](/tf5410_tc3_collision_avoidance/1033/Images/png/6326610187__Web.png)![5236179](/tf5410_tc3_collision_avoidance/1033/Images/png/6437620235__Web.png)

:   4. Check the execution task in the group. This must always be set to "NC-Task 1 SAF".
![47125611](/tf5410_tc3_collision_avoidance/1033/Images/png/6437622795__Web.png)![21477321](/tf5410_tc3_collision_avoidance/1033/Images/png/6437625355__Web.png):   5. Configure the group parameters according to the desired application.  
    For further explanation of the group parameters, see [CA Group (TF5410 TwinCAT 3 Collision Avoidance)](ms-xhelp:///?Id=beckhoff-db68-4aa8-b9c7-ce918ad20973).
:   6. To address the group from the PLC, a cyclic interface must be declared and linked to the I/Os of the group (see PLC library [Tc3\_McCoordinatedMotion](ms-xhelp:///?Id=beckhoff-49d8-44ac-9a33-5ef69f2f5fb4)). To address and enable the axes, the library Overview must be added to the project.

:   A new NC/PTP NCI configuration has been created.

```
VAR  
    stGroupRef : AXES_GROUP_REF;  
END_VAR
```

![59078165](/tf5410_tc3_collision_avoidance/1033/Images/png/6437627915__Web.png)![61941440](/tf5410_tc3_collision_avoidance/1033/Images/png/6437630475__Web.png)

Further Information

* [Geo Compensation](ms-xhelp:///?Id=beckhoff-6cf1-4955-8461-cd05652b3b1b)
