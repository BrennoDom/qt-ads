# F_ConvWordToSTAX5000C1D

## Library
tcplclib_tc2_drive

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_Drive](ms-xhelp:///?Id=beckhoff-2e0d-4470-8b4a-e1efaef0d787)
2. [Function blocks](ms-xhelp:///?Id=beckhoff-02e8-422c-8be2-5398740f979f)
3. [AX5000 SoE](ms-xhelp:///?Id=beckhoff-7af3-4d18-a767-d35b968cc10f)
4. [Conversion functions](ms-xhelp:///?Id=beckhoff-0007-4348-a7e9-a15a1d48f6ee)
5. F\_ConvWordToSTAX5000C1D

# F\_ConvWordToSTAX5000C1D

![2077973](/tcplclib_tc2_drive/1033/Images/gif/2309038219__Web.gif)

With this function the Class 1 diagnosis [FB\_SoEReadClassXDiag\_ByDriveRef](ms-xhelp:///?Id=beckhoff-47dc-470a-90a1-c65d035b9aef) (S-0-0011) can be changed to an [ST\_AX5000\_C1D](ms-xhelp:///?Id=beckhoff-f8f9-40b3-8ab3-59ee6f9756c4) structure.

## 18701764 Inputs

```
VAR_INPUT  
    wClass1Diag : WORD;  
END_VAR
```

| Name | Type | Description |
| --- | --- | --- |
| **wClass1Diag** | WORD | Class 1 diagnosis Word from S-0-0011 (see [FB\_SoEReadClassXDiag\_ByDriveRef](ms-xhelp:///?Id=beckhoff-47dc-470a-90a1-c65d035b9aef)) |

## 34098154 Return value

```
FUNCTION F_ConvWordToSTAX5000C1D : ST_AX5000_C1D
```

| Name | Type | Description |
| --- | --- | --- |
| **F\_ConvWordToSTAX5000C1D** | [ST\_AX5000\_C1D](ms-xhelp:///?Id=beckhoff-f8f9-40b3-8ab3-59ee6f9756c4) | Return value of the function. Class 1 diagnosis as structure. |

[TwinCAT 3 | PLC Library: Tc2\_Drive](ms-xhelp:///?Id=beckhoff-2e0d-4470-8b4a-e1efaef0d787)
