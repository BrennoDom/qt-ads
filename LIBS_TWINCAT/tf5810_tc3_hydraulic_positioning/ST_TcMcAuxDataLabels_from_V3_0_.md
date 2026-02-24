# ST_TcMcAuxDataLabels (from V3.0)

## Library
tf5810_tc3_hydraulic_positioning

## Category
Motion Control

1. [TwinCAT PLC Hydraulics](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
2. [PLCopen Motion Control](ms-xhelp:///?Id=beckhoff-1ded-451e-88ec-a82873484e92)
3. [Data types](ms-xhelp:///?Id=beckhoff-25bd-4475-8df7-6d29ea7ab5ff)
4. ST\_TcMcAuxDataLabels (from V3.0)

# ST\_TcMcAuxDataLabels (from V3.0)

This structure is used for storing the label texts for the customer-specific axis parameters. A structure of this type can be linked with the axis through an [MC\_AxUtiStandardInit\_BkPlcMc](ms-xhelp:///?Id=beckhoff-b490-4a55-ac43-76ba1d070d46) via a pointer in the [Axis\_Ref\_BkPlcMc](ms-xhelp:///?Id=beckhoff-002b-4aba-81ea-1693fb03013c) structure.

```
TYPE ST_TcMcAuxDataLabels:  
STRUCT  
    stLabel:        ARRAY [1..20] OF STRING(20);  
END_STRUCT  
END_TYPE
```

**stLabel**: The label texts.

[TF5810 | TwinCAT 3 Hydraulic Positioning](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
