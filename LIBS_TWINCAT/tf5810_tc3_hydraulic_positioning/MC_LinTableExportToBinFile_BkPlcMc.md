# MC_LinTableExportToBinFile_BkPlcMc

## Library
tf5810_tc3_hydraulic_positioning

## Category
Motion Control

1. [TwinCAT PLC Hydraulics](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
2. [PLCopen Motion Control](ms-xhelp:///?Id=beckhoff-1ded-451e-88ec-a82873484e92)
3. [System](ms-xhelp:///?Id=beckhoff-cf25-4865-b897-b1877bc8684d)
4. [Utilities](ms-xhelp:///?Id=beckhoff-05d5-4e7a-847c-eea5a0277852)
5. [Identification](ms-xhelp:///?Id=beckhoff-43e6-48ab-bc46-4a9c05c23e54)
6. MC\_LinTableExportToBinFile\_BkPlcMc

# MC\_LinTableExportToBinFile\_BkPlcMc

![25151854](/tf5810_tc3_hydraulic_positioning/1033/Images/gif/9044907019__Web.gif)

The function block exports a linearization table to a file in binary format.

```
VAR_INPUT  
    Execute:     BOOL:=FALSE;  
    FileName:    STRING(255):=’’;  
END_VAR
```

```
VAR_INOUT  
    Axis:           Axis_Ref_BkPlcMc;  
END_VAR
```

```
VAR_OUTPUT  
    Busy:           BOOL;  
    Done:           BOOL;  
    Error:          BOOL;  
    ErrorID:        UDINT;  
END_VAR
```

**Execute**: A rising edge initiates the export.

## Behavior of the function block

The function block generates a file in the format expected by [MC\_LinTableImportFromBinFile\_BkPlcMc](ms-xhelp:///?Id=beckhoff-1afc-4f33-a3b7-d5196ffc6065).

[TF5810 | TwinCAT 3 Hydraulic Positioning](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
