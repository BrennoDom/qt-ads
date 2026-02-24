# KL6821 with PC system (CX5120)

## Library
tcplclib_tc2_dali

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_DALI](ms-xhelp:///?Id=beckhoff-bad6-4627-b8ac-544f0eee130c)
2. [Programming](ms-xhelp:///?Id=beckhoff-1e7b-43d6-a8da-8e0049d24778)
3. [Integration into TwinCAT](ms-xhelp:///?Id=beckhoff-d9d1-4c38-a7bd-9376458d8be1)
4. KL6821 with PC system (CX5120)

# KL6821 with PC system (CX5120)

This sample explains how to write a simple PLC program for DALI in TwinCAT and how to link it with the hardware. The task is to control an individual dimmable lamp via a button.

**Sample:** [DALI\_Sample\_KL6821\_CX5120.zip](https://infosys.beckhoff.com/content/1033/tcplclib_tc2_dali/Resources/zip/4325884043.zip)

## Hardware

## Setting up the components

* 1x Embedded PC CX5120
* 1x digital 4-channel input terminal KL1104 (for the dimming and reset functions)
* 1x DALI terminal KL6821
* 1x KL9010 end terminal

Set up the hardware and the DALI components as described in the documentation.

This example assumes that a Dim button was connected to the first KL1104 input and a Reset button to the second, and that a dimmable lamp is connected to DALI address 0. Set the initial fade rate of the control gear to 7 to achieve suitable dimming.

## Software

## Creation of the PLC program

Create a new "TwinCAT XAE project" and a "Standard PLC project".

Add the library Tc2\_DALI in the PLC project under "References".

Create the following global variables:

```
VAR_GLOBAL  
   bSwitch         AT %I* : BOOL;  
   bReset          AT %I* : BOOL;  
   stKL6821InData  AT %I* : ST_KL6821InData;  
   stKL6821OutData AT %Q* : ST_KL6821OutData;  
   stCommandBuffer        : ST_DALIV2CommandBuffer;  
END_VAR
```

**bSwitch:** Input variable for the Dim button.

**bReset:** Input variable for the Reset button.

**ST\_KL6821InData:** Input variable for the DALI terminal. ([ST\_KL6821InData](ms-xhelp:///?Id=beckhoff-8da7-4e31-9fea-d54b237fb0b5))

**ST\_KL6821OutData:** Output variable for the DALI terminal. ([ST\_KL6821OutData](ms-xhelp:///?Id=beckhoff-d89c-4382-a29d-9f9fbe33ebc8))

**stCommandBuffer:** Required for the communication with DALI.

Create a program (CFC) for the background communication with DALI. The function block [FB\_KL6821Communication()](ms-xhelp:///?Id=beckhoff-24f5-4307-8c46-040081763250) is called in the program. In the communication function block ensure that the structures *stInData*, *stOutData* and
*stCommandBuffer* are linked.

![6250253](/tcplclib_tc2_dali/1033/Images/jpg/4547003915__Web.jpg)

Create a MAIN program (CFC) in which the function block [FB\_DALIV2Dimmer1Switch()](ms-xhelp:///?Id=beckhoff-9d5c-44a9-af7d-8d2c52724170) is called up. Connect the input *bSwitchDimm* of the dimmer function block with the global variable *bSwitch* and *stCommandBuffer*
with the global variable *stCommandBuffer*.

![56252285](/tcplclib_tc2_dali/1033/Images/jpg/4325802763__Web.jpg)

|  |  |
| --- | --- |
| 36508524 | Parameters nMinLevelMasterDevice and nMaxLevelMasterDevice  Make sure that the specified parameters *nMinLevelMasterDevice* and *nMaxLevelMasterDevice* match the minimum and maximum values of the device, in order to avoid malfunction. |

Navigate to the task configuration section and configure the PlcTask*.* By way of example, the task is assigned priority 16 and a cycle time of 6 ms.

![60141268](/tcplclib_tc2_dali/1033/Images/jpg/4325770891__en-US__Web.jpg)

Create a further task for the background communication. Assign a higher priority (smaller number) and a lower interval time to this task than the PLCTask.

![4400500](/tcplclib_tc2_dali/1033/Images/jpg/4325767691__en-US__Web.jpg)

Add the program for the communication to this task. Further information on task configuration can be found in the description of the function block [FB\_KL6821Communication()](ms-xhelp:///?Id=beckhoff-24f5-4307-8c46-040081763250).

![39604502](/tcplclib_tc2_dali/1033/Images/jpg/4325069323__en-US__Web.jpg)

## I/O configuration

Select the CX as target system and initiate a search for its hardware. In the project instance within the PLC section, you can see that the input and output variables are assigned to the corresponding tasks.

![20896204](/tcplclib_tc2_dali/1033/Images/jpg/4325764491__en-US__Web.jpg)

Now link the global variables of PLC program with the inputs and outputs of the Bus Terminals. Create the Solution and enable the configuration.

The lamp can now be controlled by pressing or holding the dimmer button. You can use the Reset button to reset the inputs in *arrBufferMaximumDemandMeter* and *arrBufferOverflowCounter.*

[TwinCAT 3 | PLC Library: Tc2\_DALI](ms-xhelp:///?Id=beckhoff-bad6-4627-b8ac-544f0eee130c)
