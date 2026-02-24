# MC_GroupSetOverride

## Library
tf5420_tc3_advanced_pick_and_place

## Category
Motion Control

# MC\_GroupSetOverride

![40072161](/tf5420_tc3_advanced_pick_and_place/1033/Images/png/1427994635__Web.png)

| TF5410 TwinCAT 3 Motion Collision Avoidance | TF5420 TwinCAT 3 Motion Pick-and-Place | |
| --- | --- | --- |
|  | MC Group with Pick-and-Place | MC Group Coordinated Motion |
| 25105132 | 24619602 | 20249826 |

This function block MC\_GroupSetOverride changes the override of a group. A change is made with a certain delay. An override input value is valid between 0 [0%] and 1 [100%]. If the value is set outside this range, it is automatically set to the respective limit value.

|  |  |
| --- | --- |
| 48030711 | The behavior for override modifications in relation to the **MC group** can be defined as an axis group parameter, see [Time Override Ramp Time](ms-xhelp:///?Id=beckhoff-02a8-413e-810b-f959e700e534). |

## 29623216 VAR\_INPUT

```
VAR_INPUT  
    Enable               : BOOL;  
    VelFactor            : MC_LREAL := 1.0;  
END_VAR
```

| **Name** | **Type** | **Description** |
| --- | --- | --- |
| Enable | BOOL | The command is executed as long as Enable is active. |
| VelFactor | MC\_LREAL | The override is set to this value (value range between 0 [0 %] and 1 [100 %]). |

## 65282360 50670335 VAR\_IN\_OUT

```
VAR_IN_OUT  
   AxesGroup             : AXES_GROUP_REF;   
END_VAR
```

| **Name** | **Type** | **Description** |
| --- | --- | --- |
| AxesGroup | AXES\_GROUP\_REF | Reference to a group of axes (see [Cyclic group interface](ms-xhelp:///?Id=beckhoff-64fb-4654-848c-3c33fe50f412)). |

## 53379839 VAR\_OUTPUT

```
VAR_OUTPUT  
    Enabled              : BOOL;  
    Busy                 : BOOL;  
    Error                : BOOL;  
    ErrorId              : UDINT;  
    ActualVelFactor      : UDINT;  
END_VAR
```

| **Name** | **Type** | **Description** |
| --- | --- | --- |
| Enabled | BOOL | This output signals that the `VelFactor` has been set successfully. The `VelFactor` shows the type of an override factor. |
| Busy | BOOL | This output becomes `TRUE` when the command is started with `Enable` and remains so as long as the function block executes the command. |
| Error | BOOL | This output becomes `TRUE` if an error has occurred during command execution. |
| ErrorId | UDINT | Contains the command-specific error code of the last executed command. Details of the error code can be found in the[ADS error documentation](ms-xhelp:///?Id=beckhoff-07bc-42ba-bf39-8bb430e44b38)or in the [NC error documentation](ms-xhelp:///?Id=beckhoff-7f1e-487d-a5ed-713a7234d65b) (error codes 0x4nnn and 0x8nnn). |
| ActualVelFactor | UDINT | Override that is currently active in the group (value range between 0 [0 %] and 1 [100 %]). |

## Sample

```
VAR  
    stGroupRef            : AXES_GROUP_REF;  
    fbSetOverride         : MC_GroupSetOverride;  
END_VAR
```

```
fbSetOverride(  
    AxesGroup:=stGroupRef ,   
    Enable:= TRUE ,   
    VelFactor:=1.0 , (* 1.0 = 100% *)  
);
```

## Requirements

| Development environment | Target system type | PLC libraries to be linked |
| --- | --- | --- |
| TwinCAT V3.1.4018.26  TF5400 Advanced Motion Pack V3.1.1.17 | PC or CX (x86 or x64) | Tc3\_McCoordinatedMotion, Tc2\_MC2 |
