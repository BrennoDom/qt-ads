# F_ConvWordToSTAX5000DriveStatus

## Library
tcplclib_tc2_drive

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_Drive](ms-xhelp:///?Id=beckhoff-2e0d-4470-8b4a-e1efaef0d787)
2. [Function blocks](ms-xhelp:///?Id=beckhoff-02e8-422c-8be2-5398740f979f)
3. [AX5000 SoE](ms-xhelp:///?Id=beckhoff-7af3-4d18-a767-d35b968cc10f)
4. [Conversion functions](ms-xhelp:///?Id=beckhoff-0007-4348-a7e9-a15a1d48f6ee)
5. F\_ConvWordToSTAX5000DriveStatus

# F\_ConvWordToSTAX5000DriveStatus

![38447936](/tcplclib_tc2_drive/1033/Images/gif/2309040139__Web.gif)

With this function the Drive status word (S-0-0135) can be changed to a structure [ST\_AX5000DriveStatus](ms-xhelp:///?Id=beckhoff-da82-4ca2-8a78-5087524fd70a).

## 10487112 Inputs

```
VAR_INPUT  
    wDriveStatus : WORD;  
END_VAR
```

| Name | Type | Description |
| --- | --- | --- |
| **wDriveStatus** | WORD | Drive status word from S-0-0135 (can be read with FB\_SoE\_Read\_ByDriveRef, can be mapped if necessary). |

## 27275145 Return value

```
FUNCTION F_ConvWordToSTAX5000DriveStatus : ST_AX5000DriveStatus
```

| Name | Type | Description |
| --- | --- | --- |
| **F\_ConvWordToSTAX5000DriveStatus** | ST\_AX5000DriveStatus | Return value of the function. Axis state as structure. |

[TwinCAT 3 | PLC Library: Tc2\_Drive](ms-xhelp:///?Id=beckhoff-2e0d-4470-8b4a-e1efaef0d787)
