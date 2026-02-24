# E_TcMcDriveType (from V3.0)

## Library
tf5810_tc3_hydraulic_positioning

## Category
Motion Control

1. [TwinCAT PLC Hydraulics](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
2. [PLCopen Motion Control](ms-xhelp:///?Id=beckhoff-1ded-451e-88ec-a82873484e92)
3. [Data types](ms-xhelp:///?Id=beckhoff-25bd-4475-8df7-6d29ea7ab5ff)
4. E\_TcMcDriveType (from V3.0)

# E\_TcMcDriveType (from V3.0)

The constants listed here are used to identify the hardware used to output the control values for an axis.

```
                                TYPE E_TcMcDriveType :(  
(*  
    The sequence below must not be changed!  
    New types have to be added at the end.  
    In case a type becomes obsolete it has to be replaced by a dummy  
    to ensure the numerical meaning of the other codes.  
*)  
(*  
    Die bestehende Reihenfolge darf nicht veraendert werden.  
    Neue Typen muessen am Ende eingefuegt werden.  
    Wenn ein Typ wegfallen sollte, muss er durch einen Dummy  
    ersetzt werden, um die numerische Zuordnung zu garantieren.  
*)  
(* last modification: 26.02.2016 *)  
iTcMc_Drive_Customized,  
iTcMc_DriveLowCostStepper,  
iTcMc_DriveKL2521,  
iTcMc_DriveKL4032,  
iTcMc_DriveAx2000_B900R,  
iTcMc_DriveM2400_D1,  
iTcMc_DriveM2400_D2,  
iTcMc_DriveM2400_D3,  
iTcMc_DriveM2400_D4,  
iTcMc_DriveLowCostStepperHS,  
iTcMc_DriveLowCostStepperFS,  
iTcMc_DriveIx2512_1Coil,  
iTcMc_DriveIx2512_2Coil,  
iTcMc_DriveKL2531,  
iTcMc_DriveKL2541,  
iTcMc_DriveEL4132,  
iTcMc_DriveAx2000_B200R,  
iTcMc_DriveAx2000_B110R,  
iTcMc_DriveKL2532,  
iTcMc_DriveKL2552,  
iTcMc_DriveKL2535_1Coil,  
iTcMc_DriveKL2535_2Coil,  
iTcMc_DriveKL2545_1Coil,  
iTcMc_DriveKL2545_2Coil,  
iTcMc_DriveLowCostInverter,  
iTcMc_Drive_CoE_DS408,  
iTcMc_DriveAx2000_B110A,  
iTcMc_DriveAx5000_B110A,  
iTcMc_DriveAx2000_B750A,  
iTcMc_Drive_CoE_DS402,  
iTcMc_DriveAx5000_B110SR,  
iTcMc_DriveEL4x22,  
iTcMc_DriveEL2521,  
iTcMc_DrivePumpEtcIO,  
iTcMc_DriveEL2535_1Coil,  
iTcMc_DriveEL2535_2Coil,  
iTcMc_DriveEL7201,  
iTcMc_DriveEL7037,  
iTcMc_DriveEL7047,  
iTcMc_DriveEM8908,  
iTcMc_DriveAx5000_B110INC,  
iTcMc_Drive_TestOnly:=1000  
);  
END_TYPE
```

**iTcMc\_Drive\_Customized**: The control value for the drive has not been prepared for output on any particular hardware. This process must be carried out by the PLC application itself.

**iTcMc\_DriveAx2000\_B110A**: The control value for the drive is processed for output on an AX2000 actuator at an absolute multi-turn encoder motor at the EtherCAT fieldbus.

**iTcMc\_DriveAx2000\_B110R**: The control value for the drive is processed for output on an AX2000 actuator at a resolver motor at the EtherCAT fieldbus.

**iTcMc\_DriveAx2000\_B200R**: The control value for the drive is processed for output on an AX2000 actuator at a resolver motor at the Beckhoff II/O fieldbus.

**iTcMc\_DriveAx2000\_B750A**: The control value for the drive is processed for output on an AX2000 actuator at an absolute multi-turn encoder motor at the Sercos fieldbus.

**iTcMc\_DriveAx2000\_B900R**: The control value for the drive is processed for output on an AX2000 actuator at a resolver motor at the Beckhoff RealTime Ethernet fieldbus.

**iTcMc\_DriveAx5000\_B110A**: The control value for the drive is processed for output on an AX5000 actuator at an absolute multi-turn encoder motor at the EtherCAT fieldbus.

**iTcMc\_DriveAx5000\_B110SR**: The control value for the drive is processed for output on an AX5000 actuator at an absolute single-turn encoder or resolver motor at the EtherCAT fieldbus.

**iTcMc\_DriveAx5000\_B110INC**: The control value for the drive is processed for output on an AX5000 actuator at an incremental encoder at the EtherCAT fieldbus.

**iTcMc\_DriveEL2521**:The control value for the drive has been appropriately processed for output on a KL2521 Pulse Train terminal.

**iTcMc\_DriveEL2535\_1Coil**: The control value for the drive is processed for output on an EL2535 PWM motor output stage terminal.

**iTcMc\_DriveEL2535\_2Coil**: The control value for the drive is processed for output on an EL2535 PWM motor output stage terminal.

**iTcMc\_DriveEL4132**: The control value for the drive has been appropriately processed for output on a ±10 V EL4132 analog output terminal.

**iTcMc\_DriveEL4x22**: In preparation.

**iTcMc\_DriveEL7031**: The control value for the drive is processed for output on an EL7031 stepper motor output stage terminal.

**iTcMc\_DriveEL7037**: The control value for the drive is processed for output on an EL7037 stepper motor output stage terminal.

**iTcMc\_DriveEL7041**: The control value for the drive is processed for output on an EL7041 stepper motor output stage terminal.

**iTcMc\_DriveEL7047**: The control value for the drive is processed for output on an EL7047 stepper motor output stage terminal.

**iTcMc\_DriveEL7201**: The control value for the drive is processed for output on an EL7201 servo terminal.

**iTcMc\_DriveEM8908**: Reserved for sector-specific packet.

**iTcMc\_DriveIx2512\_1Coil**: The control value for the drive is processed for output on a Fieldbus Box IP/IE2512. The rules for valves with one coil apply.

**iTcMc\_DriveIx2512\_2Coil**: The control value for the drive is processed for output on a Fieldbus Box IP/IE2512. The rules for valves with two coils apply.

**iTcMc\_DriveKL2521**: The control value for the drive has been appropriately processed for output on a KL2521 Pulse Train terminal.

**iTcMc\_DriveKL2531**: The control value for the drive is processed for output on a KL2531 stepper motor output stage terminal.

**iTcMc\_DriveKL2532**: The control value for the drive is processed for output on a KL2532 DC motor output stage terminal.

**iTcMc\_DriveKL2535\_1Coil**: The control value for the drive is processed for output on a KL2535 PWM motor output stage terminal.

**iTcMc\_DriveKL2535\_2Coil**: The control value for the drive is processed for output on a KL2535 PWM motor output stage terminal.

**iTcMc\_DriveKL2541**: The control value for the drive is processed for output on a KL2541 stepper motor output stage terminal.

**iTcMc\_DriveKL2542**: The control value for the drive is processed for output on a KL2542 DC motor output stage terminal.

**iTcMc\_DriveKL2545\_1Coil**: The control value for the drive is processed for output on a KL2545 PWM motor output stage terminal.

**iTcMc\_DriveKL2545\_2Coil**: The control value for the drive is processed for output on a KL2545 PWM motor output stage terminal.

**iTcMc\_DriveKL4032**: The set value for the drive has been appropriately processed for output on a ±10 V KL4032 analog output terminal.

**iTcMc\_DriveLowCostInverter**: The control value for the drive is processed for output in the form of digital output signals for a frequency converter with programmed fixed frequencies.

**iTcMc\_DriveLowCostStepper**: The incremental set position changes are generated as a digital output signals for a directly controlled stepper motor. This code continues to be supported for reasons of compatibility, and has the same meaning as **iTcMc\_DriveLowCostStepperHS**.

**iTcMc\_DriveLowCostStepperHS**: The incremental set position changes are generated as a digital output signals for a directly controlled stepper motor. Half-stepping is being used.

**iTcMc\_DriveLowCostStepperFS**: The incremental set position changes are generated as a digital output signals for a directly controlled stepper motor. Full-stepping is being used.

**iTcMc\_DriveM2400\_D1**: The control value for the drive has been appropriately processed for output on the first channel of an M2400 Box on the Beckhoff II/O.

**iTcMc\_DriveM2400\_D2**: The control value for the drive has been appropriately processed for output on the second channel of an M2400 Box on the Beckhoff II/O.

**iTcMc\_DriveM2400\_D3**: The control value for the drive has been appropriately processed for output on the third channel of an M2400 Box on the Beckhoff II/O.

**iTcMc\_DriveM2400\_D4**: The control value for the drive has been appropriately processed for output on the fourth channel of an M2400 Box on the Beckhoff II/O.

**iTcMc\_Drive\_CoE\_DS402**: In preparation.

**iTcMc\_Drive\_CoE\_DS408**: The control value for the drive is processed for output on a proportional valve at the EtherCAT fieldbus.

**iTcMc\_DrivePumpEtcIO:** reserved

**iTcMc\_Drive\_TestOnly:** reserved for internal testing; do not use.

[TF5810 | TwinCAT 3 Hydraulic Positioning](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
