# Homing

## Library
tf50x0_tc3_nc_ptp

## Category
Motion Control

# Homing

Homing refers to an axis initialization run during which the correct actual position is determined by means of a reference signal. This can be NC-guided, as described here.

Alternatively, there is also drive-guided homing, which is performed independently by a suitable drive without the influence of the control system. For details, please refer to the documentation of the drive system used.

## Procedure

1. The axis is at a random position.
2. The axis moves in the parameterized direction and searches for the reference switch (referencing cam/calibration cam).
3. The axis reverses as soon as the referencing cam is detected.
4. The axis moves away from the referencing cam and detects the falling edge of the cam signal.
5. The axis continues to move and searches for the sync pulse (latch signal or zero pulse of the encoder).
6. The reference position is set and the axis stops. The standstill position of the axis deviates slightly from the reference position.

![8621428](/tf50x0_tc3_nc_ptp/1033/Images/png/11506948491__Web.png)

## Parameterization

The parameterization is done via the following encoder parameters:

![10483995](/tf50x0_tc3_nc_ptp/1033/Images/png/11503883275__Web.png)

**Invert Direction for Calibration Cam Search**

For the default homing sequence the direction for calibration cam search can be inverted.

* FALSE: cam is looked for in the direction of positive movement.
* TRUE: cam is looked for in the direction of negative movement.

**Invert Direction for Sync Impuls Search**

For the default homing sequence the direction for sync pulse search can be inverted.

* FALSE: sync pulse is looked for in the direction of positive movement.
* TRUE: sync pulse is looked for in the direction of negative movement.

**Home Position (Calibration Value)**

The Home Position is the position value that will be assigned to the axis when the sync pulse appears within the homing. This is done exactly with the sync pulse while in motion. Since the axis then stops, the standstill position deviates from the parameterized value. The referencing is nevertheless exact.

**Reference Mode (Sync condition)**

The parameter Reference Mode offers the opportunity to select which signal shall be used for sync impulse search:

* ‘Default’ / ‘Homing Sensor Only (PLC cam or digital input 1..8)’

+ The simplest way of referencing an axis where only the cam signal is evaluated. Another sync signal is not used, so this setting should only be selected if the axis does not offer more extensive options.

* ‘Hardware Sync (Feedback reference pulse)’

+ Some encoder systems provide a sync pulse per revolution (zero track) in addition to the count. The homing precision can be enhanced by selecting this mode, if the encoder evaluation logic is able to pick up the sync pulse. The precision is comparable with Software Sync. Hardware Sync mode may require parameterization or special wiring of the drive or encoder system.

* ‘Hardware Latch 1 (pos. edge)’, ‘Hardware Latch 1 (neg. edge)’

+ Hardware latch responds to an external latch signal in addition to the cam signal. For this purpose, the latch mechanism must be configured in the drive and the latch input must be wired.

* ‘Software Sync’

+ Software Sync mode enhances the homing precision by additionally detecting the encoder count overflow after an encoder or motor revolution, after the reference cam signal has been detected. This mode requires a part-absolute encoder (e.g. resolver) with constant overflow interval relative to the reference cam. Overflow detection is parameterized via the Reference Mask parameter.

* ‘Application (PLC code)’

+ In this case, the entire homing procedure must be programmed in the PLC:  
  In this case, the NC sets bit 23 in the "NcApplicationRequest" status, which is polled by the PLC. Via MC\_ReadApplicationRequest the request of the NC can be determined in the PLC. So far only 0 = NONE and 1 = HOMING is supported (see 0x33 at ["Index offset" specification for axis parameter](ms-xhelp:///?Id=beckhoff-dfdb-47b4-8e03-eca6db1e801f)). In the case of homing, the PLC can perform the sequence itself by moving the axis.

**Homing Sensor Source**

* Default PLC Cam (MC\_Home)

+ By default the homing sensor signal comes from the PLC with the function block MC\_Home with the parameter bCalibrationCam, which is automatically linked to the PlcToNc.ControlWordD.7.

* Digital Input [1-8]

+ Alternatively, a digital input linked to the NC process can be used. For this purpose, a general Drive Status Byte with 8 digital inputs is defined in the process image (Drive->Inputs->nState8), which can serve as a signal source for the homing sensor. A digital input to be used must therefore be mapped manually to the desired position in this byte.
+ Note The digital inputs 1 and 2 may differ depending on the hardware used. For the MDP703/733 hardware (e.g. EL7031, EL7041, EL7201, EL7411) the direct digital inputs E1 and E2 of the terminal are used instead, which are located in the Drive.nState2 byte of the terminal at bit position 3 (E1) and 4 (E2). The lower two bits of Drive.nState8 are not assigned in this case.

## Further information

* [Homing on the AX5000](https://infosys.beckhoff.com/content/1033/ax5000_usermanual/html/ax5000_homing.htm?id=6722744867646859295)
* [MC\_Home in the Tc2\_MC2](ms-xhelp:///?Id=beckhoff-6ee1-4cfb-b8c8-8c450b3b93d9)
