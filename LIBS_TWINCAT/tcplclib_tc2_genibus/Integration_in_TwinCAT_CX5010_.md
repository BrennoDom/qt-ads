# Integration in TwinCAT (CX5010)

## Library
tcplclib_tc2_genibus

## Category
Motion Control

# Integration in TwinCAT (CX5010)

This program shows the use of the individual function blocks in 5 [examples](https://infosys.beckhoff.com/content/1033/tcplclib_tc2_genibus/Resources/zip/2073551243__en-US.zip) ![59907344](/tcplclib_tc2_genibus/1033/Images/gif/2073563019__en-US__Web.gif)

The communication runs via an EtherCAT Terminal.

## Hardware

## Setting up the components

The following hardware is required:

* 1x CX5010 Embedded PC
* 1x EL1408 eight-channel digital input terminal for the execution of the individual tests
* 1x EL6021 serial RS485 terminal

## Software

## PLC program

The respective test program section can be selected by setting the *iTest* variable in the MAIN program to values from 1 to 5.

![2295192](/tcplclib_tc2_genibus/1033/Images/jpg/2073570955__en-US__Web.jpg)

In the respective program sections, function blocks are then prepared that you can operate via the test inputs *ib1* to *ib8*:

```
VAR_GLOBAL  
   ib1     AT %I* : BOOL;  
   ib2     AT %I* : BOOL;  
   ib3     AT %I* : BOOL;  
   ib4     AT %I* : BOOL;  
   ib5     AT %I* : BOOL;  
   ib6     AT %I* : BOOL;  
   ib7     AT %I* : BOOL;  
   ib8     AT %I* : BOOL;  
  
   stInData    AT %I* : ST_GENIbusInData;  
   stOutData   AT %Q* : ST_GENIbusOutData;  
   stCommandBuffer    : ST_GENIbusCommandBuffer;  
END_VAR
```

**ib1..ib8:**  Pushbutton switch inputs for the tests.

**stInData:** [Structure](ms-xhelp:///?Id=beckhoff-ec87-4348-878f-1a7fa2e635be) with the input variables for various terminal types.

**stOutData:** [Structure](ms-xhelp:///?Id=beckhoff-9690-4e4a-bd84-1e36c04099db) with the output variables for various terminal types.

**stCommandBuffer:** Reference to the structure for communication (buffer) with the [FB\_GENIbusCommunication](ms-xhelp:///?Id=beckhoff-281b-4657-b62b-91dbb972677a)() function block.

## TwinCat System Manager

In the TwinCAT System Manager the variables are already linked and assigned to the two tasks (Background: fast for communication, Main: slower for application).

Compile the PLC program and read it into the TwinCAT System Manager:

![20656733](/tcplclib_tc2_genibus/1033/Images/jpg/2073578891__en-US__Web.jpg)

In accordance with these [instructions](ms-xhelp:///?Id=beckhoff-9b87-46a3-909b-b296979a3a72), check whether the variable assignment is correct and that the variables have been linked.

After that you can start the TwinCAT System Manager and load and start the PLC program.
