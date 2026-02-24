# F_ConvWordToSTIndraDriveCsC1D

## Library
tcplclib_tc2_drive

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_Drive](ms-xhelp:///?Id=beckhoff-2e0d-4470-8b4a-e1efaef0d787)
2. [Function blocks](ms-xhelp:///?Id=beckhoff-02e8-422c-8be2-5398740f979f)
3. [IndraDrive Cs](ms-xhelp:///?Id=beckhoff-7d8f-4bb7-b8c4-114910c9d8d6)
4. [Conversion functions](ms-xhelp:///?Id=beckhoff-9b78-44bf-81f1-b34ca45adbd5)
5. F\_ConvWordToSTIndraDriveCsC1D

# F\_ConvWordToSTIndraDriveCsC1D

![33750194](/tcplclib_tc2_drive/1033/Images/gif/2309005195__Web.gif)

With this function the Class 1 diagnosis [FB\_SoEReadClassXDiag\_ByDriveRef](ms-xhelp:///?Id=beckhoff-47dc-470a-90a1-c65d035b9aef)   
(S-0-0011) can be changed to an [ST\_IndraDriveCs\_C1D](ms-xhelp:///?Id=beckhoff-2217-461a-9cc1-73a419519da6) structure.

## 35316297 Inputs

```
VAR_INPUT  
    wClass1Diag : WORD;  
END_VAR
```

| Name | Type | Description |
| --- | --- | --- |
| **wClass1Diag** | WORD | Class 1 diagnosis Word from S-0-0011  (see [FB\_SoEReadClassXDiag\_ByDriveRef](ms-xhelp:///?Id=beckhoff-47dc-470a-90a1-c65d035b9aef)). |

## 49411218 Return value

```
FUNCTION F_ConvWordToSTIndraDriveCsC1D : ST_IndraDriveCs_C1D
```

| Name | Type | Description |
| --- | --- | --- |
| **F\_ConvWordToSTIndraDriveCsC1D** | [ST\_IndraDriveCs\_C1D](ms-xhelp:///?Id=beckhoff-2217-461a-9cc1-73a419519da6) | Return value of the function Class-1-Diagnosis as ST\_IndraDrivesCs\_C1D structure. |

[TwinCAT 3 | PLC Library: Tc2\_Drive](ms-xhelp:///?Id=beckhoff-2e0d-4470-8b4a-e1efaef0d787)
