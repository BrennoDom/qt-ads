# Linking the communication variables when using a KL6041

## Library
tcplclib_tc2_genibus

## Category
Motion Control

# Linking the communication variables when using a KL6041

The requirement for the linking of the process image is that the terminal is preset to 22 bytes in advance. In contrast to the PC interface, this cannot be configured in the I/O section, but only via the KS2000 software. The communication parameters

* Baud Rate: 9600 bits/s
* Data bits: 8
* Parity: None
* Stop bits: 1

are automatically set by the PLC application, so that following the exchange of a terminal and a subsequent restart, this terminal is correctly set.

The linking of the process image to the PLC input and output variables can be accomplished most simply from the hardware side, since multi-links are possible from there. To this end, the variables must show up in the I/O section on the right:

![52539597](/tcplclib_tc2_genibus/1033/Images/gif/6181141003__Web.gif)

First of all, just the status is linked with the status variable of the communication input. Note that when doing so the structure for KL communication must be selected.

![3094327](/tcplclib_tc2_genibus/1033/Images/gif/6181143947__Web.gif)![27848947](/tcplclib_tc2_genibus/1033/Images/gif/6187214091__Web.gif)

After that the data bytes can be conveniently linked to the corresponding variables by multi-link. The selection of several variables can be achieved by clicking on “Data1” and pressing the ↓ key with the Shift key pressed.

![49313939](/tcplclib_tc2_genibus/1033/Images/gif/6187217035__Web.gif)![41172271](/tcplclib_tc2_genibus/1033/Images/gif/6187219979__Web.gif)

The output variables must be linked in the same way.
