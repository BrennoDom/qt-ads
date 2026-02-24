# Data type MC_MotionFunctionType

## Library
tf5050_tc3_nc_camming

## Category
Motion Control

1. [TF5050 TC3 NC Camming](ms-xhelp:///?Id=beckhoff-984d-4c21-9ee9-97aff9b63946)
2. [Data type](ms-xhelp:///?Id=beckhoff-61cc-4984-82a9-77a1e817705f)
3. Data type MC\_MotionFunctionType

# Data type MC\_MotionFunctionType

```
TYPE MC_MotionFunctionType :  
(  
   MOTIONFUNCTYPE_NOTDEF,  
   MOTIONFUNCTYPE_POLYNOM1            := 1,  (* 1: polynom with order 1 *)  
   MOTIONFUNCTYPE_POLYNOM3            := 3,  (* 3: polynom with order 3 (rest <-> rest) *)  
   MOTIONFUNCTYPE_POLYNOM5            := 5,  (* 5: polynom with order 5 (rest <-> rest) *)  
   MOTIONFUNCTYPE_POLYNOM8            := 8,  (* 8: polynom with order 8 (rest <-> rest) *)  
   MOTIONFUNCTYPE_SINUSLINIE          := 10,  
   MOTIONFUNCTYPE_MODSINUSLINIE       := 11,  
   MOTIONFUNCTYPE_BESTEHORN           := 12,  
   MOTIONFUNCTYPE_BESCHLTRAPEZ        := 13, (* 13: Beschleunigungstrapez *)  
   MOTIONFUNCTYPE_POLYNOM5_MM         := 15, (* 15: polynom with order 5 (motion <-> motion) *)  
   MOTIONFUNCTYPE_SINUS_GERADE_KOMBI  := 16,  
   MOTIONFUNCTYPE_HARMONIC_KOMBI_RT   := 17,  
   MOTIONFUNCTYPE_HARMONIC_KOMBI_TR   := 18,  
   MOTIONFUNCTYPE_HARMONIC_KOMBI_VT   := 19,  
   MOTIONFUNCTYPE_HARMONIC_KOMBI_TV   := 20,  
   MOTIONFUNCTYPE_BESCHLTRAPEZ_RT     := 21, (* 21: Beschleunigungstrapez (rest <-> turn) *)  
   MOTIONFUNCTYPE_BESCHLTRAPEZ_TR     := 22, (* 22: Beschleunigungstrapez (turn <-> rest) *)  
   MOTIONFUNCTYPE_MODSINUSLINIE_VV    := 23,  
   MOTIONFUNCTYPE_POLYNOM7_MM         := 24, (* 24: polynom with order 7 (motion <-> motion) *)  
   MOTIONFUNCTYPE_POLYNOM6STP         := 27, (* 27: polynom with order 6 *)  
   MOTIONFUNCTYPE_POLYNOM6WDP         := 28, (* 28: polynom with order 6 *)  
   MOTIONFUNCTYPE_STEPFUNCTION        := 99  
);  
END_TYPE
```

Type definition for motion functions.

|  |  |
| --- | --- |
| 9216716 | Note the type  The motion function type A*utomatic* used in the TwinCAT Cam Design Editor corresponds to *MOTIONFUNCTYPE\_POLYNOM5\_MM,* the motion function type S*ynchronous* corresponds to *MOTIONFUNCTYPE\_POLYNOM1* |

[TF5050 | TwinCAT 3 NC Camming](ms-xhelp:///?Id=beckhoff-984d-4c21-9ee9-97aff9b63946)
