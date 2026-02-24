# The PlcMcManager

## Library
tf5810_tc3_hydraulic_positioning

## Category
Motion Control

1. [TwinCAT PLC Hydraulics](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
2. [Knowledge Base](ms-xhelp:///?Id=beckhoff-873e-46cd-925a-b9a96eea638e)
3. The PlcMcManager

# The PlcMcManager

The PlcMcManager supports commissioning and testing of axes, which are automated using the hydraulics library. It visualizes the actual state and enables access to parameters and triggering of commands.

|  |  |
| --- | --- |
| 32787233 | The PlcMcManager is not intended for operating machines and systems. It is not a substitute for a user interface. |

## Safety instructions

Note

Unexpected machine behavior

The commands triggered by the PlcMcManager can obstruct automatic actions and responses of the control software obstruct or influence them in an unexpected or undesirable direction. This may result in unexpected and dangerous movements.

## Installation

**For TC2:** A license-free copy of the PlcMcManager is provided with the library or the documentation. Select a suitable path, then create a shortcut on the desktop of the PC. Without such a shortcut, the PlcMcManager can only be started from Explorer.

**For TC3:** When downloading the library, a license-free copy of the PlcMcManager is created in the directory *C:\TwinCAT\Functions\TF5810-TC3\_Hydraulics-Positioning*. If your TwinCAT not installed under to *C:* or in another directory, the path must be adjusted accordingly.

## Running the PlcMcManager

If the tool is stored on the PC, it can be started by double-clicking.

## Offline display of a parameter file

In the menu bar under **Online** you will find the **Offline file mode**, where a dialog for selecting an axis parameter file of type DAT is offered. When a file is opened, the axis parameters are show like in online mode, as far as possible.

|  |  |
| --- | --- |
| 26649649 | No actual axis states are shown, and no axis commands can be triggered. This also applies if the displayed parameters belong to an axis, to which access would be possible. |

## Online operation

If the runtime system with the library function blocks is not present on the PC on which the PlcMcManager is running, the target system has to be selected first. In the menu bar under **Online** you will find the **Target** dialog, where the computers are listed that are entered as **Remote Computers** in **TwinCAT System Service** on the **AMS Router** tab.

![38520254](/tf5810_tc3_hydraulic_positioning/1033/Images/gif/18014400109641099__en-US__Web.gif)

By selecting a **Remote Computer**, the communication with the runtime system is activated automatically. If the runtime system with the library function blocks is present on the PC on which the PlcMcManager is running, the communication with the runtime system can be activated with **Login** via the menu bar under **Online**.

In the current versions the PlcMcManager is prepared for use under TC3. To establish the connection at runtime, it checks the expected ADS addresses for both TC2 and TC3. This may take several seconds, particularly if a network connection is used. The details shown below should then appear.

![11137969](/tf5810_tc3_hydraulic_positioning/1033/Images/gif/18014400109643531__en-US__Web.gif)

1. Shows the port and the server used for the communication with the runtime system.
2. The mode is displayed. Since no axis has been selected up to this point, the PlcMcManager is still in OFFLINE mode.
3. Shows the version information of the library used by the PLC application.

If these details do not appear after a few seconds, the connection has failed. This can have a number of reasons:

* No target system was selected, despite the fact that the application is not running on the same computer as the PlcMcManager.
* The PLC application does not contain a [MC\_AxAxAdsCommServer\_BkPlcMc](ms-xhelp:///?Id=beckhoff-5702-45de-80d2-87ae2f7a2a8a) function block or does not call it.
* The application is not running on the selected target system.
* No connection to the selected target system.
* The PC on which the PlcMcManager is running has no access rights to the selected target system.
* The PLC is not running.

If a dialog with an error message appears at this point, the connection to the target system is disturbed (timeout), or the PlcMcManager and the library used in the application are not compatible. Incompatibility is usually due to a new library version being used, without updating the PlcMcManager.

Many parameter input fields have a "?" field on the left-hand side. This can be used to call up a brief explanation of the parameter.

Sample: Explanation of the parameter <Global.CreepDistance>:

![33132859](/tf5810_tc3_hydraulic_positioning/1033/Images/gif/9007204016347403__en-US__Web.gif)

## First steps

Double-clicking on the server shown on the left displays the axes used in the application as a list. Click on an axis to select it. Its status is then cyclically updated, and its parameter are accessible. If the communication fails for some reason, it can be restarted by clicking on an axis.

![29760277](/tf5810_tc3_hydraulic_positioning/1033/Images/gif/9007204016322315__en-US__Web.gif)

This example shows the file path and name used for this axis. However, an **InitError 1804 (0x70C)** and an **InitState** of **-2** are reported. The error code indicates a file error and the InitState is "negative terminated". There are several possible causes for this:

* The path does not exist on the computer where the PLC application is running. Problems can easily arise if the application goes online for the first time on another system.
* The path is not accessible from the location of the PLC runtime. This is possible, for example, if the path points to a network.
* Reading and/or writing is not allowed on this path.
* The path or file name is not spelled correctly. The backslash may be missing at the end of the path name.
* There is no corresponding file under the specified path name.

The last cause listed always occurs when commissioning of a PLC application is started without an existing file. To create a file with default parameters, press the **[Save]** key to initiate a write operation with the initial parameter values. The **[Reset]** key deletes the error state, and in this case the loading of the parameters from the file is repeated. If the problem cannot be solved by this procedure, it is caused by another of the listed causes.

## Data and commands

The PlcMcManager only graphically displays variables from the PLC. Runtime values can be found in the AxisRef in stRtData. Parameters that are changed via the PlcMcManager must actively be written to the variables of the PLC via the **Activate** button. All values that have to be saved permanently are stored in the AxisRef under stAxParams. These parameters are saved by the PLC, not by the PlcMcManager.

If the axis is controller and feed enabled by the PLC with an MC\_Power\_BkPlcMc function block, it can be moved using the jog keys (<, <<, >>, >). At this time it is still a simulated axis. The axis can also be commanded via the **Position** and **Velocity** fields. The movement command is executed via the **Start** button.

[TF5810 | TwinCAT 3 Hydraulic Positioning](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
