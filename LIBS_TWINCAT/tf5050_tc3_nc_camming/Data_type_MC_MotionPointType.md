# Data type MC_MotionPointType

## Library
tf5050_tc3_nc_camming

## Category
Motion Control

1. [TF5050 TC3 NC Camming](ms-xhelp:///?Id=beckhoff-984d-4c21-9ee9-97aff9b63946)
2. [Data type](ms-xhelp:///?Id=beckhoff-61cc-4984-82a9-77a1e817705f)
3. Data type MC\_MotionPointType

# Data type MC\_MotionPointType

```
TYPE MC_MotionPointType :  
(  
   MOTIONPOINTTYPE_IGNORE,                  (* Ignore point *)  
   MOTIONPOINTTYPE_REST         := 16#0001, (* Restpoint – Rastpunkt *)  
   MOTIONPOINTTYPE_VELOCITY     := 16#0002, (* Velocity Point - Geschwindigkeitspunkt *)  
   MOTIONPOINTTYPE_TURN         := 16#0004, (* Turn Point - Umkehrpunkt *)  
   MOTIONPOINTTYPE_MOTION       := 16#0008, (* Motion Point - Bewegungspunkt *)  
   MOTIONPOINTTYPE_ADD          := 16#0F00, (* Addieren von Segmenten *)  
   MOTIONPOINTTYPE_ACTIVATION   := 16#2000  (* 1: activation point *)  
);  
END_TYPE
```

Type definition for the table point.

[TF5050 | TwinCAT 3 NC Camming](ms-xhelp:///?Id=beckhoff-984d-4c21-9ee9-97aff9b63946)
