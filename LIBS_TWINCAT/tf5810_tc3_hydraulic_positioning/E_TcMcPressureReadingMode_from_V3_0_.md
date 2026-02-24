# E_TcMcPressureReadingMode (from V3.0)

## Library
tf5810_tc3_hydraulic_positioning

## Category
Motion Control

1. [TwinCAT PLC Hydraulics](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
2. [PLCopen Motion Control](ms-xhelp:///?Id=beckhoff-1ded-451e-88ec-a82873484e92)
3. [Data types](ms-xhelp:///?Id=beckhoff-25bd-4475-8df7-6d29ea7ab5ff)
4. E\_TcMcPressureReadingMode (from V3.0)

# E\_TcMcPressureReadingMode (from V3.0)

The constants in this list are transferred to function blocks for logging [actual force or pressure values](ms-xhelp:///?Id=beckhoff-4720-4a6c-8984-3974598c0188). They determine which actual value should be updated in the [ST\_TcHydAxRtData](ms-xhelp:///?Id=beckhoff-1ffc-4f72-80ec-3f7c8585d12d) structure with the result of the evaluation.

```
TYPE E_TcMcPressureReadingMode :  
(  
    iTcHydPressureReadingDefault,  
    iTcHydPressureReadingActPressure,  
    iTcHydPressureReadingActPressureA,  
    iTcHydPressureReadingActPressureB,  
    iTcHydPressureReadingActForce,  
    iTcHydPressureReadingSupplyPressure,  
    iTcHydPressureReadingValvePressure  
);  
END_TYPE
```

**iTcHydPressureReadingDefault**: The target variable depends on the function block being used.

**iTcHydPressureReadingActPressure**: The target variable is **fActPressure**. Some function blocks automatically update **fActPressureA** and **fActPressureB**.

**iTcHydPressureReadingActPressureA**: The target variable is **fActPressureA**.

**iTcHydPressureReadingActPressureB**: The target variable is **fActPressureA**.

**iTcHydPressureReadingActForce**: The target variable is **fActForce**. Some function blocks automatically update **fActPressure,fActPressureA** and **fActPressureB**.

**iTcHydPressureReadingSupplyPressure**: The target variable is **fSupplyPressure**.

**iTcHydPressureReadingValvePressure**: The target variable is **fValvePressure**.

[TF5810 | TwinCAT 3 Hydraulic Positioning](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
