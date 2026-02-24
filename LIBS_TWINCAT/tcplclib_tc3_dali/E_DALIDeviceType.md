# E_DALIDeviceType

## Library
tcplclib_tc3_dali

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc3\_DALI](ms-xhelp:///?Id=beckhoff-3b50-4f78-8721-86f9c15e9bec)
2. [Programming](ms-xhelp:///?Id=beckhoff-b5e2-4347-b4c8-164a6e6f2543)
3. [DUTs](ms-xhelp:///?Id=beckhoff-e84a-422d-b94e-99adcaade658)
4. [Enumerations](ms-xhelp:///?Id=beckhoff-c968-4aa7-be35-e6241e64c6c6)
5. E\_DALIDeviceType

# E\_DALIDeviceType

```
TYPE E_DALIDeviceType :  
(  
  DT00FluorescentLamp                        := 0,  
  DT01IndependentEmergencyLighting           := 1,  
  DT02DischargeLamp                          := 2,  
  DT03LowVoltageHalogenLamp                  := 3,  
  DT04IncandescentLamp                       := 4,  
  DT05ConversionOfDigitalSignalToDCVoltage   := 5,  
  DT06LEDModule                              := 6,  
  DT07SwitchingFunction                      := 7,  
  DT08ColorControl                           := 8,  
  DT09Sequencer                              := 9,  
  DT15LoadReferencing                        := 15,  
  DT16ThermalGearProtection                  := 16,  
  DT17DimmingCurveSelection                  := 17,  
  DT19CentrallySuppliedEmergencyOperation    := 19,  
  DT20LoadShedding                           := 20,  
  DT21ThermalLampProtection                  := 21,  
  DT23IntegratedLightSource                  := 23,  
  DT49IntegratedBusPowerSupply               := 49,  
  DT50MemoryBank1Extension                   := 50,  
  DT51EnergyReporting                        := 51,  
  DT52DiagnosticsMaintenance                 := 52,  
  Undefined                                  := 255  
) BYTE := Unknown;  
END_TYPE
```

**DT00FluorescentLamp**: Part 201: Standard device (device type 0)

**DT01IndependentEmergencyLighting**: Part 202: Device for emergency lighting (device type 1)

**DT02DischargeLamp**: Part 203: Device for discharge lamps (device type 2)

**DT03LowVoltageHalogenLamp**: Part 204: Device for low-voltage halogen lamps (device type 3)

**DT04IncandescentLamp**: Part 205: Supply voltage controller for incandescent lamps (device type 4)

**DT05ConversionOfDigitalSignalToDCVoltage**: Part 206: Device for converting digital signals to DC voltage signals (device type 5)

**DT06LEDModule**: Part 207: Device for LED modules (device type 6)

**DT07SwitchingFunction**: Part 208: Device for switching functions (device type 7)

**DT08ColorControl**: Part 209: Device for color/color temperature control (device type 8)

**DT09Sequencer**: Part 210: Sequencer (device type 9)

**DT15LoadReferencing:** Part 216: Load referencing (device type 15)

**DT16ThermalGearProtection:** Part 217: Thermal operating device protection (device type 16)

**DT17DimmingCurveSelection:** Part 218: Dimming curve selection (device type 17)

**DT19CentrallySuppliedEmergencyOperation:** Part 220: Centrally supplied emergency operation (device type 19)

**DT20LoadShedding:** Part 221: Power adaptation (device type 20)

**DT21ThermalLampProtection:** Part 222: Thermal lamp protection (device type 21)

**DT23IntegratedLightSource:** Part 224: Non-exchangeable light sources (device type 22)

**DT49IntegratedBusPowerSupply:** Part 250: Device with integrated DALI Bus power supply (device type 49)

**DT50MemoryBank1Extension:** Part 251: Further information and parameters for DALI control gears in memory bank 1 (device type 50)

**DT51EnergyReporting:** Part 252: Further parameters for the creation of an energy report (device type 51)

**DT52DiagnosticsMaintenance:** Part 253: Further parameters with diagnostic and maintenance information for DALI control gears (device type 52)

## Requirements

| Development environment | Required PLC library |
| --- | --- |
| TwinCAT from v3.1.4024.10 | Tc3\_DALI from v3.4.0.0 |

[TwinCAT 3 | PLC Library: Tc3\_DALI](ms-xhelp:///?Id=beckhoff-3b50-4f78-8721-86f9c15e9bec)
