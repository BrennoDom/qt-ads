# Requirements

## Library
tcplclib_tc3_mc2_advancedhoming

## Category
Motion Control

# Requirements

In order to use referencing sequences that limit the torque or use the current torque as detection variable, it is necessary to ensure that the current torque is present and linked in the process image of the drive controller. In addition, in the dialog of the Nc drive on the parameter page under **Torque and Acceleration Scaling,** the **Input Scaling Factor (Actual Torque)** must be > = 0.0 and set to the correct value (0.1 scales the value for the AX5000 in %):

![5938035](/tcplclib_tc3_mc2_advancedhoming/1033/Images/png/9007202232409099__Web.png)
