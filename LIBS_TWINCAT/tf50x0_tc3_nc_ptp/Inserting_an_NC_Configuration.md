# Inserting an NC Configuration

## Library
tf50x0_tc3_nc_ptp

## Category
Motion Control

# Inserting an NC Configuration

## Motion: Add New Item…

![28414304](/tf50x0_tc3_nc_ptp/1033/Images/png/2551628427__Web.png)

:   1. Right-click the node MOTION [1].
:   A context menu opens.
:   2. Select the context menu entry **Add New Item…** [2].

:   The dialog **Insert Motion Configuration** opens.

## Dialog: Insert Motion Configuration

![54402144](/tf50x0_tc3_nc_ptp/1033/Images/png/2551618827__Web.png)

|  |  |
| --- | --- |
| [1] | Select this entry if you wish to add an NC configuration. |
| [2] | Give a name to the NC configuration that you wish to insert. |
| [3] | Confirm your settings. |

## Inserting a motion configuration

:   The dialog **Insert Motion Configuration** is open.

:   1. If you wish to add an NC configuration, select the entry **NC/PTP NCI Configuration** [1].
:   2. In the text box **Name** [2] give a name to the NC configuration that you wish to insert.
:   3. Confirm your settings with the **Ok** button [3].

:   An NC task is inserted in the MOTION subtree.
:   The subtree of the NC task contains the entry **Axes**.

## Axes: Add New Item…

![19857248](/tf50x0_tc3_nc_ptp/1033/Images/png/2551590027__Web.png)

:   1. Right-click the node **Axes** [1].
:   A context menu opens.
:   2. In the context menu, select the entry **Add New Item…** [2].

:   The dialog **Insert NC Axis** opens.

## Dialog: Adding an NC axis

![44497505](/tf50x0_tc3_nc_ptp/1033/Images/png/2551622027__Web.png)

:   With the opened dialog **Insert NC Axis** you can add one or more axes to the associated NC task.

:   1. The text box **Name** [1] provides you with the option to give a name to the axis that you wish to insert.
:   2. In the drop-down box **Type** [2], select **Continuous Axis** [2] if you wish to insert one or more continuous axes.  
    A continuous axis is, for example, a servo axis, a DC axis or a stepper axis.
:   3. You can add several axes with the same settings in a single step using the numeric up/down control element **Multiple** [3].
:   4. Confirm your settings with the **OK** button [4].

:   For example, two axes have been added to the subtree **Axes**.
:   In the example, these two axes have been given the names "Axis 1" and "Axis 2" as default names.
:   For each of the inserted axes you have the option to open the Settings dialog.
:   In the **Settings** dialog you can connect the axis of an NC task with an appropriate axis inside the IO configuration and with an axis inside the PLC configuration.

|  |  |
| --- | --- |
| 64933228 | The parameters for the axis commissioning can be found at the end of this documentation. |
