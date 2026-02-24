# FB_GENIbusGetMValue

## Library
tcplclib_tc2_genibus

## Category
Motion Control

# FB\_GENIbusGetMValue

![33628036](/tcplclib_tc2_genibus/1033/Images/gif/18014400583425419__en-US__Web.gif)

This function block reads a measured value from a GENIbus device. The operation is thereby exclusively restricted to values of class 2. Only the ID code of the high byte and the length of the measured value need to be specified; the type of scaling and the unit of the measured value are determined by an internal INFO query. A structure at the *stMValue* output provides all important information about the value.

## VAR\_INPUT

```
bStart            : BOOL;  
byAddr            : BYTE := 0;  
byIDCode          : BYTE := 0;  
eDataSize         : E_GENIBusMDataSize;  
eCommandPriority  : E_GENIbusCommandPriority := eGENIbusCommandPriorityMiddle;
```

**bStart:** The reading process is initiated by a rising edge at this input.

**byAddr:** address of the GENIbus device to be addressed: valid entries: 1 - 200. This corresponds to the setting as is made directly on the GENIbus device. Conversion to the actual address range 32 - 231 takes place within the block (see GENIbus standard). A broadcast command via address 255 is naturally not permitted.

**byIDCode:** ID code of the value to be read. In the case of 16, 24 and 32-bit values, the ID of the high byte must be specified here and the following order is always assumed: ID = hi, ID+1 = lo1, ID+2 = lo2, ID+3 = lo3.

**eDataSize:** data size of the measured value: 8, 16, 24 or 32 bytes (see [E\_GENIBusMDataSize](ms-xhelp:///?Id=beckhoff-d457-41be-b760-9ce71d64a0c4)).

**eCommandPriority:** priority (high, medium or low) with which the command is processed by the PLC library (see [E\_GENIbusCommandPriority](ms-xhelp:///?Id=beckhoff-fec5-40f5-b468-f6cc55cf7f3b)).

Sample: Read-out of the total pumped volume of water. For this case is:

* byIdCode = 121
* eDataSize = eGENIbusMSize32Bit

![34216874](/tcplclib_tc2_genibus/1033/Images/jpg/2073951371__en-US__Web.jpg)

Source: Grundfos documentation "Operating the MAGNA3 and MGE model H/I via the GENIpro interface - Edition 01.00.35 - April 2015".

## VAR\_OUTPUT

```
bBusy         : BOOL;  
bError        : BOOL;  
udiErrorId    : UDINT;  
udiErrorArg   : UDINT;  
stMValue      : ST_GENIbusMValue;
```

**bBusy:** starting with the edge at *bStart*, this output remains TRUE until the command has been processed.

**bError:** This output is switched to TRUE as soon as an error occurs during the execution of a command. The command-specific error code is contained in *udiErrorId*.

**udiErrorId:** Contains the command-specific error code of the most recently executed command (see [error codes](ms-xhelp:///?Id=beckhoff-f282-4a41-a9c6-fb23ce5f066d)). It is set back to 0 by the reactivation of the function block via the *bStart* input.

**udiErrorArg:** if applicable, contains an extended description of the error code.

**stMValue:** output of the read value (see [ST\_GENIbusMValue](ms-xhelp:///?Id=beckhoff-f468-4669-a02d-c3c56013973e)).

## VAR\_IN\_OUT

```
stCommandBuffer   : ST_GENIbusCommandBuffer;
```

**stCommandBuffer:** reference to the structure for communication (buffer) with the [FB\_GENIbusCommunication()](ms-xhelp:///?Id=beckhoff-281b-4657-b62b-91dbb972677a) function block (see [ST\_GENIbusCommandBuffer](ms-xhelp:///?Id=beckhoff-6978-4399-b7ee-a1d3e3b97d03)).

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_GENIbus from v3.3.0.0 |
