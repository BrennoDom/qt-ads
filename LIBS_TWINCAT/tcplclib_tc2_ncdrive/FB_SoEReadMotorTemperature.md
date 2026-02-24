# FB_SoEReadMotorTemperature

## Library
tcplclib_tc2_ncdrive

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_NcDrive](ms-xhelp:///?Id=beckhoff-4c50-4727-bae6-a5b8e82c9354)
2. [Function blocks](ms-xhelp:///?Id=beckhoff-725e-4601-b0fd-30492204b699)
3. [General SoE](ms-xhelp:///?Id=beckhoff-6800-459e-a087-89077ab014ae)
4. [Function blocks for determining current values](ms-xhelp:///?Id=beckhoff-ae69-46e8-9eb6-77b109d205a7)
5. FB\_SoEReadMotorTemperature

# FB\_SoEReadMotorTemperature

![31956933](/tcplclib_tc2_ncdrive/1033/Images/gif/2302123915__Web.gif)

With the function block FB\_SoEReadMotorTemperature the temperature of the motor (S-0-0383) can be read. If the motor does not contain a temperature sensor, this is 0.0, i.e. 0.0 °C.

## VAR\_INPUT

```
VAR_INPUT  
    sNetId   : T_AmsNetId := '';  
    bExecute : BOOL;  
    tTimeout : TIME := DEFAULT_ADS_TIMEOUT;  
END_VAR
```

**sNetId**: String containing the AMS network ID of the PC. (Type: T\_AmsNetId)

**bExecute**: The function block is enabled via a positive flank at this input.

**tTimeout**: Maximum time allowed for the execution of the function block.

## VAR\_IN\_OUT

```
VAR_IN_OUT  
    Axis : NCTOPLC_AXIS_REF;(* reference to NC axis *)  
END_VAR
```

**Axis**: Axis data structure of the type NCTOPLC\_AXIS\_REF

## VAR\_OUTPUT

```
VAR_OUTPUT  
    bBusy             : BOOL;  
    bError            : BOOL;  
    iAdsErrId         : UINT;  
    iSercosErrId      : UINT;  
    fMotorTemperature : REAL;  
    dwAttribute       : DWORD;  
END_VAR
```

**bBusy**: This output is set when the function block is activated, and remains set until a feedback is received.

**bError**: This output is set after the bBusy output has been reset when an error occurs in the transmission of the command.

**iAdsErrId**: In the case of a set bError output returns the ADS error code of the last executed command.

**iSercosErrId**: In the case of a set bError output returns the Sercos error of the last executed command.

**dwAttribute**: Returns the attributes of the Sercos parameter.

**fMotorTemperature**: Returns the motor temperature (e.g. 30.5 corresponds to 30.5 °C). If the motor does not contain a temperature sensor, this is 0.0, i.e. 0.0 °C.

## Sample

```
fbReadMotorTemp : FB_SoEReadMotorTemperature;  
bReadMotorTemp : BOOL;  
fMotorTemperature : REAL;  
(* NcAxis *)  
stNcToPlc AT %I* : NCTOPLC_AXLESTRUCT;  
  
IF bReadMotorTemp AND NOT bInit THEN  
 fbReadMotorTemp(  
    Axis := stNcToPlc,  
    bExecute := TRUE,  
    tTimeout := DEFAULT_ADS_TIMEOUT,  
    fMotorTemperature=>fMotorTemperature  
 );  
 IF NOT fbReadMotorTemp.bBusy THEN  
    fbReadMotorTemp(Axis := stNcToPlc, bExecute := FALSE);  
    bReadMotorTemp := FALSE;  
 END_IF  
END_IF
```

[TwinCAT 3 | PLC Library: Tc2\_NcDrive](ms-xhelp:///?Id=beckhoff-4c50-4727-bae6-a5b8e82c9354)
