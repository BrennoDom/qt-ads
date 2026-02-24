# LON

## Library
tcplclib_tc2_lon

## Category
Motion Control

# LON

![32841145](/tcplclib_tc2_lon/1033/Images/gif/9007199405178763__Web.gif)

Each LON device provides network variables (SNVTs) for communication with other devices. The required variables are selected based on the device documentation or the Xif file (machine-readable representation of all used SNVTs) and entered in the KL6401 via the [KS2000](ms-xhelp:///?Id=beckhoff-e152-481f-b2af-e39de4dfc40b). The [KS2000](ms-xhelp:///?Id=beckhoff-e152-481f-b2af-e39de4dfc40b) can now be used to create another Xif file. Both Xif files are read and combined with a LON configuration tool (not provided by Beckhoff). For further information please refer to the respective tool.

For each SNVT entered in the KL6401, a suitable function block has to be programmed on the PLC side. These function blocks can then be used to access the SNVTs of the devices.

## How the KL6401 functions

## Sending

The KL6401 sends single SNVT variables. This means that an SNVT variable sent to the KL6401 is sent to the LON network individually. Only when this has successfully been sent can the next SNVT variable be transferred to the KL6401.

## Receiving

The KL6401 has 2 buffers, the telegram buffer and the index buffer.

The input variables of a LON telegram that has been received are placed in the telegram buffer. The index number of the incoming telegram is also entered into the index buffer.

The TwinCAT LON function block evaluates the index buffer, transfers input variables that have been received to the application program, and removes them from the index buffer. If the function block does not read the data out of the telegram buffer quickly enough, it can save up to 62 entries (i.e. the maximum number of SNVT variables).

If a telegram that has already been received (which the function block has not yet transferred to the application program, and which therefore still has an entry in the index buffer) is received from the KL6401 again, then a new entry is not made in the index buffer, but the input variables in the telegram buffer are updated.

Further Information

* [Supported SNVTs](ms-xhelp:///?Id=beckhoff-542c-402f-a271-94289b2267cc)
* [Configuration software KS2000](ms-xhelp:///?Id=beckhoff-e152-481f-b2af-e39de4dfc40b)
