# FB_GENIbusMagnaPump

## Library
tcplclib_tc2_genibus

## Category
Motion Control

# FB\_GENIbusMagnaPump

![39516413](/tcplclib_tc2_genibus/1033/Images/gif/18014400583441291__en-US__Web.gif)

This function block represents a universal application for a Grundfos Magna pump. The fundamental operating modes can be set and important parameters read out.

|  |  |
| --- | --- |
| 20103398 | The values shown in bold lettering inside square brackets represent the class and ID with which the commands are executed or the information acquired. These values are listed in the Grundfos documentation "Operating the MAGNA3 and MGE model H/I via the GENIpro interface - Edition 01.00.35 - April 2015". |

## VAR\_INPUT

```
bEnable                : BOOL;  
byAddr                 : BYTE;  
tInfoCycle             : TIME;  
lrSetpoint             : LREAL;  
bSetSetpoint           : BOOL;  
eSetOpMode             : E_GENIbusOpMode := eGENIbusOpModeStop;  
bSetOpMode             : BOOL;  
eSetCtrlMode           : E_GENIbusCtrlMode := eGENIbusCtrlModeConstFreq;  
bSetCtrlMode           : BOOL;  
eSetNightReductionMode : E_GENIbusNightReductionMode := eGENIbusNightReductionModeOff;  
bSetNightReductionMode : BOOL;  
eSetKeyMode            : E_GENIbusKeyMode := eGENIbusKeyModeUnlocked;  
bSetKeyMode            : BOOL;  
bResetAlarm            : BOOL;  
bResetCounters         : BOOL;  
eCommandPriority       : E_GENIbusCommandPriority := eGENIbusCommandPriorityMiddle;
```

**bEnable:** the function block is activated by setting this input.

**byAdress:** address of the GENIbus device to be addressed: valid entries: 1 - 200. This corresponds to the setting as is made directly on the GENIbus device. Conversion to the actual address range 32 – 231 (see GENIbus standard), takes place internally in the function block.

A broadcast or collective command to several pumps is also possible. The value at this input must then be 255. The value queries are deactivated in the case of the broadcast command.

**tInfoCycle:** specifies the interval at which the value-query commands are to be output. This entry is limited to a minimum of 1 s. Conversely, the entry "0s" is permitted and means that no query takes place.

**lrSetpoint:** setpoint entry **[5, 1]**. The entry is in percent and refers to the specified limits, depending on the method of control. A more precise description is given in the respective documentation from the Grundfos company.

**bSetSetpoint:** a rising edge at this input transmits the set setpoint.

