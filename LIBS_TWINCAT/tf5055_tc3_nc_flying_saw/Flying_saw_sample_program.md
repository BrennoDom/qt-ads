# Flying saw sample program

## Library
tf5055_tc3_nc_flying_saw

## Category
Motion Control

1. [TF5055 TC3 NC Flying Saw](ms-xhelp:///?Id=beckhoff-70fc-458e-9475-9aee1787ddfa)
2. [Example program](ms-xhelp:///?Id=beckhoff-462d-4b57-9d24-59341141176a)
3. Flying saw sample program

# Flying saw sample program

The example program shows a typical cyclic flying saw sequence. The program manages three axes: master, slave and tool. The slave and tool axes are initially in their home position at 0. The master axis is started first. It can be regarded as a transport system that transports continuous material to a cutting unit. The material is to be cut at constant intervals. To this end the slave axis, i.e. the flying saw, is synchronised with the master axis and travels synchronous with the transport system. During this phase the tool axis is activated, which deals with the actual processing. The slave axis is then uncoupled and returns to its home position. During the return travel the next synchronisation process is started, with a point at a constant distance to the last machining position as target.

The example program requires the flying saw library and operates fully in simulation mode. Progress can be monitored in TwinCAT Scope View with the configuration provided.

Click here to save the example program:

[Sample Flying Saw.zip](https://infosys.beckhoff.com/content/1033/tf5055_tc3_nc_flying_saw/Resources/zip/2573794443.zip)

[TF5055 | TwinCAT 3 NC Flying Saw](ms-xhelp:///?Id=beckhoff-70fc-458e-9475-9aee1787ddfa)
