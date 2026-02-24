# Settings when using the on-board RS485 interface

## Library
tcplclib_tc2_genibus

## Category
Motion Control

# Settings when using the on-board RS485 interface

If an on-board interface is selected, it must first be correctly set in the TwinCAT System Manager, not least in order to obtain the correct process image. Unlike the terminal-based serial interfaces, the communication parameters are also set in the TwinCAT System Manager. Precisely the following settings are to be made on the “Communication Properties” tab of the COM port:

![52104579](/tcplclib_tc2_genibus/1033/Images/jpg/2073633931__en-US__Web.jpg)

The activation of the “Sync Mode” is particularly important. This ensures that the interface, which a KL6xx1 only emulates, also works correctly under higher PLC loads.

The linking of the process image to the PLC input and output variables can be accomplished most simply from the hardware side, since multi-links are possible from there. The variables must be visible in the right-hand side of the TwinCAT System Manager for this.

![66288034](/tcplclib_tc2_genibus/1033/Images/jpg/2073641867__en-US__Web.jpg)

First of all, just the status is linked with the status variable of the communication input. Note that when doing so the structure for PC communication must be selected.

![59721402](/tcplclib_tc2_genibus/1033/Images/jpg/2073649803__en-US__Web.jpg)

![621706](/tcplclib_tc2_genibus/1033/Images/jpg/2073657739__en-US__Web.jpg)

After that the data bytes can be conveniently linked to the corresponding variables by multi-link. The selection of several variables can be achieved by clicking on “Data1” and pressing the ↓ key with the Shift key pressed.

![5595356](/tcplclib_tc2_genibus/1033/Images/jpg/2073665675__en-US__Web.jpg)

The output variables must be linked in the same way:

![50358210](/tcplclib_tc2_genibus/1033/Images/jpg/2073673611__en-US__Web.jpg)

![50570707](/tcplclib_tc2_genibus/1033/Images/jpg/2073681547__en-US__Web.jpg)

![52483186](/tcplclib_tc2_genibus/1033/Images/jpg/2073689483__en-US__Web.jpg)

![2586631](/tcplclib_tc2_genibus/1033/Images/jpg/2073697419__en-US__Web.jpg)

![23279683](/tcplclib_tc2_genibus/1033/Images/jpg/2073705355__en-US__Web.jpg)
