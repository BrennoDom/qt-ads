# E_BA_Sensor

## Library
tcplclib_tc3_ba_common

## Category
Motion Control

# E\_BA\_Sensor

Enumerator for selecting a sensor type for measuring analog values.

```
TYPE E_BA_SENSOR :  
(  
  KL3208_0010_PT1000              := 0,  
  KL3208_0010_NI1000              := 1,  
  KL3208_0010_NI1000_LS           := 2,  
  KL3208_0010_NTC1K8              := 3,  
  KL3208_0010_NTC1K8_TK           := 4,  
  KL3208_0010_NTC2K2              := 5,  
  KL3208_0010_NTC3K               := 6,  
  KL3208_0010_NTC5K               := 7,  
  KL3208_0010_NTC10K              := 8,  
  KL3208_0010_NTC10KPRE           := 9,  
  KL3208_0010_NTC10K_3204         := 10,  
  KL3208_0010_NTC10KTYP2          := 11,  
  KL3208_0010_NTC10KTYP3          := 12,  
  KL3208_0010_NTC10KDALE          := 13,  
  KL3208_0010_NTC10K3A221         := 14,  
  KL3208_0010_NTC20K              := 15,  
  KL3208_0010_NTC100K             := 16,  
  KL3208_0010_Poti_Resolution_01  := 17,  
  KL3208_0010_Poti_Resolution_1_1 := 18,  
  KL320x_0000_PT1000              := 19,  
  KL320x_0000_NI1000              := 20,  
  KL320x_0000_PT100               := 21,  
  KL320x_0000_PT200               := 22,  
  KL320x_0000_PT500               := 23,  
  KL320x_0000_NI100               := 24,  
  KL320x_0000_NI120               := 25,  
  KL320x_0000_Output_10_5000      := 26,  
  KL320x_0000_Output_10_1200      := 27,  
  Undefined                       := 16#FFFF  
)DINT;  
END_TYPE
```

## Requirements

| Development environment | Required library | Necessary function |
| --- | --- | --- |
| TwinCAT3.1 4022.16 | Tc3Building Automation Common from V1.0.4.3 | TF8040 | TwinCAT Building Automation from V1.0.5.0 |
