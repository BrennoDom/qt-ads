# Detecting servo drives automatically

## Library
tf50x0_tc3_nc_ptp

## Category
Motion Control

# Detecting servo drives automatically

## Scan

In the example shown, a scan of the IO configuration of EtherCAT and of a connected servo drive from the AX5000 series is performed.

|  |  |
| --- | --- |
| 16612996 | CONFIG mode  The target system must be in CONFIG mode for a scan of the IO configuration. |

|  |  |
| --- | --- |
| 15299237 | Third-party products  In general, a scan also works for third-party products, but not without exception. |

## Start Scan

![3475410](/tf50x0_tc3_nc_ptp/1033/Images/png/2551670027__Web.png)

:   The IO tree contains an entry called **Devices** [1].

:   1. Right-click the entry **Devices** [1].
:   A context menu opens.
:   2. Select the entry **Scan** [2].

:   Automatic reading of the device configuration begins.
:   A message box opens. It contains a notice that not all device types can be detected automatically.

![31278690](/tf50x0_tc3_nc_ptp/1033/Images/png/2551612427__Web.png)

:   A message box is open. It contains a notice that not all device types can be detected automatically.

:   1. Confirm this notice with the **OK** button [1].

:   A dialog opens. It shows the IO devices found.

## Selecting IO devices

![13072760](/tf50x0_tc3_nc_ptp/1033/Images/png/2897309579__Web.png)

:   A dialog shows the IO devices found.
:   An IO device can be selected with a checkbox.

:   1. If not already selected, select the IO device for which you wish to configure a drive with the checkbox [1].
:   2. If not already deselected, deselect the IO devices for which you do not wish to configure a drive with the other checkboxes.
:   3. Actuate the **OK** button [2] to confirm your settings.

:   The device for which you wish to configure a drive is entered in the IO tree under the **Devices** node.
:   A message box opens, asking whether you wish to search for new boxes.

## Searching for new boxes

![50545980](/tf50x0_tc3_nc_ptp/1033/Images/png/2551673227__Web.png)

:   A message box that asks you whether you wish to search for new boxes is open. Such boxes could be, for example, IO terminals or servo drives.

:   1. Confirm the message box with the **Yes** button [1].

:   The IO devices found will be appended.
:   A dialog opens, informing you that servo drives have been found. You will be asked whether servo drives should be scanned for connected motors.

## Scanning motors

This automatic function corresponds to the manual insertion of a servo drive in the IO configuration, as described in [Inserting servo drives manually](ms-xhelp:///?Id=beckhoff-84ed-4be2-8da7-8b7396fb8520).

|  |  |
| --- | --- |
| 52260639 | Beckhoff motors with digital name plate   * The automatic detection of motors is only possible with motors from Beckhoff with a digital name plate, i.e. with an encoder. * If automatic detection is not possible, the parameters of a motor can be set manually in the TwinCAT Drive Manager. The manual setting of motor parameters can also be important for diagnostic purposes. |

![583706](/tf50x0_tc3_nc_ptp/1033/Images/png/2551586827__Web.png)

:   In a dialog you will be asked whether a scan for motors should be performed.

:   1. Answer this question by actuating the **Yes** button [1].

:   Motors found are appended to the configuration in the IO tree.
:   A dialog opens, asking whether the motor appended to the IO configuration should be added to the NC configuration and linked to the NC configuration.
:   If the option **NC-Configuration** has been selected and confirmed, the associated logical axes will be automatically created and linked for the setpoint generation.
:   The scan has been completed for the selected devices of the connected hardware.  
    The result is that a configuration has been created in the IO tree for the selected devices of the connected hardware.

## Drive amplifiers: Further information

* [AX5000\_SystemManual\_HW2 - Version 2.0](https://infosys.beckhoff.com/content/1033/ax5000_system_doku_hw2/index.html)
* AX5000 - TwinCAT Drive Manager

## EtherCAT drive(s) added

This automatic function corresponds to the manual creation and connection of an NC axis in the sections

* [Inserting an NC configuration,](ms-xhelp:///?Id=beckhoff-f1dd-4eb4-844b-96dbb3104c8a)
* [Button "Linked with I/O…".](ms-xhelp:///?Id=beckhoff-fb09-40bf-99fb-1c4b47e6ea14)

![5253358](/tf50x0_tc3_nc_ptp/1033/Images/png/3035149963__Web.png)

:   The **EtherCAT drive(s) added** dialog is open.
:   This dialog offers you the option of adding the axes inserted into the IO configuration to the NC configuration or to the CNC configuration and connecting them with the respective configuration.

:   1. Select the option field **NC-Configuration** [1] if you wish to add the inserted axis to the NC configuration.
:   2. Confirm your selection with the **OK** button [2].
:   3. If you do not wish to add the axes inserted into the IO configuration to the NC configuration or to the CNC configuration, you have the option later on of manually creating NC axes or CNC axes for the axes inserted into the IO configuration and of connecting them with the axes inserted into the IO configuration.  
    Information on this can be found in the section ["NC configuration"](ms-xhelp:///?Id=beckhoff-0c37-43ef-aed3-6b6abd71bd4e).
:   You have selected the option **NC-Configuration** [1] and confirmed it with the **OK** button [2].

:   The axis inserted into the IO configuration is added to the NC configuration and connected to the NC configuration.
:   Within the scope of the NC configuration, an NC-Task is created in the MOTION tree.
:   The NC-Task subtree contains a subtree with the name "Axes".
:   A module is created in the Axes subtree for each axis created in the NC configuration. Each of the modules created is given a default name, e.g. "Axis 1", "Axis 2", ….
:   Each axis in a subtree within the NC configuration is linked with an axis configured within the IO configuration.

## Enabling Free Run

If the Free Run mode is enabled, IO variables can be read from and written to supported Bus Terminals without a configured and enabled task. The target system must be in configuration mode for this.

![47280229](/tf50x0_tc3_nc_ptp/1033/Images/png/2551579275__Web.png)

:   A message box asks whether the Free Run mode should be enabled.

:   1. To enable the Free Run mode, confirm the message box with "Yes"
:   2. If you don't wish to enable the Free Run mode, answer this question with **No** [1].

:   After actuating the **No** [1] button, the message box closes and the Free Run mode is not enabled.

|  |  |
| --- | --- |
| 22868878 | IO, MOTION Activation of the configuration: Activate Configuration   * A configuration only becomes effective on a target system when it is activated for this target system. * An IO configuration determined by a scan also has to be activated for the intended target system. * Likewise, you have to activate a configuration in the MOTION subtree for the intended target system. * To do this, select your desired target system under **Choose Target System**. * Then activate the configuration for your chosen target system with the **Activate Configuration** button. |
