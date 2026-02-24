# M-Bus

## Library
tcplclib_tc2_mbus

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_MBus](ms-xhelp:///?Id=beckhoff-18e3-4e49-a9fc-7977791d6960)
2. M-Bus

# M-Bus

![60792949](/tcplclib_tc2_mbus/1033/Images/gif/9007199429567243__en-US__Web.gif)

M-Bus = metering bus

The M-Bus is a fieldbus for the recording consumption data (e.g. energy meters). Further details about M-Bus can be found under [www.m-bus.com](http://www.m-bus.com). The M-Bus is European standard and is described in the EN1434 standard. The data are sent serially from a slave (measuring device) to a master (level converter with PC). Master and slave are connected via a two-wire cable that is protected against polarity reversal. With primary addressing up to 250 slaves can be connected in star, strand or tree topologies. Ring structures are not permitted. Devices from different manufacturers can be operated on the same bus.

The master controls the communication on the bus by requesting data from the slaves. The slaves can respond with a fixed or variable data structure. The M-Bus library only evaluates data with variable data structure (low byte first). The slaves do not communicate with each other. The data have to be requested sequentially from the slaves.

Further Information

* [Topology](ms-xhelp:///?Id=beckhoff-ba95-4cbd-af59-dd7f45bd8e01)
* [Bulletin](ms-xhelp:///?Id=beckhoff-867f-4d59-be31-26fe64fe0f45)

[TwinCAT 3 | PLC Library: Tc2\_MBus](ms-xhelp:///?Id=beckhoff-18e3-4e49-a9fc-7977791d6960)
