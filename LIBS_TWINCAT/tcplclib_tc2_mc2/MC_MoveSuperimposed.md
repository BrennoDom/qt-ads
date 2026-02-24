# MC_MoveSuperimposed

## Library
tcplclib_tc2_mc2

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_MC2](ms-xhelp:///?Id=beckhoff-63a7-4c0e-8569-314547c8cffc)
2. [Motion function blocks](ms-xhelp:///?Id=beckhoff-9fda-4d69-a293-05505fb4838c)
3. [Superposition](ms-xhelp:///?Id=beckhoff-1c4d-4ef6-81de-ab45bc73a928)
4. MC\_MoveSuperimposed

# MC\_MoveSuperimposed

![2955276](/tcplclib_tc2_mc2/1033/Images/png/9007199325061003__Web.png)

MC\_MoveSuperimposed starts a relative superimposed movement while the axis is already moving. The current movement is not interrupted. The "Done" output is set once the superimposed movement is completed. The original subordinate movement may continue to be active and is monitored by the associated Move function block.

The function of the superimposition becomes clear when considering two axes that operate with the same velocity. If one of the axes is superimposed by MC\_MoveSuperimposed, it will precede or follow the other axis as determined by the "Distance" parameter. Once the superimposed movement is completed, the "Distance" between the two axes is maintained.

MC\_MoveSuperimposed can be executed on single axes as well as on master or slave axes. In a slave axis, the superimposed movement acts solely on the slave axis. If the function is applied to a master axis, the slave mimics the superimposed movement of the master due to the axis coupling.

Since MC\_MoveSuperimposed executes a relative superimposed movement, the target position for the subordinate travel command changes by Distance.

The superimposed movement depends on the position of the main movement. This means that a velocity change of the main movement also results in a velocity change in the superimposed movement, and that the superimposed movement is inactive if the main movement stops. The "Options" parameter can be used to specify whether the superimposed movement is to be aborted or continued if the main movement stops.

See also: [Application examples for MC\_MoveSuperimposed](ms-xhelp:///?Id=beckhoff-a732-4832-a702-3bc1bf3ceed0)

## Inputs

```
VAR_INPUT  
    Execute         : BOOL;    
    Mode            : E_SuperpositionMode;  
    Distance        : LREAL;    
    VelocityDiff    : LREAL;    
    Acceleration    : LREAL;    
    Deceleration    : LREAL;    
    Jerk            : LREAL;    
    VelocityProcess : LREAL;    
    Length          : LREAL;    
    Options         : ST_SuperpositionOptions;    
END_VAR
```

**Execute:** The command is executed with a positive edge.

**Mode:** Determines the type of the superimposed motion. (Type: [E\_SuperpositionMode](ms-xhelp:///?Id=beckhoff-4b2f-48a9-934c-af5b2224a654))

**Distance:** Relative distance to catch up. A positive value means an increase in velocity by an amount required to cover the additional distance, compared with the unaffected movement. A negative value results in braking and falling back by this distance.

**VelocityDiff:** Maximum velocity difference to the current velocity (basic velocity) of the axis (>0). For this parameter a distinction may have to be made, depending on the superimposition direction (acceleration or deceleration). If, for example, a direction reversal is not permitted, the maximum available acceleration corresponds to the maximum velocity, and the maximum deceleration to stop. Therefore, there are two possible maximum values for "VelocityDiff":

* Distance > 0 (axis accelerates)  
  VelocityDiff = maximum velocity – basic velocity
* Distance < 0 (axis decelerates)  
  VelocityDiff = basic velocity

**Acceleration:** Acceleration (≥0). If the value is 0, the standard acceleration from the axis configuration in the System Manager is used.

**Deceleration:** Deceleration (≥0). If the value is 0, the standard deceleration from the axis configuration in the System Manager is used.

**Jerk:** Jerk is not used because the motion profile created is not jerk-limited.

**VelocityProcess:** Mean process velocity in the axis (>0). If the basic velocity during superposition is constant, the set axis velocity can be specified.

**Length:** Distance over which the superimposed movement is available. The "Mode" parameter defines how this distance is interpreted.

**Options:** Data structure containing additional, rarely used parameters. The input can normally remain open. (Type: [ST\_SuperpositionOptions](ms-xhelp:///?Id=beckhoff-32f8-48c6-82d9-223355e99a98))

* **AbortOption:** Defines the behavior when the subordinate motion stops. The superimposed movement can be aborted or continued later.

See also: [General rules for MC function blocks](ms-xhelp:///?Id=beckhoff-8c0b-4b22-91c9-62cc025540bd)

## Outputs

```
VAR_OUTPUT  
    Done               : BOOL;  
    Busy               : BOOL;  
    Active             : BOOL;  
    CommandAborted     : BOOL;  
    Error              : BOOL;  
    ErrorID            : UDINT;  
    Warning            : BOOL;  
    WarningID          : UDINT;  
    ActualVelocityDiff : LREAL;  
    ActualDistance     : LREAL;  
    ActualLength       : LREAL;  
    ActualAcceleration : LREAL;  
    ActualDeceleration : LREAL;  
END_VAR
```

**Done:** TRUE if the superimposed movement was successfully completed.

**Busy:** TRUE as soon as the command is started with "Execute" and as long as the movement command is processed. If "Busy" is FALSE, the function block is ready for a new order. At the same time, one of the outputs "Done", "CommandAborted" or "Error" is set.

**Active:** Indicates that the command is executed.

**CommandAborted:** Becomes TRUE, if the command was aborted by another command and could therefore not be completed.

**Error:** TRUE, if an error occurs.

**ErrorID:** If the error output is set, this parameter supplies the error number.

**Warning:** TRUE if the action cannot be executed completely.

**WarningID:** The function block returns warning 4243hex (16963) if the compensation was incomplete due to the parameterization (distance, velocity, etc.). In this case compensation is implemented as far as possible. The user has to decide whether to interpret this warning message within his application as a proper error or merely as a warning.

**ActualVelocityDiff:** Actual velocity difference during the superimposed motion (ActualVelocityDiff ≤ VelocityDiff).

**ActualDistance:** Actual superimposed distance. The function block tries to reach the full "Distance" as specified. Depending on the parameterization ("VelocityDiff", "Acceleration", "Deceleration", "Length", "Mode") this distance may not be fully reached. In this case the maximum possible distance is superimposed. (ActualDistance ≤ Distance).

**ActualLength:** Actual travel during superimposed motion (ActualLenght ≤ Length).

**ActualAcceleration:** Actual acceleration of the superimposed movement (ActualAcceleration ≤ Acceleration).

**ActualDeceleration:** Actual deceleration of the superimposed movement (ActualDeceleration ≤ Deceleration).

See also: [General rules for MC function blocks](ms-xhelp:///?Id=beckhoff-8c0b-4b22-91c9-62cc025540bd)

## Inputs/outputs

```
VAR_IN_OUT  
    Axis : AXIS_REF;  
END_VAR
```

**Axis:** Axis data structure that unambiguously addresses an axis in the system. Among other parameters it contains the current axis status, including position, velocity or error state. (Type: [AXIS\_REF](ms-xhelp:///?Id=beckhoff-7cdc-4b2f-b455-b38811ddad01))

## Requirements

| Development environment | Target system type | PLC libraries to include |
| --- | --- | --- |
| TwinCAT v3.0.0 | PC or CX (x86 or x64) | Tc2\_MC2 |

[TwinCAT 3 | PLC Library: Tc2\_MC2](ms-xhelp:///?Id=beckhoff-63a7-4c0e-8569-314547c8cffc)
