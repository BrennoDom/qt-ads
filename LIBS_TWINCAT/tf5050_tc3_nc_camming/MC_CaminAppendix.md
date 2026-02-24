# MC_CaminAppendix

## Library
tf5050_tc3_nc_camming

## Category
Motion Control

1. [TF5050 TC3 NC Camming](ms-xhelp:///?Id=beckhoff-984d-4c21-9ee9-97aff9b63946)
2. [Cam plates](ms-xhelp:///?Id=beckhoff-a988-474a-ac58-949c3c4ab0ef)
3. MC\_CaminAppendix

# MC\_CaminAppendix

## Coupling with cam plates

The function block [MC\_CamIn](ms-xhelp:///?Id=beckhoff-9d6c-4e6e-b012-23819a633f2e) can be used to establish a cam plate coupling (or table coupling) between a master axis and a slave axis. Note that prior to the coupling the slave axis has to be at a position defined by the cam plate. After the coupling and once the master has been started, the slave position is calculated directly from the cam plate. The slave axis is therefore not slowly synchronized with the cam plate, but it will jump if it is not already at the table position.

In practice the question arises what position the slave should be in prior to the coupling, and how this is calculated. The following figures illustrate the procedure.

*Notes*: For all subsequent calculations only axis set positions are used. The actual positions are not used in the calculations, since they would lead to calculation errors, particularly with cyclic cam plates.

Only absolute table couplings are considered. For relative couplings, the coupling position of the master or slave axis is considered in the calculations as an additional offset.

## Linear cam plates

A linear cam plate is only defined via a limited master position range. Outside this range the slave position is defined by the first or last table position. The slave therefore stops at the table edges as soon as the master leaves the defined range.

![65164324](/tf5050_tc3_nc_camming/1033/Images/gif/460494859__en-US__Web.gif)

The diagram shows that the absolute axis coordinate system (blue) does not have to be identical to the cam plate coordinate system (red). The cam plate coordinate system may be offset by a master offset or a slave offset. Scaling is also possible.

The slave position relating to a certain master position can be determined via the function block [MC\_ReadCamTableSlaveDynamics](ms-xhelp:///?Id=beckhoff-1c8e-4598-afe8-9a6bf2af2677). The block refers to the raw table data, which means that offsets and scaling factors have to be considered via the PLC program itself. Initially, the master offset is added to the current master position. If the cam plate is to be scaled, it is divided by this scaling factor.

MasterCamTablePosition := (MasterPosition + MasterOffset) / MasterScaling;

The master table position is used as input parameter for the function block [MC\_ReadCamTableSlaveDynamics](ms-xhelp:///?Id=beckhoff-1c8e-4598-afe8-9a6bf2af2677). The result is converted to an absolute slave position with slave offset and scaling, if necessary.

SlaveCamTablePosition := ReadSlaveDynamics.SlavePosition;

SlavePosition := (SlaveCamTablePosition \* SlaveScaling) + SlaveOffset;

The slave is moved to this position prior to the coupling. Alternatively, the master may be moved to a position that corresponds to the current slave position. However, generally this position cannot be determined from the cam plate, since the cam plate may be ambiguous.

*Notice*: Since the master offset is added in the first formula, a positive offset leads to the cam plate coordinate system being shifted to the left in negative direction. Accordingly, the master offset in the diagram is negative. A positive slave offset leads to the cam plate coordinate system being shifted upwards in positive direction.

## Cyclic cam plates without lift

A cyclic cam plate without lift is characterized by the fact that the slave start and end positions in the table are identical. The slave therefore moves cyclically within a defined range, without changing its position permanently in a particular direction.

![49608012](/tf5050_tc3_nc_camming/1033/Images/gif/460498059__en-US__Web.gif)

For these cam plate types, master/slave coupling requires the same preparation as for a linear cam plate. The starting position of the slave can therefore be calculated as described above. It is not necessary to use the modulo position of the master for the calculation, since the absolute position is already correctly taken into account via the coupling command.

## Cyclic cam plates with lift

The lift of a cyclic cam plate is the difference between the last and the first table position of the slave.

![43818926](/tf5050_tc3_nc_camming/1033/Images/gif/460501259__en-US__Web.gif)

Such a cam plate is continued cyclically at the end of the table. The slave position does not jump back to the initial table value. Instead, the motion continues steadily. With each new cycle, the lift is therefore added as an additional internal slave offset or subtracted if the motion is reversed.

## Uncoupling and re-coupling for cyclic cam plates with lift

If a slave is coupled to a cam plate with lift, the coupling is always done in the basic cycle (red coordinate system), i.e. without added lifting distances. If the slave is uncoupled after a few cycles and then re-coupled, the slave position returns to the basic cycle. If necessary, this behavior has to be taken into account and compensated by re-calculating the slave offset.

![58826021](/tf5050_tc3_nc_camming/1033/Images/gif/460504459__en-US__Web.gif)

MasterCamTablePos := (MasterPosition + MasterOffset) / MasterScaling;

The master table position is used as input parameter for the function block [MC\_ReadCamTableSlaveDynamics](ms-xhelp:///?Id=beckhoff-1c8e-4598-afe8-9a6bf2af2677). The result is converted to an absolute slave position with slave offset and scaling, if necessary. In addition, the number of pending lifts must be calculated and added to the slave position.

SlaveCamTablePosition := ReadSlaveDynamics.SlavePosition;

LiftNumberl := MODTURNS( (SlavePosition - SlaveOffset), SlaveHub );

NewSlaveOffset := SlaveOffset + (SlaveHub \* lift number);

SlavePosition := (SlaveCamTablePosition \* SlaveScaling) + NewSlaveOffset;

The [Autooffset](ms-xhelp:///?Id=beckhoff-ec0d-401b-8d43-f6039df26ed1) function can simplify the calculation of offsets, particularly for switching of cam plates.

[TF5050 | TwinCAT 3 NC Camming](ms-xhelp:///?Id=beckhoff-984d-4c21-9ee9-97aff9b63946)
