# ST_FunctionGeneratorFD_BkPlcMc (from V3.0.31)

## Library
tf5810_tc3_hydraulic_positioning

## Category
Motion Control

1. [TwinCAT PLC Hydraulics](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
2. [PLCopen Motion Control](ms-xhelp:///?Id=beckhoff-1ded-451e-88ec-a82873484e92)
3. [Data types](ms-xhelp:///?Id=beckhoff-25bd-4475-8df7-6d29ea7ab5ff)
4. ST\_FunctionGeneratorFD\_BkPlcMc (from V3.0.31)

# ST\_FunctionGeneratorFD\_BkPlcMc (from V3.0.31)

This structure consolidates parameter for the definition of the output signals of a function generator. A structure of this type is transferred to [MC\_FunctionGeneratorFD\_BkPlcMc](ms-xhelp:///?Id=beckhoff-c220-4046-af00-f126004a753d)() function blocks.

```
TYPE ST_FunctionGeneratorFD_BkPlcMc :  
STRUCT  
     Sin_Amplitude:    LREAL:=0.0;  
     Sin_Phase:        LREAL:=0.0;  
     Sin_Offset:       LREAL:=0.0;  
  
     Cos_Amplitude:    LREAL:=0.0;  
     Cos_Phase:        LREAL:=0.0;  
     Cos_Offset:       LREAL:=0.0;  
  
     Rect_Amplitude:   LREAL:=0.0;  
     Rect_Phase:       LREAL:=0.0;  
     Rect_Ratio:       LREAL:=0.5;  
     Rect_Offset:      LREAL:=0.0;  
  
     Saw_Amplitude:    LREAL:=0.0;  
     Saw_Phase:        LREAL:=0.0;  
     Saw_Ratio:        LREAL:=0.5;  
     Saw_Offset:       LREAL:=0.0;  
  
END_STRUCT  
END_TYPE
```

**Sin\_Amplitude, Cos\_Amplitude, Rect\_Amplitude, Saw\_Amplitude**: The peak value of the signals.

**Sin\_Phase, Cos\_Phase, Rect\_Phase, Saw\_Phase**: The phase shift of the signals.

**Sin\_Offset**, **Cos\_Offset**, **Rect\_Offset, Saw\_Offset:** The zero point offset of the signals.

**Rect\_Ratio**, **Saw\_Ratio**: The duty factor of the square or sawtooth signal.

[TF5810 | TwinCAT 3 Hydraulic Positioning](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