**eSetOpMode:** this input is used to set one of the following operating modes (see [E\_GENIbusOpMode](ms-xhelp:///?Id=beckhoff-4e63-490c-a6b2-57afc8ce52f4)):

* Stop **[3, 5]**
* Start **[3, 6]**
* Minimum curve **[3, 25]**
* Maximum curve **[3, 26]**

**bSetOpMode:** a rising edge at this input transmits the set operating mode.

**eSetCtrlMode:** this input is used to set one of the following control modes (see [E\_GENIbusCtrlMode](ms-xhelp:///?Id=beckhoff-685b-49cb-8c5b-328a51ebdc79)):

* Constant frequency **[3, 22]**
* Proportional pressure **[3, 23]**
* Constant pressure **[3, 24]**
* Auto-adapting **[3, 52]**

**bSetCtrlMode:** a rising edge at this input transmits the set control mode.

**eSetNightReductionMode:** this input is used to select or deselect the night setback mode (see [E\_GENIbusNightReductionMode](ms-xhelp:///?Id=beckhoff-1dc5-4d86-bf5a-0e057fbb8ca7)). **[4, 170]**

**bSetNightReductionMode:** a rising edge at this input transmits the set selection.

**eSetKeyMode:** locking of the manual operation on the pump can be selected with the aid of this input (see [E\_GENIbusKeyMode](ms-xhelp:///?Id=beckhoff-9089-4c20-abb4-abde30ffb4ab)). The lock only blocks the parameterization menu, not the keys themselves. **[3, 30/31]**

**bSetKeyMode:** a rising edge at this input transmits the set selection.

**bResetAlarm:**  a rising edge at this input resets the currently pending alarm on the device. **[3, 2]**

**bResetCounters:**  a rising edge at this input resets counters, such as operating hours or energy. **[3, 36]**

**eCommandPriority:** priority (high, medium or low) with which the command is processed by the PLC library (see [E\_GENIbusCommandPriority](ms-xhelp:///?Id=beckhoff-fec5-40f5-b468-f6cc55cf7f3b)).

## VAR\_OUTPUT

```
bBusy                  : BOOL;  
bError                 : BOOL;  
udiErrorId             : UDINT;  
udiErrorArg            : UDINT;  
eActualOpMode          : E_GENIbusActOpMode;  
eActualCtrlMode        : E_GENIbusActCtrlMode;  
bNightReduction        : BOOL;  
bWarning               : BOOL;  
byWarnCode             : BYTE;  
bAlarm                 : BOOL;  
byAlarmCode            : BYTE;  
bKeysLocked            : BOOL;  
stActualSetpoint       : ST_GENIbusMValue;  
stNormalizedSetpoint   : ST_GENIbusMValue;  
stPumpFlow             : ST_GENIbusMValue;  
stPowerConsumption     : ST_GENIbusMValue;  
stRotationalSpeed      : ST_GENIbusMValue;  
stPumpHead             : ST_GENIbusMValue;  
stEngeryConsumption    : ST_GENIbusMValue;  
stOperatingHours       : ST_GENIbusMValue;  
stMediumTemperature    : ST_GENIbusMValue;
```

**bBusy:** this output is always TRUE when a command or query is being processed.

**bError:** This output is switched to TRUE as soon as an error occurs during the execution of a command. The command-specific error code is contained in *udiErrorId*.

**udiErrorId:** Contains the command-specific error code of the most recently executed command (see [error codes](ms-xhelp:///?Id=beckhoff-f282-4a41-a9c6-fb23ce5f066d)). It is set back to 0 by the reactivation of the function block via the *bStart* input.

**udiErrorArg:**  if applicable, contains an extended description of the error code.

**eActualOpMode:** currently valid operating mode (see [E\_GENIbusActOpMode](ms-xhelp:///?Id=beckhoff-4317-4edd-9824-8dea75e7951e)). **[2, 81]**

**eActualCtrlMode:** currently valid control mode (see [E\_GENIbusActCtrlMode](ms-xhelp:///?Id=beckhoff-e8b1-4dbf-af7a-ef5b0db333ae)). **[2, 81]**

**bNightReduction:** night setback is selected. **[2, 84]**

**bWarning :** a warning message is pending.

**byWarnCode:** code of the current warning message. **[2, 156]**

**bAlarm:** an alarm is pending.

**byAlarmCode:** code of the current alarm. **[2, 158]**

**bKeysLocked:** locking of manual operation on the pump is activated. **[4, 170]**

**stActualSetpoint:** currently set setpoint; the unit displayed depends on the control mode (see [ST\_GENIbusMValue](ms-xhelp:///?Id=beckhoff-f468-4669-a02d-c3c56013973e)). **[2, 48]**

**stNormalizedSetpoint:** currently normalized setpoint (see [ST\_GENIbusMValue](ms-xhelp:///?Id=beckhoff-f468-4669-a02d-c3c56013973e)). **[2, 49]**

**stPumpFlow:** flow rate (see [ST\_GENIbusMValue](ms-xhelp:///?Id=beckhoff-f468-4669-a02d-c3c56013973e)). **[2, 39]**

**stPowerConsumption:** power consumption (see [ST\_GENIbusMValue](ms-xhelp:///?Id=beckhoff-f468-4669-a02d-c3c56013973e)). **[2, 34]**

**stRotationalSpeed:** speed (see [ST\_GENIbusMValue](ms-xhelp:///?Id=beckhoff-f468-4669-a02d-c3c56013973e)). **[2, 35/36]**

**stPumpHead:** pump head (see [ST\_GENIbusMValue](ms-xhelp:///?Id=beckhoff-f468-4669-a02d-c3c56013973e)). **[2, 37]**

**stEngeryConsumption:** energy consumption (see [ST\_GENIbusMValue](ms-xhelp:///?Id=beckhoff-f468-4669-a02d-c3c56013973e)). **[2, 152/153]**

**stOperatingHours:** operating hour counter (see [ST\_GENIbusMValue](ms-xhelp:///?Id=beckhoff-f468-4669-a02d-c3c56013973e)). **[2, 24/25]**

**stMediumTemperature:** water (medium) temperature (see [ST\_GENIbusMValue](ms-xhelp:///?Id=beckhoff-f468-4669-a02d-c3c56013973e)). **[2, 58]**

|  |  |
| --- | --- |
| 46712854 | since an error may not interrupt the execution of the function block, bError, udiErrorId and udiErrorArg are initially reset in every PLC cycle and then re-evaluated. for the determination of sporadically occurring errors, an error memory must therefore be programmed external to the function block. |

## VAR\_IN\_OUT

```
stCommandBuffer   : ST_GENIbusCommandBuffer;
```

**stCommandBuffer:** reference to the structure for communication (buffer) with the [FB\_GENIbusCommunication()](ms-xhelp:///?Id=beckhoff-281b-4657-b62b-91dbb972677a) function block (see [ST\_GENIbusCommandBuffer](ms-xhelp:///?Id=beckhoff-6978-4399-b7ee-a1d3e3b97d03)).

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_GENIbus from v3.3.0.0 |
