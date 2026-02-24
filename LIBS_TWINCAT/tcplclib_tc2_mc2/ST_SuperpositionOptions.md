# ST_SuperpositionOptions

## Library
tcplclib_tc2_mc2

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_MC2](ms-xhelp:///?Id=beckhoff-63a7-4c0e-8569-314547c8cffc)
2. [Data types](ms-xhelp:///?Id=beckhoff-683b-4615-8584-914eb091e041)
3. [Motion](ms-xhelp:///?Id=beckhoff-2107-47ed-8b8e-b9259019655e)
4. ST\_SuperpositionOptions

# ST\_SuperpositionOptions

```
TYPE ST_SuperpositionOptions :  
STRUCT  
   AbortOption : E_SuperpositionAbortOption;  
END_STRUCT  
END_TYPE 
```

```
TYPE E_SuperpositionAbortOption :  
 (  
    SUPERPOSITIONOPTION_ABORTATSTANDSTILL := 0,   
    SUPERPOSITIONOPTION_RESUMEAFTERSTANDSTILL,   
    SUPERPOSITIONOPTION_RESUMEAFTERMOTIONSTOP   
 );  
END_TYPE 
```

## AbortOption

AbortOption is an optional parameter of the function block [MC\_MoveSuperimposed](ms-xhelp:///?Id=beckhoff-5d13-4934-bf02-f97d70604dd7), which determines the behavior of a superimposed movement at a standstill of the main movement.

## SUPERPOSITIONOPTION\_ABORTATSTANDSTILL:

The superimposed movement is aborted as soon as the subordinate movement leads to a standstill of the axis. The only exception to this is a standstill caused by a speed override of zero. In this case the superimposed movement is also continued as soon as the override is not equal to zero. AbortAtStandstill is the default behavior if the option is not assigned by the user.

## SUPERPOSITIONOPTION\_RESUMEAFTERSTANDSTILL:

The superimposed movement is not aborted in the case of a temporary standstill of the main movement, but is continued as soon as the axis moves again. This can occur in particular in the case of a reversal of direction or with cam disc movements. The superimposed movement is terminated only if the target position of the axis has been reached or the axis has been stopped.

## SUPERPOSITIONOPTION\_RESUMEAFTERMOTIONSTOP:

The superimposed movement is not aborted in the case of a standstill of the main movement, even if the axis has reached its target position or has been stopped. In this case, the superimposed movement is continued after the axis restarts.

This case is not of importance if the superimposed movement is applied to a slave axis, since this cannot be started or stopped actively. For slave axes, the operating modes RESUMEAFTERSTANDSTILL and RESUMEAFTERMOTIONSTOP are equivalent. The superimposed movement would thus also be continued after a restart of the master axis.

**Overview of the abort conditions for a superimposed movement (MC\_MoveSuperimposed)**

|  | ABORTATSTAND STILL | RESUMEAFTER STANDSTILL | RESUMEAFTER MOTIONSTOP |
| --- | --- | --- | --- |
| 1. override = 0% | continued | continued | continued |
| 2. temporary standstill of the main movement | Abort | continued | continued |
| 3. motion reversal | Abort | continued | continued |
| 4. axis has reached the target position or is stopped | Abort | Abort | continued |
| 5. axis reset or switch-off of the enable signal | Abort | Abort | Abort |
| 6. for slave axes: Uncoupling | Abort | Abort | Abort |

## Requirements

| Development environment | Target system type | PLC libraries to include |
| --- | --- | --- |
| TwinCAT v3.0.0 | PC or CX (x86 or x64) | Tc2\_MC2 |

[TwinCAT 3 | PLC Library: Tc2\_MC2](ms-xhelp:///?Id=beckhoff-63a7-4c0e-8569-314547c8cffc)
