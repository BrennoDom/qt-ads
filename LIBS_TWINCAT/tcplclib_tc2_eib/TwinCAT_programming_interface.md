# TwinCAT programming interface

## Library
tcplclib_tc2_eib

## Category
Motion Control

# TwinCAT programming interface

The TwinCAT libraries for the KL6301 make function blocks available that enable data exchange between the applications program running on the higher-level control system and the EIB devices connected to the KL6301. This function blocks is available as a basic version and a professional version.

## Basic interface

The basic interface consists of a collection of function blocks that significantly reduce the programming and data type conversion effort. A send and receive block is available for each popular data type. The send blocks have a very simple structure. They only transfer data in the event of a change. Further information can be found in the descriptions of the individual [Basic-Blocks](ms-xhelp:///?Id=beckhoff-3fc6-4088-a50c-8f2c04ec5bcb).

## Professional interface

The professional interface consists of a single function block offering a wide range of parameters and complete freedom for sending or receiving data.

The professional block may not be used at the same time as basic interface blocks on a KL6301! If several KL6301 are used, one KL6301 can be used with the basic interface operate and another with the professional interface.
