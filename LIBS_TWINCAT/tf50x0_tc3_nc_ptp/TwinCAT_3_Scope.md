# TwinCAT 3 Scope

## Library
tf50x0_tc3_nc_ptp

## Category
Motion Control

# TwinCAT 3 Scope

This section shows how TwinCAT 3 Scope can be used to record a YT chart for travel path and travel velocity. With TwinCAT 3 Scope, variables can be recorded (TwinCAT 3 Scope Server) and displayed graphically (TwinCAT 3 Scope View).

## Subtree for a TwinCAT Measurement project

A separate subtree is created for a TwinCAT Measurement project in the **Solution Explorer**.

![31979016](/tf50x0_tc3_nc_ptp/1033/Images/png/2833984651__Web.png)

## Recording a YT chart

:   1. Create a TwinCAT Measurement project.
:   2. Create a **Scope YT Project** in the TwinCAT Measurement project.
:   A YT Chart is created.
:   3. Add a second axis to the YT chart.
:   4. The value of the `ActPos` variable of the NC axis from the NC configuration is plotted on one Y axis.
:   5. The value of the `ActVelo` variable of the NC axis from the NC configuration is plotted on the other Y axis.
:   6. Just before you move the NC axis, start a recording for the YT Chart with the **Record** button.
:   7. Shortly after the NC axis arrives at the target position, use the **Stop Record** button for the YT chart to stop the recording.

:   A TwinCAT 3 Scope recording illustrates the travel path and travel velocity over time when moving with the NC axis.

## Travel path and travel velocity

![19375690](/tf50x0_tc3_nc_ptp/1033/Images/png/2833450635__Web.png)

## Further information

* [TF3300 TC3 ScopeServer](ms-xhelp:///?Id=beckhoff-a35b-499c-a370-ebd50c806f50)
* [TE13xx | TC3 ScopeView](ms-xhelp:///?Id=beckhoff-3929-41c4-ae92-9874f1bc0a01)
