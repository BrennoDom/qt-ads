# MC_FunctionGeneratorFD_BkPlcMc (from V3.0.31)

## Library
tf5810_tc3_hydraulic_positioning

## Category
Motion Control

1. [TwinCAT PLC Hydraulics](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
2. [PLCopen Motion Control](ms-xhelp:///?Id=beckhoff-1ded-451e-88ec-a82873484e92)
3. [System](ms-xhelp:///?Id=beckhoff-cf25-4865-b897-b1877bc8684d)
4. [FunctionGenerator](ms-xhelp:///?Id=beckhoff-15b1-4364-95d9-9bfef4a56b92)
5. MC\_FunctionGeneratorFD\_BkPlcMc (from V3.0.31)

# MC\_FunctionGeneratorFD\_BkPlcMc (from V3.0.31)

![17269710](/tf5810_tc3_hydraulic_positioning/1033/Images/gif/9007200854763915__Web.gif)

The function block calculates the signals of a function generator.

```
VAR_OUTPUT  
    Sinus:          LREAL;  
    Cosinus:        LREAL;  
    Rectangle:      LREAL;  
    SawTooth:       LREAL;  
END_VAR
```

```
VAR_INOUT  
    stTimeBase:     ST_FunctionGeneratorTB_BkPlcMc;  
    stFunctionDef:  ST_FunctionGeneratorFD_BkPlcMc;  
END_VAR
```

**Sinus, Cosinus, Rectangle**, **SawTooth**: The output signals of the function generator.

**stTimeBase**: A structure with the parameters of the time base of this function generator.

**stFunctionDef**: A structure with the definitions of the output signals of a function generator.

## Behaviour of the function block

The output signals are determined from **stTime base.CurrentRatio** and the parameters in [stFunctionDef](ms-xhelp:///?Id=beckhoff-41b5-46c5-8602-712cb9848321).

The time base in **stTimeBase** should be updated with an [MC\_FunctionGeneratorTB\_BkPlcMc](ms-xhelp:///?Id=beckhoff-fa42-43f7-96f2-1438c3255a9d)() function block.

To change the operating frequency, an [MC\_FunctionGeneratorSetFrq\_BkPlcMc](ms-xhelp:///?Id=beckhoff-b325-4204-a66a-f21961dd38a2)() function block should be used.

[TF5810 | TwinCAT 3 Hydraulic Positioning](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
