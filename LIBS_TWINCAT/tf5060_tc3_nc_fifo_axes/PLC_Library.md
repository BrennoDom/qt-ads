# PLC Library

## Library
tf5060_tc3_nc_fifo_axes

## Category
Motion Control

1. [TF5060 TC3 NC FIFO Axes](ms-xhelp:///?Id=beckhoff-8924-4fac-a694-64ecc6ef4125)
2. PLC Library

# PLC Library

The library **Tc2\_NcFifoAxes** allows to transfer externally generated position setpoint values to an axis group during runtime. In this process the setpoint value generation is designed in such a way that as well the setpoint position as the setpoint velocity are determined as the FIFO inputs are worked through in sequence. Between two neighboring FIFO inputs will be interpolated if necessary.

Further Information

* [FiFoGetDimension](ms-xhelp:///?Id=beckhoff-b167-4a55-824a-3445d65352b3)
* [FiFoGroupIntegrate](ms-xhelp:///?Id=beckhoff-8ad8-40cb-ae69-cee0b7a2e1c7)
* [FiFoGroupDisintegrate](ms-xhelp:///?Id=beckhoff-9c58-458c-9225-deb3b31bf3dd)
* [FiFoWrite](ms-xhelp:///?Id=beckhoff-32e5-4669-abc8-48475f5d7b88)
* [FiFoOverwrite](ms-xhelp:///?Id=beckhoff-5746-4f5d-9292-7c010c63f9fe)
* [FiFoStart](ms-xhelp:///?Id=beckhoff-e660-478a-a13f-9fd2c30eeba4)
* [FiFoStop](ms-xhelp:///?Id=beckhoff-f310-4f2a-a5ac-d33e6985088d)
* [FiFoSetChannelOverride](ms-xhelp:///?Id=beckhoff-c2fa-443e-90f7-d8e09c795e97)

[TF5060 | TwinCAT 3 NC FIFO AXES](ms-xhelp:///?Id=beckhoff-8924-4fac-a694-64ecc6ef4125)
