# E_SoE_CmdState

## Library
tcplclib_tc2_drive

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_Drive](ms-xhelp:///?Id=beckhoff-2e0d-4470-8b4a-e1efaef0d787)
2. [Data types](ms-xhelp:///?Id=beckhoff-88b6-4469-8360-19ad9f778595)
3. [SERCOS](ms-xhelp:///?Id=beckhoff-4caa-4381-82bf-3f8474c57300)
4. E\_SoE\_CmdState

# E\_SoE\_CmdState

The enumeration E\_SoE\_CmdState describes the state of an SoE command.

```
TYPE E_SoE_CmdState :(  
    eSoE_CmdState_NotSet                := 0,  
    eSoE_CmdState_Set                   := 1,  
    eSoE_CmdState_Executed              := 2,  
    eSoE_CmdState_SetEnabledExecuted    := 3,  
    eSoE_CmdState_SetAndInterrupted     := 5,  
    eSoE_CmdState_SetEnabledNotExecuted := 7,  
    eSoE_CmdState_Error                 := 15  
    );  
END_TYPE  
  
  
eSoE_CmdState_NotSet = 0  
- kein Kommando aktiv  
  
eSoE_CmdState_Set = 1  
- Kommando gesetzt (vorbereitet) aber (noch) nicht ausgeführt  
  
eSoE_CmdState_Executed = 2   
- Kommando wurde ausgeführt  
  
eSoE_CmdState_SetEnabledExecuted = 3  
- Kommando gesetzt (vorbereitet) und ausgeführt  
  
eSoE_CmdState_SetAndInterrupted = 5  
- Kommando wurde gesetzt aber unterbrochen  
  
eSoE_CmdState_SetEnabledNotExecuted = 7  
- Kommandoausführung ist noch aktiv  
  
eSoE_CmdState_Error = 15  
- Fehler bei der Kommandoausführung, es wurde in den Fehlerstate  
gewechselt
```

[TwinCAT 3 | PLC Library: Tc2\_Drive](ms-xhelp:///?Id=beckhoff-2e0d-4470-8b4a-e1efaef0d787)
