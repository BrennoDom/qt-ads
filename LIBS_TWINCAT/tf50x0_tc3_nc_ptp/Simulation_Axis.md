# Simulation Axis

## Library
tf50x0_tc3_nc_ptp

## Category
Motion Control

# Simulation Axis

In the following section you will find out how to set up an NC axis as a simulation axis.

A simulation axis is not linked with drive hardware via the IO configuration.

## Axis type

**Settings** dialog:  
Settings for an NC simulation axis that is linked with the PLC axis variable `axis` in the program `MAIN`:

![6742880](/tf50x0_tc3_nc_ptp/1033/Images/png/2833863051__Web.png)

|  |  |
| --- | --- |
| [1] | Select this entry. |
| [2] | Remains empty. |

## Setting up a simulation axis

:   1. In the axis level, select the NC axis that you wish to set up as a simulation axis.
:   2. Open the **Settings** dialog for this NC axis.
:   3. In the drop-down box for the axis type, select the entry **Standard (Mapping via Encoder and Drive)** [1].
:   4. For a simulation axis the entry **Link To I/O…** [2] remains empty.

:   You have set up the NC axis as a simulation axis.

## Further information

* Creating a PLC axis variable: [Motion Control in the PLC project](ms-xhelp:///?Id=beckhoff-2801-4426-a075-32668a38e3a1)
* Adding an NC axis: [Inserting an NC configuration](ms-xhelp:///?Id=beckhoff-f1dd-4eb4-844b-96dbb3104c8a)
* Linking an NC axis with a PLC axis variable: ["Link To PLC…" button](ms-xhelp:///?Id=beckhoff-a196-4658-9313-444eac261e01)
