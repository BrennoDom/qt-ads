# E_S_UPS_State

## Library
tcplclib_tc2_sups

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_SUPS](ms-xhelp:///?Id=beckhoff-26a2-4da1-bec6-c56c81740683)
2. [Data types](ms-xhelp:///?Id=beckhoff-1f88-4ab3-8154-7be0f3fe3a67)
3. E\_S\_UPS\_State

# E\_S\_UPS\_State

```
eSUPS_PowerOK:  
in all modes: Power supply is OK  
  
eSUPS_PowerFailure:   
in all modes: Power supply is faulty (only shown for one PLC cycle)  
  
eSUPS_WritePersistentData:   
in mode eSUPS_WrPersistData_Shutdown: Writing of persistent data is active  
in mode eSUPS_WrPersistData_NoShutdown: Writing of persistent data is active  
  
eSUPS_QuickShutdown:   
in mode eSUPS_WrPersistData_Shutdown: QuickShutdown ist active  
in Mode eSUPS_ImmediateShutdown: QuickShutdown is active  
  
eSUPS_WaitForRecover:   
in mode eSUPS_WrPersistData_NoShutdown: Wait for the reestablishment of the power supply  
in mode eSUPS_CheckPowerStatus: Wait for the reestablishment of the power supply  
  
eSUPS_WaitForPowerOFF:   
in mode eSUPS_WrPersistData_Shutdown: Wait for switching off of the PC by the UPS  
in mode eSUPS_ImmediateShutdown: Wait for switching off of the PC by the UPS
```

[TwinCAT 3 | PLC Lib: Tc2\_SUPS](ms-xhelp:///?Id=beckhoff-26a2-4da1-bec6-c56c81740683)
