# Overview

## Library
tf5060_tc3_nc_fifo_axes

## Category
Motion Control

1. [TF5060 TC3 NC FIFO Axes](ms-xhelp:///?Id=beckhoff-8924-4fac-a694-64ecc6ef4125)
2. Overview

# Overview

## TF5060 TC3 NC FIFO Axes

In many applications it is necessary to synchronise two or more axes. Axes can be coupled together in the TwinCAT NC PTP. A master axis is then actively controlled, and the position of one or more coupled slave axes is synchronously controlled by the NC.

The simplest type of coupling is linear coupling with a fixed ratio of transmission (an electronic gearbox).

Some applications require a more complex coupling of master and slave, one which can not be described by a simple mathematical formula. Such a dependency can be described by means of a table that specifies an associated slave position for every master position.

The TwinCAT NC PTP offers the possibility of coupling a slave axis to a master axis by means of a table (electronic camshaft). Here the table contains a certain number of prescribed reference points, and the NC interpolates position and speed between them.

FIFO axes extend the table concept for any number of sequences that do not usually recur cyclically. In this case, rather than having one master-slave table prescribed in advance, the latest axis positions are constantly "topped up" by a PLC program. Because the FIFO axes are combined into a FIFO group, synchronised axis motions can be implemented.

[Details](https://infosys.beckhoff.com/content/1033/ts5060_tcnc_fifoaxes/3456499851.html?id=7956082397023612115).

[TF5060 | TwinCAT 3 NC FIFO AXES](ms-xhelp:///?Id=beckhoff-8924-4fac-a694-64ecc6ef4125)
