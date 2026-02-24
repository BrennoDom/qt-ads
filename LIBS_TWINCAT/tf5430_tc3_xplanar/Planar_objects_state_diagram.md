# Planar objects state diagram

## Library
tf5430_tc3_xplanar

## Category
Motion Control

# Planar objects state diagram

The Planar State Machine is used by the Planar mover, the Planar track and the Planar group. All of these components can be in the *seven* planar states: Enabling, Enabled, Disabling, Disabled, Resetting, ErrorPending, Error.

![54453050](/tf5430_tc3_xplanar/1033/Images/png/9022242059__Web.png)

|  |  |
| --- | --- |
| 20315403 | The error reaction depends on how serious the error is. For minor errors, the normal error reaction is a QuickStop. The user can also force the error reaction Abort by Disable() in this case. The command must be sent in one of the three states: ErrorPending, Error or Resetting. |

## Enabling

In the Enabling state, the Enable command is executed. At the end of this command, the component is in the Enabled state. In the Enabling state, a Disable command can be sent that cancels the Enable command and causes the state to change to Disabling.

## Enabled

In the Enabled state the component is fully functional and can be used by the user. In this state a Disable command can be sent. The state then switches to Disabling.

## Disabling

In the Disabling state the Disable command is executed. At the end of this command, the component is in the Disabled state. In the Disabling state, an Enable command can be sent that cancels the Disable command and causes the state to change to Enabling.

## Disabled

After the system is booted the components are in the Disabled state. They can be placed in the Enabling state using an Enable command. The components are not functional in the Disabled state.

## Resetting

The component is in the process of rectifying the error. Depending on the error reaction it is then in the Enabled or Disabled state.

## ErrorPending

When an error occurs the component reaches the ErrorPending state from all other states except the Resetting state. Once the error has been processed correctly, the state switches to Error.

## Error

The Error state means that an error has occurred and the component can now be placed in the Resetting state using the Reset command in order to correct the error.
