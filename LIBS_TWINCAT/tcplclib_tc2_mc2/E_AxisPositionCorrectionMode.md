# E_AxisPositionCorrectionMode

## Library
tcplclib_tc2_mc2

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_MC2](ms-xhelp:///?Id=beckhoff-63a7-4c0e-8569-314547c8cffc)
2. [Data types](ms-xhelp:///?Id=beckhoff-683b-4615-8584-914eb091e041)
3. [Status and parameter](ms-xhelp:///?Id=beckhoff-a949-4038-af4c-900da2b41d28)
4. E\_AxisPositionCorrectionMode

# E\_AxisPositionCorrectionMode

```
TYPE E_PositionCorrectionMode:  
(  
    POSITIONCORRECTION_MODE_UNLIMITED, (* no limitation - pass correction immediately *)  
    POSITIONCORRECTION_MODE_FAST,      (* limitatation to maximum position change per cycle *)  
    POSITIONCORRECTION_MODE_FULLLENGTH (* limitation uses full length to adapt to correction in small steps *)  
);  
END_TYPE
```

|  |  |
| --- | --- |
| POSITIONCORRECTION\_MODE\_UNLIMITED | No filtering, the correction is executed immediately. Note that large changes in the correction value can lead to high accelerations. |
| POSITIONCORRECTION\_MODE\_FAST | The position correction is limited to the extent that a maximum acceleration is not exceeded. However, the correction is completely executed as fast as possible. |
| POSITIONCORRECTION\_MODE\_FULLLENGTH | The position correction is accomplished distributed over a distance of the axis (CorrectionLength). This results in smaller changes per time unit. |

[TwinCAT 3 | PLC Library: Tc2\_MC2](ms-xhelp:///?Id=beckhoff-63a7-4c0e-8569-314547c8cffc)
