# Linking the communication variables when using a KL6021

## Library
tcplclib_tc2_genibus

## Category
Motion Control

# Linking the communication variables when using a KL6021

The requirement for the linking of the process image is that the terminal is preset to 5 bytes in advance. Unlike the PC interface, this cannot be configured in the TwinCAT System Manager, but only via the KS2000 software. The communication parameters

* Baud Rate: 9600 bits/s
* Data bits: 8
* Parity: None
* Stop bits: 1

are automatically set by the PLC application, so that following the exchange of a terminal and a subsequent restart, this terminal is correctly set.

The linking of the process image to the PLC input and output variables can be accomplished most simply from the hardware side, since multi-links are possible from there. The variables must be visible in the right-hand side of the TwinCAT System Manager for this.

![8190559](/tcplclib_tc2_genibus/1033/Images/jpg/2073713291__en-US__Web.jpg)

First of all, just the status is linked with the status variable of the communication input. Note that when doing so the structure for PC communication must be selected.

![6606172](/tcplclib_tc2_genibus/1033/Images/jpg/2073721227__en-US__Web.jpg)

![59455556](/tcplclib_tc2_genibus/1033/Images/jpg/2073729163__en-US__Web.jpg)

After that the data bytes can be conveniently linked to the corresponding variables by multi-link. The selection of several variables can be achieved by clicking on “Data1” and pressing the ↓ key with the Shift key pressed.

![65337958](/tcplclib_tc2_genibus/1033/Images/jpg/2073737099__en-US__Web.jpg)

The output variables must be linked in the same way:

![51170717](/tcplclib_tc2_genibus/1033/Images/jpg/2073745035__en-US__Web.jpg)

![57883273](/tcplclib_tc2_genibus/1033/Images/jpg/2073752971__en-US__Web.jpg)

![51187411](/tcplclib_tc2_genibus/1033/Images/jpg/2073760907__en-US__Web.jpg)

![58033516](/tcplclib_tc2_genibus/1033/Images/jpg/2073768843__en-US__Web.jpg)
