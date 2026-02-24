# ST_TcPlcRegDataItem (from V3.0.7)

## Library
tf5810_tc3_hydraulic_positioning

## Category
Motion Control

1. [TwinCAT PLC Hydraulics](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
2. [PLCopen Motion Control](ms-xhelp:///?Id=beckhoff-1ded-451e-88ec-a82873484e92)
3. [Data types](ms-xhelp:///?Id=beckhoff-25bd-4475-8df7-6d29ea7ab5ff)
4. ST\_TcPlcRegDataItem (from V3.0.7)

# ST\_TcPlcRegDataItem (from V3.0.7)

This structure contains a parameter for a KL terminal. An ARRAY of elements of this type forms the type [ST\_TcPlcRegDataTable](ms-xhelp:///?Id=beckhoff-0216-4cca-a486-a37a23eb2ef4).

```
TYPE ST_TcPlcRegDataItem :  
STRUCT  
    Access:     INT:=0;  
    Select:     INT:=-1;  
    RegData:    WORD:=0;  
END_STRUCT  
END_TYPE
```

**Access**: The type of the operation to be executed is coded here. Details can be found under [MC\_AxUtiUpdateRegDriveTerm\_BkPlcMc](ms-xhelp:///?Id=beckhoff-dd55-4c8d-ae26-8aa901301651) or [MC\_AxUtiUpdateRegEncTerm\_BkPlcMc](ms-xhelp:///?Id=beckhoff-aecd-46aa-8e3c-4d0e10d14cac).

**Select**: The address of the register in the terminal.

**RegData**: The parameters to be used for the operation to be executed.

[TF5810 | TwinCAT 3 Hydraulic Positioning](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
