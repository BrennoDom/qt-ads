# Examples

## Library
tcplclib_tc2_mc2

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_MC2](ms-xhelp:///?Id=beckhoff-63a7-4c0e-8569-314547c8cffc)
2. Examples

# Examples

The sample programs use the Tc2\_MC2 library and run entirely in simulation mode.

Progress can be monitored in TwinCAT Scope View with the configuration provided.

## PTP – point to point movement

The sample program manages and moves an axis in PTP mode. The axis is moved with two instances of an MC\_MoveAbsolute function block in buffered mode over several intermediate positions and velocity levels.

Download: [Sample PTP Move.zip](https://infosys.beckhoff.com/content/1033/tcplclib_tc2_mc2/Resources/zip/9007201641738507.zip)

## Master-Slave coupling

The sample program couples two axes and moves them together. The slave axis is uncoupled and positioned during the journey.

Download: [Sample Master Slave.zip](https://infosys.beckhoff.com/content/1033/tcplclib_tc2_mc2/Resources/zip/9007201641736843.zip)

## Dancer control

The sample program shows how the velocity of a slave axis can be controlled according to the position of a dancer.

Download: [Sample Dancer Control.zip](https://infosys.beckhoff.com/content/1033/tcplclib_tc2_mc2/Resources/zip/9007201641733515.zip)

## Superimposed movement (Superposition)

The sample shows the overlay of a movement while an axis is driving.

Download: [Sample Superposition.zip](https://infosys.beckhoff.com/content/1033/tcplclib_tc2_mc2/Resources/zip/9007201641740171.zip)

## Compensation of the backlash of an axis

The sample program shows how the backlash of an axis can be compensated

Download: [Sample Backlash Comp.zip](https://infosys.beckhoff.com/content/1033/tcplclib_tc2_mc2/Resources/zip/9007201641730187.zip)

## External setpoint generation

The sample shows how an axis can be moved via the external setpoint generator. The movement of the NC axis "Axis" is generated as the sum of the individual movements of the other two Nc axes.

Download: [Sample ExtSetPoint.zip](https://infosys.beckhoff.com/content/1033/tcplclib_tc2_mc2/Resources/zip/9007201641735179.zip)

## Control loop switching in an AX5000 with two existing encoders

The sample illustrates switching between two axis control loops. Suitable hardware is required for this sample.

Download: [Sample Control loop switching.zip](https://infosys.beckhoff.com/content/1033/tcplclib_tc2_mc2/Resources/zip/9007201641731851.zip)

## Requirements

| Development environment | Target system type | PLC libraries to include |
| --- | --- | --- |
| TwinCAT v3.0.0 | PC or CX (x86 or x64) | Tc2\_MC2 |

[TwinCAT 3 | PLC Library: Tc2\_MC2](ms-xhelp:///?Id=beckhoff-63a7-4c0e-8569-314547c8cffc)
