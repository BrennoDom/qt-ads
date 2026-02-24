# MP_VRU_Configuration

## Library
tcplclib_tc2_mpbus

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_MPBus](ms-xhelp:///?Id=beckhoff-afbb-4e7a-a6f0-964a87283892)
2. [Programming](ms-xhelp:///?Id=beckhoff-177e-411b-bfa4-57549cd6742f)
3. [POUs](ms-xhelp:///?Id=beckhoff-d0d7-47c8-bb7c-a9b7cd043f93)
4. [Function blocks](ms-xhelp:///?Id=beckhoff-6545-479b-937c-f69f8d2863f3)
5. MP\_VRU\_Configuration

# MP\_VRU\_Configuration

![15925039](/tcplclib_tc2_mpbus/1033/Images/gif/10822175627__Web.gif)

This function block is used to configure the VAV drives VRU-D3-BAC, VRU-M1-BAC and VRU-M1R-BAC (max. 8 slaves). For more information please visit [www.belimo.ch](https://www.belimo.ch/).

*MP\_Address* is used to specify the MP-Bus device with which the function block is to communicate. *bStart* activates communication with the MP-Bus device. *bBusy* indicates that the function block is active. *bError* is used to indicate an error in communication with the drive. The type of the error can be read with *iErrorID*.

## VAR\_INPUT

```
MP_Address            : USINT := 1;  
bStart                : BOOL;  
bRead_Write           : BOOL;  
dwPassword            : DWORD;  
strDataKL6771         : DataKL6771;  
rMax                  : LREAL := 100;  
rMin                  : LREAL;  
bSetpointSource       : BOOL;  
bOperationMode        : BOOL := TRUE;  
nSensor1Type          : E_MP_VRU_Sensor1Type := MPBus_VRU_Sensor_Active;
```

**MP\_Address:** MP-Bus address of the slave.

**bStart:** A positive edge starts the function block.

**bRead\_Write:** FALSE = READ only. TRUE = READ and WRITE.

**dwPassword:** The password for the drives. Usually 0x0000.

**strDataKL6771:** The data structure with which the [KL6771()](ms-xhelp:///?Id=beckhoff-c937-4fb9-a52b-2fb5de852d97) function block must be linked (see [DataKL6771](ms-xhelp:///?Id=beckhoff-b149-499c-8025-802a734c96f2)).

**rMax:** Max in % (20...100 %).

**rMin:** Min in % (0...*rMax*). *rMin* must be smaller than *rMax*.

**bSetpointSource:** TRUE = bus; FALSE = analog

**bOperationMode:** TRUE = overpressure; FALSE = underpressure

**nSensor1Type:** Sensor 1 type (see [E\_MP\_VRU\_Sensor1Type](ms-xhelp:///?Id=beckhoff-b46b-417f-b121-d3fcdca958f7)).

## VAR\_OUTPUT

```
bBusy                 : BOOL;  
bError                : BOOL;  
iErrorId              : MP_Error;  
rNominalVolumeticFlow : LREAL;  
rNominalDeltaPressure : LREAL;  
rMinRead              : LREAL;  
rMaxRead              : LREAL;  
bSetpointSourcesRead  : BOOL;  
bOperationModeRead    : BOOL;  
nSensor1TypeRead      : E_MP_VRU_Sensor1Type;  
nApplication          : E_MP_VRU_Application;  
bControlMode          : BOOL;  
nRoomPressureCascade  : E_MP_VRU_RoomPressureCascade;
```

**bBusy:** This bit is set for as long as the function block is active.

**bError:** This output goes TRUE as soon as an error occurs. This error is described via the *iErrorId* variable.

**iErrorId:** This output outputs an error code in the event of an error (see [MP\_ERROR](ms-xhelp:///?Id=beckhoff-1b03-4e19-bdad-077c71ea9445)). *bError* goes TRUE at the same time.

**rNominalVolumeticFlow:** Nominal volume flow in m³/h (0...60.000).

**rNominalDeltaPressure:** Nominal differential pressure in Pa (0...10.000).

**rMinRead:** Min in % (0...*rMax*). *rMin* must be smaller than *rMax*.

**rMaxRead:** Max in % (20...100 %).

**bSetpointSourcesRead:** TRUE = bus; FALSE = analog

**bOperationModeRead:** TRUE = overpressure; FALSE = underpressure

**nSensor1TypeRead:** Sensor 1 type (see [E\_MP\_VRU\_Sensor1Type](ms-xhelp:///?Id=beckhoff-b46b-417f-b121-d3fcdca958f7)).

**nApplication:** Visualization of the application selected by the manufacturer (see [E\_MP\_VRU\_Application](ms-xhelp:///?Id=beckhoff-f69d-410e-995a-d5748044c852)).

**bControlMode:** Visualization of the control function selected by the manufacturer. TRUE = volume flow control; FALSE = position control

**nRoomPressureCascade:** Room pressure cascade control (see [E\_MP\_VRU\_RoomPressureCascade](ms-xhelp:///?Id=beckhoff-2939-40e5-8fd0-6b25d8b0625d)).

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4024.22 | Tc2\_MPBus from 3.4.13.0 |

[TwinCAT 3 | PLC Library: Tc3\_MPBus](ms-xhelp:///?Id=beckhoff-afbb-4e7a-a6f0-964a87283892)
