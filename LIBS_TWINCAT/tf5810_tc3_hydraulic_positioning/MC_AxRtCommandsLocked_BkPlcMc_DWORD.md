# MC_AxRtCommandsLocked_BkPlcMc : DWORD

## Library
tf5810_tc3_hydraulic_positioning

## Category
Motion Control

1. [TwinCAT PLC Hydraulics](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
2. [PLCopen Motion Control](ms-xhelp:///?Id=beckhoff-1ded-451e-88ec-a82873484e92)
3. [System](ms-xhelp:///?Id=beckhoff-cf25-4865-b897-b1877bc8684d)
4. [Utilities](ms-xhelp:///?Id=beckhoff-05d5-4e7a-847c-eea5a0277852)
5. MC\_AxRtCommandsLocked\_BkPlcMc : DWORD

# MC\_AxRtCommandsLocked\_BkPlcMc : DWORD

![7693179](/tf5810_tc3_hydraulic_positioning/1033/Images/gif/9007200854839307__Web.gif)

The function simplifies setting and deleting of a protective function in the status double word of an axis.

```
VAR_INPUT  
     nStateDWord:  DWORD:=0;  
     bProtect:     BOOL:=FALSE;  
END_VAR
```

**nStateDWord**: The current state of the status double word.

**bProtect**: The required state of the protective function.

## Behavior of the function

The function shows the status bit of the protective function in the transferred status double word, depending on **bProtect**.

|  |  |
| --- | --- |
| 2129750 | The application must assign the result of the function to the status double word of the axis. |

An [example](ms-xhelp:///?Id=beckhoff-6af5-4f42-8491-7a510b7dd9b7) is available.

[TF5810 | TwinCAT 3 Hydraulic Positioning](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
