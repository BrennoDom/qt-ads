# Button “Link To PLC…”

## Library
tf50x0_tc3_nc_ptp

## Category
Motion Control

# Button “Link To PLC…”

## Connecting a PLC project

There is cyclic communication from the NC to the PLC and vice versa. NC axes must be linked with the PLC in order to set up this communication.

## Opening the dialog Select Axis PLC Reference…

![44392488](/tf50x0_tc3_nc_ptp/1033/Images/png/2852132875__Web.png)

:   An axis variable of the type `AXIS_REF` has been created in a PLC project.
:   The PLC project with the axis variables of the type `AXIS_REF` has been successfully created.  
    Only axis variables whose PLC project has been successfully created after their declaration are displayed in the dialog **Select Axis PLC Reference…**.
:   The text box to the right of the **Link To PLC…** button [3] shows the axis variables of the type `AXIS_REF` with which the axis selected in the NC configuration is linked.
:   If you wish to change this link, create a link or cancel a link:

:   1. Open the **Settings** dialog for the axis inside the NC configuration that you wish to link with an axis variable of the type `AXIS_REF` or whose link you wish to cancel.
:   2. Actuate the **Link To PLC…** button [3].

:   The dialog **Select Axis PLC Reference…** opens.

## Selecting an axis variable

![63988077](/tf50x0_tc3_nc_ptp/1033/Images/png/2852139275__Web.png)

:   1. Use the **Unused** option box [1] to display all unlinked axis variables of the type `AXIS_REF` in the list box.
:   2. Use the **All** option box [2] to display all axis variables of the type `AXIS_REF` in the list box. In this way it is possible to change existing configurations.
:   3. In the list box, select the axis variable [3] of the type `AXIS_REF` with which you wish to link the axis selected in the NC configuration.
:   4. Select the entry **(none)** [4] if you do not wish to link any axis variable or if you wish to cancel an existing link to an axis variable.
:   5. Confirm your selection with the **OK** button [5].

:   The axis selected in the NC configuration is linked according to your choice.
