# Creating an application function block

## Library
tcplclib_tc3_dali

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc3\_DALI](ms-xhelp:///?Id=beckhoff-3b50-4f78-8721-86f9c15e9bec)
2. [Appendix](ms-xhelp:///?Id=beckhoff-799a-4543-a757-72ecd85fb150)
3. Creating an application function block

# Creating an application function block

The following section illustrates how to create an application function block based on the library Tc3\_DALI. The example describes a simple function block that controls control gears via short address, group address or broadcast.

The TwinCAT project with the example can be found [here](https://infosys.beckhoff.com/content/1033/tcplclib_tc3_dali/Resources/zip/18014408379327115.zip):

![66523006](/tcplclib_tc3_dali/1033/Images/gif/9869839883__Web.gif)

A positive edge at one of the three inputs sends the DALI command RECALL MAX LEVEL, RECALL MIN LEVEL or OFF.

## Parameterization of the DALI control gears

The function block can initialize the variables *maxLevel*, *minLevel* and *fadeTime* of DALI control gears. Corresponding properties are available for this purpose. Their values are written to the DALI control gears when a positive edge is detected at *bInitialize*. During this time the output *bInitialize* is TRUE.

## DALI short address for reference device (*nReferenceDeviceaddress*)

The parameter nReferenceDeviceAddress is used for reading the output value of a reference DALI control gear cyclically in the background (*tCycleActualLevel* > 0 s). The output value is available at the output *nActualLevel*.

No reference DALI control gear is required if a single DALI control gear is to be controlled with the function block (*eAddressType = E\_DALIAddressType.Short*). In this case, the output value of the individual control gear is determined via the individual address *nAddress*.

If a DALI group is addressed with the function block (*eAddressType = E\_DALIAddressType.Group*), *nReferenceDeviceAddress* must always contain the short address of a DALI control gear, which must be located in the addressed DALI group.

Even with a broadcast (*eAddressType = E\_DALIAddressType.Broadcast*), a DALI control gear with a corresponding short address must be located on the DALI line.

## Transfer of the reference to the communication block

The method *FB\_init* transfers the parameter *ipDALICommunication* of type *I\_DALICommunication* to the function block. The interface *I\_DALICommunication* is included in the Tc3\_DALI library and is implemented by all communication blocks (FB\_KL6811Communication and FB\_KL6821Communication). All DALI command function blocks (e.g. FB\_DALI102Off) communicate with the DALI communication block via this interface. In the method *FB\_init* the interface pointer *ipDALICommunication* is assigned to the variable *\_ipDALICommunication* of the function block.

To ensure that the reference can be changed at runtime, the interface pointer is also passed to the application function block via the property *ipDALICommunication*. Internally, the property is stored in the variable *\_ipDALICommunication*.

In the application function block it must be ensured that this interface pointer is passed on to all DALI command function blocks. The internal method *SetCommunication* is available for this purpose. In this method the interface pointer is passed to all DALI command function blocks in the function block. The property *ipDALICommunication* is used in the command function blocks for this purpose. This property is used to reassign the reference to the DALI communication block at runtime.

*SetCommunication* is called in the first PLC cycle, each time a positive edge is detected at one of the inputs *bInitialize*, *bRecallMaxLevel*, *bRecallMinLevel* or *bOff*, and when the current output value is to be read. This ensures that the interface pointer is only passed on if no DALI command function block is currently being executed.

## Checking the parameters

All parameters are checked by the internal method CheckParameters. In the event of an error the method returns the error Id, or 0 if there is no error. The Ids of the [runtime messages](ms-xhelp:///?Id=beckhoff-b989-448b-af68-d65e2e7a28f5) can be used here:

```
IF (THIS^.ipDALICommunication = 0) THEN  
  CheckParameters := TC_EVENTS.TcDALIEventClass.TheInterfaceToTheCommunicationBufferIsNotInitialized.nEventId;  
END_IF
```

If required, you can also use your own error Ids, starting at 1000:

```
IF (<check your parameter>) THEN  
  CheckParameters := 1000;  
END_IF
```

Similar to *SetCommunication*, *CheckParameters* is also called in the first PLC cycle. This call also occurs if a positive edge was detected at the inputs *bInitialize*, *bRecallMaxLevel*, *bRecallMinLevel* or *bOff*.

Alternatively, you could call the method every time the value of a parameter has changed.

## Structure of the function block

In the upper part of the function block the positive edges of the inputs *bInitialize*, *bRecallMaxLevel*, *bRecallMinLevel* or *bOff* are queried.

The middle part contains a step sequence in which the individual actions are carried out. If a positive edge is detected at one of the inputs, the corresponding step of the step sequence is triggered. The DALI command QUERY ACTUAL LEVEL is sent once the DALI commands RECALL MAX LEVEL (step 200) or RECALL MIN LEVEL (step 300) have been executed. This reads the new output value from the DALI reference device and outputs it at the output *nActualLevel*. The variables *maxLevel*, *minLevel* and *fadeTime* are written from step 10000.

In the lower part, the output value is read cyclically from the DALI reference device and output at the output *nActualLevel*.

## Comments

The step sequence can only be set to a new action if no action is currently being executed (*nStep* = 0).

The number of DALI commands should be minimized. For example, after the DALI commands RECALL MAX LEVEL or RECALL MIN LEVEL, the current output value is only read out if during the next 1000 ms the output value is not already read out by cyclic querying in the lower part of the function block:

```
IF (((tonCycleActualLevel.PT - tonCycleActualLevel.ET) > T#1S) OR (tCycleActualLevel = T#0S)) THEN  
  nStep := 9000;  
ELSE  
  bBusy := FALSE;  
  nStep := 0;  
END_IF
```

[TwinCAT 3 | PLC Library: Tc3\_DALI](ms-xhelp:///?Id=beckhoff-3b50-4f78-8721-86f9c15e9bec)
