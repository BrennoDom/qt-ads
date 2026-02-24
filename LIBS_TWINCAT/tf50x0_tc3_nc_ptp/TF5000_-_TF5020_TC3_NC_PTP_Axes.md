# TF5000 - TF5020 | TC3 NC PTP Axes

## Library
tf50x0_tc3_nc_ptp

## Category
Motion Control

# TF5000 - TF5020 | TC3 NC PTP Axes

![20077469](/tf50x0_tc3_nc_ptp/1033/Images/jpg/3406540683__Web.jpg)

TC3 NC PTP implements Motion Control in software for Point-to-Point movements. The axes are represented by axis objects and provide a cyclic interface, e.g. for the PLC. This axis object is then linked with a corresponding physical axis. In this way the most diverse axis types with the most diverse fieldbus interfaces can be connected abstractly with the axis objects, which always offer an identical configuration interface. The control of the axes can be configured in various conformations (position or velocity interface) and various controllers. The axes are configured in TwinCAT Engineering.

* TF5000: Up to 10 axes (extendable up to a maximum of 255 axes).
* TF5010: Extension of TC3 NC PTP 10 to up to 25 axes (extendable to a maximum of 255 axes).
* TF5020: Extension of TC3 NC PTP 10 to up to 255 axes.

## TC3 NC PTP:

* Supports electrical and hydraulic servo drives, frequency converter drives, stepper motor drives, DC drives, switched drives (fast/slow axes), simulation axes and encoder axes.
* Supports various encoders such as incremental encoder, absolute encoder, digital interface to the drives such as EtherCAT, SERCOS, SSI, Lightbus, PROFIBUS DP/MC, pulse train.
* Provides standard axis functions such as start/stop/reset/referencing, velocity override, master/slave couplings, electronic gearing, online distance compensation.
* Programming is carried out via PLCopen-compliant IEC 61131-3 function blocks.
* Provides convenient axis commissioning options.
* Contains online monitors for all axis state variables, such as actual/setpoint values, enables, control values, online axis tuning.

**Further scopes/options of TC3 NC PTP:**

* Forcing of axis variables.
* Configuration of all axis parameters, such as measuring system, drive parameters and position controller.
* Configurable controller structures: P-controller, PID controller, PID with velocity pre-control, PID with velocity and acceleration pre-control.
* Online master/slave and slave/master conversion.
* “Flying saw” (diagonal saw).
* Cam plates (supported by TC3 CAM Design Editor [optional]).
* FIFO axes (optional).
* External set value generators.
* Multi-master coupling.

## Further information

* [PLC Libraries](ms-xhelp:///?Id=beckhoff-63a7-4c0e-8569-314547c8cffc)
* [ADS Specification of the NC](ms-xhelp:///?Id=beckhoff-7b41-4d26-a133-61727f15d958)
