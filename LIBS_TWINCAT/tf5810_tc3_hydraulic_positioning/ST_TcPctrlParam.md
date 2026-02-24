# ST_TcPctrlParam

## Library
tf5810_tc3_hydraulic_positioning

## Category
Motion Control

1. [TwinCAT PLC Hydraulics](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
2. [PLCopen Motion Control](ms-xhelp:///?Id=beckhoff-1ded-451e-88ec-a82873484e92)
3. [Data types](ms-xhelp:///?Id=beckhoff-25bd-4475-8df7-6d29ea7ab5ff)
4. ST\_TcPctrlParam

# ST\_TcPctrlParam

This structure contains additional parameters that can be used for a force or pressure regulator. The supply of such a function block must be handled by the application.

|  |  |
| --- | --- |
| 20249826 | The order of the parameters is not guaranteed |

```
                                                                    TYPE ST_TcPctrlParam :  
(* last modification: 30.07.2019 *)  
STRUCT  
    kP:            LREAL;  
    fTn:            LREAL;  
    fTv:            LREAL;  
    fPreset:        LREAL;  
    fWuLimit:        LREAL;  
  
    nNf:            INT;  
  
    bAlignAreas:    BOOL;   
END_STRUCT  
END_TYPE
```

**bAlignAreas:** If this parameter is TRUE, the output of the controller is adjusted directionally to the ratio of the effective areas of a cylinder. This can contribute to a more stable control if the axis has to provide control in both directions.

**fkP:** The proportional gain of the controller.

**fTn:** The integration time constant of the controller. If it is set to 0.0, the I component is switched off.

**fTv:** The rate time constant of the controller. If it is set to 0.0, the D component is switched off.

**fPreset:** This value initializes the I component when it is activated.

**fWuLimit:** Limit for the I component.

**nNf:** The response of the D component usually generates an uneven signal that makes an axis unstable. This parameter can be used to activate a sliding average value filter that averages up to 100 values.

Note

Undesired vibration

Strong filtering produces a phase error that can lead to vibration.

[TF5810 | TwinCAT 3 Hydraulic Positioning](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
