# F_ConvWordToSTIndraDriveCsDriveStatus

## Library
tcplclib_tc2_drive

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_Drive](ms-xhelp:///?Id=beckhoff-2e0d-4470-8b4a-e1efaef0d787)
2. [Function blocks](ms-xhelp:///?Id=beckhoff-02e8-422c-8be2-5398740f979f)
3. [IndraDrive Cs](ms-xhelp:///?Id=beckhoff-7d8f-4bb7-b8c4-114910c9d8d6)
4. [Conversion functions](ms-xhelp:///?Id=beckhoff-9b78-44bf-81f1-b34ca45adbd5)
5. F\_ConvWordToSTIndraDriveCsDriveStatus

# F\_ConvWordToSTIndraDriveCsDriveStatus

![42047784](/tcplclib_tc2_drive/1033/Images/gif/2309005195__Web.gif)

With this function the Drive status word (S-0-0135) can be changed to a structure [ST\_IndraDriveCsDriveStatus](ms-xhelp:///?Id=beckhoff-d04c-4a7a-8886-7ab8941ed1c0) .

## 42885739 Inputs

```
VAR_INPUT  
    wClass1Diag : WORD;  
END_VAR
```

| Name | Type | Description |
| --- | --- | --- |
| **wClass1Diag** | WORD | Drive status word from S-0-0135  Can be read with FB\_SoE\_Read\_ByDriveRef, can be mapped if necessary. |

## 50427332 Return value

```
FUNCTION F_ConvWordToSTIndraDriveCsDriveStatus : ST_IndraDriveCsDriveStatus
```

| Name | Type | Description |
| --- | --- | --- |
| **F\_ConvWordToSTIndraDriveCsDriveStatus** | [ST\_IndraDriveCsDriveStatus](ms-xhelp:///?Id=beckhoff-d04c-4a7a-8886-7ab8941ed1c0) | Return value of the function. Drive status word as ST\_IndraDriveCsDriveStatus structure. |

[TwinCAT 3 | PLC Library: Tc2\_Drive](ms-xhelp:///?Id=beckhoff-2e0d-4470-8b4a-e1efaef0d787)
