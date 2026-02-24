# Moving an Axis Manually

## Library
tf50x0_tc3_nc_ptp

## Category
Motion Control

# Moving an Axis Manually

On this page you will find out how axes can be moved manually from the System Manager.

## Configuration mode

* In **Config Mode,** the **Online** dialog is grayed out for an NC axis.

|  |  |
| --- | --- |
| 14717055 | Manual movement - Link To PLC…  For a manual movement: In the **Settings** dialog of the NC axis, set the entry **Link To PLC...** to the value "(none)" or stop the PLC program with the **Stop** button. |

|  |  |
| --- | --- |
| 65344633 | Manual movement – Activate configuration  For manual movement: Enable the configuration in order to transfer configuration changes to the target system. |

|  |  |
| --- | --- |
| 51230787DANGER | |
| Risk of injury due to movement of axes!  The commissioning results in a movement of axes. There is a risk of injury to body parts.   * Maintain a suitable safety distance. * Do not remain within the movement range. | |

## Run mode, controller enable, movement

For manual movement you have to restart the TwinCAT system in Run mode.

The **Online** dialog for an NC axis is suitable as a commissioning visualization for the initial commissioning of an axis.

|  |  |
| --- | --- |
| 58423902WARNING | |
| Axis position during initial commissioning  As a rule, the axis position is displayed incorrectly before initial commissioning.   * Therefore, perform homing before initial commissioning. * Or apply a position voltage as a zero position offset. | |

After you have restarted the TwinCAT system in Run mode, the **Ready** and **NOT Moving** checkboxes are each checked in the **Status (log.)** group box in the **Online** dialog for the NC axis Standard (Mapping via Encoder and Drive).

![56053076](/tf50x0_tc3_nc_ptp/1033/Images/png/2833824651__Web.png)

:   1. To move manually, first set the controller enable.
:   2. Move with the buttons **F1 - F6** and **F8 - F9**.

## Setting the controller enable

The drive must be ready to operate in order to set the controller enable.

|  |  |
| --- | --- |
| **Ready** | * If set, the drive is ready to operate. * The simulation axis is ready to operate as a rule. |

The **Set** button in the **Enabling** group box in the **Online** dialog of an NC axis opens the **Set Enabling** dialog to set the controller enable for the corresponding axis.

![34715636](/tf50x0_tc3_nc_ptp/1033/Images/png/2833831051__Web.png)

|  |  |
| --- | --- |
| **Controller** | * Required for position control to be active. * The controller is not active without the controller enable. * If linked to the PLC: Corresponds to the `Enable` input of the `MC_Power` function block. |
| **Feed Fw** | * The axis cannot be started in the positive direction without an enable in the positive direction. * If the axis is moving in the positive direction and the enable in the positive direction is canceled, the axis will be stopped.  If this cancelation of the enable is then undone again, the axis will not automatically restart. * If linked to the PLC: Corresponds to the `Enable_Positive` input of the `MC_Power` function block. |
| **Feed Bw** | * The axis cannot be started in the negative direction without an enable in the negative direction. * If the axis is moving in the negative direction and the enable in the negative direction is canceled, the axis will be stopped.  If this cancelation of the enable is then undone again, the axis will not automatically restart. * If linked to the PLC: Corresponds to the `Enable_Negative` input of the `MC_Power` function block. |
| **Override** | * Influences the velocity of all travel commands as a percentage. It is `0 ≤ Override ≤ 100.0`. |

## The buttons F1 - F6 and F8 - F9

![44005273](/tf50x0_tc3_nc_ptp/1033/Images/png/2833866251__Web.png)

* Move with the buttons F1 - F6 and F8 - F9.

|  |  |
| --- | --- |
| **F1** | Fast movement in the negative direction of travel. |
| **F2** | Slow movement in the negative direction of travel. |
| **F3** | Slow movement in the positive direction of travel. |
| **F4** | Fast movement in the positive direction of travel. |
| **F5** | Movement at target velocity to the target position. |
| **F6** | Stops axis movement. |
| **F8** | Reset |
| **F9** | Starts the homing sequence. |
