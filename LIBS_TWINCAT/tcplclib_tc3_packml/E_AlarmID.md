# E_AlarmID

## Library
tcplclib_tc3_packml

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc3\_PackML](ms-xhelp:///?Id=beckhoff-59be-4392-80fb-0b021151334d)
2. [Packaging Machine Functional Tag Description](ms-xhelp:///?Id=beckhoff-cfa1-4cf2-bed5-de71541a6707)
3. [DataTypes](ms-xhelp:///?Id=beckhoff-9ab3-480d-a692-669d690fad49)
4. [Alarm](ms-xhelp:///?Id=beckhoff-8226-41be-850c-2af8861f6f1b)
5. E\_AlarmID

# E\_AlarmID

The data type E\_AlarmId defines the error cause.

```
TYPE E_AlarmID : (  
    eAID_Undefined                            := 0,   
  
    (*** 1..32 Machine internal reason - safeties - OMAC defined ***)  
    eAID_EStop_Pushed                         := 1,   
    eAID_PerimeterProtectionFault,   
    eAID_MainsTurnedOff,   
    eAID_SafetyGateOrGuardDoorOpen,   
    (* 5..32 reserved for future OMAC safety codes *)  
  
    (*** 33..64 Machine internal reason - operator actions - OMAC defined *)  
    eAID_CycleStopButtonPushed                := 33,   
    eAID_StartButtonPushed,   
    eAID_ResetButtonPushed,   
    eAID_JogModeSelected,   
    eAID_AutomaticModeSelected,   
    eAID_ManualModeSelected,   
    eAID_SemiAutomaticModeSelected,   
    (* 40..64 reserved for future OMAC defined operator action codes *)  
  
    (*** 65..256 Machine internal reason - internal machine faults - product related - OMAC defined *)  
    eAID_MaterialJam                          := 65,   
    (* 66..256 reserved for future OMAC defined internal material related codes *)  
  
    (*** 257..512 Machine internal reason - internal machine faults - machine related - OMAC defined *)  
    eAID_MachineJam                           := 257,   
    eAID_ElectricalOverload,   
    eAID_MechanicalOverload,   
    eAID_DriveFault,   
    eAID_DriveFailure,   
    eAID_ServoAxisFault,   
    eAID_ServoAxisFailure,   
    eAID_CommunicationError,   
    eAID_PlcErrorCode,   
    eAID_Vacuum,   
    eAID_AirPressure,   
    eAID_Voltage,   
    eAID_Temperature,   
    eAID_HydraulicPressure,   
    eAID_HydraulicLevel,   
    eAID_HydraulicTemperature,   
    (* 273..512 reserved for future OMAC defined internal machine related codes *)  
  
    (*** 513..999 Machine internal reason - general information - OMAC defined *)  
    eAID_CounterPresetReached                 := 513,   
    eAID_ProductSelected,   
    eAID_LocalSlowSpeedRequested,   
    eAID_LocalMediumSpeedRequested,   
    eAID_LocalHighSpeedRequested,   
    eAID_LocalSurgeSpeedRequested,   
    eAID_RemoteSpeedRequested,   
    eAID_DriveWarning,   
    eAID_ServoWarning,   
    (* 522..998 reserved for future OMAC defined general information related codes *)  
    eAID_CatchAllUndefinedInternalReason      := 999,   
  
    (*** 1000..1999 Machine internal reason - vendor defined *)  
    (* 1000..1999 vendor defined area for machine internal items *)  
  
    (*** 2000..2499 Machine upstream process reason - OMAC defined *)  
    eAID_InfeedNotTurnedOn                    := 2000,   
    eAID_InfeedOverload,   
    eAID_LowPrimeMaterial,   
    eAID_HighPrimeMaterial,   
    (* 2004..2498 reserved for future OMAC defined upstream reason *)  
    eAID_CatchAllUndefinedUpstreamReason      := 2499,   
  
    (*** 2500..2999 Machine upstream process reason - vendor defined *)  
    (* 2500..2999 vendor defined area for upstream items *)  
  
    (*** 3000..3499 Machine downstream process reason - OMAC defined *)  
    eAID_DischargeNotTurnedOn                 := 3000,   
    eAID_DischargeOverload,   
    eAID_DischargeBlockedReason,   
    eAID_DischargeCycleStopReason,   
    eAID_DischargeImmediateStopReason,   
    (* 3004..3498 reserved for future OMAC defined downstream reason *)  
    eAID_CatchAllUndefinedDownstreamReason    := 3499,   
  
    (*** 3500..3999 Machine upstream process reason - vendor defined *)  
    (* 3500..3999 vendor defined area for downstream items *)  
  
    (*** 4000..4499 out of service - OMAC defined *)  
    eAID_LineNotScheduled                     := 4000,   
    eAID_PlannedMaintenance,   
    eAID_MealsAndRest,   
    eAID_Meetings,   
    eAID_Training,   
    eAID_NoPackagingMaterials,   
    eAID_RemoteStopRequested,   
    eAID_MachineNotSelected,   
    eAID_Changeover,   
    eAID_Lubrication,   
    eAID_ProductCountPresetReached,   
    eAID_SetupSelected,   
    eAID_NoIncommingProduct,   
    eAID_WaitingForElectrialService,   
    eAID_WaitingForMechanicalService  
    (* 4012..4499 reserved for future OMAC defined downstream reason *)  
  
    (*** 4500..4999 out of service - vendor defined *)  
    (* 4500..4999 vendor defined area for out of service items *)  
);   
END_TYPE
```

## Requirements

| Development environment | Target system type | PLC libraries to be linked |
| --- | --- | --- |
| TwinCAT v3.1, build 4018 onwards | PC (i386) | Tc3\_PackML |

[TwinCAT 3 | PLC Library: Tc3\_PackML](ms-xhelp:///?Id=beckhoff-59be-4392-80fb-0b021151334d)
