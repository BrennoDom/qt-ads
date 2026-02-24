# NC-Axes within the MOTION-Subtree

## Library
tf50x0_tc3_nc_ptp

## Category
Motion Control

# NC-Axes within the MOTION-Subtree

On this page you will find out where you can find and set NC axes in the MOTION subtree.

## Numerical Control (NC)

An NC axis maps a motor axis in software.

For this mapping of hardware in software, you can connect NC axes to PLC axis variables and servo drives within an IO configuration as part of an NC configuration.

* If no servo drive is available within an IO configuration, you can set up a [simulation axis](ms-xhelp:///?Id=beckhoff-0382-40f9-b692-ac6db48983d3).

## Subtree for NC axes: Structure

* Open the **Solution Explorer**.
* If an NC configuration has already been added, the MOTION subtree contains an SAF task subtree.
* The Axes axis level is located underneath the SAF task. This contains the NC axes.

![46479497](/tf50x0_tc3_nc_ptp/1033/Images/png/2833987851__Web.png)

Further information on inserting an NC axis can be found in the section [Inserting an NC configuration](ms-xhelp:///?Id=beckhoff-f1dd-4eb4-844b-96dbb3104c8a).

|  |  |
| --- | --- |
| **NC task 1 SAF** | * SAF task. * Task for the block execution (**S**atz**a**us**f**ührung). * Task in which the setpoint generation takes place. * Task that communicates with the fieldbus IO of the NC. |
| **NC task 1 SVB** | * SVB task. * Task for the block preparation (**S**atz**v**or**b**ereitung). * Linking and "Look-Ahead" of NCI segments. * No effect on single-axis movements (PTP). * Not responsible for the fieldbus IO of the NC. |
| **Image** | * NC process image. |
| **Tables** | * Tables. * For example for cam plates. |
| **Objects** | * Further TCom objects, e.g. for "TF5400 Advanced Motion Pack". |
| **Axes** | * NC axis configuration. * Created automatically. * Double-clicking opens an online dialog. * If the TwinCAT system has been started with the current configuration:  this online dialog displays the most important current setpoints and actual values of the NC axes configured in this configuration. |

## Tab for an NC axis

Double-clicking the NC axis **Axis 1** opens the selection for the tabs in the figure below.

![15662289](/tf50x0_tc3_nc_ptp/1033/Images/png/2834003851__Web.png)
