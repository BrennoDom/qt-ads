# Inserting servo drives manually

## Library
tf50x0_tc3_nc_ptp

## Category
Motion Control

# Inserting servo drives manually

## Manually inserting servo drives into the IO configuration

As an alternative to an automatic scan, you can also manually insert a servo drive into an IO configuration.

## Add New Item…

![4493316](/tf50x0_tc3_nc_ptp/1033/Images/png/2834010251__Web.png)

:   At least one EtherCAT Master device is inserted in the IO tree under **Devices.**

:   1. In the IO tree, right-click the EtherCAT Master device to which you wish to add a drive.
:   A context menu opens.
:   2. Select the context menu entry **Add New Item…** [1].

:   The dialog **Insert EtherCAT Device** opens.

## Dialog: Insert EtherCAT Device

![40439847](/tf50x0_tc3_nc_ptp/1033/Images/png/2551615627__Web.png)

:   The dialog **Insert EtherCAT Device** is open.
:   The **Drives** entry is located under **Type** in the device tree.

:   1. If necessary, use the radio button under **Port** [1] to set the appropriate option for a port of the predecessor module to which the drive is to be appended.
:   2. Open the **Drives** subtree under **Type** in the device tree.
:   3. If necessary, if the servo drive you are looking for does not appear in the **Drives** subtree, check one or more of the checkboxes **Extended Information** [2], **Show Hidden Devices** [3] and **Show Sub Groups** [4].
:   4. In the open **Drives** subtree, select the drive [5] that you wish to insert.
:   5. If necessary, enter a name for the drive that you wish to insert into the IO configuration in the **Name** text box [7].
:   6. Actuate the **OK** button [6] to confirm your settings.

:   The axis you selected has been added to the IO configuration, if applicable under the name you entered.
:   The dialog **EtherCAT drive(s) added** opens (see section [Automatically reading a drive amplifier](ms-xhelp:///?Id=beckhoff-45ea-493f-bfa1-fe1ec35b8ad5)).
