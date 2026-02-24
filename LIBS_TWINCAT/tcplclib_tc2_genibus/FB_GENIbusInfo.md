# FB_GENIbusInfo

## Library
tcplclib_tc2_genibus

## Category
Motion Control

# FB\_GENIbusInfo

![48475691](/tcplclib_tc2_genibus/1033/Images/gif/18014400583417483__en-US__Web.gif)

This function reads out the notification area of an ID.

## VAR\_INPUT

```
bStart            : BOOL;  
byAddr            : BYTE := 0;  
byClass           : BYTE := 2;  
byIDCode          : BYTE := 0;  
eCommandPriority  : E_GENIbusCommandPriority := eGENIbusCommandPriorityMiddle;
```

**bStart:** The reading process is initiated by a rising edge at this input.

**byAdress:** address of the GENIbus device to be addressed: valid entries: 1 - 200. This corresponds to the setting as is made directly on the GENIbus device. Conversion to the actual address range 32 - 231 takes place within the block (see GENIbus standard). A broadcast command via address 255 is naturally not permitted.

**byClass/byIDCode:**  Class and ID code of the memory location to be read. INFO commands are permissible only for classes 2, 3, 4 and 5 - an error is output for all other entries. Conversely, there is no restriction of the ID code entry, since these ranges are not without gaps and may possibly be extended.

**eCommandPriority:** priority (high, medium or low) with which the command is processed by the PLC library (see [E\_GENIbusCommandPriority](ms-xhelp:///?Id=beckhoff-fec5-40f5-b468-f6cc55cf7f3b)).

## VAR\_OUTPUT

```
bBusy         : BOOL;  
bError        : BOOL;  
udiErrorId    : UDINT;  
udiErrorArg   : UDINT;  
byInfoHead    : BYTE;  
byUnitIndex   : BYTE;  
byZeroH       : BYTE;  
byRangeZeroL  : BYTE;
```

**bBusy:** starting with the edge at *bStart*, this output remains TRUE until the command has been processed.

**bError:** This output is switched to TRUE as soon as an error occurs during the execution of a command. The command-specific error code is contained in *udiErrorId*.

**udiErrorId:** Contains the command-specific error code of the most recently executed command (see [error codes](ms-xhelp:///?Id=beckhoff-f282-4a41-a9c6-fb23ce5f066d)). It is set back to 0 by the reactivation of the function block via the *bStart* input.

**udiErrorArg:** if applicable, contains an extended description of the error code.

**byInfoHead:** scaling information

**byUnitIndex:** sign and unit – coded.

**byZeroH:** zero point in the case of normal range zero-point scaling OR high-byte zero point in the case of extended scaling.

**byRangeZeroL:**  range in the case of normal range zero-point scaling OR low-byte zero point in the case of extended scaling.

## VAR\_IN\_OUT

```
stCommandBuffer   : ST_GENIbusCommandBuffer;
```

**stCommandBuffer:** reference to the structure for communication (buffer) with the [FB\_GENIbusCommunication()](ms-xhelp:///?Id=beckhoff-281b-4657-b62b-91dbb972677a) function block (see [ST\_GENIbusCommandBuffer](ms-xhelp:///?Id=beckhoff-6978-4399-b7ee-a1d3e3b97d03)).

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_GENIbus from v3.3.0.0 |
