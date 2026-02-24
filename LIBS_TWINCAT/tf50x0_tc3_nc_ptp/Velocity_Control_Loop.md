# Velocity Control Loop

## Library
tf50x0_tc3_nc_ptp

## Category
Motion Control

# Velocity Control Loop

Habitually, velocity control is performed within the drive controller by the velocity controller unit. This velocity controller is depicted within the controller overview of the Drive Manager. When velocity control is brought into the TwinCAT runtime this software velocity control unit has to be configured. The velocity control loop parameters configure the software velocity control within the TwinCAT runtime.

![48259009](/tf50x0_tc3_nc_ptp/1033/Images/png/3480603787__Web.png)![31677898](/tf50x0_tc3_nc_ptp/1033/Images/png/3480606987__Web.png)![16665627](/tf50x0_tc3_nc_ptp/1033/Images/png/3480613387__Web.png)

## Velocity control: Proportional Factor Kv

The Proportional Factor Kv is the gain factor of the P-controller.

![15772917](/tf50x0_tc3_nc_ptp/1033/Images/png/3480603787__Web.png)![7738529](/tf50x0_tc3_nc_ptp/1033/Images/png/3480606987__Web.png)![2537905](/tf50x0_tc3_nc_ptp/1033/Images/png/3480610187__Web.png)

## Velocity control: Integral Action Time Tn

Integral Action Time `Tn` of the I component of the PID-controller. Integration time.

## Velocity control: Derivative Action Time Tv

Rate time `Tv` of the real D component (D-T1 component) of the PID-controller.

## Velocity control: Damping Time Td

Damping time `Td` of the real D component (D-T1 component) of the PID-controller.

![22841149](/tf50x0_tc3_nc_ptp/1033/Images/png/3480603787__Web.png)![4243749](/tf50x0_tc3_nc_ptp/1033/Images/png/3480606987__Web.png)![38193748](/tf50x0_tc3_nc_ptp/1033/Images/png/3480706187__Web.png)

## Velocity control: Min./max. limitation D-Part [0.0 … 1.0]

D-part limitation of the PID-controller.

## Velocity control: Min./max. limitation I-Part [0.0 … 1.0]

I-part limitation of the PID-controller.
