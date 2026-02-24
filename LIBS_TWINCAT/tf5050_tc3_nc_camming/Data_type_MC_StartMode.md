# Data type MC_StartMode

## Library
tf5050_tc3_nc_camming

## Category
Motion Control

1. [TF5050 TC3 NC Camming](ms-xhelp:///?Id=beckhoff-984d-4c21-9ee9-97aff9b63946)
2. [Data type](ms-xhelp:///?Id=beckhoff-61cc-4984-82a9-77a1e817705f)
3. Data type MC\_StartMode

# Data type MC\_StartMode

```
TYPE MC_StartMode :  
(  
   MC_STARTMODE_ABSOLUTE            := 1,  (* cam table is absolute for master and slave *)  
   MC_STARTMODE_RELATIVE            := 2,  (* cam table is relative for master and slave *)  
   MC_STARTMODE_MASTERABS_SLAVEREL  := 3, (* cam table is absolute for master and relative for slave *)  
   MC_STARTMODE_MASTERREL_SLAVEABS  := 4  (* cam table is relative for master and absolute for slave *)  
);  
END_TYPE
```

*StartMode* is used for coupling with cam plates through [MC\_CamIn](ms-xhelp:///?Id=beckhoff-9d6c-4e6e-b012-23819a633f2e) and defines whether a cam plate is interpreted absolute (based on the origin of the axis coordinate system) or relative to the coupling position. The mode can be specified as absolute or relative separately for both coordinate axes.

With *StartModeAbsolut* the cam plate coordinate system is congruent with the axis coordinate system and can be moved through an offset, if required (master or slave offset).

With *StartModeRelativ* the origin of the cam plate coordinate system is at the axis position of the respective axis (master or slave) at the time of coupling or cam plate switching. The cam plate can additionally be moved through an offset.

**Notice**: The modes MC\_STARTMODE\_RELATIVE and MC\_STARTMODE\_MASTERREL\_SLAVEABS cannot be used in conjunction with automatic master offset calculation ([MC\_CamScalingMode](ms-xhelp:///?Id=beckhoff-ec0d-401b-8d43-f6039df26ed1)), since this would cause a conflict.

[TF5050 | TwinCAT 3 NC Camming](ms-xhelp:///?Id=beckhoff-984d-4c21-9ee9-97aff9b63946)
