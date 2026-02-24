# Device addressing

## Library
tcplclib_tc2_genibus

## Category
Motion Control

# Device addressing

In principle, the GENIbus protocol knows only two types of addressing: Individual addressing and broadcast or group commands. The addresses are to be assigned as follows:

* 0 - 31 : master addresses, i.e. the TwinCAT controllers
* 32 - 231 : slave addresses, e.g. pumps
* 255 : broadcast addressing to all slaves

At function-block level in the library the address range of the slaves is set to 1 – 200, i.e. 31 fewer than in the serial network. The reason for this is that the Grundfos parameterization devices also operate with an address range of 1 - 200. 31 is internally added to the slave address again for the serial communication.
