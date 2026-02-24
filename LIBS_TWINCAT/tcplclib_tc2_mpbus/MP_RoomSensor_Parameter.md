# MP_RoomSensor_Parameter

## Library
tcplclib_tc2_mpbus

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_MPBus](ms-xhelp:///?Id=beckhoff-afbb-4e7a-a6f0-964a87283892)
2. [Programming](ms-xhelp:///?Id=beckhoff-177e-411b-bfa4-57549cd6742f)
3. [POUs](ms-xhelp:///?Id=beckhoff-d0d7-47c8-bb7c-a9b7cd043f93)
4. [Function blocks](ms-xhelp:///?Id=beckhoff-6545-479b-937c-f69f8d2863f3)
5. MP\_RoomSensor\_Parameter

# MP\_RoomSensor\_Parameter

![65119131](/tcplclib_tc2_mpbus/1033/Images/gif/8670713867__Web.gif)

This function block is used for the parameterization of room sensors.

*MP\_Address* is used to specify the MP-Bus device with which the function block is to communicate. *bRead* reads the parameters, *bWrite* writes them to the room sensor. *bBusy* indicates that the function block is active. *bError* is used to indicate an error in communication with the drive. The type of the error can be read with *iErrorID*.

## VAR\_INPUT

```
MP_Address                : USINT := 1;  
bWrite                    : BOOL;   
bRead                     : BOOL;   
strDataKL6771             : DataKL6771;  
bUnitSelTemp              : BOOL;   
iOffsetCo2_Write          : INT;   
rOffsetTemp_Write         : LREAL;   
rOffsetHumidity_Write     : LREAL;   
rOffsetDewPointTemp_Write : LREAL;
```

**MP\_Address:** MP-Bus address of the slave.

**bWrite:** A positive edge starts the function block and writes the parameter.

**bRead:** A positive edge starts the function block and reads the parameter.

**strDataKL6771:** The data structure with which the [KL6771()](ms-xhelp:///?Id=beckhoff-c937-4fb9-a52b-2fb5de852d97) function block must be linked (see [DataKL6771](ms-xhelp:///?Id=beckhoff-b149-499c-8025-802a734c96f2)).

**bUnitSelTemp:** FALSE = °C, TRUE = °F.

**iOffsetCo2\_Write:** OffsetCO2 [ppm] -500..500.

**rOffsetTemp\_Write:** OffsetTemp [UnitSel] -15..15 °C (-27..27 °F)

**rOffsetHumidity\_Write:** OffsetHumidity [%] -20..+20.

**rOffsetDewPointTemp\_Write:** OffsetDewPointTemp [UnitSel] -15..15 °C (-27..27 °F).

## VAR\_OUTPUT

```
bBusy               : BOOL;  
bError              : BOOL;  
iErrorId            : MP_ERROR;  
stUnit              : STRING;  
iOffsetCO2          : INT;  
rOffsetHumidity     : LREAL;  
rOffsetTemp         : LREAL;  
rOffsetDewPointTemp : LREAL;
```

**bBusy:** This bit is set for as long as the function block is active.

**bError:** This output goes TRUE as soon as an error occurs. This error is described via the *iErrorId* variable.

**iErrorId:** This output outputs an error code in the event of an error (see [MP\_ERROR](ms-xhelp:///?Id=beckhoff-1b03-4e19-bdad-077c71ea9445)). *bError* goes TRUE at the same time.

**stUnit:** C = °C or F = °F, ? = not read.

**iOffsetCO2:** OffsetCO2 [ppm].

**rOffsetHumidity:** OffsetHumidity [%] 0.01.

**rOffsetTemp:** OffsetTemp [°C or °F] 0.01.

**rOffsetDewPointTemp:** DewOffsetTemp [°C or °F] 0.01.

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4024.10 | Tc2\_MPBus from 3.4.12.0 |

[TwinCAT 3 | PLC Library: Tc3\_MPBus](ms-xhelp:///?Id=beckhoff-afbb-4e7a-a6f0-964a87283892)
