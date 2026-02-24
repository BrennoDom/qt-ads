# ST_TcMcAutoIdent (from V3.0.4)

## Library
tf5810_tc3_hydraulic_positioning

## Category
Motion Control

1. [TwinCAT PLC Hydraulics](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
2. [PLCopen Motion Control](ms-xhelp:///?Id=beckhoff-1ded-451e-88ec-a82873484e92)
3. [Data types](ms-xhelp:///?Id=beckhoff-25bd-4475-8df7-6d29ea7ab5ff)
4. ST\_TcMcAutoIdent (from V3.0.4)

# ST\_TcMcAutoIdent (from V3.0.4)

In this structure the parameters for an [MC\_AxUtiAutoIdent\_BkPlcMc](ms-xhelp:///?Id=beckhoff-6e26-4519-a6b1-d0581db76054) function block are stored. It contains further information about the purpose of the individual elements.

```
TYPE ST_TcMcAutoIdent :  
(* last modification: 08.11.2019 *)  
STRUCT  
     EndOfTravel_Negativ:        LREAL:=0.0;  
     EndOfTravel_Positiv:        LREAL:=0.0;  
     EndOfTravel_NegativLimit:   LREAL:=0.0;  
     EndOfTravel_PositivLimit:   LREAL:=0.0;  
     DecelerationFactor:         LREAL:=1.0;  
     EndOfVelocity_NegativLimit: LREAL:=0.0;  
     EndOfVelocity_PositivLimit: LREAL:=0.0;  
     EndOfTravel_LastIdent_P:    LREAL:=0.0;  
     EndOfTravel_LastIdent_M:    LREAL:=0.0;  
     ValveCharacteristicLowEnd:  LREAL:=0.0;  
     ValveCharacteristicHighEnd: LREAL:=0.0;  
     ValveCharacteristicRamp:    LREAL:=0.0;  
     ValveCharacteristicSettling:LREAL:=0.0; (* starting with V3.0.32 *)  
     ValveCharacteristicRecovery:LREAL:=0.0;  
     ValveCharacteristicMinCycle:LREAL:=0.0;  
  
     Valve_LinLimitP:            LREAL:=0.0;   (* starting with V3.0.46 *)  
     Valve_LinLimitM:            LREAL:=0.0;  
  
     ValveCharacteristicTable:   ARRAY[1..100,1..2] OF LREAL;  
  
     EndOfIncrements_Negativ:    DINT:=0;  
     EndOfIncrements_Positiv:    DINT:=0;  
  
     ValveCharacteristicType:    INT:=0; (* starting with V3.0.33 *)  
     ValveCharacteristicTblCount:INT:=0;  
  
     EnableEndOfTravel:          BOOL:=FALSE;  
     EnableOverlap:              BOOL:=FALSE;  
     EnableZeroAdjust:           BOOL:=FALSE;  
     EnableArreaRatio:           BOOL:=FALSE;  
     EndOfTravel_PositivDone:    BOOL:=FALSE;  
     EndOfTravel_NegativDone:    BOOL:=FALSE;  
     EnableValveCharacteristic:  BOOL:=FALSE;  
     EnableNoUturn: BOOL:=FALSE;  
END_STRUCT  
END_TYPE
```

[TF5810 | TwinCAT 3 Hydraulic Positioning](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
