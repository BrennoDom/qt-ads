# FB_BA_KL32xxConfig

## Library
tcplclib_tc3_ba_common

## Category
Motion Control

# FB\_BA\_KL32xxConfig

![66660559](/tcplclib_tc3_ba_common/1033/Images/gif/9007204250932875__Web.gif)

Configuration of the Bus Terminals for temperature measurement.

## Functional description

The function block is for the configuration of Bus Terminals of the types KL3208\_0010, KL3201, KL3202 and KL3204.

## VAR\_INPUT

```
TI_usiState   : USINT;  
TI_iDataIn    : INT;  
bConfigurate  : BOOL;  
bReadConfig   : BOOL;  
eTerminal     : E_BA_TERMINAL_KL;  
eSensor       : E_BA_SENSOR;
```

**TI\_usiState:** Linking with the corresponding status byte of the Bus Terminal in the I/O area of the program.

**TI\_iDataIn:** Linking with the corresponding raw data (Data In) of the Bus Terminal in the I/O area of the program (0 - 32767).

**bConfigurate:** A rising edge starts the configuration of the Bus Terminal.

**bReadConfig:** A rising edge starts the reading of the Bus Terminal.

**eTerminal:** Selection of the respective Bus Terminal (see [E\_BA\_Terminal\_KL](ms-xhelp:///?Id=beckhoff-9264-4f85-b4a2-0cd35bf0bc31)).

**eSensor:** Selection of the sensor type (see [E\_BA\_Sensor](ms-xhelp:///?Id=beckhoff-1a60-479b-bffc-480cb8da760d)).

## VAR\_OUTPUT

```
TO_usiCtrl        : USINT;  
TO_iDataOut       : INT;   
usiState          : USINT;  
iData             : INT;  
rVal              : REAL;  
bWireBreak        : BOOL;  
bShortCircuit     : BOOL;  
wTerminalType     : WORD;  
wSpecialType      : WORD;  
wFirmwareVersion  : WORD;  
sDescription      : STRING;  
sSensorType       : STRING;  
bErr              : BOOL;  
sErrDescr         : T_MAXSTRING;
```

**TO\_usiCtrl:** Linking with the corresponding control byte of the Bus Terminal in the I/O area of the program.

**TO\_iDataOut:** Linking with the corresponding raw data (Data Out) of the Bus Terminal in the I/O area of the program.

**usiState:** Output of the present terminal status.

**iData:** Output of the present process data.

**rVal:** Scaled output value.

**bWireBreak:** Display of the channel status, sensor wire breakage.

**bShortCircuit:** Display of the channel status, sensor short-circuit.

**wTerminalType:** Display of the terminal type.

**wSpecialType:** Display of the special version of the terminal.

**wFirmwareVersion:** Display of the terminal firmware.

**sDescription:** Display of the terminal type and firmware.

**sSensorType:** Display of the sensor type.

**bErr:** Error in the terminal configuration.

**sErrDescr:** Contains the error description.

| Error description |
| --- |
| 01: Error: Check the terminal configuration KL32xx *eTerminal*/*eSensor*/*TI\_usiState*/*TI\_iDataIn*/*TO\_usiCtrl*/*TO\_iDataOut* |

## Requirements

| Development environment | Required library | Necessary function |
| --- | --- | --- |
| TwinCAT3.1 4022.16 | Tc3Building Automation Common from V1.0.4.3 | TF8040 | TwinCAT Building Automation from V1.0.5.0 |
