# MP_VRU_Process

## Library
tcplclib_tc2_mpbus

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_MPBus](ms-xhelp:///?Id=beckhoff-afbb-4e7a-a6f0-964a87283892)
2. [Programming](ms-xhelp:///?Id=beckhoff-177e-411b-bfa4-57549cd6742f)
3. [POUs](ms-xhelp:///?Id=beckhoff-d0d7-47c8-bb7c-a9b7cd043f93)
4. [Function blocks](ms-xhelp:///?Id=beckhoff-6545-479b-937c-f69f8d2863f3)
5. MP\_VRU\_Process

# MP\_VRU\_Process

![9107628](/tcplclib_tc2_mpbus/1033/Images/gif/10822178443__Web.gif)

This function block is suitable for the VAV drives VRU-D3-BAC, VRU-M1-BAC and VRU-M1R-BAC (max. 8 slaves). For more information please visit [www.belimo.ch](https://www.belimo.ch/).

*MP\_Address* is used to specify the MP-Bus device with which the function block is to communicate. *bStart* activates communication with the MP-Bus device. *bBusy* indicates that the function block is active. If *bStart* remains TRUE, the device is addressed cyclically with a period specified by the time in *TMPolling*. The time should be set longer than 1 second. *bError* is used to indicate an error in communication with the drive. The type of the error can be read with *iErrorID*.

## VAR\_INPUT

```
MP_Address             : USINT := 1;  
bStart                 : BOOL;  
strDataKL6771          : DataKL6771;  
TMpolling              : TIME := t#10s;  
rSetpoint              : LREAL;  
nOverrideControl       : E_MP_VRU_OverrideControl;  
nCommand               : E_MP_VRU_Command;  
nDataRead              : BYTE;
```

**MP\_Address:** MP-Bus address of the slave.

**bStart:** A positive edge starts the function block. If a TRUE is permanently present, the function block becomes cyclically active with the time TMPolling.

**strDataKL6771:** The data structure with which the [KL6771()](ms-xhelp:///?Id=beckhoff-c937-4fb9-a52b-2fb5de852d97) function block must be linked (see [DataKL6771](ms-xhelp:///?Id=beckhoff-b149-499c-8025-802a734c96f2)).

**TMpolling:** The time for which the function block should address the drive. Default 10 s, minimum time 1 s.

**rSetpoint:** Value in % (0.. 100 %).

**nOverrideControl:** Setpoint override (see [E\_MP\_VRU\_OverrideControl](ms-xhelp:///?Id=beckhoff-c9da-4420-89ad-0f8b3524c523)).

**nCommand:** Command for service and test functions of the drive (see [E\_MP\_VRU\_Command](ms-xhelp:///?Id=beckhoff-bfc5-455a-9f7f-69d0cc98ad8c)).

**nDataRead:** 0xFF - read all data; bit 0 - read relative position; bit 1 - read absolute position; bit 2 - read relative volume flow rate; bit 3 - read absolute volume flow rate; bit 4 - read value sensor 1; bit 5 - read analog setpoint; bit 6 - read relative differential pressure; bit 7 - read absolute differential pressure

## VAR\_OUTPUT

```
bBusy                  : BOOL;  
bError                 : BOOL;  
iErrorId               : MP_Error;  
strMP_Serial_Number    : MP_Serial_Number;  
st_MP_VRU_ServiceInfo  : St_MP_VRU_ServiceInfo;  
rSetpoint_Read         : LREAL;  
nOverrideControl_Read  : E_MP_VRU_OverrideControl;  
nCommand_Read          : E_MP_VRU_Command;  
rRelativePosition      : LREAL;  
rAbsolutePosition      : LREAL;  
rRelativeVolumeticFlow : LREAL;  
rAbslouteVolumeticFlow : LREAL;  
rSensor1Value          : LREAL;  
rSetpointAnalog        : LREAL;  
rRelativeDeltaPressure : LREAL;  
rAbsoluteDeltaPressure : LREAL;
```

**bBusy:** This bit is set for as long as the function block is active.

**bError:** This output goes TRUE as soon as an error occurs. This error is described via the *iErrorId* variable.

**iErrorId:** This output outputs an error code in the event of an error (see [MP\_ERROR](ms-xhelp:///?Id=beckhoff-1b03-4e19-bdad-077c71ea9445)). *bError* goes TRUE at the same time.

**strMP\_Serial\_Number:** Structure for the serial number (see [MP\_Serial\_Number](ms-xhelp:///?Id=beckhoff-a3be-444b-bf90-d137036d8bb8)).

**st\_MP\_VRU\_ServiceInfo:** Fault and service information (see [St\_MP\_VRU\_ServiceInfo](ms-xhelp:///?Id=beckhoff-b054-4967-b28d-a3e39fffa7d6)).

**rSetpoint\_Read:** Setpoint.

**nOverrideControl\_Read:** Override (see [E\_MP\_VRU\_OverrideControl](ms-xhelp:///?Id=beckhoff-c9da-4420-89ad-0f8b3524c523)).

**nCommand\_Read:** Command (see [E\_MP\_VRU\_Command](ms-xhelp:///?Id=beckhoff-bfc5-455a-9f7f-69d0cc98ad8c)).

**rRelativePosition:** Relative position in %. Value -1 means data disabled (see VAR\_INPUT *nDataRead*).

**rAbsolutePosition:** Absolute position in °. Value -1 means data disabled (see VAR\_INPUT *nDataRead*).

**rRelativeVolumeticFlow:** Relative volume flow rate in %. Value -1 means data disabled (see VAR\_INPUT *nDataRead*).

**rAbslouteVolumeticFlow:** Absolute volume flow rate in m³/h. Value -1 means data disabled (see VAR\_INPUT *nDataRead*).

**rSensor1Value:** Value of sensor 1 in mV/Ohm. Value -1 means data disabled (see VAR\_INPUT *nDataRead*).

**rSetpointAnalog:** Analog setpoint in %. Value -1 means data disabled (see VAR\_INPUT *nDataRead*).

**rRelativeDeltaPressure:** Relative differential pressure %. Value -1 means data disabled (see VAR\_INPUT *nDataRead*).

**rAbsoluteDeltaPressure:** Absolute differential pressure in Pa. Value -1 means data disabled (see VAR\_INPUT *nDataRead*).

## Requirements

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4024.22 | Tc2\_MPBus from 3.4.13.0 |

[TwinCAT 3 | PLC Library: Tc3\_MPBus](ms-xhelp:///?Id=beckhoff-afbb-4e7a-a6f0-964a87283892)
