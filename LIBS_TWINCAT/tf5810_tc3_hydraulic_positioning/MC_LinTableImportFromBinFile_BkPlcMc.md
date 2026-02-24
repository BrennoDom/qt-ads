# MC_LinTableImportFromBinFile_BkPlcMc

## Library
tf5810_tc3_hydraulic_positioning

## Category
Motion Control

1. [TwinCAT PLC Hydraulics](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
2. [PLCopen Motion Control](ms-xhelp:///?Id=beckhoff-1ded-451e-88ec-a82873484e92)
3. [System](ms-xhelp:///?Id=beckhoff-cf25-4865-b897-b1877bc8684d)
4. [Utilities](ms-xhelp:///?Id=beckhoff-05d5-4e7a-847c-eea5a0277852)
5. [Identification](ms-xhelp:///?Id=beckhoff-43e6-48ab-bc46-4a9c05c23e54)
6. MC\_LinTableImportFromBinFile\_BkPlcMc

# MC\_LinTableImportFromBinFile\_BkPlcMc

![24034261](/tf5810_tc3_hydraulic_positioning/1033/Images/gif/9044940043__Web.gif)

The function block imports a linearization table from a file in binary format.

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
    LastIdx:        INT:=0;  
END_VAR
```

**Execute**: A rising edge initiates the import.

## Behavior of the function block

The function block reads the contents of the file and interprets it line by line according to the following rules:

* Each two values are regarded as a pair of numbers.
* Each pair of numbers is entered as a point in the linearization table of the axis. LastIdx is thereby incremented. After a successful import, the number of table points read is available here.

## Manipulation of the file

The binary format makes it practically impossible to manipulate such a file with a simple editor. This is possible with an appropriate program, but absolutely not recommended. The expected structure of the file is hardly visible and it is practically impossible to maintain the formatting. Even with the correct formatting, however, it will hardly be possible to create a usable linearization table. The correct function of the system will not be possible. In addition, persons may be endangered and the products or plant may be damaged.

[TF5810 | TwinCAT 3 Hydraulic Positioning](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
