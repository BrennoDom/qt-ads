# FB_GENIbusSet

## Library
tcplclib_tc2_genibus

## Category
Motion Control

# FB\_GENIbusSet

![20299268](/tcplclib_tc2_genibus/1033/Images/gif/18014400583409547__en-US__Web.gif)

This function block writes a value in a GENIbus device or executes a command (Class-3 Ids).

## VAR\_INPUT

```
bStart           : BOOL;  
byAddr           : BYTE := 0;  
byClass          : BYTE := 2;  
byIDCode         : BYTE := 0;  
byValue          : BYTE;  
eCommandPriority : E_GENIbusCommandPriority := eGENIbusCommandPriorityMiddle;
```

**bStart:** A rising edge at this input starts the setting process.

**byAdress:** address of the GENIbus device to be addressed: valid entries: 1 - 200. This corresponds to the setting as is made directly on the GENIbus device. Conversion to the actual address range 32 - 231 takes place within the block (see GENIbus standard).

**byClass/byIDCode:** Class and ID code of the memory location to be written. SET commands are permissible only for classes 3, 4 and 5 – an error is output for all other entries. Conversely, there is no restriction of the ID code entry, since these ranges are not without gaps and may possibly be extended.

**byValue:** Value to be written. In the case of Class-3 IDs this entry is ignored.

**eCommandPriority:** priority (high, medium or low) with which the command is processed by the PLC library (see [E\_GENIbusCommandPriority](ms-xhelp:///?Id=beckhoff-fec5-40f5-b468-f6cc55cf7f3b)).

## VAR\_OUTPUT

```
bBusy             : BOOL;  
bError            : BOOL;  
udiErrorId        : UDINT;  
udiErrorArg       : UDINT;
```

**bBusy:** starting with the edge at *bStart*, this output remains TRUE until the command has been processed.

**bError:** this output is switched to TRUE as soon as an error occurs during the execution of a command. The command-specific error code is contained in *udiErrorId*.

**udiErrorId:** Contains the command-specific error code of the most recently executed command (see [error codes](ms-xhelp:///?Id=beckhoff-f282-4a41-a9c6-fb23ce5f066d)). It is set back to 0 by the reactivation of the function block via the *bStart* input.

**udiErrorArg:**  if applicable, contains an extended description of the error code.

## VAR\_IN\_OUT

```
stCommandBuffer   : ST_GENIbusCommandBuffer;
```

**stCommandBuffer:** reference to the structure for communication (buffer) with the [FB\_GENIbusCommunication()](ms-xhelp:///?Id=beckhoff-281b-4657-b62b-91dbb972677a) function block (see [ST\_GENIbusCommandBuffer](ms-xhelp:///?Id=beckhoff-6978-4399-b7ee-a1d3e3b97d03)).

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_GENIbus from v3.3.0.0 |
