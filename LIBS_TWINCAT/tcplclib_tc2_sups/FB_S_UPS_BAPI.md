# FB_S_UPS_BAPI

## Library
tcplclib_tc2_sups

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_SUPS](ms-xhelp:///?Id=beckhoff-26a2-4da1-bec6-c56c81740683)
2. [Function blocks](ms-xhelp:///?Id=beckhoff-a6eb-4086-b3fb-cafd20716093)
3. [BAPI](ms-xhelp:///?Id=beckhoff-e806-403f-b332-7b38d284d725)
4. FB\_S\_UPS\_BAPI

# FB\_S\_UPS\_BAPI

![238043](/tcplclib_tc2_sups/1033/Images/png/3716526091__Web.png)

The function block FB\_S\_UPS\_BAPI can be used on devices with 1-second UPS and with BIOS-API from version v1.15, in order to control the 1-second UPS from the PLC.

When the function block is first called, the data for accessing the 1-second UPS are determined via BIOS-API. This process takes several cycles. This is followed by cyclic testing for power failure. When the persistent data are written next, the access data for the PLC are saved persistently, so that during subsequent boot operations the check for power failures can take place immediately after the PLC start.

In the event of a power failure the charge state of the 1-second UPS is checked every 50 ms, every 200 ms if voltage is present and the capacity is less than 90%, and every second if voltage is present and the capacity is more than 90%. This also takes place via BIOS-API access.

In the event of a power failure the function block FB\_S\_UPS\_BAPI can be used to save the persistent data and/or execute a quick shutdown, depending on the selected mode. The default input values of the FB\_S\_UPS\_BAPI should be retained.

The 1-second UPS does not have sufficient capacity for bridging power failures. Only the Compact Flash/CFast card/Micro SD can be used for data storage, in view of the fact that the UPS capacity is not sufficient for operating a hard disk.

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
    eState            : E_S_UPS_State; (* current ups state *)  
    nCapacity         : BYTE; (* actual capacity of UPS *)  
    bBusy             : BOOL; (* TRUE: function block is busy *)  
    bError            : BOOL; (* FALSE: function block has error *)  
    nErrID            : UDINT; (* FB error ID *)  
END_VAR
```

**bPowerFailDetect**: TRUE during power failure. FALSE if the supply voltage is present.

**eState**: Internal state of the function block (type: [E\_S\_UPS\_State](ms-xhelp:///?Id=beckhoff-b509-480d-b667-a6924ca723dc))

**nCapacity**: Current charge state of the capacitors in percent (0..100%)

**bBusy:** TRUE, as long as the function block is active.

**bError:** FALSE if an error has occurred.

**nErrID:** Error number

## Requirements

| Development environment | Target platform | PLC libraries to include |
| --- | --- | --- |
| TwinCAT v3.1 B4020.32 | Platforms that support the BIOS API from v1.15 | Tc2\_SUPS |

[TwinCAT 3 | PLC Lib: Tc2\_SUPS](ms-xhelp:///?Id=beckhoff-26a2-4da1-bec6-c56c81740683)
