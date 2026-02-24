# E_SoE_CmdControl

## Library
tcplclib_tc2_drive

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_Drive](ms-xhelp:///?Id=beckhoff-2e0d-4470-8b4a-e1efaef0d787)
2. [Data types](ms-xhelp:///?Id=beckhoff-88b6-4469-8360-19ad9f778595)
3. [SERCOS](ms-xhelp:///?Id=beckhoff-4caa-4381-82bf-3f8474c57300)
4. E\_SoE\_CmdControl

# E\_SoE\_CmdControl

The enumeration E\_SoECmdControl determines whether the command is to be canceled, set or started.

```
TYPE E_SoE_CmdControl :(  
    eSoE_CmdControl_Cancel       := 0,  
    eSoE_CmdControl_Set          := 1,  
    eSoE_CmdControl_SetAndEnable := 3  
    );  
END_TYPE
```

| Name | Description |
| --- | --- |
| **eSoE\_CmdControl\_Cancel** | Cancel command. |
| **eSoE\_CmdControl\_Set** | Set command. |
| **eSoE\_CmdControl\_SetAndEnable** | Set command and execute. |

[TwinCAT 3 | PLC Library: Tc2\_Drive](ms-xhelp:///?Id=beckhoff-2e0d-4470-8b4a-e1efaef0d787)
