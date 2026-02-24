# Overview

## Library
tf5050_tc3_nc_camming

## Category
Motion Control

1. [TF5050 TC3 NC Camming](ms-xhelp:///?Id=beckhoff-984d-4c21-9ee9-97aff9b63946)
2. Overview

# Overview

In many applications it is necessary to synchronize two or more axes. Axes can be coupled together in the TwinCAT NC PTP. A master axis is then actively controlled, and the position of one or more coupled slave axes is synchronously controlled by the NC.

The simplest type of coupling is linear coupling with a fixed ratio of transmission (electronic gearing).

Some applications require a more complex coupling of master and slave, one which cannot be described by a simple mathematical formula. Such a dependency can be described by means of a table that specifies an associated slave position for every master position.

The TwinCAT NC PTP offers the possibility of coupling a slave axis to a master axis by means of a table (electronic cam plate) Here the table contains a certain number of prescribed interpolation points, and the NC interpolates position and speed between them.

The Tc2\_MC2\_Camming library contains function blocks for handling cam plates. Two types of cam plates are supported.

One option is a cam plate in the form of a 2-column table containing master and slave positions (position table). The master column defines interpolation points via the travel path of the master, ascending from a minimum position value to a maximum value. The associated slave position is determined from the second column using the interpolation points of the table. Values between these interpolation points are interpolated.

Another option is to define a cam plate as a so-called motion function. A motion function is a single-column table of interpolation points. Each interpolation point not only contains a position, but a complete description of the course of the curve within a section (segment) of the cam plate. In addition to the master and slave position at the start of the segment, the course of the function for example is specified up to the next interpolation point in the form of a mathematical function. Using this procedure, a motion function requires only very few interpolation points. Despite this, each point between the interpolation points is precisely defined through the mathematical function, and there are no uncertainties due to interpolation.

Unlike a position table, the points of a motion function can be manipulated at run time. The system ensures that a manipulation only becomes effective once an alteration has no direct influence on the slave. Position jumps are thus avoided.

[TF5050 | TwinCAT 3 NC Camming](ms-xhelp:///?Id=beckhoff-984d-4c21-9ee9-97aff9b63946)
