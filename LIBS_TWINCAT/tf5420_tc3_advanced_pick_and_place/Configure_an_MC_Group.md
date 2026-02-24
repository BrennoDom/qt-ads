# Configure an MC Group

## Library
tf5420_tc3_advanced_pick_and_place

## Category
Motion Control

# Configure an MC Group

Basically, the configuration described here is valid for all Motion Objects in the Advanced Motion Pack.

:   1. Add new “NC/PTP NCI Configuration” in the Motion section.

![10576944](/tf5420_tc3_advanced_pick_and_place/1033/Images/png/6326430987__Web.png)![28083633](/tf5420_tc3_advanced_pick_and_place/1033/Images/png/6326433547__Web.png)

:   2. Add all axes to the NC-Configuration.

![51426113](/tf5420_tc3_advanced_pick_and_place/1033/Images/png/6326436107__Web.png)![60181840](/tf5420_tc3_advanced_pick_and_place/1033/Images/png/6326438667__Web.png)

:   3. Add the appropriate Group to the entry “Objects” in the NC-Configuration:  
     For Coordinated Motion, multi-dimensional movements: [MC Group Coordinated Motion](ms-xhelp:///?Id=beckhoff-02a8-413e-810b-f959e700e534) or [MC Group with Pick-and-Place](ms-xhelp:///?Id=beckhoff-7ae8-4d8f-ae10-53ca658b7d2e).

![4765656](/tf5420_tc3_advanced_pick_and_place/1033/Images/png/6326610187__Web.png)![42890904](/tf5420_tc3_advanced_pick_and_place/1033/Images/png/8896650891__Web.png)![50473818](/tf5420_tc3_advanced_pick_and_place/1033/Images/png/8896652811__Web.png)

:   4. Check the Tasks in the Group.  
    Context ID 0 has to be set to **“NC-Task 1 SAF”**.  
    Context ID 1 has to be set to **“NC-Task 1 SVB”**.

![51611184](/tf5420_tc3_advanced_pick_and_place/1033/Images/png/8917257739__Web.png)

:   5. Configure the group parameters according to the desired application.  
     For more explanations referring to the group parameters see the following sections.
:   6. To address the group from the PLC a cyclic interface has to be declared and linked to the IO of the group (see PLC Library [Tc3\_McCoordinatedMotion](ms-xhelp:///?Id=beckhoff-02a8-413e-810b-f959e700e534)). To address and enable the axes the library “Tc2\_Mc2” has to be added to the project.

:   A new “NC/PTP NCI Configuration” has been established.

```
VAR  
    stGroupRef : AXES_GROUP_REF;  
END_VAR
```

![61847473](/tf5420_tc3_advanced_pick_and_place/1033/Images/png/8897294731__Web.png)![19756352](/tf5420_tc3_advanced_pick_and_place/1033/Images/png/8897296651__Web.png)
