# FB_S_UPS_CX9020_U900

## Library
tcplclib_tc2_sups

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_SUPS](ms-xhelp:///?Id=beckhoff-26a2-4da1-bec6-c56c81740683)
2. [Function blocks](ms-xhelp:///?Id=beckhoff-a6eb-4086-b3fb-cafd20716093)
3. [CX9020-U900](ms-xhelp:///?Id=beckhoff-c30e-4a0a-b339-66c240ffab7d)
4. FB\_S\_UPS\_CX9020\_U900

# FB\_S\_UPS\_CX9020\_U900

![44765691](/tcplclib_tc2_sups/1033/Images/png/2242863755__Web.png)

The function block FB\_S\_UPS\_CX9020\_U900 can be used on CX9020-U900 devices with 1-second UPS, in order to control the 1-second UPS from the PLC. In the event of a power failure, this enables the persistent data to be saved and/or a quick shutdown to be executed, depending on the selected mode. The default input values of the FB\_S\_UPS\_CX9020\_U900 should be retained.

The 1-second UPS does not have sufficient capacity for bridging power failures. Only the Compact Flash card can be used for data storage, in view of the fact that the UPS capacity is not sufficient for operating a hard disk.

The 1-second UPS can be used only for a few seconds in the event of a power failure in order, to save persistent data. The data must be saved in the fast “persistent mode” “SPDM\_2PASS”, even though this can lead to real-time violations. Make sure you configure adequate router memory for saving the persistent data.

Irrespective of the mode and irrespective of whether data were saved or the quick shutdown was executed, the 1-second UPS switches off the mainboard after the discharging of the capacitors.

Note

Loss of data

If other applications or the PLC keep further files open or write to them, file errors may occur if the 1-second UPS switches off the controller.

## Function block modes

A QuickShutdown is performed automatically in the eSUPS\_WrPersistData\_Shutdown [mode](ms-xhelp:///?Id=beckhoff-162e-46c0-8f75-001e9ac167ef) (standard setting) after the storage of the persistent data.

In the eSUPS\_WrPersistData\_NoShutdown [mode](ms-xhelp:///?Id=beckhoff-162e-46c0-8f75-001e9ac167ef) only the persistent data are saved, no QuickShutdown is performed.

In eSUPS\_ImmediateShutdown [mode](ms-xhelp:///?Id=beckhoff-162e-46c0-8f75-001e9ac167ef) a quick shutdown is executed immediately, without saving data.

In the eSUPS\_CheckPowerStatus [mode](ms-xhelp:///?Id=beckhoff-162e-46c0-8f75-001e9ac167ef) only a check is performed as to whether a power failure has occurred. If this is the case, the function block only switches back to the PowerOK state after the expiry of tRecoverTime (10s).

## VAR\_INPUT

```
VAR_INPUT  
    sNetID          : T_AmsNetId:= ''; (* '' = local netid *)  
    iPLCPort        : UINT := 0; (* PLC Runtime System for writing persistent data *)  
    tTimeout        : TIME := DEFAULT_ADS_TIMEOUT; (* ADS Timeout *)  
    eUpsMode        : E_S_UPS_Mode := eSUPS_WrPersistData_Shutdown; (* UPS mode (w/wo writing persistent data, w/wo shutdown) *)  
    ePersistentMode : E_PersistentMode := SPDM_2PASS; (* mode for writing persistent data *)  
    tRecoverTime    : TIME := T#10s; (* ON time to recover from short power failure in mode eSUPS_WrPersistData_NoShutdown/eSUPS_CheckPowerStatus *)  
END_VAR
```

**sNetID**: AmsNetID of the controller (type: T\_AmsNetID)

**iPLCPort**: Port number of the PLC runtime system (851 for the first PLC runtime system, 852 for the second PLC runtime system, …). If no port number is specified, iPLCPort is 0. The function block then automatically determines the port of the PLC runtime system.

**tTimeout**: Timeout for writing of the persistent data or the quick shutdown.

**eUpsMode**: Defines whether persistent data are to be written and whether a quick shutdown is to be executed. The default value is eSUPS\_WrPersistData\_Shutdown, i.e. a quick shutdown is executed automatically once the persistent data have been saved. (Type: [E\_S\_UPS\_Mode](ms-xhelp:///?Id=beckhoff-162e-46c0-8f75-001e9ac167ef))

**ePersistentMode**: Mode for the writing of the persistent data. Default value is SPDM\_2PASS.

**tRecoverTime**: Time after which the UPS reverts to the PowerOK status in the case of UPS modes without shutdown. tRecoverTime must be somewhat longer than the maximum hold time of the UPS in order to ensure that the capacitors are fully charged.

## VAR\_OUTPUT

```
VAR_OUTPUT  
    bPowerFailDetect  : BOOL; (* TRUE while powerfailure is detected *)  
    eState            : E_S_UPS_State := eSUPS_PowerOK; (* current ups state *)  
END_VAR
```

**bPowerFailDetect**: TRUE during power failure. FALSE if the supply voltage is present.

**eState**: Internal state of the function block (type: [E\_S\_UPS\_State](ms-xhelp:///?Id=beckhoff-b509-480d-b667-a6924ca723dc))

## VAR\_GLOBAL

```
VAR_GLOBAL  
   eGlobalSUpsState  :  E_S_UPS_State; (*current ups state*)  
END_VAR
```

**eGlobalSUpsState**: Internal state of the function block as global copy of VAR\_OUTPUT

**eState**: For values see [E\_S\_UPS\_State](ms-xhelp:///?Id=beckhoff-b509-480d-b667-a6924ca723dc)

## Requirements

| Development environment | Target platform | Hardware | PLC libraries to include |
| --- | --- | --- | --- |
| TwinCAT v3.1 B4016 | CX9020-U900 | 1-second UPS | Tc2\_SUPS |

[TwinCAT 3 | PLC Lib: Tc2\_SUPS](ms-xhelp:///?Id=beckhoff-26a2-4da1-bec6-c56c81740683)
