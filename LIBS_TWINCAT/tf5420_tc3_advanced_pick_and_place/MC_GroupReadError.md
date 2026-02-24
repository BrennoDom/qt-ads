# MC_GroupReadError

## Library
tf5420_tc3_advanced_pick_and_place

## Category
Motion Control

# MC\_GroupReadError

![21156092](/tf5420_tc3_advanced_pick_and_place/1033/Images/png/1427886475__Web.png)

| TF5410 TwinCAT 3 Motion Collision Avoidance | TF5420 TwinCAT 3 Motion Pick-and-Place | |
| --- | --- | --- |
|  | MC Group with Pick-and-Place | MC Group Coordinated Motion |
| 56187107 | 35921916 | 54861794 |

This function block returns the error code for the group. It does not return any errors for function blocks (e.g. invalid parameterization).

## 23994101 VAR\_INPUT

```
VAR_INPUT  
    Enable     : BOOL;  
END_VAR
```

| **Name** | **Type** | **Description** |
| --- | --- | --- |
| Enable | BOOL | The command is executed as long as Enable is active. |

## 14620318 64473998 VAR\_IN\_OUT

```
VAR_IN_OUT  
   AxesGroup             : AXES_GROUP_REF;   
END_VAR
```

| **Name** | **Type** | **Description** |
| --- | --- | --- |
| AxesGroup | AXES\_GROUP\_REF | Reference to a group of axes (see [Cyclic group interface](ms-xhelp:///?Id=beckhoff-64fb-4654-848c-3c33fe50f412)). |

## 43395070 VAR\_OUTPUT

```
VAR_OUTPUT  
    Valid        : BOOL;  
    Busy         : BOOL;  
    Error        : BOOL;  
    ErrorId      : UDINT;  
    GroupErrorId : UDINT;  
END_VAR
```

| **Name** | **Type** | **Description** |
| --- | --- | --- |
| Valid | BOOL | This output indicates that other output values are valid for this function block. |
| Busy | BOOL | This output becomes TRUE when the command is started with Enable and remains so as long as the function block executes the command. |
| Error | BOOL | This output becomes TRUE if an error has occurred during command execution. |
| ErrorId | UDINT | Contains the command-specific error code of the last executed command. Details of the error code can be found in the [ADS error documentation](ms-xhelp:///?Id=beckhoff-07bc-42ba-bf39-8bb430e44b38) or in the [NC error documentation](ms-xhelp:///?Id=beckhoff-7f1e-487d-a5ed-713a7234d65b) (error codes 0x4nnn and 0x8nnn). |
| GroupErrorId | UDINT | Returns the error ID of the group (see [NC error documentation](ms-xhelp:///?Id=beckhoff-7f1e-487d-a5ed-713a7234d65b)). |

## Requirements

| Development environment | Target system type | PLC libraries to be linked |
| --- | --- | --- |
| TwinCAT V3.1.4018.26  TF5400 Advanced Motion Pack V3.1.1.17 | PC or CX (x86 or x64) | Tc3\_McCoordinatedMotion, Tc2\_MC2 |
